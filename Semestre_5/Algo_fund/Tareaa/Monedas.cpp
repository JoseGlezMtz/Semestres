/*Jose Antonio González Martinez
A01028517*/

#include <iostream>
#include <vector>
#include <list>
using namespace std;

//en la función greedy, solo escoremos las monedas de mayor a menor, y vamos restando la cantidad de dinero que se tiene
void Monedas_greedy(int cantidad, vector<int> monedas){
    int i = 0;
    while(cantidad > 0){
        if(cantidad >= monedas[i]){
            cout << monedas[i] << " ";
            cantidad -= monedas[i];
        }
        else{
            i++;
        }
    }
}

void Monedas_DP(vector<int> monedas, int cantidad){
    //creamos los dos vectores en los cuales iremos guardando los datos requeridos
    vector<int> MNM(cantidad + 1, 0);
    vector<int> ultima_moneda(cantidad + 1, -1);

    int NM=0;
    MNM[0] = 0;
    //iremos recrrineod el vector de monedas
    for (int i = 1; i <= cantidad; i++){
        MNM[i] = 1e9;

        for (int j = 0; j < monedas.size(); j++){
            //si la moneda es menor o igual a la cantidad
            if (i>=monedas[j]){
                NM=MNM[i-monedas[j]]+1;

                if(NM<MNM[i]){
                    //guardamos el numero de monedas que se utilizaron para llegar a la cantidad
                    MNM[i]=NM;
                    //guardamos la ultima moneda que se utilizó para llegar a la cantidad
                    ultima_moneda[i] = monedas[j];
                }
            }
        }
    }
    cout << "Monedas usadas: ";
    cout << MNM[cantidad] << endl;

    //aqui nos regresaremos para poder encontrar cuales fueron las monedas que se encontraron 
    int valor_restante = cantidad;
    while (valor_restante > 0) {
        //aqui tomamos la ultimammoneda que se usó para llegar al valor en el cual nos encontramos
        int moneda_usada = ultima_moneda[valor_restante];
        if (moneda_usada == -1) {
            // Si no hay moneda usada, significa que no se pudo formar la cantidad exacta
            cout << "No se puede dar cambio." << endl;
            return;
        }
        cout << moneda_usada << " "; // Imprimimos la moneda utilizada
        valor_restante -= moneda_usada; // Restamos el valor de la moneda para avanzar
    }

}




int main(){
    cout<<"Ingrese la cantidad de las monedas: "<<endl;
    int cantidad;
    
    cin>>cantidad;
    vector<int> monedas(cantidad);
    cout<<"Ingrese las denominacionesde las monedas (de mayor a menos): "<<endl;

    for (int i = 0; i < cantidad; i++){
        cout<<"Ingrese la moneda "<<i+1<<": "<<endl;
        cin>>monedas[i];
        cout<<endl;
    }
    
    cout<<"Ingrese el precio del producto: "<<endl;
    int precio;
    cin>>precio;

    cout<<"Ingrese cantidad pagada: "<<endl;
    int pagado;
    cin>>pagado;

    cout<<"resultado greedy: "<<endl;
    Monedas_greedy(pagado - precio, monedas);
    cout << endl;

    cout<<"resultado DP: "<<endl;
    Monedas_DP(monedas, pagado - precio);
    return 0;
}