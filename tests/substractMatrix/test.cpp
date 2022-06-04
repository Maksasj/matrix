#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix<float>(69, 420, 6);
      mat* mat2 = createMatrix<float>(69, 420, 3);
      mat* mat3 = substractMatrix(mat1, mat2);

      saveFileMatrix(mat3, "output.txt");
      return 0;
}