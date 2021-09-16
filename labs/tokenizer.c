#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# define MAXLINE 1000


char** tokenize(char* str);
char *word_start(char* str);
char *end_word(char* str);
int count_token(char*str);
char *copy_str(char *intStr, short len);
void print_all_tokens(char** tokens,int length);


int main(){
    
    char ** start;
    int len;
    char line[MAXLINE]; /* current input line */
    printf("Please enter the input string:\n");
    printf("> ");
    //get user input
    if(*fgets(line,MAXLINE,stdin)!= '\n'){
	    printf("USER INPUT: %s",line);
	    start = tokenize(line);
   }
    return 0;
}


/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
bool delim_character(char c){
    
    return c == ' ' || c == '\t';
}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c){
    return c != ' ' || c != '\t' || c != '\0';
}



/* Returns a pointer to the first character of the next
   space-separated word*/
char *word_start(char* str){
    char* s = str;
    while(non_delim_character(*s)){
	if(delim_character(*s))
	    break;
        ++s;
    }
    return s + 1;
}
/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str){
    char* s = str;
    while(non_delim_character(*s)){
	if(delim_character(*s))
	    break;
        ++s;
    }
    return s;
}

// counts the number of words or tokens
int count_tokens(char* str){
    char c;
    int acc;
    while(*str != '\0'){
        if(delim_character(*str))
	  ++acc;
        ++str;
    }
    if (*str == '\0')
       ++acc;
    return acc;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
inStr is start i believe
*/
char *copy_str(char *inStr, short len){
    char* new_string = (char*) malloc(len*sizeof(char));
    char* s = new_string;
    
    while((*new_string = *inStr) != ' '){
        ++inStr;
        ++new_string;
    }

    *new_string ='\0';
    //Go back to the intial character of the tokenized string
    new_string = s;
    return new_string;
}

char** tokenize(char* str){
    
    char** dummy;
    char* start;
    char* end;
    char c;
    char* current_string;
    int t_count,sub_length, i,count_space;
    t_count = count_tokens(str);
    //Initialize token array here?
    char **ptr = malloc(t_count*sizeof(char*)); //[. . .]
    char **initial = ptr;
    //initial
    start = str;
    i = 0;
    
    while(*str != '\0'){
        if(delim_character(*str)){
		//update end
		end = end_word(start);
		sub_length = (end - start) + 1;
		//printf("%s",start);
		printf("Current Sub String length: %d\n",sub_length);
	        //store this to a token
		current_string = copy_str(start,sub_length);
                ptr[i] = current_string;
		printf("CURRENT SUB STRING: %s\n",current_string);
	        //update start
	        start = word_start(str);
	        //next
	        str = start;
		++i;
	}
        ++str;
    }
    //last set of characters
    if(*str == '\0'){
	end = str;
        printf("%s\n",end);
	sub_length = end - start;
        //store
	current_string = copy_str(start,sub_length);
        ptr[i] = current_string;
    }
    printf("Current Sub String length:%d\n",sub_length);
    printf("CURRENT SUB STRING:%s\n",current_string);
    print_all_tokens(initial,t_count);
    return initial;
}


void print_all_tokens(char** tokens,int length){
    int i;
    i = 0;
    
    for(i = 0; i< length; ++i){
    	printf("Tokens[%d]: %s\n",i,tokens[i]);
    }
}



