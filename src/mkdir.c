#include <mkdir.h>

#ifdef linux

void createDir(const char *name)
{
    mkdir(name,0755);
}

#else

void createDir(const char *name)
{
    mkdir(name);
}

#endif
