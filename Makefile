EXE = targa_test
GCC = gcc
SRC = targa.c targa_test.c
FLAGS = -Wall
AR = ar
OBJ_OUT = targa_lib.o
LIB = libtarga.a
LIB_SRC = targa.c
LIB_FLAGS = rcs

all: test

obj:
	$(GCC) -c $(LIB_SRC) -o $(OBJ_OUT)

lib: obj
	$(AR) $(LIB_FLAGS) $(LIB) $(OBJ_OUT) 

test: lib
	$(GCC) $(FLAGS) -L. -ltarga $(SRC) -o $(EXE)




clean:
	rm *~ *.o *.a $(EXE)