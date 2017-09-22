// Correctness 100%
// Performance 100%
// Time Complexity O(N)
// Space Complexity O(N)

// you can use includes, for example:
#include <numeric>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    
    int* numbers = new int[N];
    for (int i=0; i<N; i++){
        numbers[i] = 0;    
    }
    for(int i=0; i<N; i++){
        if(A[i]<=N){
            numbers[A[i]-1]++;    
            if(numbers[A[i]-1]>1){ // repeated num
                return 0;    
            }
        }else{ // higher num
            return 0;    
        }
    }
    
    return 1;
}
