# compiler variables
CC = gcc
CFLAGS = -Wall -Wextra

#executable
EXE1 = multi_thread_increment
EXE2 = multi_thread_increment_mutex

#find source
SRC1 = multi_thread_increment.c function.c
SRC2 = multi_thread_increment_mutex.c function.c

all: $(EXE1) $(EXE2)

$(EXE1): $(SRC1)
		$(CC) $(CFLAGS) -o $(EXE1) $(SRC1)

$(EXE2): $(SRC2)
		$(CC) $(CFLAGS) -o $(EXE2) $(SRC2)

clean: 
		rm -f $(EXE1) $(EXE2)