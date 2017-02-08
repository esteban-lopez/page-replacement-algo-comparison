# page-replacement-algorithm-comparison
lru, fifo, lfu, mfu page replacement algorithm implementation and their comparison by counting page fault under several probability distribution.

```
git clone https://github.com/rupc/page-replacement-simulator
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
