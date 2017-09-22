/*A zero-indexed array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is also moved to the first place.

For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7]. The goal is to rotate array A K times; that is, each element of A will be shifted to the right by K indexes.

Write a function:

struct Results solution(int A[], int N, int K);
that, given a zero-indexed array A consisting of N integers and an integer K, returns the array A rotated K times.

For example, given array A = [3, 8, 9, 7, 6] and K = 3, the function should return [9, 7, 6, 3, 8].

Assume that:

N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.*/

// Correctness 100%
// Performance 100%
// Time Complexity O(N) - Not interested
// Space Complexity O(1) - Not interested

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(vector<int> &A, int K) {
    // write your code in C++14 (g++ 6.2.0)
    int aux;
    int N = A.size();
    
    for(int i=0; i<K; i++){
        if(N>1){
            aux = A[N-1];
        }else{
            return A;
        }
        for(int i=N-1; i>=0; i--){        
            i>0 ? A[i] = A[i-1] : A[i] = aux;
        }
    }
    
    return A;
}
