/*Jose Antonio González Martinez
A01028517*/

#include <iostream>
#include <vector>
using namespace std;
vector<double> aux;


void merge(vector<double>& a, int ini, int mitad, int fin){
    
    int i = ini, j = mitad + 1;

    for (int k = ini; k <= fin; k++){
        
        //copiar el arreglo original en el auxiliar
        aux[k] = a[k];
        

    }
    //Evaluamos cada elemento dentro del arreglo y lo escribimos en el arreglo original
    for (int k = ini; k <= fin; k++){

        if (i > mitad){
             a[k] = aux[j++];}

        else if (j > fin){ 
            a[k] = aux[i++];}

        else if (aux[j] > aux[i]) {
            a[k] = aux[j++];}
        else {
            a[k] = aux[i++];}
    }
    

}

void sort(vector<double>& a, int ini, int fin){
   
    if (fin <= ini) return;
    //Dividimos el arreglo en dos partes
    int mitad = ini + (fin - ini) / 2;
    //Evaluamos cada parte del arreglo
    sort(a, ini, mitad);
    sort(a, mitad + 1, fin);
    //Unimos las partes del arreglo
    merge(a, ini, mitad, fin);

} 

void makeMerge(int Tamaño) {
    cout<<endl<<"MergeSort"<<endl;
    vector<double>  numeros(Tamaño);
    aux.resize(Tamaño); 
    for (int i=0; i<Tamaño; i++){

        int randomInRange = rand() % 100 + 1;
        numeros[i]=randomInRange;
        
        
    }
    cout <<endl<< "Numeros sin ordenar: "<<endl;
    for (int i = 0; i < Tamaño; i++){
        cout << numeros[i] << " ";
    }
    
    sort(numeros, 0, Tamaño-1);
    cout <<endl<< "Numeros ordenados: "<<endl;
    for (int i = 0; i < Tamaño; i++){
        cout << numeros[i] << " ";
    }
    cout <<endl<<"---------------------------------"<<endl;
}

void swap(int* a,int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(vector<int>& a, int ini, int fin)
{
    //Tomamos el primer elemento como pivote
    int pivot=a[ini];
    int i=ini+1;
    int j = fin;
    while (true){
        //Mientra i sea mayor o igual al pivote lo mantenemos del lado izquierdo
        while (i <= fin && a[i] >= pivot) i++;
        //si j es menor al pivote lo mantenemos del lado derecho
        while (j >= ini && a[j] < pivot) j--;

        if (i >= j) break;
        //Cambiamos los elementos de lugar
        swap(&a[i], &a[j]);

    }
    //Cambiamos el pivote de lugar
    swap(&a[ini], &a[j]);
    return j;
}


void quick(vector<int>& a, int ini, int fin)
{
 if (ini < fin) {
    int pivot = partition(a, ini, fin); 
    quick(a, ini, pivot-1);
    quick(a, pivot+1, fin);

}
}





void makeQuick(int tamaño2) {
    cout<<endl<<"quicksort"<<endl;
    
    vector<int>  arrQuick(tamaño2);
     // Provide a size for the array 'numeros'
    for (int i=0; i<tamaño2; i++){

        int randomInRange = rand() % 100 + 1;
        arrQuick[i]=randomInRange;
       
    }
    cout <<endl<< "Numeros sin ordenar: "<<endl;
    for (int i = 0; i < tamaño2; i++){
        cout << arrQuick[i] << " ";
    }
    quick(arrQuick, 0, tamaño2-1);

    cout <<endl<< "Numeros ordenados: "<<endl;

    for (int i = 0; i < tamaño2; i++){
        cout << arrQuick[i] << " ";
    }
    cout <<endl<<"---------------------------------"<<endl;
}
int main(){
    srand(static_cast<unsigned int>(time(0)));
    // tenemos 4 casos con tamaños diferentes
    makeMerge(5);
    makeMerge(10);
    makeMerge(20);
    makeMerge(30);
    //el mismo caso para el quicksort
    makeQuick(5);
    makeQuick(10);
    makeQuick(20);
    makeQuick(30);

    //El merge sort cuenta con una comlpejidad de O(n log n) en el peor de los casos
    //Mientras que el quicksort con una de O(n^2) 
    
    return 0;
}