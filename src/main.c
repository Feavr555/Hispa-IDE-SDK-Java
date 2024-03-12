#include <proyecto.h>
#include <package.h>
#include <stdio.h>
#include <string.h>


int listEvent(char**argv){
	if (argv[1][0] == '-') { asistente(argv[1][1]); }
	else if (strcmp(argv[1],"proyecto") == 0) { newProject(argv); }
	else if (strcmp(argv[1],"package") == 0) { addPack(argv[2],argv[3]); }
	else { puts("Comando invalido - busque ayuda en -h"); }
	return 0;
}


int main(int argc,char**argv){
	if (argc == 1) return 0;
	return listEvent(argv);
}
