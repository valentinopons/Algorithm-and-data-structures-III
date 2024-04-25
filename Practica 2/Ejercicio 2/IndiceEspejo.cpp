#include <iostream>
#include <vector>
#include <limits>
using namespace std; 

bool indiceEs(vector<int> v){
    if(v.size()== 0){
        return false;
    }
    if(v[v.size()/2] == v.size()/2 +1){
        return true;

    }else{
         if(v[v.size()/2] > v.size()/2){
            vector<int> v1(v.size()/2 );
            for (int i = 0; i < v.size()/2; i++){
                v1[i] = v[i];
            }
             return indiceEs(v1);

         }else{
            vector<int> v1(v.size()/2);
            for (int i = 0; i < v.size()/2; i++){
                v1[i] = v[v.size()/2 +i];
            }
             return indiceEs(v1);
         }
         
        }
}


int main(){
    cout<<indiceEs({-4,2,5,6,7});
}