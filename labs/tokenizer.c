#include <stdio.h>
#include <stdlib.h>
#include <stdboo.h>
# define MAXLINE 1000

int getinput(char line[], int maxLine);
char** tokenize(char* str);
char* substring(char*start, int current, int previous);
char *word_start(char str);
char *end_word(char* str);
int count_token(char*str);
char *copy_str(char *intStr, short len);
void print_all_token(char** tokens);
int main(){
    int len;
    char line[MAXLINE]; /* current input line */
    printf("Please enter the input string:\n");
    printf("> ");
    
    while((len = getinput(line,MAXLINE))>0)
	//get one input string
	break;
    printf("Tokenizing %s\n",line);
    tokenize(line);
    return 0;
}


int getinput(char s[], int maxLine){
    int c, i;
    for(i = 0; (c=getchar()) != EOF && c!= '\n'; i++){
	if (i < maxLine)
	    s[i] = c;
    }
    if( c == '\n'){
        s[i] = c;
        ++i;
    }
    if(i >= maxLine)
        s[999] = '\0';
    else
        s[i] = '\0';
    return i;
}



//TODO: Fix tokenizer problem (tok not being Hi in Hi There)
//substituted space with _ for testing purposes
char** tokenize(char* str){
    char* start;
    char* tok;
    char ** token;

    /*
    printf("%c\n",*str);
    printf("%c\n",**token);
    */
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

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').
   Zero terminators are not printable (therefore false) */
bool delim_character(char c){

}

/* Return true (non-zero) if c is a non-whitespace
   character (not tab or space).
   Zero terminators are not printable (therefore false) */
bool non_delim_character(char c){

}

/* Returns a pointer to the first character of the next
   space-separated word*/
char *word_start(char* str){

}

/* Returns a pointer to the first space character of the zero
terminated string*/
char *end_word(char* str){

}
// counts the number of words or tokens
int count_tokens(char* str){


}
/* Returns a freshly allocated zero-terminated vector of freshly allocated
   space-separated tokens from zero-terminated str.
   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string"
     tokens[3] = 0
*/
char *copy_str(char *inStr, short len){

}

char** tokenize(char* str){
}


void print_all_tokens(char** tokens){
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
