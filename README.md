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


# Análisis de datos
De acuerdo a los resultados obtenidos, tanto los tiempos de ejecución y la desviación estandar varían para cada repetición y algoritmo. Estos datos proporcionan una visión de la estabilidad y consistencia de cada algoritmo, destacando posibles tendencias o patrones que pueden influir en su rendimiento.  
Para cada tamaño de arreglo(**n**), el número de repeticiones(**m**) que se utilizó fueron **30**, esto para obtener estadísticas más confiables. 

## Gráficas de cada caso
Entonces, en las siguientes tablas podemos observar los tiempos de ejecución y la desviación estandar de cada arreglo: 

- m=30 n=5
  ![arreglo 5](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/60969217-f71e-417d-a3bb-53cbeadd33f8)

  En términos de timepo promedio, los algortimso se ordenan de manera: **Merge sort> Quicsort > Bubblesort > Insertion sort > Selection sort**.  
  La desviación estandar sugiere que los tiempos de ejecución son bastante consistentes en todas las repeticiones para cada algoritmo.

- m=30 n=10
  ![arreglo 10](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/33423612-eb05-4b14-bea5-d583e3ce2892)

  Para este **Quicksort** muestra el tiempo promedio más bajo, seguido por **Insertion sort, selection sort, bubble sort y merge sort**.
  **Insertion sort tiene la desviación estandar más baja, indicando mayor estabilidad en los tiempos de ejecución.

- m=30 n=50
  ![arreglo 50](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/00745298-694d-4e76-9d0f-51a7cf979f82)

  Tanto **Quicksort** como **Merge Sort** son consistentes en sus tiempos de ejecución. La elección de usos de cada uno puede depender de otras cosas como el espacio de memoria.
  **Bubble sort** tiene una desviación relativamente alta, por lo que indica variabilidad en los tiempos de ejecución.

- m=30 n=100
  ![arreglo 100](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/359b20cd-5bd0-4f23-a158-f6ad62dbb8e6)

  Tanto **Quicksort** como **Insertion Sort** son consistentes en sus tiempos de ejecución a diferencia de **Bubble sort** el cual muestra una variabilidad en sus tiempos de ejecución, lo que sugiere que puede ser menos predecible.

- m=30 n=500
  ![arreglo 500](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/ab02cee8-5cfb-4003-b1c6-0a17ff42ac40)

  Sugieren que el algoritmo más eficiente en términos de tiempo promedio es **Quicksort**, seguido de **Merge sort**. Los algoritmos de **Bubble, Insertion** y **Selection sort** tienen tiempos promedio significativamente mayores.

- m=30 n= 10^3 
  ![arreglo 1000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/9d388c93-d729-4d37-9d5e-872991249ca9)

  Indican que **Quicksort** es el algortimo más eficiente en términos de tiempo de ejecución promedio, seguido por **Merge sort** e **Insertion sort**. **Bubble sort** y **Selection sort** tienen tiempos promedio más altos.

- m=30 n= 5x10^3
  ![arreglo 5000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/20677d8c-b6a1-4188-bbea-454a80b1c0fc)

  En este caso, **Quicksort y Merge sort** son opciones sólidas, con **Quicksort** siendo ligeramente más eficiente en este escenario específico. **Bubble sort** es cocnsiderablemente más lento, teniendo a **Insertion sort y Selection sort** de opción intermedia.

- m=30 n= 10^4
  ![arreglo 10000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/54da514b-bcdd-42c3-afa9-87d456e40cbc)

  **Quicksort** sigue siendo la opción preferida en términos de eficiencia y consistencia, junto con **Merge sort**. **Bubble sort**, por otro lado, es menos eficiente.

- m=30 n= 5x10^4
  ![arreglo 50000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/f4f122f9-ebed-47e6-a065-ef8493dfbe3a)


- m=30 n= 10^5
  ![arreglo 100000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/c60739c5-e7a7-4150-8f04-de5fe3d759ea)

  En promedio, **Merge sort** es el algoritmo más eficiente, seguido de **Quicksort**. Sin embargo, **Bubble sort** muestra un rendimiendo significativamente bajo en comparación con los otros algoritmos.

Debido a estos datos podemos decir que, para arreglos grandes los algoritmos que mejor trabajan son **Merge sort** y **Quicksort** por lo que, proseguiremos con esos, de lo contrario, el tiempo de ejecución de cada caso sería muy extenso, lo cual, queremos evitar: 

- m=30 n= 5x10^5
  ![arreglo 500000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/9043fc25-7996-4457-ba3f-cdf24b98eae3)


- m=30 n= 10^6
  ![arreglo 1000000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/b2d14861-a275-4815-8741-f8561d4eee32)

- m=30 n= 5x10^6
  ![arreglo 5000000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/ceaf34dc-fe5d-41fa-bc27-a3142a041a74)

- m=30 n= 10^7
  ![arreglo 10000000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/27fe4829-3d7d-42be-9eb2-d71371a6e3b5)

- m=30 n= 5x10^7
  ![arreglo 50000000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/e19bebe7-72b3-4ad5-b8d0-264722877e6a)

- m=30 n= 10^8
  ![arreglo 100000000](https://github.com/AGN-Teaching/practica-4-algoritmos-de-ordenamiento-absaae/assets/125155934/18fcf206-87eb-4f2f-8e48-f2de6e19e038)





  


  








