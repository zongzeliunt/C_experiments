#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char *input;
    input = argv[1];


    printf ("hello world\n");

    printf ("argc: %d\n", argc);

    printf("%s\n", argv[argc - 1]);
    printf("%s\n", input);


    printf ("hello world 1\n");


}
