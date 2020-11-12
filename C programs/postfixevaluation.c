#include<stdio.h>
#include<conio.h>
int checkoperand(char a)
{
    if((a>='0'&&a<='9'))
    {
        return 1;
    }
    else
        return 0;
}
int operators(char a)
{
    if(a=='^'||a=='*'||a=='+'||a=='-'||a=='/'){
        return 1;
    }
    return 0;
}
int main()
{
    char postfix[30];
    int stack[30];
    int top=-1;
    printf("Enter postfix: ");
    fgets(postfix,30,stdin);
    for(int i=0;postfix[i]!='\0';i++)
    {
     if(checkoperand(postfix[i])==1)
     {
         top++;
         stack[top]=0;
         while((postfix[i]!=' ') && (operators(postfix[i])==0))
        {

          stack[top]=stack[top]*10;
          stack[top]=stack[top]+((int)postfix[i]-48);
          i++;
         }
     }
     else if(operators(postfix[i-1])==1){
        int b=stack[top];
        top--;
        int a=stack[top];
        switch(postfix[i-1])
        {
            case '*':stack[top]=a*b;break;
            case '/':stack[top]=a/b;break;
            case '+':stack[top]=a+b;break;
            case '-':stack[top]=a-b;break;
        }
     }

    }
    printf("Postfix evaluation: %d",stack[top]);
}
