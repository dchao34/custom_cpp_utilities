CXX ?= g++

CXXFLAGS = -Wall -std=c++11

$@ : $@.cc
	$(CXX) $(CXXFLAGS) $< -o $%

clean:
	@rm -f *~ *.o `find . -perm +100 -type f`
