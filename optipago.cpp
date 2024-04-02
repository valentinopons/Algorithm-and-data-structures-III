#include <iostream>
#include <vector>
using namespace std;

class Optipago{
    public:
    int costo_min_final = -1;
    int costo_min = 0; //llamado c` en el ejercicio
    int q_final = -1;
    int q = 0;
    

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

        }else if(i >= 0){
            optipago(b,i-1,j);
            costo_min = costo_min + b[i]; q++;
            optipago(b,i-1,j-b[i]);
            costo_min = costo_min - b[i]; q=q-1;

        }


    }

};
int main(){
    Optipago x;
    vector <int> b = {2,3,5,10,20,20};
    x.optipago(b, b.size()-1 , 45);
    cout <<"c`: " <<x.costo_min_final << endl;
    cout << "q: " << x.q_final <<endl;
}