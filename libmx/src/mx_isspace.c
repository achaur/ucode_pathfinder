#include <stdio.h>
#include <stdbool.h>


bool mx_isspace(char c){


if ((c > 8 && c < 14) || c == 32){
    return 1;
    }
else { 
    return 0;
    }

}

// int main(){

//     mx_isspace(' ');
//     printf("%d", mx_isspace(' '));
//     return 0;

// }
