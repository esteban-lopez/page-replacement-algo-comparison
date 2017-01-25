TARGET=page-rep-sim
CXX=g++
CFLAGS=-std=c++14 -O2
INC=./inc
EXECUTABLE=bin/pr-sim
SRC=./src
OBJ=main.o lru.o fifo.o gen-random-seq.o utility.o option.o
OBJ_DIR=$(addprefix obj/,$(OBJ))
SRC_DIR=$(addprefix src/,$(SRC))
MOVE_OBJ=mv $@ obj/

$(TARGET) : $(OBJ)
	echo $(OBJ_DIR)
	mv *.o obj/
	$(CXX) -I$(INC) $(CFLAGS) $(OBJ_DIR) -o $(EXECUTABLE)

main.o: src/main.cpp inc/pr-sim.h inc/utility.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/main.cpp src/lru.cpp src/fifo.cpp src/gen-random-seq.cpp src/utility.cpp
	#$(MOVE_OBJ)

lru.o: src/lru.cpp inc/pr-sim.h inc/gen-random-seq.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/lru.cpp

fifo.o: src/fifo.cpp inc/pr-sim.h inc/gen-random-seq.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/fifo.cpp

gen-random-seq.o: src/gen-random-seq.cpp inc/gen-random-seq.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/gen-random-seq.cpp

utility.o: src/utility.cpp inc/utility.h inc/pr-sim.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/utility.cpp

option.o: src/option.cpp inc/pr-sim.h inc/utility.h
	$(CXX) -I$(INC) $(CFLAGS) -c src/option.cpp

run:
	# examples
	./$(EXECUTABLE) --num-frames 10 --min-page 1 --max-page 40 --num-references 1000
clean:
	rm *.o
	rm -rf $(OBJ_DIR) $(TARGET) $(EXECUTABLE)
