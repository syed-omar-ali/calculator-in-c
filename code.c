#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
#include<graphics.h>
void detect_mouse();
void show_mouse();
void detect_position();
long double addnum(int);
long double addfloat(long double);
union REGS in,out;
long double num=0,num1=0,result=0,get=0,floatnum=0;
long double divcount=10,inputtype=0;
char *input[4][5]={{"1","2","3","/","sin"},
		  {"4","5","6","*","sqrt"},
		  {"7","8","9","+","x^y"} ,
		  {"clr","0","=","-","."}};
char input1[4][5]={{'1','2','3','/','o'},
		  {'4','5','6','*','r'},
		  {'7','8','9','+','p'} ,
		  {'l','0','=','-','d'}};
void main()
{
  int driver=DETECT,mode;
  int xcor,ycor,a,b;
  initgraph(&driver,&mode,"c:\\tc\\bgi");
  setfillstyle(10,6);
  bar(0,0,getmaxx(),getmaxy());
  setcolor(15);
  setfillstyle(1,8);
  rectangle(236,152,484,370);
  rectangle(237,153,483,369);
  rectangle(238,154,482,368);
  bar(238,154,482,368);
  setcolor(15);
  rectangle(238,70,482,150);
  rectangle(237,69,483,151);
  rectangle(236,68,484,152);
  setfillstyle(1,0);
  bar(238,70,482,150);
  ycor=170;
  outtext("Press any key to exit...");
  for(a=0;a<4;a++)
  {
	xcor=240;
	for(b=0;b<5;b++)
	{
	  setfillstyle(1,7);
	  setcolor(0);
	  fillellipse((xcor+xcor+40)/2,(ycor+ycor+40)/2,20,20);
	  //ellipse((xcor+xcor+40)/2,(ycor+ycor+40)/2,0,360,20,20);
	  outtextxy(xcor+9,ycor+16,input[a][b]);
	  xcor+=50;
	}
	ycor+=50;
  }
  detect_mouse();
  show_mouse();
  detect_position();
  getch();
  cleardevice();
}
void detect_mouse(){
	in.x.ax=0;
	int86(0x33,&in,&out);
	if(out.x.ax==0)
		outtext("Mouse couldn't be initialized");
	return;
}
void show_mouse(){
	in.x.ax=1;
	int86(0x33,&in,&out);
	return;
}
void detect_position(){

	int xpressed,ypressed,xcor,ycor,a,b;
	char input2,opr;int count=0;
	while(!kbhit())
	{
		in.x.ax=3;
		int86(0x33,&in,&out);
		if((out.x.bx&7)==1)
		{
			xpressed=out.x.cx;
			ypressed=out.x.dx;
			ycor=170;
			for(a=0;a<4;a++)
			{
				xcor=240;
				for(b=0;b<5;b++)
				{
					 if((xpressed>=xcor)&&(xpressed<=xcor+40)&&(ypressed>=ycor)&&(ypressed<=ycor+40))
					{
						input2=input1[a][b];
						switch(input2)
						{
							case '1':
								if(inputtype==0)
									get=addnum(1);
								else if(inputtype==1)
									get=addfloat(1.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '2':
								if(inputtype==0)
									get=addnum(2);
								else if(inputtype==1)
									get=addfloat(2.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '3':
								if(inputtype==0)
									get=addnum(3);
								else if(inputtype==1)
									get=addfloat(3.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '4':
								if(inputtype==0)
									get=addnum(4);
								else if(inputtype==1)
									get=addfloat(4.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '5':
								if(inputtype==0)
									get=addnum(5);
								else if(inputtype==1)
									get=addfloat(5.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '6':
								if(inputtype==0)
									get=addnum(6);
								else if(inputtype==1)
									get=addfloat(6.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '7':
								if(inputtype==0)
									get=addnum(7);
								else if(inputtype==1)
									get=addfloat(7.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '8':
								if(inputtype==0)
									get=addnum(8);
								else if(inputtype==1)
									get=addfloat(8.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '9':
								if(inputtype==0)
									get=addnum(9);
								else if(inputtype==1)
									get=addfloat(9.0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '0':
								if(inputtype==0)
									get=addnum(0);
								else if(inputtype==1)
									get=addfloat(0);
								gotoxy(51,9);
								printf("%Lf",get);
								break;
							case '+':
								num1=num;
								num=0;
								divcount=10;
								inputtype=0;
								opr='+';
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case '-':
								num1=num;
								num=0;
								divcount=10;
								inputtype=0;
								opr='-';
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case '*':
								num1=num;
								num=0;
								divcount=10;
								inputtype=0;
								opr='*';
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case '/':
								num1=num;
								num=0;
								divcount=10;
								inputtype=0;
								opr='/';
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case 'r':
								num1=num;
								num=0;
								divcount=10;
								inputtype=0;
								opr='r';
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case 'o':
								num1=num;
								num=0;
								divcount=10;
								inputtype=0;
								opr='o';
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case 'p':
								num1=num;
								num=0;
								divcount=10;
								inputtype=0;
								opr='p';
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case 'l':
								num=0;
								num1=0;
								result=0;
								count=0;
								floatnum=0;
								divcount=10;
								inputtype=0;
								gotoxy(51,9);
								printf("%Lf",num);
								break;
							case 'd':
								inputtype=1;
								break;
							case '=':
								switch(opr)
								{
									case '+':
										if(count<1)
											result=num+num1;
										else
											result=result+num;
										gotoxy(51,9);
										printf("%Lf",result);
										count+=1;
										break;
									case '-':
										if(count<1)
											result=num1-num;
										else
											result=result-num;
										gotoxy(51,9);
										printf("%Lf",result);
										count+=1;
										break;
									case '*':
										if(count<1)
											result=num1*num;
										else
											result=result*num;
										gotoxy(51,9);
										printf("%Lf",result);
										count+=1;
										break;
									case '/':
										if(count<1)
											result=num1/num;
										else
											result=result/num;
										gotoxy(51,9);
										printf("%Lf",result);
										count+=1;
										break;
									case 'r':
										if(count<1)
											result=sqrt(num1);
										else
											result=sqrt(result);
										gotoxy(51,9);
										printf("%Lf",result);
										count+=1;
										break;
									case 'o':
										if(count<1)
											result=sin(num1*0.01744);
										else
											result=sin(result*0.01744);
										gotoxy(51,9);
										printf("%Lf",result);
										count+=1;
										break;
									case 'p':
										if(count<1)
											result=pow(num1,num);
										else
											result=pow(result,num);
										gotoxy(51,9);
										printf("%Lf",result);
										count+=1;
										break;
								}
						}
						goto button_responded;
					}
					xcor+=50;
				}
				ycor+=50;
			}
		}
		button_responded:
		delay(200);
	}
	return;
}
long double addnum(int getnum){
	num=num*10+getnum;
	return num;
}
long double addfloat(long double getfloat){
	num=num+(getfloat/divcount);
	divcount=(divcount*10);
	return (num);
}
