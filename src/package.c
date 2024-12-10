#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stringJava.h>

void asistente(char argv){
	switch(argv){
		case 'v':
			puts("Hispa SDK Java - alpha unstable 0.1.5");
			puts("Autor: Marco P. Debiasi");
			break;
		case 'h':
			printf("sdk -h : %chelp%c\n\n",0x22,0x22);
			puts("sdk proyecto nuevo [nombre del proyecto]");
			puts("\tCrea un nuevo proyecto.\n");
			puts("sdk proyecto carga [nombre del proyecto]");
			puts("\tAun no disponible.\n");
			puts("sdk package [nombre del paquete] [nombre del archivo]");
			puts("\tCrea un nuevo paquete java con su arhivo de codigo.");
			puts("\tTiene que entrar en su proyecto.\n");
			break;
		default:
			printf("Para ayuda inserte %c-h%c\n",0x22,0x22);
			break;
	}
}

void addPack(char*namePack,char*nameFile){
	FILE*java = createFile(namePack,nameFile);
	char*code = writeJava(namePack,nameFile);
	int j = size_of(code,strlen(code) + 12);
	fwrite(code,1,j,java);
	fclose(java);
	free(code);
}

