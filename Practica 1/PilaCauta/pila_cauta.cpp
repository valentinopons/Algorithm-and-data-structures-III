#include <iostream>
#include <vector>
#include <limits> 
using namespace std;
int N = 5;
vector <int> w = {19, 7, 5, 6, 1};
vector <int> s = {15, 13, 7, 8, 2};
bool cumple_requisitos(int caja1 , int caja2){
    if(s[caja1] >= w[caja2]){
        return true;
    }else{
        return false;
    }

}
int PC(int i){
    if(i == N){
        return 0;
    }else{
        int res = 0;
        for (int t = i+1; t < N; t++){
           if(cumple_requisitos(i , t)){
               int res1 = max(PC(t)+1 , PC(t));
               res = max(res,res1);
            }else{
                PC(t);
            }
            
        
        }
    return res;
    }
}


int main(){
    cout<< PC(0);
}