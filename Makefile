CC			:= gcc -std=c23 -Dlinux
CC_WIN			:= x86_64-w64-mingw32-gcc -std=c2x
CCFLAGS		:= -static
CFLAGS		:= -g -Wall -pedantic
FLAGS_W		:= -Wall -Wpedantic -Werror -Wextra
FLAGS		:= -Iinclude
SRC			:= src
SORCES		:= $(wildcard $(SRC)/*.c)
OBJ			:= obj
OBJS		:= $(addprefix $(OBJ)/,$(notdir $(SORCES:.c=.o)))
PROGRAM		:= bin/debug/sdk

OBJ_LINUX	:= obj_linux
OBJS_LINUX	:= $(addprefix $(OBJ_LINUX)/,$(notdir $(SORCES:.c=.o)))

PROJECT		:= Hispa-IDE-SDK-Java

programa: dirs $(PROGRAM)

$(PROGRAM): $(OBJ) $(OBJS) #ico
	$(CC_WIN) $(CCFLAGS) $(OBJS) icon.res -o $(PROGRAM)


linux_static: $(OBJ_LINUX) $(OBJS_LINUX)
	$(CC) -g $(CCFLAGS) $(OBJS_LINUX) -o $(PROGRAM)

linux_shared: $(OBJ_LINUX) $(OBJS_LINUX)
	$(CC) $(OBJS_LINUX) -o $(PROGRAM)

install:
	cp -v bin/debug/sdk /usr/bin

$(OBJ_LINUX)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $< -c -o $@ $(FLAGS)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC_WIN) $< -c -o $@ $(FLAGS)

ico: icon.rc
	windres icon.rc -O coff -o icon.res

clean_linux:
	rm $(OBJS_LINUX)
	rm $(PROGRAM)

clean:
	rm $(OBJS)

cleanall: clean
	rm $(PROGRAM).exe

dirs:
	mkdir -p obj obj_linux

push:
	git remote set-url origin \
		git@github.com-Feavr555:Feavr555/$(PROJECT).git
	git push -u origin main

pull:
	git pull origin main --rebase

