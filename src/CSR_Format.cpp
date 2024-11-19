#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

const int rows = 3;
const int columns = 4;

int matrix[3][4] = {
    {0, 5, 2, 0},
    {0, 0, 0, 8},
    {0, 3, 6, 0}
};

void printMatrix(int (&matrix)[rows][columns]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl; 
    }
}

tuple <vector<int>, vector<int>, vector<int>> formatConversionCSR(int (&matrix)[rows][columns]){
    vector<int> vals;
    vector<int> cols;
    vector<int> row_pointer;

    bool isFirst = true;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (matrix[i][j] != 0){
                vals.push_back(matrix[i][j]);
                cols.push_back(j);
                
                if (isFirst){
                    row_pointer.push_back(matrix[i][j]);
                    isFirst = false;
                    }}
            }
        isFirst = true;
        }
    return {vals, cols, row_pointer};
}


int main() {
    cout << "The matrix:" << endl;
    printMatrix(matrix); 


    auto [vals, cols, row_pointer] = formatConversionCSR(matrix);

    cout << "\nNon-zero values: ";
    for (int v : vals) {
        cout << v << " ";
    }
    cout << "\nColumn indices: ";
    for (int c : cols) {
        cout << c << " ";
    }

    cout << "\nRow Pointer: ";
    for (int r : row_pointer) {
        cout << r << " ";
    }
    return 0;}
