# Toggle Capslock Brightness

It is required to toggle the Capslock Key Brightness.

* The first file `readCapslock.c` reads the Capslock Brightness from its dedicated file in the `/sys/` directory and print it and store it in the file `./output`

* The second file `toggleCapslock.c` reads Capslock Brightness and toggle it.

## Decide whether to use piping

To use piping, first, set the `USE_PIPING` macro to 1 in `toggleCapslock.c`. This will read the output of `./readCapslock` using **piping**.

```c
#define USE_PIPING 1
```

To read the brightness status from the file `./output`, unset the `USE_PIPING` macro to 0 in `toggleCapslock.c`. This will read from the file `./output`

```c
#define USE_PIPING 0
```

## Build the files

```bash
gcc ./readCapslock.c -o readCapslock;

gcc ./toggleCapslock.c -o toggleCapslock
```

## Run Using Piping

```bash
readCapslock | toggleCapslock
```

## Run Without Using Piping

```bash
readCapslock; toggleCapslock
```
