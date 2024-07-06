# Bash Script

To run the Bash script:

## To Run the script

### 1. `./file.sh`

```bash
./file.sh               # user must have permission to execute
chmod +x ./file.sh      # give permission to execute
chmod -x ./file.sh      # to undo permission
```

* Other 3 ways to run the script do not require executable permission

### 2. `source ./file.sh`

To run the script within the same bash process (no child craeted):

```bash
pstree -p               # show processes tree (-p to print processes id)
source ./file.show      
```

* This will allow you to use the variables created in this script

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

#### `test` Syntax:

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

Syntax:

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

#### Implicit Declaration

```bash
fruits=("apple" "banana" "cherry")
echo ${fruits[0]}   # you can't use $fruits[0]
```

```bash
fruits[3]="melon"
fruits[10]="melon"  # uninitialized elements will be empty
echo ${fruits[7]}   # => prints nothing
```

### 2. Associated Array

### Print Array Elements

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

### Print Array Length

```bash
echo ${#fruits[@]}
echo ${#fruits[*]}
```

### Print Array Slice

`{fruits[@]:start index:number of elements}`

```bash
echo ${fruits[@]:1:2}
```

### Print Array Indexes

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
