#include "funciones_strassen.h"
#include <iostream>


using namespace std;

int main(){ 
    cout<< "ingrese el tamaño de la matriz (debe ser potencia de 2): ";
    int size = 0;
    cin>> size;
    Matrix A = generar_matriz(size);
    Matrix B = generar_matriz(size);
    cout << "Matriz A:" << endl;
    imprimir_matriz(A);
    cout << "Matriz B:" << endl;
    imprimir_matriz(B);
    /*Matrix C = multiply_standard(A, B);
    cout << "Matriz C (A x B):" << endl;
    imprimir_matriz(C); */
    //Matrix C = sumar_matrices(A, B);
    //cout << "Matriz C (A + B):" << endl;
    /*Matrix C = restar_matrices(A, B);
    cout << "Matriz C (A - B):" << endl;
    imprimir_matriz(C);*/
    Matrix C = strassen_recursivo(A, B);
    cout<< "Multiplicacion de matrices usando Strassen completada." << endl;
    imprimir_matriz(C);
    return 0; 
}