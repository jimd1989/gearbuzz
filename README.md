Implementation of the famous [fizzbuzz](https://en.wikipedia.org/wiki/FizzBuzz) exercise bereft of both modulos and conditional statements.
 
## Data structure

My weird little fizzbuzz hinges upon a struct `circle`, which is a linked list an arbitrary number of cells in length. The final cell points back to the first, meaning it can be iterated through forever. Every cell contains an int valued at 1, except for the final cell, which is 0. So 10 iterations through a circle 3 items long would return:

    1, 1, 0, 1, 1, 0, 1, 1, 0, 1

The circle also contains an array of strings called `messages`, two items long. `messages[0]` contains a custom message (like "fizz") and `messages[1]` is blank. Those same 10 iterations, now printing back `circle.messages[circle.head]`, looks like:

    "", "", "fizz", "", "", "fizz", "", "", "fizz", ""

It should be clear where I'm going with this by now.

## Main loop

The top-level loop tracks a variable `n`, which iterates from 1 to 100. There is another two-string array `output`. `output[0]` is blank. `output[1]` contains the string equivalent of `n`'s current value. The array `circles` contains any number of heterogeneously-sized circles. In every cycle of the loop:

+ `n` is copied to `output[1]` with `snprintf`.
+ An integer `fizzed` is set to 1.
+ A sub-loop that iterates through every circle begins.
    + `fizzed` is multiplied against the value of the circle's current head.
    + The circle's `messages[circle.head]` value is printed: either the custom message or the blank string.
    + The circle's head is set to its next cell.
+ `output[fizzed]` is printed. If there were no circles with a custom message (cell value 0), then `fizzed` should still be 1 and the literal value of `n` is printed. If `fizzed` was multiplied against any 0, then the output will be blank.

This gear-like arrangement gives the canonical fizzbuzz without ever once throwing an `if`. It's trivial to add new conditions too, since the fizzing, buzzing, etc cycles are constrained within their own data structures. The example code contains 4 such structs.

In action, they produce:

    1
    2
    fizz
    4
    buzz
    fizz
    bang
    8
    fizz
    buzz
    boop
    fizz
    13
    bang
    fizzbuzz
    16
    17
    fizz
    19
    buzz
    fizzbang
    boop
    23
    fizz
    buzz
    26
    fizz
    bang
    29
    fizzbuzz
    31
    32
    fizzboop
    34
    buzzbang
    fizz
    37
    38
    fizz
    buzz
    41
    fizzbang
    43
    boop
    fizzbuzz
    46
    47
    fizz
    bang
    buzz
    fizz
    52
    53
    fizz
    buzzboop
    bang
    fizz
    58
    59
    fizzbuzz
    61
    62
    fizzbang
    64
    buzz
    fizzboop
    67
    68
    fizz
    buzzbang
    71
    fizz
    73
    74
    fizzbuzz
    76
    bangboop
    fizz
    79
    buzz
    fizz
    82
    83
    fizzbang
    buzz
    86
    fizz
    boop
    89
    fizzbuzz
    bang
    92
    fizz
    94
    buzz
    fizz
    97
    bang
    fizzboop
    buzz

