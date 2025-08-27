#include <iostream>
#include <vector>   // Needed for std::vector
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int climbStairs(int n) {

    /// the patter is like fibbonaci.. [1,2,3,5,8,...]
    if (n <= 2) return n;
    int left = 1;
    int right = 2;
    
    for (int i = 2; i < n; i++) {
        int temp = right;
        right = left + right;
        left = temp;
    }
    return right;
}

int main() {

    // Example input
    int n = 4;
    
    int result = climbStairs(n);

    cout << "Output: " << result << endl;
    return 0;
}
