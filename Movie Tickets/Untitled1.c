#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold movie information
typedef struct {
    int id;
    char title[50];
    float price;
} Movie;

// Define some movies
Movie movies[] = {
    {1, "Priyotoma", 10.0},
    {2, "Toofan", 12.0},
    {3, "Rajkumar", 8.0},
    {4, "Beder Meye Josna", 9.0},
    {5, "Ammajan", 11.0},
    {6, "Monpura", 8.0},
    {7, "Aynabaji", 10.0},
    {8, "Moner Majhe Tumi", 12.0},
    {9, "	Koti Takar Kabin", 7.0},
    {10, "Chhutir Ghonta", 6.0},

};
const int movieCount = sizeof(movies) / sizeof(movies[0]);

// Function to display available movies
void displayMovies() {
    printf("Available Movies:\n");
    for (int i = 0; i < movieCount; i++) {
        printf("%d. %s ($%.2f)\n", movies[i].id, movies[i].title, movies[i].price);
    }
}

// Function to get a movie by ID
Movie* getMovieById(int id) {
    for (int i = 0; i < movieCount; i++) {
        if (movies[i].id == id) {
            return &movies[i];
        }
    }
    return NULL;
}

int main() {
    int movieId;
    int ticketCount;

    // Display available movies
    displayMovies();

    // Get user choice for movie
    printf("Enter the ID of the movie you want to watch: ");
    scanf("%d", &movieId);

    // Get the selected movie
    Movie* selectedMovie = getMovieById(movieId);
    if (selectedMovie == NULL) {
        printf("Invalid movie ID.\n");
        return EXIT_FAILURE;
    }

    // Get the number of tickets
    printf("Enter the number of tickets: ");
    scanf("%d", &ticketCount);
    if (ticketCount <= 0) {
        printf("Invalid number of tickets.\n");
        return EXIT_FAILURE;
    }

    // Calculate total cost
    float totalCost = ticketCount * selectedMovie->price;

    // Print booking summary
    printf("\nBooking Summary:\n");
    printf("Movie: %s\n", selectedMovie->title);
    printf("Number of tickets: %d\n", ticketCount);
    printf("Total cost: $%.2f\n", totalCost);

    return EXIT_SUCCESS;
}
