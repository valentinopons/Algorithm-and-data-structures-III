#include <iostream>
#include <vector>
#include <limits>  //falta memoizar.
using namespace std;
vector<vector<int>> m= {{-2,-3,3},
                        {-5,-10,1},
                        {10,30,-5}
                        };

int TV(int i , int j){
    if(i == m.size() || j == m[0].size()){
        return INT_MAX;

    }else if(i== m.size()-1 && j == m[0].size()-1){
        return 1-m[i][j];                                 //fijarse funcion recursiva

    }else{
       return max(1,min(TV(i+1,j)- m[i][j] , TV(i,j+1) - m[i][j]));

    }
}
int bottom_up(){ //falta bottom up
    return 0;
}

int main(){
cout << TV(0 ,0);
}




