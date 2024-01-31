#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include "ordenamiento_t.h"
#include "ordenamiento_rec_t.h"

using namespace std;
using namespace std::chrono;

// Prototipo de la función
bool incluirAlgoritmo(string listaAlgs, char alg);

// Función para medir el tiempo de ejecución de un algoritmo de ordenamiento
duration<double> medirTiempoOrdenamiento(int *A, int TAM_ARREGLO, void (*ordenamiento)(int *, int), string nombreAlgoritmo);

// Función para copiar un arreglo
int *copiarArreglo(int A[], int n);

// Función para calcular la desviación estándar de un conjunto de tiempos
void calcularDesviacionEstandar(double *tiempos, int repeticiones, double &desviacion);

// Función para realizar los experimentos de ordenamiento
void realizarExperimentos(int TAM_ARREGLO, int REPETICIONES, string listaAlgoritmos);

int main() {
    int TAM_ARREGLO, REPETICIONES;
    string listaAlgoritmos;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> TAM_ARREGLO;

    cout << "Ingrese el número de repeticiones: ";
    cin >> REPETICIONES;

    cout << "Ingrese la lista de algoritmos (m para Merge Sort, q para Quicksort, i para Merge Sort con Insertion Sort, b para bubblesort, n para insertion sort, s para selection sort): ";
    cin >> listaAlgoritmos;

    realizarExperimentos(TAM_ARREGLO, REPETICIONES, listaAlgoritmos);

    return EXIT_SUCCESS;
}

// Función para determinar si se debe incluir un algoritmo en los experimentos
bool incluirAlgoritmo(string listaAlgs, char alg) {
    size_t incluir = listaAlgs.find(alg);
    return incluir != string::npos;
}

// Función para medir el tiempo de ejecución de un algoritmo de ordenamiento
duration<double> medirTiempoOrdenamiento(int *A, int TAM_ARREGLO, void (*ordenamiento)(int *, int), string nombreAlgoritmo) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    ordenamiento(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double>>(fin - inicio);
    cout << nombreAlgoritmo << ": Ordenado. Tiempo: " << tiempo.count() << "s" << endl;
    return tiempo;
}

// Función para copiar un arreglo
int *copiarArreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}

// Función para calcular la desviación estándar de un conjunto de tiempos
void calcularDesviacionEstandar(double *tiempos, int repeticiones, double &desviacion) {
    double promedio = 0.0;
    for (int i = 0; i < repeticiones; i++) {
        promedio += tiempos[i];
    }
    promedio /= repeticiones;

    desviacion = 0.0;
    for (int i = 0; i < repeticiones; i++) {
        desviacion += pow(tiempos[i] - promedio, 2);
    }
    desviacion = sqrt(desviacion / repeticiones);
}

