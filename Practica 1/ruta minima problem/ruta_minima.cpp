#include <iostream>
#include <vector>
using namespace std;

class Ruta_minima{
    public:
    int suma_minima = -1;
    vector<vector<int>> matriz;
    vector<int> res;
    vector<int> res_p;
    vector<int> valores_usados;
    int n;
    int pi(int i){
        return res_p[i];
    }
    int suma(){
        int s = matriz[pi(n-1)][pi(0)];
        for (int i = 0; i < n-1; i++){
            s = s + matriz[pi(i)][pi(i+1)];
        }
        return s;
        

    }
    void ruta_minima(){
        if(res_p.size() == n){
            int s = suma();
            if(suma_minima == -1 || s < suma_minima ){
                suma_minima = s;
                res = res_p;
            }
        }else{
            for (int i = 0; i < n; i++) {
                if (valores_usados[i]== 0){
                res_p.push_back(i);
                valores_usados[i]=1;
                ruta_minima();
                valores_usados[i]=0;
                res_p.pop_back();
                }
            }
            

        }
    }

};
int main(){
    Ruta_minima r;
    r.n = 4;
    r.matriz={
        {0,1000,10,10},
        {10,0,3,15},
        {21,17,0,2},
        {1,22,30,0}
    }; 
    for (int i = 0; i <= r.n; i++){
        r.valores_usados.push_back(0);    
    }
    r.ruta_minima();
    for (int i : r.res){
        cout<< i+1 << " ";
    }
    cout<<""<<endl;
    cout << r.suma_minima;
    
    
    


}
