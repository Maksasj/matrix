#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix(7, 13, 9);
      mat* mat2 = transposMatrix(mat1);

      saveFileMatrix(mat2, "output.txt");
      return 0;
}