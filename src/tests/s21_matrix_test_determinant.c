#include "s21_matrix_test.h"

START_TEST(determinant_1x1) {
  matrix_t matrix_1;
  double result = 0, check = 10001;
  int rows = 1, columns = 1, count = 10001;
  s21_create_matrix(rows, columns, &matrix_1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = count;
      count++;
    }
  }

  s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_1x1_when_0) {
  matrix_t matrix_1;
  double result = 0, check = 0;
  int rows = 1, columns = 1, count = 0;
  s21_create_matrix(rows, columns, &matrix_1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = count;
    }
  }

  s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_2x2_when_all_0) {
  matrix_t matrix_1;
  double result = 1, check = 0;
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_1.matrix[0][0] = 0;
  matrix_1.matrix[0][1] = 0;
  matrix_1.matrix[1][0] = 0;
  matrix_1.matrix[1][1] = 0;

  s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_2x2_easy) {
  matrix_t matrix_1;
  double result = 0, check = -2;
  int rows = 2, columns = 2, count = 1;
  s21_create_matrix(rows, columns, &matrix_1);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = count;
      count++;
    }
  }

  s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_2x2_diag_eq_0) {
  matrix_t matrix_1;
  double result = 0, check = -2;
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &matrix_1);

  matrix_1.matrix[0][0] = 0;
  matrix_1.matrix[0][1] = 1;
  matrix_1.matrix[1][0] = 2;
  matrix_1.matrix[1][1] = 0;

  s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_2x2_hard) {
  matrix_t matrix_1;
  double result = 0, check = -613101888999;
  int rows = 2, columns = 2;
  s21_create_matrix(rows, columns, &matrix_1);
  matrix_1.matrix[0][0] = 123123;
  matrix_1.matrix[0][1] = 85237;
  matrix_1.matrix[1][0] = 7297452;
  matrix_1.matrix[1][1] = 72375;

  s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&matrix_1);
}
END_TEST

START_TEST(determinant_3x3_with_0) {
  matrix_t A;
  double result = 0, check = 6;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 2;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 0;

  s21_determinant(&A, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3x3_only_0) {
  matrix_t A;
  double result = -1, check = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 0;
  A.matrix[0][2] = 0;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 0;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 0;

  s21_determinant(&A, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3x3_easy_when_det_0) {
  matrix_t A;
  double result = -1, check = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;

  s21_determinant(&A, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_3x3_hard) {
  matrix_t A;
  double result = 1, check = -310311824;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 235.;
  A.matrix[0][1] = 141.;
  A.matrix[0][2] = 914.;
  A.matrix[1][0] = 842.;
  A.matrix[1][1] = 0.;
  A.matrix[1][2] = 150.;
  A.matrix[2][0] = 185.;
  A.matrix[2][1] = -128.;
  A.matrix[2][2] = 1855.;

  s21_determinant(&A, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4x4_0) {
  matrix_t A;
  double result = 1, check = 0;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 7;
  A.matrix[1][3] = 8;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = 11;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 13;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 16;

  s21_determinant(&A, &result);

  ck_assert_int_eq(result, check);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4x4) {
  matrix_t A;
  double result = 0, check = 3748276;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[0][3] = -4;
  A.matrix[1][0] = 51;
  A.matrix[1][1] = 6;
  A.matrix[1][2] = 72;
  A.matrix[1][3] = -8;
  A.matrix[2][0] = 91;
  A.matrix[2][1] = 10;
  A.matrix[2][2] = -115;
  A.matrix[2][3] = 12;
  A.matrix[3][0] = 134;
  A.matrix[3][1] = 14;
  A.matrix[3][2] = 15;
  A.matrix[3][3] = 161;

  s21_determinant(&A, &result);

  ck_assert_double_eq_tol(result, check, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_4x4_when_diag_0) {
  matrix_t A;
  double result = 0, check = -203880;
  s21_create_matrix(4, 4, &A);
  A.matrix[0][0] = 0.;
  A.matrix[0][1] = 2.;
  A.matrix[0][2] = 3.;
  A.matrix[0][3] = -4.;
  A.matrix[1][0] = 51.;
  A.matrix[1][1] = 0.;
  A.matrix[1][2] = 72.;
  A.matrix[1][3] = -8.;
  A.matrix[2][0] = 91.;
  A.matrix[2][1] = 10.;
  A.matrix[2][2] = 0.;
  A.matrix[2][3] = 12.;
  A.matrix[3][0] = 134.;
  A.matrix[3][1] = 14.;
  A.matrix[3][2] = 15.;
  A.matrix[3][3] = 0.;

  s21_determinant(&A, &result);

  ck_assert_double_eq_tol(result, check, 1e-7);

  s21_remove_matrix(&A);
}
END_TEST

Suite *determinant_suite() {
  Suite *s1 = suite_create("Determinant");
  TCase *tc1_1 = tcase_create("determinant");

  tcase_add_test(tc1_1, determinant_1x1);
  tcase_add_test(tc1_1, determinant_1x1_when_0);
  tcase_add_test(tc1_1, determinant_2x2_when_all_0);
  tcase_add_test(tc1_1, determinant_2x2_easy);
  tcase_add_test(tc1_1, determinant_2x2_diag_eq_0);
  tcase_add_test(tc1_1, determinant_2x2_hard);
  tcase_add_test(tc1_1, determinant_3x3_with_0);
  tcase_add_test(tc1_1, determinant_3x3_only_0);
  tcase_add_test(tc1_1, determinant_3x3_easy_when_det_0);
  tcase_add_test(tc1_1, determinant_3x3_hard);
  tcase_add_test(tc1_1, determinant_4x4_0);
  tcase_add_test(tc1_1, determinant_4x4);
  tcase_add_test(tc1_1, determinant_4x4_when_diag_0);

  suite_add_tcase(s1, tc1_1);

  return s1;
}