#pragma once

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef NULL
#define NULL 0x00
#endif

extern void build(int argc,char **argv);
extern void run();
extern void export(int argc,char**argv);
extern void jar();

