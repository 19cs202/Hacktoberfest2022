#include<stdio.h>
#include<math.h>

int priority(char);
void intialize_stack();
void push(char );
char pop();
float evaluation(float ,float , char);
void postPush(float val);
float postPop();

struct Stack{
    char arr[30];
    float pFixArr[30];
    int top;
} stk;

struct Stack *stkPtr = &stk;

void main(){

    intialize_stack();
    char exp[30],postfix[30];
    char *e,ch;
    int i = 0;
    printf("Enter expression: ");
    scanf("%s", exp);
    e = exp;
    //Converting to postfix
    while(*e!='\0'){
       if(isalnum(*e))
           postfix[i++] = *e;
           else if(*e=='(')
               push(*e);
               else if(*e==')'){
                   while((ch=pop())!='('){
                      postfix[i++] = ch;
                   }
               }else{
                   while(priority(stkPtr->arr[stkPtr->top])>=priority(*e))
                       postfix[i++] = pop();
                   push(*e);
               }
                e++;
    }
    //leftover elements in the stack
    while (stkPtr->top != -1)
        postfix[i++] = pop();

    //Displaying
    printf("\nPostfix Expression : ");
    for (int k = 0; k < i;k++){
        printf("%c", postfix[k]);
    }
//Evalutaion
    intialize_stack();
    for (int k = 0; k < i;k++){
        if (isalnum(postfix[k])){
            float num = (float)(postfix[k] - '0');//Converting char value to float//ASCII value of '0'=48
            postPush(num);
            }
        else{
            float op2 = postPop();
            float op1 = postPop();
            float val = evaluation(op1, op2, postfix[k]);
            postPush(val);
            }
    }
    printf("\nValue = %.2f",stkPtr->pFixArr[stkPtr->top]);
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

void postPush(float val){
     stkPtr->top++;
     stkPtr->pFixArr[stkPtr->top] = val;
}

float postPop(){
    return stkPtr->pFixArr[stkPtr->top--];
}

float evaluation(float op1, float op2,char oper){
    if(oper=='+')
        return op1+op2;
        else if(oper=='-')
            return op1 - op2;
            else if(oper=='*')
                return op1 * op2;
                else if(oper=='/')
                    return op1/op2;
                     else if(oper=='^')
return pow(op1, op2);
}
