## Busqueda y ordenamiento

**Busqueda**

En computanción "buscar" significa ver si un elemento particular pertenece o no

Un algoritmo de busqueda recibe un dato, el cual busca generalemten en un arreglo

_Formas de buscar en arreglos_

- *Secuancial*: para cualquier arreglo
- *Binaria*: Sólo para arreglos ordenados
- *Transfomarción* de claves: Funciones Hash

#### Busqueda sequencial

la forma trivial de buscar en un arreglo es hacerlo elemento por elemento

"Complejidad O(n)"

si lo mejoramos puede dar O($\sqrt{n}$)

#### Busqueda binaria

Se debe hacer en un arreglo ordenado, consiste en partir el arreglo en dos

"complejidad $O(\log{n})$"

### Ordenamiento 

#### Selecction sort

Seleccionar el menor en cada paso y colocarlo en la parte superior del arreglo

$O(n^2)$


#### Bubble Sort

Se van comparando de dos en dos y en la primera pasada tenemos el mas grande hasta abajo

$O(n^2)$

#### Insertion Sort

se va comoparando todos los elementos y si es menor/mayor se hace el cambio hasta que alcance su lugar

$O(n^2)$

$$\frac{pendejo}{jose}=baboso$$


#### Merge sort

Se divide el arreglo y ordena cada parte para despues juntarlos

$O(n\log{n})$

#### Quick sort

se escoge un pivote y se hace una partición y se agregan todos los que son menores del lado izquierdo y los mayores del lado derecho

$O(n\log{n})$
