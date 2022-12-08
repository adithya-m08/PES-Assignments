module full_adder(input wire a, b, cin,output wire cout, sum);
	assign sum = a^b^cin;
	assign cout = (b&cin)|(a&cin)|(a&b);
endmodule

module xor2 (input wire i0, i1, output wire o);
  assign o = i0 ^ i1;
endmodule

module and2 (input wire i0, i1, output wire o);
  assign o = i0 & i1;
endmodule

module or2 (input wire i0, i1, output wire o);
  assign o = i0 | i1;
endmodule

module mux2 (input wire i0, i1, j, output wire o);
  assign o = (j==0)?i0:i1;
endmodule

module alu_slice(input wire cin,i0,i1,input wire [1:0]op,output wire o,cout);
	wire temp,o1,o2,o3,o4;
	
	xor2 x(i1,op[0],temp);
	full_adder f(i0,temp,cin,cout,o1);

	and2 a(i0,i1,o2);
	or2 orr(i0,i1,o3);

	mux2 m1(o2,o3,op[0],o4);
	mux2 m2(o1,o4,op[1],o);
endmodule
		 	
		
