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

### 2. source `./file.sh`

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

### The difference between "" and ''

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

There are 3 types of conditions

### 1. integers condition

* `-eq` : equal
* `-ne` : not equal
* `-gt` : greater than
* `-lt` : less than
* `-ge` : greater than or equal

```bash
1 -eq 1     #true
001 -eq 1   #true
```

### 2. string condition

* `=`   : equal
* `!=`  : not equal
* `-z`  : zero characters
* `-n`  : non-zero characters

```bash
"ahmed"="mohammed"  #true
1=1                 # sees it as strings => true
001=1               #false
```

### 3. file condition

* `-f` : file exists
* `-d` : directory exists
* `-x` : file is executable

```bash
-d /path/dir
-f /path/file
```

### Example

The syntax is: `tset[space][exp][space][condition][space][exp]`

* 0 is equib=valent to true in bash script
* `$?` stores the return status of the last command

```bash
test 1 -q 1     # returns 0
echo $?
```
