# Object files to either reference or create                          
OBJECTS = instruccionAdd.o instruccionRead.o instruccionWrite.o programaSuma.o main.o
# The executable file that will be created at the end                 
EXEC = main                                                     
# The flags to use for compilation                                    
FLAGS = -Wall                                                         
# The code compiler to use for compilation                            
CC = g++                                                              

# Perform action on all object files (May or may not exist)           
all: $(OBJECTS)                                                   
	$(CC) $(FLAGS) -o $(EXEC) $(OBJECTS)
