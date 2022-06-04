#include "../../matrix.hpp"

float func(float x) {
      return (x*2.0 - 3.0 + 1.315);
}

int main() {
      mat* mat1 = createMatrix<float>(69, 420, 228);
      applyFunction(mat1, &func);

      saveFileMatrix(mat1, "output.txt");
      return 0;
}