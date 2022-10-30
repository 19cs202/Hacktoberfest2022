
//prefix
#include<stdio.h>

int priority(char);
void intialize_stack();
void push(char );
char pop();

struct Stack{
    char arr[308];
    int top;
} stk;

struct Stack *stkPtr = &stk;

void main(){
    intialize_stack();
    char exp[370];
    char *e,ch;
    char rev[360];
    char prefix[360];
    int i = 0,r=0 ,n = 0;
    printf("Enter expression : ");
    scanf("%s", exp);
    e = exp;
    //counting the no.of elements
    while(*e!='\0'){
        n++;
        e++;
    }
 //reversing
    while (n > 0)
    {
        rev[r++] = exp[n-1];
        n--;
        }
        rev[r] = '\0';
        e =rev;
       
       //Converting to prefix 
    while(*e!='\0'){
       if(isalnum(*e))
           prefix[i++] = *e;
           else if(*e==')')
               push(*e);
               else if(*e=='('){
                   while((ch=pop())!=')'){
                       prefix[i++] = ch;
                   }
               }else{
                   while(priority(stkPtr->arr[stkPtr->top])>priority(*e))
                      prefix[i++] = pop();
                      
                   push(*e);
               }
                e++;
    }
               while(stkPtr->top!=-1)
                   prefix[i++] = pop();
            
            //Displaying in reverse order
               printf("Prefix Expression : ");
               while(i>0){
                  printf("%c", prefix[i-1]);
                i--;
               }
}
int priority(char ch){
    switch(ch){
        case '(' :
        case ')' :
            return 0;
        case '+' :
        case '-' :
            return 1;
        case '*' :
        case '/' :
        case '%' :
            return 2;
        case '^' :
            return 3;
    }
}
void intialize_stack(){
    stkPtr->top = -1;
}
void push(char val){

    stkPtr->top++;
    stkPtr->arr[stkPtr->top] = val;
        
}
char pop(){
           return stkPtr->arr[stkPtr->top--];
}
