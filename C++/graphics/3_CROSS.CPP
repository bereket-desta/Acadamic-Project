#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
//using namespace std;

int main()
{
    int gd=0, gm;
    initgraph(&gd, &gm, "\\TURBOC3\\bgi");
    setcolor(1);
    moveto(320,35);
    lineto(340,35);
    lineto(340,50);
    lineto(350,50);
    lineto(350,60);
    lineto(340,60);
    lineto(340,150);
    lineto(450,150);
    lineto(450,140);
    lineto(460,140);
    lineto(460,150);
    lineto(475,150);
    lineto(475,170);
    lineto(460,170);
    lineto(460,180);
    lineto(450,180);
    lineto(450,170);
    lineto(340,170);
    lineto(340,350);
    lineto(350,350);
    lineto(350,360);
    lineto(340,360);
    lineto(340,375);
    lineto(320,375);
    lineto(320,360);
    lineto(310,360);
    lineto(310,350);
    lineto(320,350);
    lineto(320,170);
    lineto(210,170);
    lineto(210,180);
    lineto(200,180);
    lineto(200,170);
    lineto(185,170);
    lineto(185,150);
    lineto(200,150);
    lineto(200,140);
    lineto(210,140);
    lineto(210,150);
    lineto(320,150);
    lineto(320,60);
    lineto(310,60);
    lineto(310,50);
    lineto(320,50);
    lineto(320,35);
    setfillstyle(1,15);
    floodfill(330,70,1);
    setcolor(15);
    arc(330,40,0,180,20);
    arc(310,55,90,270,15);
    arc(350,55,270,90,15);
    arc(455,140,0,180,15);
    arc(470,160,270,90,20);
    arc(455,180,180,0,15);
    arc(350,355,270,90,15);
    arc(330,370,180,0,20);
    arc(310,355,90,270,15);
    arc(190,160,90,270,20);
    arc(205,180,180,0,15);
    arc(205,140,0,180,15);
    line(350,70,350,140);
    line(350,140,440,140);
    line(350,180,440,180);
    line(350,340,350,180);
    line(310,340,310,180);
    line(220,180,310,180);
    line(220,140,310,140);
    line(310,140,310,70);

getch();
}