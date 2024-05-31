#include <iostream>
#include <vector>
#include <list>
#include <cmath> 
#include<set>
#include<string>
#include <queue>
#include <unordered_map>
#include <climits>

using namespace std;


struct Edge{
    string v;
    string w;
    int weight;
};

struct Vertex{
    string name;
    list <string> neighbours;
    vector<pair<string , int>> E;
    unordered_map<string, int> claves_a_indices;

};

typedef vector<Vertex> graph; 
// esto me va a servir para calcular la distancia mas cercana entre xxxx e yyyy
vector<vector<int>> valores = {{0,1,2,3,4,5,4,3,2,1} , {1,0,1,2,3,4,5,4,3,2} , {2,1,0,1,2,3,4,5,4,3} , {3,2,1,0,1,2,3,4,5,4} , {4,3,2,1,0,1,2,3,4,5} ,
                {5,4,3,2,1,0,1,2,3,4} , {4,5,4,3,2,1,0,1,2,3} , {3,4,5,4,3,2,1,0,1,2} , {2,3,4,5,4,3,2,1,0,1} , {1,2,3,4,5,4,3,2,1,0}};

int diferencia(vector<int> num1, vector<int> num2) { //
    int suma = 0;
    for (int i = 0; i < 4; i++){
        suma += valores[num1[i]][num2[i]];
    }
    return suma;
}


graph armar_grafo(vector<string>& claves  , int N ){
    graph grafo(N+1);
    for (int i = 0; i < N; i++){
        Vertex v;
        v.name = claves[i];
        grafo[0].claves_a_indices[claves[i]] = i; 
        for (int j = 0; j < N; j++){
            if( i != j){
                v.neighbours.push_back(claves[j]);
            }
        }
        grafo[i] = v;
    }
    return grafo;
}


vector<int> separar_cifras(string c){
    vector<int> res(4);
    for (int i = 0; i < 4; i++){
        res[i] = c[i] - '0';
    }
    return res;
}

void agregar_peso(graph& G){ // 
    for (int i = 0; i < G.size(); i++){
        list<string>::iterator next = G[i].neighbours.begin();
        while(next != G[i].neighbours.end()){
            vector<int> w1 = separar_cifras(*next);
            int peso = diferencia( separar_cifras(G[i].name), w1);
            pair<string,int> par = {*next , peso};
            G[i].E.push_back(par);
            ++next;
        }
    }
    
    
}
/////////////////////PRIM/////////////
struct Compare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
        return a.second > b.second; // Ordena por la segunda posición del par
    }
};

int prim(graph& G, int start) {
    int n = G.size();
    priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> cola; // <posicion en G,peso>
    vector<bool> in_AGM(n, false);
    vector<int> key(n, INT_MAX); // Inicializa todas las claves con un valor grande

    int weight = 0; // Inicializa la suma de los pesos de las aristas del AGM
    cola.push({start, 0}); // Empieza con el nodo de inicio con peso 0
    int por_visitar = n-1;
    
    while (por_visitar != 0) {
        pair<int, int> siguiente = cola.top();
        cola.pop();
        int u = siguiente.first;
        
        if (!in_AGM[u]) {
            in_AGM[u] = true;
            por_visitar--;
            weight += siguiente.second; // Agrega el peso de la arista al AGM
        }

            for (int i = 0; i < G[u].E.size(); i++) {
                string vname = G[u].E[i].first;
                int v = G[0].claves_a_indices[vname];
                int pesov = G[u].E[i].second;
                if(!in_AGM[v] || pesov < key[v] ){
                    key[v] = pesov;
                    cola.push({v, pesov});
                    
                }
            }
        
    }

    return weight; // Devuelve el peso total del AGM
}

int resolver(graph G){
    vector<int> v = {0,0,0,0};
    int peso_min = diferencia(v , separar_cifras(G[0].name));
                                        // me fijo la diferencia de el nodo 0000 con el primer vertice de mi grafo
                                         // me fijo la diferencia de el nodo 0000 con el primer vertice de mi grafo
    int pos = 0;
   
    for (int i = 0; i < G.size(); i++){ // este for lo uso para recorrer todoas las posibles claves y encontrar la minima para empezar
        int peso = diferencia(v , separar_cifras(G[i].name));
        if( peso  < peso_min){
            pos = i;
            peso_min = peso;
        
        }
    }
    
    return peso_min + prim(G , pos);
        

}




int main() {
    int casos;
    cin >> casos;
    int casos_fijo = casos;
    vector<vector<string>> C(casos);
    vector<int> res(casos);
    int i = 0;
    while (i < casos_fijo) {
        int tam;
        cin >> tam;
        vector<string> v(tam);
        for (int clave = 0; clave < tam; clave++) {
            string c;
            cin >> c;
            v[clave] = c;
        }
        C[i] = v;
        res[i] = tam;
        i++;
    }

    for (int j = 0; j < casos_fijo; j++) {     
        graph G = armar_grafo(C[j], res[j]);
        agregar_peso(G);
        cout << resolver(G) << endl;
    }
}


