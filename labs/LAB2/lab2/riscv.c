#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // malloc & free
#include <stdint.h> // use guaranteed 64-bit integers
#include "tokenizer.h" // Create header file and reference that
#include "memory.h" // built-in functions to read and write to a specific file
#include <string.h> //ONLY USE strtok AND fgets
int32_t* reg; // Array of 32 32-bit registers
void init_regs();
void print_regs();
bool interpret(char* instr);
void write_read_demo();

//int count_tokens(char* str);

bool equals(char* instr, char* match);
int parse_register(char* p);

void add_instruct(char* sum, char* op1, char* op2);
void addi_instruct(char* sum, char* op1, char* op2);
#define MAXLINE 1000
/**
 * Initialize register array for usage.
 * Malloc space for each 32-bit register then initializes each register to 0.
 * Do not alter this function!
 */
void init_regs(){
	int reg_amount = 32;
	reg = malloc(reg_amount * sizeof(int32_t)); // 32 * 4 bytes
	for(int i = 0; i < 32; i++)
		reg[i] = i;
}

//TODO: ADD DESCRIPTION (PLAN B)
/*
int count_tokens(char* str){
    char c;
    int acc;
    acc = 0;
    while(*str != '\0'){
        if(*str == ' ')
          ++acc;
        ++str;
    }
    if (*str == '\0')
       ++acc;
    return acc;
}
*/
/**
 * Fill out this function and use it to read interpret user input to execute RV64 instructions.
 * You may expect that a single, properly formatted RISC-V instruction string will be passed
 * as a parameter to this function.
 */
bool interpret(char* instr){
	bool valid = false;
	/* 
	//THIS IS MY PLAN B
	int t_count;
	t_count = count_tokens(instr);
	//FILL POINTER ARRAY WITH TOKENS
	char ** t = malloc(t_count*sizeof(char*));
        int i;
	i = 0;
	///first token
	char * token = strtok(instr, " ");
	//get rest of tokens
	while(token != NULL && i != t_count){
		//update new token
		t[i] = token;
		//
		token = strtok(NULL, " ");
		// update your position of pointer array
		++i;
	}
	*/
	//PRINTING POINTER ARRAY CONTENTS
	//PART OF PLAN B
	//for(int j = 0; j < t_count; ++j){
	//	printf("TOKEN[%d]: ",j);
	//	printf("%s\n", token[j]);
	//}

	//TODO: Insert logic of Instructions
	char** token = tokenize(instr);

	
	//TODO: Add check to validate if it is a valid instruction
	//Try to do string comparisons first
	if (equals(token[0],"ADD")){
	    //do logic
		printf("ADD LOGIC\n");
		add_instruct(token[1],token[2],token[3]);
		print_regs();
		valid = true;
	}
	
	else if (equals(token[0],"ADDI")){
	            //do logic
		printf("ADDI LOGIC\n");
		addi_instruct(token[1],token[2],token[3]);
		print_regs();
		valid = true;
	}
	
	else if(equals(token[0], "LW")){
		printf("LW LOGIC");
	}
	
	else if(equals(token[0], "SW")){
		printf("SW LOGIC");
	}
	//EXTRA CREDIT

	
	
	return valid;
}

//CHECK OF USE CASES
//parsing an add instruction
void add_instruct(char* sum, char* op1, char* op2){
	int32_t address, op1_address, op2_address;
	//ADDRESSES FOR REGISTERS as integers 
	address = (int32_t) parse_register(sum);
	op1_address =(int32_t)  parse_register(op1);
	op2_address = (int32_t) parse_register(op2);
	//NOW TO USE REG ARRAY (using read_address and write_address)
	int32_t data_to_write = reg[op1_address] + reg[op2_address];
	//UPDATE CONTETNS OF ADDRESS
	reg[address] = data_to_write;
}

void addi_instruct(char* sum, char* op1, char* op2){

        int32_t address, op1_address, immediate;

        //ADDRESSES FOR REGISTERS as integers
        address = (int32_t) parse_register(sum);
        op1_address =(int32_t)  parse_register(op1);
        immediate = (int32_t) parse_register(op2);

        //NOW TO USE REG ARRAY (using read_address and write_address)
        int32_t data_to_write = reg[op1_address] + immediate;
        reg[address] = data_to_write;
}

//TODO: ADD DESCRIPTION
// *p => int
int parse_register(char* p){
	char* copy_number = p;
	//START AT NUMBER IF USING REGISTER
	if(*p == 'X')
		p = p + 1;
	//SAVE WHERE YOU STARTED
	char* s = copy_number;
	while((*copy_number = *p) != '\0'){
		++copy_number;
		++p;
	}
	//GO PACK TO THE START OF YOUR NEW STRING
	copy_number = s;
	//have to atoi function get you the integer
	int reg = atoi(copy_number);
	return reg;
}


//TODO: Add Description
bool equals(char* instr, char* match){
	while(*instr == *match){ 
		++instr;
		++match;
	}
	//if(*instr+1 == '\n'){printf("THIS IS A NOT NULL TERMINATOR\n");}
	if(*instr != '\0'){
		return false;
	}
	return true;
}


/**
 * Simple demo program to show the usage of read_address() and write_address() found in memory.c
 * Before and after running this program, look at mem.txt to see how the values change.
 * Feel free to change "data_to_write" and "address" variables to see how these affect mem.txt
 * Use 0x before an int in C to hardcode it as text, but you may enter base 10 as you see fit.
 */
/**/
void write_read_demo(){
	//REG 
	int32_t data_to_write = 69; // equal to 4095
	int32_t address = 2; // equal to 152
	char* mem_file = "mem.txt";

	// Write 4095 (or "0000000 00000FFF") in the 20th address (address 152 == 0x98)
	int32_t write = write_address(data_to_write, address, mem_file);
	//reg[address] = write_address(data_to_write, address, mem_file);
	if(write == (int32_t) NULL)
		printf("ERROR: Unsucessful write to address %0X\n", 0x40);
	int32_t read = read_address(address, mem_file);

	printf("Read address %lu (0x%lX): %lu (0x%lX)\n", address, address, read, read); // %lu -> format as an long-unsigned
}

/**
 * Prints all 32 registers in column-format
 */
void print_regs(){
    int col_size = 10;
    for(int i = 0; i < 8; i++){
        printf("X%02i:%.*lld", i, col_size, (long long int) reg[i]);
        printf(" X%02i:%.*lld", i+8, col_size, (long long int) reg[i+8]);
        printf(" X%02i:%.*lld", i+16, col_size, (long long int) reg[i+16]);
        printf(" X%02i:%.*lld\n", i+24, col_size, (long long int) reg[i+24]);
    }
}
/**/
/**
 * Your code goes in the main
 *
 */
//TODO: MAIN WILL BE PROVIDED BY STEVEN
int main(){
	
	// Do not write any code between init_regs
	init_regs(); // DO NOT REMOVE THIS LINE
	// Below is a sample program to a write-read. Overwrite this with your own code.
	write_read_demo();
	print_regs();
	char line[MAXLINE];
	printf("Please enter the INSTRUCTION:\n");
    	printf("> ");
        bool complete;
	complete = false;
	
    	//get user input
    	if(*fgets(line,MAXLINE,stdin)!= '\n'){
            printf("USER INPUT: %s",line);
            complete = interpret(line);
   	}
	return 0;
}
