# Modern CPP P5 - Files I/O Lab

It is required to read integer values from a file `input.txt` then write the sum, avg, min, and max of these values in tabular format into `output.txt` file.

## Example

Input file conatins values:

```txt
4
56
5462
498
43547
4
4
4054
1
```

Run the `files.cpp` file

```bash
g++ ./files.cpp -o ./files.exe; ./files.exe
```

The output file will be:

```txt
-------------------------------------------------------------------------
|       Sum       |       Avg       |       Min       |       Max       |
-------------------------------------------------------------------------
|      53630      |     5958.89     |        1        |      43547      |
-------------------------------------------------------------------------
```
