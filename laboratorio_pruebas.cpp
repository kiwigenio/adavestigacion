#include "laboratorio_pruebas.h"
#include "funciones_strassen.h"
#include <iostream> 
#include <chrono>
#include <algorithm>
#include <fstream>

using namespace std;
using namespace std::chrono;

LaboratorioPruebas::LaboratorioPruebas(vector<int> tamanos, int num_pruebas, string nombre_archivo) 
    : tamanos(tamanos), num_pruebas(num_pruebas), nombre_archivo(nombre_archivo) {}

double LaboratorioPruebas::medir_mediana(function<Matrix(const Matrix&, const Matrix&)> algoritmo, int n) {
    vector<double> tiempos; 

    for(int r = 0 ; r< num_pruebas; ++r){ 
        Matrix A= generar_matriz(n);
        Matrix B= generar_matriz(n);
        auto inicio = high_resolution_clock::now();
        algoritmo(A, B);
        auto fin = high_resolution_clock::now();

        tiempos.push_back(duration_cast<duration<double>>(fin - inicio).count());
    }
    sort(tiempos.begin(), tiempos.end());
    return tiempos[tiempos.size() / 2];
}

void LaboratorioPruebas::ejecutar_comparacion(
    function<Matrix(const Matrix&, const Matrix&)> algoritmo_standar, 
    function<Matrix(const Matrix&, const Matrix&)> algoritmo_strassen
) {
    ofstream archivo(nombre_archivo);
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo: " << nombre_archivo << endl;
        return;
    }
    archivo << "num_pruebas,Tiempo_Estandard,Tiempo_Strassen\n";
    cout<<"====================================================\n";
    cout<<" INICIANDO LABORATORIO DE RENDIMIENTO\n";
    cout<<" Repeticiones por muestra: "<< num_pruebas << "\n";
    cout<<"====================================================\n";
    for (int n : tamanos) {
        double tiempo_standard = medir_mediana(algoritmo_standar, n);
        double tiempo_strassen = medir_mediana(algoritmo_strassen, n);

        cout<< "N = " << n 
            << " | O(n^3): " << tiempo_standard
            << " | Strassen: " << tiempo_strassen << endl;
        archivo << n << "," << tiempo_standard << "," << tiempo_strassen << "\n";
    }
    archivo.close();
}
