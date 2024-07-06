# Bash Script

To run the Bash script:

## Shebang

Start your code script with
**Shebang**:`#!/bin/bash` Tells the terminal that this is script is written in `bash`, so it must run using bash.

## Bash script environment variables

`$@`
`$#`
`$0`
...

## To Run the script

### 1. `./file.sh`

```bash
./file.sh               # user must have permission to execute
chmod +x ./file.sh      # give permission to execute
chmod -x ./file.sh      # to undo permissionrunrunningning
```

* if you did not use the **shebang**, it will use the current running shell.

* Other 3 ways to run the script do not require executable permission

### 2. `bash ./file.sh`

```bash
bash ./file.show      
```

* if you did not use the **shebang**, it will use `bash`.

### 3. `source ./file.sh` (not supported in `sh`, but supported in `bash`)

To run the script within the same bash process (no child craeted):

```bash
pstree -p               # show processes tree (-p to print processes id)
source ./file.show      
```

* This will allow you to use the variables created in this script

### 4. `. ./file.sh` (another way to run as source)

```bash
. ./file.sh
```

## Variables

* Variable name can't start with a number
* No spaces (ex. name = 5 => Error)
* To put a string, put "" or '' (ex. name= "ahmed essam")

### To access a variable

```bash
name2=$name
name2=${name}
```

### To append on avariable

```bash
name=ahmed
name3=${name}1
echo name3      # => ahmed3
```

### The difference between `""` and `''`

```bash
var=iti
var2="Hello $var"   
echo $var2      # => Hello iti

var3='Hello $var'
echo $var3      # => Hello $iti
```

### Take inputs

```bash
read -sp "Enter password" password      # -s to hide input password
echo $Password
```

### To store the output of the command into a var

`output=$(command)`

```Bash
output=$(date)
echo $output    # => Friday 15 December 2023 01:06:49 PM IST 
```

### Operations on variables

To treat var as integer:

```bash
var=5

# Using ((c-style syntax))
((var++))
var5=$((var++))

# Using expr
var2= expr $var + 1
var3= expr 2 + 2

# Using decalre
declare -i var4=5
var4=var4+1     # no spaces
```

---

## `test condiion`

### Conditions

There are 3 types of conditions:

#### 1. integers condition

* `-eq` : equal
* `-ne` : not equal
* `-gt` : greater than
* `-lt` : less than
* `-ge` : greater than or equal

```bash
1 -eq 1     #true
001 -eq 1   #true
```

#### 2. string condition

* `=`   : equal
* `!=`  : not equal
* `-z`  : zero characters
* `-n`  : non-zero characters

```bash
"ahmed"="mohammed"  #true
1=1                 # sees it as strings => true
001=1               #false
```

#### 3. file condition

* `-f` : file exists
* `-d` : directory exists
* `-x` : file is executable

```bash
-d /path/dir
-f /path/file
```

#### `test` Syntax

* `0` is equib=valent to true in bash script
* `$?` stores the return status of the last command

```bash
test 1 -eq 1    # returns 0
echo $?         # returns 0
```

Or:

```bash
[ 1 -eq 1 ]
echo $?
```

---

### Logical Operators

* and: `&&` , `-a`
* or: `||` , `-o`

#### Syntax

* Syntax 1: `( condition1 ) && ( condition2 ) ...`
* Syntax 2: `(( condition1 && condition2 ...))`
* Syntax 3: `( condition1 &&,-a condition2 ...)`

#### Syntax using `test`

```bash
test 1 -eq 1 && test 10 -eq 8
test 1 -eq 1 -a 10 -eq 8
```

---

## If Conditions

### If then fi

```bash
if [condition]
then
    echo "hello iti"
fi
```

```bash
if [condition]; then
    echo "hello iti"
fi
```

### If else

```bash
if [ condition ]
then
    echo "true"
else
    echo "false"
fi
```

### If elif

```bash
if [ condition ]; then
    echo "A"
elif [ condiion ]; then
    echo "B"
else
    echo "C"
fi
```

---

## Loops

### For loop

```bash
for var in 1 2 3    # list 
do
    echo $var
done
```

```bash
for var in {1..9}
do
    echo $var
done
```

#### * Example1

```bash
str="Medhat Mohamed Ahmed"
for var in $str
do
    echo $var
done
```

Output:

```bash
Medhat
Mohamed
Ahmed
```

#### * Example2

