#include <iostream>
#include <vector>
#include <limits>
using namespace std;



int skylinesIncr(vector<int> &h, vector<int> &w) { //funcion que calcula el incremento utiliza tecnica bottom up
    if(h.size() == 1){ 
        return w[0];
    }
    vector<int> v(h.size());
    v = w;
    int res =  w[0];
    for (int i = 1; i < h.size(); i++){ // utilizo dos for para recorrer el arreglo
        for (int j = 0; j < i; j++){
            if(h[i]>h[j]){
                if(v[i] < w[i]+v[j]){
                    v[i] = w[i] +v[j]; // cada posicion de v va a contener al final de los dos ciclos la maxima subsequencia hasta ese punto.
                    if(res< v[i]){
                    res = v[i];
                    }
                }
            }else{
                if(res< v[i]){
                    res = v[i];
                }
        }
    }
        
    }
    return res;
    
}
int skylinesDecr(vector<int> &h, vector<int> &w) { // lo mismo pero con decreciente
    if(h.size() == 1){
        return w[0];
    }
    vector<int> v(h.size()); 
    v = w;
    int res =  w[h.size()-1];
    v[h.size()-1] = w[h.size()-1];
    for (int i = h.size()-2; i >= 0; i--){
        for (int j = h.size()-1; j > i; j--){
            if(h[i]>h[j]){
                if(v[i] < w[i]+v[j]){
                    v[i] = w[i] +v[j];
                    if(res< v[i]){
                    res = v[i];
                    }
                }
            }else{
                if(v[i]==-1){
                    v[i] = w[i];
                }
                if(res< v[i]){
                    res = v[i];
                }
        }
    }
        
    }
    return res;
    
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int casos;
    cin >> casos;
    vector<int> res(casos*2); //este vector alfinal va a contener las incr y decr de cada caso
    int it = 0; // it los es un iterador que utilizo mas adelante
    for (int i = 0; i < casos; i++) {
        int largo;
        cin >> largo;
        vector<int> altura(largo);
        vector<int> ancho(largo);
        for (int h = 0; h < largo; h++) {
            cin >> altura[h];
        }
        for (int w = 0; w < largo; w++) {
            cin >> ancho[w];
        }

        int incr = skylinesIncr(altura,ancho);
        int decr = skylinesDecr(altura,ancho);
        res[it] = incr;
        res[it+1] = decr;
        it=it+2;
        
    }
    int caso = 1;
    for (int j = 0; j < res.size()-1; j=j+2){ //recorro los resultados obtenidos impimiendolos en pantalla.
        if(res[j] >= res[j+1]){
            cout<<"Case "<<caso<<". Increasing ("<<res[j]<<"). "<<"Decreasing ("<<res[j+1]<<")."<<endl;
        }else{
            cout<<"Case "<<caso<<". Decreasing ("<<res[j+1]<<"). "<<"Increasing ("<<res[j]<<")."<<endl;

        } 
        caso++;
    }
    
    

    return 0;
}

