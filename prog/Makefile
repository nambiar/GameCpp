# #OBJS specifies which files to compile as part of the project
# OBJS = ConstructScreen.cpp EventsHandling.cpp test.cpp 

# #OBJ_NAME specifies the name of our exectuable
# OBJ_NAME = SDLMain

# #This is the target that compiles our executable
# all : $(OBJS)
# 	g++ $(OBJS) -g -IC:\Users\600013785\Documents\Projects\game\SDL2-2.0.10\i686-w64-mingw32\include -LC:\Users\600013785\Documents\Projects\game\SDL2-2.0.10\i686-w64-mingw32\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2Main -lSDL2 -o $(OBJ_NAME)

#OBJS specifies which files to compile as part of the project
OBJS = ConstructScreen.cpp EventsHandling.cpp test.cpp

#CC specifies which compiler we're using
CC = g++

#COMPILER_FLAGS specifies the additional compilation options we're using
# -w suppresses all warnings
COMPILER_FLAGS = -w

#LINKER_FLAGS specifies the libraries we're linking against
LINKER_FLAGS = -lSDL2

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = 01_hello_SDL

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)