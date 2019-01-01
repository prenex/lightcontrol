#!/bin/make

OBJDIR=obj
OBJCPPSUBDIR=cpp
SRCDIR=src

ifdef THREADS
	PTHREAD=-D WAFER_THREADS=$(THREADS) -pthread
endif

ifdef DEBUG
	ifeq ($(DEBUG),0) 
		DEBUG_OPT=-ggdb
	else
		DEBUG_OPT=-D WAFER_DEBUG -ggdb
	endif
endif

ifdef PROCESSES
	PROCESSES_OPT=-D WAFER_PROCESSES=$(PROCESSES) -ggdb
endif

ifdef LOOP
	ifeq ($(LOOP),epoll) 
		LOOP_OPT=-D WAFER_EPOLL
	endif	
endif

ifdef MAX_CON_CONS
	MAX_CON_CONS_OPT=-D WAFER_MAX_CON_CONS=$(MAX_CON_CONS)
endif

ifndef CC
	CC=gcc
endif

ifndef CPP
	CPP=g++
endif

EXT_OPTIONS=$(PTHREAD) $(DEBUG_OPT) $(PROCESSES_OPT) $(LOOP_OPT) $(MAX_CON_CONS_OPT) 

AR=ar
CPPFLAGS=-std=c++14 -W -Wall -O2 -Wno-unused-parameter -g $(EXT_OPTIONS)
CFLAGS=-std=gnu99 -W -Wall -O2 -Wno-unused-parameter -g $(EXT_OPTIONS)
_LIBWAFER_OBJ=wafer.o waferapi.o
_LIBWAFER=libwafer.a
# Rem.: These might get "rm-ed" in the end automagically because make thinks 
#       - quite rightfully I might add - that they are only intermediate resources!
_CPP11_OBJ=json11.o
MODULES=lightcontrol

# Rem.: patsubst parameters: <pattern>,<replacement>,<source-text>
#       where pattern is usually % here - meaning the whole text!
LIBWAFER_OBJ = $(patsubst %,$(OBJDIR)/%,$(_LIBWAFER_OBJ))
LIBWAFER = $(patsubst %,$(OBJDIR)/%,$(_LIBWAFER))
CPP11_OBJ = $(patsubst %,$(OBJDIR)/$(OBJCPPSUBDIR)/%,$(_CPP11_OBJ))

all: $(MODULES)

# rule to build modules
# Rem.: $@ is the module name (like lightcontrol), $^ is all the requirements so both the *.cpp and the *.a
%: $(SRCDIR)/%.cpp $(LIBWAFER) $(CPP11_OBJ)
	g++ $(CPPFLAGS) -o $@ $^ $(OPTIONS)

# Rem.: $@ is the libwafer.a with relative path, $^ is all the requirements so both *.o for the lib
$(LIBWAFER): $(LIBWAFER_OBJ)
	$(AR) r $@ $^

# Rem.: $@ is the *.o, $< is the FIRST requirement so is the *.c
$(OBJDIR)/%.o: $(SRCDIR)/%.c $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

# Rem.: $@ is the *.o (in subdir), $< is the FIRST requirement so is the *.cpp
# Rem.: OBJCPPSUBDIR already requires OBJDIR
$(OBJDIR)/$(OBJCPPSUBDIR)/%.o: $(SRCDIR)/%.cpp $(OBJDIR)/$(OBJCPPSUBDIR)
	g++ $(CPPFLAGS) -c -o $@ $<

# The directory of *.o files
$(OBJDIR):
	mkdir $(OBJDIR)

# This is subdir to the obj directory so that we can differentiate when linking/compiling them
$(OBJDIR)/$(OBJCPPSUBDIR):
	mkdir $(OBJDIR)/$(OBJCPPSUBDIR)

clean:
	rm -f $(LIBWAFER_OBJ) $(CPP11_OBJ)

distclean:
	rm -f $(LIBWAFER) $(LIBWAFER_OBJ) $(MODULES)

# vim: set ts=4 noet :
