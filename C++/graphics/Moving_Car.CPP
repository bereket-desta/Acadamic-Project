#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <stdlib.h>
#include <graphics.h>
//using namespace std;

int main()
{
    int gd=0, gm, i=0;
    initgraph(&gd, &gm, "\\TURBOC3\\bgi");
    setlinestyle(0, 0, 2);
    while(!kbhit()){
        //car body
        setfillstyle(1, 1);
	    moveto(20+i, 150);
	    lineto(20+i, 100);
	    lineto(30+i, 90);
	    lineto(100+i, 90);
	    lineto(140+i, 120);
	    lineto(140+i, 150);
	    lineto(20+i, 150);

	    // car window

	    moveto(90+i, 90);
	    lineto(90+i, 110);
	    lineto(125+i, 110);

	    //car wheel

	    moveto(60+i, 150);
	    ellipse(40+i, 150, 0, 180, 10, 10);
	    ellipse(110+i, 150, 0, 180, 10, 10);
	    floodfill(50+i, 100, 15);
	    setfillstyle(5, 4);
	    fillellipse(40+i, 150, 7, 7);
	    fillellipse(110+i, 150, 7, 7);

	    i+=5;
	    delay(30);
	    cleardevice();
	    if(i>640)
	        i=0;
    }

    getch();
    return 0;
}
