#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <list>
using namespace std;

int characterReplacement(string s, int k) {

    if (s.size() <= 1) return s.size();

    int left = 0;
    int right = 1;
    int maxLength = 1;
    map<char, int> charMap = {{s[left], 1}};

    while(left < right && right < s.size()) {
        cout << "Left: " << left << "-" << s[left] << ", Right: " << right << "-" << s[right];

        charMap.count(s[right]) ? charMap[s[right]] += 1 : charMap[s[right]] = 1;

        int windowSize = right - left + 1;

        // get the count of max number of chars in the map.
        int maxCount = INT_MIN;
        char maxChar;
        for (auto item : charMap) {
            if (item.second > maxCount) {
                maxCount = item.second;
                maxChar = item.first;
            }  
        }
        if (k >= windowSize-maxCount) {
            // The window is valid for the changes.
            maxLength = max(maxLength, windowSize);
            right += 1;
        }
        else {
            charMap.at(s[left]) -= 1;
            left += 1;
            right += 1;
        }
        cout << ", MaxLength: " << maxLength << endl;
    }
    return maxLength;   
}

int main() {

    // Example input
    string s= "AABABBA";
    int k = 1;

    int result = characterReplacement(s, k);

    cout << "Output: " << result << endl;
    return 0;
}
