# Compiler and flags
CXX := g++
CXXFLAGS := -fdiagnostics-color=always -g

# Linker flags for winmm
LDFLAGS := -lwinmm

# Source files and object files
SRC := Level.cpp main.cpp SingleProjectile.cpp Vector2.cpp
OBJ := $(SRC:.cpp=.o)

# Executable name
TARGET := main.exe

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ) $(TARGET)
