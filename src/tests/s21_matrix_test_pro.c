#include "s21_matrix_test.h"

START_TEST(transpose_matrix_4x3) {
  matrix_t matrix_1, result, check;
  int rows = 4, columns = 3, count = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = count;
      count++;
    }
  }

  s21_transpose(&matrix_1, &result);
  s21_create_matrix(columns, rows, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 4;
  check.matrix[0][2] = 7;
  check.matrix[0][3] = 10;
  check.matrix[1][0] = 2;
  check.matrix[1][1] = 5;
  check.matrix[1][2] = 8;
  check.matrix[1][3] = 11;
  check.matrix[2][0] = 3;
  check.matrix[2][1] = 6;
  check.matrix[2][2] = 9;
  check.matrix[2][3] = 12;

  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(calc_complements) {
  matrix_t A, result, check;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &check);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;

  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;

  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;

  check.matrix[0][0] = 0;
  check.matrix[0][1] = 10;
  check.matrix[0][2] = -20;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = -14;
  check.matrix[1][2] = 8;
  check.matrix[2][0] = -8;
  check.matrix[2][1] = -2;
  check.matrix[2][2] = 4;

  s21_calc_complements(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&check);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix) {
  matrix_t A, result, check;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &check);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;

  s21_inverse_matrix(&A, &result);

  check.matrix[0][0] = 1;
  check.matrix[0][1] = -1;
  check.matrix[0][2] = 1;
  check.matrix[1][0] = -38;
  check.matrix[1][1] = 41;
  check.matrix[1][2] = -34;
  check.matrix[2][0] = 27;
  check.matrix[2][1] = -29;
  check.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&A);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(s21_inverse_matrix_1x1) {
  int res;
  matrix_t A = {0};
  matrix_t result = {0};

  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 5;

  res = s21_inverse_matrix(&A, &result);

  ck_assert_double_eq(result.matrix[0][0] == (1.0 / A.matrix[0][0]), 1);
  ck_assert_int_eq(res, code_ok);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *pro_suite() {
  Suite *s1 = suite_create("Pro");
  TCase *tc1_1 = tcase_create("pro");

  tcase_add_test(tc1_1, transpose_matrix_4x3);
  tcase_add_test(tc1_1, calc_complements);
  tcase_add_test(tc1_1, inverse_matrix);
  tcase_add_test(tc1_1, s21_inverse_matrix_1x1);

  suite_add_tcase(s1, tc1_1);

  return s1;
}