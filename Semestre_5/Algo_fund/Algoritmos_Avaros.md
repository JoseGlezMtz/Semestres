## Algoritmos Avaros

Paradigma de diseño de algoritmos que cosiste en una serie de pasos que sean la mejor decision a "corto plazo" de acuerdo a aalgun criterio

Tomada la decision no se puede revertir, por lo que no siemore encuentran la solución correcta

"solo toma la mejor decisión con la información al rededor sin ver a futuro"

PELIGRO: La mayoría de los algoritmos avaros NO SON CORRECTOS 

1. Inicializar respueata en vacio
2. Se tiene respuesta al problema? regresar respiesta

3. hacer una selección mas:
    - Seleccionar la mejor opcion posible, es decir, la que "Mas mejore" la respuesta

Ejemplos: 
- Distancia más corta de Dijkstra
- Arbol de expanción mínimo de Prim
- Árbol de expancion mínimo de kruskal

Sirven para resolver problemas de grafos

### programación dinamica

Es una tecnoica de diseños de algoritmos que se utilizaa para reducir el trabajo de algunos algoritmos

programación: Serie de opciones
Dinamica: las opciones pueden depender del estado actual

Se puede aplicar a todos los algoritmos mientras la solición dependa de un problema menor

Un algortmo dinamico almacena resultados o soluciones de subproblemas mas pequeños y luego lso consulta en lugar de calcularlos otra vez

este proceso se llma "Memoization"

