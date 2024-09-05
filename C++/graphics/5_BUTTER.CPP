#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>

void buf1(){

    //  structure of butterfly
     ellipse(240,180,115,65,10,40);//body

     circle(240,140,10);   // face
     circle(240,130,2);    // lips
     circle(235,137,2);   // left eye
     circle(245,137,2);   // right eye

     ellipse(215,140,15,100,20,40);    //antenna
     ellipse(265,140,85,165,20,40);    //antenna

     ellipse(160,190,270,0,80,25);   //left wing
     ellipse(160,160,0,90,80,25);

     ellipse(160,175,270,90,15,40);   // wing border
     ellipse(320,175,90,270,15,40);   //wing border

     ellipse(320,190,180,270,80,25); //  right wing
     ellipse(320,160,90,180,80,25);

     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,140,WHITE);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(200,180,WHITE);
     setfillstyle(SOLID_FILL,RED);
     floodfill(290,160,WHITE);
     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,180,WHITE);
     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,210,WHITE);

}
void buf2(){
     ellipse(240,180,120,60,10,40);

     circle(240,140,10);
     circle(240,130,2);
     circle(235,137,2);
     circle(245,137,2);

     ellipse(215,140,15,100,20,30);
     ellipse(265,140,85,165,20,30);

     ellipse(320,190,180,260,80,40);
     ellipse(320,160,100,180,80,40);
     ellipse(310,175,115,245,15,60);

     ellipse(160,190,280,0,80,40); //  left
     ellipse(160,160,0,80,80,40);
     ellipse(170,175,295,65,15,60);
     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,140,WHITE);
     setfillstyle(SOLID_FILL,GREEN);
     floodfill(200,180,WHITE);
     setfillstyle(SOLID_FILL,RED);
     floodfill(290,160,WHITE);
     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,180,WHITE);
     setfillstyle(SOLID_FILL,YELLOW);
     floodfill(240,210,WHITE);

}
int main()
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"\\TURBOC3\\bgi");
    while(!kbhit()){
	buf1();
	delay(300);
	cleardevice();
	buf2();
	delay(300);
	cleardevice();
    }

    return 0;
}
