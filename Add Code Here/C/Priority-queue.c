//Priority queue

#include<stdio.h>
#define MAX 5
int n,p,ch,q[MAX],flag=0,f=0,r=0,i,b[MAX];
int main()
{
    printf("Priority queue\n\n1.Enqueue\n2.Dequeue\n3.Exit");

    while(ch!=3)
    {
        printf("\n\nChoose operation:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            enq();
            display();
            break;
        case 2:
            dq();
            display();
            break;
        case 3:
            break;
        default:
            printf("Invalid Selection\n");
        }
    }
    return 0;
}
int enq()
{
 if(r==0)
    {printf("Enter element and it's priority:");
    scanf("%d%d",&n,&p);
        f=r=1;
        q[r]=n;
        b[r]=p;
    }
    else if(r==MAX)
       { printf("Queue is full");
          flag=1;
        return 0;
        }
     else
    {    printf("Enter element and it's priority:");
    scanf("%d%d",&n,&p);
        r=r+1;
        q[r]=n;
        b[r]=p;
    }
    if(r>1)
    {
        int k,t,s,j;
        j=r;
        t=b[j];
        s=q[j];
        k=j-1;
        while((t>b[k])&&(k>=1))
        {
            b[k+1]=b[k];
            q[k+1]=q[k];
            k=k-1;
        }
        b[k+1]=t;
        q[k+1]=s;
    }
}
int display()
{
    if(f==0)
    {
        printf("Queue is empty\n");
        return 0;
    }
    
    else if(flag==1)
    {
    return 0;
    flag=0;
    }
    if(r>=f)
    {    printf("\nQueue\n");
        for(i=f; i<=r; i++)
            printf("\nElement = %d\tPriority = %d",q[i],b[i]);
    }
}
void dq()
{
    if(f==r)
    {
        printf("Deleted element : %d\tPriority = %d\n",q[f],b[f]);
        
        f=0;
        r=0;
    }
    else
    {
        printf("Deleted element : %d\tPriority = %d\n",q[f],b[f]);
        f=f+1;
    }
}
