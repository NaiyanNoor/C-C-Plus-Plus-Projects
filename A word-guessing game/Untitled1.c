
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TRIES 6

void printWord(char *word, int length, int *guessed);
int isWordGuessed(int length, int *guessed);
void printHangman(int tries);

int main() {
    char *words[] = {"computer", "hangman", "programming", "software", "developer"};
    int numWords = sizeof(words) / sizeof(words[0]);

    srand(time(0));
    int randomIndex = rand() % numWords;
    char *selectedWord = words[randomIndex];
    int wordLength = strlen(selectedWord);
    int guessed[wordLength];

    for (int i = 0; i < wordLength; i++) {
        guessed[i] = 0;
    }

    int tries = 0;
    char guess;
    int correctGuess;

    printf("Welcome to Hangman!\n");

    while (tries < MAX_TRIES && !isWordGuessed(wordLength, guessed)) {
        printHangman(tries);
        printWord(selectedWord, wordLength, guessed);

        printf("Enter a letter: ");
        scanf(" %c", &guess);

        correctGuess = 0;
        for (int i = 0; i < wordLength; i++) {
            if (selectedWord[i] == guess && !guessed[i]) {
                guessed[i] = 1;
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            tries++;
        }
    }

    if (isWordGuessed(wordLength, guessed)) {
        printf("\nCongratulations! You've guessed the word '%s'\n", selectedWord);
    } else {
        printHangman(tries);
        printf("\nGame Over! The word was '%s'\n", selectedWord);
    }

    return 0;
}

void printWord(char *word, int length, int *guessed) {
    printf("\nWord: ");
    for (int i = 0; i < length; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int isWordGuessed(int length, int *guessed) {
    for (int i = 0; i < length; i++) {
        if (!guessed[i]) {
            return 0;
        }
    }
    return 1;
}

void printHangman(int tries) {
    printf("\n");
    printf("  +---+\n");
    printf("  |   |\n");
    printf("  |   %c\n", (tries > 0) ? 'O' : ' ');
    printf("  |  %c%c%c\n", (tries > 2) ? '/' : ' ', (tries > 1) ? '|' : ' ', (tries > 3) ? '\\' : ' ');
    printf("  |  %c %c\n", (tries > 4) ? '/' : ' ', (tries > 5) ? '\\' : ' ');
    printf("  |\n");
    printf("  |\n");
    printf("=========\n");
}
