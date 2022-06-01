#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix(69, 420, 3);
      scaleMatrix(mat1, 4);

      saveFileMatrix(mat1, "output.txt");
      return 0;
}