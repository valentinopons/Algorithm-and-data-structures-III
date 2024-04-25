#include <iostream>
#include <vector>
#include <limits>
using namespace std;


vector<int> C = {2,4,7};
vector<vector<int>> matriz;

bool corteDisponible(int i , int j){
    for (int t = 0; t < C.size(); t++){
        if ( i<C[t] && C[t]<j){
            return true;
        }
        
    }
    return false;
    
}

int cortesEconomicos(int i , int j){
    if(matriz[i][j] != INT_MAX){
        return matriz[i][j];
    }
    if (!corteDisponible(i , j)){
        matriz[i][j] = 0;
        return 0;
    }else{
        int min_res = INT_MAX;
        for (int t = 0; t < C.size(); t++){
            if(i<C[t] && C[t]< j){
                int valor = (cortesEconomicos(i,C[t])+cortesEconomicos(C[t],j) + (j-i));
                matriz[i][j] = valor;
                min_res = min(min_res , valor);
            }

            
        }
        return min_res;
    }
 
}
int bottomUp(int i , int j){
    return 0;
}

int main(){
int l = 10;
matriz.assign(l, vector<int>(l+1 , INT_MAX));
cout<< cortesEconomicos(0 ,l);
}