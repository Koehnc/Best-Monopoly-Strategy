CXX = g++
CXXFLAGS = -Wall
SRC_FILES = $(wildcard *.cpp)
EXECUTABLE = Monopoly

all: $(EXECUTABLE)

$(EXECUTABLE): $(SRC_FILES)
    $(CXX) $(CXXFLAGS) -o $@ $^

clean:
    rm -f $(EXECUTABLE)

.PHONY: all clean