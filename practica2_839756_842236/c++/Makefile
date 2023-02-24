# Object files to either reference or create
OBJECTS = instruccion.o instruccionAdd.o instruccionDup.o instruccionJumpif.o instruccionPush.o instruccionRead.o instruccionWrite.o instruccionMul.o instruccionOver.o instruccionSwap.o programaSuma.o programaCuentaAtras.o programaFactorial.o main.o
# The executable file that will be created at the end
EXEC = main
# The flags to use for compilation
FLAGS = -Wall
# The code compiler to use for compilation
CC = g++

# Perform action on all object files (May or may not exist)
all: $(OBJECTS)
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)

clean:
	rm -f $(EXEC) *.o
