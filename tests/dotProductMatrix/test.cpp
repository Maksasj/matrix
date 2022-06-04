#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix<float>(69, 150, 3.6);
      mat* mat2 = createMatrix<float>(150, 69, 1.2);
      mat* mat3 = dotProductMatrix(mat1, mat2);

      saveFileMatrix(mat3, "output.txt");
      return 0;
}