CC = g++
TARGET = query
SOURCE = src/Server.cpp
BINDIR = $(PREFIX)/bin
BUILDDIR = ./build

all = $(TARGET)

$(TARGET): $(SOURCE)
	$(CC) $(SOURCE) -o $(TARGET)

install:
	install -m 755 $(TARGET) $(BINDIR)

build:
	mkdir -p $(BUILDDIR)
	$(CC) $(SOURCE) -o $(BUILDDIR)/$(TARGET)

clean:
	rm -rf $(TARGET) $(BUILDDIR)

.PHONY: all clean install

