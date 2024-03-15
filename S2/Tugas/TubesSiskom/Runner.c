#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <string.h>

int main(int argc, char *argv[])
{
    pid_t child_id;
    int status;

    child_id = fork();

    char command[60];
    char currentDir[50];

    getcwd(currentDir, sizeof(currentDir));
    sprintf(command, "%s/%s", currentDir, "FUSE.exe");

    if (child_id < 0)
    {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }

    if (child_id == 0)
    {
        printf("Mounting %s....\n", argv[1]);
        char *newArgv[] = {command, argv[1], NULL};
        execv(command, newArgv);
    }
    else
    {
        // this is parent
        while ((wait(&status)) > 0)
            ;
        printf("Fetching Data From https://pokeapi.co/api/v2/pokemon/%s\n", argv[2]);
        printf("Please Wait...\n");

        char *pokeCommand[60];
        sprintf(pokeCommand, "%s/%s", currentDir, "get.exe");

        char *newArg[] = {pokeCommand, argv[2]};

        execv(pokeCommand, newArg);

        perror("execv");
        exit(EXIT_FAILURE);
    }
}