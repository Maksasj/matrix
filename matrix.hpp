#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <iostream>
#include <string>
#include <fstream>

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

//Matrix multiplication
matrix* multipMatrix(matrix *mat_a, matrix *mat_b) {
      assert(mat_b->row == mat_a->collum);
      
      matrix *mat = new matrix();

      int row = mat_b->collum;
      int collum = mat_a->row;

      mat->row = row;
      mat->collum = collum;
      mat->data = new float*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new float[collum];
            for(int c = 0; c < mat->collum; c++) {
                  float value = 0;

                  for(int tmp_r = 0; tmp_r < mat_a->collum; tmp_r++) {
                        value += mat_a->data[r][tmp_r]*mat_b->data[tmp_r][c];
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

void printMatrix(matrix *mat4) {
      for(int r = 0; r < mat4->row; r++) {
            for(int c = 0; c < mat4->collum; c++) {
                  std::cout << mat4->data[r][c] << " ";
            }
            std::cout << "\n";
      }
}

typedef matrix mat;

#endif