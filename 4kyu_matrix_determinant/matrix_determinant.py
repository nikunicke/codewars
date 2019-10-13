def     define_submatrix(matrix, index):
    length = len(matrix)
    submatrix = [[0 for i in range(length - 1)] for j in range(length - 1)]

    if (length <= 1):
        return matrix
    
    i = 1
    while (i < length):
        j = 0
        k = 0
        while (j < length):
            if(j != index):
                submatrix[i - 1][k] = matrix[i][j]
                k += 1
            j += 1
        i += 1
    return (submatrix)

def     determinant(matrix):
    length = len(matrix)
    if (length == 1):
        return (matrix[0][0])
    i = 0
    det = 0
    while (i < length):
        submatrix = define_submatrix(matrix, i)
        if (i % 2 != 0):
            sign = -1
        else:
            sign = 1
        det += matrix[0][i] * determinant(submatrix) * sign
        i += 1
    return (det)

test_arr = [[3, 1, 3, 4, 5],
            [5, 1, 33, 4, 6],
            [4, 2, 22, 5, 5],
            [1, 3, 5, 9, 7],
            [11, 2, 5, 4, 2]]
print(determinant(test_arr))
print(define_submatrix(test_arr, 0))