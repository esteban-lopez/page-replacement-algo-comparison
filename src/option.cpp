#include "pr-sim.h"
#include "utility.h"
#include "gen-random-seq.h"
#include <getopt.h>

void get_context(struct context *ctx, int argc, char *argv []) {
    int choice;
        printf("%d\n", __LINE__);
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
            /*{"mean", required_argument, 0, 0},
            {"stddev", required_argument, 0, 0},*/
            {"mean", required_argument, 0, OPT_MEAN},
            {"stddev", required_argument, 0, OPT_STDDEV},

            {"poisson", no_argument, 0, OPT_POISSON},
            {"normal", no_argument, 0, OPT_NORMAL},
            {"geometric", no_argument, 0, OPT_GEOMETRIC},
            {"binomial", no_argument, 0, OPT_BINOMIAL},
            {"exponential", no_argument, 0, OPT_EXPONENTIAL},
            {"uniform", no_argument, 0, OPT_UNIFORM},
            {"user-dist", required_argument, 0, OPT_USERDIST},
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
            case OPT_MEAN:
                ctx->mean = atoi(optarg);
                break;
            case OPT_STDDEV:
                ctx->stddev = atoi(optarg);
                break;

            /* specify distribution type*/
            case OPT_POISSON:
                ctx->distribution = DISTRIB_POISSON;
                break;
            case OPT_NORMAL:
                ctx->distribution = DISTRIB_NORMAL;
                break;
            case OPT_GEOMETRIC:
                ctx->distribution = DISTRIB_GEOMETRIC;
                break;
            case OPT_BINOMIAL:
                ctx->distribution = DISTRIB_BINOMIAL;
                break;
            case OPT_EXPONENTIAL:
                ctx->distribution = DISTRIB_EXPONENTIAL;
                break;
            case OPT_UNIFORM:
                ctx->distribution = DISTRIB_UNIFORM;
                break;
            case OPT_USERDIST:
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
            case 'v':
                version();
                break;
            case 'h':
                help();
                break;
            default:
                /* Not sure how to get here... */
                //return EXIT_FAILURE;
                break;
        }
    }

    /* allocate space for random sequence */
    ctx->ref_seqeunce = std::vector<int>(ctx->nref);

    /*create random sequence based on specified distrubution*/
    gen_ref_seq(ctx);

    /* Deal with non-option arguments here */
    if ( optind < argc )
    {
        while ( optind < argc )
        {
            
        }
    }
}
