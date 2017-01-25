#include "utility.h"

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
