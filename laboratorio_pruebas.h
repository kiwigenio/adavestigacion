#pragma once
#include <vector> 
#include <functional>
#include <string>

using Matrix = std::vector<std::vector<int>>;
using namespace std;

class LaboratorioPruebas {
    private: 
        vector<int> tamanos;
        int num_pruebas;
        string nombre_archivo;

        double medir_mediana(function<Matrix(const Matrix&, const Matrix&)> algoritmo, int n );
    public: 
        LaboratorioPruebas(vector<int> tamanos, int num_pruebas, string nombre_archivo);

        void ejecutar_comparacion(
            function<Matrix(const Matrix&, const Matrix&)> algoritmo_standar, 
            function<Matrix(const Matrix&, const Matrix&)> algoritmo_strassen
        );
};