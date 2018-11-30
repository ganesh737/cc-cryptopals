# cryptopals

Contains my solutions to problems from the website [Cryptopals](http://cryptopals.com).

## Structure of the code base
* problem_statements
    * The problem statements from when I started coding are available in docs.
    * The little script(refreshProblemStatements.sh) should be able to refresh the problem statements in case of updates.

* inc
    * This folder contains all the declarations for functions.
    * This is an attempt to have common functions across problem statements.

* src
    * This folder contains all the implementations for the functions.
    * The main.c file calls the functions. It mainly handles all the input parameters for each problem statement.

* inputs
    * This folder contains any inputs needed for any problems.

* build
    * This folder is generated and contains all the object files and executable.

* utest
    * This folder contains all the unit tests for the functions using [Unity Test Framework](https://www.throwtheswitch.org/unity).

Kindly use the Makefile for any changes to build process or adding source files.


## Static Checks, Runtime Checks and Profiling the Code
* Static code checks are performed with `-Wall -Wextra -Werror`
* Runtime checks are done with [Valgrind](http://valgrind.org/)
* Profiling is done with gprof and time
    * gprof
        ```gcc -pg test.c -o test
        ./test
        gprof test
        ```
    * time
        ```
        time ./test
        ```

## References
* Makefiles
    * [GCC and Make: Compiling, Linking and Building C/C++ Applications](https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html)
    * [Using make and writing Makefiles](https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html)

