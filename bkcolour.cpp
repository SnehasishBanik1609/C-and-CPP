#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<stdio.h>
main()
{
  int gd=DETECT,gm,i;
  initgraph(&gd,&gm,"c:\\tc\\bgi");
  for(i=0;i<=15;i++)
  {
    setbkcolor(i);
    delay(1000);
    getch();
  }
  closegraph();
}
