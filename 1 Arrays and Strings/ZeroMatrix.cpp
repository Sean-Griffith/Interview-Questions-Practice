/*
    Write an algorithm such that if an element in an 
    MxN matrix is zero, its entire row and column are 
    set to zero
*/
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define N 4
#define M 6

struct coordinate{
        int x;
        int y;
};

void zeroMatrix(int** matrix, int n, int m);
void zeroMatrix2(int** matrix, int n, int m);
void fillMatrix(int** matrix, int n, int m);
void printMatrix(int** matrix, int n, int m);
int** initMatrix(int n, int m);

int main(){

    int** example = initMatrix(N, M);
    int** example2 = initMatrix(N, M);

    cout << "First solution\n" << endl;

    fillMatrix(example, N, M);
    printMatrix(example, N, M);
    
    zeroMatrix(example, N, M);
    printMatrix(example, N, M);

    cout << "Second solution\n" << endl;

    fillMatrix(example2, N, M);
    printMatrix(example2, N, M);
    
    zeroMatrix2(example2, N, M);
    printMatrix(example2, N, M);

    return 1;
}

/*
    (First Solution)

    O(m*n) time complexity, which is impossible to surpass because
    all algorithms will touch every element atleast once.
    O(m*n) space complexity, as we are tracking all cells with a zero,
    potentially causing us to track every cell
*/
void zeroMatrix(int** matrix, int n, int m){
    vector<coordinate> foundCoords;

    // Go through every cell and take note of the coordinates
    // at which zero-cells are found
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 0){
                coordinate newCoord;
                newCoord.x = i;
                newCoord.y = j;
                foundCoords.push_back(newCoord);
            }
        }
    }

    // Go through coordinate list and zero out respective
    // rows and columns
    for(int k = 0; k < foundCoords.size(); k++){
        for(int i = 0; i < n; i++){
            matrix[i][foundCoords[k].y] = 0;
        }
        for(int j = 0; j < m; j++){
            matrix[foundCoords[k].x][j] = 0;
        }
    }

}

/*
    (Second Solution)

    O(m*n) time complexity, which is impossible to surpass because
    all algorithms will touch every element atleast once.
    O(1) space complexity, as the matrix can be manipulated without
    creating a new datastructure.
*/
void zeroMatrix2(int** matrix, int n, int m){
    bool firstColumnZero = false;
    bool firstRowZero = false;

    // Check if first row/column have a zero element in them
    for(int i = 0; i < n; i++){
        if(matrix[i][0] == 0){
            firstColumnZero = true;
            break;
        }
    }

    for(int j = 0; j < m; j++){
        if(matrix[0][j] == 0){
            firstRowZero = true;
            break;
        }
    }

    // Go through every cell and zero out first-row or first-column
    // element relative to that cell if a zero is found
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            if(matrix[i][j] == 0){
                matrix[0][j] = 0;
                matrix[i][0] = 0;
            }
        }
    }

    // Go through marked matrix and zero necessary rows and columns
    for(int i = 1; i < n; i++){
        if(matrix[i][0] == 0){
            for(int j = 0; j < m; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int j = 1; j < m; j++){
        if(matrix[0][j] == 0){
            for(int i = 0; i < n; i++){
                matrix[i][j] = 0;
            }
        }
    }

    if(firstColumnZero == true){
        for(int i = 0; i < n; i++){
                matrix[i][0] = 0;
        }
    }

    if(firstRowZero == true){
        for(int j = 0; j < m; j++){
                matrix[0][j] = 0;
        }
    }
}

void printMatrix(int** matrix, int n, int m){
    for(int i = 0; i < n*2-1; i++){
        cout << "#";
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    for(int i = 0; i < n*2-1; i++){
        cout << "#";
    }
    cout << endl << endl;
}

void fillMatrix(int** matrix, int n, int m){
    srand(time(0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            //3% of elements set to zero (randomly)
            if((rand()%100) < 3){
                matrix[i][j] = 0;
            } else {
                //matrix[i][j] = i*N+j;
                matrix[i][j] = 1;
            }
        }
    }
}

int** initMatrix(int n, int m){
    int** newMatrix = new int*[n];
    for(int i = 0; i < n; i++){
        newMatrix[i] = new int[m];
    }
    return newMatrix;
}