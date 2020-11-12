#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int x=20/2,y=20/2,fruitx,fruity,flag,score=0,gameover=0,ct=0,tailx[100],taily[100];
void setup()
{

    lable1:
    fruitx=rand()%20;
    if(fruitx==0)
        goto lable1;
    lable2:
    fruity=rand()%20;
    if(fruity==0)
        goto lable2;

}
void draw()
{
    system("cls");
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {

            if(i==0 || j==0 || j==20-1 || i==20-1)
                printf("#");
            else{
                    if(i==x && j==y)
                       printf("O");
                     else if(i==fruitx && j==fruity)
                        printf("F");
                  else{
                        int c=0;
                        for(int k=0;k<ct;k++)
                        {
                            if(i==tailx[k] &&j==taily[k])
                            {
                                printf("o");
                               c=1;
                            }
                        }
                   if(c==0)
                printf(" ");
                  }
            }

        }
        printf("\n");

    }
    printf("SCORE=%d",score);

}
void input()
{

    if(kbhit())
    {

        switch(getch())
        {
        case 'w':
            flag=1;
            break;
        case 's':
            flag=2;
            break;
        case 'a':
            flag=3;
            break;
        case 'd':
            flag=4;
            break;
        }
    }
}
void logic()
{
    int px=tailx[0];
    int py=taily[0];
    int px2,py2;
    tailx[0]=x;
    taily[0]=y;
    for(int i=1;i<ct;i++)
    {
        px2=tailx[i];
        py2=taily[i];
        tailx[i]=px;
        taily[i]=py;
        px=px2;
        py=py2;
    }
    switch(flag)
    {

    case 1:
        x--;
        break;
    case 2:
        x++;
        break;
    case 3:
        y--;
        break;
    case 4:
        y++;
        break;
    default :
        break;
    }
    if(x<0||y<0||x>20||y>20)
    {
        gameover=1;
    }
    for(int i=0;i<ct;i++)
    {
        if(x==tailx[i] && y==tailx[i])
            gameover=1;
    }
    if(x==fruitx && y==fruity)
    {
    setup();
    score+=10;
    ct++;
        }
}
int main()
{
    setup();
    while(!gameover)
    {
    draw();
    input();
    logic();
    for(int i=0;i<10000;i++){
        for(int j=0;j<10000;j++){}
    }
    }

    return 0;
}