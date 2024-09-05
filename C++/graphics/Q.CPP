#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream.h>
#include <dos.h>
#include <stdio.h>
#include <graphics.h>
#define max 20
struct queue
{
int st[max];
};
void insert(struct queue *my, int val);
void Delete(struct queue *my);
void display(struct queue my);
int ch;
int num,tot,i;
struct queue myq;
void interface()
{
int gd=0,gm,i=0;
initgraph(&gd,&gm,"\\turboc3\\bgi");
while(!kbhit())
{
setbkcolor(1);
setcolor(15);
setlinestyle(0,1,3);
settextstyle(4,0,4);
rectangle(0,0,getmaxx(),getmaxy());
outtextxy(50,30,"Array Implementation of ");
setcolor(5);
settextstyle(3,0,5);
outtextxy(400,25,"QUEUE");
setcolor(6);
settextstyle(2,0,4);
outtextxy(450,430,"Press Any Key to Continue...");
putpixel(rand()%getmaxx(),rand()%getmaxy(),rand()%16);
delay(20);
i++;
}
getch();
restorecrtmode();
}

int menu()
{
clrscr();
cout<<"\n\n***************************\n\n";
cout<<" MENU Q";
cout<<"\n1. Insert";
cout<<"\n2. Delete";
cout<<"\n3. Display";
cout<<"\n4. Exit";
cout<<"\n\nEnter Your choice  : ";
cin>>ch;
return ch;

}
void main()
{
clrscr();
myq.st[0] = 2;
myq.st[1] = 2;
interface();
do
{

ch = menu();
switch(ch)
{
case 1 : cout<<"How many Element to Insert ? ";
		cin>>tot;
		for(i=0;i<tot;i++)
		{
		cout<<("Enter the number to insert :-");
		cin>>num;
		insert(&myq,num);
		}
		cout<<"Insertedd...";
		getch();
		break;
case 2 : cout<<"How many Element to Delete ? ";
		cin>>tot;
		for(i=0;i<tot;i++)
		{

		Delete(&myq);
		}
			break;
case 3 : display(myq);
			break;
case 4 : cout<<"Exiting...";
		getch();
		exit(0);
		default : cout<<"\n\n\nInvalid choice!";
}
cout<<"\n\n\nBack to menu ? Yes (1) | No (0) :\t";
cin>>ch;
} while(ch != 0);
  closegraph();
}
		void insert(struct queue * my, int val)
		{
			if(my->st[1]>=max+1)
			{
				cout<<"Already Full:-";
			getch();
			return;
		}
		my->st[my->st[1]]=val;
		my->st[1]=my->st[1]+1;
		}
		void Delete(struct queue *my)
		{
			if(my->st[0]== my->st[1])
			{
				cout<<("Q Underflow :- NOTHING TO Delete :- ");
				getch();
				return;
			}
			my->st[0] = my->st[0]+1;
			cout<<"One Element Deleted!...";
		}
		void display(struct queue my)
		{
			int g = 0, d,i;
			int j = 400;
			char str[10];
			if(my.st[0]>=my.st[1])
			{
				cout<<"Please, Atleast PUSH one item";
				getch();
				return;
			}
			initgraph(&g,&d,"\\turboc3\\bgi");
			setbkcolor(1);
			outtextxy(10,10,"Press Any Key : ");
			getch();
			setfillstyle(11,12);
			for(i=2;i<20;i++)
			{
				setcolor(4);
				bar(200,j,400,j-20);
				rectangle(200,j,400,j-20);
				j = j-20;
			}
			j = 400;

			for(i = 2;i<my.st[0];i++)
			{
				setcolor(4);
				rectangle(200,j,400,j-20);
				j = j-20;
			}
			setfillstyle(1,3);
			for(i=my.st[0];i<my.st[1];i++)
			{
				setcolor(7);
				delay(500);
				bar(200,j,400,j-20);
				sprintf(str,"%d", my.st[i]);
				setcolor(4);
				outtextxy(280,j-10,str);
				j = j-20;
				}
				j = 390;
				for(i = 2; i<my.st[0];i++)
				j = j-20;
				outtextxy(410,j,"<- Front Pointer");
				j=390;
				for(i = 2; i<my.st[1];i++)
				j = j-20;
				outtextxy(410,j,"<- Rear Pointer");
				getch();
				restorecrtmode();
			}