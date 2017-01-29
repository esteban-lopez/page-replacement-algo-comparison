#include <iostream>
#include "pr-sim.h"
#include "utility.h"


int main(int argc, char *argv[])
{
    struct context ictx;
    get_context(&ictx, argc, argv); // process option variables
    ictx.print();
    PageRepAlgo *page_rep_algo[MAX_ALGO];
    page_rep_algo[0] = new LRU;
    page_rep_algo[1] = new FIFO;
    page_rep_algo[2] = new MFU;
    page_rep_algo[3] = new LFU;
    for (int i = 0; i < MAX_ALGO; i++) {
        std::cout << page_rep_algo[i]->count_page_fault(&ictx) << "\n";
    }
}
