#include <iostream>
#include <vector>
#include <tuple>
#include <set>
class Maxisubconjunto{
    public:
    int k = 3;
    int n = 4;
    std::vector<std::vector<int>> matriz={
        {0  ,10  ,10  ,1},
        {1  ,0   ,5   ,2},
        {2  ,5   ,0   ,1},
        {1  ,10  ,10  ,0}
    };
    std::set<int> res;
    int suma_maxima = 0;
    std::set<int> conjunto_actual;

    int suma(std::set<int> res){
        int suma_actual = 0;
        for (int i : res){
            for(int j : res){
                if(i!= 0 && j!=0){
                suma_actual = suma_actual + matriz[i-1][j-1];
                }
            }
        }
        return suma_actual;
    }
    void maxisubconjunto(int v){
        if (conjunto_actual.size() == k){
            int  s= suma(conjunto_actual);
            if (s > suma_maxima){
                suma_maxima = s;
                conjunto_actual.erase(0);
                res = conjunto_actual;
            }
        }else if(v <= n) {

                conjunto_actual.insert(v);
                maxisubconjunto(v+1);
                conjunto_actual.erase(v);
                maxisubconjunto(v+1);            
        }
    }
    };

int main(){
    Maxisubconjunto x;
    x.maxisubconjunto(1);
    for (int i : x.res){
        std::cout<< i << " "<<std::endl;
    }
    std::cout<< x.suma_maxima;
    
        return 0;
}
