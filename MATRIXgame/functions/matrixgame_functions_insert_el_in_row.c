#include<stdlib.h>

#include "../headers/matrixgame_headers_insert_el_in_row.h"
#include "../headers/matrixgame_headers_matrix_t.h"
#include "../headers/matrixgame_errno.h"

#define R_I 1  // Right input.

#define NO_ERR 0  // No errors.
#define MEM_ERR -808  // Memory error: array of pointers or values was not allocated right.
#define EL_IND_ERR -809  // Element index error: element's index is not coorect. 

/*
  Проверка позиции, на которую будет вставлен элемент
  (ind >= 0 и ind <= rows/columns).
*/

int is_index_correct(const int rows, const int columns, const int index_row, const int index_column)
{
    if (index_row >= 0 && index_column >= 0 && index_row <= rows && index_column <= columns)
        return R_I;

    return EL_IND_ERR;
}

/*
  Выделяет дополнительную память для каждой строки матрицы.
  Присваивает значение 0 всем элементам последнего столбца матрицы.
*/

int one_pos_shifting(matrix_t *const matrix)
{
    matrix->columns = matrix->columns + 1;

    for (int i = 0; i < matrix->rows; i++)
    {
        *((matrix->matrix) + i) = (int *) realloc((matrix->matrix)[i],  matrix->columns * sizeof(int *));
        if (!*((matrix->matrix) + i))
            return MEM_ERR;

        *(*((matrix->matrix) + i) + (matrix->columns - 1)) = 0;
    }

    return 0;
}

/*
  Смещает элементы строки, в которую нужно добавить элемент
  на одну позицию с индекса нового элемента.
  Записывает новый элемент на освободишвуюся позицию.
*/

int insert_el_in_row(matrix_t *const matrix, int index_row, int index_column, int el)
{
    if (one_pos_shifting(matrix) != MEM_ERR)
    {
        if (is_index_correct(matrix->rows, matrix->columns, index_row, index_column) != EL_IND_ERR)
        {
            for (int i = (matrix->columns) - 1; i > index_column; i--)
                *(*((matrix->matrix) + index_row) + i) = *(*((matrix->matrix) + index_row) + (i - 1));

            *(*((matrix->matrix) + index_row) + index_column) = el;
    
            return NO_ERROR;
        }

        return EL_IND_ERR;
    }

    return MEM_ERR;
}
