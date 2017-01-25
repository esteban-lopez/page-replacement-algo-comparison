#include <iostream>
#include "pr-sim.h"
#include "utility.h"

int main(int argc, char *argv[])
{
    struct context ictx;
    get_context(&ictx, argc, argv); // process option variables
    ictx.print();
    PageRepAlgo *page_rep_algo;
    LRU LRUSimulator;
    FIFO FIFOSimulator;
    /*int lru_fault = LRUSimulator.count_page_fault(&ictx);
    int fifo_fault = FIFOSimulator.count_page_fault(&ictx);*/

    /*page_rep_algo = &LRUSimulator;
    int lru_fault = page_rep_algo->count_page_fault(&ictx);
    page_rep_algo = &FIFOSimulator;
    int fifo_fault = page_rep_algo->count_page_fault(&ictx);*/

    page_rep_algo = &LRUSimulator;
    int lru_fault = page_rep_algo->count_page_fault(&ictx);
    page_rep_algo = &FIFOSimulator;
    int fifo_fault = page_rep_algo->count_page_fault(&ictx);
    std::cout << "LRU's fault " << lru_fault << "\n";
    std::cout << "FIFO's fault " << fifo_fault << "\n";
}
