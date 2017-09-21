// Correctness 100%
// Performance 100%
// Time complexity O(N+M)
// Space complexity O(N+M)

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    
    vector <int> counters(N,0);
    int max = 0;
    int level = 0;
    
    for(int i=0; i<(int)A.size(); i++){
        if(A[i]-1<N){
            if(counters[A[i]-1]<level){
                counters[A[i]-1] = level;
            }
            counters[A[i]-1]++;
            if(counters[A[i]-1]>max){
                max = counters[A[i]-1];
            }
        }
        else{
            level = max;    
        }
    }
    
    for(int i=0; i<N; i++){
        if(counters[i]<level){
            counters[i] = level;
        }    
    }
    return counters;
}