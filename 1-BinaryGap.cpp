// Correctness 100%
// Performance 100%
// Time Complexity O(log(N))
// Space Complexity O(1)

// you can use includes, for example:
// #include <algorithm>
#include<vector>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    
    int maxGap=0;
    int actualGap=0;
    bool looking = false;
    
    int index=0;
    while(N>0){
        if(N%2==1){
            looking = true;
            if(actualGap>maxGap){
                maxGap=actualGap;    
            } 
            actualGap=0;
        }
        else if(looking){
            actualGap++;    
        }
        
        N = N/2;
        index++;        
    }
    return maxGap;   
}
