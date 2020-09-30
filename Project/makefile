# project directories
IDIR = include
SDIR = src
ODIR = obj

# compiler specs
CC = gcc
CFLAGS = -I $(IDIR) 

# executable name
EXECUTABLE = executable/project-organizer

# libraries
LIBS = -lncurses


_DEPS= Exceptions.h Label.h Project.h Task.h TaskList.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))


_OBJ = Label.o main.o Project.o Task.o TaskList.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)


$(EXECUTABLE): $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
