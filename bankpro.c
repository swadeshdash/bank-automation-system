#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>

void clear();
void login();
void welcome();
void logo();
void disp_heading();
void main_menu();
void account_menu();
void transaction_menu();
void report_menu();
void new_account_menu();
void modify_account_menu();
void delete_account_menu();
void deposit_menu();
void withdraw_menu();
void balance_menu();
void account_report_menu();
void transaction_report_menu();
void date_wise_report_menu();
void individual_report_menu();

struct acc
{
	char acc_no[10];
	char name[30];
	char addr[50];
	char acc_type;
	int acc_bal;
	struct date op_date;
}st;
struct tran
{
	char acc_no[10];
	struct date tran_date;
	int prev_bal,cur_bal,tran_amt;
	char tr_type;
}tr;
FILE *fp,*ft;
const int min_bal=1000;
void main()
{
	int gm,gd=DETECT,i;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	welcome();
	main_menu();
	clear();
}

void clear()
{
	static int i=0;
	int x;
	if(i==0)
	{
		setcolor(0);
		setfillstyle(1,0);
		i=1;
		x=0;
		while(x<=400)
		{
			fillellipse(320,240,x,x);
			delay(1);
			x++;
		}
	}
	else
	{
		setcolor(15);
		setfillstyle(1,0);
		i=0;
		x=400;
		while(x>0)
		{
			fillellipse(320,240,x,x);
			delay(1);
			x--;
		}
	}
	setcolor(0);
	cleardevice();
}


void logo()
{
	int i;
	setcolor(4);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(8);
	rectangle(15,15,getmaxx()-15,getmaxy()-15);
	setcolor(4);
	rectangle(20,20,getmaxx()-20,getmaxy()-20);
	setfillstyle(1,9);
	setcolor(0);
	bar(25,25,615,100);
	setcolor(1);
	setfillstyle(1,1);
	fillellipse(65,63,35,35);
	setcolor(9);
	setfillstyle(1,9);
	fillellipse(65,63,9,9);
	bar(63,63,68,100);
	settextstyle(0,HORIZ_DIR,3);
	setcolor(15);
	outtextxy(120,45,"STATE BANK OF INDIA");
	setfillstyle(1,0);
	bar(120,70,575,75);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(175,78,"W i t h    Y o u  -  A l l    T h e    W a y");
	settextstyle(0,HORIZ_DIR,3);
	setcolor(13);
	for(i=24;i<600;i+=2)
	{
		outtextxy(i,140,"=");
		outtextxy(i,410,"=");
		delay(1);
	}
}

void welcome()
{
	int i;
	char ch;
	clear();
	setbkcolor(0);
	cleardevice();
	setcolor(4);
	setlinestyle(2,2,2);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(8);
	rectangle(15,15,getmaxx()-15,getmaxy()-15);
	setcolor(4);
	rectangle(20,20,getmaxx()-20,getmaxy()-20);
	settextstyle(10,HORIZ_DIR,4);
	setcolor(10);
	outtextxy(130,15,"W E L C O M E");
	setcolor(15);
	outtextxy(265,65,"T O");
	setcolor(13);
	outtextxy(50,115,"STATE BANK OF INDIA");
	setfillstyle(1,1);
	setcolor(0);
	fillellipse(getmaxx()/2,270,90,90);
	setcolor(0);
	setfillstyle(1,0);
	bar(315,290,325,380);
	fillellipse(getmaxx()/2,270,20,20);
	settextstyle(10,HORIZ_DIR,15);
	setcolor(14);
	settextstyle(4,HORIZ_DIR,3);
	outtextxy(180,355,"Developed By:-");
	settextstyle(11,HORIZ_DIR,10);
	setcolor(7);
	outtextxy(300,390,"Swadesh Ranjan Dash");
	outtextxy(300,400,"B.tech");
	outtextxy(300,410,"Regd No : 0901206216");
	outtextxy(300,420,"Under The Guidance Of=>Binayak Sir,ctc");
	outtextxy(300,430,"A.B.I.T");
	outtextxy(300,440,"B.P.U.T");
	ch=getch();
	if(ch==27)
		return;
	else
		login();
}

