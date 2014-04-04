# To build a simple simulator program 
CXX = g++
CXXFLAGS = -std=c++11 -g -Wall
LDFLAGS=

HEADERS=job.hpp scheduler.hpp simulator.cpp
SOURCES=job.cpp scheduler.cpp simulator.cpp main.cpp
TARGET=simu

.PHONY : all test clean

all : $(SOURCES) $(HEADERS) 
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SOURCES) -o $(TARGET)

clean :
	rm *.~ $(TARGET)
