#include "libmx.h"

int mx_atoi(const char *s) {
    if (*s == '\0')     
        return 0;
    unsigned long long output = 0;
    int sign = 1;
    int i = 0;
    
    while (mx_isspace(s[i]))
        i++;
    if (s[i] == '-' || s[i] == '+') {
        sign = 1 - 2 * (s[i++] == '-');
    } 
    while (mx_isdigit(s[i])) {
        if (sign == -1 && ((output > -(LONG_MIN / 10)) || ((output == -(LONG_MIN / 10)) 
            && (s[i] - 48 > -(LONG_MIN % 10)))))
            return 0;
        if ((output > (LONG_MAX / 10)) || ((output == (LONG_MAX / 10)) 
            && s[i] - 48 > LONG_MAX % 10 && sign != -1))
            return -1;
        output = output * 10 + s[i++] - 48;
    }
    return output * sign;
}
