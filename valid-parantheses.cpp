#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <list>
#include <stack>
using namespace std;

bool isValid(string s) {

    if (s.size() == 1) return false;

    stack<int> stackOfBrackets;
    stackOfBrackets.push(s[0]);
    
    for (int i = 1; i < s.size(); i++) {
        if (!stackOfBrackets.empty()) {
            switch (s[i])
            {
            case '}':
                if (stackOfBrackets.top() == '{') stackOfBrackets.pop();
                else return false;
                break;
            
            case ']':
                if (stackOfBrackets.top() == '[') stackOfBrackets.pop();
                else return false;
                break;

            case ')':
                if (stackOfBrackets.top() == '(') stackOfBrackets.pop();
                else return false;
                break;
            
            default:
                stackOfBrackets.push(s[i]);
                break;
            }
        } else {
            stackOfBrackets.push(s[i]);
        }
    }
    if (stackOfBrackets.size() == 0) {return true;}
    else {return false;}
}

int main() {

    // Example input
    string s= "()";

    bool result = isValid(s);

    cout << "Output: " << result << endl;
    return 0;
}