void login()
{
	int i;
	char ch,id[20],pw[20];
	clear();
	setbkcolor(0);
	cleardevice();
	setcolor(4);
	rectangle(10,10,getmaxx()-10,getmaxy()-10);
	setcolor(8);
	rectangle(15,15,getmaxx()-15,getmaxy()-15);
	setcolor(4);
	rectangle(20,20,getmaxx()-20,getmaxy()-20);
	setfillstyle(1,9);
	setcolor(0);
	bar(30,30,610,254);
	setcolor(1);
	setfillstyle(1,1);
	fillellipse(142,142,110,110);
	setcolor(9);
	setfillstyle(1,9);
	fillellipse(142,142,25,25);
	bar(133,150,147,254);
	settextstyle(8,HORIZ_DIR,4);
	setcolor(15);
	outtextxy(240,30,"State Bank of India");
	setcolor(0);
	setfillstyle(1,0);
	bar(240,75,590,80);
	setcolor(15);
	settextstyle(2,HORIZ_DIR,5);
	outtextxy(255,80,"W i t h   Y o u  -  A l l   T h e   W a y");
	settextstyle(7,HORIZ_DIR,5);
	setcolor(13);
	outtextxy(270,120,"Pure Banking");
	outtextxy(290,180,"Nothing Else");
	login:
	setfillstyle(1,8);
	setcolor(6);
	bar(100,280,540,385);
	setcolor(2);
	settextstyle(3,HORIZ_DIR,4);
	setcolor(0);
	outtextxy(150,292,"USER ID  ");
	outtextxy(150,337,"PASSWORD ");
	setfillstyle(1,0);
	setcolor(0);
	bar(320,302,500,320);
	bar(320,350,500,368);
	setfillstyle(1,0);
	bar(100,385,540,445);
	settextstyle(2,HORIZ_DIR,7);
	setcolor(13);
	outtextxy(170,400,"Enter Login ID and Password");
	gotoxy(41,20);
	printf("_");
	gotoxy(41,20);
	i=0;
	do
	{
		ch=getch();
		if(i==20 && ch!=13 && ch!=9)
		{
			if(ch==8)
			{
				gotoxy(41+i-1,20);
				printf(" ");
				gotoxy(41+i-1,20);
				i--;
			}
			else
				printf("\a");
		}
		else if(ch==8)
		{
			if(i!=0)
			{
				gotoxy(41+i-1,20);
				printf(" ");
				gotoxy(41+i-1,20);
				i--;
			}
		}
		else if(ch==13 || ch==9)
		{
			id[i]=NULL;
			break;
		}
		else
			printf("%c",id[i++]=ch);
	}while(1);
	gotoxy(41,23);
	printf("_");
	gotoxy(41,23);
	i=0;
	do
	{
		ch=getch();
		if(i==20 && ch!=13)
		{
			if(ch==8)
			{
				gotoxy(41+i-1,23);
				printf(" ");
				gotoxy(41+i-1,23);
				i--;
			}
			else
				printf("\a");
		}
		else if(ch==8)
		{
			if(i!=0)
			{
				gotoxy(41+i-1,23);
				printf(" ");
				gotoxy(41+i-1,23);
				i--;
			}
		}
		else if(ch==13)
		{
			pw[i]=NULL;
			break;
		}
		else
		{
			pw[i++]=ch;
			printf("*");
		}
	}while(1);
	if(strcmp(id,"sbi")==0 && strcmp(pw,"oca")==0)
		main_menu();
	else
	{
		setfillstyle(1,0);
		bar(100,385,540,445);
		settextstyle(1,HORIZ_DIR,2);
		setcolor(4);
		outtextxy(150,390,"INVALID USERNAME AND PASSWORD");
		settextstyle(2,HORIZ_DIR,6);
		setcolor(13);
		outtextxy(120,420,"Press Enter To Retry and ESC to Terminate");
		ch=getch();
		if(ch==27)
			return;
		else
			goto login;
	}
}

void disp_heading()
{
	settextstyle(1,HORIZ_DIR,2);
	setcolor(7);
	outtextxy(30,168,"Account No");
	outtextxy(190,168,":");
	outtextxy(30,215,"Account Type");
	outtextxy(190,215,":");
	outtextxy(30,265,"Account Holder");
	outtextxy(190,265,":");
	outtextxy(30,312,"Address");
	outtextxy(190,312,":");
	outtextxy(410,168,"Date");
	outtextxy(500,168,":");
	outtextxy(415,215,"Balance");
	outtextxy(500,215,":");
}

void main_menu()
{
	char op=0;
	clear();
	logo();
	do
	{
		if(op)
		{
			clear();
			logo();
		}
		settextstyle(0,HORIZ_DIR,3);
		setcolor(14);
		outtextxy(115,110,"M A I N   M E N U");
		settextstyle(3,HORIZ_DIR,4);
		setcolor(11);
		outtextxy(180,190,"1. ACCOUNT");
		outtextxy(180,240,"2. TRANSACTION");
		outtextxy(180,290,"3. REPORT");
		outtextxy(180,340,"4. EXIT");
		op=getch();
		switch(op)
		{
			case '1':
			case 'A':
			case 'a':
				account_menu();
				break;
			case '2':
			case 't':
			case 'T':
				transaction_menu();
				break;
			case '3':
			case 'R':
			case 'r':
				report_menu();
				break;
			case '4':
			case 27:
				return;
			default:
				op=NULL;
		}
	}while(1);
}

