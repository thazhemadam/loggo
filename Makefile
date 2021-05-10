CC=g++

IDIR =include
SRC=src
ODIR=bin

CFLAGS=-I $(IDIR) -DGEOMETRY

# enter names of header files defined in `include/` here
_DEPS = logga.h observer.h subject.h concretes/observer.h concretes/subject.h change_manager.h concretes/dual.h examples/geometry.h examples/library.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# enter `path/to/file.o` for each file defined in `src/` here
_OBJ = subject.o concretes/observer.o concretes/subject.o change_manager.o client.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# generate object files for all source files, following the same directory structure
$(ODIR)/%.o: $(SRC)/%.cpp $(DEPS)
	mkdir -p $(@D)
	$(CC) -c -o $@ $< $(CFLAGS)

# final executable image
loggo : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -rf $(ODIR) loggo
