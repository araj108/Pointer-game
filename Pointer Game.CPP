#include<iostream.h>
#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>

int checkpass(char a[]);
int point();
void maimenu();
void box();
void demo();
void fun();

class id
{
public:
char uname[30],pass[20];
id()
{
strcpy(uname,NULL);
strcpy(pass,NULL);
ofstream fout("ACCOUNT.dat",ios::app);
fout.close();
}
char addr[50],phno[11];
char fname[30] ;
void save();
void login();
void chapas(id a);              //change password
void delid(id a);	       //delete account
void search();
};

class leabro:public id
{
public:
int score;
void leader();
void scor(id a,int score);
leabro()
{
score=0;
ofstream fout("score.dat",ios::app);
fout.close();
}
};

void menu(id a);
void sys(id a);
void game(id a);

void id::search()
{
clrscr();
char un[30];
id i;
int flag=0;
cout<<"\n\tEnter username to search ";
gets(un);
ifstream fin("ACCOUNT.dat");
while( fin.read((char*)&i,sizeof(i)) )
{
 if( strcmp(un,i.uname)==0 )
  {
   flag=1;
   cout<<"\n\tName "<<i.fname;
   cout<<"\n\tAddress "<<i.addr;
   cout<<"\n\tMobile no. "<<i.phno;
   break;
  }
}
if(flag==0)
{
cout<<"\n\tNot found ";
}
getch();
}

void id::delid(id a)
{
 clrscr();
 id i;
 char op;
 gotoxy(10,2);
 cout<<"ARE YOU CONFIRM TO DELETE YOUR ACCOUNT(y/n)";
 mark:
 op = getch();
 op=tolower(op);
 if(op=='y')
   {
     ifstream fin("ACCOUNT.dat");
     ofstream fout("temp.dat",ios::app | ios::binary);
      while( ! fin.eof())
	{
	fin.read( (char*)&i,sizeof(i) ) ;
	 if(strcmp(i.uname,a.uname) !=0 )
	   {
	     fout.write((char*)&i,sizeof(i)) ;
	   }
	}
	 fin.close();
	 fout.close();
	 remove("ACCOUNT.dat");
	 rename("temp.dat","ACCOUNT.dat");
    gotoxy(10,6);
    cout<<"                ";
    gotoxy(10,5);
    cout<<"Deleting account";
    gotoxy(10,6);
    for(int i=0;i<15;i++)
    {
    delay(200);
    cout<<"*";
    }
    gotoxy(10,10);
    cout<<"ACCOUNT DELETED";
    gotoxy(10,12);
    cout<<"PRESS ANY KEY TO GO TO MAINMENU";
    getch();
   }
 else if (op == 'n')
   {
   sys(a);
   }
 else
  {
   gotoxy(10,5);
   cout<<"INVALID CHOICE\a";
   gotoxy(10,6);
   cout<<"RE-ENTER CHOICE";
   goto mark;
  }

}

void id::chapas(id a)
{ clrscr();
  id i;
  int flag=0;
  char tpass[20];
  ifstream fin("ACCOUNT.dat");
   ofstream fout("temp.dat",ios::app | ios::binary);
gotoxy(10,22);
cout<<"New password ";

  while(fin.read((char*)&i,sizeof(i)))
   {
     if( strcmp(i.uname,a.uname) == 0 )
       {
	 while(flag == 0)
	  {
	    gotoxy(30,22);
	    gets(tpass);
	    int check = checkpass(tpass);
	     if(check == 0)
	       {
		strcpy(i.pass,tpass);
		flag=1;
		break;
	       }
	  }

       }

     fout.write((char*)&i,sizeof(i));
   }

  fout.close();
  remove("ACCOUNT.dat");
  rename("temp.dat","ACCOUNT.dat");
}