void account_menu()
{
	char op=0;
	clear();
	logo();
	do
	{
		if(op)
		{
			clear();
			logo();
		}
		settextstyle(0,HORIZ_DIR,3);
		setcolor(14);
		outtextxy(165,110,"A C C O U N T");
		settextstyle(3,HORIZ_DIR,4);
		setcolor(11);
		outtextxy(180,190,"1. NEW ACCOUNT");
		outtextxy(180,240,"2. MODIFY ACCOUNT");
		outtextxy(180,290,"3. DELETE ACCOUNT");
		outtextxy(180,340,"4. BACK");
		op=getch();
		switch(op)
		{
			case '1':
			case 'n':
			case 'N':
				new_account_menu();
				break;
			case '2':
			case 'M':
			case 'm':
				modify_account_menu();
				break;
			case '3':
			case 'D':
			case 'd':
				delete_account_menu();
				break;
			case '4':
			case 27:
				return;
			default:
				op=NULL;
		}
	}while(1);
}

void transaction_menu()
{
	int i;
	char op=0;
	clear();
	logo();
	do
	{
		if(op)
		{
			clear();
			logo();
		}
		settextstyle(0,HORIZ_DIR,3);
		setcolor(14);
		outtextxy(70,110,"T R A N S A C T I O N");
		settextstyle(3,HORIZ_DIR,4);
		setcolor(11);
		outtextxy(180,190,"1. DEPOSIT");
		outtextxy(180,240,"2. WITHDRAW");
		outtextxy(180,290,"3. BALANCE INQUARY");
		outtextxy(180,340,"4. BACK");
		op=getch();
		switch(op)
		{
			case '1':
			case 'D':
			case 'd':
				deposit_menu();
				break;
			case '2':
			case 'W':
			case 'w':
				withdraw_menu();
				break;
			case '3':
			case 'B':
			case 'b':
				balance_menu();
				break;
			case '4':
			case 27:
				return;
			default:
				op=NULL;
		}
	}while(1);
}

void report_menu()
{
	int i;
	char op=0;
	clear();
	logo();
	do
	{
		if(op)
		{
			clear();
			logo();
		}
		settextstyle(0,HORIZ_DIR,3);
		setcolor(14);
		outtextxy(190,110,"R E P O R T");
		settextstyle(3,HORIZ_DIR,4);
		setcolor(11);
		outtextxy(180,190,"1. Account Report");
		outtextxy(180,240,"2. Transaction Report");
		outtextxy(180,290,"3. BACK");
		op=getch();
		switch(op)
		{
			case '1':
			case 'A':
			case 'a':
				account_report_menu();
				break;
			case '2':
			case 't':
			case 'T':
				transaction_report_menu();
				break;
			case '3':
			case 27:
				return;
			default:
				op=NULL;
		}
	}while(1);
}

void transaction_report_menu()
{
	int i;
	char op=0;
	clear();
	logo();
	do
	{
		if(op)
		{
			clear();
			logo();
		}
		settextstyle(0,HORIZ_DIR,3);
		setcolor(14);
		outtextxy(105,110,"TRANSACTION REPORT");
		settextstyle(3,HORIZ_DIR,4);
		setcolor(11);
		outtextxy(180,190,"1. date wise");
		outtextxy(180,240,"2. Individual");
		outtextxy(180,290,"3. BACK");
		op=getch();
		switch(op)
		{
			case '1':
			case 'D':
			case 'd':
				date_wise_report_menu();
				break;
			case '2':
			case 'i':
			case 'I':
				individual_report_menu();
				break;
			case '3':
			case 27:
				return;
			default:
				op=NULL;
		}
	}while(1);
}

