#include <iostream>
#include <vector>
#include <limits>


using namespace std;




vector<int> p = {3,6,10};
vector<vector<int>> matriz;


int astroTrade(int j , int c){ //complejidad temporal y espacial es O(n*n+1) ya que es la cantidad de estados unicos posibles (tamaño de la matriz)
    if ( c < 0 || c > j){
        return -1000;

    }else if (j == 0 ){
        return 0;
    
    }else if(matriz[j][c] != INT_MIN){
        return matriz[j][c];

    }else{
        int res = max(max(astroTrade(j-1 , c+1)+p[j-1] , astroTrade(j-1 , c-1)-p[j-1]) , astroTrade(j-1 , c) );
        matriz[j][c]= res;
        return res;
    }
}


int main(){
    matriz.assign(p.size()+1, vector<int>(p.size(), INT_MIN));
    cout<<astroTrade(p.size() , 0)<<endl;
    
}