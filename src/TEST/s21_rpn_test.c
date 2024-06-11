#include <check.h>
#include "../SmartCalc/polish.h"

START_TEST(calc_str_1) {
    const char *input = "2 ^ 2 ^ 2";
    double x = 3;
    char* my_res = startRPN(input, x);
    char* original_res = "16.0000000";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_2) {
    const char *input = "sin ( 1 )";
    double x = 5;
    char* my_res = startRPN(input, x);
    char* original_res = "0.8414710";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_3) {
    const char *input = "fsdgsdfgsdg";
    double x = 6;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_4) {
    const char *input = "fsdgsdfgsdg";
    double x = 4;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_5) {
    const char *input = "tan ( 1 )";
    double x = -1;
    char* my_res = startRPN(input, x);
    char* original_res = "1.5574077";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_6) {
    const char *input = "cos ( 1 )";
    double x = 8;
    char* my_res = startRPN(input, x);
    char* original_res = "0.5403023";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_7) {
    const char *input = "acos ( 1 )";
    double x = 0;
    char* my_res = startRPN(input, x);
    char* original_res = "0.0000000";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_8) {
    const char *input = "asin ( 1 )";
    double x = 99;
    char* my_res = startRPN(input, x);
    char* original_res = "1.5707963";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_9) {
    const char *input = "atan ( 1 )";
    double x = 110;
    char* my_res = startRPN(input, x);
    char* original_res = "0.7853982";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_10) {
    const char *input = "atan ( x )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "0.7853982";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_11) {
    const char *input = "sin ( - 1 + 2 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "0.8414710";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_12) {
    const char *input = "- 1 + sin ( - 1 + 2 ) + sin ( 1 + 3 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "-0.9153315";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_13) {
    const char *input = "- 1 + sin ( - 1 + 2 ) * sin ( 1 + 3 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "-1.6368273";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_14) {
    const char *input = "acos ( 3 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Ошибка вычислений";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_15) {
    const char *input = "asin ( 3 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Ошибка вычислений";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_16) {
    const char *input = "atan ( 3 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "1.2490458";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_17) {
    const char *input = "ln ( 1 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "0.0000000";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_18) {
    const char *input = "- 1 + sin ( - 1 + 2 ) * sqrt ( 3 - 1 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "0.1900197";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_19) {
    const char *input = "- 1 + sin ( - 1 + 2 ) / sqrt ( 2 + 1 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "-0.5141765";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_20) {
    const char *input = "log ( 3 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "0.4771213";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_21) {
    const char *input = "- 1 + sin ( - 1 + 2 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "-0.1585290";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_22) {
    const char *input = "- 1 + sin ( 2 %% 1 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "-1.0000000";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_23) {
    const char *input = "sin ( ( - 1 + 2 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_24) {
    const char *input = "sin ( - - 1 + 2 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_25) {
    const char *input = "sin - - 1 + 2 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_26) {
    const char *input = "sin sin ( - 1 + 2 )";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_27) {
    const char *input = "2 2";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_28) {
    const char *input = "^";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

START_TEST(calc_str_29) {
    const char *input = "2 %% %% 2";
    double x = 1;
    char* my_res = startRPN(input, x);
    char* original_res = "Ошибка: Неправильное выражение";
    ck_assert_str_eq(my_res,original_res);
}
END_TEST

int main(void) {
    Suite *s1 = suite_create("Core");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1,tc1_1);
    tcase_add_test(tc1_1, calc_str_1);
    tcase_add_test(tc1_1, calc_str_2);
    tcase_add_test(tc1_1, calc_str_3);
    tcase_add_test(tc1_1, calc_str_4);
    tcase_add_test(tc1_1, calc_str_5);
    tcase_add_test(tc1_1, calc_str_6);
    tcase_add_test(tc1_1, calc_str_7);
    tcase_add_test(tc1_1, calc_str_8);
    tcase_add_test(tc1_1, calc_str_9);
    tcase_add_test(tc1_1, calc_str_10);
    tcase_add_test(tc1_1, calc_str_11);
    tcase_add_test(tc1_1, calc_str_12);
    tcase_add_test(tc1_1, calc_str_13);
    tcase_add_test(tc1_1, calc_str_14);
    tcase_add_test(tc1_1, calc_str_15);
    tcase_add_test(tc1_1, calc_str_16);
    tcase_add_test(tc1_1, calc_str_17);
    tcase_add_test(tc1_1, calc_str_18);
    tcase_add_test(tc1_1, calc_str_19);
    tcase_add_test(tc1_1, calc_str_20);
    tcase_add_test(tc1_1, calc_str_21);
    tcase_add_test(tc1_1, calc_str_22);
    tcase_add_test(tc1_1, calc_str_23);
    tcase_add_test(tc1_1, calc_str_24);
    tcase_add_test(tc1_1, calc_str_25);
    tcase_add_test(tc1_1, calc_str_26);
    tcase_add_test(tc1_1, calc_str_27);
    tcase_add_test(tc1_1, calc_str_28);
    tcase_add_test(tc1_1, calc_str_29);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);
    return nf == 0 ? 0 : 1;
}