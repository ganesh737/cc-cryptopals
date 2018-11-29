# Using https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LINK_TARGET = build/cryptopals

OBJS =  \
 build/functions.o \
 build/s1.o \
 build/main.o

REBUILDABLES = $(OBJS) $(LINK_TARGET)

INCLUDES = -Iinc/ \
	-Isrc/


## Mail level rules
all: run runv runu
	echo All done

# Build and run the code for a problem statement
run: createBuildFolder $(LINK_TARGET) s1c1 s1c2 s1c3
	echo RUN done

# Build and run the code with valgrind for a problem statement
runv: createBuildFolder $(LINK_TARGET) s1c1v s1c2v s1c3v

# Build and run the unit test code for a problem statement
runu: createBuildFolder $(LINK_TARGET)
	echo UTEST done

# Create the local build folder
createBuildFolder:
	if [ ! -d $(PWD)/build ]; then mkdir $(PWD)/build; fi

# $@ expands to the rule's target, in this case "build/cryptopals".
# $^ expands to the rule's dependencies, in this case the three files
# main.o, functions.o, and s1.o.
$(LINK_TARGET) : $(OBJS)
	${CC} -g -o $@ $^

# $@ for the pattern-matched target
# $< for the pattern-matched dependency
# %.c refers to *.c
build/%.o : src/%.c
	${CC} ${CFLAGS} -g -o $@ -c $< ${INCLUDES}

# build/main.o :
# build/functions.o : inc/functions.h


## Individual problem run rules
# Set 1 Challenge 1
s1c1:
	./build/cryptopals -s1c1

# Set 1 Challenge 1 with valgrind
s1c1v:
	valgrind -v ./build/cryptopals -s1c1

# Set 1 Challenge 1 Unit Test
# s1c1u:

# Set 1 Challenge 2
s1c2:
	./build/cryptopals -s1c2

# Set 1 Challenge 2 with valgrind
s1c2v:
	valgrind -v ./build/cryptopals -s1c2

# Set 1 Challenge 3
s1c3:
	./build/cryptopals -s1c3

# Set 1 Challenge 3 with valgrind
s1c3v:
	valgrind -v ./build/cryptopals -s1c3


clean:
	rm -f $(REBUILDABLES)
	rm -rf build
	echo CLEAN done

.PHONY: all createBuildFolder run utest clean s1c1 s1c1v s1c2 s1c2v s1c3 s1c3v
