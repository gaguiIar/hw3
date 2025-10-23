CXX := g++
CXXFLAGS := -g -Wall --std=c++11
VALGRIND := valgrind --tool=memcheck --leak-check=yes

all: llrec-test

#-----------------------------------------------------
# ADD target(s) to build your llrec-test executable
#-----------------------------------------------------
llrec.o: llrec.cpp llrec.h
	$(CXX) $(CXXFLAGS) -c llrec.cpp

llrec-test.o: llrec-test.cpp llrec.h 
	$(CXX) $(CXXFLAGS) -c llrec-test.cpp

llrec-test: llrec.o llrec-test 
	$(CXX) $(CXXFLAGS) llrec.o llrec-test.o -o llrec-test

valgrind:llrec-test
	$(VALGRIND) ./llrec-test llrec-test1.ins

clean:
	rm -f *.o rh llrec-test *~

.PHONY: all clean valgrind