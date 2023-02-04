#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid;
    int i,fork;
    for (i = 0; i < 4; i++) {
        pid = fork;
        if (pid == 0) {
            break;
        }
    }
    if (i == 0) {
        printf("First child process ID: %d\n", getpid());
        for (i = 1; i <= 100; i += 2) {
            printf("%d\n", i);
        }
    } else if (i == 1) {
        printf("Second child process ID: %d\n", getpid());
        for (i = 2; i <= 100; i += 2) {
            printf("%d\n", i);
        }
    } else if (i == 2) {
        printf("Third child process ID: %d\n", getpid());
        for (i = 3; i <= 100; i += 3) {
            printf("%d\n", i);
        }
    } else if (i == 3) {
        printf("Fourth child process ID: %d\n", getpid());
        for (i = 5; i <= 100; i += 5) {
            printf("%d\n", i);
        }
    }
    return 0;
}
