CXX = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings

CXXFLAGS = -std=c++14 -g -Wall

OBJECTS = Customer.o Heap.o StackQueue.o CustServiceSim.o ServiceCenter.o AnalyticalModel.o

main: main.cpp $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
clean:
	rm -rf *.dSYM
		$(RM) *.o *.gc* main