void id::login()
{
 int flag=0;
 char uname1[30],pass1[20];
 id i;
 ma:
  gotoxy(10,10);
  cout<<"Username ";
  gotoxy(10,12);
  cout<<"Password ";
  gotoxy(21,10);
  gets(uname1);
  gotoxy(21,12);
  gets(pass1);

  ifstream fin("ACCOUNT.dat");
      cout<<endl<<endl<<endl;
   while(!fin.eof())
     {

       fin.read( (char*)&i , sizeof(i) );
       if(strcmp( uname1,i.uname )==0 )
	 {
	   if(strcmp( pass1,i.pass )==0 )
	     {
	     flag=1;
	     break;
	     }
	 }

     }
      if(flag==1)
	menu(i);

      else
	{
	     gotoxy(10,14);
	     cout<<"Invaild username or password \a";
	     gotoxy(10,16);
	     cout<<"Want to RETRY (Y/N)";
	     char op;
	     check:
	     op=getch();
	      if(op=='Y'|| op=='y')
		{
		 clrscr();
		 goto ma;
		}
	      else if(op=='N'|| op=='n')
	      {
	       maimenu();
	      }
	      else
	      {
	       gotoxy(10,14);
	       cout<<"Invalid choice\a                   ";
	       gotoxy(10,16);
	       cout<<"Re-enter choice(Y/N)              ";
	       gotoxy(20,16);
	       goto check;
	      }
	  getch();
	}
   fin.close();
}

void id::save()
{
 id a,i;
 gotoxy(10,10);
 cout<<"First name ";
 gotoxy(10,14);
 cout<<"Username ";
 gotoxy(10,18);
 cout<<"Password ";
 gotoxy(21,10);
 gets(a.fname);
 a.fname[0]=toupper(a.fname[0]);

 int flag;
 mark:
 flag=0;
 gotoxy(21,14);
 gets(a.uname);

  ifstream in("ACCOUNT.dat");

   while(in.read( (char*)&i , sizeof(i) )  )
     {
	if( strcmp( a.uname , i.uname ) == 0 )
	 {
	   flag=1;
	   break;
	 }
     }
 int len;
   if(flag==1)
      {
	  aa:
	  gotoxy(30,11);
	  cout<<"Username already exists";
	  gotoxy(30,13);
	  cout<<"Want to re-enter(Y/N)\a";
	  char op;
	  op=getch();
	   if(op=='Y'||op=='y')
	     {
	       gotoxy(21,14);
	       cout<<"             ";
	       gotoxy(30,11);
	       cout<<"                       ";
	       gotoxy(30,13);
	       cout<<"                      ";
	       gotoxy(30,15);
	       cout<<"                ";
	       gotoxy(30,17);
	       cout<<"                              ";
	       goto mark;
	     }
	   else if(op=='N'||op=='n')
	   maimenu();

	   else
	     {
	       gotoxy(30,15);
	       cout<<"\aINVALID CHOICE";
	       gotoxy(30,17);
	       cout<<"Please re-enter your choice";
	       gotoxy(21,14);
	       cout<<"          ";
	       goto aa;
	     }

      }

   else
      {
	     ma:
	     gotoxy(21,18);
	     gets(a.pass);
	     len=strlen(a.pass);
	     int check=checkpass(a.pass);
	     if(check==1)
	       {
		gotoxy(10,20);
		cout<<"              ";
		gotoxy(10,22);
		cout<<"                  ";
		gotoxy(21,18);
		for(int cnt=0;cnt<len;cnt++)
		cout<<" ";
		goto ma;
	       }
	     else
	       {
	       int fla=0;
	       clrscr();
	       gotoxy(10,10);
	       cout<<"Address";
	       gotoxy(10,12);
	       cout<<"Mobile no.(10 digit)";
	       gotoxy(20,10);
	       gets(a.addr);
	       gotoxy(30,12);
	       while(1)
	       {
		fla=1;
		gets(a.phno);
		for(int i=0;i<10;i++)
		 {
		 if(!a.phno[i]>0 && !a.phno[i]<10 )
		   fla=0;
		 }
		   if(fla==0)
		   {
		   gotoxy(10,14);
		   cout<<"Invaild mobile no.\a";
		   gotoxy(10,12);
		   cout<<"Re-enter Mobile no.               ";
		   gotoxy(30,12);
		   }
		   else
			break;
	       }
	       clrscr();
	       gotoxy(15,10);
	       cout<<"First name "<<a.fname;
	       gotoxy(15,12);
	       cout<<"Username "<<a.uname;
	       gotoxy(15,14);
	       cout<<"Password "<<a.pass;
	       gotoxy(10,16);
	       cout<<"Address "<<a.addr;
	       gotoxy(10,18);
	       cout<<"Mobile no. "<<a.phno;
	       gotoxy(10,20);
	       cout<<"PRESS 1 to register & 2 to re-enter";
	       maa:
	       char op=getch();
	       if(op=='1')
		 {
		 clrscr();
		 ofstream fout("ACCOUNT.dat", ios::app|ios::binary);
		 fout.write( (char*)&a,sizeof(a) );
		 fout.close();
		 gotoxy(15,15);
		 cout<<"Creating account";
		 gotoxy(15,16);
		 for(int i=0;i<15;i++)
		  {
		  delay(200);
		  cout<<"*";
		  }
		 gotoxy(15,15);
		 cout<<"ACCOUNT CREATED  ";
		 gotoxy(15,16);
		 cout<<"PRESS ANY KEY TO RETURN TO MAIN MENU ";
		 getch();

		 }
	       else if(op=='2')
		 {
		 clrscr();
		 a.save();
		 }
	       else
		 {
		 gotoxy(10,22);
		 cout<<"Invalid choice\a";
		 gotoxy(10,20);
		 cout<<"Re-enter choice(1/2)                      ";
		 gotoxy(29,20);
		 goto maa;
		 }
	       }
      }

in.close();

}

