# Definition of directories' variables.
SDIR = ./src
IDIR = ./inc
ODIR = ./obj
LDIR = ./lib
BDIR = ./bin

# C compiler macros.
CC = gcc
CFLAGS = -I$(IDIR)

# Get all files in inc/ directory.
DEPS = $(wildcard $(IDIR)/*.h)

# Generate object files' names.
_OBJ = $(wildcard $(ODIR)/*.o)
_OBJ += $(patsubst $(IDIR)/%.h,$(ODIR)/%.o,$(DEPS))
OBJ = $(sort $(_OBJ))

$(ODIR)/%.o: $(SDIR)/%.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

# Rules.
l24es: $(OBJ)
	gcc -o $(BDIR)/$@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~
	rm -f $(BDIR)/*

all:
	$(MAKE) clean
	$(MAKE) l24es
