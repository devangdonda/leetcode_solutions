#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int top = 0;
    int left = 0;
    int right = matrix[0].size() - 1;
    int bottom = matrix.size() - 1;
    vector<int> result;
    int pointer = 0;
    int fixed = 0; // top, right, bottom, left = 0,1,2,3

    while (top <= bottom && left <= right) {

        switch (fixed)
        {
            // Top is fixed, travel to right
            case 0:
                while (pointer <= right) {
                    result.push_back(matrix[top][pointer]);
                    pointer += 1;
                }
                top += 1;
                pointer = top;
                fixed = 1;
                break;

            // Right is fixed, travel to bottom
            case 1:
                while (pointer <= bottom) {
                    result.push_back(matrix[pointer][right]);
                    pointer += 1;
                }
                right -= 1;
                pointer = right;
                fixed = 2;
                break;

            // Bottom is fixed, travel to left
            case 2:
                while (pointer >= left) {
                    result.push_back(matrix[bottom][pointer]);
                    pointer -= 1;
                }
                bottom -= 1;
                pointer = bottom;
                fixed = 3;
                break;

            // Left is fixed, travel to up
            case 3:
                while (pointer >= top) {
                    result.push_back(matrix[pointer][left]);
                    pointer -= 1;
                }
                left += 1;
                pointer = left;
                fixed = 0;
                break;
        }
    }
    return result;
}

int main() {

    // Example input
    vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    // Call the function (currently does nothing meaningful)
    vector<int> result = spiralOrder(nums);

    for (int number : result) {
        cout << number << " ";
    }
    return 0;
}
