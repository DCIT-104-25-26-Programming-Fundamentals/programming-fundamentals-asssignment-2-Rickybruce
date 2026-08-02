// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void input_matrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

void print_matrix(int matrix[10][10], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << "\n";
    }
}

void transpose_matrix(int matrix[10][10], int rows, int cols) {
    int result[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j];
        }
    }
    cout << "\nTransposed Matrix:\n";
    print_matrix(result, cols, rows);
}

void add_matrices(int A[10][10], int B[10][10], int rows, int cols) {
    int result[10][10];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    cout << "\nResultant Matrix (A + B):\n";
    print_matrix(result, rows, cols);
}

void multiply_matrices(int A[10][10], int B[10][10], int r1, int c1, int c2) {
    int result[10][10] = {0};
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            for (int k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "\nResultant Matrix (A x B):\n";
    print_matrix(result, r1, c2);
}

int main() {
    int choice;
    cout << " ========================================\n"
         << "           MATRIX OPERATIONS\n"
         << " ========================================\n"
         << "1. Transpose Matrix\n"
         << "2. Add Matrices\n"
         << "3. Multiply Matrices\n"
         << "4. Quit\n";

    while (true) {
        cout << "\nEnter your choice (1-4): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Error: Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 4) {
            cout << "Goodbye\n";
            break;
        }

        if (choice < 1 || choice > 4) {
            cout << "Error: Invalid operation choice.\n";
            continue;
        }

        if (choice == 1) {
            int rows, cols;
            int A[10][10];
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            cout << "Enter elements for Matrix:\n";
            input_matrix(A, rows, cols);

            cout << "\nOriginal Matrix:\n";
            print_matrix(A, rows, cols);

            transpose_matrix(A, rows, cols);
        }
        else if (choice == 2) {
            int rows, cols;
            int A[10][10], B[10][10];
            cout << "Enter number of rows: ";
            cin >> rows;
            cout << "Enter number of columns: ";
            cin >> cols;

            cout << "Enter elements for Matrix A:\n";
            input_matrix(A, rows, cols);

            cout << "Enter elements for Matrix B:\n";
            input_matrix(B, rows, cols);

            add_matrices(A, B, rows, cols);
        }
        else if (choice == 3) {
            int r1, c1, r2, c2;
            int A[10][10], B[10][10];

            cout << "Enter number of rows for Matrix A: ";
            cin >> r1;
            cout << "Enter number of columns for Matrix A: ";
            cin >> c1;

            cout << "Enter number of rows for Matrix B: ";
            cin >> r2;
            cout << "Enter number of columns for Matrix B: ";
            cin >> c2;

            if (c1 != r2) {
                cout << "Error: Columns of A must match Rows of B for multiplication!\n";
                continue;
            }

            cout << "Enter elements for Matrix A:\n";
            input_matrix(A, r1, c1);

            cout << "Enter elements for Matrix B:\n";
            input_matrix(B, r2, c2);

            multiply_matrices(A, B, r1, c1, c2);
        }
    }

    return 0;
}