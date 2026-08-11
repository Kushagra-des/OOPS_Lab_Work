#include<stdio.h>
void strcat_ptr (char *s, char *t) {
while (*s) s++;
while (*t) *s++ = *t++;
*s = '\0';
}
    int main () {
    printf("This is a C Program from our Lab Exercise 2! \n\n");
    char s [100] = "Hello,";
    char t [] = " World !";
    strcat_ptr (s,t);
    printf("The Concatenated String we want is : %s\n",s);
    return 0;
    }
