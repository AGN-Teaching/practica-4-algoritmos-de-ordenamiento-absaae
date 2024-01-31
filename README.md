[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/ke8zCzPd)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-7f7980b617ed060a017424585567c406b6ee15c891e84e1186181d67ecf80aa0.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=13588008)
# Práctica 4: Algoritmos de ordenamiento

# Introducción

## Objetivos
Verificar de forma experimental el tiempo de ejecución de algunos algoritmos de ordenamiento. 

## Antecedentes

El problema abordado en este conjunto es el de ordenamiento de arreglos. El objetivo es analizar experimentalmente el rendimiento de cinco algoritmos de ordenamiento: **'insertion sort'**, **'selection sort'**, **'bubble sort'**, **'merge sort'**, y **'quick sort'**. El proceso de experimentación implica generar arreglos aleatorios de diferentes tamaños y ordenarlos con cada uno de los algoritmos mencionados. La medición del tiempo de ejecución se realiza para obtener datos cuantitativos sobre la eficiencia de cada algoritmo. 


# Análisis del problema

Como mencionamos en los antecedentes, de centra en la evaluación de cinco algoritmos de ordenamiento. El objetivo es analizar cómo se comportan en distintos tamaños de entrada y proporcionar conclusiones informadas sobre su rendimiento. 
Para poder realizarlo hay que tener en cuenta el funcionamiento de los cinco algoritmos de ordenamiento: 
- **Insertion sort**  
  Para este método la matriz se divide en una parte ordenada y otra no ordenada. Los valores de la parte no ordenada se seleccionan y se colocan en la posición correcta en la parte ordenada.
  Para ordenar una matriz de tamaño **n** en orden ascendente, hay que iterar sobre la matriz y comparar el elemento actual (clave) son su predecesor, y compararlo con los elementos anteriores.
  
  ![insertionsort](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/93640e4c-b551-4661-9972-60f4cf6d42f0)

  Después se mueven los elementos mayores una posición hacia arriba para dejar el elemento intercambiado.

- **Selection sort**  
  El algoritmo selecciona repetidamente el elemento más pequeño (o más grande) de la parte no ordenada de la lista y lo intercambia con el primer elemento de la parte no ordenada. Este proceso se repite hasta que la parte restante sin ordenar hasta que se ordena toda la lista.

  ![selection sort](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/20ebe34b-941d-465b-8699-f149aa70554f)

- **Bubble sort**  
  Para este método se recorre desde la izquierda y compara los elementos adyacentes, el más alto se coloca en el lado derecho. De esta manera, el elemento más grande se mueve al extremo derecho del principio. Este proceso continúa para encontrar el segundo más grande y colocarlo, y así sucesivamente hasta que se ordenan los datos.
  
  ![bubble sort](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/e3bacb1c-5abb-44bc-ae57-125bd57916d4)

- **Merge sort**  
  Este es un algoritmo recursivo que divide continuamente la matriz por la mitad hasta que no se puede dividir más, es decir, a la matriz solo le queda un elemento. Divide la matriz en dos mitades, ordena cada mitad y luego vuelve a fusionar las mitades ordenadas. Este proceso se repite hasta que se ordena toda la matriz.

  ![merge sort](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/42874ae8-dafb-4f49-a101-2084e5e7e306)

- **Quick sort**  
  Para este método, el proceso clave es una partición. El objetuvi de las particiones es colocar el pivote(generalmente es el último elemento) en su posición correcta en la matriz ordenada y colocar todos los elementos más pequeños a la izquierda del pivote y todos los elementos mayores a la derecha del pivote. La partición se realiza de forma recursiva a cada lado del pivote después de que el pivote se coloca en su posición correcta y esto finalmente ordena la matriz.
  
  ![quicksort](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/96e9dd07-ce2f-4d4b-9cc8-4eeb82938fc7)



  