```bash
str="Medhat Mohamed Ahmed"
for var in "$str"   # it will consider that as one element (one string)
do
    echo $var
done
```

Output:

```bash
Medhat Mohamed Ahmed
```

#### * Example3

```bash
str="Medhat" "Mohamed" "Ahmed"
for var in $str
do
    echo $var
done
```

Output:

```bash
Medhat
Mohamed
Ahmed
```

### While loop

```bash
x=0
y=3

while [[ $x -le 6 && $y -ge 0 ]]; do
echo "x= $x"
echo "y= $y"
((x++))
((y--))
# break
done
```

### Until

```bash
until [ 1 -eq 1 ]; do
    echo "hello"
    # break
done
```

**Note**: to decalre an integer explicitly:

```bash
declare -i c=2
```

---

## Arrays

There are two types of arrays:

### 1. Index Array

#### Declare Using Implicit Declaration

```bash
var=5
((var++))
```

```bash
fruits=("apple" "banana" "cherry")      # the bash recognises that it's an index array
echo ${fruits[0]}   # you can't use $fruits[0]
```

```bash
fruits[3]="melon"
fruits[10]="melon"  # uninitialized elements will be empty
echo ${fruits[7]}   # => prints nothing
```

#### Print Array Elements

```bash
fruits=("apple" "banana" "cherry")

echo ${fruits[@]}   # apple banana cherry   # @: stands for 'anything'
echo ${fruits[*]}   # apple banana cherry
```

The behaviour of `[@]` differs from `[*]` when putting qutation marks `""`  

```bash
echo "${fruits[@]}" # "apple" "banana" "cherry"
echo "${fruits[*]}" # "apple banana cherry"

# [@] is better with for loops as it will consider every element
for var in "${fruits[@]}"; do
    echo $var
done
```

`"${fruits[@]}"` considers every element,

while `"${fruits[*]}"` considers the array as one unit.

##### Example1

```bash
cities=("New York" "Los Angeles" "Cairo")
for city in ${cities[@]}    # ${cities[@]} this gives: new York Los Angeles Cairo  
do
    echo $city
done
```

Output:

```bash
New
York
Los
Angeles
Cairo
```

##### Example2

```bash
cities=("New York" "Los Angeles" "Cairo")
for city in "${cities[@]}"      # "${cities[@]}" this gives: "new" "York" "Los" "Angeles" "Cairo"
do
    echo $city
done
```

Output:

```bash
New York
Los Angeles
Cairo
```

#### Print Array Length

```bash
echo ${#fruits[@]}
echo ${#fruits[*]}
```

#### Print Array Slice

`{fruits[@]:start index:number of elements}`

```bash
echo ${fruits[@]:1:2}
```

#### Print Array Indexes

```bash
fruits=("apple" "banana" "cherry")

for index in ${!fruits[@]}
do
    echo "$index, element ${fruits[$index]}"
done
```

Output

```bash:
0, element apple
1, element banana
2, element cherry
```

---

### 2. Associated Array

#### Declare Using Explicit Declaration

```bash
declare -i var=5
$var=$var+5
```

* You cannot define associated array other than by explicit declaration

```bash
#declare array
declare -A fruits=([apple]="red" [banana]="yellow")       #declare associated array

declare -A fruits2
fuits2[apple]="red"
fuits2[banana]="yellow"
```

#### Print Associated Array Elements

```bash
declare -A fruits=([apple]="red" [banana]="yellow")
echo ${fruits[apple]}   # red
echo ${fruits[@]}       # red yellow (not necessarily in the same order)
```

#### Print Array Keys

```bash
declare -A fruits=([apple]="red" [banana]="yellow")

for key in ${!fruits[@]}
do
    echo key
done
```

```bash
declare -A fruits=([apple]="red" [banana]="yellow")

for key in ${!fruits[@]}
do
    echo "key is $key, value is ${fruits[$key]}"
done
```

---

### To remove array

```bash
fruits=("apple" "banana" "melon")
unset fruits[1]         # removes "banana"
echo ${fruits[1]}       # prints nothing => as it will not shift elements
```

---

## Case

```bash
read -p "are you sure? " var

case $var in
yes|y|Yes|YES)
    echo $var
    ;;              # break
no|n|No|NO)
    echo $var
    ;;
*)
    echo "invalid"
    ;;
esac
```

---

## Select

```bash
select var in "date" "ls" "exit"
do
    $var        # runs selected command
    # break
done
```
