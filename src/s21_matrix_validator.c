#include "s21_matrix.h"

int s21_matrix_exist(matrix_t *A) {
  int exist = 1;
  if (A == NULL || A->matrix == NULL) {
    exist = 0;
  }
  return exist;
}

int s21_sum_sub_validator(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;
  if (result == NULL || !result || !s21_matrix_exist(A) ||
      !s21_matrix_exist(B) || A->columns == 0 || A->rows == 0 ||
      B->columns == 0 || B->rows == 0) {
    error_code = code_valid_error;
  }
  if (!error_code && ((A->rows != B->rows) || (A->columns != B->columns))) {
    error_code = code_arithmetic_error;
  }
  if (!error_code) {
    error_code = s21_value_validator(A);
  }
  if (!error_code) {
    error_code = s21_value_validator(B);
  }
  return error_code;
}

int s21_value_validator(matrix_t *A) {
  int error_code = 0;
  if (s21_matrix_exist(A) == 0) {
    error_code = code_valid_error;
  }
  for (int i = 0; !error_code && i < A->rows; i++) {
    for (int j = 0; !error_code && j < A->columns; j++) {
      double value = A->matrix[i][j];
      if (isinf(value) || isnan(value)) {
        error_code = code_arithmetic_error;
      }
    }
  }
  return error_code;
}

int s21_mul_num_validator(matrix_t *A, double number, matrix_t *result) {
  int error_code = 0;
  if (result == NULL || !result || !s21_matrix_exist(A) || A->columns == 0 ||
      A->rows == 0) {
    error_code = code_valid_error;
  }
  if (!error_code &&
      (isnan(number) || isinf(number) || s21_value_validator(A))) {
    error_code = code_arithmetic_error;
  }
  return error_code;
}

int s21_mul_matrix_validator(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_code = 0;
  if (result == NULL || !result || !s21_matrix_exist(A) ||
      !s21_matrix_exist(B) || A->rows == 0 || A->columns == 0 || B->rows == 0 ||
      B->columns == 0) {
    error_code = code_valid_error;
  }
  if (!error_code && (s21_value_validator(A) || s21_value_validator(B) ||
                      A->columns != B->rows)) {
    error_code = code_arithmetic_error;
  }
  return error_code;
}

int s21_determinant_validator(matrix_t *A, double *result) {
  int error_code = 0;
  if (!s21_matrix_exist(A) || result == NULL || A->rows == 0 ||
      A->columns == 0) {
    error_code = code_valid_error;
  }
  if (!error_code && (s21_value_validator(A) || A->rows != A->columns)) {
    error_code = code_arithmetic_error;
  }
  return error_code;
}

int s21_calc_complements_validator(matrix_t *A, matrix_t *result) {
  int error_code = 0;
  if (!s21_matrix_exist(A) || result == NULL) {
    error_code = code_valid_error;
  }
  if (!error_code && (s21_value_validator(A) || A->rows != A->columns)) {
    error_code = code_arithmetic_error;
  }
  return error_code;
}