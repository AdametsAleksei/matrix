#include "s21_matrix.h"

int s21_determinant(matrix_t *A, double *result) {
  int error_code = s21_determinant_validator(A, result);
  if (!error_code) {
    *result = 0;
    if (A->rows == 1) {
      *result = A->matrix[0][0];
    } else if (A->rows == 2) {
      s21_determinant_2x2(A, result);
    } else {
      matrix_t A_copy;
      s21_copy_matrix(A, &A_copy);
      s21_determinant_Gauss(&A_copy, result);
      s21_remove_matrix(&A_copy);
    }
  }
  return error_code;
}

void s21_determinant_2x2(matrix_t *A, double *result) {
  *result =
      A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
}

void s21_determinant_Gauss(matrix_t *A, double *result) {
  int columns = A->columns, minus = 1, flag = 0;
  for (int j = 0; !flag && j < columns; j++) {
    int k = j + 1;
    while (A->matrix[j][j] == 0 && k < columns) {
      flag = 1;
      if (A->matrix[k][j] != 0) {
        minus *= -1;
        flag = 0;
        matrix_t row_1, row_2;
        s21_create_matrix(1, columns, &row_1);
        s21_create_matrix(1, columns, &row_2);
        s21_copy_row(A, j, &row_1);
        s21_copy_row(A, k, &row_2);
        s21_replace_row(A, j, &row_2);
        s21_replace_row(A, k, &row_1);
        s21_remove_matrix(&row_1);
        s21_remove_matrix(&row_2);
      }
      k++;
    }
    if (!flag) {
      if (*result == 0) {
        *result = A->matrix[j][j];
      } else {
        *result *= A->matrix[j][j];
      }
    } else {
      *result = 0;
    }
    for (int i = j + 1; !flag && i < A->rows; i++) {
      matrix_t row_1, row_2, row_1_coef, row_2_result;
      s21_create_matrix(1, columns, &row_1);
      s21_copy_row(A, j, &row_1);
      s21_create_matrix(1, columns, &row_2);
      s21_copy_row(A, i, &row_2);

      double coef = (double)row_2.matrix[0][j] / (double)row_1.matrix[0][j];
      s21_mult_number(&row_1, coef, &row_1_coef);
      s21_sub_matrix(&row_2, &row_1_coef, &row_2_result);
      s21_replace_row(A, i, &row_2_result);

      s21_remove_matrix(&row_1);
      s21_remove_matrix(&row_2);
      s21_remove_matrix(&row_1_coef);
      s21_remove_matrix(&row_2_result);
    }
  }
  *result *= minus;
}

void s21_replace_row(matrix_t *A, int row, matrix_t *B) {
  for (int j = 0; j < A->columns; j++) {
    A->matrix[row][j] = B->matrix[0][j];
  }
}

void s21_copy_row(matrix_t *A, int row, matrix_t *result) {
  for (int i = 0; i < A->columns; i++) {
    result->matrix[0][i] = A->matrix[row][i];
  }
}