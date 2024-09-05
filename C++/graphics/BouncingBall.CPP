#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>

void main(){
	int gd = DETECT,gmode;
	initgraph(&gd,&gmode,"\\Turboc3\\BGI");
	int i = 0;
	int y = 50;
	char po = 'd';
	 line(50,380,600,380);
	while(!kbhit()){
	  setfillstyle(1,3);

	  circle(300,y,10);

	  floodfill(301,y,15);
	  if(y >= 370){
	     po = 'u';
	  }
	  if(y <= 50 ){
	    po = 'd';
	  }
	  switch(po){
	  case 'd':
	  i= i+5;
	  y = y+5;
	  break;
	  case 'u':
	  i=i+5;
	  y = y-5;
	  break;
	  }

	  delay(50);
	  cleardevice();
	  line(50,380,600,380);
	}
	getch();


}
