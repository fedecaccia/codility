// Correctness 100%
// Performance 100%
// Time Complexity O(N+M)
// Space Complexity O(N) - not counting the storage required for input arguments

// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    int nNuc = 3; 
    int N = S.size();
    int M = P.size();
    
    vector<vector<int>> adn(nNuc, vector<int>(N+1,0)); 
        
    for (int i=0; i<N; i++){
        for(int j=0; j<nNuc; j++){
            adn[j][i+1]=adn[j][i];    
        }
        if(S[i]=='A'){
            adn[0][i+1]=adn[0][i]+1;
        }
        else if(S[i]=='C'){
            adn[1][i+1]=adn[1][i]+1;
        }
        else if(S[i]=='G'){
            adn[2][i+1]=adn[2][i]+1;
        }
    }
    
    vector <int> query(M,4);
    
    for (int i=0; i<M; i++){
        if(adn[0][Q[i]+1]-adn[0][P[i]]>0){
            query[i] = 1;    
        }
        else if(adn[1][Q[i]+1]-adn[1][P[i]]>0){
            query[i] = 2;
        }
        else if(adn[2][Q[i]+1]-adn[2][P[i]]>0){
            query[i] = 3;
        }
    }
    
    return query;
}
