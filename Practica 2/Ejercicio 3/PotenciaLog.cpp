#include <iostream>
#include <vector>
#include <limits>
using namespace std; 

int potLog(int a , int b){
    if(b == 1){
        return a;
    }else{
        if(b % 2 == 0){
            int res = potLog( a , b / 2);
            return res*res;
        }else{
            int res =  a * potLog(a , (b-1)/2);
            return res*res;
        }
    }
}

int main(){
    cout<<potLog(4,2);
    
}