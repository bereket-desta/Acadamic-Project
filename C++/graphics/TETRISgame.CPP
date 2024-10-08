#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<iostream.h>
#include<stdlib.h>
#include<dos.h>
#include<time.h>
#include <string.h>
enum direction{hor,ver};
enum bool{false=0,true=1};
int SPEED=500;
int SCORE=0;
const int BLOCKWIDTH=15; //width for each blocks
const int BLOCKHEIGHT=15;//height for each blocks
const int LEFTCORNER=230;//Position of the palying board from the left margin of the screen
const int TOPCORNER=120;//Position of the palying board from the left margin of the screen
const int BOARDWIDTH=180;
const int BOARDHEIGHT=240;
const int INFOAREAWIDTH=600;
const int INFOAREAHEIGHT=105;
const int INFOAREALEFT=20;
const int INFOAREATOP=370;
const int LEFTARROW=75;
const int RIGHTARROW=77;
const int UPARROW=72;
const int DOWNARROW=80;
const int ENTER=13;
const int ESC=27;
const int SPACE=32;
const int FILLCOLOR=BLACK;
const int DRAWCOLOR=GREEN;
int WHITECELL=0;
struct point
{
int x;
int y;
};
int shape_curx;
int shape_cury;
point *shapepoints;
void InitGraphEngine(){
  int gdriver = DETECT, gmode;
  initgraph(&gdriver, &gmode, "\\turboc3\\bgi");
}
void DrawShape(point *p,int fcolor,int dcolor){
  setfillstyle(SOLID_FILL, fcolor);
  setcolor(dcolor);
  for(int i=0;i<=3;i++){
     bar(p[i].x,p[i].y, p[i].x+BLOCKWIDTH,p[i].y+BLOCKHEIGHT);
     rectangle(p[i].x, p[i].y, p[i].x+BLOCKWIDTH,p[i].y+BLOCKHEIGHT);
  }
}
bool CanDrawTShape(point *p,int fcolor){
    if(getpixel(p[3].x+1,p[3].y+1)!=fcolor&&getpixel(p[2].x+1,p[2].y+1)!=fcolor)
      return true;
    else
      return false;
}
bool CanDrawLShape(point *p,int fcolor){
    if(getpixel(p[3].x+1,p[3].y+1)!=fcolor&&getpixel(p[2].x+1,p[2].y+1)!=fcolor)
      return true;
    else
	return false;
}
bool CanDrawIShape(point *p,int fcolor){
    if(getpixel(p[3].x+1,p[3].y+1)!=fcolor)
      return true;
    else
      return false;
}
bool CanDrawSShape(point *p,int fcolor){
  if(getpixel(p[1].x+1,p[1].y+1)!=fcolor&&getpixel(p[3].x+1,p[3].y+1)!=fcolor)
     return true;
  else
     return false;
}
bool CanDrawZShape(point *p,int fcolor){
  if(getpixel(p[1].x+1,p[1].y+1)!=fcolor&&getpixel(p[3].x+1,p[3].y+1)!=fcolor)
     return true;
  else
     return false;

}

