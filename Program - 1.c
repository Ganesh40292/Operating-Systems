#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;

    printf("Parent Process Started\n");
    printf("Parent PID: %d\n", getpid());

    pid = fork();

    if (pid < 0)
    {
        perror("Fork failed");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("\nChild Process Created\n");
        printf("Child PID: %d\n", getpid());
        printf("Parent PID (from child): %d\n", getppid());

        printf("\nChild executing exec()...\n");
        execlp("ls", "ls", NULL);

        perror("Exec failed");
        exit(1);
    }
    else
    {
        printf("\nParent waiting for child to terminate...\n");
        wait(NULL);

        printf("Child process terminated\n");
        printf("Parent process terminating\n");
    }

    return 0;
}
