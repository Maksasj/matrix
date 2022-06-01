#include "../../matrix.hpp"

int main() {
      mat* mat1 = createMatrix(7, 13);
      fillMatrix(mat1, 69);

      saveFileMatrix(mat1, "output.txt");
      return 0;
}