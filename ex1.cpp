#include <iostream>

int main() {
    int rows = 3;
    int cols = 4;

    int** matrix = new int*[rows];
    for(int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            matrix[i][j] = i * cols + j; 
        }
    }

    for(int i = 0; i < rows; ++i) {
        for(int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}
