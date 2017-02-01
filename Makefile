TARGET=bin/page-rep-sim
CXX=g++
CXXFLAGS=-std=c++14 -O2
INC=./inc

#SRC=main.cpp lru.cpp fifo.cpp lfu.cpp mfu.cpp gen-random-seq.cpp utility.cpp option.cpp
SRC=$(subst src/,,$(wildcard src/*.cpp))
#OBJ=main.o lru.o fifo.o lfu.o mfu.o gen-random-seq.o utility.o option.o 
OBJ=$(SRC:.cpp=.o)

SRC_DIR=$(wildcard src/*.cpp)
OBJ_DIR=$(subst src/,obj/,$(SRC_DIR:.cpp=.o))
#OBJ_DIR=$(addprefix obj/,$(OBJ))
#SRC_DIR=$(addprefix src/,$(SRC))
MOVE_OBJ=mv $@ obj/


$(TARGET) : $(OBJ)
	@echo $(OBJ_DIR)
	mv *.o obj/
	$(CXX) -I$(INC) $(CXXFLAGS) $(OBJ_DIR) -o $@

main.o: src/main.cpp 
	$(CXX) -I$(INC) $(CXXFLAGS) -c $(SRC_DIR)
	#$(MOVE_OBJ)

lru.o: src/lru.cpp 
	$(CXX) -I$(INC) $(CXXFLAGS) -c $^

fifo.o: src/fifo.cpp
	$(CXX) -I$(INC) $(CXXFLAGS) -c $^

lfu.o: src/lfu.cpp 
	$(CXX) -I$(INC) $(CXXFLAGS) -c $^

mfu.o: src/mfu.cpp
	$(CXX) -I$(INC) $(CXXFLAGS) -c $^

gen-random-seq.o: src/gen-random-seq.cpp
	$(CXX) -I$(INC) $(CXXFLAGS) -c $^

utility.o: src/utility.cpp
	$(CXX) -I$(INC) $(CXXFLAGS) -c $^

option.o: src/option.cpp
	$(CXX) -I$(INC) $(CXXFLAGS) -c $^

run:
	# examples
	./$(TARGET) --num-frames 500 --min-page 1 --max-page 1000 --num-references 10000
clean:
	rm *.o
	rm -rf $(OBJ_DIR) $(TARGET)
