#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    map<int, int> mapOfNumbers;

    /// This is to create the unique set/list of values in ascending order.
    /// Maps and Sets are implemented on self-balancing binary search tree and hence,
    /// have same time complexities for search, insert, and erase.
    /// However index lookup is not possible in sets hence we are not going to use them.

    sort(nums.begin(), nums.end());

    for (int number : nums) {
        mapOfNumbers.insert({number, 1});
    }

    int complement = 0 - nums[0];
    int i = 0;

    do {

        if (nums[i] != nums[i-1]) {

            for (int j = i+1; j < nums.size()-1; j++) {
                int complement2 = complement - nums[j];
                if (find(nums.begin()+j+1, nums.end(), complement2) != nums.end()) {
                    result.push_back({nums[i], nums[j], complement2});
                }
            }
        }
        i += 1;
        int complement = 0 - nums[i];

    } while (i < nums.size() - 2);
    return result;
}

int main() {

    vector<int> nums = {2,0,-2,4,3, 1, -4, -6};
    // {-6, -4, -2, 0, 1, 2, 3, 4}
    vector<vector<int>> result = threeSum(nums);
    for (vector<int> number : result) {
        cout << "Output: " << number[0] << ", "<< number[1] << ", " << number[2] << endl;
    }
}

