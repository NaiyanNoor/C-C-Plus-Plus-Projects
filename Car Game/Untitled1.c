#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // For _getch()

#define WIDTH 20
#define HEIGHT 10

void clearScreen() {
    system("cls"); // For Windows
    // system("clear"); // For Unix-based systems
}

void printTrack(int carPosition, int obstaclePosition) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            if (i == HEIGHT - 1 && j == carPosition) {
                printf("C"); // Car
            } else if (i == obstaclePosition && (j == carPosition - 1 || j == carPosition + 1)) {
                printf("O"); // Obstacle
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main() {
    int carPosition = WIDTH / 2;
    int obstaclePosition = 0;
    char input;
    int score = 0;

    srand(time(0));

    while (1) {
        clearScreen();
        printTrack(carPosition, obstaclePosition);

        if (kbhit()) {
            input = _getch();
            if (input == 'a' && carPosition > 0) {
                carPosition--;
            } else if (input == 'd' && carPosition < WIDTH - 1) {
                carPosition++;
            }
        }

        if (obstaclePosition == HEIGHT - 1) {
            if (carPosition == WIDTH / 2 || carPosition == WIDTH / 2 + 1) {
                printf("Game Over! Final Score: %d\n", score);
                break;
            }
            obstaclePosition = 0;
            score++;
        } else {
            obstaclePosition++;
        }

        _sleep(200); // Delay to slow down the game
    }

    return 0;
}
