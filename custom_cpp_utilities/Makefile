# Configurations
# --------------

# compiler
CXX ?= g++
CXXFLAGS = -Wall -std=c++11 
CXXFLAGS += -fPIC

# library name
LIBNAME = libCustomCPPUtils.so

# path to compiled libaries
PKG_LIBPATH = ../lib

# package sources
SOURCES = CsvReader.cc

# Build Rules
# -----------

.PHONY: all debug lib clean distclean

OBJECTS = $(addprefix $(PKG_LIBPATH)/, $(patsubst %.cc, %.o, $(SOURCES)))

all : CXXFLAGS += -O2
all : lib

debug : CXX += -DDEBUG -g
debug : CXXFLAGS += -O0
debug : lib

lib : $(PKG_LIBPATH)/$(LIBNAME)

$(PKG_LIBPATH)/$(LIBNAME) : $(OBJECTS)
	if [ "$(shell uname)" = "Darwin" ]; then \
		SHARED_LIB_FLAG="-dynamiclib -Wl,-install_name,@rpath/$(LIBNAME)"; \
	else \
		SHARED_LIB_FLAG="-shared -Wl,-soname,$(LIBNAME)"; \
	fi; \
	$(CXX) $${SHARED_LIB_FLAG} $(OBJECTS) $(LDFLAGS) -o $@

$(OBJECTS) : $(PKG_LIBPATH)/%.o : %.cc %.h
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

clean:
	rm -f *~ $(PKG_LIBPATH)/$(LIBNAME) $(OBJECTS)
