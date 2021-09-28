#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> // malloc & free
#include <stdint.h> // use guaranteed 64-bit integers
#include "tokenizer.h" // Create header file and reference that
#include "memory.h" // built-in functions to read and write to a specific file
#include <string.h> //ONLY USE strtok AND fgets
int32_t* reg; // Array of 32 32-bit registers
void init_regs();
bool interpret(char* instr);
void write_read_demo();
int count_tokens(char* str);

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

//TODO: ADD DESCRIPTION
int count_tokens(char* str){
    char c;
    int acc;
    while(*str != '\0'){
        if(*str == ' ')
          ++acc;
        ++str;
    }
    if (*str == '\0')
       ++acc;
    return acc;
}

/**
 * Fill out this function and use it to read interpret user input to execute RV64 instructions.
 * You may expect that a single, properly formatted RISC-V instruction string will be passed
 * as a parameter to this function.
 */
bool interpret(char* instr){
	//TODO: INSERT LOGIC OF INSTRUCTIONS
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
	
	//PRINTING POINTER ARRAY CONTENTS
	//BUG FOUND. LOOP GIVES SEGMENTATION FAULT
	for(int j = 0; j < t_count; ++j){
		
		printf("TOKEN[%d]: ",j);
		printf("%s\n", t[j]);
	}
	
	//TODO: FIX LOGIC;
	
	return true;
}


/**
 * Simple demo program to show the usage of read_address() and write_address() found in memory.c
 * Before and after running this program, look at mem.txt to see how the values change.
 * Feel free to change "data_to_write" and "address" variables to see how these affect mem.txt
 * Use 0x before an int in C to hardcode it as text, but you may enter base 10 as you see fit.
 */
void write_read_demo(){
	int32_t data_to_write = 0xFFF; // equal to 4095
	int32_t address = 0x98; // equal to 152
	char* mem_file = "mem.txt";

	// Write 4095 (or "0000000 00000FFF") in the 20th address (address 152 == 0x98)
	int32_t write = write_address(data_to_write, address, mem_file);
	if(write == (int32_t) NULL)
		printf("ERROR: Unsucessful write to address %0X\n", 0x40);
	int32_t read = read_address(address, mem_file);

	printf("Read address %lu (0x%lX): %lu (0x%lX)\n", address, address, read, read); // %lu -> format as an long-unsigned
}

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
	char line[MAXLINE];
	printf("Please enter the INSTRUCTION:\n");
    	printf("> ");
        bool complete;
    	//get user input
    	if(*fgets(line,MAXLINE,stdin)!= '\n'){
            printf("USER INPUT: %s",line);
            complete = interpret(line);
   	}
	return 0;
}
