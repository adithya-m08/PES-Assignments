module TB;
reg aa,bb,cc;
wire ss,cy,hs,hc;
fulladd add1(.a(aa), .b(bb), .cin(cc), .sum(ss), .cout(cy));
halfadd add2(.a(aa),.b(bb),.ha(hs),.hca(hc));
initial
begin
$dumpfile("dump.vcd");
$dumpvars(0, TB);
end

initial begin $monitor(aa,bb,cc,ss,cy,hs,hc);
aa = 1'b0;
bb = 1'b0;
cc=1'b0;
#5
aa = 1'b0;
bb = 1'b1;
cc=1'b1;
#5
aa = 1'b1;
bb = 1'b0;
cc=1'b0;
#5
aa = 1'b1;
bb = 1'b1;
cc=1'b0;
#5
aa = 1'b0;
bb = 1'b0;
cc=1'b1;
end
endmodule


