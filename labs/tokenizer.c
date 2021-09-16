#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
# define MAXLINE 1000


char** tokenize(char* str);
char *word_start(char* str);
char *end_word(char* str);
int count_token(char*str);
char *copy_str(char *intStr, short len);
void print_all_tokens(char** tokens);


int main(){
    printf("Here");
    char ** start;
    int len;
    char line[MAXLINE]; /* current input line */
    printf("Please enter the input string:\n");
    printf("> ");
    //get user input
    fgets(line,MAXLINE,stdin);
    printf("USER INPUT: %s",line);
    start = tokenize(line);
    printf("HERE");
    print_all_tokens(start);
    return 0;
}

//TODO: Fix tokenizer problem (tok not being Hi in Hi There)
//substituted space with _ for testing purposes
/**
char** tokenize(char* str){
    char* start;
    char* tok;
    char ** token;

    
    //printf("%c\n",*str);
    //printf("%c\n",**token);
    
    int i,previous;
    previous = 0;
    start = str;
    for(i = 0; *str != '\0'; ++i){
        if (*str == '_'){    
            tok = substring(start,i,previous);
            token = &tok;
            //print token
	    previous = i;
	}
	++str;
        start = str;
    }
    //case for last word/token
    
    printf("Current position of Token: %s\n",*token);
    printf("Current poistion of Start: %s\n",start);
    printf("Current position of tok: %s\n",tok);
    return token;
}
**/

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
    return c != ' ' || c != '\t';
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
    int t_count,sub_length;
    t_count = count_tokens(str);
    //Initialize token array here?
    char **ptr = malloc(t_count*sizeof(char*)); //[. . .]
    char **initial = ptr[0];
    //initial
    start = str;
    while(*str != '\0'){
        //update end
        if(delim_character(*str)){
		end = end_word(start);
		sub_length = (end - start) + 1;
		//printf("%s",start);
		printf("Current Sub String length: %d\n",sub_length);
	        //store this to a token
		current_string = copy_str(start,sub_length);
                ptr = current_string;
		printf("CURRENT SUB STRING: %s\n",current_string);
	        //update start
	        start = str+1;
	        //next
	        str = start;
		++ptr;
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
        ptr = current_string;
    }
    printf("Current Sub String length:%d\n",sub_length);
    printf("CURRENT SUB STRING:%s\n",current_string);
    
    return initial;
}


void print_all_tokens(char** tokens){
    int i;
    i = 0;
    printf("Here");
    //printf("%s",tokens);
}


/*
char* substring(char* start, int current,int previous){
    char* temp = start;
    
    char* new_string = (char*) malloc(current-previous*sizeof(char));
    char* first = new_string;
    while( (*new_string = *temp) != '\0'){
        ++new_string;
        ++temp;
        
    }
    new_string = first;

    return new_string;
}
*/
