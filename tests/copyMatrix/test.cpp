#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix<float>(69, 420, 228);
      mat* mat2 = copyMatrix(mat1);

      saveFileMatrix(mat2, "output.txt");
      return 0;
}