#include <stdio.h>
#include <string.h>
#include <proyecto.h>
#include <sys/stat.h>
#include <makefile.h>
#include <mkdir.h>
#define code_java "package main;\n\npublic class Main{\n\tpublic static void main(String[] args){\n\t\t//Inserte su codigo de la funcion main\n\t}\n}\n\n\0"
//#define makefile 1200

void newProject(char**argv){
	if(strcmp(argv[2],"nuevo") == 0) { createProject(argv[3],argv[0]); }
	else if (strcmp(argv[2],"carga") == 0) { puts("Aun no disponible."); }
	else { puts("Comando invalido - busque ayuda en -h"); }
}

void createProject(char*address,char*dirBase){
	char project[200],dir[200];
	strcpy(project,address);
	strcpy(dir,address);
	strcat(dir,"/src/main/Main.java");
	dirMain(project);
	fileMain(project,dir);
	make(project/*,dirBase*/);
}

void dirMain(char*address){
	char file[200];
	//mkdir(address);
	createDir(address);
	strcpy(file,address);
	strcat(file,"/src");
	//mkdir(file);
	createDir(file);
	strcat(file,"/main");
	//mkdir(file,0755);
	//mkdir(file);
	createDir(file);
}

void fileMain(char*address,char*file){
	FILE*Main;
	char code[] = code_java;
	Main = fopen(file,"w");
	fwrite(code,1,(sizeof code)-2,Main);
	fclose(Main);
}


void make(char *project/*,char *dirBase*/)
{
	//char dir[100];
	char address[200];
	//strcpy(dir,dirBase);
	strcpy(address,project);
	strcat(address,"/Makefile");
	FILE *paste = fopen(address,"wb");
	fwrite(bin_debug_Makefile,bin_debug_Makefile_len,1,paste);
	fclose(paste);
}




/*
void make(char*project,char*dirBase){
	char dir[100];
	strcpy(dir,dirBase);
	//char*last = strrchr(dir,'/');
	//if(last!= NULL) *last='\0';

	//FILE *copy;
	FILE *paste;
	char address[200];
	strcpy(address,project);
	strcat(address,"/Makefile");
	//strcpy(dir,"/usr/bin/Makefile");
	//printf("%s\n",dir);
	//copy = fopen(dir,"rb");
	paste = fopen(address,"wb");

	//char file[bin_debug_Makefile_len];
	//for(int i=0; i<bin_debug_Makefile_len; i++) file[i]=0x0A;
	//fread(file,bin_debug_Makefile,1,copy);
	//fwrite(file,bin_debug_Makefile_len,1,paste);
	fwrite(bin_debug_Makefile,bin_debug_Makefile_len,1,paste);

	//fclose(copy);
	fclose(paste);
}
*/
