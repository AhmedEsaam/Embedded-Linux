# Bash Script

To run the Bash script:

```bash
./file.sh               # user must have permission to execute
chmod +x ./file.sh      # give permission to execute
chmod -x ./file.sh      # to undo permission
```

```bash
pstree -p               # show processes tree (-p to print processes id)

bash 
```

* Other 3 ways to run the script do not require executable permission

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
