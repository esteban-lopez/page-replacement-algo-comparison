#include <vector>
#include <random>

#define DISTRIB_BINOMIAL 0
#define DISTRIB_GEOMETRIC 1
#define DISTRIB_POISSON 2
#define DISTRIB_EXPONENTIAL 3
#define DISTRIB_GAMMA 4
#define DISTRIB_NORMAL 5
#define DISTRIB_EXPONEN 6
#define DISTRIB_UNIFORM 7

void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq);
void gen_ref_seq(int range_min, int range_max, std::vector<int> &rseq, int distribution);

void gen_uniform(std::vector<int> &rseq, std::default_random_engine &e1, int range_min, int range_max);
/* Normal distribution calculates mean by (range_min + range_max) / 2
 * and standard deviation is 5 */
void gen_normal(std::vector<int> &rseq, std::default_random_engine &e1, int range_min, int range_max);
void gen_poisson(std::vector<int> &rseq, std::default_random_engine &e1, double mean);
//void gen_normal(std::vector<int> &rseq, std::default_random_engine &e1, double mean, double stddev);
