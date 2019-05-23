package com.company.main;

public class Main {

    static Integer NUMBER_OF_REGISTER = 5;
    static Integer[] regs = new Integer[NUMBER_OF_REGISTER];
    static int[] build_vm = {0x1032, 0x11C8, 0x2201, 0x3120, 0x4112, 0x5212, 0x6000, 0x0000};
    static int counter = 0;
    static int instNum = 0;
    static Boolean running = true;
    static int r0 = 0;
    static int r1 = 0;
    static int r2 = 0;
    static int imm = 0;

    public static int instruction_counter() {
        return build_vm[counter++];
    }

    public static void decode_instruction(int instr) {
        instNum = (instr & 0xF000) >> 12;
        r0 = (instr& 0xF00) >> 8;
        r1 = (instr& 0xF0) >> 4;
        r2 = (instr& 0xF);
        imm = (instr& 0xFF);
    }

    public static void statement_execution() {
        switch (instNum) {
            case 0:
                running = false;
                break;
            case 1:
                regs[r0] = imm;
                break;
            case 2:
                regs[r0] = regs[r1] + regs[r2];
                break;
            case 3:
                regs[r0] = regs[r1] - regs[r2];
                break;
            case 4:
                regs[r0] = regs[r1] * regs[r2];
                break;
            case 5:
                regs[r0] = regs[r1] / regs[r2];
                break;
            case 6:
                for (int i = 0; i < NUMBER_OF_REGISTER; ++i)
                {
                    regs[i] = 0;
                }
        }
    }

    public static void start_vm() {
        while (running) {
            int instr = instruction_counter();
            decode_instruction(instr);
            statement_execution();
        }
    }

    public static void main(String[] args) {
	    start_vm();
    }
}
