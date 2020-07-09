EXEC = bots 
FILES = bots.cpp bots.h  

LFLAGS = -g++ 
CFLAGS = -g++ -c
 
OBJECTS = $(FILES:.c=.o)
 
$(EXEC):$(OBJECTS) 
	$(LFLAGS) -o $(EXEC) $(OBJECTS) -lpthread
	rm -f *.o
 
c.o: 
	$(CC) $(CFLAGS) $<
 
clean: 
	rm -f *.o $(EXEC)
