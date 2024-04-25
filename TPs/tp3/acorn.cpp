#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> v;
int caminoMaximmo(vector<vector<int>>& l , int f){
    int max = l[0][0];
    


}


int main(){
    int datasets;
    cin >> datasets;
    vector<int> res;
    for (int d = 0; d < datasets; d++){
        int trees , height , f , num_acorn;
        cin >> trees >> height >> f;
        cin >> num_acorn; 
        vector<vector<int>> level(height+1, vector<int>(trees, 0));
        for (int t = 0; t < trees; t++){
            for (int a = 0; a < num_acorn; a++){
                int acorn;
                cin >> acorn;
                level[acorn][t] += 1;
                }   
        }

            

            
        
    }

  
}