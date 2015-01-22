CXX = g++
CXXFLAGS = -g -Wall
INC_DIR =
LIB_DIR =
LIBS =

TARGET = a.out
DEPENDENCIES = main.o magicSquare.o

$(TARGET): $(DEPENDENCIES)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(INC_DIR) $(LIB_DIR) $(LIBS)

clean:
	rm *.o;

.phony: clean
