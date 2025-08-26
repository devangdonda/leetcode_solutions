#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <string>
#include <list>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s) {

    if (s.size()<=1) return s.size();

    int left = 0;
    int result = 0;
    set<char> charList = {s[0]};

    for (int right = 1; right < s.size(); right++) {
        while (charList.count(s[right])) {
            charList.erase(s[left]);
            left += 1;
        }
        charList.insert(s[right]);
        result = max(result, right - left + 1);
    }
    return result;
}

int main() {
    string nums = "dvdf";
    int result = lengthOfLongestSubstring(nums);
    cout << "Output: " << result;
}

