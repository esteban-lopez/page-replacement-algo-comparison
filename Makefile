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
	./$(TARGET) --num-frames 30 --min-page 1 --max-page 50 --num-references 10000 

test:
	./$(TARGET) --num-frames 30 --min-page 1 --max-page 50 --num-references 10000 --mean 10 --stddev 5 --uniform

test2:
	./$(TARGET) --num-frames 30 --min-page 1 --max-page 50 --num-references 10000 --mean 30 --stddev 5 --poisson

test3:
	./$(TARGET) --num-frames 30 --min-page 1 --max-page 50 --num-references 10000 --mean 30 --stddev 5 --exponential

test-binomial:
	./$(TARGET) --num-frames 30 --min-page 1 --max-page 50 --num-references 10000 --mean 0.5 --binomial

clean:
	rm -rf $(OBJ_DIR) $(TARGET)
