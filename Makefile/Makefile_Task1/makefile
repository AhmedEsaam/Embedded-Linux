# Initializing variables essesntial to the build process 
CC = gcc
INCS = -I ./include
projectName = ./bin/game.exe

# Defining the source files needed and the target object files required
src = $(wildcard ./src/*.c)
obj = $(foreach src_file, $(src), $(patsubst ./src%.c, ./build%.o, $(src_file)))

# Or, we can just use:
# obj = $(patsubst ./src/%.c, ./build/%.o, $(src))


# Target file
all: $(projectName)


# Creating object files
./build/%.o: ./src/%.c
# Creating the ./build directory if not exists (by creating the dir that this rule target resides in)
	@mkdir -p $(@D)		
# Recipe for building the target via CC and INCS
	@${CC} ${INCS} -c ./$< -o ./$@


# Creating the target executable file
$(projectName): $(obj)
# Creating the ./bin directory if not exists
	@mkdir -p $(@D)
# Recipe for building the target via CC and INCS
	@${CC} ${INCS} ./$^ -o ./$@


# Clean the object and executable files
.PHONY:clean
clean:
	@rm $(obj) $(projectName)
	