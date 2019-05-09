
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transferHex.h"

#define NUMBER_OF_REGISTER 5

int regs[NUMBER_OF_REGISTER];
int build_vm[] = {0x1032, 0x11C8, 0x2201, 0x3120, 0x4112, 0x5212, 0x6000, 0x0000};

int counter = 0;
int instrNum = 0;

int r0 = 0;
int r1 = 0;
int r2 = 0;
int imm = 0;

unsigned int firstValue;
unsigned int secondValue;

int running = 1;


int instruction_counter()
{
	return build_vm[counter++];
}


void decode_insruction(int instr)
{
	instrNum = (instr& 0xF000) >> 12;
	r0 = (instr& 0xF00) >> 8;
	r1 = (instr& 0xF0) >> 4;
	r2 = (instr& 0xF);
	imm = (instr& 0xFF);
}


void statement_execution()
{
	printf("Instruction %d\n", instrNum);
	printf("Registers = [%d, %d, %d];   r0 = %d; r1 = %d; r2 = %d;\n", regs[r0], regs[r1], regs[r2], r0, r1, r2);
	switch (instrNum)
	{
		case 0:
			printf("\n%s\n", "Stopping VM!");
			running = 0;
			break;
		case 1:
			regs[r0] = imm;
			printf("LOADI r%d #%d\n", r0, imm);
			break;
		case 2:
			regs[r0] = regs[r1] + regs[r2];
			printf("ADD r%d r%d r%d\nResult: %d\n", r0, r1, r2, regs[r0]);
			break;
		case 3:
			regs[r0] = regs[r1] - regs[r2];
			printf("SUB r%d r%d r%d\nResult: %d\n", r0, r1, r2, regs[r0]);
			break;
		case 4:
			regs[r0] = regs[r1] * regs[r2];
			printf("MULT r%d r%d r%d\nResult: %d\n", r0, r1, r2, regs[r0]);
			break;
		case 5:
			regs[r0] = regs[r1] / regs[r2];
			printf("DIV r%d r%d r%d\nResult: %d\n", r0, r1, r2, regs[r0]);
			break;
		case 6:
			for (int i = 0; i < NUMBER_OF_REGISTER; ++i)
			{
				regs[i] = 0;
			}
			printf("Reset memory done\n");
	}
	printf("\n");
}


void startVM()
{
	while (running)
	{
		int instr = instruction_counter();
		decode_insruction(instr);
		statement_execution();
	}
}


int checkRange()
{
	if (firstValue <= 255 && secondValue <= 255) return 1;
	return 0;
}


void addInstructions()
{
	firstValue = hexreverse(F(firstValue));
	secondValue = hexreverse(F(secondValue));
	build_vm[0] = 0x1000 + firstValue;
	build_vm[1] = 0x1100 + secondValue;
}


int main(int argc, char const *argv[])
{
	system("cls");
	system("color 0a");
	printf("%s\n", "Virtual Machine NL-1\n\n");
	printf("%s\n", "Max value 255 for input");
	printf("%s", "First number: ");
	scanf("%u", &firstValue);
	printf("%s", "Second number: ");
	scanf("%u", &secondValue);	
	if (checkRange() == 1)
	{
		addInstructions();
		startVM();
	} else printf("%s\n", "Error! Out of range >255");
	system("pause > nul");
	return 0;
}