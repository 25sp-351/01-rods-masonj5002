# Tests - rodcut
Use `make` to build

## Test 1
### Input
./rodcut 99
12, 13

14, 17

22, 29

41, 23

### Expected Output
Cut List:

1 @ 12 = 13

1 @ 14 = 17

1 @ 22 = 29

1 @ 41 = 23

1 @ 1 = 2

Remainder: 9

Value: 84
## Test 2
### Input
./rodcut 99
10, 5

10, 87

10, 32

10, 33

10, 51

10, 99

10, 81

10, 7

10, 2

9, 8

### Expected Output
Cutlist:
1 @ 10 = 5

1 @ 10 = 5

1 @ 10 = 5

1 @ 10 = 5

1 @ 10 = 5

1 @ 10 = 5

1 @ 10 = 5

1 @ 10 = 5

1 @ 10 = 5

1 @ 9 = 8
## Test 3
### Input
./rodcut 5
3, 2

2, 4

2, 1

### Expected Output
The cut is too long for rod. Program will exit.
## Test 4
### Input
./rodcut
### Expected Output
USAGE: rod_length < int >