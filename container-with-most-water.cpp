#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

int maxArea(vector<int>& height) {
    int highestArea = 0;
    int left = 0;
    int right = height.size() - 1;

    while (left < right) {
        highestArea = max(highestArea, (right-left) * min(height[left], height[right]));
        height[left] > height[right] ? right -= 1 : left += 1;
    }
    return highestArea;
}

int main() {

    vector<int> nums = {1,8,6,2,5,4,8,3,7};
    int result = maxArea(nums);
    cout << "Output: " << result << endl;
}

