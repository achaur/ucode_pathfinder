#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    int i;
    int j;
    int count;
    const char *hstart = haystack;

    for (i = 0; haystack[i] != '\0';) {
        j = 0;
        count = 0;
            while (haystack[i] == needle[j]) {   
                count++;
                i++;
                j++;  
            }
            if (count == mx_strlen(needle)) {
                
                hstart = &haystack[i - mx_strlen(needle)];
                return (char *) hstart;
            }
            else
                i++;
    }
    return NULL;
}