int checkpass(char a[])
{
	     /* c - string lenght            u - uppercase characters
	       lc- lowercase characters     d - digits
	       m - digits b/w 1 & last ch   t - same characters
	       cu- concesutive uppercase    cl- concesutive lowercase
	       sd- sequential characters    ac-letters only
	       ad1,ad2-digit only*/
	      int c,u=0,lc=0,d=0,m=0,t=0,cu=0,cl=0,sd=1,ac=0,ad1=0,ad2=0;
	      int flag=1;
	      int sum;
	      c=strlen(a);

	      for(int i=0;i<c;i++)
	      {
		if( isupper(a[i]) )       //uppercase characters
		 u++;
		if( islower(a[i]) )      //lowercase characters
		 lc++;
		if( isdigit(a[i]) )       //digits
		 d++;
		if(a[i]==a[i+1]+1 || a[i]==a[i+1]-1)  //sequential characters
		 sd++;
		if( isalpha(a[i]) )
		 ad1++;
	      }
if(ad1==c)
ad2=ad1;
if(d==c)
ac=d;

for(i=1;i<c-1;i++)
{
if( isdigit(a[i]) )     //digits b/w 1 & last ch
m++;
}

for(i=0;i<c;i++)              //concesutive uppercase
{
if( isupper(a[i]) )
flag--;
else
flag=1;
if(flag<0)
cu++;
if(flag==-1)
cu++;
}
flag=1;
for(i=0;i<c;i++)              //concesutive lowercase
{
if( islower(a[i]) )
flag--;
else
flag=1;
if(flag<0)
cl++;
if(flag==-1)
cl++;
}

int ma=c-2;
char temp;
char te[30];
strcpy(te,a);

for(i=0;i<c;i++)                   //same characters
{
  for(int j=0;j<ma;j++)
  {
  if( te[j]>te[j+1] )
    {
    temp=te[j];
    te[j]=te[j+1];
    te[j+1]=temp;
    }

  }
}
flag=1;
for(i=0;i<c-1;i++)
{
 if( te[i]==te[i+1])
 {
 flag--;
 t++;
 }
 else
 flag=1;
 if(flag==0)
 t++;
}
sum=(c*4) + (u*2) + (lc*2) + (d*4) + (m*2) - ac - ad2 -(t*2) - (cu*2) -
(cl*2) - (sd*2);

    if(sum<=29)
      {
      gotoxy(10,20);
      cout<<"WEAK PASSWORD";
      gotoxy(10,22);
      cout<<"Re-enter password\a                    ";
      gotoxy(30,22);
      getch();
      return 1;
      }
    else if(sum<=59)
       {
	gotoxy(10,20);
	cout<<"AVERAGE PASSWORD";
       }
    else
       {
	gotoxy(10,20);
	cout<<"STRONG PASSWORD";
       }
     gotoxy(1,1);
     cout<<"PRESS ANY KEY TO CONTINUE";
     getch();

return 0;
}

