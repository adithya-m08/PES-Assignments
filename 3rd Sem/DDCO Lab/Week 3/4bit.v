module fulladdR(input wire a,b,cin,output wire sum,cout);
	wire t;
	assign t = a^b;
	assign sum = t^cin;
	assign cout = (a&b)|(b&cin)|(a&cin);
endmodule


module r_c_addr(input wire [3:0] a,input wire [3:0]b, input wire cin, output wire [3:0] s, output wire cout);
	wire [2:0]c;
	fulladdR f_0(a0,b0,cin,s0,c0);
	fulladdR f_1(a1,b1,c0,s1,c1);
	fulladdR f_2(a2,b2,c1,s2,c2);
	fulladdR f_3(a3,b3,c2,s3,cout);
endmodule
