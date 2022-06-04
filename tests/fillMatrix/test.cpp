#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix<float>(7, 13);
      fillMatrix(mat1, 69.0f);

      saveFileMatrix(mat1, "output.txt");
      return 0;
}