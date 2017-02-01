VPATH=src
TARGET=bin/page-rep-sim
CXX=g++
CXXFLAGS=-std=c++14 -O2
INC=./inc

SRC=$(subst src/,,$(wildcard src/*.cpp))
OBJ=$(SRC:.cpp=.o)

SRC_DIR=$(wildcard src/*.cpp)
OBJ_DIR=$(subst src/,obj/,$(SRC_DIR:.cpp=.o))
#OBJ_DIR=$(addprefix obj/,$(OBJ))
#SRC_DIR=$(addprefix src/,$(SRC))
.SUFFIXES : .cpp .o

.cpp.o :
	$(CXX) $(CXXFLAGS) -I$(INC) -c $< -o $@

$(TARGET) : $(OBJ)
	@echo $(OBJ_DIR)
	$(CXX) -I$(INC) $(CXXFLAGS) -o $@ $^
	mv *.o obj/

run:
	# examples
	./$(TARGET) --num-frames 500 --min-page 1 --max-page 1000 --num-references 10000
clean:
	rm -rf $(OBJ_DIR) $(TARGET)
