# Linux Admin - Session 04 Notes

## User

When you create a new user, three files are affcted:

1. `/etc/passwd`
2. `/etc/shadow`
3. `/etc/group`

And it's created for him `.bashrc`, `.profile`, `.bash_history`, and `.bash_logout`.

* Use `sync` to synchronise openned terminals with the latest status.

---

## Permissions

When you type:

```bash
ls -lh
```

It will list files with its permissions.

![file permissions](<screenshots/Screenshot from 2024-07-10 17-36-31.png>)

The first character may be:

* `-`: regular file
* `b`: block device (sda)
* `c`: character device: series of buffer (tty)
* `n`: network device

Permissions are devided into `[owner] [group] [other]`

* **Owner of the file**: The one who created the file

* **Group of the file**: the primary group of the file

* **Other of the file**: any other user

When you touch a new file:

![alt text](<screenshots/Screenshot from 2024-07-10 17-39-17.png>)

---

### read permission `r: 4`

| For files | for directories |
| :--- | :--- |
| cat | ls |
| less ||
| head ||
| more ||
| tail ||
| vim ||
| bi ||
| nano ||

### write permission `w: 2`

| file | directory |
| :--- | :--- |
| vim | mkdir |
| rm | |
| echo | |

### executable permission `x: 1`

| file | directory |
| :--- | :--- |
| bash | cd |
| source | all commands inside this dir (touch a file inside this dir) |

When you create an executable file, you tell the **kernel** to treat this file as a process.

---

### Change Permissions

Permissions are appreviated as:

| u | g | o |
|:--:|:--:|:--:|
| owner | group | other |

To change permissions, there are two ways:

| octal | alphabetical |
| :---: | :---: |
| 605 | ugo=x |
| rw- --- r-x | ugo +x |
|| ug = rw |

To make a user [sherif] write on a file that he is not the owner [fady] of:

1. change the `other` permission of the file to be `rw-`

```shell
chmod +rw file
```

2. put this user in the primary group of the file owner

```shell
usermod -aG sherif fady
```

3. change the `group` permissions of the file.

```shell
chgrp HR file
```

4. change the `owner` of the file.

```shell
chown sherif files      # to change the owner of the file

chown :hr file          # to change group of the file

chown sherif:hr file    # to change owner and group at the same time
```

* **Note:** The `owner`, `sudoers`, and `root` can change permissions of the file without sudo.

---

## Special Permissions

1. **Set user id** `s: u+s (4---)` : gives **owner** privlege when executing a file which in return performs reading or writing on other files which requires owner permissions. (`s` : x, s) (`S`: s)

```bash
chmod 4777 myfile
```

2. **Set group id** `s: g+s (2---)`: inherit directory group permissions.

```bash
chmod 2777 myfile
```

3. **Sticky bit** `t: o+t (1---)`: When more than one user have the same owner:group permissions, only the owner of the file can delete his own file (and cannot delete others files).

```bash
chmod 1777 myfile
```

### Tips and Tricks

* To list group members

```bash
sudo groupmems -g hr -l

# if you want to run it as sudo from your non-sudoer user (set user id)
sudo chmod u+s /ur/sbin/groupmems
```

* To list group shadow file (that stores group passwords)

```bash
ls -lh /usr/sbin/groupmems
```

---

## Process

`PPID`: Parent Process id
`PID`: Process id

* All process running in RAM are under the filesystem `procfs`
* `/proc/`: (memics procfs) provides info about the process:

1. priority.
2. stack.
3. CPU architecture.
4. number of block storages that you can access ...

* To know how much space is occupied in the hard disk from a specific directory

```bash
sudo du -sh /proc/      # you will find it 0 as /proc is running on memory
```

* A **Process** can create a number of **threads** (every thread use a CPU **core**)

### Priorities

`-20` highest priority.

`20` lowest priority.

To force a certain priority number:

```bash
nice -n -5 ./script

nice -n -20 -p PID
```

* processes with the same priority are executed as First Come First Served FCFS

### Display Processes

* to get process id:

```bash
ps -aux     # all process running on the system

ps -at      # all processes created by the terminal

top         # real-time system monitor

pstree      # tree process (every process has a parent except the 'init' process)
```

* the `ps` command reads from the `/proc/`.

### Signals

```bash
kill -9 PID     # to kill a process

pkill script
```

* You can use `Ctrl+c` to force kill
* You can use `Ctrl+z` to halt process (freeze)

```bash
./script &      # to run in the background

fg ./script     # to make the process running in foreground

bg ./script     # to make thep rocess running in background
```

* To show all processses running in the background:

```bash
job
```

---

### Notes

* The **Kernel** runs with the **Non-Primitive** **round robin** (time slices) technique.

* How to make the Linux a real-time OS: by make it runs with **Primitive** priority technique. (But it's not determenistic nevertheless, so it's **not certified** as an RTOS).

### Architectures

**QNX**: A closed source runs with linux-based commands: [microservice] creates a **kernel** for every **process**.

**Linux is a Monolithic system**: Monolithic Architecture: all in one code, complex , not reusable.
