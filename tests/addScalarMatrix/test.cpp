#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix(69, 420, 228);
      addScalarMatrix(mat1, -159);

      saveFileMatrix(mat1, "output.txt");
      return 0;
}