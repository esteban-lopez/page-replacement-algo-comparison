#include <iostream>
#include <vector>
#include <string>

#define I_LRU 0
#define I_FIFO 1
#define I_MFU 2
#define I_LFU 3
#define MAX_ALGO 5

struct context {
    int npage_min = 0;
    int npage_max = 9;
    int nref = 30; // number of reference sequence
    int available_frames = 7;
    double mean = 10;
    int stddev = 0;
    int distribution;
    std::vector<int> ref_seqeunce;
    context(int pmin, int pmax, int r, int af) : 
        npage_min(pmin), npage_max(pmax), nref(r), available_frames(af) {}
    context() {}
    void print() {
        printf("%-45s\n", "--------------------------------------------------------------");
        printf("%-15s%-15s%-15s%-18s\n", "Min Page", "Max Page", "Num reference", "Available Frame");
        printf("%-45s\n", "--------------------------------------------------------------");
        printf("%-15d%-15d%-15d%-18d\n",  npage_min, npage_max, nref, available_frames);
        printf("%-45s\n", "--------------------------------------------------------------");
    }
};

void get_context(struct context *ctx, int argc, char *argv[]);
class PageRepAlgo {
    public:
        virtual int count_page_fault(struct context *ctx) = 0;
        std::string name;
        std::string get_name() {return name;};
    protected:
        PageRepAlgo() {}
};
class Context {
public:
    Context(PageRepAlgo *);  
    ~Context();

private:
    PageRepAlgo* _strategy;
    int npage_min;
    int npage_max;
    int nref; // number of reference sequence
    int available_frames;
};


class LRU : public PageRepAlgo {
    public:
        LRU() {name="LRU";}
        ~LRU() {}
        virtual int count_page_fault(struct context *ctx);

};

class FIFO : public PageRepAlgo {
    public:
        FIFO() {name="FIFO";}
        ~FIFO() {}
        virtual int count_page_fault(struct context *ctx);
    private:
        /* data */
};

class LFU : public PageRepAlgo {
    public:
        LFU() {name="LFU";}
        ~LFU() {}
        virtual int count_page_fault(struct context *ctx);
};

class MFU : public PageRepAlgo {
    public:
        MFU() {name="MFU";}
        ~MFU() {}
        virtual int count_page_fault(struct context *ctx);
};

class SecondChance : public PageRepAlgo {
    public:
        SecondChance() {name = "Second Chance";}
        ~SecondChance() {}
        virtual int count_page_fault(struct context *ctx);
};

