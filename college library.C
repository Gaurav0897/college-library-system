#include<stdio.h>
#include<conio.h>
#include<stdlib.h>/*contains header file of exit function*/
#include<graphics.h>
#include<time.h>
#include<dos.h>
#include<string.h>
struct student
{
int bookno,regno;
char name[20],author[20],publications[20],genre[20];
};
void read ();
void print();
void search();
void issue();
void issueprint();
void issuesearch();
void del();
main()
 { int ch;
 char name[10],password[10];
 float x, y;
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:\\tc\\bgi");
 setbkcolor(BLACK);
 setcolor(15);
settextstyle(4,0,5);
outtextxy(30,40,"Poornima College Of Engineering");
setcolor(15);
settextstyle(4,0,5);
outtextxy(30,40,"Poornima College Of Engineering");
setcolor(15);
settextstyle(8,0,8);
outtextxy(10,0,"___________");
setcolor(15);
settextstyle(8,0,8);
outtextxy(10,1,"___________");
setcolor(15);
settextstyle(8,0,8);
outtextxy(10,2,"___________");
setcolor(15);
settextstyle(8,0,3);
outtextxy(10,300,"GUIDED BY:-");
setcolor(3);
settextstyle(1,0,2);
outtextxy(10,350,"MR. SANJAY GUPTA");
setcolor(3);
settextstyle(1,0,2);
outtextxy(10,380,"(CHIEF PROCTOR)");
setcolor(15);
settextstyle(8,0,3);
outtextxy(400,300,"DEVELOPED BY:-");
setcolor(3);
settextstyle(1,0,1);
outtextxy(400,350,"LOVENISH GUPTA & ");
setcolor(3);
settextstyle(1,0,1);
outtextxy(400,375,"GAURAV SHARMA ");
setcolor(3);
settextstyle(1,0,2);
outtextxy(400,400,"E-SECTION");
setcolor(3);
settextstyle(1,0,2);
outtextxy(400,430,"CS");
getch();
cleardevice();
setcolor(15);
settextstyle(1,0,8);
outtextxy(150,20,"COLLEGE ");
setcolor(15);
settextstyle(1,0,7);
outtextxy(180,150,"LIBRARY");
setcolor(LIGHTBLUE);
settextstyle(1,0,4);
outtextxy(80,300,"PRESS ENTER TO RUN LIBRARY");
getch();
cleardevice();
settextstyle(2,0,6);
setcolor(WHITE);
outtextxy(1,10,"Enter username: ");
gotoxy(20,2);
scanf("%s",name);
outtextxy(1,30,"Enter password: ");
gotoxy(20,3);
scanf("%s",password);
if (strcmp(name, "admin") == 0 && strcmp(password, "poornima") == 0)
{printf("Access granted\n");

 while(1)
 {

  clrscr();
  setcolor(BLACK);
  setbkcolor(BLACK);
  settextstyle(1,0,1);
  outtextxy(1,10,"\n 1. Read details");
  setcolor(BLACK);
  outtextxy(1,40,"\n 2. print details");
  setcolor(BLACK);
  outtextxy(1,70,"\n 3. search details");
  setcolor(BLACK);
  outtextxy(1,100,"\n 4. delete");
  setcolor(BLACK);
  outtextxy(1,130,"\n 5. issue");
  setcolor(BLACK);
  outtextxy(1,160,"\n 6. issue details");
  setcolor(BLACK);
  outtextxy(1,190,"\n 7. exit");
  scanf("%d",&ch);
  switch (ch)
  {
  case 1: cleardevice();
	  read();
	  break;
  case 2: cleardevice();
	  print();
	  getch ();
	  break;
  case 3: cleardevice();
	  search();
	  getch();
	  break;
  case 4: cleardevice();
	  del();
	  getch();
	 break;
  case 5: cleardevice();
	 issue();
	 getch();
	 break;
  case 6:
	 cleardevice();
	 issueprint();
	 getch();
	 break;
  case 7:exit(1);
   }
  }
 }
else
{printf("ACCESS DENIED");
}
} void read()
 {
  FILE *fp;/*FILE is predefined datatype*/ /*fp is pointer variable*/
  struct student s;/*structure type variable capable of storing variable of diff. datatypes*/
  fp=fopen("std1.txt","a");/*w-new content storing, a-appendstores new data with pre existing data*/
  if (fp==NULL)
  {
   printf("\n Can't open file");
   exit(1);
  }
  setcolor(WHITE);
  outtextxy(1,10,"\n Enter book no.");
  gotoxy(40,2);
   flushall();
  scanf("%d",&s.bookno);
  /*flush all - it cleares data stored in particular location*/
  outtextxy(1,30,"\n Enter name of book.");
  gotoxy(40,3);
   flushall();
  gets(s.name);
  outtextxy(1,60,"\n Enter genre");
  gotoxy(40,5);
   flushall();
  scanf("%s",&s.genre);
  outtextxy(1,90,"\n enter name of author");
  gotoxy(40,7);
   flushall();
  scanf("%s",&s.author);
  outtextxy(1,120,"\n Enter name of publications");
  gotoxy(40,9);
   flushall();
  scanf("%s",&s.publications);
  fwrite(&s,sizeof(s),1,fp);/*it stores input formation into a file, 1 is quantity of variable*/
  fclose(fp);
 }
