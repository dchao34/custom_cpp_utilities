CXX ?= g++

CXXFLAGS = -Wall -std=c++11
CXXFLAGS += -I./

$@ : $@.cc
	$(CXX) $(CXXFLAGS) $< -o $%

clean:
	@rm -f *~ *.o `find . -perm +100 -type f`
