#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    int num;
    /*checking if there is any argument passed or not and if not then exiting the program*/
    if (argc == 1)
    {
        printf("No command line argument is passed\n");
        exit(0);
    }

    /*If there is any argument the second element of array will be it, then we will use the atoi function to convert string into num*/
    num = atoi(argv[1]);

    /*checking if the argument is negative*/
    if (num <= 0)
    {
        printf("The number must be a positive integer.\n");
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
        printf("1\n");
    }
    else
    {
        // Parent process may wait for child process to complete
        wait(NULL);
    }
    
    return 0;
}
