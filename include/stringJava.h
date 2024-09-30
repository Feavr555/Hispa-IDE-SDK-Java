#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <mkdir.h>

extern char*reserve(int size,char format);
extern int size_of(char*str,int size);
extern FILE*createFile(char*namePack,char*nameFile);
extern char*writeJava(char*namePack,char*nameFile);
