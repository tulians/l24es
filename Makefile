# Definition of directories' variables.
SDIR = ./src
IDIR = ./inc
ODIR = ./obj
LDIR = ./lib
BDIR = ./bin

# C compiler macros.
CC = gcc
CFLAGS = -I$(IDIR)

_DEPS = matrix.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = matrix.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(OBJ): $(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rules.
matrix: $(OBJ)
	gcc -o $(BDIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

all:
	$(MAKE) clean
	$(MAKE) matrix
	echo "Project compiled successfully."
