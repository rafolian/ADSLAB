// NAME: AMIRAH NAILOFAR BINTI MUHAMAD HAFIDZ
// ID: 24007510
// EMAIL: amirah_24007510@utp.edu.my
// COURSE: BACHELOR OF COMPUTER SCIENCE


// Hard: Largest Plus or '+' formed by all ones in a binary square matrix

#include <iostream>
#include <vector>
#include <algorithm>  // for min() and max()
using namespace std;

// Function to find the largest '+' of 1s in a binary matrix
int findLargestPlus(const vector<vector<int>>& mat) {
    int n = mat.size();
    if (n == 0) return 0;

    // Create 4 helper matrices to store consecutive 1s in 4 directions
    vector<vector<int>> left(n, vector<int>(n, 0));
    vector<vector<int>> right(n, vector<int>(n, 0));
    vector<vector<int>> top(n, vector<int>(n, 0));
    vector<vector<int>> bottom(n, vector<int>(n, 0));

    // Step 1: Fill left and top directions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                left[i][j] = (j == 0) ? 1 : left[i][j - 1] + 1;
                top[i][j] = (i == 0) ? 1 : top[i - 1][j] + 1;
            }
        }
    }

    // Step 2: Fill right and bottom directions
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (mat[i][j] == 1) {
                right[i][j] = (j == n - 1) ? 1 : right[i][j + 1] + 1;
                bottom[i][j] = (i == n - 1) ? 1 : bottom[i + 1][j] + 1;
            }
        }
    }

    // Step 3: Find the maximum plus size
    int maxPlus = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] == 1) {
                // The arm length is the smallest among all four directions
                int arm = min({left[i][j], right[i][j], top[i][j], bottom[i][j]});
                // Size = 1 (center) + 4 * (arm - 1)
                int size = 4 * (arm - 1) + 1;
                maxPlus = max(maxPlus, size);
            }
        }
    }

    return maxPlus;
}

int main() {
    // Example matrix
    vector<vector<int>> mat = {
        {0, 1, 1, 0, 1},
        {0, 0, 1, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 1, 1, 1, 0}
    };

    cout << "Largest Plus Size: " << findLargestPlus(mat) << endl;
    return 0;
}