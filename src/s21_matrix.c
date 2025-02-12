#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_code = 0;
  if (s21_matrix_exist(A) && result != NULL) {
    int rows = A->columns, columns = A->rows;
    error_code = s21_create_matrix(rows, columns, result);
    for (int i = 0; !error_code && i < rows; i++) {
      for (int j = 0; !error_code && j < columns; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else {
    error_code = code_valid_error;
  }
  return error_code;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_code = s21_calc_complements_validator(A, result);
  if (!error_code && A->rows > 1) {
    int rows = A->rows, columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        double determinant = 0;
        matrix_t sub_matrix = {0};
        s21_create_matrix(rows - 1, columns - 1, &sub_matrix);
        s21_fill_submatrix(A, i, j, &sub_matrix);
        error_code = s21_determinant(&sub_matrix, &determinant);
        result->matrix[i][j] = determinant;
        if (result->matrix[i][j] != 0) {
          result->matrix[i][j] *= pow(-1, i + j);
        }
        s21_remove_matrix(&sub_matrix);
      }
    }
  } else if (!error_code) {
    int rows = A->rows, columns = A->columns;
    s21_create_matrix(rows, columns, result);
    double determinant = 0;
    error_code = s21_determinant(A, &determinant);
    result->matrix[0][0] = determinant;
  }
  return error_code;
}

void s21_fill_submatrix(matrix_t *A, int wo_row, int wo_column,
                        matrix_t *sub_matrix) {
  int count_row = 0;
  for (int i = 0; i < A->rows; i++) {
    int count_column = 0;
    if (i != wo_row) {
      for (int j = 0; j < A->columns; j++) {
        if (j != wo_column) {
          sub_matrix->matrix[count_row][count_column] = A->matrix[i][j];
          count_column++;
        }
      }
      count_row++;
    }
  }
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_code = s21_calc_complements_validator(A, result);
  double determinant = 0;
  if (!error_code) {
    error_code = s21_determinant(A, &determinant);
    if (determinant == 0) {
      error_code = code_arithmetic_error;
    }
  }
  if (!error_code && A->rows > 1) {
    matrix_t matrix_calc = {0}, matrix_calc_transp = {0};
    s21_calc_complements(A, &matrix_calc);
    s21_transpose(&matrix_calc, &matrix_calc_transp);
    s21_mult_number(&matrix_calc_transp, (1. / determinant), result);
    s21_remove_matrix(&matrix_calc);
    s21_remove_matrix(&matrix_calc_transp);
  } else if (!error_code) {
    s21_create_matrix(A->rows, A->columns, result);
    result->matrix[0][0] = 1. / A->matrix[0][0];
  }
  return error_code;
}