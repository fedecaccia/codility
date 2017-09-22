/*A zero-indexed array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.

For example, consider array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.

Write a function

int solution(vector<int> &A);

that, given a zero-indexed array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.

Assume that:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
For example, given array A such that

 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
the function may return 0, 2, 4, 6 or 7, as explained above.

Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.*/

// Correctness 100%
// Performance 100%
// Time Complexity O(N)
// Space Complexity O(1)

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int N = A.size();
    
    if(N==0) return -1;
    if(N==1) return 0;
    
    vector <int> leader;
    
    leader.push_back(A[0]);
    
    for (int i=1; i<N; i++){
        leader.push_back(A[i]);
        if(leader.size()>1){
            if( (leader.end()[-1]) != (leader.end()[-2]) ){                
                leader.pop_back();                
                leader.pop_back();
            }
        }
    }
    
    int count =0;
    int pos=-1;
    if(leader.size()>0){
        for(int i=0; i<N; i++){
            if(leader[0]==A[i]){
                pos =i; 
                count++;
            }
        }
    }
    
    if(count > N/2){
      return pos;
    }
    else{
      return -1;
    }
}
