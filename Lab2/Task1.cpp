// NAME: AMIRAH NAILOFAR BINTI MUHAMAD HAFIDZ
// ID: 24007510
// EMAIL: amirah_24007510@utp.edu.my
// COURSE: BACHELOR OF COMPUTER SCIENCE

//Easy: Check given matrix is magic square or not

#include <iostream>
using namespace std;

bool isMagicSquare3x3(const int a[3][3]) {
    // Target = sum of the first row
    int target = a[0][0] + a[0][1] + a[0][2];

    // Check each row
    for (int r = 0; r < 3; ++r) {
        int rowSum = 0;
        for (int c = 0; c < 3; ++c) rowSum += a[r][c];
        if (rowSum != target) return false;
    }

    // Check each column
    for (int c = 0; c < 3; ++c) {
        int colSum = 0;
        for (int r = 0; r < 3; ++r) colSum += a[r][c];
        if (colSum != target) return false;
    }

    // Check both diagonals
    int diag1 = a[0][0] + a[1][1] + a[2][2];
    int diag2 = a[0][2] + a[1][1] + a[2][0];
    if (diag1 != target || diag2 != target) return false;

    return true;
}

int main() {
    int a[3][3] = {
        {2, 7, 6},
        {9, 5, 1},
        {4, 3, 8}
    };

    if (isMagicSquare3x3(a)) cout << "Magic Square\n";
    else                      cout << "Not a Magic Square\n";
    return 0;
}