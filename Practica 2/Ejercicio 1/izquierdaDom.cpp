#include <iostream>
#include <vector>
#include <limits>
using namespace std;  
bool izqDom(vector<int> v){
    if(v.size() == 1){
        return true;    
       
    }else{
        int sumai = 0;
        int sumaf = 0;
        vector<int> v1(v.size()/2);
        vector<int> v2(v.size()/2);
        for (int i = 0; i < v.size() / 2 ; i++){
            v1[i] = v[i];
            v2[i] = v[v.size()/2 + i];
            sumai += v[i];
            sumaf += v[v.size()/2 + i];
        }

        if(sumai > sumaf){
            return izqDom(v1) && izqDom(v2);
        }else{
            return false;
        }
    
    }
}


int main(){
    cout<<izqDom({8,4,7,6,5,1,3,2});
    

}