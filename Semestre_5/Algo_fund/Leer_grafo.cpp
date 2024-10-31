#include <iostream>
#include <vector>
#include <fstream>

using namespace std;


vector<vector<int>> leergrafo(string archivo){
    int n,m,t;

    vector<vector<int>> ady;
    ifstream miArchivo(archivo);

    if (miArchivo.is_open()){
        miArchivo >> n >> m>>t;
        ady.resize(n);
        for (int i = 0; i < m; i++){
            int a,b;
            miArchivo >> a >> b;
            ady[a-1].push_back(b-1);
            ady[b-1].push_back(a-1);
        }
        miArchivo.close();
    }
    else{
        cout << "No se pudo abrir el archivo" << endl;
    }
    return ady;

}

void imprimir(vector<vector<int>> ady){
    for (int i = 0; i < ady.size(); i++){
        cout << i+1 << ": ";
        for (int j = 0; j < ady[i].size(); j++){
            cout << ady[i][j]+1 << " ";
        }
        cout << endl;
    }
}

int main(){
    vector<vector<int>> ady = leergrafo("../grafo.txt");
    imprimir(ady);
    return 0;
}


