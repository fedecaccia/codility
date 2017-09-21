// Correctness 100%
// Performance 100%
// Time Complexity O(N)
// Space Complexity O(1)

// you can write to stdout for debugging purposes, e.g.
// printf("this is a debug message\n");

int solution(int A[], int N) {
    int ret = 0;
    
    for (int i = 0; i < N; ++i) {
        // bitwise operator ^
        ret = ret ^ A[i];
    }    
    
    return ret;
}
