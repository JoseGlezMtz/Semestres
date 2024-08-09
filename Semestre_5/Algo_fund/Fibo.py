fibo_arreglo=[]

def fibo(n):
    for i in range (n):
        fibo_arreglo[i]=fibo_arreglo[i-1]+fibo_arreglo[i-2]
    return fibo_arreglo[n]


fibo(2)