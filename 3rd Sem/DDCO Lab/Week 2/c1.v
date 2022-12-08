module fulladd(input wire a,b,cin,output wire sum,cout);
	wire t;
	assign t = a^b;
	assign sum = t^cin;
	assign cout = (a&b)|(b&cin)|(a&cin);
	endmodule
module halfadd(input wire a,b,output wire ha,hca);
	assign ha = a^b;
	assign hca = a&b;
	endmodule	

