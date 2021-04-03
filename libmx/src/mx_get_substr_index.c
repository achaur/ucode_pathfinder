#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    int i = 0;
    int count;
    int j;

    if (!str || !sub) return -2;
    for (; str[i] != '\0';) {
        j = 0;
        count = 0;
        while (str[i] == sub[j]) {   
            count++;
            i++;
            j++;  
        }
        if (count == mx_strlen(sub)) {
            return i - mx_strlen(sub);
        }
        else
            i++;
    } 
    return -1;
}
