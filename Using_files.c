/*
Matrix ADT (Abstract Data Type) in C
Author: Tannaz Chowdhury
Date: 2025

This file demonstrates how to define, use, and manipulate a dynamic 2D integer matrix in C
using header files and modular code separation. This is designed for beginners to learn about
C structures, pointer operations, memory management, and file organization in modular projects.
*/

// -----------------------------------------------------------------------------
// matrix.h - Header File (Interface)
// -----------------------------------------------------------------------------
#ifndef MATRIX_H
#define MATRIX_H

typedef struct {
    int rows;     // number of rows (n)
    int cols;     // number of columns (m)
    int *data;    // 1D array to simulate 2D matrix: data[i * cols + j]
} Matrix;

// Function declarations
Matrix *create_matrix(int rows, int cols);
void destroy_matrix(Matrix *mat);
int get_elem(Matrix *mat, int i, int j);
void set_elem(Matrix *mat, int i, int j, int value);
Matrix *add_matrix(Matrix *A, Matrix *B);
void print_matrix(Matrix *mat);

#endif // MATRIX_H


// -----------------------------------------------------------------------------
// matrix.c - Source File (Implementation)
// -----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

// Create and initialize a new matrix with given dimensions
Matrix *create_matrix(int rows, int cols) {
    Matrix *mat = malloc(sizeof(Matrix));
    mat->rows = rows;
    mat->cols = cols;
    mat->data = malloc(sizeof(int) * rows * cols);
    return mat;
}

// Free the matrix memory
void destroy_matrix(Matrix *mat) {
    free(mat->data);
    free(mat);
}

// Get element at position (i, j)
int get_elem(Matrix *mat, int i, int j) {
    return mat->data[i * mat->cols + j];
}

// Set element at position (i, j)
void set_elem(Matrix *mat, int i, int j, int value) {
    mat->data[i * mat->cols + j] = value;
}

// Add two matrices and return a new matrix with the result
Matrix *add_matrix(Matrix *A, Matrix *B) {
    if (A->rows != B->rows || A->cols != B->cols) {
        printf("Matrix dimensions do not match for addition.\n");
        return NULL;
    }

    Matrix *C = create_matrix(A->rows, A->cols);
    for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->cols; j++) {
            int val = get_elem(A, i, j) + get_elem(B, i, j);
            set_elem(C, i, j, val);
        }
    }
    return C;
}

// Print matrix contents
void print_matrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        for (int j = 0; j < mat->cols; j++) {
            printf("%d ", get_elem(mat, i, j));
        }
        printf("\n");
    }
}


// -----------------------------------------------------------------------------
// main.c - Usage Example
// -----------------------------------------------------------------------------
#include <stdio.h>
#include "matrix.h"

int main() {
    Matrix *A = create_matrix(2, 3);
    Matrix *B = create_matrix(2, 3);

    // Fill matrix A
    set_elem(A, 0, 0, 1); set_elem(A, 0, 1, 2); set_elem(A, 0, 2, 3);
    set_elem(A, 1, 0, 4); set_elem(A, 1, 1, 5); set_elem(A, 1, 2, 6);

    // Fill matrix B
    set_elem(B, 0, 0, 10); set_elem(B, 0, 1, 20); set_elem(B, 0, 2, 30);
    set_elem(B, 1, 0, 40); set_elem(B, 1, 1, 50); set_elem(B, 1, 2, 60);

    // Add matrices
    Matrix *C = add_matrix(A, B);

    // Print all matrices
    printf("Matrix A:\n"); print_matrix(A);
    printf("Matrix B:\n"); print_matrix(B);
    printf("Matrix A + B:\n"); print_matrix(C);

    // Clean up
    destroy_matrix(A);
    destroy_matrix(B);
    destroy_matrix(C);

    return 0;
}

// -----------------------------------------------------------------------------
// Exercise Ideas:
// -----------------------------------------------------------------------------
// 1. Implement a function to transpose a matrix (swap rows and columns).
// 2. Add support for matrix multiplication.
// 3. Allow reading/writing matrices from/to text files.
// 4. Validate bounds in get/set functions and handle errors.
// 5. Extend to float matrices by modifying the type in struct.
// -----------------------------------------------------------------------------
