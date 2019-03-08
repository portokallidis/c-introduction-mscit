#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int is_operator(const char c) { return (c == '!' || c == '&' || c == '|'); }
int is_ident(const char c) { return (c == '0' || c == '1'); }

int op_preced(const char c) {
    // proteraiotita
    switch(c)    {
        case '|':
            return 3;
        case '&':
            return 2;
        case '!':
            return 1;
    }
    return 0;
}
int op_left_assoc(const char c) {
    switch(c)    {
        // left to right
        case '&': case '|':
            return 1;
        // right to left
        case '!':
            return 0;
    }
    return 0;
}
int op_arg_count(const char c) {
    switch(c)  {
        case '&': case '|':
            return 2;
        case '!':
            return 1;
    }
    return 0;
}

int expressionParser(const char *input, char *output) {
    const char *strpos = input, *strend = input + strlen(input);
    char c, *outpos = output;

    char stack[32];       // operator stack
    int sl = 0;  // stack length
    char     sc;          // used for record stack element

    while(strpos < strend)   {
        // read one token from the input stream
        c = *strpos;
        if(c != ' ')    {
            // If the token is a number (identifier), then add it to the output queue.
            if(is_ident(c))  {
                *outpos = c; ++outpos;
            }
            // If the token is an operator, op1, then:
            else if(is_operator(c))  {
                while(sl > 0)    {
                    sc = stack[sl - 1];
                    if(is_operator(sc) &&
                        ((op_left_assoc(c) && (op_preced(c) >= op_preced(sc))) ||
                           (op_preced(c) > op_preced(sc))))   {
                        // Pop op2 off the stack, onto the output queue;
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                    else   {
                        break;
                    }
                }
                // push op1 onto the stack.
                stack[sl] = c;
                ++sl;
            }
            // If the token is a left parenthesis, then push it onto the stack.
            else if(c == '(')   {
                stack[sl] = c;
                ++sl;
            }
            // If the token is a right parenthesis:
            else if(c == ')')    {
                int pe = 0;
                // Until the token at the top of the stack is a left parenthesis,
                // pop operators off the stack onto the output queue
                while(sl > 0)     {
                    sc = stack[sl - 1];
                    if(sc == '(')    {
                        pe = 1;
                        break;
                    }
                    else  {
                        *outpos = sc;
                        ++outpos;
                        sl--;
                    }
                }
                // If the stack runs out without finding a left parenthesis, then there are mismatched parentheses.
                if(!pe)  {
                    printf("Error: parentheses mismatched\n");
                    return 0;
                }
                // Pop the left parenthesis from the stack, but not onto the output queue.
                sl--;
                // If the token at the top of the stack is a function token, pop it onto the output queue.
                if(sl > 0)   {
                    sc = stack[sl - 1];
                }
            }
            else  {
                printf("Unknown token %c\n", c);
                return 0; // Unknown token
            }
        }
        ++strpos;
    }
    // When there are no more tokens to read:
    // While there are still operator tokens in the stack:
    while(sl > 0)  {
        sc = stack[sl - 1];
        if(sc == '(' || sc == ')')   {
            printf("Error: parentheses mismatched\n");
            return 0;
        }
        *outpos = sc;
        ++outpos;
        --sl;
    }
    *outpos = 0; // Null terminator
    return 1;
}

int evalBoolExpr(char * expr)  {
    char output[500] = {0};
    char * op;
    int tmp;
    char part1[250], part2[250];

    if(!expressionParser(expr, output))
      return 0;  // oops can't convert to postfix form

    while (strlen(output) > 1) {
        op = &output[0];
        while (!is_operator(*op) && *op != '\0')
          op++;
        if (*op == '\0') {
          return 0;  // oops - zero operators found
        }
        else if (*op == '!') {
            tmp = !(*(op-1) - 48);
            *(op-1) = '\0';
        }
        else if(*op == '&') {
            tmp = (*(op-1) - 48) && (*(op-2) - 48);
            *(op-2) = '\0';
        }
        else if (*op == '|') {
            tmp = (*(op-1) - 48) || (*(op-2) - 48);
            *(op-2) = '\0';
        }

        memset(part1, 0, sizeof(part1));
        memset(part2, 0, sizeof(part2));
        strcpy(part1, output);
        strcpy(part2, op+1);
        memset(output, 0, sizeof(output));
        strcat(output, part1);
        strcat(output, ((tmp==0) ? "0" : "1"));
        strcat(output, part2);
    }
    return *output - 48;
}
char *gate_replacer(char *input) {
    char *result; // the return string
    int count;    // number of chars in the input

    // sanity checks and initialization
    if (!input) return NULL;
    count = strlen(input);
    result = malloc(count+2);
    if (!result) return NULL;
    for(int i=0,j=0; i<count; i++,j++){
        if(input[i]=='A' && count>i+2 &&input[i+1]=='N' && input[i+2]=='D') {
            // A AND B => A & B 
            result[j]='&';
            i+=2;
            continue;
        } else if(input[i]=='N' && input[i+1]=='O' && input[i+2]=='T') {
            // NOT A => !A
            result[j]='!';
            i+=3;
            continue;
        } else if(input[i]=='O' && input[i+1]=='R') {
            // A OR B => A | B
            result[j]='|';
            i+=1;
            continue;
        } else {
            result[j]=input[i];
        }
    }
    return result;
}
char *var_replacer(char *input,char a , char b, char c) {
    char *result; // the return string
    int count;    // number of chars in the input

    // sanity checks and initialization
    if (!input) return NULL;
    count = strlen(input);
    result = malloc(count+2);
    if (!result) return NULL;
    for(int i=0; i<count; i++){
        if(input[i]=='A') {
            result[i]=a;
        } else if(input[i]=='B') {
            result[i]=b;
        } else if(input[i]=='C') {
            result[i]=c;
        } else {
            result[i] = input[i];
        }
    }
    return result;
}
int main(int argc, char *argv[]) {
    
    
    char *input;
    input = malloc(500);
    
    // input = "(A AND B) OR C";
    // input = "(A AND B) OR NOT C";
    // Works for infinite instances of A,B,C 
    // input = "(A AND B) OR (A AND (NOT B)) OR C";
    
    printf("\nEnter Function: ");
    scanf("%[^\n]s",input);
    
    char * result = gate_replacer(input);
    char * tmp = malloc(strlen(input));
        
    // printf("%s\n",result);
    
    for(int x=0; x<2; x++) {
        for(int y=0; y<2; y++) {
            for(int z=0; z<2; z++) {
            
                tmp = var_replacer(result,x+'0',y+'0',z+'0');
                printf("\n%d %d %d  %d",x,y,z,evalBoolExpr(tmp));
            }
        }
    }
    free(result);
    free(tmp);
    
	return 0;
}
