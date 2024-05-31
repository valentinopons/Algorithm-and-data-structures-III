#include <iostream>
#include <vector>
using namespace std;

int modulo(int x){
    if(x<0){
        return x*(-1);
    }else{
        return x;
    }
}
int parejasBaile(vector<int> s , vector<int> t){
    int contador = 0;
    int it = 0;
    for (int i = 0; i < s.size(); i++){
        if(it < t.size()){
            if(modulo(s[i] -t[it]) <= 1){
                contador++;
                it++;
            }
        }else if(it<t.size()-1){
            if(modulo(s[i] -t[it+1])<= 1){
                contador++;
                it++;
            }   
        }else{
            it= it+2;
        } 

           
    }
    return contador;
    
}

int main(){
cout << parejasBaile({1,2,4,6} , {1, 5, 5, 7, 9});
}