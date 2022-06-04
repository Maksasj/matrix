# Matrix
Simmple single-header [matrix](https://en.wikipedia.org/wiki/Matrix_(mathematics)) library written in C++, intended for simple projects, tests.

### Provides simple way to interact wiht:
- Matrix type
- Matrix algebra
- Simple way to save & load matrix from files.

# Todo
- [ ] CPU Parallel mode, for some functions
- [ ] Fix all bugs (almost imposible, but still...) 
- [ ] GPU matrix computation

# Docs

## Matix type
```c++
template<class T> struct matrix {
      int collum;
      int row;
      T** data;
};
```
Usually matrix you will pass around using pointers, `matrix* mat`, also theres a shorter writing version `mat* mat1`.

If you want get access to the specific element you can do that like that `mat->data[x][y]`, but be carefully be cause *x* and *y* can't be more then collum and row correspondently, or less then 0. Another way how to get access specific cell from matrix is using `getElement(mat, row, collum)` , there mat is yours matrix, row and collum is just regular ints like `x` and `y` as stated above.

## CreateMatrix

`matrix* createMatrix<T>(int row, int collum)`

Returns pointer to the created matrix, also can be written like this.

`matrix* createMatrix<T>(int row, int collum, float value)`

These both methods have save meaning, second will just fill matrix with default value. Regularly this value will be 0.

```c++
matrix<float>* mat1 = createMatrix<float>(69, 420); //Will be initialized with 0
matrix<int>* mat2 = createMatrix<int>(69, 420, 228); //Will be initialized with 228
```

## fillMatrix
`void fillMatrix(matrix *mat<T>, T value)`

Just fills entire matrix with specific value

```c++
fillMatrix(mat, 69); // Will fill entire 'mat matrix' with 69
```

## scaleMatrix
`void scaleMatrix(matrix *mat<T>, float value)`

Will multiply each element of matrix by provided value.

```c++
scaleMatrix(mat, 69); // Will multiply each element of matrix 'mat' by specific value, in this case 69.
```

## addScalarMatrix
`void addScalarMatrix(matrix<T> *mat, float value)`

Adds provided value to the each element of the provided matrix

```c++
scaleMatrix(mat, 69); // In this case, will add 69 to the each element of the matrix 'mat'
```


## sumMatrix
`matrix<T>* sumMatrix(matrix<T> *mat_a, matrix<T> *mat_b)`

Simply will sumup each element of first matrix with same element from th second matrix. As a result will create a new matrix.
Be very careful, different matrix dimensions can couse errors.

```c++
matrix<T>* result = sumMatrix(mat1, mat2);
/*
Will sumup each element of matrix 'mat1' with same element from 'mat2'.
*/
```

## substractMatrix
`matrix<T>* substractMatrix(matrix<T> *mat_a, matrix<T> *mat_b)`

Simply will substract each element of first matrix with same element from th second matrix. As a result will create a new matrix.
Be very careful, different matrix dimensions can couse errors.

```c++
matrix<T>* result = substractMatrix(mat1, mat2);
/*
Will substract each element of matrix 'mat1' with same element from 'mat2'.
*/
```

## multiplyMatrix
`matrix<T>* multiplyMatrix(matrix<T> *mat_a, matrix<T> *mat_b)`

Simply will multiply each element of first matrix with same element from th second matrix. As a result will create a new matrix.
Be very careful, different matrix dimensions can couse errors.


```c++
matrix<T>* result = multiplyMatrix(mat1, mat2);
/*
Will multiply each element of matrix 'mat1' with same element from 'mat2'.
*/
```

## transposMatrix
`matrix<T>* transposMatrix(matrix<T> *tmp_mat)`

Will do matrix 'flip', it switches the row and column indices of the matrix A by producing another matrix.

```c++
matrix<T>* result = transposMatrix(mat);
/*
For example
input:
2 3
1 2 6
9 8 1

result:
3 2
9 1
8 2
1 6

*/
```

## dotProductMatrix
`matrix<T>* dotProductMatrix(matrix<T> *mat_a, matrix<T> *mat_b)`

Returns dot products between rows of first matrix and columns of the second matrix. More about *dot product* you can read in this [article](https://en.wikipedia.org/wiki/Dot_product).

```c++
matrix<T>* result = dotProductMatrix(mat1, mat2);
```

## loadFileMatrix
`matrix* loadFileMatrix(std::string file_name)`

Returns matrix stored in text file, be careful because there I using custom matrix format. To lear more check out test folder of the repository.

```c++
matrix<T>* result = loadFileMatrix("matrix.txt");

/*

Example(matrix.txt):
3 3
4 3 3
1 2 9
0 3 7

*/
```

## saveFileMatrix

`void saveFileMatrix(matrix<T> *mat, std::string file_name)`

Same with loadFileMatrix but , this allows to save matrix in txt file.

```c++
saveFileMatrix(mat,"matrix.txt");
```

## copyMatrix
`matrix<T>* copyMatrix(matrix<T> *tmp_mat)`

Copies provided matrix , and created new unique one, with unique pointer.


```c++
matrix<T>* result = copyMatrix(mat); 
```

## applyFunction
`void applyFunction(matrix<T> *mat, T (*func)(T))`

Allows to apply specific function for every element of provided matrix. Regularly provided matrix should accept single float variable as input, and return just 'T' type. But if you want to do somethink more, do that on your own risk :).


```c++
T func(T x) {
      return x*69 - 0.420;
}

applyFunction(mat, &func);

/*
For example there, for each element of 'mat' matrix will be applied function 'func'
*/
```

## deleteMatrix
`void deleteMatrix(matrix<T> *mat)`

Delets entire matrix, and free the memory.

```c++
deleteMatrix(mat);
```

## printMatrix
`void printMatrix(matrix<T> *mat)`

Just prints entire matrix in terminal.
```c++
printMatrix(mat);
```


## elementSum
`float elementSum(matrix<T> *mat)`

Returns sum of all elements of the provided matrix.
```c++
T sum = elementSum(mat);
```