#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
using namespace std;

bool isValidAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    
    int counts[26] = {0};
    for (int i = 0; i < s.size(); i++) {
        counts[s[i] - 'a'] ++;
        counts[t[i] - 'a'] --;
    }
    for (int item : counts) {
        if (item != 0) return false;
    }
    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    vector<vector<string>> result;

    int n = strs.size()-1;
    while (n >= 0) {
        string s = strs[n];
        cout << "Currently at string: " << s << endl;
        strs.pop_back();
        n -= 1;
        if (result.size() == 0) {
            result.push_back(vector<string>{s});
            cout << "Added to result" << endl;
            continue;
        }
        bool isAnagram = false;
        for (int i = 0; i < result.size(); i++) {
            // resultItem may have an empty string but never will never be empty according to code.
            isAnagram = isValidAnagram(result[i][0], s);
            cout << "Is " << result[i][0] << " and " << s << " palindrome?: " << isAnagram << endl;
            if (isAnagram) {
                result[i].push_back(s);
                cout << "Added the string to " << result[i][0] << endl;
            
                break;
            }
        }
        if (!isAnagram) {
            result.push_back(vector<string>{s});
            cout << "Added to result" << endl;
        }
    }
    return result;
}


int main() {

    // Example input
    vector<string> s= {"eat","tea","tan","ate","nat","tab","bat"};

    vector<vector<string>> result = groupAnagrams(s);

    cout << "Output: ";
    for (vector<string> strVector : result) {
        cout << "[";
        for (string item : strVector) {
            cout << item << ", ";
        }
        cout << "] ";
    }
    
    return 0;
}
