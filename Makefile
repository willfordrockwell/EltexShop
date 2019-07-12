CFLAGS = -lpthread
CC = gcc
SOURCES = Shop.c
SOURCES += Buyer_Thread.c
SOURCES += Loader_Thread.c
SOURCES += Shopping.c
SOURCES += Loading.c
OBJECTS = $(SOURCES:.c=.o)
EXECUTABLE = Shop

all: $(EXECUTABLE)

debug: clean
debug: CFLAGS += -g
debug: all

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE).elf $(CFLAGS)

$(OBJECTS): $(SOURCES)
	$(CC) $(SOURCES) -c $(CFLAGS)

.PHONY: clean
clean:
	rm *.elf *.o
