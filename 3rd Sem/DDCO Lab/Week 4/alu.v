module alu (input wire [1:0] op, input wire [15:0] i0, i1,output wire [15:0] o, output wire cout);
	wire [14:0]c;

	alu_slice a0(op[0],i0[0],i1[0],op,o[0],c[0]);
	alu_slice a1(c[0],i0[1],i1[1],op,o[1],c[1]);
	alu_slice a2(c[1],i0[2],i1[2],op,o[2],c[2]);
	alu_slice a3(c[2],i0[3],i1[3],op,o[3],c[3]);
	alu_slice a4(c[3],i0[4],i1[4],op,o[4],c[4]);
	alu_slice a5(c[4],i0[5],i1[5],op,o[5],c[5]);
	alu_slice a6(c[5],i0[6],i1[6],op,o[6],c[6]);
	alu_slice a7(c[6],i0[7],i1[7],op,o[7],c[7]);
	alu_slice a8(c[7],i0[8],i1[8],op,o[8],c[8]);
	alu_slice a9(c[8],i0[9],i1[9],op,o[9],c[9]);
	alu_slice a10(c[9],i0[10],i1[10],op,o[10],c[10]);
	alu_slice a11(c[10],i0[11],i1[11],op,o[11],c[11]);
	alu_slice a12(c[11],i0[12],i1[12],op,o[12],c[12]);
	alu_slice a13(c[12],i0[13],i1[13],op,o[13],c[13]);
	alu_slice a14(c[13],i0[14],i1[14],op,o[14],c[14]);
	alu_slice a15(c[14],i0[15],i1[15],op,o[15],cout);
endmodule
