#include "libmx.h"

char *mx_itoa(int number) {
    char *str = mx_strnew(100);
    int i = 0;
    bool IsNegative = false;

    if (number == -2147483648) {
        mx_strcpy(str, "-2147483648");
        return str;
    }
    if (number < 0) {
        IsNegative = true;
        number *= -1; 
    }
    if (number == 0) 
        str[i++] = '0';
    if (number > 0) {
        while (number != 0) {
            str[i++] = number % 10 + 48;
            number /= 10; 
        }
    }
    if (IsNegative) 
        str[i++] = '-';
    str[i] = '\0';
    mx_str_reverse(str);
    return str;
}
