#include "s21_matrix_test.h"

int main() {
  int failed = 0;
  SRunner *sr;
  sr = srunner_create(NULL);
  srunner_add_suite(sr, arithmetic_suite());
  srunner_add_suite(sr, comparsion_suite());
  srunner_add_suite(sr, helper_suite());
  srunner_add_suite(sr, pro_suite());
  srunner_add_suite(sr, determinant_suite());
  failed = srunner_ntests_failed(sr);

  srunner_run_all(sr, CK_NORMAL);
  srunner_free(sr);
  return (failed == 0) ? 0 : 1;
}