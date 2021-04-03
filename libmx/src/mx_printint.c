#include "libmx.h"

void mx_printint(int n) {   
    if (n < 0) {
        n *= -1;
        mx_printchar('-');
    }
    if (n == -2147483648) {
        write( 1, "2147483648", 10); 
    }
    if ((n >= 0) && (n <= 9)) {
        mx_printchar(n + 48);
    }
    if (n > 9) { 
            mx_printint(n / 10);
            mx_printchar((n % 10) + 48);
    }
}
