// NAME: AMIRAH NAILOFAR BINTI MUHAMAD HAFIDZ
// ID: 24007510
// EMAIL: amirah_24007510@utp.edu.my
// COURSE: BACHELOR OF COMPUTER SCIENCE

// Medium: Rotate Each Row of Matrix K Times

#include <iostream>
using namespace std;

// Rotate one row of the matrix to the right by k times
void rotateRowRight(int row[], int columns, int k) {
    k = k % columns; // handle if k > columns
    if (k == 0) return;

    // Temporary array to store the rotated version
    int temp[columns];

    // Move last k elements to the front
    for (int i = 0; i < k; i++)
        temp[i] = row[columns - k + i];

    // Move the remaining elements after that
    for (int i = 0; i < columns - k; i++)
        temp[k + i] = row[i];

    // Copy temp back to original row
    for (int i = 0; i < columns; i++)
        row[i] = temp[i];
}

// Rotate every row of the matrix
void rotateMatrix(int matrix[][3], int rows, int columns, int k) {
    for (int i = 0; i < rows; i++)
        rotateRowRight(matrix[i], columns, k);
}

// Print matrix neatly
void printMatrix(int matrix[][3], int rows, int columns) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int matrix[3][3] = {
        {12, 23, 34},
        {45, 56, 67},
        {78, 89, 91}
    };
    int k = 2;

    cout << "Original Matrix:\n";
    printMatrix(matrix, 3, 3);

    rotateMatrix(matrix, 3, 3, k);

    cout << "\nMatrix after rotating each row " << k << " times:\n";
    printMatrix(matrix, 3, 3);

    return 0;
}