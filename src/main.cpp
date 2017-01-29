#include <iostream>
#include "pr-sim.h"
#include "utility.h"
#include <string>

void print_page_fault_info(PageRepAlgo *algo, struct context &ctx);

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
        //std::cout << page_rep_algo[i]->count_page_fault(&ictx) << "\n";
        print_page_fault_info(page_rep_algo[i], ictx);
    }
}
void print_page_fault_info(PageRepAlgo *algo, struct context& ctx) {
    int nfault = algo->count_page_fault(&ctx);
    std::string name = algo->get_name();
    //std::cout << name << " " << nfault << "\n";
    printf("%-10s%-10d\n", name.c_str(), nfault);
}
