CC = g++
TARGET = query
SOURCE = src/Server.cpp
BINDIR = $(PREFIX)/bin

all = $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET)

install:
	install -m 755 $(TARGET) $(BINDIR)

clean:
	rm -f $(TARGET)

.PHONY: all clean install

