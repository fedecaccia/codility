// Correctness 100%
// Performance 100%
// Time Complexity O(N)
// Space Complexity O(1)

// you can use includes, for example:
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    // Reducing elements in vector
    int reduce = std::accumulate(A.begin(), A.end(), 0);
    
    // Reducing elements in (1, n+1) // Gauss summation
    int count = ((A.size()+1) + 1) * (A.size()+1)/2;
    
    // The difference is the missing number   
    return count - reduce;
}
