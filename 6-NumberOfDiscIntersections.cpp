// Correctness 100%
// Performance 100%
// Time Complexity O(N log(N))
// Space Complexity O(N)

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();    
    
    // vector O(N)
    vector<int> startingPoint(N);
    
    for(int c=0; c<N; c++){
       startingPoint[c] = c - A[c];
    }
    
    // merge sort O(N*log(N))
    sort(startingPoint.begin(), startingPoint.end());
    
    // comparison with binary search O(N*log(N))
    int pairs = 0;
    int s=0; // searching point
    int lb; // bottom level 
    int lt; // top level
    for(int c=0; c<N; c++){
        lb = c;
        lt= N;
        while(lt-lb>1){
            s = (lt-lb)/2 + lb;
            if(startingPoint[s]>(long int)c+A[c]){
                lt=s;    
            }
            else{
                lb=s;
            }
        }
        if(startingPoint[lt]==c+A[c]){
            pairs += lt-c;    
        }
        else{
            pairs += lb-c;    
        }  
        if (pairs>10000000){
            return -1;    
        }        
    }   
    
    return pairs;   
}
