#define BUILTINS_COUNT 3

void builtin_cd(char** args);
void builtin_pwd(char** args);
void builtin_export(char** args);

struct Builtin {
    char *name;
    void (*func)(char** args);
};

struct Builtin builtins[] = {
    {"cd", &builtin_cd},
    {"pwd", &builtin_pwd},
    {"export", &builtin_export}
};
