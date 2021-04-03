#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    unsigned long result = nbr;
    int residue;
    char *hex= mx_strnew(1000);
    int i = 0;

    while (result != 0) {
        residue = result % 16;
        result /= 16;
        if (residue >= 0 && residue <= 9) {
            hex[i] = residue + 48;
        }
        else if (residue >= 10 && residue <= 15) {
            hex[i] = residue + 87;
        }
        i++;
    }
    mx_str_reverse(hex);
    return hex;
}
