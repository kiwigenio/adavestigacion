#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <random>
#include <cmath>
#include <fstream>

using namespace std;
using namespace std::chrono;

// definicion de mi matriz n x n como un vector de vectores de enteros 
using Matrix = vector<vector<int>>;

// Creacion de matriz aleatoria con valores entre 1 y 10 
Matrix generar_matriz(int n) {
    Matrix M(n, vector<int>(n));
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 10);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            M[i][j] = dis(gen);
    return M;
}

//suma de matrices qyue es parte del algoritmo Strassen
Matrix sumar_matrices(const Matrix& A, const Matrix& B){
    int n = A.size(); 
    Matrix C(n, vector<int> (n));
    for( int i =0; i< n; ++i){
        for(int j=0; j<n; ++j){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    return C;
}

//resta de matrices que es parte del algoritmo Strassen
Matrix restar_matrices(const Matrix& A, const Matrix& B){
    int n = A.size(); 
    Matrix C(n, vector<int> (n));
    for( int i =0; i< n; ++i){
        for(int j=0; j<n; ++j){
            C[i][j] = A[i][j] - B[i][j];
        }
    }
    return C;
}

// algoritmo estandar de multiplicacion de matrices (O(n^3))
Matrix multiply_standard(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) { 
            for (int j = 0; j < n; ++j) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

void imprimir_matriz (const Matrix& M ){
    for(const auto& fila: M){
        for(int  valor  : fila){
            cout<< valor << "\t";
        }
        cout<<endl; 
    }
    cout<< "********************"<<endl;
}
int main(){ 
    Matrix A = generar_matriz(3);
    Matrix B = generar_matriz(3);
    cout << "Matriz A:" << endl;
    imprimir_matriz(A);
    cout << "Matriz B:" << endl;
    imprimir_matriz(B);
    /*Matrix C = multiply_standard(A, B);
    cout << "Matriz C (A x B):" << endl;
    imprimir_matriz(C); */
    //Matrix C = sumar_matrices(A, B);
    //cout << "Matriz C (A + B):" << endl;
    Matrix C = restar_matrices(A, B);
    cout << "Matriz C (A - B):" << endl;
    imprimir_matriz(C);

    return 0; 
}