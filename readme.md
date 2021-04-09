Matrix Optimization
===================

This project provide a matrix additional and matrix multiplication subroutines. These subroutines are currently suboptimal.

Matrix Addition
---------------

Matrix addition results in a new matrix that is the sum of corresponding entries from two matrices. Here is an example:

![Matrix addition](https://wikimedia.org/api/rest_v1/media/math/render/svg/b7da39614abf8978240dd50e3111f7dfa416daa1)

The basic algorithm for implementing matrix addition is:

```python
for row in matrix:
  for column in matrix:
    c[row][col] = a[row][col] + b[row][col]
```

This algorithm requires iterating over the columns while iterating over the rows, so it is O(n^2) with respect to the size of the matrix.

Matrix Multiplication
---------------------

Matrix multiplication can be defined as:

![Matrix multiplication expression](https://wikimedia.org/api/rest_v1/media/math/render/svg/ee372c649dea0a05bf1ace77c9d6faf051d9cc8d)

Each element in the resulting matrix will be the sum of the products in a row from matrix a and a column from matrix b.

![Matrix multiplication diagram](https://upload.wikimedia.org/wikipedia/commons/e/eb/Matrix_multiplication_diagram_2.svg)

An algorithm for matrix multiplication would be:

```python
for row in matrix:
  for column in matrix:
    c[row][col] = 0
    for i in range(colsize):
      c[row][col] += a[i][col] + b[row][i]
```

This algorithm requires iterating over the columns while iterating over the rows and then iterating over the items within an entire row and column, so it is O(n^3) with respect to the size of the matrix. Note that this is not an optimal algorithm. The optimal algorithm is an area of ongoing research, with the current state-of-the-art being [O(n^2.37286](https://arxiv.org/pdf/2010.05846.pdf).

Memory and Cache Optimization
-----------------------------

These algorithms do not make optimal use of the way that CPUs and memory interact in modern systems. Both algorithms can be adjusted to have better cache hit rates and memory properties. Addition can trivially be improved by [loop interchange](https://en.wikipedia.org/wiki/Loop_interchange) while multiplication can be improved using [loop tiling](https://en.wikipedia.org/wiki/Loop_nest_optimization).
