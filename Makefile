INC = -Iinclude

SRC = src
OBJ = obj
INCLUDE = include

CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
FSANITIZER = -fsanitize=address

vpath %.cpp $(SRC)
vpath %.h $(INCLUDE)

MAKE = $(CC) $(INC) 

OS_OBJ = $(addprefix $(OBJ)/, logger.o node.o strategy.o preprocessor.o tree.o dataframe.o file_parser.o main.o)
HEADER = $(wildcard $(INCLUDE)/*.h)

all: os

os: $(OS_OBJ)
	$(MAKE) $(LFLAGS) $(OS_OBJ) -o main.exe $(LIB)

$(OBJ)/%.o: %.cpp ${HEADER} $(OBJ)
	$(MAKE) $(CFLAGS) $< -o $@

# Prepare objectives container
$(OBJ):
	mkdir -p $(OBJ)

clean:
	rm -f $(OBJ)/*.o main
	rm -r $(OBJ)

