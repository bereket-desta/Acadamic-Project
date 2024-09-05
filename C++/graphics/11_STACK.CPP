
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#define max 5

#define null -1
void status();
enum boolean{false,true};

struct stack{
	int data[max];
	int top;
};

stack s;
int x,ch;

void create(stack &s)
{
	s.top=null;
}

boolean empty(stack s)
{
if(s.top==null)
	return true;
else
	return false;
}
boolean full(stack s)
{
if(s.top==max-1)
	 return true;
else
	 return false;
}

void push(stack &s,int x)
{
if(full(s))
	  cout<<"stack over flow!!!";
else
{
	  s.top=s.top+1;
	  s.data[s.top]=x;
}
}

int pop(stack &s)
{
if(empty(s))
{
	  cout<<"\n\nstack under flow!!!";
	  }
else
{
	  x=s.data[s.top];

	  s.top=s.top-1;
}
return x;
}


int peek(stack &s)
{
if(empty(s))
	  cout<<"\n\nStack under flow";
else
{
	  x=s.data[s.top];
}
return x;
}


void display(stack &s)
{
if (empty(s))
	 cout<<"\n\nStack is underflow";
else
while(!empty(s))
	  cout<<s.data[s.top--]<<endl;

}


void shape()
{
int y = 15;
int gd = 0,gm;
initgraph(&gd,&gm,"\\turboc3\\bgi");
setbkcolor(1);
setcolor(15);
line(260,50,260,260);
line(320,50,320,260);
line(260,260,320,260);

line(260,220,320,220);
line(260,180,320,180);
line(260,140,320,140);
line(260,100,320,100);
line(260,50,320,50);

switch(s.top)
{
case 0:   gotoxy(36,15);
	  cout<<s.data[s.top];
	  break;
case 1:   gotoxy(36,y);
	  cout<<s.data[s.top-1];
	  y-=2;
	  gotoxy(36,y);
	  cout<<s.data[s.top];
	  break;
case 2:   gotoxy(36,y);
	  cout<<s.data[s.top-2];
	  y-=2;
	  gotoxy(36,y);
	  cout<<s.data[s.top-1];
	  y-=2;
	  gotoxy(36,y);
	  cout<<s.data[s.top];
	  break;
case 3:   gotoxy(36,y);
	  cout<<s.data[s.top-3];
	  y-=1.5;
	  gotoxy(36,y);
	  cout<<s.data[s.top-2];
	  y-=2;
	  gotoxy(36,y);
	  cout<<s.data[s.top-1];
	  y-=2.5;
	  gotoxy(36,y);
	  cout<<s.data[s.top];
	  break;
case 4:   gotoxy(36,y);
	  cout<<s.data[s.top-4];
	  y-=1.5;
	  gotoxy(36,y);
	  cout<<s.data[s.top-3];
	  y-=1.5;
	  gotoxy(36,y);
	  cout<<s.data[s.top-2];
	  y-=2.5;
	  gotoxy(36,y);
	  cout<<s.data[s.top-1];
	  y-=3;
	  gotoxy(36,y);
	  cout<<s.data[s.top];
	  break;
	  }
}


int menu()
{
shape();
status();
gotoxy(1,1);
       //  cout<<"\n\n*********M E N U*********\n\n";
       setcolor(12);
       settextstyle(4,0,1);
	outtextxy(10,20,"Stack Operation");
	settextstyle(0,0,0);
	setcolor(14);
	/*cout<<"\
	Push		[1]\n\
	Pop		[2]\n\
	Peek		[3]\n\
	Display		[4]\n\
	About 		[6]\n\
	Exit		[5]";  */

	outtextxy(65,70,"Push            [1]");
	outtextxy(65,100,"Pop             [2]");
	outtextxy(65,130,"Peek            [3]");
	outtextxy(65,160,"Exit            [4]");
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\nEnter your choice:\t";
	cin>>ch;

return ch;
}

void main()
{
create(s);

do
{
clrscr();
ch=menu();
switch(ch)
{

case 1:
   cout<<"\n\nEnter data:\t";
   cin>>x;
   push(s,x);
break;

case 2:
   cout<<"\n\nThe popped element is:\t"<<pop(s);
break;

case 3:
   cout<<"\n\nThe top element is:\t"<<peek(s);
break;

/*case 4:
    cout<<"\n\nThe content of the stack:\t"<<endl;display(s);
break;*/

case 4: exit(0);
break;

default: cout<<"\n\n Wrong choice";
}
cout<<"\n\nBack to menu? Yes(1)||No(0):\t";
cin>>ch;
}while(ch!=0);
getch();
}
void status()
{
setcolor(YELLOW);
outtextxy(535,465,"");
gotoxy(49,4);
cout<<"Top : "<<s.top;

if(empty(s))
{
moveto(260,280);
outtext("Condition : Stack is Underflow");
}
else if(full(s))
{

	moveto(260,280);
	outtext("Condition : Stack is Overflow");
}
}












