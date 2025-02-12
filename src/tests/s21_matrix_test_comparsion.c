#include "s21_matrix_test.h"

START_TEST(eq_when_matrix_eq) {
  matrix_t matrix_1, matrix_2;
  int rows = 3, columns = 3, count = 0;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = count;
      matrix_2.matrix[i][j] = count;
      count++;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_when_matrix_rows_diff) {
  matrix_t matrix_1, matrix_2;
  int rows = 3, columns = 3;
  s21_create_matrix(rows + 1, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_when_matrix_columns_diff) {
  matrix_t matrix_1, matrix_2;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns + 1, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);

  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_whith_small_num) {
  matrix_t matrix_1, matrix_2;
  int rows = 3, columns = 3;
  double count = 0.0000001;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = count;
      matrix_2.matrix[i][j] = count;
      count += 0.0000001;
    }
  }
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 1);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_whith_small_num_diff) {
  matrix_t matrix_1, matrix_2;
  int rows = 3, columns = 3;
  double count = 0.000001;
  s21_create_matrix(rows, columns, &matrix_1);
  s21_create_matrix(rows, columns, &matrix_2);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      matrix_1.matrix[i][j] = count;
      matrix_2.matrix[i][j] = count;
      count += 0.0000001;
    }
  }
  matrix_2.matrix[0][0] += 0.0000001;
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), 0);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(eq_when_matrix_is_null) {
  matrix_t matrix_1;
  s21_create_matrix(1, 1, &matrix_1);

  ck_assert_int_eq(s21_eq_matrix(&matrix_1, NULL), 0);
  s21_remove_matrix(&matrix_1);
}
END_TEST

Suite *comparsion_suite() {
  Suite *s1 = suite_create("Comparsion");
  TCase *tc1_1 = tcase_create("comparsion");
  tcase_add_test(tc1_1, eq_when_matrix_eq);
  tcase_add_test(tc1_1, eq_when_matrix_rows_diff);
  tcase_add_test(tc1_1, eq_when_matrix_columns_diff);
  tcase_add_test(tc1_1, eq_when_matrix_is_null);
  tcase_add_test(tc1_1, eq_whith_small_num);
  tcase_add_test(tc1_1, eq_whith_small_num_diff);
  suite_add_tcase(s1, tc1_1);
  return s1;
}