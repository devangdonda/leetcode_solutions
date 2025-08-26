#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <list>
using namespace std;

bool isPalindrome(string s) {

    int p1 = 0;
    int p2 = s.size() - 1;

    while (p1<p2) {
        if (!isalnum(s[p1])) {p1++;}
        if (!isalnum(s[p2])) {p2--;}
        else if (isalnum(s[p1]) && isalnum(s[p2])) {
            if (tolower(s[p1]) != tolower(s[p2])) return false;
            else {p1++; p2--;}
        }
    }
    return true;    
}

int main() {

    // Example input
    string s= "anagram";

    int result = isPalindrome(s);

    cout << "Output: " << result << endl;
    return 0;
}
