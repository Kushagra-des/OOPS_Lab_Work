#include <stdio.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
        }
    return length;
    }
int main()
{
    char name[100];
    printf("Enter your full name: ");
    fgets(name, sizeof(name), stdin);
    int length = stringLength(name);
    if (length > 0 && name[length - 1] == '\n') {
        length--; // Ignore the newline character
    }
    printf("Length of your name (excluding newline) is: %d\n", length);
    return 0;
}
