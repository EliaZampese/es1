#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void) {
    pid_t r = fork();
    if (r == -1) {
        perror("Errore del fork");
        exit(-1);
    }

    if (!r) {
        sleep(5);
        printf("Il figlio conta: \n");
        for (int i = 1; i < 6; i++) {
            printf("%d \n", i);
        }
        exit(0);
    }
    int status = 5;
    wait(&status);

    printf("Il padre conta: \n");
    for (int j = 6; j < 11; j++) {
        printf("%d \n", j);
    }








    return 0;
}
