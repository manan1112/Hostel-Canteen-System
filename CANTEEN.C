#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
//THE FUNCTIONS
void menu();
void student();
void order();
////////////


int pass;
////TYPE
struct menu
{
	char itemname[100];
	float itemprice;
};
struct student
{

	char name[100];
	int reg;
	char phno[20];
	float due;
};
struct student s1[100],s2;
struct menu m1[20];
int z=0,ch;
FILE *fp;
///////FUNCTIONS USED/////////////

/*MENU FUNCTIONS*/
void acceptmenu();
void updatemenu();
void displaymenu();
/*STUDENT FUNCTIONS*/
int searchstudent();
void updatestudent();
void deletestudent();
int getstudent();
int checkid(int);
void addstudent();
void displaystudent();
/*ORDER FUNCTION*/
float bill();
void order();
void duepayment();
////////////////////////////DECLARATIONS//////////////////////////
void password()
{
int k;
char p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11;
for(k=3;k>0;k--)
{

printf("\n\n\n  Enter your Password : \t\t\t\t(hint:manan)\n\t");
p1=getch();
printf("*");
p2=getch();
printf("*");
p3=getch();
printf("*");
p4=getch();
printf("*");
p5=getch();
printf("*");
if(((p1=='m')||(p1=='M'))&&((p2=='a')||(p2=='A'))&&((p3=='n')||(p3=='N'))&&((p4=='a')||(p4=='A'))&&((p5=='n')||(p5=='N')))
{
printf("\n\n\n\n  Correct Password......Press any key to continue");
getch();
pass=1;
break;
}
else
{
printf("\n\n\n\n  Incorrect Password......Press any key");
printf("\n\n  Trials Remaining:- %d",k-1);
getch();
pass=0;
}
}
}


////////////////////////////////Main Body///////////////////////////////
int main()
{
   char a;
  printf("\n");
  printf("\n\n\n\n\n\n");
  printf("\n********************************************************************************");
  printf("********************************************************************************");
  printf("\n  W       W       W  EEEEEE L      CCCCCC OOOOOO  M               M  EEEEEE");
  printf("\n  W      W W      W  E      L      C      O    O  M M           M M  E");
  printf("\n  W     W   W     W  E      L      C      O    O  M  M         M  M  E");
  printf("\n  W    W     W    W  EEEEEE L      C      O    O  M   M       M   M  EEEEEE");
  printf("\n  W   W       W   W  E      L      C      O    O  M    M     M    M  E");
  printf("\n  W  W         W  W  E      L      C      O    O  M     M   M     M  E");
  printf("\n  W W           W W  E      L      C      O    O  M      M M      M  E");
  printf("\n  W               W  EEEEEE LLLLLL CCCCCC OOOOOO  M       M       M  EEEEEE");
  printf("\n\n********************************************************************************");
  printf("********************************************************************************");
  printf("\n\n\n Press ENTER...........");
  getch();
  password();
  if(pass==0)
  {
  	return 0;
  }
  system("cls");
  printf("\n\n\n\n\n");
  printf("\t\xdb\xdb\xdb This Application only meant for HOSTEL CANTEEN MANAGER.\xdb\xdb\xdb");
  printf("\n\n\n\t\xdb\xdb\xdb It Can be operated by him only \xdb\xdb\xdb ");
  printf("\t\n\n Here, Manager can");
  printf("\t\n Modify the items which is in the canteen.");
  printf("\t\n Modify the Student records.");
  printf("\t\n Take Order.");
  getch();
  do
  {
  system("cls");
  printf("\n\n\t\t\t HOSTEL CANTEEN MANAGEMENT SYSTEM");
  printf("\n\t\t\t ^^^^^^ ^^^^^^^ ^^^^^^^^^^ ^^^^^^");
  printf("\n\t\t\t (By Manandeep Kaur)");
  printf("\n\n Enter Your Choice -");
  printf("\n\n 1. Canteen Items modifications");
  printf("\n\n 2.Student Related modifications and Due payment");
  printf("\n\n 3.Take Order");
  printf("\n\n 4.Exit");
  printf("\n\n Enter Your Choice :- ");
  fflush(stdin);
  scanf("%c",&a);
  if(a=='1')
  {
	  menu();
  }
 else if(a=='2')
  {
  	student();
  }
  else if(a=='3')
  {
  	order();
  }
  else if(a=='4')
  {
  exit(0);
  }
  else
  printf("\n MAKE A VALID CHOICE!!!!!");
  getch();
  }
  while(1);
}


