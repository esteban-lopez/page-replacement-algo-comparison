#include <iostream>
#include <map>
#include <random>
#include <set>
#include <cassert>
#include "pr-sim.h"

template<typename T>
void print_vec(std::vector<T> &v) {
    for (auto &p : v) 
        std::cout << p << " ";
    std::cout << "\n";

}
template<typename T>
void print_maptable(std::map<T, T> &tab) {
    for (auto &p : tab) {
        std::cout << p.first << " " << p.second << "\n";
    }
}
template<typename T>
void print_set(std::set<T> &s) {
    std::cout << "Loaded pages : ";
    for (auto &p : s) {
        std::cout << p << " ";
    }
}
void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq);
int main(int argc, char *argv[])
{
    int npage_min = 0;
    int npage_max = 9;
    int nref = 30; // number of reference sequence
    int available_frames = 7;
    struct context input_context(npage_min, npage_max, nref, available_frames);
    LRU lru;
    lru.count_page_fault(&input_context);
    get_context(input_context, argc, argv); // process option variables
    
    //std::cout << "Randomly-chosen mean: " << mean << '\n';
    std::vector<int> ref_seqeunce(nref);
    gen_ref_seq(npage_min, npage_max, ref_seqeunce);
    //print_vec(ref_seqeunce);

    std::set<int> loaded_pages; // Initially, It contains 0 because of demand paging
    std::map<int, int> ref_counting_table;
    int nfault = 0;
    int ref_time = 0;
    
    for (int i = 0; i < nref; i++) {
        int ref_page = ref_seqeunce[i];
        //print_set(loaded_pages);
        //std::cout << "(" <<  ref_page << ")" << "\n";
        if (loaded_pages.find(ref_page) == loaded_pages.end()) {
            nfault++;
            //assert(loaded_pages.size() <= available_frames);
            // page fault algorithm starts here
            if (loaded_pages.size() >= available_frames) {
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
    std::cout << "Fault count in LRU algorithm is " << nfault << "\n";
}
// return recently referenced page
int reference_next_page(int page, std::map<int, int> &tab) {
    return (tab[page]++);
}
void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq) {
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(range_min, range_max);
    for (int i = 0; i < rseq.size(); i++) {
        rseq[i] = uniform_dist(e1);
    }
}
void get_context(struct context &ctx, int argc, char *argv []) {

}
