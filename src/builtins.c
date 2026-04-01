#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

static int argcount(char **args){
    int i = 0;
    while (args[i] != NULL){
        i++;
    }
    return i;
}

int builtin_cd(char **args){
    int argc = argcount(args);
    if (argc > 2){
        fprintf(stderr, "cd: too many arguments\n");
        return 1;
    } else if (argc < 2){
        if (chdir(getenv("HOME"))){
            perror("cd");
            return 1;
        }
    } else {
        if (chdir(args[1])){
            perror("cd");
            return 1;
        }
    }
    return 0;
}

int builtin_pwd(char** args){
    char workingDirectory[4096];
    int argc = argcount(args);
    if (argc > 1){
        fprintf(stderr, "pwd: too many arguments\n");
        return 1;
    }
    getcwd(workingDirectory, sizeof(workingDirectory));
    printf("%s\n", workingDirectory);
    return 0;
}

int builtin_export(char** args){
    char** exportArgs[3];
    int argc = argcount(args);
    if (argc > 2){
        fprintf(stderr, "export: too many arguments\n");
        return 1;
    } else if (argc < 2){
        extern char **environ;
        int i = 0;
        while (environ[i] != NULL) {
            printf("%s\n", environ[i]);
            i++;
        }
    } else {
        char* exportEnv = strdup(args[1]);
        char* exportArgs[2];
        exportArgs[0] = strtok(exportEnv, "=");
        exportArgs[1] = strtok(NULL, "=");
        if (exportArgs[0] == NULL || exportArgs[1] == NULL){
            fprintf(stderr, "export: Use VAR=value.");
            return 1;
        }
        if (setenv(exportArgs[0], exportArgs[1], 1) != 0){
            perror("export");
            return 1;
        }
    }
    return 0;
}

int builtin_version(char** args){
    puts(GASH_VERSION);
    return 0;
}
