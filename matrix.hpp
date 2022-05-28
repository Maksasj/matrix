#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <iostream>

typedef struct matrix {
      int row;
      int collum;
      float** data;
} matrix;

//Default create
matrix* createMatrix(int row, int collum) {
      matrix *mat = new matrix();
      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];
      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
      }
      return mat;
}

//Create but with default value
matrix* createMatrix(int row, int collum, float value) {
      matrix *mat = new matrix();
      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];
      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = value;
            }
      }
      return mat;
}

void deleteMatrix(matrix *mat) {
      for(int r = 0; r < mat->row; r++) {
            delete mat->data[r];
      }
      delete mat;
}

void fillMatrix(matrix *mat, float value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = value;
            }
      }
}

//Scalar multiplication
void scalarMultMatrix(matrix *mat, float value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] *= value;
            }
      }
}

matrix* sumMatrix(matrix *mat_a, matrix *mat_b) {
      assert(mat_a->row == mat_b->row || mat_a->collum == mat_b->collum);
      
      int row = mat_a->row;
      int collum = mat_a->collum;

      matrix *mat = new matrix();
      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
            for(int c = 0; c < collum; c++) {
                  mat->data[r][c] = mat_a->data[r][c] + mat_b->data[r][c];
            }
      }
      return mat;
}

void printMatrix(matrix *mat4) {
      for(int r = 0; r < mat4->row; r++) {
            for(int c = 0; c < mat4->collum; c++) {
                  std::cout << mat4->data[r][c] << " ";
            }
            std::cout << "\n";
      }
}

//Transposition
matrix* transposMatrix(matrix *tmp_mat) {
      assert(tmp_mat != NULL);
      
      matrix *mat = new matrix();
      mat->row = tmp_mat->collum;
      mat->collum = tmp_mat->row;
      mat->data = new float*[mat->row];
      for(int r = 0; r < mat->row; r++) {
            mat->data[r] = new float[mat->collum];
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = tmp_mat->data[c][r];
            }
      }
      return mat;
}

typedef matrix mat;

#endif