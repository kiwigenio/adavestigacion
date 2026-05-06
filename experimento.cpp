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

//algoritmos Strassen  
Matrix strassen_recursivo(const Matrix& A, const Matrix& B) { 
    int n = A.size();

    if (n == 1) {
        Matrix C(1, vector<int>(1));
        C[0][0] = A[0][0] * B[0][0];
        return C;
    }

    int mitad = n/2; 
    Matrix a11(mitad, vector<int> (mitad)), a12(mitad, vector<int> (mitad)), a21(mitad, vector<int> (mitad)), a22(mitad, vector<int> (mitad));
    Matrix b11(mitad, vector<int> (mitad)), b12(mitad, vector<int> (mitad)), b21(mitad, vector<int> (mitad)), b22(mitad, vector<int> (mitad));

    for (int i = 0; i< mitad; ++i){
        for(int j = 0; j<mitad; ++j){
            a11[i][j] = A[i][j];
            a12[i][j] = A[i][j + mitad];
            a21[i][j] = A[i + mitad][j];
            a22[i][j] = A[i + mitad][j + mitad];

            b11[i][j] = B[i][j];
            b12[i][j] = B[i][j + mitad];
            b21[i][j] = B[i + mitad][j];
            b22[i][j] = B[i + mitad][j + mitad];
        }
    }
    cout<< "Submatrices a11, a12, a21, a22, b11, b12, b21, b22 creadas." << endl;
    imprimir_matriz(a11);
    imprimir_matriz(a12);  
    imprimir_matriz(a21);
    imprimir_matriz(a22);
    imprimir_matriz(b11);
    imprimir_matriz(b12);
    imprimir_matriz(b21);
    imprimir_matriz(b22);

    // las 7 operaciones de Strassen
    Matrix M1 = strassen_recursivo(a11,restar_matrices(b12, b22)); // M1 = a11 * (b12 - b22)
    Matrix M2 = strassen_recursivo(sumar_matrices(a11, a12), b22); // M2 = (a11 + a12) * b22
    Matrix M3 = strassen_recursivo(sumar_matrices(a21,a22),b11); // M3 = (a21 + a22) * b11
    Matrix M4 = strassen_recursivo(a22, restar_matrices(b21, b11)); // M4 = a22 * (b21 - b11)
    Matrix M5 = strassen_recursivo(sumar_matrices(a11, a22), sumar_matrices(b11, b22)); //  M5 = (a11 + a22) * (b11 + b22)
    Matrix M6 = strassen_recursivo(restar_matrices(a12, a22), sumar_matrices(b21, b22)); // M6 = (a12 - a22) * (b21 + b22)
    Matrix M7 = strassen_recursivo(restar_matrices(a11, a21), sumar_matrices(b11, b12)); // M7 = (a11 - a21) * (b11 + b12)

    Matrix c11 = sumar_matrices(restar_matrices(sumar_matrices(M5,M4), M2), M6);
    Matrix c12 = sumar_matrices(M1, M2);
    Matrix c21 = sumar_matrices(M3, M4);
    Matrix c22 = restar_matrices(restar_matrices(sumar_matrices(M5,M1), M3), M7);

    

    return A; 
}
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
    strassen_recursivo(A, B);
    return 0; 
}