//checks whether new D shape can be drawn on the next move
bool CanDrawDShape(point *p,int fcolor){
    if(getpixel(p[1].x+1,p[1].y+1)!=fcolor&&getpixel(p[3].x+1,p[3].y+1)!=fcolor)
     return true;
  else
     return false;
}
point* TShapePoints(int xpos,int ypos)
{
    int x=xpos,y=ypos;
    point *p=new point[4];

    for(int i=0;i<=2;i++){
      p[i].x=x;
      p[i].y=y;
      y+=BLOCKHEIGHT;
    }
    p[3].x=xpos+BLOCKWIDTH;
    p[3].y=ypos+BLOCKHEIGHT;

    return p;
}
point* LShapePoints(int xpos,int ypos)
{
    int x=xpos,y=ypos;
    point *p=new point[4];

    for(int i=0;i<=2;i++){
      p[i].x=x;
      p[i].y=y;
      y+=BLOCKHEIGHT;
    }
    p[3].x=xpos+BLOCKWIDTH;
    p[3].y=ypos+(BLOCKHEIGHT*2);

    return p;
}
point* IShapePoints(int xpos,int ypos)
{
    int x=xpos,y=ypos;
    point *p=new point[4];

    for(int i=0;i<=3;i++){
      p[i].x=x;
      p[i].y=y;
      y+=BLOCKHEIGHT;
    }

    return p;
}
point* SShapePoints(int xpos,int ypos)
{
    int x=xpos,y=ypos;
    point *p=new point[4];

    for(int i=0;i<=3;i++){
      p[i].x=x;
      p[i].y=y;
      y+=BLOCKHEIGHT;
      if(i==1){
	 x+=BLOCKWIDTH;
	 y-=BLOCKWIDTH;
	}
    }

    return p;
}
point* ZShapePoints(int xpos,int ypos)
{
    int x=xpos,y=ypos;
    point *p=new point[4];

    y+=BLOCKHEIGHT;
    for(int i=0;i<=3;i++){
      p[i].x=x;
      p[i].y=y;
      y+=BLOCKHEIGHT;
      if(i==1){
	 x+=BLOCKWIDTH;
	 y=ypos;
      }
    }

    return p;
}
point* DShapePoints(int xpos,int ypos)
{
    int x=xpos,y=ypos;
    point *p=new point[4];

    for(int i=0;i<=3;i++){
      p[i].x=x;
      p[i].y=y;
      y+=BLOCKHEIGHT;
      if(i==1){
	 x+=BLOCKWIDTH;
	 y=ypos;
      }
    }
  return p;
}
bool CheckUpperCells(int fcolor){
    int x=LEFTCORNER+BLOCKWIDTH,y=TOPCORNER;
    bool marked=false;

    for(int i=1;i<=10&&!marked;i++){
      if(getpixel(x+1,y+1)==fcolor)
	 marked=true;
      else
	 x+=BLOCKWIDTH;
    }
return marked;
}
void ShiftRowsDown(int i)
{
	for(i=i-15;i>=110;i-=15)
	{
		for(int j=250;j<=390;j+=15)
		{
			if(getpixel(j,i)==WHITE)
			{
				setfillstyle(1,BLACK);
				bar(j-5,i-10,j+10,i+5);
				delay(50);
				setfillstyle(1,WHITE);
				bar(j-5,i+5,j+10,i+20);
				setcolor(YELLOW);
				line(j-5,i-10,j+10,i-10);
				setcolor(LIGHTGRAY);
				line(j-5,i-10,j-5,i+5);
				line(j+10,i+5,j-5,i+5);
				line(j+10,i+5,j+10,i-10);
			}
		}
	}
	char score[10];
	SCORE=SCORE+10;
	itoa(SCORE,score,10);
	setcolor(WHITE);
	rectangle(450,120,550,220);
	setfillstyle(1,BLUE);
	floodfill(455,125,WHITE);
    //	outtextxy(480,145,score);
	settextstyle(12,0,3);
	outtextxy(495,170,score);
}
void IsFull()
{
	setfillstyle(1,0);
	setcolor(14);
	for(int i=340;i>=125;i-=15)
	{
		for(int j=250;j<=390;j+=15)
		{
			if(getpixel(j,i)==WHITE)
			{
				WHITECELL+=1;
			}
		}
		if(WHITECELL==10)
		{
			setcolor(0);
			bar(245,i+5,395,i-10);
			setcolor(YELLOW);
			for(int k=245;k<=410;k+=15)
			{
				line(k,120,k,345);
			}
			for(int l=120;l<=345;l+=15)
			{
				line(245,l,395,l);
			}
			ShiftRowsDown(i);
		}
		WHITECELL=0;
	}
	//return true;
}
void EraseEntry(){
  setfillstyle(SOLID_FILL, BLACK);
  bar(LEFTCORNER+BLOCKWIDTH,0,(LEFTCORNER+BOARDWIDTH-BLOCKWIDTH),TOPCORNER-1);
}
void DrawBoard(){
setfillstyle(SOLID_FILL, WHITE);
 bar(LEFTCORNER,TOPCORNER,LEFTCORNER+BOARDWIDTH,TOPCORNER+BOARDHEIGHT);
setfillstyle(SOLID_FILL, BLACK);
bar(LEFTCORNER+BLOCKWIDTH,TOPCORNER,(LEFTCORNER+BOARDWIDTH-BLOCKWIDTH),(TOPCORNER+BOARDHEIGHT-BLOCKHEIGHT));
setfillstyle(SOLID_FILL, BLUE);
bar(INFOAREALEFT,INFOAREATOP,INFOAREALEFT+INFOAREAWIDTH,INFOAREATOP+INFOAREAHEIGHT);
rectangle(INFOAREALEFT,INFOAREATOP,INFOAREALEFT+INFOAREAWIDTH,INFOAREATOP+INFOAREAHEIGHT);
}
void DisplayInfo(char *msg){
  setcolor(WHITE);
  setfillstyle(SOLID_FILL, BLUE);
  bar(INFOAREALEFT+1,INFOAREATOP+1,INFOAREALEFT+400,INFOAREATOP+INFOAREAHEIGHT-1);
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 1.5);
  outtextxy(INFOAREALEFT+30,INFOAREATOP+50,msg);
}
void FillGrid(int fcolor,int speed,int numrows=15,int numcols=10){
int x=LEFTCORNER+BLOCKWIDTH,y=TOPCORNER;

setcolor(YELLOW);
setfillstyle(SOLID_FILL, fcolor);
for(int i=1;i<=numrows;i++)
{
    for(int j=1;j<=numcols;j++)
    {
     delay(speed);
     bar(x,y,x+BLOCKWIDTH,y+BLOCKHEIGHT);
     rectangle(x,y,x+BLOCKWIDTH,y+BLOCKHEIGHT);
     x+=BLOCKWIDTH;
    }
    x=LEFTCORNER+BLOCKWIDTH;
    y+=BLOCKHEIGHT;
}
}
int NextShape(){
  int xstart=INFOAREALEFT+401;
  int ystart=INFOAREATOP+1;
  int ShapeIndex;
  point *p;
  time_t t;

  srand((unsigned) time(&t));
  ShapeIndex=rand()%6;
  setfillstyle(SOLID_FILL, BLUE);
  bar(xstart,ystart,xstart+198,ystart+103);
  settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
  setcolor(LIGHTCYAN);
  outtextxy(xstart+50,ystart+10,"Next Shape");
  switch(ShapeIndex){
     case 0:
	 p=TShapePoints(xstart+70,ystart+30);
	 break;
     case 1:
	 p=LShapePoints(xstart+70,ystart+30);
	 break;
     case 2:
	 p=IShapePoints(xstart+70,ystart+30);
	 break;
     case 3:
	 p=SShapePoints(xstart+70,ystart+30);
	 break;
     case 4:
	 p=ZShapePoints(xstart+70,ystart+30);
	 break;
     case 5:
	 p=DShapePoints(xstart+70,ystart+30);
	 break;
     }

  DrawShape(p,WHITE,LIGHTGRAY);
  delete p;

  return ShapeIndex;
// return 1; // this line is only for test purpose. finally it will be erased and substitute by the above comment
}
int MoveShapeleft(int index,int speed){
bool canmove=true;
point *nextpoint;
point *prevpoint;
//shape_curx-=15;
//shape_curx=LEFTCORNER+(BLOCKWIDTH*5)-15;
if(shape_curx-15==LEFTCORNER) //--------------------------
	shape_curx=shape_curx;
else
	shape_curx-=15;
/*if(index==2)
     shape_cury=TOPCORNER-(BLOCKWIDTH*2)-15;
else if(index==5)
     shape_cury=TOPCORNER-(BLOCKWIDTH*1)-15;
else
     shape_cury=TOPCORNER-(BLOCKWIDTH*2)-15;
  */
     switch(index){
	case 0:
	  do{
	    nextpoint=TShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=TShapePoints(shape_curx,shape_cury+BLOCKHEIGHT);
	    canmove=CanDrawTShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	  break;
      case 1:
	  do{
	    nextpoint=LShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=LShapePoints(shape_curx,shape_cury+15);
	    canmove=CanDrawLShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	    break;
      case 2:
	  do{
	    nextpoint=IShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=IShapePoints(shape_curx,shape_cury+15);
	    canmove=CanDrawIShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	    break;
      case 3:
	     do{
		nextpoint=SShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=SShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawSShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
		break;
      case 4:
	     do{
		nextpoint=ZShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=ZShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawZShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
		break;
      case 5:
	     do{
		nextpoint=DShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=DShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawDShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
		break;
      }

return 0;
}
int MoveShaperight(int index,int speed){
bool canmove=true;
point *nextpoint;
point *prevpoint;
//shape_curx=2*LEFTCORNER+(BLOCKWIDTH*5);
if(index==2)
{
	if(shape_curx+30>=LEFTCORNER+BOARDWIDTH)
		shape_curx=shape_curx;
	else
		shape_curx=shape_curx+15;
}
else
{
	if(shape_curx+45>=LEFTCORNER+BOARDWIDTH)
		shape_curx=shape_curx;
	else
		shape_curx=shape_curx+15;
}
/*if(index==2)
     shape_cury=2*TOPCORNER-(BLOCKWIDTH*2);
else if(index==5)
     shape_cury=2*TOPCORNER-(BLOCKWIDTH*1);
else
     shape_cury=2*TOPCORNER-(BLOCKWIDTH*2);
  */
     switch(index){
	case 0:
	  do{
	    nextpoint=TShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=TShapePoints(shape_curx+15,shape_cury+BLOCKHEIGHT);
	    canmove=CanDrawTShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	  break;
      case 1:
	  do{
	    nextpoint=LShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=LShapePoints(shape_curx,shape_cury+15);
	    canmove=CanDrawLShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	    break;
      case 2:
	  do{
	    nextpoint=IShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=IShapePoints(shape_curx-15,shape_cury+15);
	    canmove=CanDrawIShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	    break;
      case 3:
	     do{
		nextpoint=SShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=SShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawSShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
		break;
      case 4:
	     do{
		nextpoint=ZShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=ZShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawZShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
		break;
      case 5:
	     do{
		nextpoint=DShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=DShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawDShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
		break;
      }
return 0;
}
int MoveShapeDown(int index,int speed){
bool canmove=true;
point *nextpoint;
point *prevpoint;
shape_curx=LEFTCORNER+(BLOCKWIDTH*5);
if(index==2)    //can be substitude by if(index!=5)
     shape_cury=TOPCORNER-(BLOCKWIDTH*2);
else if(index==5)
     shape_cury=TOPCORNER-(BLOCKWIDTH*1);
else
     shape_cury=TOPCORNER-(BLOCKWIDTH*2);

     switch(index){
	case 0:
	  do{
	    nextpoint=TShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=TShapePoints(shape_curx,shape_cury+BLOCKHEIGHT);
	    canmove=CanDrawTShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	 /*   if(getch()==LEFTARROW)       //------------
		MoveShapeleft(index,500);*/
	  break;
      case 1:
	  do{
	    nextpoint=LShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=LShapePoints(shape_curx,shape_cury+15);
	    canmove=CanDrawLShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
/*	    if(getch()==LEFTARROW)       //------------
		MoveShapeleft(1,500);*/
	     break;
      case 2:
	  do{
	    nextpoint=IShapePoints(shape_curx,shape_cury);
	    DrawShape(nextpoint,WHITE,LIGHTGRAY);
	    prevpoint=nextpoint;
	    nextpoint=IShapePoints(shape_curx,shape_cury+15);
	    canmove=CanDrawIShape(nextpoint,WHITE);
	    if(canmove){
	      delay(speed);
	      DrawShape(prevpoint,BLACK,YELLOW);
	      EraseEntry();
	      shape_cury+=15;
	    }
	    delete nextpoint;
	    delete prevpoint;
	    }while(!kbhit()&&canmove);
	    /*if(getch()==LEFTARROW)       //------------
		moveshapeleft(index,500);*/
	    break;
      case 3:
	     do{
		nextpoint=SShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=SShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawSShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
       /*		if(getch()==LEFTARROW)       //------------
			moveshapeleft(index,500);*/
		break;
      case 4:
	     do{
		nextpoint=ZShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=ZShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawZShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
	       /*	if(getch()==LEFTARROW)       //------------
			moveshapeleft(index,500);*/
		break;
      case 5:
	     do{
		nextpoint=DShapePoints(shape_curx,shape_cury);
		DrawShape(nextpoint,WHITE,LIGHTGRAY);
		prevpoint=nextpoint;
		nextpoint=DShapePoints(shape_curx,shape_cury+15);
		canmove=CanDrawDShape(nextpoint,WHITE);
		if(canmove){
		  delay(speed);
		  DrawShape(prevpoint,BLACK,YELLOW);
		  EraseEntry();
		  shape_cury+=15;
		}
		delete nextpoint;
		delete prevpoint;
		}while(!kbhit()&&canmove);
		/*if(getch()==LEFTARROW)       //------------
			moveshapeleft(index,500);   */
		break;
      }
return 0;
}
void pause()
{
	while(!kbhit())
	{
	}
}
void startmessage()
{
clrscr();
setcolor(4);
delay(120);
settextstyle(1,0,5);
setfillstyle(SOLID_FILL, BLUE);
bar(1,1,640,480);
outtextxy(90,160,"T E T R I S  G A M E !");
delay(1000);
settextstyle(1,0,2);
setcolor(5);
outtextxy(250,350,"Developed By : Dada");
setcolor(15);
settextstyle(12,0,3);
outtextxy(23,450,"Press enter/escape key to start/exit game....");
if(getch()==27)
exit(1);
//getch();
//setcolor(4);
cleardevice();
}
void main()
{
    int key,key1,m,n;

    int nextindex,previndex;
    InitGraphEngine();
    startmessage();
START:
    DrawBoard();
    FillGrid(BLACK,0);
    DisplayInfo("press ENTER key to start");
    setcolor(WHITE);
    rectangle(450,120,550,220);
    setfillstyle(1,BLUE);
    floodfill(455,125,WHITE);
    outtextxy(480,145,"Score");
    outtextxy(495,170,"0");
    key=getch();
    if(key==ENTER)
    {
      PLAY:
      DisplayInfo("press ESC to stop");
      outtextxy(50,450,"press space to pause");
      previndex=rand()%6;
      point *p;
      int fcolor;
      CanDrawLShape(p,fcolor);
      while(!kbhit())
      {
		nextindex=NextShape();
		IsFull();
		if(!CheckUpperCells(WHITE))
		{
			 SPEED=500;
			 MoveShapeDown(previndex,SPEED);
	     test:	 if(!kbhit())
			 previndex=nextindex;
		}
		else
		{
	     ENDGAME:	  EraseEntry();
			  delay(SPEED);
			  FillGrid(WHITE,15);
			  DisplayInfo("Game Over!!!");
			  getch();
			  goto START;
		}
      }
      switch (getch())
      {
		case LEFTARROW :
			MoveShapeleft(previndex,SPEED);
			break;
		case RIGHTARROW :
			MoveShaperight(previndex,SPEED);
			break;
		case DOWNARROW :
			SPEED=100;
			//MoveShapeDown(previndex,SPEED);
			break;
		case SPACE :
			pause();
			break;
		case ESC:
			goto ENDGAME;
			break;
      }
      goto test;       //-------------------------
   }
}
