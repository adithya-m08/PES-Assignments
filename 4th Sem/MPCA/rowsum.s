.DATA
	MAT: .WORD 1, 2, 3, 4, 5, 6, 7, 8, 9
	SUM: .WORD

.TEXT
	LDR R5,=MAT
	LDR R6,=SUM
	MOV R0, #3

LOOP:
	LDMIA R5,{R2-R4}
	ADD R5,R5,#12
	ADD R2,R2,R3
	ADD R2,R2,R4
	STR R2,[R6],#4
	SUB R0,R0,#1
	TEQ R0,#0   
	BNE LOOP
	SWI 0X11    