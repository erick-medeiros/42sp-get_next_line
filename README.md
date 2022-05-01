# get_next_line
This project is about programming a function that returns a line read from a file descriptor

## Final Score

<img height=150px src=https://github.com/erick-medeiros/guide42/blob/main/grade/grade_125_100.png alt="eandre-f score"/>

## The Project

- Your function should return the line that was read.
If there is nothing else to read or if an error occurred, it should return NULL. 

- Please note that the returned line should include the terminating \n character,
except if the end of file was reached and does not end with a \n character.

- Because you will have to read files in get_next_line(), add this option to your
compiler call: -D BUFFER_SIZE=n
It will define the buffer size for read().

### Mandatory

Works with a single file descriptor at a time

#### Tests

```
make m
```

### Bonus

Works with multiple file descriptor at a time

#### Tests

```
make b
```