#include<stdio.h>
int checkoperand(char a)
{
    if((a>='a'&& a<='z') || (a>='A' && a<='Z')||(a>='0'&&a<='9'))
    {
        return 1;
    }
    else
        return 0;
}
int priority(char x)
{
    if(x=='^')
        return 3;
    else if(x=='*'|| x=='/')
        return 2;
    else if(x=='+'||x=='-')
        return 1;
    else
        return 0;
}
int main()
{
    char stack[30],infix[30],postfix[30];
    int top=-1,top1=-1;
    fgets(infix,30,stdin);
    for(int i=0;infix[i]!='\0';i++)
    {
        if(infix[i]=='(')
        {
            top++;
            stack[top]=infix[i];
        }
        else if(checkoperand(infix[i])==1)
        {
            top1++;
            postfix[top1]=infix[i];
        }
        else if(top==-1)
        {
              top++;
              stack[top]=infix[i];
        }
        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                top1++;
                postfix[top1]=stack[top];
                top--;
            }
            top--;
        }
        else if(priority(infix[i])>=priority(stack[top]))
        {
            top++;
            stack[top]=infix[i];
        }
        else if(priority(infix[i])<priority(stack[top]))
        {
           while(top!=-1 && stack[top]!='(')
           {
               top1++;
               postfix[top1]=stack[top];
               top--;
           }
           top++;
           stack[top]=infix[i];
        }

    }
        while(top!=-1)
        {
            top1++;
            postfix[top1]=stack[top];
            top--;
        }
        postfix[top1+1]='\0';
    puts(postfix);
    return 0;
}
