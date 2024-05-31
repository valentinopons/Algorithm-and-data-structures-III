#include <iostream>
#include <vector>

using namespace std;

int caminoMaximmo(vector<vector<int>>& tree , int f){
    int niveles = tree[0].size();
    vector<vector<int>> v(tree.size(), vector<int>(niveles,0) );
    vector<int> s(niveles); // me voy a ir guardando la suma de la maxima cant de bellotas por nivel

    for (int n = 0; n < niveles; n++){ // este ciclo junnto al de abajo se lee: para el nivel n de todos los arboles busco el que mas beyotas tenga y lo guardo en s y en mi matriz v
        vector<int> suma_max = {0,0};    // {suma,posicion}
        int suma = 0;
        for (int t = 0; t < tree.size(); t++){
            if(n == 0){ // caso base
                v[t][0] = tree[t][0];
            }else if( n < f){   // Primeros casos que no pude haber aterrizado de ningun salto anterior
                v[t][n] = v[t][n-1] + tree[t][n];

            }else{              
                v[t][n] = tree[t][n] + max(v[t][n-1] , s[n-f]); 
            }
            if(v[t][n] > suma_max[0]){  // voy guardando el maximo de todos los arboles por nivel
                suma_max[0] = v[t][n];
                suma_max[1] = t;
                suma = suma_max[0];
            }

        }
        s[n] = suma_max[0];
   
    }
    
    return s[niveles-1];

}


int main(){
    
    int datasets;
    cin >> datasets;
    vector<int> res(datasets);
    for (int d = 0; d < datasets; d++){
        int trees , height , f , num_acorn;
        cin >> trees >> height >> f;
        vector<vector<int>> level(trees, vector<int>(height+1, 0)); // este vector guarda los arboles del dataset correspondiente donde cada posicion de level es un arbol.
        for (int t = 0; t < trees; t++){  
            cin >> num_acorn; 
            for (int a = 0; a < num_acorn; a++){
                int acorn;
                cin >> acorn;
                level[t][acorn] += 1;
                }   
        }
        
        res[d] = caminoMaximmo(level , f); // guardo resultados en un vector
    }
    int cero;
    cin>>cero;

    for (int d = 0; d < res.size(); d++){
        cout<<res[d]<<endl;
    }
            
        
    
  
}