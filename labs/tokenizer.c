#include <stdio.h>
#include <stdlib.h>
# define MAXLINE 1000

int getinput(char line[], int maxLine);
char** tokenize(char* str);
char* substring(char*start, int current, int previous);
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