void menu()
{
  char a;
  do
  {
  system("cls");
  printf("\n\n 1.Enter New Items in Menu");
  printf("\n\n 2.Update Menu");
  printf("\n\n 3.Display Menu");
  printf("\n\n 4.Exit from Menu Database");
  printf("\n\n Enter Your Choice :- ");
  fflush(stdin);
  scanf("%c",&a);
  if(a=='1')
  {
	  acceptmenu();
  }
  else if(a=='2')
  {
  	 updatemenu();
  }
  else if(a=='3')
  {
  	displaymenu();
  }
  else if (a=='4')
  {
  	break;
  }
  else
  printf("MAKE A VALID CHOICE!!!");
  getch();
  }while(1);
}

void acceptmenu()
{
	int n,j,k,r,o,i;
    FILE *fs,*fp;
	fs=fopen("noe.txt","r");
	if(fs!=NULL)
	{
	fscanf(fs,"%d",&n);
	fclose(fs);
	remove("noe.txt");
	}
	else
	n=0;
	k=0;
	fp=fopen("menuu.txt","a+");
	fs=fopen("noe.txt","w");
	printf("\n\n Enter the number of Elements you want to Enter in the Menu - \n");
	scanf("%d",&j);
	for (k=n+1;k<=j+n;k++)
	{
		i=k;
		x4:
		system("cls");
		printf("\n\n %d Item Name : ",k);
		fflush(stdin);
		gets(m1[k].itemname);
		r=0;
		r=strlen(m1[k].itemname);
		for(o=0;o<r;o++)
		{
		if(((m1[k].itemname[o]>='A')&&(m1[k].itemname[o]<='Z'))||((m1[k].itemname[o]>='a')&&(m1[k].itemname[o]<='z'))||(m1[k].itemname[o]==' '))
		{
		}
		else
		{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x4;
		}
		}
		printf("\n\n\t Price : ");
		r=scanf("%f",&m1[k].itemprice);
		if(r==0)
		{
		printf("\n\n ERROR !!! You have not entered a number... ");
		getch();
		goto x4;
		}
		fwrite(&m1,sizeof(m1),1,fp);
		getch();
	}
	fprintf(fs,"%d",n+j);
	fclose(fs);
	fclose(fp);
}

void updatemenu()
{
	int n1,c=0,i=0,n;
	int p,r,o;
	char x,y;
	struct menu m1[20];
	FILE *fs,*fp;
	system("cls");
	fs=fopen("noe.txt","r");
	fp=fopen("menuu.txt","r+");
	if((fp!=NULL)&&(fs!=NULL))
	{
		displaymenu();
	printf("\n\n Enter the item number you want to update -");
	scanf("%d",&n1);
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		x5:
		fread(&m1,sizeof(m1),1,fp);
	    if(i==n1)
		{
		system("cls");
		printf("\n\n Old Details -");
		printf("\n ^^^ ^^^^^^^");
		printf("\n\n  %d Item Name : %s",i,m1[i].itemname);
		printf("\n\n  Price : %.2f",m1[i].itemprice);
		p=sizeof(m1);
		fseek(fp,-p,SEEK_CUR);
		printf("\n\n Enter New Details -");
		printf("^^^^^ ^^^ ^^^^^^^");
		printf("\n\n  %d  Item Name : ",i);
		fflush(stdin);
		gets(m1[i].itemname);
		r=0;
		r=strlen(m1[i].itemname);
		for(o=0;o<r;o++)
		{
		if(((m1[i].itemname[o]>='A')&&(m1[i].itemname[o]<='Z'))||((m1[i].itemname[o]>='a')&&(m1[i].itemname[o]<='z'))||(m1[i].itemname[o]==' '))
		{
		}
		else
		{
		printf("\n\n ERROR !!! You have entered any other character in name... ");
		getch();
		goto x5;
		}
		}
		printf("\n  Price : ");
		r=scanf("%f",&m1[i].itemprice);
		if(r==0)
		{
		printf("\n\n ERROR !!! You have not entered a number... ");
		getch();
		goto x5;
		}
		c++;
		fwrite(&m1,p,1,fp);
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
		getch();
	}
	else
	printf("\n\n  Menu Updated....");
	fclose(fp);
	fclose(fs);
	}
	else
	printf("\n\n Menu doesn't exist");
	getch();
}


void displaymenu()
{
	FILE *fp,*fs;
	int i,n;
	char x,y;
	struct menu m1[20];
	system("cls");
	fs=fopen("noe.txt","r");
	fp=fopen("menuu.txt","r");
	if((fp!=NULL)&&(fs!=NULL))
	{
	fscanf(fs,"%d",&n);
	printf("\n\n\n ====================================MENU===================================");
	for(i=1;i<=n;i++)
	{
	fread(&m1,sizeof(m1),1,fp);
	printf("\n\n%d Item Name : %s",i,m1[i].itemname);
	printf("\nPrice  :  %.2f",m1[i].itemprice);
	}
	fclose(fp);
	fclose(fs);
	}
	else
	printf("\n\n Menu doesn't exist");
	getch();
}

