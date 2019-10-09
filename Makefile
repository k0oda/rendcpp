.PHONY: all clean install uninstall

CC = g++

SRCDIR = src
BUILDDIR = build
TARGET = bin/boxmover
INSTALLATION_DIR = /usr/local/bin
LIB_DIR = lib/

SRCEXT = cpp
SOURCES = $(wildcard $(SRCDIR)/*.$(SRCEXT))
OBJECTS = $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))

RM = rm -rf

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@echo "Linking..."
	$(CC) -o $(TARGET) $(OBJECTS)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@echo "Compiling $@:"
	@mkdir -p $(BUILDDIR)
	$(CC) -c -I $(LIB_DIR) -o $@ $<

install:
	@echo "Installing..."
	install $(TARGET) $(INSTALLATION_DIR)

uninstall:
	@echo "Uninstalling..."
	$(RM) $(INSTALLATION_DIR)/$(TARGET)

clean:
	@echo "Cleaning..."
	$(RM) $(BUILDDIR) $(TARGET)
