VERSION = 1.0.0
CC = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c2x -g
RM = rm

BIN = smpg

.PHONY: all clean dist self

BDIR = bin
ODIR = obj
SDIR = src
DDIR = doc

SRCS = $(wildcard $(SDIR)/*.c)
OBJS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

# Building -------------------------------------

all: $(BIN)

$(BIN): $(BDIR) $(ODIR) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(BDIR)/$@

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BDIR):
	 mkdir $@
$(ODIR):
	 mkdir $@

# Distribution ---------------------------------

dist: clean
dist: all
dist: $(DDIR)/$(BIN).7
	gzip -vk $<
	tar -czvf $(BIN)-$(VERSION).tar.gz $(BDIR)/$(BIN) $(DDIR)/* ../README.md ../LICENSE --transform 's,^,$(BIN)-$(VERSION)/,'
	md5sum $(BIN)-$(VERSION).tar.gz

self: clean
self: all
self: $(DDIR)/$(BIN).7
	gzip -vk $<
	sudo mkdir /usr/local/man/man7/ -p
	sudo mv $(BDIR)/$(BIN) /usr/local/bin
	sudo mv $(DDIR)/$(BIN).7.gz /usr/local/man/man7/
	sudo mandb -q

# Other ----------------------------------------

clean:
	$(RM) -f $(BDIR)/* $(ODIR)/*

