CC			:= gcc
CCFLAGS		:= -static
CFLAGS		:= -g -Wall -pedantic
FLAGS		:= -Iinclude
SRC			:= src
SORCES		:= $(wildcard $(SRC)/*.c)
OBJ			:= obj
OBJS		:= $(addprefix $(OBJ)/,$(notdir $(SORCES:.c=.o)))
PROGRAM		:= bin/debug/sdk

programa: $(PROGRAM)

$(PROGRAM): $(OBJ) $(OBJS) ico
	$(CC) $(CCFLAGS) $(OBJS) icon.res -o $(PROGRAM)

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $< -c -o $@ $(FLAGS) $(CFLAGS)

ico: icon.rc
	windres icon.rc -O coff -o icon.res

clean:
	rm $(OBJS)

cleanall: clean
	rm $(PROGRAM).exe