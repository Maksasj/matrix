#include "../../matrix.hpp"

int main() {
      matrix<float>* mat1 = createMatrix<float>(69, 420, 228);
      addScalarMatrix(mat1, -159);

      saveFileMatrix(mat1, "output.txt");
      return 0;
}