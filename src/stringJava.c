#include <stringJava.h>
#include <sys/stat.h>

char*reserve(int size,char format){
	char*str = (char*)malloc(size);
	for (int i=0; i<size; ++i)
		str[i] = format;
	return str;
}

int size_of(char*str,int size){
	int i=0,j=0;
	while(i<size) {if(str[i]==0x00) {j=i;} i++;}
	return j;
}


FILE*createFile(char*namePack,char*nameFile){
	FILE*java;
	char*code = reserve(50,0x20);
	strcpy(code,"src/");
	strcat(code,namePack);
	//mkdir(code,0755);
	//mkdir(code);
	createDir(code);
	strcat(code,"/");
	strcat(code,nameFile);
	strcat(code,".java");
	java = fopen(code,"w");
	free(code);
	return java;
}

char*writeJava(char*namePack,char*nameFile){
	char*code = reserve(100,0x20);
	char*func = reserve(50,0x20);
	strcpy(func,"\tpublic ");
	strcat(func,nameFile);
	strcat(func,"(){\n");
	strcat(func,"\t\t//Inserte su código aquí...\n\t}\n}\n");

	strcpy(code,"package ");
	strcat(code,namePack);
	strcat(code,";\n\npublic class ");
	strcat(code,nameFile);
	strcat(code,"{\n");
	strcat(code,func);
	return code;
}

/*
char*compatibleJava(char*str,int size){
	int i=0;
	while(i<size) {if(str[i]==0x00) {str[i]=0x20;} i++;}
	char*string = (char*)malloc(size);
	while(i<size) {string[i]=str[i]; i++;}
	return string;
}

int comp(char*txt1,char*txt2){
	char t1=txt1[0];
	char t2=txt2[0];
	int i=0;
	while(t1!='\0' || t2!='\0'){
		if(t1!=t2) return 0;
		i++;
		t1=txt1[i];
		t2=txt2[i];
	}
	return 1;	
}
*/
