#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = s21_sum_sub_validator(A, B, result);
  if (!error_code) {
    int rows = A->rows, columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return error_code;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = s21_sum_sub_validator(A, B, result);
  if (!error_code) {
    int rows = A->rows, columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
    }
  }
  return error_code;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int error_code = s21_mul_num_validator(A, number, result);
  if (!error_code) {
    int rows = A->rows, columns = A->columns;
    s21_create_matrix(rows, columns, result);
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return error_code;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = s21_mul_matrix_validator(A, B, result);
  if (!error_code) {
    int rows = A->rows, columns = B->columns;
    error_code = s21_create_matrix(rows, columns, result);
    for (int i = 0; !error_code && i < rows; i++) {
      for (int j = 0; !error_code && j < columns; j++) {
        double temp = 0;
        for (int k = 0; k < A->columns; k++) {
          temp += A->matrix[i][k] * B->matrix[k][j];
        }
        result->matrix[i][j] = temp;
      }
    }
  }
  return error_code;
}