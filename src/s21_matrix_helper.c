#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error_code = code_ok;
  if (result == NULL || rows <= 0 || columns <= 0) {
    error_code = code_valid_error;
  }
  if (!error_code) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix == NULL) {
      error_code = code_memory_error;
    }
    for (int i = 0; !error_code && i < rows; i++) {
      result->matrix[i] = calloc(columns, sizeof(double));
      if (result->matrix[i] == NULL) {
        error_code = code_memory_error;
        s21_clear_submatrix(result, i - 1);
      }
    }
  }
  return error_code;
}

void s21_remove_matrix(matrix_t *A) { s21_clear_submatrix(A, A->rows); }

void s21_clear_submatrix(matrix_t *result, int i) {
  if (result != NULL) {
    if (result->matrix != NULL) {
      for (int j = 0; j < i; j++) {
        free(result->matrix[j]);
      }
      free(result->matrix);
      result->matrix = NULL;
    }
  }
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int code = SUCCESS;
  if (!s21_matrix_exist(A) || !s21_matrix_exist(B)) {
    code = FAILURE;
  }
  if (code && (A->rows != B->rows || A->columns != B->columns)) {
    code = FAILURE;
  }
  for (int i = 0; code && i < A->rows; i++) {
    for (int j = 0; code && j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
        code = FAILURE;
      }
    }
  }
  return code;
}

void s21_copy_matrix(matrix_t *A, matrix_t *B) {
  s21_create_matrix(A->rows, A->columns, B);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      B->matrix[i][j] = A->matrix[i][j];
    }
  }
}