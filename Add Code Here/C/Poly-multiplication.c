#include<stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int pow;
    struct node *next;
};
typedef struct node *NODE;

NODE add_node(NODE p, int coeff, int pow);
NODE multiply(NODE a, NODE b);
NODE sop(NODE res, int coeff, int pow);
void display(NODE p);

void main(){
    NODE A = NULL, B = NULL, C = NULL;
    int coeff, n1, n2;
    char ch;
    printf("\nEnter the highest order of 1st Polynomial  : ");
    scanf("%d", &n1);
    for (int i = n1; i >=0;i--){
        printf("\nEnter coefficient of x^%d : ", i);
        scanf("%d", &coeff);
        A = add_node(A, coeff, i);
    }
    printf("\nEnter the highest order of 2nd Polynomial  : ");
    scanf("%d", &n2);
    for (int i = n2; i >=0;i--){
        printf("\nEnter coefficient of x^%d : ", i);
        scanf("%d", &coeff);
        B = add_node(B, coeff, i);
    }
    printf("\n1st : ");
    display(A);
    printf("\n2nd : ");
    display(B);
    printf("\nPRODUCT : ");
    C=multiply(A, B);
    display(C);
}

NODE add_node(NODE p,int coeff,int pow){
    NODE temp, current;
    temp=malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->pow = pow;
    temp->next = NULL;
    if(p==NULL)
        return temp;

    current = p;
    while(current->next!=NULL){//Traversing
        current = current->next;
    }
    current->next = temp;
    return p;
}
void display(NODE p){
    if(p==NULL){
        printf("Empty!");
        return;
    }
    NODE temp=p;
    while(temp->next!=NULL){
        printf("%dX^%d ", temp->coeff, temp->pow);
        if((temp->next)->coeff>=0)
            printf("+");
        temp = temp->next;
    }
    printf("%dX^%d", temp->coeff, temp->pow);
}
NODE multiply(NODE a,NODE b){
    NODE poly1=a, poly2=b, poly = NULL;
    int coeff, pow;
    while(poly1!=NULL){
        while(poly2!=NULL){
            coeff = poly1->coeff * poly2->coeff;
            pow = poly1->pow + poly2->pow;
            poly = sop(poly, coeff, pow);
            poly2 = poly2->next;
        }
        poly2 = b;
        poly1 = poly1->next;
    }
    return poly;
}
NODE sop(NODE res,int coeff,int pow){
    NODE temp,current;
    int flag = 0;//to know whether a term with same power exists
    temp = malloc(sizeof(struct node));
    temp->coeff = coeff;
    temp->pow = pow;
    temp->next = NULL;
    if(res==NULL)
        return temp;
    current = res;
    while(current!=NULL){
        if(current->pow==pow){//Summing up coefficients of terms with same power
            current->coeff = current->coeff + coeff;
            flag = 1;
        }
        current = current->next;
    }
if(flag==0){
    current = res;
    while(current->next!=NULL)
        current = current->next;
    current->next = temp;
}
return res;
}
