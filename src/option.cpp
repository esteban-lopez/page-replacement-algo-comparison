#include "pr-sim.h"
#include "utility.h"
#include "gen-random-seq.h"
#include <getopt.h>

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
            {"distribution", required_argument, 0, 'd'},
            
            {0,0,0,0}
        };

        int option_index = 0;

        /* Argument parameters:
            no_argument: " "
            required_argument: ":"
            optional_argument: "::" */

        choice = getopt_long(argc, argv, "vhf:M:m:r:d:",
                    long_options, &option_index);

        if (choice == -1)
            break;
        int distribution = DISTRIB_UNIFORM;
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
            /*case 'd':
                distribution = atoi(optarg);*/
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
    ctx->ref_seqeunce = std::vector<int>(ctx->nref);
    gen_ref_seq(ctx->npage_min, ctx->npage_max, ctx->ref_seqeunce, DISTRIB_NORMAL);
    //gen_ref_seq(ctx->npage_min, ctx->npage_max, ctx->ref_seqeunce, DISTRIB_UNIFORM);

    /* Deal with non-option arguments here */
    if ( optind < argc )
    {
        while ( optind < argc )
        {
            
        }
    }
}
