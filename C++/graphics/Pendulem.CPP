#include <iostream.h>
#include <graphics.h>
#include <math.h>
#include <dos.h>
#include <conio.h>



int main(){
    int gd=0, gm, xc= 320, yc=100, r=150;
    initgraph(&gd, &gm, "\\turboc3\\bgi");

    const double teta= 22.0/(7.0*180.0);
    double i;
    setlinestyle(0, 0, 3);
    line(xc-100, yc, xc+100, yc);
    for(i=45; i<=135; i++) {
	setlinestyle(0, 0, 3);
	line(xc-100, yc, xc+100, yc);
	line(xc, yc, xc+r*cos(i*teta), yc+r*sin(i*teta));
	fillellipse(xc+r*cos(i*teta), yc+r*sin(i*teta), 10, 10);
	setfillstyle(1, 5);
	delay(20);
	cleardevice();
	if(i==135)
	for(i; i>=45; i--){
	    setcolor(15);
	    line(xc, yc, xc+r*cos(i*teta), yc+r*sin(i*teta));
	    fillellipse(xc+r*cos(i*teta), yc+r*sin(i*teta), 10, 10);
	    setfillstyle(1, 5);
	    delay(20);
	    cleardevice();
	    setlinestyle(0, 0, 3);
	    line(xc-100, yc, xc+100, yc);

      }
    }
    getch();
}