void game(id a)
{
textbackground(8);
textcolor(1);
clrscr();
  int k=18,j;

  for(j=5 ;j<21 ;j++)
  {
  gotoxy(k,j);
  cout<<"";
  gotoxy(k+23,j);
  cout<<"";
  }
  j=5;
  for(k=18 ;k<42 ;k++)
  {
  gotoxy(k,j);
   cout<<"";
  gotoxy(k,j+15);
   cout<<"";
  }

gotoxy(22,8);
cout<<"P.Play game";
gotoxy(22,10);
cout<<"D.Demo";
gotoxy(22,12);
cout<<"L.Leaderbroad";
gotoxy(22,14);
cout<<"B.Back";
gotoxy(22,16);
cout<<"Enter Choice ";

char op;
m2:
op=getch();
op=tolower(op);
if(op=='p')
 {
 int score= point();
 leabro l;
 l.scor(a,score);
 game(a);
 }
else if(op=='d')
 {
 demo();
 game(a);
 }
else if(op=='l')
 {
  leabro l;
  l.leader();
  game(a);
 }
else if(op=='b')
menu(a);
else
 {
  gotoxy(22,18);
 cout<<"INVALID CHOICE\a";
 gotoxy(22,18);
 cout<<"              ";
 gotoxy(35,16);
 goto m2;
 }


}

void leabro::leader()
{
textbackground(6);
textcolor(7);
 clrscr();
 ifstream fin("score.dat");
 leabro l;
 int max[100]={NULL};
  int i=0,j,k,temp;
while( !fin.eof() )
  {
     fin.read((char*)&l,sizeof(l));
       max[i]=l.score;
       i++;
  }
  fin.close();

for(j=0;j<i;j++)
{
  for(k=j+1;k<i;k++)
   {
     if(max[j]<max[k])
      {
      temp=max[j];
      max[j]=max[k];
      max[k]=temp;
      }
   }
}

for(i=2;i<45;i++)
{
  gotoxy(i,2);
  cout<<"";
  gotoxy(i,4);
  cout<<"";
  gotoxy(i,15);
  cout<<"";
}
for(i=3;i<15;i++)
{
  gotoxy(2,i);
  cout<<"";
  gotoxy(9,i);
  cout<<"";
  gotoxy(36,i);
  cout<<"";
  gotoxy(44,i);
  cout<<"";
}
gotoxy(4,3);
cout<<"Rank";
gotoxy(20,3);
cout<<"Name";
gotoxy(38,3);
cout<<"Score";
j=1;
for(i=5;i<15;i++)
 {
   gotoxy(5,i);
   cout<<j;
   j++;
 }

for(i=0;i<10;i++)
 {
  ifstream in("score.dat");
  while( !in.eof())
    {
    in.read( (char*)&l,sizeof(l) );
    if(max[i]==l.score)
      {
      gotoxy(12,i+5);
      cout<<l.uname;
      gotoxy(38,i+5);
      cout<<l.score;
      }
    }
    in.close();
 }
getch();

}

void leabro::scor(id a,int scor)
{
 id i;
 leabro s;
 ifstream fin("ACCOUNT.dat");
 ofstream fout("score.dat",ios::app | ios::binary);
 while( fin.read( (char*)&i ,sizeof(i) ) )
  {
   if(strcmp(a.uname,i.uname)==0)
     {
      strcpy(s.fname,i.fname);
      strcpy(s.uname,i.uname);
      s.score=scor;
      fout.write((char*)&s,sizeof(s));
     }
  }
fin.close();
fout.close();
}

