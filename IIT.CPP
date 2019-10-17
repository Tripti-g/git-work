#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>
#include<process.h>
#include<string.h>
#include<iomanip.h>
long autobno();
int autoadmin();
void rect(int,int,int,int);
void dash();
void loading();
class book
{
 public:
	int bno;
	int noc;
	char cat[20];
	char bname[50];
	char aname[20];
	void create_book()
	{
		clrscr();
		rect(15,8,65,19);
		gotoxy(31,9);
		cprintf("NEW BOOK ENTRY");
		gotoxy(17,11);
		cprintf(" Book no:");
		bno=autobno();
		cprintf("%d",bno);
		gotoxy(17,13);
		cprintf("Enter Name of The Book:");
		gets(bname);
		gotoxy(17,14);
		cprintf("Enter Name of The author:");
		gets(aname);
		gotoxy(17,15);
		cprintf("Enter Category:");
		gets(cat);
		gotoxy(17,16);
		cprintf("Enter No.of copies:");
		cin>>noc;
	}

	void show_book()
	{
			rect(1,2,79,8);
			gotoxy(5,3);   cprintf("BOOK No");
			gotoxy(37,3);  cprintf("BOOK NAME");
			gotoxy(67,3);  cprintf("AUTHOR");
			gotoxy(6,4);   cprintf("%d",bno);
			gotoxy(38,4);  cprintf("%s",bname);
			gotoxy(68,4);  cprintf("%s",aname);
			getch();
	}
};
class student
{
 public:
	int  admno;
	char name[20],clas[10],mobno[30],address[30];
	int stbno[20];
	int tok;
	student()
	{
	   tok=0;
	}
	void create_student()
	{
		clrscr();
		rect(15,8,65,19);
		gotoxy(31,9);
		cprintf("NEW STUDENT ENTRY");
		gotoxy(17,11);
		cprintf("admission no:");
		admno=autoadmin();
		cprintf("%d",admno);
		gotoxy(17,12);
		cprintf("Enter The Name of The Student:");
		gets(name);
		gotoxy(17,13);
		cprintf("Enter Class:");
		gets(clas);
		gotoxy(17,14);
		cprintf("Enter Mobile no.:");
		gets(mobno);
		gotoxy(17,15);
		cprintf("Enter Address:");
		gets(address);
	}
	void show_student()
	{
			rect(2,2,78,8);
			textcolor(0);
			gotoxy(5,3);   cprintf("S. ID");
			gotoxy(13,3);  cprintf("NAME");
			gotoxy(30,3);  cprintf("Class");
			gotoxy(40,3);  cprintf("BOOK Issued");
			textcolor(15);
			gotoxy(6,4);   cprintf("%d",admno);
			gotoxy(14,4);  cprintf("%s",name);
			gotoxy(31,4);  cprintf("%s",clas);
			for(int i=0;i<tok;i++)
			{
			 gotoxy(41,4+i);  cprintf("%d ,",stbno[i]);
			}
	}
};
int autoadmin()
{       student st;
	int admin=0;
	ifstream fp;
	fp.open("student.dat",ios::in|ios::binary);
	while(fp.read((char*)&st,sizeof(student)))
	{
	  admin=st.admno;
	}
	admin++;
	fp.close();
	return admin;
}
long autobno()
{       long bno=0;
	book bk;
	ifstream fp;
	fp.open("book.dat",ios::in|ios::binary);
	while(fp.read((char*)&bk,sizeof(bk)))
	{
	    bno=bk.bno;
	}
	bno++;
	fp.close();
	return bno;
}
void write_book()
{
	char ch;
	book bk;
	ofstream fp;
	do
	{       fp.open("book.dat",ios::app|ios::binary);
		textbackground(2);
		clrscr();
		bk.create_book();
		fp.write((char*)&bk,sizeof(book));
		textbackground(6);
		clrscr();
		rect(26,11,54,17);
		gotoxy(28,12);
		cprintf("DO YOU WANT TO ADD MORE ?");
		rect(28,14,32,16);
		gotoxy(29,15);
		textcolor(WHITE);
		cprintf("YES");
		rect(48,14,52,16);
		gotoxy(49,15);
		textcolor(BLACK);
		cprintf("NO");
		gotoxy(40,20);
		textcolor(0);
		ch=getche();
		fp.close();
	}while(ch=='y'||ch=='Y');

}
///////////////////////////////////////////////////////////////////
void write_student()
{
	char ch;
	student st;
	ofstream fp;
	do
	{      	fp.open("student.dat",ios::app|ios::binary);
		textbackground(2);
		clrscr();
		st.create_student();
		fp.write((char*)&st,sizeof(st));    loading();
		gotoxy(19,15);
		textbackground(6);
		clrscr();
		rect(26,11,54,17);
		gotoxy(28,12);
		cprintf("DO YOU WANT TO ADD MORE ?");
		rect(28,14,32,16); gotoxy(29,15);
		textcolor(RED);
		cprintf("YES");
		rect(48,14,52,16); gotoxy(49,15);
		textcolor(GREEN);
		cprintf("NO");
		gotoxy(40,20);
		textcolor(0);
		ch=getche();
		fp.close();
	}while(ch=='y'||ch=='Y');

}
//////////////////////////////////////////////////////////////////////
void display_spb()
{
	int flag=0,n;
	clrscr();
	cprintf("ENTER THE BOOK NO.: ");   cin>>n;
	book bk;
	ifstream fp1;
	fp1.open("book.dat",ios::in|ios::binary);
	while(fp1.read((char*)&bk,sizeof(book)))
	{
		if(bk.bno==n)
		{       clrscr();
			rect(2,2,78,8);textcolor(0);
			gotoxy(4,3);   cprintf("BOOK ID");
			gotoxy(13,3);  cprintf("BOOK NAME");
			gotoxy(38,3);  cprintf("AUTHOR");
			gotoxy(53,3);  cprintf("CATEGORY");
			gotoxy(65,3);  cprintf("NO.of copy");
			textcolor(15);
			gotoxy(5,4);   cprintf("%d",bk.bno);
			gotoxy(14,4);  cprintf("%s",bk.bname);
			gotoxy(39,4);  cprintf("%s",bk.aname);
			gotoxy(54,4);  cprintf("%s",bk.cat);
			gotoxy(66,4);  cprintf("%d",bk.noc);
			flag=1;
		}
	}
	fp1.close();
	if(flag==0)
	cprintf("Book does not exist");
	getch();
}
///////////////////////////////////////////////////////////////////////////
void display_sps()
{       clrscr();
	int flag=0,n;
	cprintf("ENTER THE STUDENT ID: ");   cin>>n;
	clrscr();
	student st;
	ifstream fp;
	fp.open("student.dat",ios::in|ios::binary);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.admno==n)
		{
			rect(2,2,78,10);
			textcolor(0);
			gotoxy(5,3);   cprintf("S. ID");
			gotoxy(13,3);  cprintf("NAME");
			gotoxy(30,3);  cprintf("Class");
			gotoxy(40,3);  cprintf("Issued Book No.");
			gotoxy(6,4);   cprintf("%d",st.admno);
			gotoxy(14,4);  cprintf("%s",st.name);
			gotoxy(31,4);  cprintf("%s",st.clas);
			for(int i=0;i<st.tok;i++)
			{
			 gotoxy(41,4+i);  cprintf("%d ,",st.stbno[i]);
			}
			flag=1;
		 }
	}
	fp.close();
	if(flag==0)
	cprintf("Student does not exist");
	getch();
}
///////////////////////////////////////////////////////////////////////
void modify_book()
{
	int n;
	int found=0;
	textbackground(RED);
	clrscr();
	textcolor(0);
	cprintf("Enter The book no.:");
	cin>>n;
	book bk;
	fstream fp;
	fp.open("book.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&bk,sizeof(book)) && found==0)
	{
		if(bk.bno==n)
		{
			rect(2,2,78,8);     textcolor(0);
			gotoxy(5,3);   cprintf("Book No");
			gotoxy(13,3);  cprintf("Book NAME");
			gotoxy(38,3);  cprintf("AUTHOR");
			gotoxy(53,3);  cprintf("Category");
			gotoxy(65,3);  cprintf("No.of copy");
			textcolor(15);
			gotoxy(6,4);   cprintf("%d",bk.bno);
			gotoxy(14,4);  cprintf("%s",bk.bname);
			gotoxy(39,4);  cprintf("%s",bk.aname);
			gotoxy(54,4);  cprintf("%s",bk.cat);
			gotoxy(66,4);  cprintf("%d",bk.noc);
			rect(2,10,78,20);
			gotoxy(25,11);
			cprintf("Enter The New Details of the book");
			gotoxy(5,13);
			cprintf("Modify book Name : ");
			gets(bk.bname);
			gotoxy(5,14);
			cprintf("Modify Author Name : ");
			gets(bk.aname);
			gotoxy(5,15);
			cprintf("Modify Category : ");
			gets(bk.cat);
			gotoxy(5,16);
			cprintf("Modify No of copies : ");
			cin>>bk.noc;
			int pos=-1*sizeof(bk);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&bk,sizeof(book));
			gotoxy(5,18);
			cprintf(" Record Updated");            loading();
			found=1;
		}
	}

	fp.close();
	if(found==0)
	{       gotoxy(30,15);
		cprintf(" Record Not Found ");
	}
	getch();
}
//////////////////////////////////////////////////////////////////////////
void modify_student()
{
	int n;
	int found=0;
	textbackground(RED);
	clrscr();
	textcolor(0);
	cprintf("Enter The admission no. of The student");
	cin>>n;
	student st;
	fstream fp;
	fp.open("student.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.admno==n)
		{
			rect(2,2,78,6);     textcolor(0);
			gotoxy(4,3);   cprintf("S ID");
			gotoxy(13,3);  cprintf("NAME");
			gotoxy(38,3);  cprintf("class");
			gotoxy(53,3);  cprintf("mobile no");
			gotoxy(65,3);  cprintf("address");  textcolor(15);
			gotoxy(5,4);   cprintf("%d",st.admno);
			gotoxy(14,4);  cprintf("%s",st.name);
			gotoxy(39,4);  cprintf("%s",st.clas);
			gotoxy(54,4);  cprintf("%s",st.mobno);
			gotoxy(66,4);  cprintf("%s",st.address);
			rect(2,10,78,20);
			gotoxy(25,11);
			cprintf("Enter The New Details of student");
			gotoxy(5,13);
			cprintf("Modify Student Name : ");
			gets(st.name);
			gotoxy(5,14);
			cprintf("Modify Class: ");
			gets(st.clas);
			gotoxy(5,16);
			cprintf("Modify Mobie no. : ");
			gets(st.mobno);
			gotoxy(5,17);
			cprintf("Modify Address : ");
			gets(st.address);
			int pos=-1*sizeof(st);
			fp.seekp(pos,ios::cur);
			fp.write((char*)&st,sizeof(student));
			gotoxy(5,19);
			cprintf("Record Updated");
			found=1;
		}
	}

	fp.close();
	if(found==0)
	{
	   gotoxy(32,14);
	   cprintf("Record Not Found ");
	}
	getch();
}
///////////////////////////////////////////////////////////////////////
void delete_student()
{
	int n;
	int flag=0;
	clrscr();
	gotoxy(2,2);
	textcolor(0);
	cprintf("Enter Student ID : ");
	cin>>n;
	student st;
	fstream fp;
	fp.open("student.dat",ios::in|ios::out|ios::binary);
	fstream fp2;
	fp2.open("Temp.dat",ios::out|ios::binary);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.admno!=n)
			fp2.write((char*)&st,sizeof(student));
		else
			flag=1;
	}
	fp2.close();
	fp.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	if(flag==1)
	{	gotoxy(5,4);
		cprintf("Record Deletion successfull");
	}
	else
	{
		gotoxy(30,18);
		cprintf("Record not found");
	}
	getch();
}
//////////////////////////////////////////////////////////////////
void delete_book()
{
	int n; int flag;
	clrscr();
	gotoxy(2,2);
	cprintf("Enter Book Id: ");
	cin>>n;
	book bk;
	fstream fp;
	fp.open("book.dat",ios::in|ios::out|ios::binary);
	fstream fp2;
	fp2.open("Temp.dat",ios::out|ios::binary);
	fp.seekg(0,ios::beg);
	while(fp.read((char*)&bk,sizeof(book)))
	{
		if(bk.bno!=n)
		{
			fp2.write((char*)&bk,sizeof(book));
		}
		else
		  flag=1;
	}
	textcolor(0);
	fp2.close();
	fp.close();
	remove("book.dat");
	rename("Temp.dat","book.dat");
		if(flag==1)
	{
		gotoxy(5,4);
		cprintf("Record Deletion successfull...");
	}
	else
	{
		gotoxy(30,18);
		cprintf("Record not found...");
	}
	  getch();
}
/////////////////////////////////////////////////////////////////////////
void display_alls()
{       int y=4;
	textbackground(RED);
	clrscr();
	student st;
	ifstream fp;
	fp.open("student.dat",ios::in|ios::binary);
	rect(2,2,78,24); gotoxy(5,3);    textcolor(15);
	cprintf("S.ID");   gotoxy(13,3);cprintf("NAME");
	gotoxy(41,3);   cprintf("Mobile No.");
	gotoxy(55,3);   cprintf("ADDRESS");
	gotoxy(30,3);   cprintf("CLASS");
	while(fp.read((char*)&st,sizeof(student)))
	{      textcolor(0);
	       gotoxy(7,y);    cprintf("%d.",st.admno);
	       gotoxy(14,y);   cprintf("%s",st.name);
	       gotoxy(31,y);   cprintf("%s",st.clas);
	       gotoxy(42,y);   cprintf("%s",st.mobno);
	       gotoxy(56,y);   cprintf("%s",st.address);
	       y++;
	}
	fp.close();
	getch();
}
///////////////////////////////////////////////////////////////////////
void display_allb()
{
	textbackground(RED);
	clrscr();
	book bk;
	textcolor(0);
	ifstream fp;
	fp.open("book.dat",ios::in|ios::binary);
	int y=4;
			rect(2,2,78,24);    textcolor(0);
			gotoxy(5,3);   cprintf("Book No");
			gotoxy(13,3);  cprintf("Book NAME");
			gotoxy(38,3);  cprintf("AUTHOR");
			gotoxy(53,3);  cprintf("Category");
			gotoxy(65,3);  cprintf("No.of copy");
	while(fp.read((char*)&bk,sizeof(book)))
	{               textcolor(15);
			gotoxy(6,y);   cprintf("%d",bk.bno);
			gotoxy(14,y);  cprintf("%s",bk.bname);
			gotoxy(39,y);  cprintf("%s",bk.aname);
			gotoxy(54,y);  cprintf("%s",bk.cat);
			gotoxy(66,y);  cprintf("%d",bk.noc);
			y++;
	}
	fp.close();
	getch();
}
///////////////////////////////////////////////////////////////////////
void book_issue()
{
	char bname[30];
	int stdid;
	student st;
	fstream fp;
	fstream fp1;
	book bk;
	int found=0,flag=0;
	clrscr();
	rect(2,2,78,24);
	textcolor(0);
	gotoxy(5,4);
	cprintf("Enter The student's ID: ");
	cin>>stdid;
	fp.open("student.dat",ios::in|ios::out|ios::binary);
	fp1.open("book.dat",ios::in|ios::out|ios::binary);
	while(fp.read((char*)&st,sizeof(student)))
	{
		if(st.admno==stdid)
		{
				 found=1;
				 clrscr();
				 st.show_student();
				 gotoxy(5,10);
				 cprintf("Enter the book name: ");
				 gets(bname);
				 while(fp1.read((char*)&bk,sizeof(book)))
				 {              if((strcmpi(bk.bname,bname)==0)&&(bk.noc>0))
						{   clrscr();
						    bk.show_book();
						    flag=1;
						    st.stbno[st.tok]=bk.bno;
						    st.tok++;
						    bk.noc--;
						    int pos=-1*sizeof(st);
						    fp.seekp(pos,ios::cur);
						    fp.write((char*)&st,sizeof(student));
						    int pos1=-1*sizeof(bk);
						    fp1.seekp(pos1,ios::cur);
						    fp1.write((char*)&bk,sizeof(bk));
						    gotoxy(30,20);
						    cprintf("Book Issued successfully");
						    delay(400);
						 }
				  }
				if(flag==0)
				{
					gotoxy(20,18);
					cprintf("No copy Available");
					getch();
				}
		}
       }

	if(found==0)
	{   gotoxy(20,18);
	    cprintf("Student record not exist...");
	    getch();
	}
	fp.close();
	fp1.close();
}
/////////////////////////////////////////////////////////////////////////