void print()

{FILE *fp;
 struct student s;
 fp=fopen ("std1.txt","r");
 if(fp==NULL)
 {
  printf("\n Cant open file");
  exit(1);
 }
while(fread(&s,sizeof(s),1,fp)==1)
{
 printf("\n book no.=%d",s.bookno);
 printf("\n Name=%s",s.name);
 printf("\n genre =%s",s.genre);
 printf("\n author=%s",s.author);
 printf("\n publications =%s",s.publications);
}
fclose(fp);
}
void search()/*it search a particular code in file and displays on console*/
{
 FILE *fp;
 struct student s;
 int n;
 fp=fopen ("std1.txt","r");
 if(fp==NULL)
 {
  printf("\n Cant open file");
  exit(1);
 }
 printf("\n enter book no. you want to search");
 scanf("%d",&n);
while(fread(&s,sizeof(s),1,fp)==1)
{
if(s.bookno==n)
{
 printf("\n book no.=%d",s.bookno);
 printf("\n Name=%s",s.name);
 printf("\n genre =%s",s.genre);
 printf("\n author=%s",s.author);
 printf("\n publications =%s",s.publications);

}
}
fclose(fp);
}
void issue()
{ FILE *fp;/*FILE is predefined datatype*/ /*fp is pointer variable*/

  struct student s;/*structure type variable capable of storing variable of diff. datatypes*/
  fp=fopen("std1.txt","b");/*w-new content storing, a-appendstores new data with pre existing data*/
     setcolor(WHITE);
     outtextxy(1,10,"enter your registration no. ");
   gotoxy(40,2);
  scanf("%d",&s.regno);
  flushall();/*flush all - it cleares data stored in particular location*/
  setcolor(WHITE);
  outtextxy(1,30,"enter your book no.");
  gotoxy(40,3);
  scanf("%d",&s.bookno);
{  struct tm date ;
  time_t timer;
  timer=time(NULL);
  date= *gmtime( &timer ) ;
  printf("\ndate of issue :%d/%d/%d",date.tm_mday,date.tm_mon+1,date.tm_year+1900);
  setcolor(WHITE);

  outtextxy(1,90,"Your Book Is Issued");
  fwrite(&s,sizeof(s),1,fp);/*it stores input formation into a file, 1 is quantity of variable*/
  fclose(fp);
 }
 }
void issueprint()
{
 FILE *fp;
 struct student s;
 int n;
 fp=fopen ("std1.txt","r");
 if(fp==NULL)
 {
  printf("\n Cant open file");
  exit(1);
 }

 setcolor(WHITE);
 outtextxy(1,10,"\n enter your bookno.");
 gotoxy(40,2);
 scanf("%d",&n);
while(fread(&s,sizeof(s),1,fp)==1)
{
if(s.bookno==n)
{
 printf("\n registration no.=%d",s.regno);
 printf("\n book no.=%d",s.bookno);
 printf("\n Name=%s",s.name);
 printf("\n genre =%s",s.genre);
 printf("\n author=%s",s.author);
 printf("\n publications =%s",s.publications);
{ struct tm date ;
  time_t timer;
  timer=time(NULL);
  date= *gmtime( &timer ) ;
  printf("\ndate of issue :%d/%d/%d",date.tm_mday,date.tm_mon+1,date.tm_year+1900);
  date.tm_year=date.tm_year;
  date.tm_mon=date.tm_mon;
  date.tm_mday=date.tm_mday+15;
  timer = mktime( &date);
  //printf(“%s”,asctime(localtime(&timer)));
  printf("\ndue date :%d/%d/%d\n",date.tm_mday,date.tm_mon+1,date.tm_year+1900);
 }
}
}
fclose(fp);
}


void del()
{
 FILE *f1,*f2;
 struct student s;
 int n;
 f1=fopen("std1.txt","r");
 f2=fopen ("temp.txt","w");
 if(f1==NULL||f2==NULL)
 {
  printf("\n Cant open file");
  exit(1);
 }
 setcolor(WHITE);
 outtextxy(1,30,"enter book no. you want to delete");
 gotoxy(40,3);
 scanf("%d",&n);
while(fread(&s,sizeof(s),1,f2)==1)
{
if(s.bookno!=n)
fwrite(&s,sizeof(s),1,f2);
}
fcloseall();
remove("std1.txt");
rename("temp.txt","std1.txt");
}
