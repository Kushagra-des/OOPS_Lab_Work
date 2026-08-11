#include<stdio.h>
#include<string.h>

int strend (char*s, char *t) {
int len_s = strlen (s);
int len_t = strlen (t);
if(len_t > len_s) {
    return 0;
}
for (int i = 0; i< len_t; i++) {
     if (s[len_s - len_t + i] != t[i]) {
            return 0; }}
     return 1;
}

int main ()
{

    char s[] = "Object Oriented Programming using C++";
    char t[] = "C++";
    if (strend(s,t)) {
        printf("'%s' is AT the End of '%s'\n",t,s);
    } else {
    printf("'%s is NOT at the End of'%s'\n", t,s);
    }
    return 0;
}
