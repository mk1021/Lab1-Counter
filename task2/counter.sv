module counter #(
    parameter WIDTH = 8
)(
    //interface signals
    input logic             clk,    // clock
    input logic             rst,    // reset
    input logic             en,     // counter enable
    output logic [WIDTH-1:0] count   // counter output
    //           [7:0] (WIDTH-1)=7
);

always_ff @ (posedge clk)
    if (rst) count <= {WIDTH{1'b0}};
    else    count <= count + {{WIDTH-1{1'b0}}, en}; //{} and , means concatenate     

always_ff @ (posedge clk)
    if (!rst && !en) count <= count - {{WIDTH-1{1'b0}},1};
endmodule

//challenge - if en=0 want to decrement (count down)