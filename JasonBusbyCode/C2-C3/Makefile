# Determine the operating system
ifeq ($(OS),Windows_NT)
    RM := del /Q /F
else
    RM := rm -f
endif


# Compiler and flags
CXX := g++
CXXFLAGS := -fdiagnostics-color=always -g

# Linker flags for winmm
LDFLAGS := -lwinmm

# Source files and object files
SRC := Level.cpp main.cpp SingleProjectile.cpp Vector2.cpp Player.cpp Fireball.cpp WeaponPickupTile.cpp MultiFireball.cpp Actor.cpp Enemy.cpp HealthPickupTile.cpp
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
	$(RM) $(OBJ) $(TARGET)
