#include<conio.h>
#include<PROCESS.h>
#include<stdio.h>
#include<graphics.h>
#include<dos.h>
#include<iostream.h>
void main(){
int gd = DETECT,gmode,i;
initgraph(&gd,&gmode,"\\Turboc3\\BGI");
while(!kbhit()){
for(i=1;i<=8;++i)
{
setcolor(i+1);
settextstyle(1,0,i);
outtextxy(40,140,"SCREEN_SAVER");
setcolor(0);
delay(500);
cleardevice();
settextstyle(1,0,i-1);
outtextxy(40,140,"SCREEN_SAVER");
}
if(i==8){
i==0;
}
}
getch();
}
