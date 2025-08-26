#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <list>
using namespace std;

bool isAnagram(string s, string t) {

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

int main() {

    // Example input
    string s= "anagram";
    string t = "nagaram";

    int result = isAnagram(s,t);

    cout << "Output: " << result << endl;
    return 0;
}
