CC = g++

CFLAGS = -Wall -Werror -ggdb -g

SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

SRCDIR = src
OBJDIR = obj

EXECUTABLE=generate_dungeon

all: prereq $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ -lncurses $^

$(OBJECTS) : $(OBJDIR)/%.o : $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) -o $@ -c $^

prereq:
	mkdir -p $(OBJDIR)
	mkdir -p $(SRCDIR)

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
