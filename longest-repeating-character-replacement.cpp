#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int characterReplacement(string s, int k) {

    if (s.size() <= 1) return s.size();

    int left = 0;
    int right = 1;
        
}

int main() {

    // Example input
    string s= "ABAB";
    int k = 1;

    int result = characterReplacement(s, k);

    cout << "Output: " << result << endl;
    return 0;
}
