#include <vector>
#include <random>

/* #define fill_ref_sequence(distb) \
    int sz = ctx->ref_seqeunce.size(); \
    int cnt = 0; \
    while (cnt < sz) { \
        double ran = distb_dist(e1); \
        if (ran >= ctx->npage_min && ran <= ctx->npage_max) { \
            ctx->ref_seqeunce[cnt++] = (int)ran; \
            continue; \
        } \
    } \ */
#define DISTRIB_BINOMIAL 0
#define DISTRIB_GEOMETRIC 1
#define DISTRIB_POISSON 2
#define DISTRIB_EXPONENTIAL 3
#define DISTRIB_GAMMA 4
#define DISTRIB_NORMAL 5
#define DISTRIB_UNIFORM 7

/*void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq);
void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq, int distribution);*/

void gen_ref_seq(struct context *ctx);
void gen_ref_seq(struct context *ctx);


void gen_normal(struct context *ctx);
void gen_uniform(struct context *ctx);
void gen_poisson(struct context *ctx);
void gen_geometric(struct context *ctx);
void gen_binomial(struct context *ctx);
void gen_exponential(struct context *ctx);
void gen_gamma(struct context *ctx);

/* Normal distribution calculates mean by (range_min + range_max) / 2
 * and standard deviation is 5 */
//void gen_normal(std::vector<int> &rseq, std::default_random_engine &e1, int range_min, int range_max);
//void gen_poisson(std::vector<int> &rseq, std::default_random_engine &e1, double mean);
//void gen_normal(std::vector<int> &rseq, std::default_random_engine &e1, double mean, double stddev);
