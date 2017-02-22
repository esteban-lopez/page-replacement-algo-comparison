/* Copyright (C) 
 * 2017 - Yongrae Jo
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

/**
 * @file main.cpp
 * @brief 
 * @author Yongrae Jo
 * @version 1.0
 * @date 2017-02-22
 */

#include <iostream>
#include "pr-sim.h"
#include "utility.h"
#include <string>
#include <vector>

void print_page_fault_info(PageRepAlgo *algo, struct context &ctx);

int main(int argc, char *argv[])
{
    struct context ictx;
    get_context(&ictx, argc, argv); // process option variables
    ictx.print();

    /*PageRepAlgo *page_rep_algo[MAX_ALGO];
    page_rep_algo[0] = new LRU;
    page_rep_algo[1] = new FIFO;
    page_rep_algo[2] = new MFU;
    page_rep_algo[3] = new LFU;
    page_rep_algo[4] = new SecondChance;*/

    std::vector<PageRepAlgo *> page_rep_algo;
    page_rep_algo.push_back(new LRU);
    page_rep_algo.push_back(new FIFO);
    page_rep_algo.push_back(new MFU);
    page_rep_algo.push_back(new LFU);
    /*page_rep_algo.push_back(new SecondChance);*/

    /* This is strategy pattern! */
    for (int i = 0; i < page_rep_algo.size(); i++) {
        /*std::cout << page_rep_algo[i]->count_page_fault(&ictx) << "\n";*/
        print_page_fault_info(page_rep_algo[i], ictx);
    }
}
void print_page_fault_info(PageRepAlgo *algo, struct context& ctx) {
    int nfault = algo->count_page_fault(&ctx);
    std::string name = algo->get_name();
    //std::cout << name << " " << nfault << "\n";
    printf("%-20s%-10d\n", name.c_str(), nfault);
}
