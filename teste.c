#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char c;
    while (scanf ("%c", &c ) != EOF)
        printf("%d ",c );
    printf("\n");
}