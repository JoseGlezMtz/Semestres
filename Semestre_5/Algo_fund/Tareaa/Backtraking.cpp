#include <iostream>
#include <vector>

#include <climits>
using namespace std;


 int columnas;
 int filas;

vector<vector<int>> solucion;
vector<vector<int>> solucionFinal;
int camino_final = 100000;

void backtracking(vector<vector<int>>& laberinto, int x, int y, vector<vector<int>>& Final) {
    if (x == filas - 1 && y == columnas - 1) { 
        Final[x][y] = 1; // Si llegamos al final
        cout << "Backtraking" << endl;
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                cout << Final[i][j] << " ";
            }
            cout << endl;
        }
        return;
    }
    if (x < 0 || y < 0 || x >= filas || y >= columnas) {  // Si estamos fuera del laberinto
        return;
    }
    if (laberinto[x][y] == 0) {  // Si la casilla está bloqueada
        return;
    }
    else{ 
    Final[x][y] = 1;
    laberinto[x][y] = 0;  // Marcar la casilla como visitada 
    backtracking(laberinto, x + 1, y,Final);  // Moverse hacia abajo
    backtracking(laberinto, x - 1, y,Final);  // Moverse hacia arriba
    backtracking(laberinto, x, y + 1,Final);  // Moverse hacia la derecha
    backtracking(laberinto, x, y - 1,Final);  // Moverse hacia la izquierda
    laberinto[x][y] = 1;  }
}




void BranchAndBound(int x, int y, int Tam_camino, vector<vector<int>>& laberinto) {
    if (x == filas - 1 && y == columnas - 1) {
        solucion[x][y] = 1;
        if (Tam_camino < camino_final) { 
        
            camino_final = Tam_camino;
            solucionFinal = solucion;
        }
        return;
    }
    if ( x >= 0 && x < filas && y >= 0 && y < columnas && laberinto[x][y] == 1) {
        solucion[x][y] = 1;
        cout << x<<" "<< y << endl;

        if(Tam_camino + 1 < camino_final){

         BranchAndBound(x + 1, y, Tam_camino + 1, laberinto); 
         BranchAndBound(x, y + 1, Tam_camino + 1, laberinto); 
         BranchAndBound(x - 1, y, Tam_camino + 1, laberinto); 
         BranchAndBound(x, y - 1, Tam_camino + 1,laberinto); 
         
        }

        solucion[x][y] = 0;
        }

    
     
}



void Laberinto() {
    cout << "Ingresa numero de columnas: ";
    
    cin >> columnas;
    cout << "Ingresa numero de filas: ";
    
    cin >> filas;
    vector<vector<int>> laberinto; 

    for (int i = 0; i < filas; i++) {
        vector<int> temp;  // Vector temporal para cada fila
        for (int j = 0; j < columnas; j++) {
            int valor;
            cout << "Ingresa el valor de la casilla [" << i << "][" << j << "]: ";
            cin >> valor;
            temp.push_back(valor);  // Agregar el valor a la fila
        }
        laberinto.push_back(temp);  // Agregar la fila al laberinto
    }

    cout << "Laberinto" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << laberinto[i][j] << " ";
        }
        cout << endl;
    }
    
    vector<vector<int>> Final;
    Final.resize(filas, vector<int>(columnas, 0));
    backtracking(laberinto, 0, 0, Final);  // Llamar a la función backtracking
    


    solucion.resize(filas, vector<int>(columnas, 0));
    solucionFinal.resize(filas, vector<int>(columnas, 0));
    BranchAndBound(0,0,0,laberinto); 

    cout << "B&B" << endl;
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            cout << solucionFinal[i][j] << " ";
        }
        cout << endl;
    }

    
}






    
int main() {
    Laberinto();
    return 0;
}
