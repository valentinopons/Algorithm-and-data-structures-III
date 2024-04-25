#include <iostream>
#include <vector>
#include <limits>
using namespace std;

vector<vector<int>> potencia_mult(vector<vector<int>> A ,vector<vector<int>> B){ // solo para matrizes nxn
    vector<vector<int>> C(A.size(),vector<int> (A.size() , 0));
        for (int i = 0; i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                for (int k = 0; k < A.size(); ++k) {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        return C;
}
vector<std::vector<int>> sumarMatrices(const vector<vector<int>>& A, const vector<vector<int>>& B) {
    int n = A.size(); 
    int m = A[0].size(); 

    vector<vector<int>> suma(n, vector<int>(m, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            suma[i][j] = A[i][j] + B[i][j];
        }
    }

    return suma;
}


vector<vector<int>> m(4 , vector<int>(4) );
vector<vector<int>> D = potencia_mult(m,m);
    
vector<vector<int>> potencia_sum( int n ){
    if(n==2){
        return D;
       
    }else if(n==1){
        return m;

    }else{ if(n % 2 == 0){   
        return sumarMatrices(potencia_sum(n/2),potencia_sum())
    }
        
    }
}


int main(){

}