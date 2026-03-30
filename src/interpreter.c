#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include "../include/builtins.h"

int main(){
    using_history();
    if (setenv("GASH_PROMPT", "Gash > ", 0) != 0){
        perror("gash");
        return 1;
    }
    while (1){
        char *input = readline(getenv("GASH_PROMPT"));
        if (input == NULL){
            while (wait(NULL) > 0);
            char historyPath[512];
            char* home = getenv("HOME");
            snprintf(historyPath, sizeof(historyPath), "%s/.gash_history", home);
            write_history(historyPath);
            free(input);
            printf("\ngash: Exiting from Gash...\n");
            break;
        }
        input[strcspn(input, "\n")] = '\0';
        if (*input) add_history(input);
        int is_builtin = 0;
        char* args[64];
        int i = 0;
        args[i] = strtok(input, " ");
        while (args[i] != NULL){
            i++;
            args[i] = strtok(NULL, " ");
        }
        if (args[0] == NULL) continue;
        if (strcmp(args[0], "exit") == 0){
            while (wait(NULL) > 0);
            char historyPath[512];
            char* home = getenv("HOME");
            snprintf(historyPath, sizeof(historyPath), "%s/.gash_history", home);
            write_history(historyPath);
            free(input);
            printf("\ngash: Exiting from Gash...\n");
            break;
        }
        for (i = 0; i < BUILTINS_COUNT; i++){
            if (strcmp(builtins[i].name, args[0]) == 0){
                builtins[i].func(args);
                is_builtin = 1;
                break;
            }
        }
        if (is_builtin == 1) continue;
        pid_t pid = fork();
        if (pid == 0){
            execvp(args[0], args);
            fprintf(stderr, "gash: %s not found!", args[0]);
            exit(127);
        } else if (pid == -1){
            perror("gash");
            exit(1);
        } else {
            int status;
            waitpid(pid, &status, 0);
        }
    }
}
