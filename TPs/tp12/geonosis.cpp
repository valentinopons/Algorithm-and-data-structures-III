#include<iostream>
#include<vector>
#include<algorithm>
#include <limits> 

using namespace std;

const long long int INF = numeric_limits<long long int>::max();

long long int sumar(vector<vector<long long int>>& G, int k) { //dada una matriz G suma los elementos de la submatriz k x k.
    long long int sum = 0;

    for (int i = 0; i <= k; ++i) {
        for (int j = 0; j <= k; ++j) {
            sum += G[i][j];
        }
    }

    return sum;
}

long long int Dantzig(vector<vector<long long int>>& G){ // hago dantzig y voy calculando en cada iteracion la suma de la matriz encontrada de k+1 x k+1
    long long int suma = 0;
    int n = G.size();
    for (int k = 0; k < n-1; k++){
        for (int i = 0; i <= k; i++){
            long long int minc = INF;
            long long int minf = INF;
            for (int j = 0; j <= k; j++){
                if(G[i][j] + G[j][k+1] < minc){
                    minc = G[i][j] + G[j][k+1];
                }
                if(G[k+1][j] + G[j][i] < minf){
                    minf = G[k+1][j] + G[j][i];
                }
            }

            G[i][k+1] = minc;
            G[k+1][i] = minf;
        }
        for (int i = 0; i <= k; i++){
            for (int j = 0; j <= k; j++){
                G[i][j] = min(G[i][j], G[i][k+1] + G[k+1][j]);
            }
        }
        suma += sumar(G, k+1); //funcion que suma los elem de la matriz k+1 x k+1
    }

    return suma;
}

vector<vector<long long int>> ordenar_matriz(vector<vector<long long int>>& G, vector<int>& orden ){ //ordeno la matriz para que me quede a mi conveniencia. si el orden de destruccion es 0,1,2 pongo la fila numero 2 en la posicion 0 la 1 queda igual y la 0 en la 2  
    vector<vector<long long int>> N(G.size(), vector<long long int>(G.size()));                        
    int n = orden.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            N[i][j] = G[orden[i]][orden[j]];
        }
    }
    return N;
}

int main() {
    int casos;
    cin >> casos;
    vector<long long int> res(casos);

    for(int i = 0; i < casos; i++) {
        int torres;
        cin >> torres;
        
        vector<vector<long long int>> G(torres, vector<long long int>(torres));
        for (int f = 0; f < torres; f++) {
            for (int t = 0; t < torres; t++) {
                long long int t1;
                cin >> t1;
                G[f][t] = t1;
            }
        }

        vector<int> ord(torres);
        for (int j = 0; j < torres; j++) {
            int o;
            cin >> o;
            ord[torres - j - 1] = o;
        }

        vector<vector<long long int>> N = ordenar_matriz(G, ord);

        res[i] = Dantzig(N);
    }

    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }

    return 0;
}
