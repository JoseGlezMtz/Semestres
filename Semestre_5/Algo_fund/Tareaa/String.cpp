#include <iostream>
using namespace std;
#include <vector>

void funcion_z (string s){
    vector<int> Arreglo(s.size(),0);

    for (int i=1;i<s.size(); i++){

        for (int j=i;j<s.size(); j++){
            
        if (s[j]==s[j-i]){
            Arreglo[i]++;
        }
        else{
            
            break;
        }

        }
    }
    
    for (int k=0; k<=Arreglo.size(); k++){
        cout<<Arreglo[k]<<endl;
    }
}

int main(){

    funcion_z("aaabaaab");
}