void new_account_menu()
{
	char ch,bal[10],i;
	clear();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(60,100,"A C C O U N T  C R E A T I O N");
	disp_heading();
	getdate(&st.op_date);
	gotoxy(65,12);
	if(st.op_date.da_day<10)
		printf("0%d-",st.op_date.da_day);
	else
		printf("%d-",st.op_date.da_day);
	if(st.op_date.da_mon<10)
		printf("0%d-",st.op_date.da_mon);
	else
		printf("%d-",st.op_date.da_mon);
	printf("%d",st.op_date.da_year);
	gotoxy(65,15);
	do
	{
		gotoxy(26,12);
		printf("_");
		gotoxy(26,12);
		fflush(stdin);
		gets(st.acc_no);
	}while(!strlen(st.acc_no));
	do
	{
		gotoxy(26,15);
		printf("_                        ");
		gotoxy(26,15);
		fflush(stdin);
		scanf("%c",&st.acc_type);
		st.acc_type=toupper(st.acc_type);
		if(st.acc_type=='S' || st.acc_type=='C')
			break;
	}while(1);
	do
	{
		gotoxy(65,15);
		printf("_           ");
		gotoxy(65,15);
		fflush(stdin);
		gets(bal);
		for(i=0;bal[i]!='\0';i++)
			if(!isdigit(bal[i]))
			{
				bal[0]=NULL;
				break;
			}
	}while(!strlen(bal));
	st.acc_bal=atoi(bal);
	do
	{
		gotoxy(26,18);
		printf("_");
		gotoxy(26,18);
		flushall();
		gets(st.name);
	}while(!strlen(st.name));
	do
	{
		gotoxy(26,21);
		printf("_");
		gotoxy(26,21);
		gets(st.addr);
	}while(!strlen(st.addr));
	settextstyle(1,HORIZ_DIR,2);
	setcolor(10);
	outtextxy(150,350,"WANT TO SAVE THE RECORD ?");
	outtextxy(190,380,"PRESS (Y)ES OR (N)O");
	flushall();
	ch=getch();
	if(toupper(ch)=='Y' || ch==13)
	{
		fp=fopen("acc.dat","ab");
		if(fp!=NULL)
			fwrite(&st,sizeof(st),1,fp);
		fclose(fp);
	}
}

void modify_account_menu()
{
	char ch,ac_no[10];
	int i=0,ctr=0;
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(85,100,"M O D I F Y   A C C O U N T");
	disp_heading();
	fp=fopen("acc.dat","rb");
	if(fp!=NULL)
	{
		gotoxy(69,15);
		do
		{
			gotoxy(26,12);
			printf("_");
			gotoxy(26,12);
			fflush(stdin);
			gets(ac_no);
		}while(!strlen(ac_no));

		while(fread(&st,sizeof(st),1,fp))
		{
			if(strcmp(st.acc_no,ac_no)==0)
			{
				gotoxy(65,12);
				if(st.op_date.da_day<10)
					printf("0%d-",st.op_date.da_day);
				else
					printf("%d-",st.op_date.da_day);
				if(st.op_date.da_mon<10)
					printf("0%d-",st.op_date.da_mon);
				else
					printf("%d-",st.op_date.da_mon);
				printf("%d",st.op_date.da_year);
				gotoxy(26,15);
				printf("%c",st.acc_type);
				gotoxy(65,15);
				printf("%u",st.acc_bal);
				gotoxy(26,18);
				puts(st.name);
				gotoxy(26,21);
				puts(st.addr);
				i=1;
				settextstyle(1,HORIZ_DIR,2);
				setcolor(10);
				outtextxy(150,350,"WANT TO EDIT THE RECORD ?");
				outtextxy(190,380,"PRESS (Y)ES OR (N)O");
				ch=getch();
				break;
			}
			ctr++;
		}
		if(i!=1)
		{
			settextstyle(1,HORIZ_DIR,2);
			setcolor(10);
			outtextxy(120,350,"ACCOUNT DOES NOT EXIST ... .. . .");
			getch();
		}
	}
	fclose(fp);
	if(toupper(ch)=='Y' || ch==13)
	{
		gotoxy(26,18);
		puts("                      ");
		do
		{
			gotoxy(26,18);
			printf("_");
			gotoxy(26,18);
			flushall();
			gets(st.name);
		}while(!strlen(st.name));

		gotoxy(26,21);
		puts("                      ");
		do
		{
			gotoxy(26,21);
			printf("_");
			gotoxy(26,21);
			gets(st.addr);
		}while(!strlen(st.addr));
		bar(150,350,500,410);
		settextstyle(1,HORIZ_DIR,2);
		setcolor(10);
		outtextxy(150,350,"WANT TO SAVE THE RECORD ?");
		outtextxy(190,380,"PRESS (Y)ES OR (N)O");
		ch=getch();
		if(toupper(ch)=='Y' || ch==13)
		{
			fp=fopen("acc.dat","rb+");
			if(fp!=NULL)
			{
				fseek(fp,ctr*sizeof(st),SEEK_SET);
				fwrite(&st,sizeof(st),1,fp);
			}
			fclose(fp);
		}
	}
}

