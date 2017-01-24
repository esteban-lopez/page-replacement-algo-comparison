struct context {
    int npage_min = 0;
    int npage_max = 9;
    int nref = 30; // number of reference sequence
    int available_frames = 7;
    context(int pmin, int pmax, int r, int af) : 
        npage_min(pmin), npage_max(pmax), nref(r), available_frames(af) {}
};
