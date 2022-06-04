#include "../../matrix.hpp"
#include "../../external/hypercomplex.hpp"

int main() {
      complex z = {-1, 3};

      matrix<complex>* mat1 = createMatrix<complex>(4, 12, z);
      matrix<complex>* mat2 = createMatrix<complex>(12, 4, z);

      matrix<complex>* mat3 = dotProductMatrix(mat1, mat2); 
      saveFileMatrix(mat3, "output.txt");
      return 0;
}