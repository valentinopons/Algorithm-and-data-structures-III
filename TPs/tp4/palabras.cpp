#include <iostream>
#include <vector>

using namespace std;
bool equivalentes(string a , string b){
    if(a.size() %  2 != 0){ //caso impar si son iguales devuelvo true sino false
        if(a == b){
            return true;
        }
    } else { 
        string a1, a2 ,b1 ,b2;
        a1 = a.substr(0,a.size()/2);
        a2 = a.substr(a.size()/2,a.size()/2);
        b1 = b.substr(0,b.size()/2);
        b2 = b.substr(b.size()/2,a.size()/2);
        if (a1 == b1 && a2 == b2 || a2 == b1 && a1 == b2){ 
            return true;
        }else{
        return (equivalentes(a1, b2) && equivalentes(a2, b1))
                || equivalentes(a1, b1) && equivalentes(a2, b2);
        }      
    }
    return false;
    
}

int main(){
    string a;
    string b;
    cin >> a;
    cin >> b;
    if(equivalentes(a,b)){
        cout<<"YES";
    }else{
        cout<<"NO";
    }
    
}
