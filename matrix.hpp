#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

typedef struct matrix {
      int collum;
      int row;
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

void fillMatrix(matrix *mat, float value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = value;
            }
      }
}

//Scalar multiplication
void scaleMatrix(matrix *mat, float value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] *= value;
            }
      }
}

//Add scalar value to the each metrix element
void addScalarMatrix(matrix *mat, float value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] += value;
            }
      }
}

matrix* sumMatrix(matrix *mat_a, matrix *mat_b) {
      if(( mat_a->row != mat_b->row ) && ( mat_a->collum != mat_b->collum )) {
            std::cout << "sumMatrix: mat_a and mat_b have not equal dimensions";
            exit(1);
      }
      
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

matrix* substractMatrix(matrix *mat_a, matrix *mat_b) {
      if(( mat_a->row != mat_b->row ) && ( mat_a->collum != mat_b->collum )) {
            std::cout << "substractMatrix: mat_a and mat_b have not equal dimensions";
            exit(1);
      }
      
      int row = mat_a->row;
      int collum = mat_a->collum;

      matrix *mat = new matrix();
      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
            for(int c = 0; c < collum; c++) {
                  mat->data[r][c] = mat_a->data[r][c] - mat_b->data[r][c];
            }
      }
      return mat;
}

matrix* multiplyMatrix(matrix *mat_a, matrix *mat_b) {
      if(( mat_a->row != mat_b->row ) && ( mat_a->collum != mat_b->collum )) {
            std::cout << "multiplyMatrix: mat_a and mat_b have not equal dimensions";
            exit(1);
      }
      
      int row = mat_a->row;
      int collum = mat_a->collum;

      matrix *mat = new matrix();
      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
            for(int c = 0; c < collum; c++) {
                  mat->data[r][c] = mat_a->data[r][c] - mat_b->data[r][c];
            }
      }
      return mat;
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

//Just regular dot product
matrix* dotProductMatrix(matrix *mat_a, matrix *mat_b) {
      matrix *mat = new matrix();

      int row = mat_a->row;
      int collum = mat_b->collum;

      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];

      for(int r = 0; r < mat_a->row; r++) {
            mat->data[r] = new float[collum];
            for(int c = 0; c < mat_b->collum; c++) {
                  float value = 0;

                  for(int k = 0; k < mat_b->row; k++) {
                        value += mat_a->data[r][c] * mat_b->data[k][c];
                  }

                  mat->data[r][c] = value;
            }
      }
      return mat;
}

matrix* loadFileMatrix(std::string file_name) {
      std::ifstream in(file_name);

      int collum, row;
      in >> collum >> row;

      matrix *mat = new matrix();
      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];
      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
            for(int c = 0; c < mat->collum; c++) {
                  int value;
                  in >> value;
                  mat->data[r][c] = value;
            }
      }

      in.close();
      return mat;
}

void saveFileMatrix(matrix *mat, std::string file_name) {
      std::ofstream out(file_name);

      out << mat->collum << " " << mat->row << "\n";
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  out << mat->data[r][c] << " ";
            }
            out << "\n";
      }

      out.close();
}

matrix* copyMatrix(matrix *tmp_mat) {
      matrix *mat = new matrix();
      mat->row = tmp_mat->row;
      mat->collum = tmp_mat->collum;
      mat->data = new float*[mat->row];
      for(int r = 0; r < mat->row; r++) {
            mat->data[r] = new float[mat->collum];
            for(int c = 0; c < mat->collum; c++) {
                 mat->data[r][c] = tmp_mat->data[r][c];
            }
      }
      return mat;
}

//Apply function to the each matrix element
void applyFunction(matrix *mat, float (*func)(float)) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = func(mat->data[r][c]);
            }
      }
}

void deleteMatrix(matrix *mat) {
      for(int r = 0; r < mat->row; r++) {
            delete mat->data[r];
      }
      delete mat;
}

void printMatrix(matrix *mat) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  std::cout << mat->data[r][c] << " ";
            }
            std::cout << "\n";
      }
}

float elementSum(matrix *mat) {
      float value = 0;
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  value += mat->data[r][c];
            }
      }
      return value;

}

typedef matrix mat;

#endif