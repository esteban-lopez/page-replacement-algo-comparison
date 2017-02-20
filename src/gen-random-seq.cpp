#include <gen-random-seq.h>
#include <iostream>
#include "pr-sim.h"

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
void gen_ref_seq(struct context *ctx) {
    switch (ctx->distribution) {
        case DISTRIB_NORMAL:
            gen_normal(ctx);
            break;
        case DISTRIB_EXPONEN:
            break;
        case DISTRIB_UNIFORM:
            gen_uniform(ctx);
            break;
        case DISTRIB_BINOMIAL:
            break;
        case DISTRIB_GEOMETRIC:
            break;
        case DISTRIB_POISSON:
            gen_poisson(ctx);
            break;
        case DISTRIB_EXPONENTIAL:
            break;
        case DISTRIB_GAMMA:
            break;
        default:
            std::cerr 
                << "Error(Wrong distribution code) > "
                << ctx->distribution  << "\n";
            break;
    }
}
void gen_uniform(struct context *ctx) {
    std::uniform_int_distribution<int>
        uniform_dist(ctx->npage_min, ctx->npage_max);

    std::random_device rd;
    std::default_random_engine e1(rd());

    int sz = ctx->ref_seqeunce.size();

    for (int i = 0; i < sz; i++) {
        ctx->ref_seqeunce[i] = uniform_dist(e1);
    }
}
void gen_normal(struct context *ctx) {
    std::normal_distribution<double> normal_dist(ctx->mean, ctx->stddev);

    std::random_device rd;
    std::default_random_engine e1(rd());

    int cnt = 0;

    while (cnt < (ctx->ref_seqeunce).size()) {
        double ran = normal_dist(e1);
        if (ran >= ctx->npage_min && ran <= ctx->npage_max) {
            ctx->ref_seqeunce[cnt] = (int)ran;
            ++cnt;
        } else {
            continue;
        }
    }
}
void gen_poisson(struct context *ctx) {
    std::poisson_distribution<int> poisson_dist(ctx->mean);
    std::random_device rd;
    std::default_random_engine e1(rd());

    int sz = ctx->ref_seqeunce.size();

    for (int i = 0; i < sz; i++) {
        ctx->ref_seqeunce[i] = poisson_dist(e1);
    }
}
