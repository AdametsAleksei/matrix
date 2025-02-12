#ifndef SRC_S21_MATRIX_H
#define SRC_S21_MATRIX_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define EPSILON 1e-7

enum result_code {
  code_ok,
  code_valid_error,
  code_arithmetic_error,
  code_memory_error,
  FAILURE = 0,
  SUCCESS
};

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

// helper
int s21_create_matrix(int rows, int columns, matrix_t *result);
void s21_remove_matrix(matrix_t *A);
void s21_clear_submatrix(matrix_t *result, int i);
int s21_eq_matrix(matrix_t *A, matrix_t *B);
int s21_matrix_exist(matrix_t *A);
void s21_copy_matrix(matrix_t *A, matrix_t *B);

// validator
int s21_sum_sub_validator(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_value_validator(matrix_t *A);
int s21_mul_num_validator(matrix_t *A, double number, matrix_t *result);
int s21_mul_matrix_validator(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_determinant_validator(matrix_t *A, double *result);
int s21_calc_complements_validator(matrix_t *A, matrix_t *result);

// base_arithmetic
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

// matrix
int s21_transpose(matrix_t *A, matrix_t *result);
int s21_calc_complements(matrix_t *A, matrix_t *result);
void s21_create_submatrix(matrix_t *A, int wo_row, int wo_column,
                          matrix_t *sub_matrix);
void s21_fill_submatrix(matrix_t *A, int wo_row, int wo_column,
                        matrix_t *sub_matrix);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

// determinant
int s21_determinant(matrix_t *A, double *result);
void s21_determinant_2x2(matrix_t *A, double *result);
void s21_determinant_Gauss(matrix_t *A, double *result);
void s21_copy_row(matrix_t *A, int row, matrix_t *result);
void s21_replace_row(matrix_t *A, int row, matrix_t *B);

#endif