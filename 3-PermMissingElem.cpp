/*A zero-indexed array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.

Your goal is to find that missing element.

Write a function:

int solution(vector<int> &A);
that, given a zero-indexed array A, returns the value of the missing element.

For example, given array A such that:

  A[0] = 2
  A[1] = 3
  A[2] = 1
  A[3] = 5
the function should return 4, as it is the missing element.

Assume that:

N is an integer within the range [0..100,000];
the elements of A are all distinct;
each element of array A is an integer within the range [1..(N + 1)].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.
/*

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
