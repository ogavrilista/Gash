#define BUILTINS_COUNT 4
#define GASH_VERSION "0.1"

int builtin_cd(char** args);
int builtin_pwd(char** args);
int builtin_export(char** args);
int builtin_version(char** args);

struct Builtin {
    char *name;
    int (*func)(char** args);
};