void delete_account_menu()
{
	char ch,ac_no[10];
	int i=0;
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(60,100,"D E L E T E   A C C O U N T");
	disp_heading();
	fp=fopen("acc.dat","rb");
	ft=fopen("temp.dat","wb");
	if(fp!=NULL && ft!=NULL)
	{
		gotoxy(69,15);
		do
		{
			gotoxy(26,12);
			printf("_");
			gotoxy(26,12);
			fflush(stdin);
			gets(ac_no);
		}while(!strlen(ac_no));

		while(fread(&st,sizeof(st),1,fp))
		{
			if(strcmp(st.acc_no,ac_no)==0)
			{
				gotoxy(65,12);
				if(st.op_date.da_day<10)
					printf("0%d-",st.op_date.da_day);
				else
					printf("%d-",st.op_date.da_day);
				if(st.op_date.da_mon<10)
					printf("0%d-",st.op_date.da_mon);
				else
					printf("%d-",st.op_date.da_mon);
				printf("%d",st.op_date.da_year);
				gotoxy(26,15);
				printf("%c",st.acc_type);
				gotoxy(65,15);
				printf("%u",st.acc_bal);
				gotoxy(26,18);
				puts(st.name);
				gotoxy(26,21);
				puts(st.addr);
				i=1;
				settextstyle(1,HORIZ_DIR,2);
				setcolor(10);
				outtextxy(150,350,"WANT TO DELETE THE RECORD ?");
				outtextxy(190,380,"PRESS (Y)ES OR (N)O");
				fflush(stdin);
				ch=getch();
			}
			else
				fwrite(&st,sizeof(st),1,ft);
		}
		if(i!=1)
		{
			settextstyle(1,HORIZ_DIR,2);
			setcolor(10);
			outtextxy(120,350,"ACCOUNT DOES NOT EXIST ... .. . .");
			getch();
		}
	}
	fclose(fp);
	fclose(ft);
	if(toupper(ch)=='Y' || ch==13)
	{
		remove("acc.dat");
		rename("temp.dat","acc.dat");
		bar(150,350,500,410);
		settextstyle(1,HORIZ_DIR,2);
		setcolor(10);
		outtextxy(150,355,"ACCOUNT DELETED ... .. .. . .");
		getch();
	}
	else
		remove("temp.dat");
}

