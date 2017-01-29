#include "gen-random-seq.h"
#include <iostream>

// unifrom distribution is default
// use no locality properties which is actually happened in reality
void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq) {
    std::random_device rd;
    std::default_random_engine e1(rd());
    std::uniform_int_distribution<int> uniform_dist(range_min, range_max);
    for (int i = 0; i < rseq.size(); i++) {
        rseq[i] = uniform_dist(e1);
    }
}

void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq, int distribution) {

    std::random_device rd;
    std::default_random_engine e1(rd());
    switch (distribution) {
        case DISTRIB_BINOMIAL:
            break;
        case DISTRIB_GEOMETRIC:
            break;
        case DISTRIB_POSSION: 
            break;
        case DISTRIB_EXPONENTIAL:
            break;
        case DISTRIB_GAMMA:
            break;
        case DISTRIB_NORMAL:
            break;
        case DISTRIB_EXPONEN:
            break;
        default:
            std::cout << "Error(Wrong distribution code) > " << distribution  << "\n";
            break;
    }
    std::uniform_int_distribution<int> uniform_dist(range_min, range_max);
    for (int i = 0; i < rseq.size(); i++) {
        rseq[i] = uniform_dist(e1);
    }
}
