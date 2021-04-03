unsigned long mx_pow(unsigned long n, unsigned int pow) {
    unsigned long m = n;
    if (pow == 0) return 1;
    else if (pow == 1) return n;
    else {
        for (unsigned int i = 1; i < pow; i++){
            n *= m;    
        }
        return n;
    }
}

unsigned long mx_hex_to_nbr(const char *hex) {
    int i = 0;
    int len = 0; 
    int val = 0;
    unsigned long nbr = 0;

    for (; hex[i] != '\0'; i++) 
        len++;
    for (i = 0; i < len; i++) {
        if (hex[i] >= '0' && hex[i] <= '9')
            val = hex[i] - 48;
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            val = hex[i] - 65 + 10;
        else if (hex[i] >= 'a' && hex[i] <= 'f')
            val = hex[i] - 97 + 10; 
        nbr += val * mx_pow(16, len - i - 1);   
    }  
    return nbr; 
}
