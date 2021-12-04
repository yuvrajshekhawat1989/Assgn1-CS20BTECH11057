#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int num;
    // checking if there is any argument passed or not and if not then exiting the program
    if (argc == 1)
    {
        printf("No command line argument is passed\n");
        exit(0);
    }

    // converting the char into integer
    num = atoi(argv[1]);

    // checking - is the argument positive interger or not
    if (num <= 0)
    {
        printf("\nThe number should be a positive interger.\n\n");
        exit(0);
    }

    if (fork() == 0)
    {
        // Child process
        while (num > 1)
        {
            printf("%d ", num);
            if (num % 2 == 0)
                num = num / 2;
            else
                num = 3 * num + 1;
        }
        printf("1\n\n");
    }
    else
    {
        // Parent process - waiting for child to complete
        wait(NULL);
    }

    return 0;
}
