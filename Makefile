#define dir for source files
SRC_DIR = ./src

#define dir for target *.o files, etc
OBJ_DIR = ./bin

#define any directories containing header files other than /usr/include
INCLUDES = -I ./inc

#define libraries to be included
#LIBS = -lstdc++

#define the C compiler to use
CC = g++

#define any compile-time flags
CFLAGS = -Wall -Werror -g

# define prerequisites (source files)
SOURCES =       $(SRC_DIR)/ChessPlay.cpp\
					$(SRC_DIR)/ChessBoardPosition.cpp

SRCS = $(notdir $(SOURCES))

# define the executable file 
MAIN = PlayKnight

OBJS = $(patsubst %.cpp,$(OBJ_DIR)/%.o, $(filter %.cpp, $(SRCS)))

all:    $(MAIN)

$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(LIBS) -o $(MAIN) $(OBJS) $(LFLAGS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

