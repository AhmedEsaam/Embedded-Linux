CC = gcc
INCS = -I ./include
projectName = ./bin/game.exe

src = $(wildcard ./src/*.c)
obj = $(foreach src_file, $(src), $(patsubst ./src%.c, ./build%.o, $(src_file)))

# Or, we can just use:
# obj = $(patsubst ./src/%.c, ./build/%.o, $(src))

all: $(projectName)

./build/%.o: ./src/%.c
	@${CC} ${INCS} -c ./$< -o ./$@

$(projectName): $(obj)
	@${CC} ${INCS} ./$^ -o ./$@

show:

.PHONY:clean
clean:
	@rm $(obj) $(projectName)
	