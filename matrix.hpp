#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>

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
            for(int c= 0; c < mat->collum; c++) {
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
            for(int c= 0; c < mat->collum; c++) {
                  mat->data[r][c] = value;
            }
      }
}

matrix* sumMatrix(matrix *mat_a, matrix *mat_b) {
      assert(mat_a->row == mat_b->row || mat_a->collum == mat_b->collum);
      
      int row = mat_a->row || mat_b->row;
      int collum = mat_a->collum || mat_b->collum;

      matrix *mat = new matrix();
      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
            for(int c= 0; c < collum; c++) {
                  mat->data[r][c] = mat_a->data[r][c] + mat_b->data[r][c];
            }
      }
      return mat;
}

typedef matrix mat;

#endif