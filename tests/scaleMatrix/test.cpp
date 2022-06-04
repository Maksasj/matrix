#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix<float>(69, 420, 3);
      scaleMatrix(mat1, 4.0);

      saveFileMatrix(mat1, "output.txt");
      return 0;
}