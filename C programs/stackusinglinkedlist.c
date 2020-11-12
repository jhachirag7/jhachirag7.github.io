#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{

    struct node *link;
    int data;
    };
struct node *p,*top;
void push(struct node *q,int num){
   struct node *temp;
   if(q==NULL){
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->link=NULL;
    p=temp;
    top=temp;
   }
   else{
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=num;
    temp->link=p;
    p=temp;
    top=temp;
   }

   }
void pop(struct node *q){
    if(q==NULL)
        printf("LIST DOES NOT EXIST");
    else{
            p=q->link;
            top=p;
    }

  }
void count(struct node *q){
      int c=0;
      if(q==NULL)
        printf("LIST DOES NOT EXIST");
      else{
        while(q!=NULL){
            c++;
            q=q->link;
        }
        printf("NUMBER OF NODES : %d\n",c);
      }

     }
void display(struct node *q){
      if(q==NULL)
        printf("LIST DOES NOT EXIST");
      else{
        while(q!=NULL){
            printf("%d ",q->data);
            q=q->link;
        }
      }

     }
int main(){
     int n,ch;
     p=NULL;
     top=NULL;
     do{
        printf("\n1.Push\n2.Pop\n3.Count\n4.Display\n5.Exit");
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d",&ch);
        switch(ch){
    case 1:
        printf("Enter a value: ");
        scanf("%d",&n);
        push(p,n);
        break;
    case 2:
        pop(p);
        getch();
        break;
    case 3:
        count(p);
        break;
    case 4:
        display(p);
        break;
        getch();
        }

     }while(ch!=5);
     }

