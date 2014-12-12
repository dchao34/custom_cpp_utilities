# Configurations
# --------------

# compiler
CXX ?= g++
CXXFLAGS = -Wall -std=c++11
CXXFLAGS += -fPIC

# Contents
# --------

BINARIES = trie_test csv_reader_test

# Dependencies
# ------------

# custom cpp utilities
CUSTOM_CPP_UTIL_ROOT = ..
CUSTOM_CPP_UTIL_LIBPATH = $(CUSTOM_CPP_UTIL_ROOT)/lib
CUSTOM_CPP_UTIL_LIBNAME = -lCustomCPPUtils
INCFLAGS += -I$(CUSTOM_CPP_UTIL_ROOT)
LDFLAGS += -L $(CUSTOM_CPP_UTIL_LIBPATH) $(CUSTOM_CPP_UTIL_LIBNAME)

# Build Rules
# -----------

.PHONY: all debug clean 

$@ : $@.cc
	$(CXX) $(CXXFLAGS) $< -o $%

all : CXXFLAGS += -O2
all : $(BINARIES)

debug : CXX += -DDEBUG -g
debug : $(BINARIES)

$(BINARIES) : % : %.cc
	$(CXX) $(CXXFLAGS) $(INCFLAGS) $(LDFLAGS) -Wl,-rpath,$(CUSTOM_CPP_UTIL_LIBPATH) -o $@ $<

clean:
	rm -f *~ *.o `find . -perm +100 -type f`
