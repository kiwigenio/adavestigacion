#pragma once 
#include <vector> 
#include <iostream>

using Matrix = std::vector<std::vector<int>>;

Matrix sumar_matrices(const Matrix& A, const Matrix& B);
Matrix restar_matrices(const Matrix& A, const Matrix& B);
Matrix multiply_standard(const Matrix& A, const Matrix& B);
Matrix strassen_recursivo(const Matrix& A, const Matrix& B);
Matrix completar_matriz(const Matrix& A, const Matrix& B);
void imprimir_matriz(const Matrix& M);
Matrix generar_matriz(int n);