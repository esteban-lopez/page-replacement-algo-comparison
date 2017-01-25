
#include <random>
#define DISTRIB_BINOMIAL 0
#define DISTRIB_GEOMETRIC 1
#define DISTRIB_POSSION 2
#define DISTRIB_EXPONENTIAL 3
#define DISTRIB_GAMMA 4
#define DISTRIB_NORMAL 5
#define DISTRIB_EXPONEN 6
void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq);
void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq, int distribution);
