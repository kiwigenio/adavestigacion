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


int main(){ 
    return 0; 
}