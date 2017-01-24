TARGET=page-rep-sim
CXX=g++
CFLAGS=-std=c++14 -O2
INC=./inc
EXECUTABLE=bin/pr-sim
SRC=./src
OBJ=main.o lru.o fifo.o
OBJ_DIR=$(addprefix obj/,$(OBJ))
SRC_DIR=$(addprefix src/,$(SRC))
MOVE_OBJ=mv $@ obj/

$(TARGET) : $(OBJ)
	echo $(OBJ_DIR)
	mv *.o obj/
	$(CXX) -I$(INC) $(CFLAGS) $(OBJ_DIR) -o $(EXECUTABLE)

main.o: src/main.cpp inc/pr-sim.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/main.cpp src/lru.cpp src/fifo.cpp
	#$(MOVE_OBJ)

lru.o: src/lru.cpp inc/pr-sim.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/lru.cpp

fifo.o: src/fifo.cpp inc/pr-sim.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/fifo.cpp

clean:
	rm *.o
	rm -rf $(OBJ_DIR) $(TARGET) $(EXECUTABLE)
