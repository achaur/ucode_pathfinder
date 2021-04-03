#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    int count_sub = 0;
    int j;
    int i = 0;
    int count;

    if (!str || !sub) return -1;
    if (mx_strlen(sub) == 0) return 0;
    for (; str[i] != '\0';) {
        j = 0;
        count = 0;
            while (str[i] == sub[j]) {   
                count++;
                i++;
                j++;  
            }
            if (count == mx_strlen(sub)) {
                count_sub++;
                count = 0;
            }
            else
                i++;
        }   
    return count_sub;
}
