#define BUILTINS_COUNT 4
#define GASH_VERSION 0.1

void builtin_cd(char** args);
void builtin_pwd(char** args);
void builtin_export(char** args);
void builtin_version(char** args);

struct Builtin {
    char *name;
    void (*func)(char** args);
};

struct Builtin builtins[] = {
    {"cd", &builtin_cd},
    {"pwd", &builtin_pwd},
    {"export", &builtin_export},
    {"version", &builtin_version}
};
