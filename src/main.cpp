#include <iostream>
#include "pr-sim.h"
#include <getopt.h>

void help();
void version();
int main(int argc, char *argv[])
{
    struct context ictx;
    get_context(&ictx, argc, argv); // process option variables
    ictx.print();
    PageRepAlgo *page_rep_algo;
    LRU LRUSimulator;
    FIFO FIFOSimulator;
    /*int lru_fault = LRUSimulator.count_page_fault(&ictx);
    int fifo_fault = FIFOSimulator.count_page_fault(&ictx);*/
    page_rep_algo = &LRUSimulator;
    int lru_fault = page_rep_algo->count_page_fault(&ictx);
    page_rep_algo = &FIFOSimulator;
    int fifo_fault = page_rep_algo->count_page_fault(&ictx);

    std::cout << "LRU's fault " << lru_fault << "\n";
    std::cout << "FIFO's fault " << fifo_fault << "\n";
}
void get_context(struct context *ctx, int argc, char *argv []) {
    int choice;
    while (1)
    {
        static struct option long_options[] =
        {
            /* Use flags like so:
            {"verbose",    no_argument,    &verbose_flag, 'V'}*/
            /* Argument styles: no_argument, required_argument, optional_argument */
            {"version", no_argument,    0,    'v'},
            {"help", no_argument,    0,    'h'},
            {"num-frames", required_argument,    0,    'f'},
            {"min-page", required_argument,    0,    'm'},
            {"max-page", required_argument,    0,    'M'},
            {"num-references", required_argument,    0,    'r'},
            
            {0,0,0,0}
        };

        int option_index = 0;

        /* Argument parameters:
            no_argument: " "
            required_argument: ":"
            optional_argument: "::" */

        choice = getopt_long(argc, argv, "vhf:M:m:r:",
                    long_options, &option_index);

        if (choice == -1)
            break;

        switch( choice )
        {
            case 'v':
                version();
                break;
            case 'h':
                help();
                break;
            case 'f':
                ctx->available_frames = atoi(optarg);
                break;
            case 'M':
                ctx->npage_max = atoi(optarg);
                break;
            case 'm':
                ctx->npage_min = atoi(optarg);
                break;
            case 'r':
                ctx->nref = atoi(optarg);
                break;
            case '?':
                /* getopt_long will have already printed an error */
                std::cout << "WTF?" << "\n";
                break;
            default:
                /* Not sure how to get here... */
                //return EXIT_FAILURE;
                break;
        }
    }

    /* Deal with non-option arguments here */
    if ( optind < argc )
    {
        while ( optind < argc )
        {
            
        }
    }
}
void help() {
    printf("--num-frames : available_frames\n");
    printf("--min-page : min page number\n");
    printf("--max-page : max page number\n");
    printf("--num-references : length of reference sequence\n");
    printf("--help : to get help\n");
    printf("--version : print version of program\n");
    exit(0);
}

void version() {
    printf("Version 1.0\n");
    exit(0);
}
