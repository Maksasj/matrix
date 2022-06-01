# Matrix
Simmple single-header matrix library written in C++, intended for simple projects, tests.

# Todo
- [ ] Parallel mode, for some functions
- [ ] Fix all bugs (almoust imposible, but still...) 
- [ ] GPU matrix computation

# Docs

## CreateMatrix
```c++

matrix* mat1 = createMatrix(int row, int collum); //Will be initialized with 0
matrix* mat2 = createMatrix(int row, int collum, float value); //Will be initialized with 'value'

```

## fillMatrix
```c++

fillMatrix(mat, 69); // Will fill entire 'mat matrix' with 69

```

## scaleMatrix
```c++

scaleMatrix(mat, 69); // Will multiply each element of matrix 'mat' by specific value, in this case 69.

```

## addScalarMatrix
```c++

scaleMatrix(mat, 69); // Will add specific value to he each element of matrix 'mat'

```


## sumMatrix
```c++

matrix* result = sumMatrix(mat1, mat2);
/*
Will sumup each element of matrix 'mat1' with same element from 'mat2'. Be careful, different matrix dimensions can couse errors.
*/

```

## substractMatrix
```c++

matrix* result = substractMatrix(mat1, mat2);
/*
Will substract each element of matrix 'mat1' with same element from 'mat2'. Be careful, different matrix dimensions can couse errors.
*/

```

## multiplyMatrix
```c++

matrix* result = multiplyMatrix(mat1, mat2);
/*
Will multiply each element of matrix 'mat1' with same element from 'mat2'. Be careful, different matrix dimensions can couse errors.
*/

```

## transposMatrix
```c++

matrix* result = transposMatrix(mat);
/*
Will do matrix 'flip', it switches the row and column indices of the matrix A by producing another matrix.
*/

```

## dotProductMatrix
```c++

matrix* result = dotProductMatrix(mat1, mat2);
/*
Returns dot products between rows of first matrix and columns of the second matrix.
*/

```

## loadFileMatrix
```c++

matrix* result = loadFileMatrix("matrix.txt");

/*
Returns matrix stored in text file.

Example(matrix.txt):
3 3
4 3 3
1 2 9
0 3 7

*/

```

## saveFileMatrix
```c++

matrix* result = saveFileMatrix(mat,"matrix.txt"); // Same with loadFileMatrix but , this allows to save matrix in txt file.


```

## copyMatrix
```c++

matrix* result = copyMatrix(mat); // Copies provided matrix , and created new unique one

```

## applyFunction
```c++

float func(float x) {
      return x*69 - 0.420;
}


applyFunction(mat, &func);

/*
Allows to apply specific function for every element of given matrix.
For example there, for each element of 'mat matrix' will be applied function 'func'
*/

```

## deleteMatrix
```c++

deleteMatrix(mat); // Just delets matrix, free memory

```

## printMatrix
```c++

printMatrix(mat); // just prints entire matrix in terminal.

```


## elementSum
```c++

float sum = elementSum(mat);// Returns sum of all elements

```