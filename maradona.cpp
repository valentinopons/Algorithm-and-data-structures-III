#include <iostream>
#include <vector>
#include <tuple>
#include <sstream>
#include <algorithm>
#include <string>

// funciones para ordenar primero por nombre, luego por defensa y por ultimo por ataque:
bool ordenar_por_nombre(std::tuple<std::string, int, int> jugador_1 , std::tuple<std::string, int, int> jugador_2){
    return std::get<0>(jugador_1) < std::get<0>(jugador_2);
}
bool ordenar_por_defensa(std::tuple<std::string, int, int> jugador_1 , std::tuple<std::string, int, int> jugador_2){
    return std::get<2>(jugador_1) > std::get<2>(jugador_2);
}
bool ordenar_por_ataque(std::tuple<std::string, int, int> jugador_1 , std::tuple<std::string, int, int> jugador_2){
    return std::get<1>(jugador_1) > std::get<1>(jugador_2);
}

void ordenar(std::vector<std::tuple<std::string, int, int>>& jugadores){
    std::stable_sort(jugadores.begin() , jugadores.end() , ordenar_por_nombre);
    std::stable_sort(jugadores.begin() , jugadores.end() , ordenar_por_defensa);
    std::stable_sort(jugadores.begin() , jugadores.end() , ordenar_por_ataque);      
}

void imprimir_soluciones(std::vector<std::vector<std::string>> atacantes_defensores , int casos){
        int c = 1;
        
        for(int j = 0 ; j < atacantes_defensores.size()-1;j= j+2){
            std::cout << "Case " << c++ << ":" << std::endl;
            std::cout<<"(";
            for(int a = 0 ; a < atacantes_defensores[j].size(); a++){
                std::cout << atacantes_defensores[j][a];
                if(a != atacantes_defensores[j].size()-1){
                    std::cout<<", ";

                }else{
                    std::cout<<")"<<std::endl;
                }
            }
            std::cout<<"(";
            for(int d = 0 ; d < atacantes_defensores[j+1].size(); d++){
                std::cout << atacantes_defensores[j+1][d];
                if(d != atacantes_defensores[j+1].size()-1){
                    std::cout<<", ";

                }else{
                    std::cout<<")"<<std::endl;
                }
            }
              
        }
    
}

int main() {
    int casos;
    std::string nombre;
    int ataque;
    int defensa;
    
    
    std::cin >> casos;
    std::cin.ignore(); // Descartar el salto de línea después de leer 'casos'
    std::vector<std::vector<std::tuple<std::string, int, int>>>lista_jugadores;
    std::vector<std::vector<std::string>> atacantes_defensores;
    
    for (int c = 0; c < casos; c++) {
        std::vector<std::tuple<std::string, int, int>>lista;
        for (int i = 0; i < 10; i++) { // cargo los jugadores correspondientes al caso c en lista_jugadores.
            std::string datos;              //Cada caso corresponde a una posicion del vector de vectores
            std::cin >> nombre >> ataque >> defensa;
            lista.push_back(std::make_tuple(nombre, ataque, defensa));

        }
        lista_jugadores.push_back(lista);  
        
    }

    for (auto& vec : lista_jugadores) {
    ordenar(vec);
    }
    for (int i = 0; i < casos; i++){
        std::vector<std::string> atacantes(5);
        std::vector<std::string> defensores(5);
        for (int j = 0; j < 5; j++){
            atacantes[j] = std::get<0>(lista_jugadores[i][j]);
        }
        for (int j = 0; j < 5; j++){
            defensores[j] = std::get<0>(lista_jugadores[i][j+5]);
        }
        atacantes_defensores.push_back(atacantes);
        atacantes_defensores.push_back(defensores);
        
    }
     for(int i = 0 ; i< atacantes_defensores.size() ; i++){
        std::stable_sort(atacantes_defensores[i].begin() , atacantes_defensores[i].end());   
     }

    imprimir_soluciones(atacantes_defensores , casos);

    return 0;
}