//////////////////////////////////////////////////////////////////////
/*STUDENT RECORD*/
////////////////////////////////////////////////////////////////////////

void student()
{
char ch,e;
do
{
system("cls");
printf("\n\n 1.Add New Student");
printf("\n\n 2.Search Student Information");
printf("\n\n 3.Update Student Information");
printf("\n\n 4.Display All Information");
printf("\n\n 5.Remove All Data");
printf("\n\n 6.Exit from Student Database");
printf("\n\n Enter your choice :- ");
fflush(stdin);
scanf("%c",&ch);
if(ch=='1')
{
addstudent();
}
else if(ch=='2')
{
e=searchstudent();
}
else if(ch=='3')
{
updatestudent();
}
else if(ch=='4')
{
displaystudent();
}
else if(ch=='5')
{
deletestudent();
}
else if(ch=='6')
{
	break;
}
else
{
printf("\n\n You have entered a wrong choice");
getch();
}
}while(1);
}


int getstudent()
{
	int t;
	printf("Enter the Information Below");
    printf("\nROll NUMBER :");
    scanf("%d",&t);
    if(checkid(t)==0)
    {
		printf("\n The Roll no. already exists\n");
		getch();
		student();
		return 0;
	}
	s2.reg=t;
	printf("\n\nThe Roll no. :%d\n",s2.reg);
	printf("\nEnter the name: ");
    scanf("%s",&s2.name);
 	printf("\nEnter the phone number: ");
    scanf("%s",&s2.phno);

return 1;
}

int checkid(int t)
{
	rewind(fp);
	while(fread(&s2,sizeof(s2),1,fp)==1)
	if(s2.reg==t)
	{
        return 0;
    }
	return 1;
}

//***************************************************************
//        ADD RECORDS OF STUDENT
//****************************************************************

void addstudent()
{
	system("cls");
	int i;
	fp=fopen("STUDENT.txt","a+");
	if(getstudent()==1)
	{
		fseek(fp,0,SEEK_END);
		fwrite(&s2,sizeof(s2),1,fp);
		fclose(fp);
		printf("\nThe record is sucessfully saved\n");
	}
	printf("\n\n\n\n\nPress Ener to go back");
	getch();
	student();
}


int searchstudent()
{
	int d=0,find=0,z,ch,e;
	fp=fopen("STUDENT.txt","r+");
	rewind(fp);

			system("cls");
			printf("Enter the Rollno of Student :");
			scanf("%d",&d);
			while(fread(&s2,sizeof(s2),1,fp)==1)
			{
				if(s2.reg==d)
				{

			       printf("The Record is available\n");
					printf("\nRollno. : %d",s2.reg);
					printf("\nName : %s",s2.name);
					printf("\nPhone no. : %s", s2.phno);
					printf("\nDue Payment : %f",s2.due);
					find=1;
					e=d;
             	}
			}
				if(find!=1)
			{
				printf("\n No Record Found");
				z=1;
				e=0;
			}
			fclose(fp);
			getch();
			return e;
}


void updatestudent()
{
system("cls");
  int c=0;
  int d=0;
  char another='y';
  while(another=='y')
  {
	system("cls");
	printf("\n\n\nEnter Rollno. to be edited:\t");
	scanf("%d",&d);
	fp=fopen("STUDENT.txt","r+");
   while(fread(&s2,sizeof(s2),1,fp)==1)
	{
		if(checkid(d)==0)
		{
			printf("\n\nThis Member is available");
			printf("\n\nRoll no.:%d\t\t\n",s2.reg);
			printf("\n\nEnter new name:");
			scanf("%s",&s2.name);
			printf("\n\n Enter new Phone number :");
			scanf("%s",&s2.phno);
			printf("\n\n\t\t\tThe record is modified");
			fseek(fp,ftell(fp)-sizeof(s2),0);
			fwrite(&s2,sizeof(s2),1,fp);
			fclose(fp);
			c=1;
		}
	}
		if(c==0)
		{
			printf("No record found");
		}

	   printf("\n\nModify another Record?(Y/N)");
	   fflush(stdin);
   	   another=getch() ;
  }
	student();
}

void deletestudent()
{
	int x;
	fp=fopen("STUDENT.txt","r");
	system("cls");
	if(fp!=NULL)
	{
	printf("\n\nAll Student Data Deleted........");
	x=1;
	}
	else
	printf("\n\n Student record doesn't exist");
	if(x==1)
	{
	fclose(fp);
	remove("STUDENT.txt");
	}
	getch();
}



