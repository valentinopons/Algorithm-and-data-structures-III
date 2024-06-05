#include<iostream>
#include<vector>
#include <bits/stdc++.h>
#include <list>
using namespace std;
struct Vertex{
    int ascensor;
    int piso;
    bool operator==(const Vertex& other) const {
        return ascensor == other.ascensor && piso == other.piso;
    }

};
struct VertexHash {
    std::size_t operator()(const Vertex& v) const {
        return std::hash<int>()(v.ascensor) ^ std::hash<int>()(v.piso);
    }
};

struct Edge{
    Vertex w;
    int peso;
    
};
struct graph{
    Vertex start;
    vector<Vertex> V = {};
    vector<list<Edge>> E = {}; 
    unordered_map<Vertex, int, VertexHash> posicion_de = {}; // <piso en cuestion , posicion en el grafo>

    graph(int n) {
        E.resize(n);
    }
    
};

void addEdge(graph& G, int u, Vertex w , int peso){ // u= posicion / se crea arista v->w con respectivo peso
    Edge e;
    e.w = w; e.peso = peso;
    G.E[u].push_back(e);
    }


void conexion_ascensores(graph& G , Vertex& v , int a , int n , vector<vector<bool>>& vertices ){
    for (int i = a+1; i < n; i++){
        if(vertices[i][v.piso]){
            Vertex u; u.ascensor = i+1; u.piso = v.piso; 
            addEdge(G , G.posicion_de[v] , u , 60);
            addEdge(G , G.posicion_de[u] , v , 60);
            }
    }
    
}


graph armarGrafo(int n , vector<int> T , vector<vector<int>> f , int tam){ // n = cantidad elevadores / T = lista con tiempo de cada elevador / f = pisos que visita cada elevador
    graph G(tam);
    int posicion = 0;
    vector<Vertex> piso_0;
    vector<vector<bool>> vertices(n , vector<bool> (100,false));
    
    for (int a = 0; a < n; a++){

        for (int p = 0; p < f[a].size()-1; p++){
            int tiempo = (f[a][p+1] -  f[a][p]) * T[a];
            Vertex v; v.ascensor = a+1; v.piso = f[a][p];
            Vertex w; w.ascensor = a+1; w.piso = f[a][p+1];
            if(v.piso == 0){
                piso_0.push_back(v);
            } 
            vertices[a][v.piso] = true;

            addEdge(G , posicion , w , tiempo); //  tengo un grafo disconexo donde cada parte forma parte del recorrido de cada elevador. n partes conexas.
            addEdge(G , posicion+1 , v , tiempo );
            G.V.push_back(v);
            G.posicion_de[v] = posicion; // agrego en el diccionario la posicion del vertice en mi grafo.
            posicion++;
            if(p == f[a].size()-2){
                G.V.push_back(w);
                vertices[a][w.piso] = true; 
                G.posicion_de[w] = posicion;
                posicion++;
            }
        }
        
    }
    for (int i = 0; i < G.V.size(); i++){
            conexion_ascensores(G , G.V[i] , G.V[i].ascensor -1 , n , vertices); // conecto entre pisos de dsitintos ascensores
        }
    for (int i = 1; i < piso_0.size(); i++)  // este for lo utilizo para conectar los ascensores que arrancan en el piso 0
                                            // con una arista de peso 0 para buscar el optimo por el que arrancar luego
    {
        addEdge(G , G.posicion_de[piso_0[0]] , piso_0[i] , 0  ); 
    }

    G.start = piso_0[0];    // lo arranco en el primer ascensor que encuentre con piso 0       
    return G;
    
}


unordered_map<Vertex, int, VertexHash> dijkstra(graph& G, Vertex origen) {
    // Inicializar distancias
    unordered_map<Vertex, int, VertexHash> dist;
    for (Vertex v : G.V) {
        dist[v] = numeric_limits<int>::max();
    }
    dist[origen] = 0;

    // Función para encontrar el vértice con la distancia mínima
    auto minDistance = [&dist](const Vertex& u, const Vertex& v) {
        return dist[u] > dist[v];
    };

    // Cola de prioridad para los vértices a explorar
    priority_queue<Vertex, vector<Vertex>, decltype(minDistance)> pq(minDistance);
    pq.push(origen);

    while (!pq.empty()) {
        Vertex u = pq.top();
        pq.pop();

        for (Edge e : G.E[G.posicion_de[u]]) {
            Vertex v = e.w;
            int peso = e.peso;
            if (dist[u] != numeric_limits<int>::max() && dist[v] > dist[u] + peso) {
                dist[v] = dist[u] + peso;
                pq.push(v);
            }
        }
    }

    return dist;
}


int main(){
    string first;
    vector<int> res;
    int pos_res = 0;
    while(getline(cin, first) && !first.empty()){
        istringstream ss(first);
        int n , k;
        ss >> n >> k;
        vector<int> T(n);
        for (int i = 0; i < n; i++){
            int t;
            cin >> t;
            T[i] = t;
        }
        cin.ignore();
        vector <vector<int>> F(n);
        int tam = 0;
        string pisos;
        for (int i = 0; i < n; i++) {
            getline(cin, pisos);
            istringstream ss(pisos);
            int p;
            while (ss >> p) {
                F[i].push_back(p);
                tam++;
            }
        }
        graph G = armarGrafo(n , T , F ,tam); //armo mi grafo
        unordered_map<Vertex, int, VertexHash> dij = dijkstra(G, G.start); // pido un diccionario a dijstra con el peso de cada nodo hacia mi raiz
        Vertex min;                                 
        int peso_min = numeric_limits<int>::max();
        
        for (int i = 0; i < n; i++){  

        Vertex v; v.piso = k ; v.ascensor = i+1;
        if(dij.find(v) != dij.end()){ // // como quiero llegar a un piso k y hay n ascensores voy a buscar cual tiene el camino minimo desde mi raiz
            if(dij[v] < peso_min){
            peso_min = dij[v];
            min = v;
            }
        }
        
    }
    res.push_back(peso_min); //guardo mi solucion
    }
    for (int i = 0; i < res.size(); i++){
        if(res[i] == numeric_limits<int>::max() ){
            cout << "IMPOSSIBLE" <<endl;
        }else{
            cout<<res[i]<<endl;
        }
    }
}




