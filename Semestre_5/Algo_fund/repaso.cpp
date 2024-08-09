#include <iostream>

using namespace std;

 

int Fibo_recursive(int n){
    if (n == 0) return 0;
    if (n == 1) return 1;
    return Fibo_recursive(n-1) + Fibo_recursive(n-2);
}

int Fibo_naiv(int n){
    if (n<=1) return n;
    return Fibo_recursive(n-1) + Fibo_recursive(n-2);
}

int main(){
    Fibo_recursive(46);
    return 0;
}