// #include <stdio.h>

int mx_strlen(const char *s) {
    int c = 0;

    for (int i = 0; s[i] != '\0'; i++)
        c++; 
    return c;   
}

// int main() {
//     printf("%d",mx_strlen(""));
// }