void book_deposit()
{
    char bname[20];
    int sid;
    book bk;
    fstream fp;
    fstream fp1;
    student st;
    int found=0,flag=0;
    clrscr();
    rect(2,2,78,24);
    textcolor(0);
    gotoxy(5,3);
    cprintf("Enter The student ID:");
    cin>>sid;
    clrscr();
    fp.open("student.dat",ios::in|ios::out|ios::binary);
    fp1.open("book.dat",ios::in|ios::out|ios::binary);
    while(fp.read((char*)&st,sizeof(student)))
       {
	    if(st.admno==sid)
	    {
			found=1;
			rect(2,2,78,10);
			textcolor(0);
			gotoxy(5,3);   cprintf("S. ID");
			gotoxy(13,3);  cprintf("NAME");
			gotoxy(30,3);  cprintf("Class");
			gotoxy(40,3);  cprintf("Issued Book No.");
			gotoxy(6,4);   cprintf("%d",st.admno);
			gotoxy(14,4);  cprintf("%s",st.name);
			gotoxy(31,4);  cprintf("%s",st.clas);
			for(int i=0;i<st.tok;i++)
			{
				gotoxy(41,4+i);  cprintf("%d ",st.stbno[i]);
			}
			 getch();
			 gotoxy(5,12);
			 cprintf("Enter the book no: ");
			 int x;
			 cin>>x;
			 while(fp1.read((char*)&bk,sizeof(bk)))
			 {  if(bk.bno==x)
			    {
				clrscr();
				bk.show_book();
				flag=1;
				bk.noc++;
				st.tok--;
				int pos=-1*sizeof(st);
				fp.seekp(pos,ios::cur);
				fp.write((char*)&st,sizeof(student));
				int pos1=-1*sizeof(bk);
				fp1.seekp(pos1,ios::cur);
				fp1.write((char*)&bk,sizeof(bk));
				gotoxy(5,15);
				cprintf("Book deposited successfully...");
				delay(400);
			   }
			}
			  if(flag==0)
			  {
			      gotoxy(30,15);
			      cprintf("Book does not exist");
			      getch();
			  }
		}
	   }
      if(found==0)
      {  gotoxy(30,15);
	 cprintf("Student record not exist");
	 getch();
      }
	 fp.close();
	 fp1.close();
  }
