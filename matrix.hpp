#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <string>
#include <cassert>

template<class T> struct matrix {
      int collum;
      int row;
      T** data;
};

//Default create

template<class T>
matrix<T>* createMatrix(int row, int collum) {
      matrix<T> *mat = new matrix<T>();
      mat->row = row;
      mat->collum = collum;
      mat->data = new T*[row];
      for(int r = 0; r < row; r++) {
            mat->data[r] = new T[collum];
      }
      return mat;
}

//Create but with default value
template<class T>
matrix<T>* createMatrix(int row, int collum, T value) {
      matrix<T> *mat = new matrix<T>();
      mat->row = row;
      mat->collum = collum;
      mat->data = new T*[row];
      for(int r = 0; r < row; r++) {
            mat->data[r] = new T[collum];
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = value;
            }
      }
      return mat;
}

template<class T>
void fillMatrix(matrix<T> *mat, T value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = value;
            }
      }
}

//Scalar multiplication
template<class T>
void scaleMatrix(matrix<T> *mat, float value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] *= value;
            }
      }
}

//Add scalar value to the each metrix element
template<class T>
void addScalarMatrix(matrix<T> *mat, float value) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] += value;
            }
      }
}

template<class T>
matrix<T>* sumMatrix(matrix<T> *mat_a, matrix<T> *mat_b) {
      if(( mat_a->row != mat_b->row ) && ( mat_a->collum != mat_b->collum )) {
            std::cout << "sumMatrix: mat_a and mat_b have not equal dimensions";
            exit(1);
      }
      
      int row = mat_a->row;
      int collum = mat_a->collum;

      matrix<T> *mat = new matrix<T>();
      mat->row = row;
      mat->collum = collum;
      mat->data = new T*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new T[collum];
            for(int c = 0; c < collum; c++) {
                  mat->data[r][c] = mat_a->data[r][c] + mat_b->data[r][c];
            }
      }
      return mat;
}

template<class T>
matrix<T>* substractMatrix(matrix<T> *mat_a, matrix<T> *mat_b) {
      if(( mat_a->row != mat_b->row ) && ( mat_a->collum != mat_b->collum )) {
            std::cout << "substractMatrix: mat_a and mat_b have not equal dimensions";
            exit(1);
      }
      
      int row = mat_a->row;
      int collum = mat_a->collum;

      matrix<T> *mat = new matrix<T>();
      mat->row = row;
      mat->collum = collum;
      mat->data = new T*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new T[collum];
            for(int c = 0; c < collum; c++) {
                  mat->data[r][c] = mat_a->data[r][c] - mat_b->data[r][c];
            }
      }
      return mat;
}

template<class T>
matrix<T>* multiplyMatrix(matrix<T> *mat_a, matrix<T> *mat_b) {
      if(( mat_a->row != mat_b->row ) && ( mat_a->collum != mat_b->collum )) {
            std::cout << "multiplyMatrix: mat_a and mat_b have not equal dimensions";
            exit(1);
      }
      
      int row = mat_a->row;
      int collum = mat_a->collum;

      matrix<T> *mat = new matrix<T>();
      mat->row = row;
      mat->collum = collum;
      mat->data = new T*[row];

      for(int r = 0; r < row; r++) {
            mat->data[r] = new T[collum];
            for(int c = 0; c < collum; c++) {
                  mat->data[r][c] = mat_a->data[r][c] * mat_b->data[r][c];
            }
      }
      return mat;
}

//Transposition
template<class T>
matrix<T>* transposMatrix(matrix<T> *tmp_mat) {
      assert(tmp_mat != NULL);
      
      matrix<T> *mat = new matrix<T>();
      mat->row = tmp_mat->collum;
      mat->collum = tmp_mat->row;
      mat->data = new T*[mat->row];

      for(int r = 0; r < mat->row; r++) {
            mat->data[r] = new T[mat->collum];
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = tmp_mat->data[c][r];
            }
      }
      return mat;
}

//Just regular dot product
template<class T>
matrix<T>* dotProductMatrix(matrix<T> *mat_a, matrix<T> *mat_b) {
      matrix<T> *mat = new matrix<T>();

      int row = mat_a->row;
      int collum = mat_b->collum;

      mat->row = row;
      mat->collum = collum;
      mat->data = new T*[row];

      for(int r = 0; r < mat_a->row; r++) {
            mat->data[r] = new T[collum];
            for(int c = 0; c < mat_b->collum; c++) {
                  T value;

                  for(int k = 0; k < mat_b->row; k++) {
                        value += ( mat_a->data[r][c] * mat_b->data[k][c] );
                  }

                  mat->data[r][c] = value;
            }
      }
      return mat;
}

template<class T>
matrix<T>* loadFileMatrix(std::string file_name) {
      std::ifstream in(file_name);

      int collum, row;
      in >> collum >> row;

      matrix<T> *mat = new matrix<T>();
      mat->row = row;
      mat->collum = collum;
      mat->data = new T*[row];
      for(int r = 0; r < row; r++) {
            mat->data[r] = new T[collum];
            for(int c = 0; c < mat->collum; c++) {
                  int value;
                  in >> value;
                  mat->data[r][c] = value;
            }
      }

      in.close();
      return mat;
}

template<class T>
void saveFileMatrix(matrix<T> *mat, std::string file_name) {
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

template<class T>
matrix<T>* copyMatrix(matrix<T> *tmp_mat) {
      matrix<T> *mat = new matrix<T>();
      mat->row = tmp_mat->row;
      mat->collum = tmp_mat->collum;
      mat->data = new T*[mat->row];
      for(int r = 0; r < mat->row; r++) {
            mat->data[r] = new T[mat->collum];
            for(int c = 0; c < mat->collum; c++) {
                 mat->data[r][c] = tmp_mat->data[r][c];
            }
      }
      return mat;
}

//Apply function to the each matrix<T> element
template<class T>
void applyFunction(matrix<T> *mat, T (*func)(T)) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  mat->data[r][c] = func(mat->data[r][c]);
            }
      }
}

template<class T>
void deleteMatrix(matrix<T> *mat) {
      for(int r = 0; r < mat->row; r++) {
            delete mat->data[r];
      }
      delete mat;
}

template<class T>
void printMatrix(matrix<T> *mat) {
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  std::cout << mat->data[r][c] << " ";
            }
            std::cout << "\n";
      }
}

template<class T>
float elementSum(matrix<T> *mat) {
      float value = 0;
      for(int r = 0; r < mat->row; r++) {
            for(int c = 0; c < mat->collum; c++) {
                  value += mat->data[r][c];
            }
      }
      return value;

}

template<class T>
float getElement(matrix<T>* mat, int row, int collum) {
      if(row > mat->row || collum > mat->collum || row < 0 || collum < 0) {
            return mat->data[row][collum];
      }
}

typedef matrix<float> mat;

#endif