void menu(id a)
{
textbackground(9);
textcolor(7);
clrscr();
  int k=18,j;
gotoxy(18,3);
cout<<"Welcome "<<a.fname;
  for(j=6 ;j<21 ;j++)
  {
  gotoxy(k,j);
  delay(30);
  cout<<"Î";
  gotoxy(k+23,j);
  cout<<"Î";
  }
  j=6;
  for(k=18 ;k<42 ;k++)
  {
  gotoxy(k,j);
  delay(30);
   cout<<"Î";
  gotoxy(k,j+14);
   cout<<"Î";
  }

gotoxy(22,8);
cout<<"1.Pointer game";
gotoxy(22,10);
cout<<"2.System setting";
gotoxy(22,12);
cout<<"3.Search person";
gotoxy(22,14);
cout<<"4.Logout";
gotoxy(22,16);
cout<<"Enter Choice ";

char op;
m2:
op=getch();

if(op=='1')
 {
 game(a);
 menu(a);
 }
else if(op=='2')
 {
 sys(a);
 menu(a);
 }
else if(op=='3')
 {
 a.search();
 menu(a);
 }
else if(op=='4')
 {
 clrscr();
 char log[12]={"Logging out"};
 gotoxy(12,12);
 for(int q=0;q<12;q++)
 {
 delay(200);
 cout<<log[q];
 }
 maimenu();
 }
else
 {
  gotoxy(22,18);
 cout<<"INVALID CHOICE\a";
 gotoxy(22,18);
 cout<<"              ";
 gotoxy(35,16);
 goto m2;
 }

}

void sys(id a)
{
textbackground(8);
textcolor(1);
clrscr();
for(int k=26 ;k<61 ;k+=25)
{
  for(int j=5 ;j<18 ;j++)
  {
  gotoxy(k,j);
  cout<<"®";
  }
}
for(int j=5 ;j<31 ;j+=13)
{
  for(k=26 ;k<52 ;k++)
  {
  gotoxy(k,j);
  cout<<"®";
  }
}

gotoxy(29,8);
cout<<"1.Change password";
gotoxy(29,10);
cout<<"2.Deactivate account";
gotoxy(29,12);
cout<<"3.Home ";
gotoxy(29,14);
cout<<"Enter Choice ";
char op1;
mar:
op1=getch();

if(op1=='1')
 {
  a.chapas(a);
  sys(a);
 }
else if(op1=='2')
 {
  a.delid(a);
  maimenu();
 }
else if(op1=='3')
menu(a);
else
 {
 gotoxy(29,16);
 cout<<"\aINVALID CHOICE";
 delay(1000);
 gotoxy(29,16);
 cout<<"              ";
 gotoxy(42,14);
 goto mar;
 }

}

void box()
{
int x1 = 12, y1 = 4;
int a,i;
 for(i=1;i<10;i++)
    {
      gotoxy(x1,y1);
      cout<<i;
      x1=x1+10;
      if(x1>33)
	{
	x1=12;
	y1=y1+6;
	}

    }

   for(a=3;a<22;a+=6)
    {
     for(i=10;i<40;i++)
       {
       gotoxy(i,a);
       cout<<"";
       }
    }

   for(a=10;a<41;a+=10)
    {
     for(i=3;i<22;i++)
       {
       gotoxy(a,i);
       cout<<"";
       }
    }
}

void demo()
{
clrscr();
box();
gotoxy(43,4);
cout<<"You Will be Shown Pointers in the box ";
gotoxy(43,6);
delay(1000);
cout<<"Every correct answer will increase the ";
gotoxy(48,7);
cout<<"no.of pointer in the next level";
delay(1000);
gotoxy(43,9);
cout<<"You have to enter the sum of no. where";
gotoxy(48,10);
cout<<" the pointer are shown";
delay(1000);
gotoxy(15,12);
cout<<"*";
delay(700);
gotoxy(15,12);
cout<<" ";
gotoxy(35,12);
cout<<"*";
delay(700);
gotoxy(35,12);
cout<<" ";
gotoxy(61,12);
cout<<"Enter sum ";
gotoxy(71,12);
char arr[]={"4+6="};
for(int i=0;i<4;i++)
{
cout<<arr[i];
delay(700);
}
gotoxy(71,12);
cout<<"    ";
gotoxy(71,12);
cout<<"10";
gotoxy(1,1);
cout<<"PRESS ANY KEY TO CONTINUE";
getch();

}

