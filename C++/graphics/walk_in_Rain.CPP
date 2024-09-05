#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>

int main()
{
    int gd=0, gm;
    initgraph(&gd, &gm, "\\TURBOC3\\bgi");

 while(!kbhit()){
    for(int i=0; i<620; i+=5){
    line(0,420,640,420);

    if(i%2==0){
    line(25+i,420,35+i,380);
    line(45+i,420,35+i,380);
    line(35+i,350,25+i,370);
    delay(30);
    }
    else{
    line(35+i,420,35+i,380);
    line(35+i,350,40+i,370);
    delay(30);
    }
    line(35+i,380,35+i,350);
    line(35+i,350,50+i,370);
    circle(35+i,340,10);

    setcolor(1);
    setfillstyle(1,15);
    arc(50+i,320,0,180,35);
    line(15+i,320,85+i,320);
    floodfill(20+i,315,1);
    setcolor(15);
    line(50+i,370,50+i,320);
    arc(55+i,370,180,360,5);

    for(int j=0; j<200; j++){
    outtextxy(rand()%640,rand()%420,"'");
    }
    delay(100);
    cleardevice();
    }
    }
getch();
}
