COMPILER		= javac
EXECUTE			= java
FLAGSC			= -d bin
FLAGSE			= -cp bin
EXPORT			= jar cvfe
EXECUTEJAR		= java -jar
MAIN			= main.Main
MAINFREE		= Main

CARPETA			= sur export
PROGRAM			= export/program.jar
SRC			= $(wildcard src/*/*.java)
SOURCE			= -sourcepath . $(SRC)

CLASS			= $(wildcard src/*.java)

OBJECTS			= $(foreach classfile,$(wildcard bin/*/*.class),-C bin $(classfile:bin/%=%))

FREEOBJECTS		= $(foreach classfile,$(wildcard bin/*.class),-C bin $(classfile:bin/%=%))

execute: class
	$(EXECUTE) $(FLAGSE) $(MAIN)

class: $(SRC)
	$(COMPILER) $(FLAGSC) $(SOURCE)

export: class
	$(CARPETA)
	$(EXPORT) $(PROGRAM) $(MAIN) $(OBJECTS)

jar: export
	$(EXECUTEJAR) $(PROGRAM)

filesclass: freeclass
	$(EXECUTE) $(FLAGSE) $(MAINFREE)

freeclass: $(CLASS)
	$(COMPILER) $(FLAGSC) $(CLASS)

freeexport: freeclass
	$(EXPORT) $(PROGRAM) $(MAINFREE) $(FREEOBJECTS)

freejar: freeexport
	$(EXECUTEJAR) $(PROGRAM)
