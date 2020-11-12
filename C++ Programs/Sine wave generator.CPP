#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#define HEIGHT getmaxx()
#define WIDTH getmaxy()
#define pi 3.141592
int t=0,f,A;
int isContinue=1,phi=0;
void soundwave()
{  setcolor(RED);
double y=0;
   line(0,150,0,350);
   setcolor(2);
   line(0,WIDTH/2,HEIGHT,WIDTH/2);
  for(double x=0;x<=HEIGHT;x+=1){
      y=A*sin((t+phi)*pi/180);
     y=WIDTH/2-y;
     putpixel(x,y,15);
     delay(10);
     t+=4;
     }
}
void get()
{
    printf("ENTER FREQUENCY OF THE WAVE: ");
    scanf("%d",&f);
    printf("ENTER AMPLITUDE OF THE WAVE: ");
    scanf("%d",&A);
    printf("ENTER PHASE DIFFERENCE: ");
    scanf("%d",&phi);
    clrscr();
}
void main()
{
  int gd=DETECT,gm;
  char ch;
  initgraph(&gd,&gm,"C:\\TurboC3\\BGI");
  do
  {
	textcolor(0);
	get();
	sound(f);
	soundwave();
	nosound();
	fflush(stdin);
	printf("ENTER 'X' TO EXIT: ");
	scanf("%c",&ch);
	  if(ch=='X'||ch=='x'){
	  isContinue=0;
	  }
	clrscr();
	cleardevice();
  }while(isContinue);
  nosound();
}


