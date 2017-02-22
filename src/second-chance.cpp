#include <list>
#include <map>
#include <algorithm>
#include "pr-sim.h"
#include <bitset>
#include <vector>

int SecondChance::count_page_fault(struct context *ctx) {
    int npages = ctx->npage_max - ctx->npage_min + 1;

    /* Declaration of second chance bits */
    auto scbits = new std::vector<bool>(npages, 0);

    /* auto &sc_bits = new std::bitset<npages>();
    std::cout << "SIZE!!!! " << sc_bits.size() << "\n"; */

}

