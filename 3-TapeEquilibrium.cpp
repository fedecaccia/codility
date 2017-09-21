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


