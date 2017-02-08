# page-replacement-algorithm-comparison
lru, fifo, lfu, mfu page replacement algorithm implementation and their comparison by counting page fault under several probability distribution.
I actually start this small project for the problem 9.34 from the text book, Operating system concepts 8th

```
git clone https://github.com/rupc/page-rep-algo-comp
cd page-replacement-simulator
./setup.sh
make run
```


## Option explained
1. --num-frames # : number of available frames
2. --min-page # : minimum page number
3. --max-page # : maximum page number
4. --num-references # : number of reference sequence

**You can change option argument from run: section in Makefile**

**You can also add more probability distributions in src/gen-random-seq.cpp**
