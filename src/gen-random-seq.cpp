#include <gen-random-seq.h>
#include <iostream>

// unifrom distribution is default
// use no locality properties which is not actually happened in computer system
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
        case DISTRIB_POISSON:
            //gen_poisson(rseq, e1, mean);
            break;
        case DISTRIB_EXPONENTIAL:
            break;
        case DISTRIB_GAMMA:
            break;
        case DISTRIB_NORMAL:
            gen_normal(rseq, e1, range_min, range_max);
            break;
        case DISTRIB_EXPONEN:
            break;
        case DISTRIB_UNIFORM:
            gen_uniform(rseq, e1, range_min, range_max);
            break;
        default:
            std::cerr << "Error(Wrong distribution code) > " << distribution  << "\n";
            break;
    }
}
void gen_uniform(std::vector<int> &rseq, std::default_random_engine &e1, int range_min, int range_max) {
    std::uniform_int_distribution<int> uniform_dist(range_min, range_max);
    for (int i = 0; i < rseq.size(); i++) {
        rseq[i] = uniform_dist(e1);
    }
}
void gen_normal(std::vector<int> &rseq, std::default_random_engine &e1, int range_min, int range_max) {
    double mean = (range_min + range_max) / 2.0;
    std::normal_distribution<double> normal_dist(mean, 5.0);

    int cnt = 0;
    while (cnt < rseq.size()) {
        double ran = normal_dist(e1);
        if (ran >= range_min && ran <= range_max) {
            rseq[cnt] = (int)ran;
            ++cnt;
        } else {
            continue;
        }
    }
}
void gen_poisson(std::vector<int> &rseq, std::default_random_engine &e1, double mean) {
    std::poisson_distribution<int> poisson_dist(mean);
    for (int i = 0; i < rseq.size(); i++) {
        rseq[i] = poisson_dist(e1);
    }
}
