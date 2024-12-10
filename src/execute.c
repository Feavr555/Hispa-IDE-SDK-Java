#include <execute.h>
#include <vector.h>

int post_point(char *string,char *comp)
{
	int i = 0;
	char keyboard[20];
	while(i < strlen(string)){
		if(string[i] == '.' && string[0] != '.'){
			int j = 0;
			while(i < strlen(string)){
				keyboard[j] = string[i];
				j++;
				i++;
			}
			if(strcmp(comp,keyboard) == 0)
				return 1;
		}
		i++;
	}
	return 0;
}

char *getFiles(DIR *folder,struct dirent *directorio,char *name_pack,char *suFiles)
{
	char *dirs = (char*)malloc(200);
	if(folder == NULL) { puts("Error aquí!\n"); }
	while((directorio = readdir(folder))){
		if(directorio->d_name[0] != '.' && post_point(directorio->d_name,suFiles)){
			strcat(dirs,name_pack);
			strcat(dirs,directorio->d_name);
			strcat(dirs," ");
		}
	}
	return dirs;
}


char *getClass(DIR *folder,struct dirent *directorio,char *name_pack,char *suFiles)
{
	char *dirs = (char*)malloc(800);
	if(folder == NULL) { puts("Error aquí!\n"); return 0x00; }
	while((directorio = readdir(folder))){
		if(directorio->d_name[0] != '.' && post_point(directorio->d_name,suFiles)){
			strcat(dirs,"-C bin ");
			strcat(dirs,name_pack);
			strcat(dirs,directorio->d_name);
			strcat(dirs," ");
		}
	}
	return dirs;
}





char *getPack(Vector *package,char *name_pack,char *directory,char *folder,int index)
{
	char *name_pack_only = (char*)malloc(200);
	strcpy(name_pack_only,Vector_getValue(package,index));
	strcat(name_pack_only,"/");

	strcpy(name_pack,folder);
	strcat(name_pack,"/");
	strcat(name_pack,Vector_getValue(package,index));
	strcat(name_pack,"/");

	// access each packages
	strcpy(directory,"./");
	strcat(directory,folder);
	strcat(directory,"/");
	strcat(directory,Vector_getValue(package,index));

	return name_pack_only;
}

void build(int argc,char **argv)
{
	// open folder src
	char directory[200] = "./src/";
	DIR *folder;
	struct dirent *directorio;
	folder = opendir(directory);

	// get names packages
	char *packs = (char*)malloc(200);
	Vector *package = Vector_init(100);
	int i = 0;
	while((directorio = readdir(folder))){
		if(directorio->d_name[0] != '.'){
			strcpy(packs,directorio->d_name);
			Vector_pushback(package,packs);
			i++;
		}
	}
	// get all files of all packages
	char *name_pack = (char*)malloc(500);
	char *dirs = (char*)malloc(500);
	for(int i=0; i<package->size; ++i){
		getPack(package,name_pack,directory,"src",i);

		folder = opendir(directory);

		strcat(dirs,getFiles(folder,directorio,name_pack,".java"));
	}

	// compile from class
	char *javac = (char*)malloc(strlen(dirs)+50);
	strcpy(javac,"javac -d bin -sourcepath . ");
	strcat(javac,dirs);
	system(javac);

	// free memory
	Vector_destroy(package);
	free(packs);
	free(name_pack);
	free(dirs);
	free(javac);
	if(argc > 2 && strcmp(argv[2],"run") == 0)
		run();
}

void run()
{
	system("java -cp bin main.Main");
}



void export(int argc,char**argv)
{
	// open folder bin
	char directory[200] = "./bin/";
	DIR *folder;
	struct dirent *directorio;
	folder = opendir(directory);

	// get names packages
	char *packs = (char*)malloc(200);
	Vector *package = Vector_init(200);
	int i = 0;
	while((directorio = readdir(folder))){
		if(directorio->d_name[0] != '.'){
			strcpy(packs,directorio->d_name);
			Vector_pushback(package,packs);
			i++;
		}
	}
	// get all files of all packages
	char *name_pack = (char*)malloc(200);
	char *dirs = (char*)malloc(800);
	for(int i=0; i<package->size; ++i){
		char *name_pack_only = getPack(package,name_pack,directory,"bin",i);

		folder = opendir(directory);

		//printf("%s\n",name_pack_only);
		//printf("%s\n",directory);
		char *_class = (char*)malloc(800);
		_class = getClass(folder,directorio,name_pack_only,".class");
		strcat(dirs,_class);
		//printf("%s\n",dirs);
		free(_class);
	}
	
	// compile from class
	char *javac = (char*)malloc(strlen(dirs)+100);
	strcpy(javac,"jar cvfe export/program.jar main.Main ");
	strcat(javac,dirs);
	//printf("%s\n",javac);
	system(javac);

	// free memory
	Vector_destroy(package);
	free(packs);
	free(name_pack);
	free(dirs);
	free(javac);
	if(argc > 2 && strcmp(argv[2],"run") == 0)
		jar();
}


void jar()
{
	system("java -jar export/program.jar");
}

