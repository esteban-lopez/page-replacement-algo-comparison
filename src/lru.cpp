#include "pr-sim.h"
#include "gen-random-seq.h"
#include <iostream>
#include <vector>
#include <set>
#include <map>

int LRU::count_page_fault(struct context *ctx) {

    std::set<int> loaded_pages; // Initially, It contains 0 because of demand paging
    std::map<int, int> ref_counting_table;
    int nfault = 0;
    int ref_time = 0;
    
    for (int i = 0; i < ctx->nref; i++) {
        int ref_page = ctx->ref_seqeunce[i];
        //print_set(loaded_pages);
        //std::cout << "(" <<  ref_page << ")" << "\n";
        if (loaded_pages.find(ref_page) == loaded_pages.end()) {
            nfault++;
            //assert(loaded_pages.size() <= available_frames);
            // page fault algorithm starts here
            if (loaded_pages.size() >= ctx->available_frames) {
                // victim selection
                auto min_used_page = *loaded_pages.begin();
                //print_maptable(ref_counting_table);
                for (auto &p : loaded_pages) {
                    //std::cout << p << " " << ref_counting_table[p] << "\n";
                    if (ref_counting_table[min_used_page] > ref_counting_table[p]) {
                        min_used_page = p;
                    }
                }

                //std::cout << "victim page is " << min_used_page << "(time " << ref_counting_table[min_used_page] << ")" << "\n";
                ref_counting_table[min_used_page] = -1; // Initialze victim page's reference count to zero
                loaded_pages.erase(min_used_page);
                loaded_pages.insert(ref_page);
            } else { // when first loading
                loaded_pages.insert(ref_page);
            }
        }
        ref_counting_table[ref_page] = ref_time++;
    }
    //std::cout << "Fault count in LRU algorithm is " << nfault << "\n";
    return nfault;
}

