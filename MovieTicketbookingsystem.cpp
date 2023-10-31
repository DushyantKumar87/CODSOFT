#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

const int ROWS = 5;
const int COLS = 10;

// Function prototypes
void initializeSeats(bool seats[][COLS], int rows);
void printSeats(bool seats[][COLS], int rows);
void bookSeat(bool seats[][COLS], int rows, int row, int col);
bool isValidSeat(bool seats[][COLS], int rows, int row, int col);

int main() {
    bool seats[ROWS][COLS];
    int option, row, col;
    
    initializeSeats(seats, ROWS);
    
    do {
        cout << "Movie Ticket Booking System" << endl;
        cout << "1. View Seats" << endl;
        cout << "2. Book a Seat" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter option (1-3): ";
        cin >> option;
        
        switch(option) {
            case 1:
                printSeats(seats, ROWS);
                break;
            case 2:
                cout << "Enter seat row: ";
                cin >> row;
                cout << "Enter seat column: ";
                cin >> col;
                if (isValidSeat(seats, ROWS, row, col)) {
                    bookSeat(seats, ROWS, row, col);
                } else {
                    cout << "Invalid seat selection!" << endl;
                }
                break;
            case 3:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid option!" << endl;
        }
        
        cout << endl;
    } while(option != 3);
    
    return 0;
}

// Function to initialize all seats as available
void initializeSeats(bool seats[][COLS], int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            seats[i][j] = true;
        }
    }
}

// Function to print the current seat status
void printSeats(bool seats[][COLS], int rows) {
    cout << "Current Seat Status" << endl;
    cout << setw(3) << " ";
    for (int j = 0; j < COLS; j++) {
        cout << setw(3) << j + 1;
    }
    cout << endl;
    
    for (int i = 0; i < rows; i++) {
        cout << setw(3) << i + 1;
        for (int j = 0; j < COLS; j++) {
            if (seats[i][j]) {
                cout << setw(3) << "O";
            } else {
                cout << setw(3) << "X";
            }
        }
        cout << endl;
    }
}

// Function to book a seat
void bookSeat(bool seats[][COLS], int rows, int row, int col) {
    if (seats[row - 1][col - 1]) {
        seats[row - 1][col - 1] = false;
        cout << "Seat booked successfully!" << endl;
    } else {
        cout << "Seat already booked!" << endl;
    }
}

// Function to check if a seat is valid
bool isValidSeat(bool seats[][COLS], int rows, int row, int col) {
    if (row > 0 && row <= rows && col > 0 && col <= COLS) {
        return true;
    }
    return false;
}