void displaystudent()
{
	int i,n=0;
	FILE *f1,*f2;
	system("cls");
	f1=fopen("STUDENT.txt","r");

		while(fread(&s2,sizeof(s2),1,f1)==1)
		{
			printf("\nRollno. - %d\n",s2.reg);
            printf("Name - %s\n",s2.name);
    		printf("Phoneno.- %s\n",s2.phno);
			printf("Due Payment - %f\n\n",s2.due);
		}
		fclose(f1);

	getch();
}
////////////////////////////////////////////////////////////
/*ORDER FUNCTION*/
///////////////////////////////////////////////////////////
void order()
{
	FILE *fs,*fp,*f1,*f2;
	int s,r;
	char k;
	float e;
	fs=fopen("noe.txt","r");
	fp=fopen("menuu.txt","r");
	if((fp!=NULL)&&(fs!=NULL))
	{
	do
	{
	system("cls");
	printf("\n\n Enter your choice :-");
	printf("\n\n 1.Student");
	printf("\n\n 2.Outsider");
	printf("\n\n 3.Exit to Main Menu ");
	fflush(stdin);
	scanf("%d",&ch);
	if(ch==1)
	{
		fp=fopen("STUDENT.txt","r");
		if(fp!=NULL)
		{
		duepayment();
	    }

	}
	else if(ch==2)
	{
		e=bill();
		printf("Your payment is %f",e);
		break;
	}
	else if(ch==3)
	{
		fclose(fp);
		fclose(fs);
		break;
	}
	else
	{
	printf("\n\n You have entered a wrong choice");
	getch();
	}
	}while(1);
	fclose(fp);
	fclose(fs);
	}
	else
	{
	system("cls");
	printf("\n\n Menu doesn't exist");
	getch();
	}
}
///////////////////////////////////////////////////////////////////////////////////////////
float bill()
{
	int df=0,o=0,t,j,c=0,a[100],q[100],i,n;
	float s=0;
	FILE *fs,*fp;
	system("cls");
	displaymenu();
	printf("\n\n Enter the total no. of Items you want to purchase - ");
	scanf("%d",&t);
	for(j=1;j<=t;j++)
	{
	i=j;
	c=0;
	printf("\n\n  %d Item No. = ",j);
	scanf("%d",&a[j]);
	printf("\n\n  Quantity = ");
	scanf("%d",&q[j]);
	fs=fopen("noe.txt","r");
	fp=fopen("menuu.txt","r");
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
		fread(&m1,sizeof(m1),1,fp);

		if(i==a[j])
		{
		printf("\n\n  Item Details -");
		printf("\n  ^^^^^^^^^^^^");
		printf("\n\n  %d Item Name - %s",i,m1[i].itemname);
		printf("\n\n  Price - %f",m1[i].itemprice);
		s=s+m1[i].itemprice*q[j];
		}
		c=1;
		df++;
		getch();
		}
	}
	if(c==0)
	{
		printf("\n\n Item doesn't Exist in the Menu ");
		getch();
	}
    fclose(fs);
	fclose(fp);
	if(df!=0)
	{
	system("cls");
	printf("\n ********************************* Cash Memo **********************************");
	printf("\n================================================================================");
	for(j=1;j<=t;j++)
	{
	fs=fopen("noe.txt","r");
	fp=fopen("menuu.txt","r");
	fscanf(fs,"%d",&n);
	for(i=1;i<=n;i++)
	{
	fread(&m1,sizeof(m1),1,fp);
	if(i==a[j])
	{
	++o;
    printf("\nSerial Number - %d",o);
    printf("\nItem name- %s",m1[i].itemname);
	printf("\nQuantity - %d",q[j]);
	printf("\nPrice - %f",m1[i].itemprice*q[j]);
	}
	}
	}
	printf("\n===============================================================================");
	printf(" \nTotal Payment = %f",s);
	printf("\n===============================================================================");
	getch();
	system("cls");
	fclose(fs);
	fclose(fp);
	return(s);
}
}


void duepayment()
{
	int r;
	float d=0,a,s;
	char t[40];
	system("cls");
	r=searchstudent();
	fp=fopen("STUDENT.txt","r");
	rewind(fp);
	while(fread(&s2,sizeof(s2),1,fp)==1)
	{
		if((s2.reg)==r)
		{
		fseek(fp,-sizeof(s2),SEEK_CUR);
		d=s2.due;
		break;
	    }
	}
		fclose(fp);
		s=bill();
	printf("\n\n Current Payment = %f",s);

	printf("\n\n Total Payment = %f",s+d);
	printf("\n\n Enter the amounnt,you want to pay now = ");
    scanf("%f",&a);
	printf("\n\n Remaining Balance = %f",s+d-a);
	d=s+d-a;
	fp=fopen("STUDENT.txt","r+");
	while(fread(&s2,sizeof(s2),1,fp)==1)
	{
		if(s2.reg==r)
		{
			s2.due=d;
			fseek(fp,-sizeof(s2),SEEK_CUR);
			fwrite(&s2,sizeof(s2),1,fp);
			break;
		}
	}

	fclose(fp);
	getch();
	order();
}


