module mux4 (input wire [0:3] i, input wire j1, j0, output wire o);
  wire  t0, t1;
  mux2 m0 (i[0], i[1], j1, t0);
  mux2 m1 (i[2], i[3], j1, t1);
  mux2 m2 (t0, t1, j0, o);
endmodule
