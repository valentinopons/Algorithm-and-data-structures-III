#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<tuple<int,int>>> crearMatriz(){
    int k = 5;
    int i = 7;
    vector<vector<tuple<int,int>>> matriz = vector<vector<tuple<int,int>>>(i, vector<tuple<int,int>>(k));
    for ( int i1 = 0; i1 < i; i1++){
        for ( int j1 = 0; j1 < k; j1++){
            matriz[i1][j1] = make_tuple(-1,0);
        }
        
    }
    return matriz;
    
}

class Optipago{
    public:
    int costo_min_final = -1;
    int costo_min = 0; //llamado c` en el ejercicio
    int q_final = -1;
    int q = 0;
    vector<vector<tuple<int,int>>> matriz = crearMatriz();
    

    void optipago(vector<int> b , int i , int j){
        if ( j <= 0){
            if(costo_min < costo_min_final || costo_min_final < 0 ){
                costo_min_final = costo_min;
                q_final = q; 
            }else if(costo_min == costo_min_final){
                if (q < q_final || q_final < 0){
                    costo_min_final = costo_min;
                    q_final = q; 
                }
            }

        }else if(get<0>(matriz[i][j])!= -1){
                costo_min = get<0>(matriz[i][j]);
                q = get<1>(matriz[i][j]);
                return;
         
        }else if(i >= 0){
            // como hago la recursion?
            

        }
        cout<<"No alcanzan los fondos";
        return;

    }

};
int main(){
    Optipago x;
    vector <int> b = {2,3,5,10,20,20};
    int k = 5;
    x.optipago(b, b.size()-1 , k);
    cout <<"c`: " <<x.costo_min_final << endl;
    cout << "q: " << x.q_final <<endl;
}