void deposit_menu()
{
	int i,amt,ctr=0;
	char ch,ac_no[10],bal[10];
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(210,100,"D E P O S I T");
	disp_heading();
	fp=fopen("acc.dat","rb+");
	settextstyle(1,HORIZ_DIR,3);
	if(fp!=NULL)
	{
		do
		{
			gotoxy(26,12);
			printf("_");
			gotoxy(26,12);
			fflush(stdin);
			gets(ac_no);
		}while(!strlen(ac_no));

		while(fread(&st,sizeof(st),1,fp))
		{
			if(!strcmp(st.acc_no,ac_no))
			{
				i=1;
				break;
			}
			ctr++;
		}
		if(i!=1)
		{
			settextstyle(1,HORIZ_DIR,2);
			setcolor(10);
			outtextxy(120,350,"ACCOUNT DOES NOT EXIST ... .. . .");
			getch();
		}
		else
		{
			gotoxy(65,12);
			if(st.op_date.da_day<10)
				printf("0%d-",st.op_date.da_day);
			else
				printf("%d-",st.op_date.da_day);
			if(st.op_date.da_mon<10)
				printf("0%d-",st.op_date.da_mon);
			else
				printf("%d-",st.op_date.da_mon);
			printf("%d",st.op_date.da_year);
			gotoxy(26,15);
			printf("%c",st.acc_type);
			gotoxy(65,15);
			printf("%u",st.acc_bal);
			gotoxy(26,18);
			puts(st.name);
			gotoxy(26,21);
			puts(st.addr);
			gotoxy(69,18);
			settextstyle(1,HORIZ_DIR,2);
			setcolor(7);
			outtextxy(330,312,"Deposit Amount");
			outtextxy(500,312,":");
			gotoxy(65,21);
			do
			{
				gotoxy(65,21);
				printf("_           ");
				gotoxy(65,21);
				fflush(stdin);
				gets(bal);
				for(i=0;bal[i]!='\0';i++)
					if(!isdigit(bal[i]))
					{
						bal[0]=NULL;
						break;
					}
			}while(!strlen(bal));
			amt=atoi(bal);
			settextstyle(1,HORIZ_DIR,2);
			setcolor(10);
			outtextxy(150,345,"WANT TO SAVE THE RECORD ?");
			outtextxy(190,375,"PRESS (Y)ES OR (N)O");
			ch=getch();
			if(toupper(ch)=='Y' || ch==13)
			{
				ft=fopen("tran.dat","ab");
				if(fp!=NULL && ft!=NULL)
				{
					strcpy(tr.acc_no,st.acc_no);
					getdate(&tr.tran_date);
					tr.prev_bal=st.acc_bal;
					tr.tran_amt=amt;
					st.acc_bal=st.acc_bal+amt;
					tr.cur_bal=st.acc_bal;
					tr.tr_type='D';
					fseek(fp,ctr*sizeof(st),SEEK_SET);
					fwrite(&st,sizeof(st),1,fp);
					fwrite(&tr,sizeof(tr),1,ft);
				}
				fclose(ft);
			}
		}
	}
	fclose(fp);
}
void withdraw_menu()
{
	int i,amt,ctr=0;
	char ch,ac_no[10],bal[10];
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(185,100,"W I T H D R A W");
	disp_heading();
	fp=fopen("acc.dat","rb+");
	settextstyle(1,HORIZ_DIR,3);
	if(fp!=NULL)
	{
		do
		{
			gotoxy(26,12);
			printf("_");
			gotoxy(26,12);
			fflush(stdin);
			gets(ac_no);
		}while(!strlen(ac_no));

		while(fread(&st,sizeof(st),1,fp))
		{
			if(!strcmp(st.acc_no,ac_no))
			{
				i=1;
				break;
			}
			ctr++;
		}
		if(i!=1)
		{
			settextstyle(1,HORIZ_DIR,2);
			setcolor(10);
			outtextxy(120,350,"ACCOUNT DOES NOT EXIST ... .. . .");
			getch();
		}
		else
		{
			gotoxy(65,12);
			if(st.op_date.da_day<10)
				printf("0%d-",st.op_date.da_day);
			else
				printf("%d-",st.op_date.da_day);
			if(st.op_date.da_mon<10)
				printf("0%d-",st.op_date.da_mon);
			else
				printf("%d-",st.op_date.da_mon);
			printf("%d",st.op_date.da_year);
			gotoxy(26,15);
			printf("%c",st.acc_type);
			gotoxy(65,15);
			printf("%u",st.acc_bal);
			gotoxy(26,18);
			puts(st.name);
			gotoxy(26,21);
			puts(st.addr);
			settextstyle(1,HORIZ_DIR,2);
			outtextxy(310,312,"Withdraw Amount");
			outtextxy(500,312,":");
			gotoxy(65,21);
			do
			{
				gotoxy(65,21);
				printf("_           ");
				gotoxy(65,21);
				fflush(stdin);
				gets(bal);
				for(i=0;bal[i]!='\0';i++)
					if(!isdigit(bal[i]))
					{
						bal[0]=NULL;
						break;
					}
			}while(!strlen(bal));
			amt=atoi(bal);
			if(st.acc_bal - amt < min_bal)
			{
				settextstyle(1,HORIZ_DIR,2);
				setcolor(10);
				outtextxy(120,350,"INSUFFICIENT BALANCE! PRESS ANY KEY...");
				getch();
				return;
			}
			settextstyle(1,HORIZ_DIR,2);
			setcolor(10);
			outtextxy(150,345,"WANT TO SAVE THE RECORD ?");
			outtextxy(190,375,"PRESS (Y)ES OR (N)O");
			ch=getch();
			if(toupper(ch)=='Y' || ch==13)
			{
				ft=fopen("tran.dat","ab");
				if(fp!=NULL && ft!=NULL)
				{
					strcpy(tr.acc_no,st.acc_no);
					getdate(&tr.tran_date);
					tr.prev_bal=st.acc_bal;
					tr.tran_amt=amt;
					st.acc_bal=st.acc_bal-amt;
					tr.cur_bal=st.acc_bal;
					tr.tr_type='W';
					fseek(fp,ctr*sizeof(st),SEEK_SET);
					fwrite(&st,sizeof(st),1,fp);
					fwrite(&tr,sizeof(tr),1,ft);
				}
				fclose(ft);
			}
		}
	}
	fclose(fp);
}

void balance_menu()
{
	char ch,ac_no[10];
	int i=0;
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(100,100,"B A L A N C E   C H E C K");
	disp_heading();
	fp=fopen("acc.dat","rb");
	if(fp!=NULL)
	{
		do
		{
			gotoxy(26,12);
			printf("_");
			gotoxy(26,12);
			fflush(stdin);
			gets(ac_no);
		}while(!strlen(ac_no));

		while(fread(&st,sizeof(st),1,fp))
		{
			if(strcmp(st.acc_no,ac_no)==0)
			{
				gotoxy(65,12);
				if(st.op_date.da_day<10)
					printf("0%d-",st.op_date.da_day);
				else
					printf("%d-",st.op_date.da_day);
				if(st.op_date.da_mon<10)
					printf("0%d-",st.op_date.da_mon);
				else
					printf("%d-",st.op_date.da_mon);
				printf("%d",st.op_date.da_year);
				gotoxy(26,12);
				gotoxy(26,15);
				printf("%c",st.acc_type);
				gotoxy(65,15);
				printf("%u",st.acc_bal);
				gotoxy(26,18);
				puts(st.name);
				gotoxy(26,21);
				puts(st.addr);
				i=1;
			}
		}
		if(i!=1)
		{
			settextstyle(1,HORIZ_DIR,2);
			setcolor(10);
			outtextxy(120,350,"ACCOUNT DOES NOT EXIST ... .. . .");
		}
	}
	fclose(fp);
	getch();
}

