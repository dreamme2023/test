COMPILER = gcc
CFLAGS   = -O2 -fPIC -Wall -Werror -Wextra
LDFLAGS  = -shared

LIBNAME  = matrix
LIBSRCS  = src/matrix.c
LIBOBJS  = $(LIBSRCS:.c=.o)

all: lib$(LIBNAME).so

main: main.c | lib$(LIBNAME).so
	mkdir -p bin
	$(COMPILER) $(CFLAGS) -Iinclude -o bin/$@ $< -Llib -l$(LIBNAME)

lib$(LIBNAME).so: $(LIBOBJS)
	mkdir -p lib
	$(COMPILER) $(LDFLAGS) -o lib/$@ $^

%.o: %.c
	$(COMPILER) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	rm -f $(LIBOBJS)
	rm -rf bin
	rm -rf lib

.PHONY: all clean lib$(LIBNAME).so