#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

int vinos(vector<long long int>& h){
    int contador = 0;
    for (int i = 0; i < h.size()-1; i++){
        if(h[i]<0){
            h[i+1] = h[i] + h[i+1]; 
            contador += -h[i];
        }else if (h[i]>0){
            h[i+1] = h[i] + h[i+1]; 
            contador += h[i];
        }
        }
    
    return contador;
    
}


int main(){
    std::ios_base::sync_with_stdio(false);
    vector<long long int> res(0);
    int h;
    cin >> h;
    while(h != 0){
        vector<long long int> habitantes;
        long long int num;
        string input;
        for (int i = 0; i < h; ++i) {
            std::cin >> num;
            habitantes.push_back(num);
        }
        getline(cin, input);
        res.push_back(vinos(habitantes));

        cin >> h;
        
        
}

    for (int i = 0; i < res.size(); i++){
        cout<<res[i]<<endl;
    }

}
