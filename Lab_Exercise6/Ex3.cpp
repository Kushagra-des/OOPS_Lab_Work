#include <iostream>
using namespace std;

int sumOfCorners(int** matrix, int rows, int cols) {
    if (rows < 1 || cols < 1) {
        cout << "Invalid matrix size!" << endl;
        return 0; }
    int sum = 0;
    sum += matrix[0][0];
    sum += matrix[0][cols - 1];
    sum += matrix[rows - 1][0];
    sum += matrix[rows - 1][cols - 1];
    return sum;
}
int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols]; }
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Element at position [" << i << "][" << j << "]: ";
            cin >> matrix[i][j]; } }
    int cornerSum = sumOfCorners(matrix, rows, cols);
    cout << "The sum of the four corner elements is: " << cornerSum << endl;
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i]; }
    delete[] matrix;
    return 0;
}