void studbook()
{
	int y=4,x=0;
	textbackground(RED);
	clrscr();
	student st;
	ifstream fp;
	fp.open("student.dat",ios::in|ios::binary);
	rect(2,2,78,24); gotoxy(5,3);    textcolor(15);
	cprintf("S.ID");   gotoxy(13,3);cprintf("NAME");
	gotoxy(41,3);   cprintf("Mobile No.");
	gotoxy(55,3);   cprintf("Book alloted");
	gotoxy(30,3);   cprintf("CLASS");
	while(fp.read((char*)&st,sizeof(student)))
	{      textcolor(0);
	       gotoxy(8,y);    cprintf("%d.",st.admno);
	       gotoxy(14,y);   cprintf("%s",st.name);
	       gotoxy(31,y);   cprintf("%s",st.clas);
	       gotoxy(42,y);   cprintf("%s",st.mobno);
	       for(int i=0;i<st.tok;i++)
	       { x=x+4;
		 gotoxy(53+x,y);   cprintf("%d ,",st.stbno[i]);
	       }
	       y++;
	}
	fp.close();
	getch();

}
/////////////////////////////////////////////////////////////////////////
void admin_menu()
{
   int ch2;
   textbackground(2);
   clrscr();
   rect(22,2,60,22);
   textcolor(RED);
   gotoxy(32,3);
   cprintf("ADMINISTRATION MENU ");
   textcolor(RED);
   gotoxy(23,4);
   dash();
   gotoxy(23,5);
   dash();
   gotoxy(23,6);
   textcolor(1);
   cprintf("1.CREATE STUDENT RECORD");
   gotoxy(23,7);
   cprintf("2.DISPLAY ALL STUDENT RECORD");
   gotoxy(23,8);
   cprintf("3.DISPLAY SPECIFIC STUDENT RECORD");
   gotoxy(23,9);
   cprintf("4.MODIFY STUDENT RECORD");
   gotoxy(23,10);
   cprintf("5.DELETE STUDENT RECORD");
   gotoxy(23,11);
   dash();
   gotoxy(23,12);
   dash();
   gotoxy(23,13);
   cprintf("6.CREATE BOOK");
   gotoxy(23,14);
   cprintf("7.DISPLAY ALL BOOKS");
   gotoxy(23,15);
   cprintf("8.DISPLAY SPECIFIC BOOK");
   gotoxy(23,16);
   cprintf("9.MODIFY BOOK");
   gotoxy(23,17);
   cprintf("10.DELETE BOOK");
   gotoxy(23,18);
   cprintf("11.STUDENT AND BOOK");
   gotoxy(23,19);
   dash();
   gotoxy(23,20);
   cprintf("12.BACK TO MAIN MENU");
   gotoxy(23,21);
   textcolor(0);
   cprintf("please input your choice(1-12)");
   cin>>ch2;
   //  loading();
   switch(ch2)
   {
		case 1: clrscr();
			write_student();break;
		case 2: display_alls();break;
		case 3: display_sps();
			break;
		case 4: modify_student();break;
		case 5: delete_student();break;
		case 6: clrscr();
			write_book();break;
		case 7: display_allb();break;
		case 8: display_spb();
			break;
		case 9: modify_book();break;
		case 10: delete_book();break;
		case 11:studbook();
			break;
		case 12: return;
		default:cout<<"\a";
	}
	admin_menu();
}
 ////////////////////////////////function for making rectangle////////////