void account_report_menu()
{
	int r,i;
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(180,100,"ACCOUNT REPORT");
	setcolor(15);

	fp=fopen("acc.dat","rb");
	if(fp!=NULL)
	{
		i=1;
		while(fread(&st,sizeof(st),1,fp))
		{
			if(i%12==1)
			{
				if(i-1)
					if(getch()==27)
						return;
				r=14;
				setfillstyle(1,0);
				bar(30,163,610,410);
				rectangle(30,163,610,410);
				rectangle(30,163,610,195);
				rectangle(75,163,138,410);
				rectangle(280,163,355,410);
				rectangle(440,163,535,410);
				gotoxy(5,12);
				printf("SL.No");
				gotoxy(11,12);
				printf("A/C No.");
				gotoxy(20,12);
				printf("ACCOUNT HOLDER");
				gotoxy(37,12);
				printf("ADDRESS");
				gotoxy(47,12);
				printf("A/C TYPE");
				gotoxy(57,12);
				printf("OP. DATE");
				gotoxy(69,12);
				printf("BALANCE");
			}
			gotoxy(6,r);
			printf("%d",i++);
			gotoxy(12,r);
			printf("%s",st.acc_no);
			gotoxy(19,r);
			printf("%-16s",st.name);
			gotoxy(37,r);
			printf("%-7s",st.addr);
			gotoxy(47,r);
			if(toupper(st.acc_type)=='S')
				printf("Saving");
			else if(toupper(st.acc_type)=='C')
				printf("Current");
			gotoxy(57,r);
			if(st.op_date.da_day<10)
				printf("0%d-",st.op_date.da_day);
			else
				printf("%d-",st.op_date.da_day);
			if(st.op_date.da_mon<10)
				printf("0%d-",st.op_date.da_mon);
			else
				printf("%d-",st.op_date.da_mon);
			printf("%d",st.op_date.da_year);
			gotoxy(69,r);
			printf("%6u",st.acc_bal);
			r++;
		}
	}
	if(i==1)
	{
		setcolor(10);
		outtextxy(150,260,"There are no Account");
	}
	fclose(ft);
	while(getch()!=27);
}

void date_wise_report_menu()
{
	int r,i,day,mon,yr;
	char ac_no[10],d[6],ch;
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(65,100,"DATE WISE TRANSACTION REPORT");
	settextstyle(1,HORIZ_DIR,2);
	setcolor(7);
	outtextxy(100,250,"Date of Transaction : ");
	gotoxy(42,17);
	printf("_ /  /");
	gotoxy(42,17);
	i=0;
	do
	{
		do
		{
			d[i]=getch();
			printf("%c",d[i]);
			if(d[i]==13)
				break;
			else if(i==1)
			{
				i++;
				break;
			}
			i++;
		}while(1);
		d[i]=NULL;
		day=atoi(d);
		if(day>0 && day<32)
			break;
		else
		{
			gotoxy(42,17);
			printf("  ");
			gotoxy(42,17);
			printf("_");
			gotoxy(42,17);
			i=0;
		}
	}while(1);
	gotoxy(45,17);
	printf("_");
	gotoxy(45,17);
	i=0;
	do
	{
		do
		{
			d[i]=getch();
			printf("%c",d[i]);
			if(d[i]==13)
				break;
			else if(i==1)
			{
				i++;
				break;
			}
			i++;
		}while(1);
		d[i]=NULL;
		mon=atoi(d);
		if(mon>0 && mon<13)
			break;
		else
		{
			gotoxy(45,17);
			printf("  ");
			gotoxy(45,17);
			printf("_");
			gotoxy(45,17);
			i=0;
		}
	}while(1);
	gotoxy(48,17);

	printf("_");
	gotoxy(48,17);
	i=0;
	do
	{
		do
		{
			d[i]=getch();
			if(d[i]==13)
				break;
			else if(i==4)
				continue;
			printf("%c",d[i]);
			i++;
		}while(i);
		d[i]=NULL;
		yr=atoi(d);
		if(yr>0 && yr<10000)
			break;
		else
		{
			gotoxy(48,17);
			printf("    ");
			gotoxy(48,17);
			printf("_");
			gotoxy(48,17);
			i=0;
		}
		i++;
	}while(1);
	settextstyle(1,HORIZ_DIR,3);
	ft=fopen("tran.dat","rb");
	i=1;
	while(fread(&tr,sizeof(tr),1,ft)==1)
	{
		if(tr.tran_date.da_day==day && tr.tran_date.da_mon==mon && tr.tran_date.da_year==yr)
		{
			if(i%12==1)
			{
				if(i-1)
					if(getch()==27)
						return;
				r=14;
				setfillstyle(1,0);
				bar(30,163,610,410);
				rectangle(30,163,610,410);
				rectangle(30,163,610,195);
				rectangle(75,163,130,410);
				rectangle(220,163,305,410);
				rectangle(420,163,500,410);
				gotoxy(5,12);
				printf("SL.No");
				gotoxy(11,12);
				printf("A/C No");
				gotoxy(18,12);
				printf("Tran Date");
				gotoxy(29,12);
				printf("Particular");
				gotoxy(42,12);
				printf("Prev. Bal");
				gotoxy(56,12);
				printf("Amount");
				gotoxy(66,12);
				printf("Avail. Bal");
			}
			gotoxy(6,r);
			printf("%d",i++);
			gotoxy(11,r);
			printf("%s",tr.acc_no);
			gotoxy(18,r);
			if(tr.tran_date.da_day<10)
				printf("0%d-",tr.tran_date.da_day);
			else
				printf("%d-",tr.tran_date.da_day);
			if(tr.tran_date.da_mon<10)
				printf("0%d-",tr.tran_date.da_mon);
			else
				printf("%d-",tr.tran_date.da_mon);
			printf("%d",tr.tran_date.da_year);
			gotoxy(30,r);
			if(tolower(tr.tr_type)=='w')
				printf("Withdraw");
			else if(tolower(tr.tr_type)=='d')
				printf("Deposit");
			gotoxy(40,r);
			printf("%13u",tr.prev_bal);
			gotoxy(54,r);
			printf("%9u",tr.tran_amt);
			gotoxy(64,r);
			printf("%13u",tr.cur_bal);
			r++;
		}
	}
	fclose(ft);
	if(i==1)
	{
		settextstyle(1,HORIZ_DIR,2);
		setcolor(10);
		bar(30,163,610,410);
		outtextxy(120,260,"There are no transaction on this account");
	}
	while(getch()!=27);
}

