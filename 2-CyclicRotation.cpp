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
