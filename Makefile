# Nom
EXEC = act4

# Arxius
SRC = act4.c

# Compilador
CC = gcc


CFLAGS = -Wall -g

$(EXEC): $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(SRC)

# execució
run: $(EXEC)
	./$(EXEC) 10 10 100  # valor predeterminats

# neteja arxius generats
clean:
	rm -f $(EXEC)

# neteja arxius temporals
distclean: clean
	rm -f *~ *.o
