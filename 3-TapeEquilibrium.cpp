/*A non-empty zero-indexed array A consisting of N integers is given. Array A represents numbers on a tape.

Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].

The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|

In other words, it is the absolute difference between the sum of the first part and the sum of the second part.

For example, consider array A such that:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
We can split this tape in four places:

P = 1, difference = |3 − 10| = 7 
P = 2, difference = |4 − 9| = 5 
P = 3, difference = |6 − 7| = 1 
P = 4, difference = |10 − 3| = 7 
Write a function:

int solution(int A[], int N);
that, given a non-empty zero-indexed array A of N integers, returns the minimal difference that can be achieved.

For example, given:

  A[0] = 3
  A[1] = 1
  A[2] = 2
  A[3] = 4
  A[4] = 3
the function should return 1, as explained above.

Assume that:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Elements of input arrays can be modified.*/

// Correctness 100%
// Performance 100%
// Time Complexity O(N)
// Space Complexity O(N)


// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int f (int a){
    if(a>0){
        return a;
    }    
    else{
        return a*-1;    
    }    
}

void print (int a){
    cout<<a<<" ";    
}


int solution(vector<int> &A) {
    // write your code in C99 (gcc 6.2.0)
    //int* sum = (int*) calloc(N-1,sizeof(int));
    //int* diff = (int*) calloc(N-1,sizeof(int));
    int N=A.size();
    vector<int> sum(N-1, 0);
    vector<int> min(N-1, 0);
    vector<int> diff(N-1, 0);
    
    for(int i=0; i<N-1; i++){
        if(i>0){
            sum[i] = sum[i-1]+A[i];
        } else{
            sum[i] = A[i];
        }
    }
    
    for(int i=N-2; i>=0; i--){
        if(i<N-2){
            min[i] = min[i+1]-A[i+1];
        } else{
            min[i] = -A[i+1];
        }
    }   
    
    //for_each(sum.begin(), sum.end(), print);
    //cout<<endl;
    //for_each(min.begin(), min.end(), print);
    //cout<<endl;
    
    transform (sum.begin(), sum.end(), min.begin(), diff.begin(), std::plus<int>());
    //for_each(diff.begin(), diff.end(), print);
    //cout<<endl;
    transform(diff.begin(), diff.end(), diff.begin(), f);
    //for_each(diff.begin(), diff.end(), print);
    //cout<<endl;
    int minor = *(min_element(diff.begin(), diff.end()));
    
    return minor;
}


