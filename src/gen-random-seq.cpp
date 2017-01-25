#include "gen-random-seq.h"

void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq) {
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(range_min, range_max);
    for (int i = 0; i < rseq.size(); i++) {
        rseq[i] = uniform_dist(e1);
    }
}
