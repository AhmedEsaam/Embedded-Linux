# Make

## What is Make

**Make** is a build automation tool.

```shell
sudo apt-get install make
```

* We define instructions in the `makefile` by giving every instruction shell command(s).

* you will find it under `user/bin`

## Why we learn Make?

we'll use it in `yocto` and **Device Drivers**.

## How to use Make?

It parses input file: **Makefile**.

## How to write Makefile?

When you build normally a simple project consists of main.c, add.c, add.h

```shell
gcc -c main.c           # main.o
gcc -c add.c            # add.o
gcc main.o add.o        # out.o
```

### Makefile Syntax:-

```makefile
target:prerequisite
    recipe  # → any bash command. and you can write muliple lines in recipe
```

* Example:

```makefile
main.o:main.c
    gcc -c main.c

add.o:add.c
    gcc -c add.c

a.out:main.o add.o
    gcc main.o add.o

```

* To invoke this Makefile:

```shell
make
```

* **make** executes the first rule by default.

## Important points:-

### 1. Phony Target

Phony command which executes whether there is a file named 'clean' or not.

```makefile
.PHONY:clean
clean:
  rm add.o main.o a.out
```

### 2. Variables

#### 2.1 Variable Reference

* You can start a var with a number
* You can use any characters
* Example:

```makefile
var = ahmed

display:
    echo $(var) # variable reference
```

#### 2.2 Substitution Reference

```makefile
$(var: suffix = replacement)

obj=main.o
src = $(obj: .o=.c)

#or
$(var: pattern = replacement)

var2=main.o add.o
var2=$(var1: main.o = ahmed)
var2=$(var2: %.o = ahmed)
```

### 3. Automatic Variable

1. `$@` : the name of the target
2. `$^` : the name of the prerequisites [spaces]
3. `$<` : the name of the first prerequisite

* Example:

```makefile
App=iti
all = $(App)
$(App):main.o add.o
    gcc $^ -o $@
```

### 4. Pattern Rule

You can combine multiple rules in one rule if they have the same syntax.

```makefile
# more generic: 

%.o:%.c
        gcc -c $^

a.out:main.o add.o
        gcc main.o add.o
```

* Here, it compares `main.o` with `%.o` and sees if it matches.

### 5. Built-in Function

```makefile
$(FunNmae parameters)
```

### Most common functions:-

1. Wildcard Functions

You want to get all `.c` files and put them in var, but you can't put `var=*.c`

```makefile
var=$(wildcard *.c)
```

=>

```shell
var=main.c add.c
```

---

2. Substitute

```shell
$(Subset character, replacement, text)
```

```makefile
var=add1.o add2.o add3.o    # You can say Wildcard *.o
var2=$(subset add, mul, $(var))
```

3. Define a Function

```makefile
define print
        echo the first parameter is $1
        echo the second parameter is $2
endef

all: $(call print, Mohammed, 2)

```

```makefile
define Print
        @echo "the first parameter is $1"
        @echo "the second parameter is $2"
endef

x=Tera

all: 
        $(call Print, Mohammed, $(x))
        @echo "target is all" 
```

---

### Example 1

**Requirement**:

We need to write makefile that can compile my application to work either on my host machne or on Raspberry Bi

**Givens**:

The comiler for Rasp. is [ arm-linux-gnueabihf-gcc ]

and could be installed using "sudo apt install gcc-arm-linux-gnueabihf"

***Hint***: use variable reference.

**Solution**:

```makefile
compile=$COMP
.o:%.c
        $(compile) -c $^

a.out:main.o add.o
        $(compile) $^
```

---

```makefile
.o:%.c
        $$comp -c $^

a.out:main.o add.o
        $$comp $^
```

---

```makefile
cc=gcc
obj = main.o add.o
programType=host.elf

all : $(programType)

%.o : %.c
        $(cc) -c $<

$(programType) : $(obj)
        $(cc) $^ -o $(@)

.PHONY:clean
clean:
        @rm main.o add.o
        @rm $(programType)
```

* To check the type of the execuable file:
    file host.elf

---

```makefile
obj = main.o add.o
programType=host.elf

all : $(programType)

%.o : %.c
        $${cc} -c $<

$(programType) : $(obj)
        $${cc} $^ -o $(@)

.PHONY:clean
clean:
        @rm main.o add.o
        @rm $(programType)
```

---

### Example 2

To build application using `Includes` labraries directory.

```makefile
INC= -I ./Includes
src=$(wildcard *.c)
obj=$(src:.c=.o)

projectName=iti.elf


all: $(projectName)

%.o : %.c
        $(cc) $(INC) -c $<

$(projectName) : $(obj)
        $(cc) $(INC) $< -o $@

clean:
        rm *.o
        rm iti.elf

```

## Wildcards

1. \*
2. ?
3. [] or {}

* you can use wildcards in the rules and prerequistites.

## Implicit Instruction Calls

```makefile
INC= -I ./Includes
src=$(wildcard *.c)
obj=$(src:.c=.o)

projectName=iti.elf


all: $(projectName)

# %.o : %.c
#         $(cc) $(INC) -c $<

$(projectName) : $(obj)
        $(cc) $(INC) $< -o $@

clean:
        rm *.o
        rm iti.elf

```

* The file will still execute despite the absence of the previous command as it will implicitly call `gcc` using implicit rule.
* We can change this implicit compiler using by overwriting the environment var `CC`.
* What is`CFLAG` variable?

---
**Foot Notes**:

* If the makefile has crashed, use `rm .makefile.swp`
* You can run any file other than `makefile` using

```makefile
make -f makefile2
```
