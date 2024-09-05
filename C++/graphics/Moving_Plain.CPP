#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <graphics.h>
//using namespace std;

int main()
{
    int gd=0, gm, i=0;
    initgraph(&gd, &gm, "\\TURBOC3\\bgi");

    while(!kbhit()){
	//sky
	setfillstyle(1, 1);
	bar(0, 0, 640, 480);
	//body
	setcolor(14);
	setlinestyle(0, 0, 2);
	rectangle(80+i,140,90+i,150);
	rectangle(120+i,140,130+i,150);
	rectangle(160+i,140,170+i,150);
	rectangle(200+i,140,210+i,150);
	rectangle(240+i,140,250+i,150);
	setfillstyle(1, 15);
	moveto(0+i, 100);
	lineto(20+i, 100);
	lineto(50+i, 130);
	lineto(200+i, 130);
	lineto(250+i, 125);
	ellipse(245+i, 135, 0, 90, 25, 10);
	ellipse(270+i, 148, 270, 90, 30, 17);
	moveto(270+i, 165);
	lineto(200+i, 165);
	lineto(50+i, 160);
	lineto(10+i, 140);
	lineto(0+i, 100);
    floodfill(10+i, 110, 14);

	//left wing
	moveto(130+i, 130);
	lineto(70+i, 70);
	lineto(100+i, 70);
	lineto(190+i, 130);
    floodfill(130+i, 120, 14);
	//right wing
	moveto(160+i, 155);
	lineto(80+i, 190);
	lineto(110+i, 190);
	lineto(220+i, 155);
	lineto(160+i, 155);
       floodfill(160+i, 165, 14);
	//text
	setcolor(12);
	setbkcolor(15);
	settextstyle(8, 0, 1);
	outtextxy(60+i, 125, "B o i n g");
	// right wing motors moveto(200+i, 185);
	i+=5;
	delay(100);
	if(i==700)
	    i=0;
    }

    return 0;
}
