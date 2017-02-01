#include "pr-sim.h"
#include "gen-random-seq.h"
#include <list>
#include <map>
#include <algorithm>

int LFU::count_page_fault(struct context *ctx) {
    
    std::list<int> loaded_pages; // Initially, It contains 0 because of demand paging
    std::map<int, int> ref_counting_table;
    int nfault = 0;

    for (int i = 0; i < ctx->nref; i++) {
        int ref_page = ctx->ref_seqeunce[i];
        auto has_page =
            !(std::find(loaded_pages.begin(), loaded_pages.end(), ref_page) == loaded_pages.end());
        if (has_page == false) {
            ++nfault;
            if (loaded_pages.size() >= ctx->available_frames) {
                auto lfu_page = loaded_pages.begin();
                // find the least freqeuntly used page
                for (auto &p : loaded_pages) {
                    if (ref_counting_table[*lfu_page] > ref_counting_table[p]) {
                        *lfu_page = p;
                    }
                }
                //auto victim = std::find(loaded_pages.begin(), loaded_pages.end(), lfu_page);
                loaded_pages.erase(lfu_page);
            }
            loaded_pages.push_back(ref_page);
        } else {
            
        }
        ref_counting_table[ref_page]++;
    }
    return nfault;
}
