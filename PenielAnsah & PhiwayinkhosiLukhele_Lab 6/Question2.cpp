#include <iostream>
using namespace std;

// Reads 'size' numbers from the user and stores them in 'alpha' array.
void inputArray(int alpha[], int size) {
    cout << "Enter " << size << " numbers: " << endl;
    for (int i = 0; i < size; i++) {
        cout << "Number " << (i + 1) << ": ";
        cin >> alpha[i];
    }
}

// Doubles each value in 'alpha' and stores the result in 'beta'.
void doubleArray(int alpha[], int beta[], int size) {
    for (int i = 0; i < size; i++) {
        beta[i] = 2 * alpha[i];
    }
}

// Function to fill the matrix with the elements in aloha and beta
void copyAlphaBeta(int alpha[], int beta[], int matrix[10][4]) {
    int count = 0;
    // Loop to fill the first five rows of the matrix with the elements in alpha
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 4; j++) {
            if (count < 20) {
                matrix[i][j] = alpha[count];
                count++;
            }
        }
    }
    
    int count2 = 0;
     // Loop to fill the last five rows of the matrix with the elements in beta
    for (int i = 5; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            if (count2 < 20) {
                matrix[i][j] = beta[count2];
                count2++;
            }
        }
    }
}

// Prints elements in a one-dimensional array.
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
        if ((i + 1) % 15 == 0) {
            cout << endl;
        }
    }
    cout << endl;
}

// Prints the contents of the matrix.
void printMatrix(int matrix[10][4]) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 4; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int alpha[20];
    int beta[20];
    int matrix[10][4] = {};
    int sizealpha = sizeof(alpha) / sizeof(alpha[0]);
    int sizebeta = sizeof(beta) / sizeof(beta[0]);

    inputArray(alpha, sizealpha);       // Populate 'alpha' with user input
    doubleArray(alpha, beta, sizebeta); // Populate 'beta' with double of 'alpha'
    copyAlphaBeta(alpha, beta, matrix); // Copy values into 'matrix'

    cout << "Alpha Array: " << endl;
    printArray(alpha, sizealpha);       // Print 'alpha' array

    cout << "Beta Array: " << endl;
    printArray(beta, sizebeta);         // Print 'beta' array

    cout << "Matrix: " << endl;
    printMatrix(matrix);                // Print 'matrix'

    return 0;
}
