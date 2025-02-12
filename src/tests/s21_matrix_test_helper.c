#include "s21_matrix_test.h"

START_TEST(create_matrix_result_null) {
  int rows = 1, columns = 1;

  ck_assert_int_eq(s21_create_matrix(rows, columns, NULL), code_valid_error);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_B_null) {
  matrix_t A, result;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &result);

  ck_assert_int_eq(s21_sum_sub_validator(&A, NULL, &result), code_valid_error);

  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_A_null) {
  matrix_t B, result;
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &result);

  ck_assert_int_eq(s21_sum_sub_validator(NULL, &B, &result), code_valid_error);

  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_result_null) {
  matrix_t B, A;
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &A);

  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, NULL), code_valid_error);

  s21_remove_matrix(&B);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_A_rows_0) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  A.rows = 0;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result), code_valid_error);
  A.rows = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_A_columns_0) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  A.columns = 0;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result), code_valid_error);
  A.columns = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_B_rows_0) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  B.rows = 0;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result), code_valid_error);
  B.rows = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_B_columns_0) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  B.columns = 0;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result), code_valid_error);
  B.columns = 1;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_rows_different) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows + 1, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result),
                   code_arithmetic_error);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_matrix_columns_different) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns + 1, &B);
  s21_create_matrix(rows, columns, &result);
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result),
                   code_arithmetic_error);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_A_value_nan) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  A.matrix[0][0] = NAN;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result),
                   code_arithmetic_error);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_A_value_inf) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  A.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result),
                   code_arithmetic_error);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_B_value_nan) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  B.matrix[0][0] = NAN;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result),
                   code_arithmetic_error);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_sum_sub_when_B_value_inf) {
  matrix_t A, B, result;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  s21_create_matrix(rows, columns, &result);
  B.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_sum_sub_validator(&A, &B, &result),
                   code_arithmetic_error);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(validator_value_matrix_null) {
  ck_assert_int_eq(s21_value_validator(NULL), code_valid_error);
}
END_TEST

START_TEST(validator_value_inf) {
  matrix_t A;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_value_validator(&A), code_arithmetic_error);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(validator_value_nan) {
  matrix_t A;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  A.matrix[0][0] = INFINITY;
  ck_assert_int_eq(s21_value_validator(&A), code_arithmetic_error);

  s21_remove_matrix(&A);
}
END_TEST

Suite *helper_suite() {
  Suite *s1 = suite_create("Helper");
  TCase *tc1_1 = tcase_create("helper");
  tcase_add_test(tc1_1, create_matrix_result_null);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_B_null);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_A_null);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_result_null);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_A_rows_0);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_A_columns_0);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_B_rows_0);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_B_columns_0);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_rows_different);
  tcase_add_test(tc1_1, validator_sum_sub_when_matrix_columns_different);
  tcase_add_test(tc1_1, validator_sum_sub_when_A_value_nan);
  tcase_add_test(tc1_1, validator_sum_sub_when_A_value_inf);
  tcase_add_test(tc1_1, validator_sum_sub_when_B_value_nan);
  tcase_add_test(tc1_1, validator_sum_sub_when_B_value_inf);
  tcase_add_test(tc1_1, validator_value_matrix_null);
  tcase_add_test(tc1_1, validator_value_inf);
  tcase_add_test(tc1_1, validator_value_nan);
  suite_add_tcase(s1, tc1_1);
  return s1;
}