int point()
{
clrscr();
char sym[10]={'','Þ','®','Î','*','š','$','%','@','!'};
int lv = 1, tem,del=250;
int cnt;
int sum,x;
int score=0,time;
int bonus[10]={15,10,8,7,5,4,3,2,1,0};
int pox[3]={6,12,18};
int poy[3]={15,25,35};

clrscr();
box();
gotoxy(1,1);
cout<<"Press any key to start";
getch();
gotoxy(1,1);
cout<<"                      ";
clock_t start,end;
while(1)
 {
   sum = 0;
   if(lv>5 && lv<8)
   del=del+100;
   cnt=0;
   randomize();
   for(int j=0;j<lv;j++)
   {
     x =random(9)+1;
     int tex,tey;
     if(x%3==0)
       {
       tey=2;
       tex=(x/3)-1;
       }
     else
       {
       tex=x/3;
       tey=(x%3)-1;
       }
      sum=sum+x;
      gotoxy(poy[tey],pox[tex]);
      cout<<sym[cnt];
      cnt++;
      if(cnt>=9)
      cnt=0;
      delay(del);
      gotoxy(poy[tey],pox[tex]);
      cout<<" ";
   }
   start = clock();
   gotoxy(61,10);
   cout<<"Enter sum ";
   gotoxy(71,10);
   cin>>tem;
     end = clock();
  time = (end - start)/CLK_TCK -1;

   if(tem==sum)
     {
     gotoxy(61,12);
     if(time >= 10)
     time=9;
     score = score + (lv*10) + bonus[time];
     gotoxy(61,14);
     cout<<"Your score is "<<score;
     gotoxy(61,15);
     cout<<"Got it RIGHT";
     gotoxy(61,16);
     cout<<"Time Bonus "<<bonus[time];
     lv++;
     }
   else
     {
     gotoxy(61,12);
     cout<<"Got it wrong ";
     gotoxy(61,13);
     cout<<"Correct anwer is "<<sum;
     gotoxy(61,14);
     cout<<"Your score is "<<score;
     getch();
     break;
     }
      getch();
      gotoxy(61,10);
      cout<<"             ";
      gotoxy(61,12);
      cout<<"                ";
      gotoxy(61,14);
      cout<<"                    ";
      gotoxy(61,15);
      cout<<"                   ";
      gotoxy(61,16);
      cout<<"                   ";

 }
return score;
}

void maimenu()
{
my:
textbackground(7);
textcolor(8);
   clrscr();
 gotoxy(34,5);
 cout<<"POINTER GAME";
 for(int k=28 ;k<59 ;k+=23)
  {
   for(int j=7;j<20 ;j++)
   {
   gotoxy(k,j);
   cout<<"";
   }
  }
 for(int j=7 ;j<30 ;j+=12)
  {
   for(k=28 ;k<52 ;k++)
   {
   gotoxy(k,j);
   cout<<"";
   }
  }
  gotoxy(32,9);
  cout<<"1.Log in";
 gotoxy(32,11);
 cout<<"2.Create account";
  gotoxy(32,13);
  cout<<"3.Exit";
 gotoxy(32,15);
 cout<<"Enter Choice ";

char op;
id i;
m2:
op=getch();

if(op=='1')
 {
 clrscr();
 i.login();
 goto my;
 }
else if(op=='2')
 {
 clrscr();
 i.save();
 goto my;
 }
else if(op=='3')
 exit(0);

else
 {
   gotoxy(32,17);
   cout<<"\aINVALID CHOICE";
   delay(1000);
     gotoxy(32,17);
     cout<<"              ";
   gotoxy(45,15);
  goto m2;
 }
getch();
}

void fun()
{
char ar1[]={"WELCOME"};
char ar2[]={"TO THE WORLD"};
char ar3[]={"OF POINTER GAME"};

clrscr();
for(int i=1;i<34;i++)
{
gotoxy(i,10);
delay(30);
cout<<ar1;
gotoxy(i-1,10);
cout<<" ";
}
for(i=69;i>30;i--)
{
gotoxy(i,12);
delay(29);
cout<<ar2;
gotoxy(i+12,12);
cout<<" ";
}
for(i=20;i>13;i--)
{
gotoxy(30,i);
delay(40);
cout<<ar3;
gotoxy(30,i+1);
cout<<"                 ";
}
gotoxy(25,16);
cout<<"Press any key to continue";
getch();
}

void main()
{
  fun();
  maimenu();
}