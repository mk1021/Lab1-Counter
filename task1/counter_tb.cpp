#include "Vcounter.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <iostream>

int main(int argc, char **argv, char **env) {
    int i; 
    //counts number of clock cycles to simulate
    int clk;
    //clk = clock signal
    int s;

    Verilated::commandArgs(argc, argv);
    
    // init top verilog instance
    // instantiate the counter module - this is a DUT
    // DUT = Device Under Testing
    Vcounter* top = new Vcounter;
    
    // init trace dump
    // turn on signal tracing and
    // tell Verilator to dump waverform data to counter.vcd
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    top->trace (tfp, 99);
    tfp->open ("counter.vcd");

    // initialize simulation inputs
    // top = top-level entity
    // only top-level signals are visible
    top->clk = 1;
    top->rst = 1;
    top->en = 0;

    // run simulation for many clock cycles
    for (i=0; i<100; i++) {

        //std::cout << int(top->count) << std::endl;

        // when count = 0x9, enable = off and clk is held for 3 cycles
        if (int(top->count) == 8) {
            s = int(i);
        }
        
        if (i==int(s)+1 || i==int(s)+2) {
            top->en = 0;
        }

        // dump variables into VCD file and toggle clock
        for(clk=0; clk<2; clk++) {
            tfp->dump (2*i+clk);
            top->clk = !top->clk;
            top->eval ();
        }

        top->rst = (i<2) | (i==30);
        top->en = (i>0);

        if (Verilated::gotFinish()) exit(0);
    }
    tfp->close();
    exit(0);
}