// Función principal para realizar los experimentos de ordenamiento
void realizarExperimentos(int TAM_ARREGLO, int REPETICIONES, string listaAlgoritmos) {
    int RANGO_MAX = 10 * TAM_ARREGLO;

    srand((unsigned)time(0));

    double tiempos_ms[REPETICIONES];
    double tiempos_qs[REPETICIONES];
    double tiempos_mis[REPETICIONES];
    double tiempos_buble[REPETICIONES];
    double tiempos_insertion[REPETICIONES];
    double tiempos_selection[REPETICIONES];

    for (int i = 0; i < REPETICIONES; i++) {
        cout << "*** REPETICION " << i + 1 << " ***" << endl;
        int *A = new int[TAM_ARREGLO];

        // Arreglo aleatorio
        cout << "Creando arreglo aleatorio de tamaño " << TAM_ARREGLO << "... " << flush;
        duration<double> tiempo = medirTiempoOrdenamiento(A, TAM_ARREGLO, [](int *A, int n) { crearArreglo(A, n, RANGO_MAX); }, "Creación de arreglo");
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;

        int *aux;

        aux = copiarArreglo(A, TAM_ARREGLO);
        tiempos_ms[i] = medirTiempoOrdenamiento(aux, TAM_ARREGLO, merge_sort, "Merge Sort").count();
        delete[] aux;

        aux = copiarArreglo(A, TAM_ARREGLO);
        tiempos_qs[i] = medirTiempoOrdenamiento(aux, TAM_ARREGLO, quicksort, "QuickSort").count();
        delete[] aux;

        int k;
        aux = copiarArreglo(A, TAM_ARREGLO);
        tiempos_mis[i] = medirTiempoOrdenamiento(aux, TAM_ARREGLO, [k](int *A, int n) { merge_sort_is(A, 0, n - 1, k); }, "Merge Sort con Insertion Sort").count();
        delete[] aux;

        aux = copiarArreglo(A, TAM_ARREGLO);
        tiempos_buble[i] = medirTiempoOrdenamiento(aux, TAM_ARREGLO, bubblesort, "BubbleSort").count();
        delete[] aux;

        aux = copiarArreglo(A, TAM_ARREGLO);
        tiempos_insertion[i] = medirTiempoOrdenamiento(aux, TAM_ARREGLO, insertion_sort, "Insertion Sort").count();
        delete[] aux;

        aux = copiarArreglo(A, TAM_ARREGLO);
        tiempos_selection[i] = medirTiempoOrdenamiento(aux, TAM_ARREGLO, selection_sort, "Selection Sort").count();
        delete[] aux;

        delete[] A;
        cout << endl;
    }

    // Calcular desviación estándar
    double desviacion_ms, desviacion_qs, desviacion_mis, desviacion_buble, desviacion_insertion, desviacion_selection;

    calcularDesviacionEstandar(tiempos_ms, REPETICIONES, desviacion_ms);
    calcularDesviacionEstandar(tiempos_qs, REPETICIONES, desviacion_qs);
    calcularDesviacionEstandar(tiempos_mis, REPETICIONES, desviacion_mis);
    calcularDesviacionEstandar(tiempos_buble, REPETICIONES, desviacion_buble);
    calcularDesviacionEstandar(tiempos_insertion, REPETICIONES, desviacion_insertion);
    calcularDesviacionEstandar(tiempos_selection, REPETICIONES, desviacion_selection);

    // Mostrar resultados
    cout << "*** TIEMPO PROMEDIO ***" << endl;
    if (incluirAlgoritmo(listaAlgoritmos, 'm')) {
        cout << "Merge Sort:\t" << calcularPromedio(tiempos_ms, REPETICIONES) << " s" << endl;
        cout << "Desviación Estándar:\t" << desviacion_ms << endl;
    }
    if (incluirAlgoritmo(listaAlgoritmos, 'q')) {
        cout << "QuickSort:\t" << calcularPromedio(tiempos_qs, REPETICIONES) << " s" << endl;
        cout << "Desviación Estándar:\t" << desviacion_qs << endl;
    }
    if (incluirAlgoritmo(listaAlgoritmos, 'i')) {
        cout << "Merge Sort con Insertion Sort:\t" << calcularPromedio(tiempos_mis, REPETICIONES) << " s" << endl;
        cout << "Desviación Estándar:\t" << desviacion_mis << endl;
    }
    if (incluirAlgoritmo(listaAlgoritmos, 'b')) {
        cout << "BubbleSort:\t" << calcularPromedio(tiempos_buble, REPETICIONES) << " s" << endl;
        cout << "Desviación Estándar:\t" << desviacion_buble << endl;
    }
    if (incluirAlgoritmo(listaAlgoritmos, 'n')) {
        cout << "Insertion Sort:\t" << calcularPromedio(tiempos_insertion, REPETICIONES) << " s" << endl;
        cout << "Desviación Estándar:\t" << desviacion_insertion << endl;
    }
    if (incluirAlgoritmo(listaAlgoritmos, 's')) {
        cout << "Selection Sort:\t" << calcularPromedio(tiempos_selection, REPETICIONES) << " s" << endl;
        cout << "Desviación Estándar:\t" << desviacion_selection << endl;
    }

    // Liberar memoria
}