void individual_report_menu()
{
	int r,i;
	char ac_no[10];
	clear();
	cleardevice();
	logo();
	setcolor(14);
	settextstyle(1,HORIZ_DIR,4);
	outtextxy(60,100,"INDIVIDUAL TRANSACTION REPORT");
	settextstyle(1,HORIZ_DIR,2);
	setcolor(7);
	outtextxy(120,250,"Account No  : ");
	do
	{
		gotoxy(35,17);
		printf("_");
		gotoxy(35,17);
		fflush(stdin);
		gets(ac_no);
	}while(!strlen(ac_no));
	settextstyle(1,HORIZ_DIR,3);
	ft=fopen("tran.dat","rb");
	i=1;
	while(fread(&tr,sizeof(tr),1,ft)==1)
	{
		if(strcmp(tr.acc_no,ac_no)==0)
		{
			if(i%12==1)
			{
				if(i-1)
					if(getch()==27)
						return;
				r=14;
				setfillstyle(1,0);
				bar(30,163,610,410);
				rectangle(30,163,610,410);
				rectangle(30,163,610,195);
				rectangle(75,163,130,410);
				rectangle(220,163,305,410);
				rectangle(420,163,500,410);
				gotoxy(5,12);
				printf("SL.No");
				gotoxy(11,12);
				printf("A/C No");
				gotoxy(18,12);
				printf("Tran Date");
				gotoxy(29,12);
				printf("Particular");
				gotoxy(42,12);
				printf("Prev. Bal");
				gotoxy(56,12);
				printf("Amount");
				gotoxy(66,12);
				printf("Avail. Bal");
			}
			gotoxy(6,r);
			printf("%d",i++);
			gotoxy(11,r);
			printf("%s",tr.acc_no);
			gotoxy(18,r);
			if(tr.tran_date.da_day<10)
				printf("0%d-",tr.tran_date.da_day);
			else
				printf("%d-",tr.tran_date.da_day);
			if(tr.tran_date.da_mon<10)
				printf("0%d-",tr.tran_date.da_mon);
			else
				printf("%d-",tr.tran_date.da_mon);
			printf("%d",tr.tran_date.da_year);
			gotoxy(30,r);
			if(tolower(tr.tr_type)=='w')
				printf("Withdraw");
			else if(tolower(tr.tr_type)=='d')
				printf("Deposit");
			gotoxy(40,r);
			printf("%13u",tr.prev_bal);
			gotoxy(54,r);
			printf("%9u",tr.tran_amt);
			gotoxy(64,r);
			printf("%13u",tr.cur_bal);
			r++;
		}
	}
	fclose(ft);
	if(i==1)
	{
		settextstyle(1,HORIZ_DIR,2);
		setcolor(10);
		bar(30,163,610,410);
		outtextxy(120,260,"There are no transaction on this account");
	}
	while(getch()!=27);
}
