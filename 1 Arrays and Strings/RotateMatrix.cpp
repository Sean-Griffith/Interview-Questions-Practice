/*
    Given an image represented by an NxN matrix, 
    where each pixel in the image is represented 
    by an integer, write a method to rotate the 
    image by 90 degrees. Can you do this in place?
*/
#include <iostream>
using namespace std;

#define N 3

void fillMatrix(int** matrix);
void printMatrix(int** matrix);
int** rotateMatrix(int** matrix);

int main(){
    int** matrix = new int*[N];
    for(int i = 0; i < N; i++){
        matrix[i] = new int[N];
    }
    fillMatrix(matrix);
    printMatrix(matrix);
    int** matrix2 = rotateMatrix(matrix);
    printMatrix(matrix2);
    rotateMatrixOptimal(matrix2);
    printMatrix(matrix2);

    return 1;
}

/*
    (First Solution) (Non-optimal)

    O(n^2) time complexity, which is impossible to surpass because
    all algorithms will touch every element atleast once.
    O(n^2) space complexity, as we are making a copy of the matrix
*/
int** rotateMatrix(int** matrix){
    int** matrix2 = new int*[N];
    for(int i = 0; i < N; i++){
        matrix2[i] = new int[N];
    }
    for(int i = 0, ii = 0; i < N && ii < N; i++, ii++){
        for(int j = 0, jj = N-1; j < N && jj > -1; j++, jj--){
            //rows are reversed, rows become columns
            matrix2[i][j] = matrix[jj][ii];
        }
    }
    return matrix2;
}

/*
    (Second Solution) (Optimal)

    O(n^2) time complexity
    O(1) space complexity, as elements are swapped in-place

    This algorithm swaps sizes of the image clockwise 
    (top->right, right->bottom, etc.) and in-place.
*/
void rotateMatrixOptimal(int** matrix){
    
}

void printMatrix(int** matrix){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void fillMatrix(int** matrix){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            matrix[i][j] = i*N+j;
        }
    }
}