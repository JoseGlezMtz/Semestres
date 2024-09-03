aux=[]

def lista():
    lista=[]
    tamaño=int(input("Ingrese el tamaño de la lista: "))
    for i in range(tamaño):
        num=int(input("Ingrese el numero: "))
        lista.append(num)
    
    sort(lista, lista[0],lista[tamaño-1])
    print(lista)
    
    
def sort(lista, inicio, fin):
    if fin<=inicio:
        return
    else:
        mitad=inicio- (inicio+fin)/2
        sort(lista, inicio, mitad)
        sort(lista, mitad+1, fin)
        merge(lista, inicio, mitad, fin)

def merge(lista, inicio, mitad, fin):
    for i in range(inicio, fin+1):
        aux[i]=lista[i]
    i=inicio
    j=mitad+1
    
    for k in range(inicio, fin+1):
        if i>mitad:
            lista[k]=aux[j]
            j+=1
        elif j>fin:
            lista[k]=aux[i]
            i+=1
        elif aux[j]<aux[i]:
            lista[k]=aux[j]
            j+=1
        else:
            lista[k]=aux[i]
            i+=1
    return lista

lista()