//////////////////////////////////////////////////////////////////////////
void rect(int x1,int y1,int x2,int y2)
{       textcolor(15);
	gotoxy(x1,y1);
	cprintf("Щ");
	gotoxy(x2,y1);
	cprintf("Л");
	gotoxy(x1,y2);
	cprintf("Ш");
	gotoxy(x2,y2);
	cprintf("М");
	for(int i=x1+1;i<x2;i++)
	{
	gotoxy(i,y1);
	cprintf("Э");
	}
	for(i=y1+1;i<y2;i++)
	{
	gotoxy(x2,i);
	cprintf("К");
	}
	for(i=y1+1;i<y2;i++)
	{
	gotoxy(x1,i);
	cprintf("К");
	}
	for(i=x1+1;i<x2;i++)
	{
	gotoxy(i,y2);
	cprintf("Э");
	}
}
////////////////////////////////function for loading1//////////////////////
////////////////////////////////////////////////////////////////////////////
void load()
{    textcolor(YELLOW);
     rect(20,22,60,24);
     int x=22,y=23;
     textcolor(MAGENTA);
  for(int i=1;i<20;i++)
  {
    gotoxy(x,y);   textcolor(i+1);
    cprintf("л ");
    x=x+2;
    delay(200);
    gotoxy(30,25);
    if((x>=24)&&(x<=34))
    cprintf("   LO@DING D@T@...");
    if((x>34)&&(x<=44))
    cprintf("   S Y N C I NG...");
    if((x>44)&&(x<=54))
    cprintf("   ALMOST  DONE...");
    if((x>54)&&(x<=64))
    cprintf("   HERE  WE  GO...");
  }
}
/////////////////////////////////////function for loading 2////////////////
////////////////////////////////////////////////////////////////////////////
void loading()
{
  int p=1,x=21,y=21,r=1;
  textcolor(YELLOW);
  rect(20,22,61,24);
  for(int i=0;i<10;i++)
 {
    gotoxy(x,y+2);
    textcolor(BLUE);
    cprintf("лл");
    x=x+2;
    gotoxy(x,y+2);
    cprintf("лл");      x=x+2;
    gotoxy(25,25);
    textcolor(BLUE);
    int q=p*(10);
    cprintf("LOADING %d% ",q);
    p++;
    delay(200);
    gotoxy(39,25);
    if((i%5==0)||(i==10))
    {
    cprintf("Time remaining:%d sec",r);
    r=r-1;
    }
 }
}
//////////////////////////////////function for introduction////////////////
///////////////////////////////////////////////////////////////////////////
void intro()
{   rect(1,1,80,21);
    textcolor(9); textbackground(4);
    gotoxy(14,5);
    cprintf("                                                       ");
    gotoxy(14,6);     textbackground(15);
    cprintf("  L I B R @ R Y   I N F O R M @ T I O N   S Y S T E M  ");
    gotoxy(14,7);     textbackground(2);
    cprintf("                                                       ");
    textcolor(5);     textbackground(0);
    gotoxy(35,14);
    cprintf("2017-2018");
    textcolor(7);
    gotoxy(25,10);
    cprintf("ST. MARY`S SEN. SEC. SCHOOL BANDA");
    textcolor(11);
    gotoxy(38,17);
    cprintf("BY-");
    textcolor(2+128);
    gotoxy(25,19);
    cprintf(" NARENDRA SINGH  XII B ");
    load();
}

