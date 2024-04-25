#include <iostream>
#include <vector>
using namespace std;
vector<int> subseq(vector <int> s , int i , int j){
    vector<int> res;
    for (int i1 = i; i < j; i++){
        res.push_back(s[i]);
    }
    return res;
    
}
int dissort(vector<int> s){
    if(s.size() % 2 != 0){
        if(s[s.size()-1] > s[s.size()-2]){
            return 1+ dissort(subseq(s,0,s.size()-2));
        }
        return dissort(subseq(s,0,s.size()-2));
    }
    if(s.size() == 2){
        if(s[0]> s[1]){
            return 1;
        }else{
            return 0;
        }

    }else {
        if(s[s.size()/2-1] > s[s.size()/2]){
            return 1 + dissort(subseq(s,0,s.size()/2)) + dissort(subseq(s,s.size()/2 , s.size()));
        }else{
            return dissort(subseq(s,0,s.size()/2)) + dissort(subseq(s,s.size()/2 , s.size()));

        }   
    }

}

int main(){
    cout << dissort({4,3,2,4,5,3,8,9});    
}