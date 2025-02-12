#include "s21_matrix_test.h"

START_TEST(sum_matrix_should_be_eq) {
  matrix_t matrix_1, matrix_2, result, check;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  s21_create_matrix(rows, columns, &check);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = 1;
      matrix_2.matrix[i][j] = 1;
      check.matrix[i][j] = 2;
    }
  }
  s21_sum_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &check), 1);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(sub_matrix_should_be_eq) {
  matrix_t matrix_1, matrix_2, result, check;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  s21_create_matrix(rows, columns, &check);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = 1;
      matrix_2.matrix[i][j] = 1;
      check.matrix[i][j] = 0;
    }
  }
  s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_with_diff_rows_and_columns_should_be_error_code) {
  matrix_t matrix_1, matrix_2, result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows - 1, columns, &matrix_2);

  ck_assert_int_eq(s21_mult_matrix(&matrix_1, &matrix_2, &result),
                   code_arithmetic_error);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(mult_matrix_when_rows_0) {
  matrix_t matrix_1, matrix_2, result;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_1.rows = 0;
  s21_create_matrix(rows, columns, &matrix_2);

  ck_assert_int_eq(s21_mult_matrix(&matrix_1, &matrix_2, &result),
                   code_valid_error);
  matrix_1.rows = rows;

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(mult_matrix) {
  matrix_t matrix_1, matrix_2, result, check;
  s21_create_matrix(2, 3, &matrix_1);
  s21_create_matrix(3, 2, &matrix_2);
  s21_create_matrix(2, 2, &check);
  int count = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1.matrix[i][j] = count;
      count++;
    }
  }
  count = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_2.matrix[i][j] = count;
      count++;
    }
  }
  check.matrix[0][0] = 10;
  check.matrix[0][1] = 13;
  check.matrix[1][0] = 28;
  check.matrix[1][1] = 40;

  s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_3x6) {
  matrix_t matrix_1, matrix_2, result, check;
  s21_create_matrix(3, 6, &matrix_1);
  s21_create_matrix(6, 4, &matrix_2);
  s21_create_matrix(3, 4, &check);
  int count = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      matrix_1.matrix[i][j] = count;
      count++;
    }
  }
  count = 1;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 4; j++) {
      matrix_2.matrix[i][j] = count;
      count++;
    }
  }
  check.matrix[0][0] = 301;
  check.matrix[0][1] = 322;
  check.matrix[0][2] = 343;
  check.matrix[0][3] = 364;
  check.matrix[1][0] = 697;
  check.matrix[1][1] = 754;
  check.matrix[1][2] = 811;
  check.matrix[1][3] = 868;
  check.matrix[2][0] = 1093;
  check.matrix[2][1] = 1186;
  check.matrix[2][2] = 1279;
  check.matrix[2][3] = 1372;

  s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_matrix_4x3) {
  matrix_t matrix_1, matrix_2, result, check;
  s21_create_matrix(4, 2, &matrix_1);
  s21_create_matrix(2, 3, &matrix_2);
  s21_create_matrix(4, 3, &check);
  int count = 1;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 2; j++) {
      matrix_1.matrix[i][j] = count;
      count++;
    }
  }
  count = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_2.matrix[i][j] = count;
      count++;
    }
  }
  check.matrix[0][0] = 9;
  check.matrix[0][1] = 12;
  check.matrix[0][2] = 15;
  check.matrix[1][0] = 19;
  check.matrix[1][1] = 26;
  check.matrix[1][2] = 33;
  check.matrix[2][0] = 29;
  check.matrix[2][1] = 40;
  check.matrix[2][2] = 51;
  check.matrix[3][0] = 39;
  check.matrix[3][1] = 54;
  check.matrix[3][2] = 69;

  s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number) {
  matrix_t matrix_1, result, check;
  s21_create_matrix(3, 3, &matrix_1);
  s21_create_matrix(3, 3, &check);
  double num = 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      matrix_1.matrix[i][j] = 3;
      check.matrix[i][j] = 9;
    }
  }

  s21_mult_number(&matrix_1, num, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &check), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&check);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mult_number_when_matrix_NULL) {
  matrix_t matrix_1, result;
  matrix_1.matrix = NULL;
  result.matrix = NULL;

  ck_assert_int_eq(s21_mult_number(&matrix_1, 0, &result), code_valid_error);
}
END_TEST

START_TEST(transpose_when_matrix_NULL) {
  matrix_t matrix_1, result;
  matrix_1.matrix = NULL;

  ck_assert_int_eq(s21_transpose(&matrix_1, &result), code_valid_error);
}
END_TEST

START_TEST(transpose_matrix_with_0) {
  matrix_t matrix_1, result, check;
  int rows = 2, columns = 3;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_transpose(&matrix_1, &result);
  s21_create_matrix(columns, rows, &check);

  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

START_TEST(transpose_matrix_2x3) {
  matrix_t matrix_1, result, check;
  int rows = 3, columns = 2, count = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      matrix_1.matrix[j][i] = count;
      count++;
    }
  }

  s21_transpose(&matrix_1, &result);
  s21_create_matrix(columns, rows, &check);
  check.matrix[0][0] = 1;
  check.matrix[0][1] = 2;
  check.matrix[0][2] = 3;
  check.matrix[1][0] = 4;
  check.matrix[1][1] = 5;
  check.matrix[1][2] = 6;

  ck_assert_int_eq(s21_eq_matrix(&check, &result), SUCCESS);

  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&result);
  s21_remove_matrix(&check);
}
END_TEST

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

Suite *arithmetic_suite() {
  Suite *s1 = suite_create("Arithmetic");
  TCase *tc1_1 = tcase_create("arithmetic");

  tcase_add_test(tc1_1, sum_matrix_should_be_eq);
  tcase_add_test(tc1_1, sub_matrix_should_be_eq);
  tcase_add_test(tc1_1,
                 mult_matrix_with_diff_rows_and_columns_should_be_error_code);
  tcase_add_test(tc1_1, mult_matrix_when_rows_0);
  tcase_add_test(tc1_1, mult_matrix);
  tcase_add_test(tc1_1, mult_matrix_3x6);
  tcase_add_test(tc1_1, mult_matrix_4x3);
  tcase_add_test(tc1_1, mult_number);
  tcase_add_test(tc1_1, mult_number_when_matrix_NULL);
  tcase_add_test(tc1_1, transpose_when_matrix_NULL);
  tcase_add_test(tc1_1, transpose_matrix_with_0);
  tcase_add_test(tc1_1, transpose_matrix_2x3);
  tcase_add_test(tc1_1, transpose_matrix_4x3);
  suite_add_tcase(s1, tc1_1);

  return s1;
}