void inline dash()
{
  cprintf("*************************************");
}
/////**///////////////////////**/////////*/////////////////////////////
void main()
{

	textbackground(0);
	clrscr();
	char ch3;
	intro();
	textbackground(0);
	top:
	do
	{        textbackground(4);
		 clrscr();
		 rect(22,2,60,22);
		 textcolor(0);
		 gotoxy(32,3);
		 cprintf("    MAIN MENU ");
		 gotoxy(23,4);
		 textcolor(0);    dash();
		 gotoxy(23,5);     dash();
		 gotoxy(33,6);    textcolor(15);
		 cprintf("1.  ISSUE BOOK");
		 gotoxy(23,7);     dash();
		 gotoxy(23,8);     dash();
		 gotoxy(33,9);
		 cprintf("2.  RETURN BOOK");
		 gotoxy(23,10);    dash();
		 gotoxy(23,11);    dash();
		 gotoxy(33,12);
		 cprintf("3.  ADMINISTRATION");
		 gotoxy(23,13);    dash();
		 gotoxy(23,14);    dash();
		 gotoxy(33,15);
		 cprintf("4.  FORMAT DATA");
		 gotoxy(23,16);    dash();
		 gotoxy(23,17);    dash();
		 gotoxy(33,18);
		 cprintf("5.  QIT");
		 gotoxy(23,19);    dash();
		 gotoxy(23,20);    dash();
		 gotoxy(25,21);
		 cprintf("please input your choice(1-5):");
		 ch3=getche();
		 switch(ch3)
		 {
			case '1':
				 loading();
				 clrscr();
				 book_issue();
				 break;
			case '2':
				 loading();
				 book_deposit();
				 break;
			case '3':
				 loading();
				 admin_menu();
				 break;
			case '5':
				 clrscr();
				 textbackground(6);	clrscr();
				 rect(26,11,54,17);     gotoxy(28,12);
				 cprintf("DO YOU WANT TO EXIT ?");
				 rect(28,14,32,16); gotoxy(29,15);
				 textcolor(RED);  cprintf("YES");
				 rect(48,14,52,16); gotoxy(49,15);
				 textcolor(GREEN); cprintf("NO");
				 gotoxy(40,20);  char ch5=getche();
				 if(ch5=='y'||ch5=='Y')
				 {
					int i=4;
					textbackground(12);
					clrscr();
					char ch[]={"THANKS FOR USING  "};
					rect(3,2,77,24);
					gotoxy(33,15);
					for( i=0;i<18;i++)
					{
					     cprintf("%c",ch[i]);
					     delay(200);
					}
				  }
					  exit(1);
					  break;
			      case '4': clrscr();
					cprintf("ARE YOU SURE??");
					char s;
					cin>>s;
					if(s=='Y'||s=='y')
				      {
					remove("book.dat");
					remove("student.dat");
				     }
			      default :cout<<"\a";
			      }
	}while(ch3!='5');
}