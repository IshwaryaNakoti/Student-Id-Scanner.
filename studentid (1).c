#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<conio.h>
#include<process.h>
#include<windows.h>

#define ENTER 13
#define SPACE 32
#define BACKSPACE 8
#define TAB 9

void box(int,int,int,int);
struct student
{
    char name[50];
    char rno[30];
	char gender[10];
    char branch[30];
	char section[3];
	char semster[2];
    char password[10];
    char confirmPassword[10];
	char admnCategory[10];
	char category[20];
	char mentorName[20];
	char identificationMarks[50];
    char schoolName[35];
    char color[15];
	char houseNumber[20];
	char houseAddress[30];
	char city[30];
	char state[30];
	char country[30];
	char pinCode[10];
	char mailId[30];
	char phone[10];
	float score;
	struct result 
{
  	char sub_name[100];
  	float cgpa;
  	int credit;
  	float m_w_c;

};
struct result1 
{
  	int i, n_f_S;
  	struct result R[5];
}R1;
};
struct faculty
{
    char name[50];
	char id[30];
	char gender[10];
	char department[30];
	char subject[25];
    char mailId[30];
    char password[10];
    char confirmPassword[10];
    char phone[11];
	char qualifications[20];
    char experience[10];
	char identificationMarks[50];
    char colour[15];
    char school[16];
};
struct record
{
    char time[6];
    char name[30];
    char place[25];
    char note[500];
} ;
const char *registerFile1 = "Student.dat";
const char *registerFile2 = "Faculty.dat";

void Register_S();
void Register_F();
void Login_S();
void Login_F();
int Home();
void Faculty();
void Student();
void gotoxy(int ,int);
void View_Marks(char *,char *);

//Methods under faculty
void Homepage_F(char *, char *);

//in Homepage_F
void Attendance_F(char *);
void Marks_F(char *);
void Settings_F(char *, char *);

//methods for Attendance_F
int attendance_data(char *);
int search_attendance(char *);
int search_student_attendance(char *);
int att_edit1(char *);
int search_attendance1(int ,char *);
int view_student_att();
int edit3(char id[], char date[], char *);
int edit_2(int ,char *);

//methods under ModifyDetails_F
void namechange_F(char *);
void branchchange_F(char *);
void passwordchange_F(char *);
void phonechange_F(char *); 
void emailchange_F(char *); 
void securityquestionschange_F(char *);
void experience_F(char *); 
void qualifications_F(char *); 

void Search_F(char *);
void Delete_F(char *);

void namesearch_F(char *);
void branchsearch_F(char *);
void passwordsearch_F(char *);
void contactsearch_F(char *);
void emailsearch_F(char *);
void securityquestionssearch_F(char *);

//methods under student
void Homepage_S(char *,char *);

//in Homepage_S
void TimeTable(char *);
void LibraryDetails(char *);
void CollegeDetails(char *);
void Attendance_S(char *);
void Notepad(char *, char *);
void Settings_S(char *, char *);

//in TimeTable
void timetableITA();
void timetableITB();
void timetableITC();

//in LibraryDetails
void LibraryStaff();
void RulesRegulations();

//in CollegeDetails
void Departments(char *);
void About(char *);

//in About
void Academy();
void College();

//in Departments
void IT(char *);
void CSE(char *);

//in IT
void IT_Syllabus(int, char *);
void IT_Staff();

//in CSE
void CSE_Syllabus(int, char *);
void CSE_Staff();


void MyDetails_F(char *);
void ModifyDetails_F(char *);

//in Setting_S
void MyDetails(char *);
void ModifyDetails(char *);
void Delete(char *);
void Search(char *);
void RenameFile(char *);
//void DeleteFile1(char *);
void FileName(char *);

//in ModifyDetails
void namechange(char *);
void branchchange(char *);
void passwordchange(char *);
void phonechange(char *);
void emailchange(char *);
void securityquestionschange(char *);

//in Search
void namesearch(char *);
void branchsearch(char *);
void passwordsearch(char *);
void contactsearch(char *);
void emailsearch(char *);
void securityquestionssearch(char *);

//in Notepad
void addrecord(char *);
void viewrecord(char *);
void editrecord(char *);
void deleterecord(char *);
void box(int,int,int,int);
bool isDigit(char ch)
{
	if(ch>='0' && ch<='9')
		return true;
	return false;
}
void box(int a,int b,int c,int d)
{
	int i,j;
	for(i=a;i<c;i++)
	{
		gotoxy(i,b);printf("\xcd");
		gotoxy(i,d);printf("\xcd");
	}
	for(j=b;j<d;j++)
	{
		gotoxy(a,j);printf("\xba");
		gotoxy(c,j);printf("\xba");
	}
		gotoxy(a,b);printf("\xc9");
		gotoxy(c,b);printf("\xbb");
		gotoxy(a,d);printf("\xc8");
		gotoxy(c,d);printf("\xbc");
}
void SetColor(int ForgC) 
{
    WORD wColor;
   //We will need this handle to get the current background attribute
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO csbi;
   //We use csbi for the wAttributes word.
   if (GetConsoleScreenBufferInfo(hStdOut, & csbi)) {
   //Mask out all but the background attribute, and add in the forgournd color
   wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
   SetConsoleTextAttribute(hStdOut, wColor);
  }
  return;
}
int isValid (char s[])
{
	int length=strlen(s), ind1=0, ind2=0, ind3=0; 
	if ( (s[0]<'a') || (s[0]>'z') && ((s[0]<'0') || (s[0]>'9')))
     		return 0;
	else
	{
	for (int i=1;i<length;i++)
	{
	if (s[i]=='@')
	   {	
		 ind1=i+1;
		 break;
	    }
	else
	   if ((s[0]<'a') || (s[0]>'z') && ((s[0]<'0') || (s[0]>'9')) && ((s[0]<'A') ||(s[0]>'Z'))) 
		return 0;
	}
    for (int j=ind1;j<length;j++)
	{
		if (s[j]=='.')
		{	
			ind2=j+1;
			break;
		}
		else
			if ((s[0]<'a') || (s[0]>'z') && ((s[0]<'0') || (s[0]>'9')) && ((s[0]<'A') ||(s[0]>'Z')))
				return 0;
		}
	}
	if ((s[ind2] == 'c' && s[ind2+1] == 'o' && s[ind2+2] == 'm')) 
     		return 1;
	else 
		return 0;
}
int isValid2(char s[])
{
	int length=strlen(s), ind1=0, ind2=0, ind3=0; 
	if ( (s[0]<'a') || (s[0]>'z') && ((s[0]<'0') || (s[0]>'9')))
     		return 0;
	else
	{
	for (int i=1;i<length;i++)
	{
	if (s[i]=='@')
	   {	
		 ind1=i+1;
		 break;
	    }
	else
	   if ((s[0]<'a') || (s[0]>'z') && ((s[0]<'0') || (s[0]>'9')) && ((s[0]<'A') ||(s[0]>'Z'))) 
		return 0;
	}
    for (int j=ind1;j<length;j++)
	{
		if (s[j]=='.')
		{	
			ind2=j+1;
			break;
		}
		else
			if ((s[0]<'a') || (s[0]>'z') && ((s[0]<'0') || (s[0]>'9')) && ((s[0]<'A') ||(s[0]>'Z')))
				return 0;
		}
	}
	if ((s[ind2] == 'i' && s[ind2+1] == 'n')) 
     		return 1;
	else 
		return 0;
}
void loading() 
{
	for (int i = 0; i < 2; i++) 
	{
    	system("color 1");
    	system("cls");
    	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLoading.");
    	Sleep(300);
    	system("cls");
    	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLoading..");
    	Sleep(300);
    	system("cls");
    	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLoading...");
    	Sleep(300);
    	system("cls");
   	 	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\tLoading...");
    	Sleep(300);
    	system("cls");
    	system("color 2");
  	}
}
int main()
{
	Home();
	return 0;
}
int Home()
{
	system("cls");
    system("color B");
    printf("\n \n");
    jump1:
    {
        system("cls");
		int n;
	    box(60,5,130,40);
	    gotoxy(60,10);
	    printf("\t\t\t*** WELCOME TO STUDENT ID SCANNER ***\n");
		gotoxy(60,14);
		printf("\t 1.FACULTY\n");
		gotoxy(60,16);
		printf("\t 2.STUDENT\n");
		gotoxy(60,18);
		printf("\t 3.EXIT\n");
		gotoxy(60,22);
		printf("\tEnter your choice: ");
        scanf("%d",&n);
        if(n==1)
        {
		    loading();
         	Faculty();
        }
        else if(n==2)
        {
		    loading();
       		Student();
        }
		else if(n==3)
		{
			exit(0);
		}
        else
        {
			gotoxy(60,26);
           	printf("\tInvalid Input!!\n\n");
			gotoxy(60,28);
           	printf("\tEnter any key.\n");
			getch();
           	goto jump1;
        }
   	}
   	return 0;
}
void Faculty()
{
   	int s;
    	jump2:
    	{
        system("cls");
  		system("color 2");
		box(60,5,130,40);
		gotoxy(60,10);
        printf("\t\t   ****** WELCOME TO FACULTY ROOM ******\n");
        gotoxy(60,14);
		printf("\t 1.LOGIN\n");
		gotoxy(60,16);
		printf("\t 2.REGISTER\n");
		gotoxy(60,18);
		printf("\t 3.BACK\n");
		gotoxy(60,22);
        printf("\tEnter your choice: ");
        scanf("%d",&s);
        printf("\n");
    	}
    	if(s==1)
    	{
		    loading();
        	Login_F();
    	}
   	    else if(s==2)
    	{
		    loading();
        	Register_F();
    	}
    	else if(s==3)
    	{
        	Home();
    	}
    	else
        {
			gotoxy(60,26);
            printf("\tInvalid Input!!\n\n");
			gotoxy(60,28);
            printf("\tEnter any key.\n");
			getch();
            goto jump2;
        }
}
void Student()
{
	int s;
	jump2:
        {
  		system("cls");
        system("color 6");
		box(60,5,130,40);
		gotoxy(60,10);
        printf("\t\t   ****** WELCOME TO STUDENT ROOM ******\n");
        gotoxy(60,14);
		printf("\t 1.LOGIN\n");
		gotoxy(60,16);
		printf("\t 2.REGISTER\n");
		gotoxy(60,18);
		printf("\t 3.BACK\n");
		gotoxy(60,22);
        printf("\tEnter your choice: ");
        scanf("%d",&s);
        printf("\n");
        }
	if(s==1)
	{
		loading();
        Login_S();
	}
	else if(s==2)
	{
		loading();
        Register_S();
	}
	else if(s==3)
	{
        Home();
	}
	else
    {
		gotoxy(60,26);
        printf("\tInvalid Input!!\n\n");
	    gotoxy(60,28);
        printf("\tEnter any key.\n");
	    getch();
        goto jump2;
    }

}
void Register_F()
{
	system("cls");
	box(60,5,130,50);
	gotoxy(60,9);
	struct faculty s;
	FILE *fp;
    fp=fopen(registerFile2,"ab");
	printf("\t\t\t REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
	gotoxy(60,14);
	printf("\t  NAME : ");
    fgets(s.name,sizeof(s.name),stdin);
    scanf("%[^\n]s",s.name);
	gotoxy(60,16);
	printf("\t  ID : ");
    scanf("%s",s.id);
    gotoxy(60,18);
	printf("\t  GENDER : ");
    scanf("%s",s.gender);
	gotoxy(60,20);
	printf("\t  DEPARTMENT : ");
	fgets(s.department,sizeof(s.department),stdin);
    scanf("%[^\n]s",s.department);
    gotoxy(60,22);
	printf("\t  SUBJECT : ");
	fgets(s.subject,sizeof(s.subject),stdin);
    scanf("%[^\n]s",s.subject);
    gotoxy(60,24);
	int count=0;
	jump1:
    {
		gotoxy(60,24);
        printf("\t  CONTACT NUMBER :: ");
        scanf("%s",s.phone);
    }
	count=strlen(s.phone);
	for(int i=0;i<count;i++)
	{
	   if(!isDigit(s.phone[i]))
	   {
	    gotoxy(60,26);
	    printf("\t Sorry,the contact number is invalid!");
	    gotoxy(60,28);
        printf("\t Contact number consists only numbers\n");
		getch();
    	system("cls");
		box(60,5,130,50);
		gotoxy(60,9);
		printf("\t\t\t REGISTRATION\n");
		gotoxy(60,12);
		printf("\t\t Enter your details...\n");
		gotoxy(60,14);
		printf("\t  NAME : %s",s.name);
		gotoxy(60,16);
		printf("\t  ID : %s",s.id);
		gotoxy(60,18);
		printf("\t  GENDER : %s",s.gender);
		gotoxy(60,20);
		printf("\t  DEPARTMENT : %s",s.department);
		gotoxy(60,22);
		printf("\t  SUBJECT : %s",s.subject);
        goto jump1;
		break;
       }
    }
    if(count!=10)
    {
	    gotoxy(60,26);
        printf("\t  Sorry,the contact number is invalid!");
		gotoxy(60,28);
        printf("\t  Contact number consists of 10 digits\n");
		getch();
		system("cls");
		box(60,5,130,50);
		gotoxy(60,9);
		printf("\t\t\t REGISTRATION\n");
		gotoxy(60,12);
		printf("\t\t Enter your details...\n");
		gotoxy(60,14);
		printf("\t  NAME : %s",s.name);
		gotoxy(60,16);
		printf("\t  ID : %s",s.id);
		gotoxy(60,18);
		printf("\t  GENDER : %s",s.gender);
		gotoxy(60,20);
		printf("\t  DEPARTMENT : %s",s.department);
		gotoxy(60,22);
		printf("\t  SUBJECT : %s",s.subject);
		gotoxy(60,24);
        	goto jump1;
    	}
	char ch;
	jump2:
	{
	system("cls");
	box(60,5,130,50);
	gotoxy(60,9);
	printf("\t\t\t\t REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
	gotoxy(60,14);
	printf("\t  NAME : %s",s.name);
	gotoxy(60,16);
	printf("\t  ID : %s",s.id);
    gotoxy(60,18);
	printf("\t  GENDER : %s",s.gender);
	gotoxy(60,20);
	printf("\t  DEPARTMENT : %s",s.department);
    gotoxy(60,22);
	printf("\t  SUBJECT : %s",s.subject);
    gotoxy(60,24);
    printf("\t  CONTACT NUMBER : %s",s.phone);
	gotoxy(60,26);
	printf("\t  Password has to be 8 characters only(case sensitive)\n");
	gotoxy(60,28);
	printf("\t  PASSWORD :");		 
	int i=0;
   	while(1)
	{
		ch = getch();
		if(ch==ENTER)
		{
			s.password[i]='\0';
			break;
	    }
		else if(ch==BACKSPACE)
	    {
		    if(i>0)
			{
			    i--;
				printf("\b \b");
			}
		}
		else if(ch==TAB || ch==SPACE)
	    {
		    continue;
	    }
	    else 
	    {
		    s.password[i]=ch;
		    i++;
			printf("*");
		}
	}	
	}		  
	if(strlen(s.password)!=8)
	{
	    gotoxy(60,30);
		printf("\t  Sorry, It's incorrect password !!");
		gotoxy(60,32);
		printf("\t  Password consists of 8 characters only\n\n");
		getch();
		goto jump2;
	}
	jump3:
	{
	system("cls");
	box(60,5,130,50);
	gotoxy(60,9);
	printf("\t\t\t\t REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
	gotoxy(60,14);
	printf("\t  NAME : %s",s.name);
	gotoxy(60,16);
	printf("\t  ID : %s",s.id);
    gotoxy(60,18);
	printf("\t  GENDER : %s",s.gender);
	gotoxy(60,20);
	printf("\t  DEPARTMENT : %s",s.department);
    gotoxy(60,22);
	printf("\t  SUBJECT : %s",s.subject);
    gotoxy(60,24);
    printf("\t  CONTACT NUMBER : %s",s.phone);
	gotoxy(60,26);
	printf("\t  Password has to be 8 characters only(case sensitive)\n");
	gotoxy(60,28);
	printf("\t  PASSWORD : ********");	
	gotoxy(60,30);
	printf("\t  CONFIRMATION PASSWORD :");
	int i=0;
   	while(1)
	{
		ch = getch();
		if(ch==13)
		{
			s.confirmPassword[i]='\0';
			break;
	    }
		else if(ch==8)
		{
			if(i>0)
			{
		    	i--;
				printf("\b \b");
			}
	    }
		else if(ch==9 || ch==32)
		{
			continue;
	    }
		else 
	    {
			s.confirmPassword[i]=ch;
			i++;
			printf("*");
		}
	}	
	}
     	if(strcmp(s.password,s.confirmPassword)!=0)
	{
		gotoxy(60,32);
		printf("\t Sorry, Passwords did not matched!!  \n");
		gotoxy(60,34);
		printf("\t Try again...\n");
		getch();
		goto jump3;
	}

	jump4:
   	{
	system("cls");
	box(60,5,130,50);
	gotoxy(60,9);
	printf("\t\t\t\t REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
	gotoxy(60,14);
	printf("\t  NAME : %s",s.name);
	gotoxy(60,16);
	printf("\t  ID : %s",s.id);
    gotoxy(60,18);
	printf("\t  GENDER : %s",s.gender);
	gotoxy(60,20);
	printf("\t  DEPARTMENT : %s",s.department);
    gotoxy(60,22);
	printf("\t  SUBJECT : %s",s.subject);
    gotoxy(60,24);
    printf("\t  CONTACT NUMBER : %s",s.phone);
	gotoxy(60,26);
	printf("\t  Password has to be 8 characters only(case sensitive)\n");
	gotoxy(60,28);
	printf("\t  PASSWORD : ********");	
	gotoxy(60,30);
	printf("\t  CONFIRMATION PASSWORD : ********");
	gotoxy(60,32);
	printf("\t  EMAIL : ");
    scanf("%s",s.mailId);
	}
    if(isValid(s.mailId)==1 || isValid2(s.mailId)==1)
    {
		gotoxy(60,34);
		printf("\t  QUALIFICATIONS : ");
    	scanf("%s",s.qualifications);
        gotoxy(60,36);			
    	printf("\t  NUMBER OF YEARS EXPERIENCED : ");
    	scanf("%s",s.experience);
	}
	else 
	{
		gotoxy(60,34);
		printf("\t Invalid mailId- Try again");
		getch();
		goto jump4;
	}
	system("cls");
    box(60,5,130,40);
	gotoxy(60,9);
	printf("\t\t\t *** SECURITY QUESTIONS ***\n");
	gotoxy(60,12);
	printf("\t  Identification marks :");
    fgets(s.identificationMarks,sizeof(s.identificationMarks),stdin);
    scanf("%[^\n]s",s.identificationMarks);
    gotoxy(60,14);
    printf("\t  First school name in one word :");
    fgets(s.school,sizeof(s.school),stdin);
    scanf("%s",s.school);
	gotoxy(60,16);
	printf("\t  Favourite color :: ");
    scanf("%s",s.colour);     
	fwrite(&s,sizeof(s),1,fp);
	gotoxy(60,18);
    printf("\t\t  Successfully added your details into our database..\n");
    getch();
    fclose(fp);
	int x;
	gotoxy(60,20);
	printf("\t\t Would you like to login?(1/0) : ");
	scanf("%d",&x);
	if(x)
	{
		Login_F();
	}
	else
	{
		gotoxy(60,22);
		printf("\t\t Thankyou For Registering\n");	
	}		
}
void Register_S()
{
	system("cls");
    system("color 6");
	FILE *fp;
    struct student s;
    fp=fopen(registerFile1,"ab");
	box(60,5,130,56);
	gotoxy(60,9);
	printf("\t\t\t\t STUDENT REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
    gotoxy(60,14);
	printf("\t  Name : ");
    fgets(s.name,sizeof(s.name),stdin);
    scanf("%[^\n]s",s.name);
	gotoxy(60,16);
	printf("\t  Roll Number : ");
	fgets(s.rno,sizeof(s.rno),stdin);
    scanf("%[^\n]s",s.rno);
	gotoxy(60,18);
	printf("\t  Gender :");
	scanf("%s",s.gender);
    gotoxy(60,20);
	printf("\t  Branch : ");
	fgets(s.branch,sizeof(s.branch),stdin);
    scanf("%[^\n]s",s.branch);
	gotoxy(60,22);
	printf("\t  Section : ");
	scanf("%s",s.section);
    gotoxy(60,24);
	printf("\t  Semester : ");
	scanf("%s",s.semster);
	int count=0;
    jump1:
    {
	system("cls");
    box(60,5,130,56);
	gotoxy(60,9);
	printf("\t\t\t\t STUDENT REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
    gotoxy(60,14);
	printf("\t  Name : %s",s.name);
	gotoxy(60,16);
	printf("\t  Roll Number : %s",s.rno);
	gotoxy(60,18);
	printf("\t  Gender : %s",s.gender);
    gotoxy(60,20);
	printf("\t  Branch : %s",s.branch);
	gotoxy(60,22);
	printf("\t  Section : %s",s.section);
    gotoxy(60,24);
	printf("\t  Semester : %s",s.semster);
	gotoxy(60,26);
    printf("\t Enter your contact number : ");
    scanf("%s",s.phone);
    }
	count=strlen(s.phone);
	for(int i=0;i<count;i++)
	{
		if(!isDigit(s.phone[i]))
		{
			gotoxy(60,28);
			printf("\t Sorry,the contact number is invalid!");
			gotoxy(60,30);
        	printf("\t Contact number consists only numbers\n");
			getch();
        	goto jump1;
			break;
    		}
	}
    if(count!=10)
    {
		gotoxy(60,28);
        printf("\t Sorry, the contact number is invalid!");
		gotoxy(60,30);
        printf("\t Contact number consists of 10 digits\n");
		getch();
        goto jump1;
    }
	jump2:
    {
	system("cls");
    box(60,5,130,56);
	gotoxy(60,9);
	printf("\t\t\t\t STUDENT REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
    gotoxy(60,14);
	printf("\t  Name : %s",s.name);
	gotoxy(60,16);
	printf("\t  Roll Number : %s",s.rno);
	gotoxy(60,18);
	printf("\t  Gender : %s",s.gender);
    gotoxy(60,20);
	printf("\t  Branch : %s",s.branch);
	gotoxy(60,22);
	printf("\t  Section : %s",s.section);
    gotoxy(60,24);
	printf("\t  Semester : %s",s.semster);
	gotoxy(60,26);
    printf("\t Enter your contact number : %s",s.phone);
		gotoxy(60,28);
        printf("\t NOTE : Password consists of 8 characters");
		gotoxy(60,30);
        printf("\t  Password : ");
        int i=0;
	    char ch;
        while(1)
		{
			ch = getch();
			if(ch==ENTER)
			{
				s.password[i]='\0';
				break;
			 }
			 else if(ch==BACKSPACE)
			 {
				if(i>0)
				{
					i--;
					printf("\b \b");
				 }
			 }
			 else if(ch==TAB || ch==SPACE)
			 {
				 continue;
			 }
			 else 
			 {
				 s.password[i]=ch;
				 i++;
				 printf("*");
			 }
		 }	
        }
        if(strlen(s.password)!=8)
        {
			gotoxy(60,32);
            printf("\t Sorry, Password must consists of 8 characters\n");
			getch();
            goto jump2;
        }
	
	jump3:
        {
		system("cls");
    box(60,5,130,56);
	gotoxy(60,9);
	printf("\t\t\t\t STUDENT REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
    gotoxy(60,14);
	printf("\t  Name : %s",s.name);
	gotoxy(60,16);
	printf("\t  Roll Number : %s",s.rno);
	gotoxy(60,18);
	printf("\t  Gender : %s",s.gender);
    gotoxy(60,20);
	printf("\t  Branch : %s",s.branch);
	gotoxy(60,22);
	printf("\t  Section : %s",s.section);
    gotoxy(60,24);
	printf("\t  Semester : %s",s.semster);
	gotoxy(60,26);
	printf("\t Enter your contact number : %s",s.phone);
	gotoxy(60,28);
	printf("\t  Password : ********");
	gotoxy(60,30);
    printf("\t  Confirm your password : ");
	int i=0;
	char ch;
    while(1)
	{
		ch = getch();
		if(ch==ENTER)
		{
			s.confirmPassword[i]='\0';
			break;
		}
		else if(ch==BACKSPACE)
		{
			if(i>0)
			{
				i--;
				printf("\b \b");
			}
		}
		else if(ch==TAB || ch==SPACE)
		{
			continue;
		}
		else 
		{
			s.confirmPassword[i]=ch;
			i++;
			printf("*");
		}
	}	
    }
    if(strcmp(s.password,s.confirmPassword)!=0)
    {
		gotoxy(60,32);
        printf("\t Sorry, your password did not match\n");
		gotoxy(60,34);
        printf("\t Try again\n");
		getch();
        goto jump3;
        }
	jump4:
	{
    system("cls");
    box(60,5,130,56);
	gotoxy(60,9);
	printf("\t\t\t STUDENT REGISTRATION\n");
	gotoxy(60,12);
	printf("\t\t Enter your details...\n");
    gotoxy(60,14);
	printf("\t  Name : %s",s.name);
	gotoxy(60,16);
	printf("\t  Roll Number : %s",s.rno);
	gotoxy(60,18);
	printf("\t  Gender : %s",s.gender);
    gotoxy(60,20);
	printf("\t  Branch : %s",s.branch);
	gotoxy(60,22);
	printf("\t  Section : %s",s.section);
    gotoxy(60,24);
	printf("\t  Semester : %s",s.semster);
	gotoxy(60,26);
	printf("\t Enter your contact number : %s",s.phone);
	gotoxy(60,28);
	printf("\t  Password : ********");
	gotoxy(60,30);
    printf("\t  Confirm your password : ********");
	gotoxy(60,32);
	printf("\t  Enter your mailID :");
    scanf("%s",s.mailId);
	}
    if(isValid(s.mailId)==1 || isValid2(s.mailId)==1)
	{		
        gotoxy(60,34);
        printf("\t  House Number : ");
		scanf("%s",s.houseNumber);
		gotoxy(60,36);
		printf("\t  House Address : ");
		fgets(s.houseAddress,sizeof(s.houseAddress),stdin);
    	scanf("%[^\n]s",s.houseAddress);
	    gotoxy(60,38);
		printf("\t  City : ");
		scanf("%s",s.city);
		gotoxy(60,40);
		printf("\t  State : ");
		fgets(s.state,sizeof(s.state),stdin);
    	scanf("%[^\n]s",s.state);
		gotoxy(60,42);
		printf("\t  Country : ");
		fgets(s.country,sizeof(s.country),stdin);
    	scanf("%[^\n]s",s.country);
	    gotoxy(60,44);
		printf("\t  PinCode : ");
		fgets(s.pinCode,sizeof(s.pinCode),stdin);
    	scanf("%[^\n]s",s.pinCode);
        gotoxy(60,46);
		printf("\t  Enter your Admission Category :");
		scanf("%s",s.admnCategory);
        gotoxy(60,48);
		printf("\t  Enter your Category :");
		scanf("%s",s.category);
        gotoxy(60,50);
		printf("\t  Enter your MentorName :");
		scanf("%s",s.mentorName);	
	}
	else 
	{
		gotoxy(60,34);
		printf("\t Invalid mailId- Try again\n\n");
		getch();
		goto jump4;
	}
	system("cls");
	box(60,5,136,38);
	gotoxy(60,9);
	printf("\t\t  *** SECURITY QUESTIONS ***\n");
	gotoxy(60,12);
	printf("\t  Identification Marks : ");
	fgets(s.identificationMarks,sizeof(s.identificationMarks),stdin);
    scanf("%[^\n]s",s.identificationMarks);
    gotoxy(60,14);
    printf("\t  Enter your first school : ");
    fgets(s.schoolName,sizeof(s.schoolName),stdin);
    scanf("%[^\n]s",s.schoolName);
    gotoxy(60,16);
    printf("\t  Enter your favourite color : ");
    scanf("%s",s.color);
    gotoxy(60,18);
    fwrite(&s,sizeof(s),1,fp);
    gotoxy(60,20);
    printf("\t Successfully added your details into our database...\n");
    fclose(fp);
	int x;
	gotoxy(60,22);
	printf("\t Would you like to login?(1/0) : ");
	scanf("%d",&x);
	if(x)
	{
		loading();
		Login_S();
	}
	    else
		{
			gotoxy(60,24);
		    printf("\t Thankyou For Registering\n");		
		}			
}
void Login_F()
{
	system("cls");
	struct faculty t;
	FILE *fp;
	int found=0;
	char id[30],pwd[10],school[10],colour[30];
	fp=fopen(registerFile2,"rb");
    box(60,5,130,40);
	gotoxy(60,7);
	printf("\t\t\t\tFACULTY LOGIN\n");
    gotoxy(60,12);
	printf("\t\tEnter your ID : ");
	scanf("%s",id);
	while(1)
	{
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		break;
	}
	if(strcmp(id,t.id)==0)
	{
		cross1:
		{
			system("cls");
			box(60,5,130,40);
			gotoxy(60,7);
			printf("\t\t\t\tFACULTY LOGIN\n");
			gotoxy(60,12);
			printf("\t\tEnter your ID : %s",t.id);
			gotoxy(60,14);
			printf("\t\tEnter your password : ");
			int i=0;
			char ch;
          	while(1)
		  	{
			  	ch = getch();
			  	if(ch==ENTER)
			  	{
				  	pwd[i]='\0';
				  	break;
			  	}
			  	else if(ch==BACKSPACE)
			  	{
				  	if(i>0)
				  	{
					  	i--;
					  	printf("\b \b");
				  	}
			  	}
			  	else if(ch==TAB || ch==SPACE)
			  	{
				 	continue;
			  	}
			  	else 
			  	{
				  	pwd[i]=ch;
				  	i++;
				  	printf("*");
			  	}
		  	}	
	if(strcmp(pwd,t.password)==0)
	{
		gotoxy(60,18);
		found=1;
		printf("\t\tLogin Successfull\n");
		gotoxy(60,20);
		printf("\t\tEnter any key..");
		getch();
		Homepage_F(id,pwd);
	}
	else
	{
		gotoxy(60,16);
		printf("\t\t  Oops, Invalid password\n");
		int x;
		gotoxy(60,18);
		printf("\t\t 1.Forgot password?\n");
		gotoxy(60,20);
		printf("\t\t 2.Re-try \n");
		gotoxy(60,22);
		printf("\t\t 3.Exit\n");
		gotoxy(60,24);
		printf("\t\t Enter your choice : ");
		scanf("%d",&x);
		if(x==1)
		{
			gotoxy(60,26);
		    printf("\t\t\t *** SECURITY QUESTIONS ***\n");
			gotoxy(60,28);
			printf("\t\t Favourite color:");
			scanf("%s",colour);
			gotoxy(60,30);
			printf("\t\t Favourite school:");
			scanf("%s",school);
			if(strcmp(t.colour,colour)==0 && strcmp(t.school,school)==0)
			{
				gotoxy(60,32);
				printf("\t\t Your Password : %s",t.password);
				getch();
				Homepage_F(id,pwd);
			}
			else
			{
				gotoxy(60,32);
				printf("\tYou dont have account");	
				bool s;
				gotoxy(60,34);
				printf("\t Would you like to register?(1/0) : ");
				scanf("%d",&s);
				if(s)
				{
					Register_F();
				}
				else
					Faculty();
			}
		}
		else if(x==2)
		{
			goto cross1;	
		}
		else if(x==3)
		{
			exit(0);
		}
		else
		{
			gotoxy(60,26);
			printf("\t\tInvalid Input- Please Retry!\n");
			gotoxy(60,28);
			printf("\tEnter any key..");
			getch();
			goto cross1;
		}
	    }
	}
	}
	}
	if(found==0)
	{
		int x;
		gotoxy(60,14);
		printf("\t\tSorry, Account not found\n");
		bool s;
		gotoxy(60,16);
		printf("\t\tWould you like to register?(1/0) : ");
		scanf("%d",&s);
		if(s)
		{
		    Register_F();
	    }
		else
			Faculty();
	}
	fclose(fp);
}
void Login_S()
{
	system("cls");
	FILE *fp;
	system("color 6");
	struct student t;
	int found=0;
	char id[30],pwd[10],colour[30],school[30];;
	fp=fopen(registerFile1,"rb");
	box(60,5,130,40);
	gotoxy(60,8);
	printf("\t\t\t\tSTUDENT LOGIN\n");
	gotoxy(60,12);
	printf("\t\t Enter your ID : ");
	fgets(id,sizeof(id),stdin);
    scanf("%[^\n]s",id);	
	while(1)
	{
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		break;
	}
	if(strcmp(id,t.rno)==0)
	{
		cross1:
		{
			system("cls");
			box(60,5,130,40);
			gotoxy(60,8);
			printf("\t\t\t\tSTUDENT LOGIN\n");
			gotoxy(60,12);
			printf("\t\tEnter your ID : %s",id);
			gotoxy(60,14);
			printf("\t\tEnter your password : ");
			int i=0;
			char ch;
          	while(1)
		  	{
			  	ch = getch();
			  	if(ch==ENTER)
			  	{
				  	pwd[i]='\0';
				  	break;
			  	}
			  	else if(ch==BACKSPACE)
			  	{
				  	if(i>0)
				  	{
				 		i--;
				 		printf("\b \b");
				  	}
			  	}
			  	else if(ch==TAB || ch==SPACE)
			  	{
				  	continue;
			  	}
			  	else 
			  	{
				  	pwd[i]=ch;
				  	i++;
				  	printf("*");
			  	}
		  	}	
			if(strcmp(pwd,t.password)==0)
			{
				gotoxy(60,18);
				found=1;
				printf("\t\tLogin Successfull\n");
				gotoxy(60,20);
				printf("\t\tEnter any key..");
				getch();
				Homepage_S(id,pwd);
			}
			else
			{
				gotoxy(60,16);
				printf("\t  Oops, Invalid password\n");
				int x;
				gotoxy(60,18);
				printf("\t\t 1.Forgot password?\n");
				gotoxy(60,20);
				printf("\t\t 2.Re-try \n");
				gotoxy(60,22);
				printf("\t\t 3.Exit\n");
				gotoxy(60,24);
				printf("\t\t Enter your choice : ");
				scanf("%d",&x);
				if(x==1)
				{
					gotoxy(60,26);
				    printf("\t\t\t *** SECURITY QUESTIONS ***\n");
					gotoxy(60,28);
					printf("\t\t Favourite color:");
					scanf("%s",colour);
					gotoxy(60,30);
					printf("\t\t Favourite school:");
					scanf("%s",school);
					if(strcmp(t.color,colour)==0 && strcmp(t.schoolName,school)==0)
					{
						Homepage_S(id,pwd);
					}
					else
					{
						gotoxy(60,32);
						printf("\tYou dont have account");	
						bool s;
						gotoxy(60,34);
						printf("\t Would you like to register?(1/0) : ");
						scanf("%d",&s);
						if(s)
						{
							Register_S();
						}
					    else
							Student();
						}
					}
					else if(x==2)
					{
						goto cross1;	
					}
					else if(x==3)
					{
						exit(0);
					}
					else
					{
						gotoxy(60,26);
						printf("\t\tInvalid Input- Please Retry!\n");
						gotoxy(60,28);
						printf("\tEnter any key..");
						getch();
						goto cross1;
					}
				}
			}
		}
	}
	if(found==0)
	{
		int x;
		gotoxy(60,14);
		printf("\t\tSorry, Account not found\n");
		bool s;
		gotoxy(60,16);
		printf("\t\tWould you like to register?(1/0) : ");
		scanf("%d",&s);
		if(s)
		{
		    Register_S();
	    }
		else
			Student();
	}
	fclose(fp);
}
void Homepage_F(char *MyFile, char *password)
{
	FILE *fp,*fp1;
	int c; 
	struct faculty t;
	struct faculty s;
	fp=fopen(registerFile2,"rb");
	while(1)
	{
		fread(&t,sizeof(t),1,fp);
		if(feof(fp))
		{
			break;
		}
		if((strcmp(MyFile,t.id)==0) && (strcmp(password,t.password)==0))
		{
			s=t;
			strcat(MyFile,".dat");
			fp1=fopen(MyFile,"ab");
			fwrite(&s,sizeof(s),1,fp1);
			fclose(fp1);
		}
	}
	fclose(fp);
	while(c!=6)
	{
		system("cls");
		box(60,5,130,40);
        gotoxy(60,10);
		system("color 2");
		printf("\t\t\t\t FACULTY ROOM\n");
		gotoxy(60,12);
		printf("\t 1.Attendance\n");
		gotoxy(60,14);
		printf("\t 2.Marks\n");
		gotoxy(60,16);
		printf("\t 3.Settings\n");
		gotoxy(60,18);
		printf("\t 4.Logout\n");
		gotoxy(60,20);
		printf("\t\t Enter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1 : Attendance_F(MyFile); break;
			case 2 : Marks_F(MyFile); break;
			case 3 : Settings_F(MyFile, password); break;
			case 4 : exit(0);
			default : gotoxy(60,22);
			          printf("\t Invalid Input\n");
		}
		getch();
	}	
}
void Attendance_F(char *MyFile)
{
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct faculty t;
	fread(&t,sizeof(t),1,fp);
	system("cls");
	box(60,5,130,40);
    gotoxy(60,10);
  	char tswitch;
  	SetColor(14);
  	printf("\t\t\t*** === Teachers Portal ===***\n\n");
  	SetColor(45);
	gotoxy(60,14);
  	printf("\t 1.Input Attendance\n");
	gotoxy(60,16);
  	printf("\t 2. View Attendance\n");
	gotoxy(60,18);
  	printf("\t 3. Search a Student Attendance\n");
	gotoxy(60,20);
  	printf("\t 4. Edit Attendance\n");
	gotoxy(60,22);
  	printf("\t 5. Back");
	gotoxy(60,24);
  	SetColor(11);
  	printf("\t\t Select an Option:");
  	SetColor(45);
  	tswitch = getche();
  	switch (tswitch) 
	{
  		case '1': attendance_data(MyFile);
    			  break;
  		case '2': search_attendance(MyFile);
    		  	  break;
  		case '3': search_student_attendance(MyFile);
    			  break;
  		case '4': att_edit1(MyFile);
    	  		  break;
  		case '5': Homepage_F(MyFile,t.password);
    			  break;
  		default : SetColor(4);
    		 	  printf("\n\n\t\t  INVALID KEYWORD\n");
    		  	  Sleep(1000);
    		 	  SetColor(45);  
		 	  Attendance_F(MyFile);
  	}
	fclose(fp);
}
struct s_attendance
{
  char date[30];
  char sid[30];
  char ati[5];
  char sname[50];
  int att_count;
}
s_att, s_att_e, s_att_e1;

struct s_attendance2 
{
  char date[30];
  char sid[30];
  char ati[5];
  char sname[50];
  int att_count;
};
int attendance_data(char *MyFile) 
{
  	system("cls");
	box(60,5,140,52);
  	int i = 0;
  	int count = 0;
  	char name[100];
  	int id[100];
  	char date[100];
  	int found = 0;
  	char att_cmp[5] = {
    	"p"
  	};
  	char att_cmp1[5] = {
    	"a"
  	};
  	FILE * fptr1;
  	fptr1 = fopen(registerFile1, "rb");
	struct student std;
  	FILE * chdate;
  	chdate = fopen("Attendance.dll", "r");
  	SetColor(14);
	gotoxy(60,9);
  	printf("\t\tEnter Current date[dd/mm/yyyy]:");
  	SetColor(9);
  	scanf("%s", date);
  	while (fread( & s_att, sizeof(s_att), 1, chdate)) 
	{
    if (strcmp(date, s_att.date) == 0) 
	{
      	found = 1;
   	}
    }
  	if (found == 0) 
	{
    while (fread(&std, sizeof(std), 1, fptr1)) 
	{
		jump1:
		{
      		fflush(stdin);
      		strcpy(s_att.date, date);
      		strcpy(s_att.sid, std.rno);
      		strcpy(s_att.sname, std.name);
      		SetColor(13);
      		printf("\n\n\t\t\t\t\t\t\t\t Student Name: %s",s_att.sname);
			printf("\n\n\t\t\t\t\t\t\t\t Student ID: %s",s_att.sid);
      		SetColor(7);
      		printf("\n\n\t\t\t\t\t\t\t\t Press [p] for present and [a] for absent....");
      		SetColor(9);
      		scanf("%s", & s_att.ati);
      		SetColor(45);
			}
      		if (strcmp(s_att.ati, att_cmp) == 0 || strcmp(s_att.ati, att_cmp1) == 0) 
			{
        		if (strcmp(s_att.ati, att_cmp) == 0) 
				{
          			s_att.att_count = s_att.att_count + 1;
        		}
        		if (strcmp(s_att.ati, att_cmp1) == 0) 
				{
          			s_att.att_count = s_att.att_count + 0;
        		}
     		}					
			else 
			{
	system("cls");
	box(60,5,140,50);
  	SetColor(14);
	gotoxy(60,9);
  	printf("\t\tEnter Current date[dd/mm/yyyy]: %s",date);
    SetColor(4);
	gotoxy(60,12);
    printf("\t\tInvalid Attendance Case Try Again...!!\n");
    SetColor(45);
	getch();
	goto jump1;
    }
    FILE * att1;
    att1 = fopen("Attendance.dll", "a");
    if (att1 == NULL) 	
    {
        printf("\n\n\t\tError\n");
        exit(1);
    }
    fwrite( & s_att, sizeof(s_att), 1, att1);
    fclose(att1);
    }
    printf("\n\n\t\t\t\t\t\t\t\t SUCESSFULLY SAVED\n\n");
    char end;
    printf("\t\t\t\t\t\t\t\t  Press 1 for Input more attendance\n");
    printf("\n\t\t\t\t\t\t\t\t  Press 2 for go Back");
    printf("\n\t\t\t\t\t\t\t\t  Press 3 for EXIT Software\n");
    printf("\n\t\t\t\t\t\t\t\t  Select an Option : ");
    end = getche();
    switch (end) 
	{
    	case '1': attendance_data(MyFile); break;
    	case '2': Attendance_F(MyFile); break;
    	case '3': exit(0); break;
    	default : printf("\n\t INVALID KEYWORD\n");
      		      Sleep(1000);
     			  Attendance_F(MyFile);
    }
 	} 
	else 
	{
    	SetColor(4);
		gotoxy(60,12);
		printf("\t\t Attendance Already Taken. TRY ANOTHER DATE\n\n");
    	Sleep(2000);
    	SetColor(45);
    	attendance_data(MyFile);
  	}
  	return 0;
}
int search_attendance(char *MyFile) 
{
  	int tdt = 0;
  	FILE * fptdt;
  	fptdt = fopen("Attendance.dll", "r");
  	while (fread( & s_att, sizeof(s_att), 1, fptdt)) 
	{
    		tdt = tdt + 1;
  	}
  	fclose(fptdt);
  	search_attendance1(tdt, MyFile);
  	char end;
	system("cls");
	box(60,5,130,40);
	gotoxy(60,9);
	printf("\t\t\t SEARCH ATTENDANCE \n\n\n");
	gotoxy(60,12);
  	printf("\t  Press 1 for search more attendance\n");
	gotoxy(60,14);
  	printf("\t  Press 2 for go Back\n");
	gotoxy(60,16);
  	printf("\t  Press 3 for EXIT Software\n");
	gotoxy(60,18);
  	printf("\t Select an Option : ");
  	end = getche();
  	switch (end) 
	{
  		case '1': search_attendance(MyFile); break;
  		case '2': Attendance_F(MyFile); break;
  		case '3': exit(0); break;
  		default: gotoxy(60,20);
		         printf("\t  INVALID KEYWORD\n");
  		     	 Sleep(1000);
    			 Attendance_F(MyFile);
  	}
  	return 0;
}
int search_attendance1(int tdt, char *MyFile) 
{
  	system("cls");
	box(60,5,130,40);
	gotoxy(60,9);
  	printf("\t\t\t SEARCH ATTENDANCE \n\n\n");
  	int lc = 0,found=0;
  	char sr_att[30];
  	SetColor(14);
	gotoxy(60,12);
  	printf("\t Enter the date you want to search attendance: ");
  	SetColor(11);
  	scanf("%s", sr_att);
  	FILE * fpsr;
  	fpsr = fopen("Attendance.dll", "r");
  	SetColor(11);
  	while (fread( & s_att, sizeof(s_att), 1, fpsr)) 
	{
    		if (strcmp(sr_att, s_att.date) == 0) 
		    {
      			printf("\n\t\t\t\t\t\t\t\t Student Name: %s\n\t\t\t\t\t\t\t\t Student ID: %s\n\t\t\t\t\t\t\t\t Attendance: %s\n", s_att.sname, s_att.sid, s_att.ati);
				found=1;
    		}
  	}
	if(found==0)
   {
		printf("\n\n\t\t\t\t\t\t\t\t DATA NOT FOUND");
	}
  	SetColor(45);
	getch();
  	return 0;
}
int search_student_attendance(char *MyFile) 
{
  	system("cls");
	box(60,5,140,40);
  	float present = 0;
  	float absent = 0;
  	int y = 25;
  	float mark_att1, mark_att2;
  	float count = 0;
  	float count1 = 0;
  	float count2;
  	char p[20] = {
    	"p"
  	};
  	char a[20] = {
    	"a"
  	};
  	FILE * ssatt;
  	ssatt = fopen("Attendance.dll", "r");
  	char id[30];
  	char dtls;
  	int i = 0, found = 0;
  	view_student_att();
  	SetColor(14);
  	printf("\n\n\t\t\t\t\t\t\t\t  Enter The ID You Want To Search: ");
  	SetColor(11);
  	fflush(stdin);
  	gets(id);
  	SetColor(45);
  	while (fread(&s_att, sizeof(s_att), 1, ssatt)) 
	{
    	if (strcmp(id, s_att.sid) == 0) 
		{
      		if (strcmp(p, s_att.ati) == 0) 
			{
        		present = present + 1;
      		} 
			else 
			{
        		absent = absent + 1;
      		}
      		count = count + 1;
      		found = 1;
    	}
  	}
  	if (found == 0) 
	{
    	SetColor(4);
        gotoxy(60,29);
    	printf("\t DATA NOT FOUND\n");
		getch();
    	SetColor(45);
  	} 
	else
  	{
    	char idfc[20];
    	FILE * stdptr1;
		struct student std;
    	stdptr1 = fopen(registerFile1, "rb");
    	while (fread(&std, sizeof(std), 1, stdptr1)) 
		{
      		strcpy(idfc, std.rno);
      		break;
    	}
    	fclose(stdptr1);
    	FILE * stdptr2;
    	stdptr2 = fopen("Attendance.dll", "r");
    	while (fread(&s_att, sizeof(s_att), 1, stdptr2)) 
		{
      		if (strcmp(idfc, s_att.sid) == 0) 
			{
        		count1 = count1 + 1;
      		}
    	}
        fclose(stdptr2);
		FILE * stdptr;
    	stdptr = fopen(registerFile1, "rb");
    	while (fread(&std, sizeof(std), 1, stdptr)) 
		{
      		if (strcmp(id, std.rno) == 0) 
			{
				system("cls");
				box(60,3,130,50);
        		SetColor(11);
        		gotoxy(60,6);
        		printf("\t\t >> Attendance <<\n");
        		SetColor(14);
        		gotoxy(60,8);
        		printf("\t  Name:%s", std.name);
        		gotoxy(60,10);
        		printf("\t  ID: %s", std.rno);
        		gotoxy(60,12);
        		printf("\t  Department: %s", std.branch);
        		gotoxy(60,14);
        		printf("\t  Section: %s", std.section);
        		gotoxy(60,16);
        		printf("\t  Total Class: %0.0f", count1);
        		gotoxy(60,18);
        		printf("\t  Present: %0.0f Days", present);
        		gotoxy(60,20);
        		printf("\t  Absent: %0.0f Days", absent);
      		}
    	}
    if (count1 > count) 
	{
      	count2 = count1 - count;
      	SetColor(4);
      	printf("\n\t [Registered after %0.0f Class]", count2);
      	SetColor(14);
    }
    mark_att1 = (present * 5) / count1;
    mark_att2 = (present * 7) / count1;
    gotoxy(60,22);
    printf("\t Attendance Mark: %0.2f  [Out of 5.0]", mark_att1);
    gotoxy(60,24);
    printf("\t Attendance Mark: %0.2f  [Out of 7.0]\n", mark_att2);
    gotoxy(60,26);
    printf("\t  Do you want to view attendance details[y/n]");
    scanf("%c", & dtls);
    if (dtls == 'y') 
	{
      	FILE * temp2;
      	temp2 = fopen("Attendance.dll", "r");
      	while (fread( & s_att, sizeof(s_att), 1, temp2)) 
		{
        	if (strcmp(id, s_att.sid) == 0) 
			{
          		if (strcmp(p, s_att.ati) == 0) 
				{
            		SetColor(11);
            		printf("\n\t\t\t\t\t\t\t\t %s: Present", s_att.date);
          		} 
				else if (strcmp(a, s_att.ati) == 0) 
				{
            		SetColor(4);
            		printf("\n\t\t\t\t\t\t\t\t %s: Absent", s_att.date);
            		SetColor(11);
          	    }
          y++;
           }
        }
		getch();
        fclose(temp2);
    }
    fclose(ssatt);
  	}
  	//EXIT_Switch
	system("cls");
  	SetColor(62);
	box(60,5,130,40);
	gotoxy(60,10);
  	char end;
  	gotoxy(60,12);
  	printf("\t Press 1 To Search Again");
  	gotoxy(60,14);
  	printf("\t Press 2 for go Back");
  	gotoxy(60,16);
  	printf("\t Press 3 for EXIT Software");
  	gotoxy(60,18);
  	printf("\t  Select an Option : ");
  	end = getche();
  	switch (end) 
	{
  		case '1': search_student_attendance(MyFile); break;
    	case '2': Attendance_F(MyFile); break;
  		case '3': exit(0);  break;
  		default : gotoxy(60,20);
		          printf("\t INVALID KEYWORD");
    			  Sleep(1000);
    			  Home();
  	}
  	return 0;
}
int att_edit1(char *MyFile) 
{

  	FILE * fpedt_att;
  	fpedt_att = fopen("Attendance.dll", "r");
  	int td = 0;
  	while (fread( & s_att, sizeof(s_att), 1, fpedt_att)) 
	{
    		td = td + 1;
  	}
  	fclose(fpedt_att);
  	edit_2(td,MyFile);
  	return 0;
}
struct Edit_take 
{
  char id[40];
  char date[40];
  char new_att[5];
}
edit_scan, edit_scan1;
int edit_3(char id[40], char date[40], char *MyFile) 
{
  	FILE * fread_att1;
  	FILE * edit_file;
  	fread_att1 = fopen("Attendance.dll", "r");
  	edit_file = fopen("Attendance Edit.dll", "w");
  	struct s_attendance s_att, s_att_e, s_att_e1;
  	struct Edit_take edit_scan, edit_scan1;
  	int found = 0;
  	SetColor(12);
  	printf("\n\n\t\t\t\t\t\t\t\t Press [p] for present and [a] for absent....");
  	fflush(stdin);
  	SetColor(11);
  	scanf("%s", & edit_scan1.new_att);
  	while (1) 
	{
    	fread(&s_att_e, sizeof(s_att_e), 1, fread_att1);
    	if (feof(fread_att1)) 
		{
      		break;
    	}
    	if (strcmp(id, s_att_e.sid) == 0 && strcmp(date, s_att_e.date) == 0) 
		{
      		found = 1;
      		strcpy(s_att_e.date, s_att_e.date);
      		strcpy(s_att_e.sid, s_att_e.sid);
      		strcpy(s_att_e.sname, s_att_e.sname);
      		strcpy(s_att_e.ati, edit_scan1.new_att);
      		fwrite( & s_att_e, sizeof(s_att_e), 1, edit_file);
    	} 
		else 
		{
      		fwrite(&s_att_e, sizeof(s_att_e), 1, edit_file);
    	}
  	}
  	fclose(fread_att1);
  	fclose(edit_file);
  	if (found == 0) 
	{
    	SetColor(4);
    	printf("\n\t Data Not Found");
  	} 
	else 
	{
    	fread_att1 = fopen("Attendance.dll", "w ");
    	edit_file = fopen("Attendance Edit.dll", "r");
    	while (1) 
		{
      		fread(&s_att_e, sizeof(s_att_e), 1, edit_file);
      		if (feof(edit_file)) 
			{
        		break;
      		}
      		fwrite(&s_att_e, sizeof(s_att_e), 1, fread_att1);
    	}
    	SetColor(14);
    	printf("\n\t\t\t\t\t\t\t\t Edited Successfully");
  	}	
  	fclose(fread_att1);
  	fclose(edit_file);
 	SetColor(45);
  	char end;
  	printf("\n\n\t\t\t\t\t\t\t\t Press 1 To Edit More");
  	printf("\n\t\t\t\t\t\t\t\t Press 2 for go Back");
  	printf("\n\t\t\t\t\t\t\t\t Press 3 for EXIT Software");
  	printf("\n\n\t\t\t\t\t\t\t\t  Select an Option:");
  	end=getche();
  	switch (end) 
	{
  		case '1': att_edit1(MyFile); break;
  		case '2': Attendance_F(MyFile); break;
  		case '3': exit(0); break;
  		default : printf("\n\t\t\t\t\t\t\t\t INVALID KEYWORD");
         		  Sleep(1000);
    			  Home();
  	}
	return 0;
}
int edit_2(int td, char *MyFile) 
{
  	system("cls");
	box(60,5,130,50);
	gotoxy(60,8);
  	FILE * fread_att;
  	int found = 0;
  	int found2 = 0;
  	int loopc = 0;
  	struct s_attendance s_att, s_att_e, s_att_e1;
  	fread_att = fopen("Attendance.dll", "r");
  	fflush(stdin);
  	SetColor(14);
  	printf("\t\t  Enter date: ");
  	SetColor(11);
  	gets(edit_scan.date);
  	FILE * fpsr;
  	fpsr = fopen("Attendance.dll", "r");
  	SetColor(14);
  	while (fread(&s_att, sizeof(s_att), 1, fpsr)) 
	{
    		if (strcmp(edit_scan.date, s_att.date) == 0) 
		{
      			found2 = 1;
      			printf("\n\n\t\t\t\t\t\t\t\t Student Name: %s\n\t\t\t\t\t\t\t\t Student ID: %s\n\t\t\t\t\t\t\t\t Attendance: %s\n", s_att.sname, s_att.sid, s_att.ati);
    		}
  	}
  	if (found2 == 1) 
	{
    		SetColor(14);
    		printf("\n\t\t\t\t\t\t\t\t  Enter Student ID You want to Edit: ");
    		SetColor(11);
    		gets(edit_scan.id);
    		while (fread( & s_att, sizeof(s_att), 1, fread_att)) 
		{
      			loopc = loopc + 1;
      			if (strcmp(edit_scan.id, s_att.sid) == 0 && strcmp(edit_scan.date, s_att.date) == 0) 
			{
        			SetColor(14);
        			printf("\n\n\t\t\t\t\t\t\t\t Student Name: %s", s_att.sname);
       	 			printf("\n\t\t\t\t\t\t\t\t Student ID: %s", s_att.sid);
        			printf("\n\t\t\t\t\t\t\t\t Attendance: %s", s_att.ati);
        			edit_3(s_att.sid, s_att.date,MyFile);
        			break;
      			}
      			if (loopc == td) 
			{
        			SetColor(4);
        			printf("\n\n\t\t\t\t\t\t\t\t\tStudent Not Found");
        			SetColor(45);
        			char end;
        			printf("\n\n\t\t\t\t\t\t\t\t Press 1 To Edit More");
        			printf("\n\t\t\t\t\t\t\t\t Press 2 for go Back");
        			printf("\n\t\t\t\t\t\t\t\t Press 3 for EXIT Software");
        			printf("\n\n\t\t\t\t\t\t\t\t Select an Option:");
        			end=getche();
        			switch (end) 
				{
        				case '1': att_edit1(MyFile); break;
        				case '2': Attendance_F(MyFile); break;
        				case '3': exit(0); break;
        				default: gotoxy(50, 23);
         				 	printf("\n\t  INVALID KEYWORD");
         				 	Sleep(1000);
        				 	Home();
        			}
      			}
    		}
  		if (found == 0) 
		{
    			SetColor(4);
    			printf("\n\n\t\t\t\t\t\t\t\t Data Not Found");
    			SetColor(45);
    			char end;
    			printf("\n\n\t\t\t\t\t\t\t\t Press 1 To Edit More");
    			printf("\n\t\t\t\t\t\t\t\t Press 2 for go Back");
    			printf("\n\t\t\t\t\t\t\t\t Press 3 for EXIT Software");
				printf("\n\n\t\t\t\t\t\t\t\t  Select an Option:");
    			end = getche();
    			switch (end) 
			 {
    				case '1': att_edit1(MyFile); break;
    				case '2': Attendance_F(MyFile); break;
    				case '3': exit(0); break;
   	 			    default : 
      			 	  	printf("\n\t\t\t\t\t\t\t\t INVALID KEYWORD\n");
      				  	Sleep(1000);
      				  	Home();
    			}
  		}
	}
  	return 0;
}
int view_student_att() 
{
  	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
  	SetColor(14);
	struct student std;
  	printf("\t\t\t\t ALL STUDENTS\n\n");
  	FILE * fptr_att;
  	fptr_att = fopen(registerFile1, "rb");
  	while (fread(&std, sizeof(std), 1, fptr_att)) 
	{
    		SetColor(11);
    		printf("\n\t\t\t\t\t\t\t\t  NAME: %s", std.name);
			printf("\n\t\t\t\t\t\t\t\t  ID: %s",std.rno);
			printf("\n\t\t\t\t\t\t\t\t  Section:%s\n",std.section);
  	}
  	fclose(fptr_att);
  	return 0;
}
	
void Marks_F(char *MyFile)
{
	FILE *fp,*fp1;
	fp=fopen(MyFile,"rb");
	struct faculty t;
	struct student s;
	char id[30];
	fread(&t,sizeof(t),1,fp);
	system("cls");
	box(60,5,130,48);
	gotoxy(60,10);
	SetColor(6);
	printf("\t Enter the Id of the student : ");
	fgets(id,sizeof(id),stdin);
	scanf("%[^\n]s",id); 
	strcat(id,".dat");
	fp1=fopen(id,"ab");
  	float a_w_m_c = 0;
  	int t_c = 0;
  	gotoxy(60,12);
	SetColor(12);
  	printf("\t\t\t SEMESTER RESULT COUNT\n");
  	fflush(stdin);
  	printf("\n\t\t\t\t\t\t\t\t  Enter How Many Subject In This Semester>>");
  	scanf("%d", & s.R1.n_f_S);
  	for (s.R1.i = 1; s.R1.i <= s.R1.n_f_S; s.R1.i++) 
	{
    		fflush(stdin);
    		printf("\n\t\t\t\t\t\t\t\t  Enter Subject %d Name >>", s.R1.i);
    		gets(s.R1.R[s.R1.i].sub_name);
    		printf("\n\t\t\t\t\t\t\t\t  Enter %s GPA Result >>", s.R1.R[s.R1.i].sub_name);
    		scanf("%f", & s.R1.R[s.R1.i].cgpa);
    		printf("\n\t\t\t\t\t\t\t\t  Enter %s Credit >>", s.R1.R[s.R1.i].sub_name);
    		scanf("%d", & s.R1.R[s.R1.i].credit);
  	}
  	for (s.R1.i = 1; s.R1.i <= s.R1.n_f_S; s.R1.i++) 
	{
    	s.R1.R[s.R1.i].m_w_c = s.R1.R[s.R1.i].cgpa * s.R1.R[s.R1.i].credit;
  	}
  	for (s.R1.i = 1; s.R1.i <= s.R1.n_f_S; s.R1.i++) 
	{
    	a_w_m_c = a_w_m_c + s.R1.R[s.R1.i].m_w_c;
  	}
  	for (s.R1.i = 1; s.R1.i <= s.R1.n_f_S; s.R1.i++) 
	{
    	t_c = t_c + s.R1.R[s.R1.i].credit;
  	}
  	s.score = a_w_m_c / t_c;

  	for (s.R1.i = 1; s.R1.i <= s.R1.n_f_S; s.R1.i++) 
	{
    		printf("\n\t\t\t\t\t\t\t\t  Subject:: %d %s", s.R1.i, s.R1.R[s.R1.i].sub_name);
			printf("\n\t\t\t\t\t\t\t\t  GPA :: %.2f ",s.R1.R[s.R1.i].cgpa);
			printf("\n\t\t\t\t\t\t\t\t  Credit :: %d",s.R1.R[s.R1.i].credit);
  	}
 	printf("\n\t\t\t\t\t\t\t\t  Result is: %.2f\n", s.score);
	fclose(fp1);
  	char end;
  	printf("\n\t\t\t\t\t\t\t\t  Press 1 for Count More Results\n");
  	printf("\n\t\t\t\t\t\t\t\t  Press 2 for go to home page\n");
  	printf("\n\t\t\t\t\t\t\t\t Select an Option:");
  	end = getche();
  	switch (end)
	{
  		case '1': Marks_F(MyFile); break;
  		case '2': Homepage_F(MyFile,t.password); break;
  		default: printf("\n\t\t\t\t\t\t\t\t  INVALID KEYWORD\n");
  	}
	fclose(fp);
}
void Homepage_S(char *MyFile, char *password)
{
	FILE *fp,*fp1; 
	int c;
	struct student t;
	struct student s;
	fp=fopen(registerFile1,"rb");
	while(1)
	{
		fread(&t,sizeof(t),1,fp);
		if(feof(fp))
		{
			break;
		}
		if((strcmp(MyFile,t.rno)==0) && (strcmp(password,t.password)==0))
		{
			s=t;
			strcat(MyFile,".dat");
			fp1=fopen(MyFile,"ab");
			fwrite(&s,sizeof(s),1,fp1);
			fclose(fp1);
		}
	}
	fclose(fp);
       	while(c!=7)
    	{
       		system("cls");
			box(60,5,130,40);
		    gotoxy(60,9);
       		printf("\t\t\t**** HOMEPAGE MENU ****\n");
			gotoxy(60,12);
       		printf("\t  1.TimeTable\n");
			gotoxy(60,14);
			printf("\t  2.Library details\n");
			gotoxy(60,16);
			printf("\t  3.College details and faculty details\n");
			gotoxy(60,18);
			printf("\t  4.Attendance\n");
			gotoxy(60,20);
			printf("\t  5.Notepad\n");
			gotoxy(60,22);
			printf("\t  6.Settings\n");
			gotoxy(60,24);
       		printf("\t  7.Logout\n\n");
			gotoxy(60,27);
       		printf("\t\t Enter you choice : ");
       		scanf("%d",&c);
       		switch(c)
       		{
			case 1 : TimeTable(MyFile); break;
			case 2 : LibraryDetails(MyFile); break;
			case 3 : CollegeDetails(MyFile); break;
			case 4 : Attendance_S(MyFile); break;
			case 5 : Notepad(MyFile,password); break;
			case 6 : Settings_S(MyFile,password); break;
			case 7 : exit(0);
           	default : gotoxy(60,28);
				      printf("\tInvalid Input\n");
       		}
		getch();
    	}	
}
void TimeTable(char *MyFile)
{
	int n;
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct student t;
	fread(&t,sizeof(t),1,fp);
	while(n!=4)
	{
		system("cls");
		box(60,5,130,40);
		gotoxy(60,10);
		system("color 6");
	    printf("\t\t\t  **** TIME-TABLE ****\n");
		gotoxy(60,12);
		printf("\t  1.IT-A");
		gotoxy(60,14);
		printf("\t  2.IT-B");
		gotoxy(60,16);
		printf("\t  3.IT-C");
		gotoxy(60,18);
		printf("\t  4.Homepage");
		gotoxy(60,20);
		printf("\t\t  Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : timetableITA();
			         break;
			case 2 : timetableITB();
			         break;
			case 3 : timetableITC();
			         break;				 
			case 4 : Homepage_S(MyFile,t.password); exit(0);
			default :{
				     gotoxy(60,22);
          			 printf("\tInvalid Input");
					 TimeTable(MyFile);
			}
		}
		getch();
    	}
}
void timetableITA()
{
	system("cls");
	box(60,5,145,40);
	gotoxy(60,9);
	printf("\t\t\t **** IT-A TIME-TABLE ****");
	gotoxy(60,12);
	printf("\t\t 9:40 to 10:40\t 11:00 to 12:00\t 12:20 to 03:00\t 03:20 to 04:20");
	gotoxy(60,14);
	printf("\tMonday:\t\t OOPS\t\t DELD\t\t DM\t\t DS");
	gotoxy(60,16);
	printf("\tTuesdat\t\t OE\t\t DS\t\t SDC\t\t SDC");
	gotoxy(60,18);
	printf("\tWednesday\t DS\t\t DELD\t\t OOPS\t\t OOPS LAB");
	gotoxy(60,20);
	printf("\tThursday\t DM\t\t OOPS\t\t OE\t\t ES");
	gotoxy(60,22);
	printf("\tFriday\t\t SDC\t\t SDC\t\t DS\t\t MINI PROJECT");
	gotoxy(60,24);
	printf("\tSaturday\t DELD\t\t IE\t\t ES\t\t DM");
	gotoxy(60,27);
	printf("\t\tEnter any key..");
}
void timetableITB()
{
	system("cls");
	box(60,5,145,40);
	gotoxy(60,9);
	printf("\t\t\t **** IT-B TIME-TABLE ****");
	gotoxy(60,12);
	printf("\t\t 9:40 to 10:40\t 11:00 to 12:00\t 12:20 to 03:00\t 03:20 to 04:20");
	gotoxy(60,14);
	printf("\tMonday\t\t OOPS\t\t DS\t\t DELD\t\t OOPS LAB");
	gotoxy(60,16);
	printf("\tTuesday\t\t OE\t\t OOPS\t\t DS\t\t DM");
	gotoxy(60,18);
	printf("\tWednesday\t SDC\t\t SDC\t\t OOPS\t\t DM");
	gotoxy(60,20);
	printf("\tThursday\t DELD\t\t DS\t\t OE\t\t ES");
	gotoxy(60,22);
	printf("\tFriday\t\t DS\t\t DELD\t\t DM\t\t MINI PROJECT");
	gotoxy(60,24);
	printf("\tSaturday\t DM\t\t IE\t\t SDC\t\t SDC");
	gotoxy(60,27);
	printf("\t\tEnter any key..");
}
void timetableITC()
{
	system("cls");
	box(60,5,145,40);
	gotoxy(60,9);
	printf("\t\t\t **** IT-C TIME-TABLE ****");
	gotoxy(60,12);
	printf("\t\t 9:40 to 10:40\t 11:00 to 12:00\t 12:20 to 03:00\t 03:20 to 04:20");
	gotoxy(60,14);
	printf("\tMonday\t\t OOPS\t\t ES\t\t DELD\t\t DS");
	gotoxy(60,16);
	printf("\tTuesday\t\t OE\t\t DM\t\t DS\t\t OOPS");
	gotoxy(60,18);
	printf("\tWednesday\t DM\t\t DS\t\t SDC\t\t SDC");
	gotoxy(60,20);
	printf("\tThursday\t DELD\t\t OOPS\t\t OE\t\t ES");
	gotoxy(60,22);
	printf("\tFriday\t\t DS\t\t DELD\t\t OOPS\t\t MINI PROJECT");
	gotoxy(60,24);
	printf("\tSaturday\t SDC\t\t SDC\t\t DM\t\t IE");
	gotoxy(60,27);
	printf("\t\tEnter any key..");
}
void LibraryDetails(char *MyFile)
{
	system("cls");
	system("color 6");
	printf("\n\n\n\t\t\t\t\t====================================================================================");
	printf("\n\n\t\t\t\t\t\t\t\t LIBRARY DETAILS \n");
	printf("\n\t\t\t\t\t====================================================================================\n");
	printf("\n\t\t\t\t\tDr. Sarvepalli Radhakrishnan Learning Resources Centre, the central Library has a \n\t\t\t\t\tfloor area of 2977 Sq.Mtr. with a reading space 770 Sq.Mtr. It houses more than 12,971 titles, \n\t\t\t\t\t1,12,358 volumes \"includes rare books 123 titles\" and subscribes to \n\t\t\t\t\t25172 E-Journals, 98050 E-Books and also 100 National and International print \n\t\t\t\t\tJournals & magazines. Central library is equipped with different types of Learning resources.\n\n");
	printf("\n\t\t\t\t\tIt also has reprographic facilities. Library uses Online Public Access Catalog \"WEB OPAC\" \n\t\t\t\t\tto access library facilities through digital Library. \n\t\t\t\t\tThe digital library has 22 systems and connected with 1 Gbps->ACT FIBERNET, \n\t\t\t\t\t100 Mbps->BSNL, 100 Mbps->Pioneer E Labs, Internet facilities. \n\n\t\t\t\t\tIt enables students to access remotly to IEEE IEL, ASME, ASCE, ELSEVIER & J-GATE e-journals.\n");
	printf("\t\t\t\t\tThe college provides a book-lending scheme to the students with a full set of \n\t\t\t\t\ttextbooks for a nominal annual payment in addition to the provision of issuing 4 library cards per student. \n\t\t\t\t\tThe library is fully computerized and availability of any book in the \n\t\t\t\t\tlibrary can be checked just by a click of mouse.\n\n");
	printf("\t\t\t\t\tThe Library has a collection of Books, Periodicals C.D-ROM’s on \n\t\t\t\t\tScience and Technology and Humanities including Civil Engineering, Mechanical Engineering, \n\t\t\t\t\tComputer Science, Electronic and Communication, Electrical Engg. and Electornics, \n\t\t\t\t\tMaths, Physics, Chemistry and English.\n");
	printf("\n\t\t\t\t\t====================================================================================");
	getch();
	int n;
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct student t;
	fread(&t,sizeof(t),1,fp);
	while(n!=4)
	{
		system("cls");
		box(60,5,140,40);
	    gotoxy(60,9);
		printf("\t\t\t   LIBRARY DETAILS \n\n");
		gotoxy(60,12);
		printf("\t  1.Departments\n");
		gotoxy(60,14);
		printf("\t  2.Library Staff\n");
		gotoxy(60,16);
		printf("\t  3.Rules & Regulations\n");
		gotoxy(60,18);
		printf("\t  4.Back\n");
		gotoxy(60,20);
		printf("\t  Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : Departments(MyFile); break;
			case 2 : LibraryStaff(); break;
			case 3 : RulesRegulations(); break;
			case 4 : Homepage_S(MyFile, t.password); exit(0);
			default :   gotoxy(60,22);
			           printf("\t  Invalid Input \n");
		}
		getch();
	}
	fclose(fp);	
}
void LibraryStaff()
{
	system("cls");
	box(60,5,140,40);
	gotoxy(60,9);
	system("color 6");
	printf("\t\t\t LIBRARY - STAFF DETAILS \n");
	gotoxy(60,12);
	printf("\t  1.Mr. Ch. Bikshapathi,  M.A., M.L.Sc., PGDC LAN, Library Asst.\n");
	gotoxy(60,14);
	printf("\t  2.Mr. P. Srikanth,  M.A., M.L.Sc., Library Asst.\n");
	gotoxy(60,16);
	printf("\t  3.Mr. P. Chitti Babu,  B.A, MLISC., DEO\n");
	gotoxy(60,18);
	printf("\t  4.Mr. J.Paramesh,  10thclass, Book Bearer\n");
	gotoxy(60,20);
	printf("\t  5.Mr. P. Nagesh,  5th Class, Sr. Attender\n");
	gotoxy(60,22);
	printf("\t  6.Mr. E. Krishnaiah,  6th Class, Sr. Attender\n");
	gotoxy(60,24);
	printf("\t  7.Mr. T. Ravinder Goud,  Inter, CLISC, Attender\n");
    getch();
	system("cls");
	box(60,5,140,40);
	gotoxy(60,9);
	printf("\t\t\t CONTACT DETAILS \n");
	gotoxy(60,12);
	printf("\t  Mr. M. Ravi Kumar");
	gotoxy(60,14);
	printf("\t  Librarian"); 
	gotoxy(60,16);
	printf("\t  040 - 23146095");
	gotoxy(60,18);
	printf("\t  library@staff.vce.ac.in");
	gotoxy(60,20);
	printf("\t  LIBRARY WORKING HOURS - 9:30 AM to 6:30 PM\n\n");
}
void RulesRegulations()
{
	system("cls");
	box(60,5,145,40);
	gotoxy(60,9);
	printf("\t\t\t LIBRARY - RULES AND REGULATIONS \n");
	gotoxy(60,12);
	printf("\t1. Students are advised to bring their ID Cards, whenever they visit the Library.\n");
	gotoxy(60,14);
	printf("\t2. Students are advised NOT to Exchange the Library Cards.\n");
	gotoxy(60,16);
	printf("\t3. Students are advised NOT to take more than one copy of the Same Book.\n");
	gotoxy(60,18);
	printf("\t4. Cell Phone talking and using of MP3 players are NOT allowed inside the Library.\n");
	gotoxy(60,20);
	printf("\t6. Every M.E. & MCA (PG) student are eligible for 6 (Six).");
	gotoxy(60,22);
	printf("\t7. Book Bank Books will be issued to SC/ST students.\n");
	gotoxy(60,24);
	printf("\t8. Consult the Library Staff on Duty for any other Information or Clarification.\n");
	gotoxy(60,26);
	printf("\t9. Reprography facility is available at Library for Photocopying.\n");
	gotoxy(60,28);
	printf("\t10. Borrowers should RETURN the books the Due Date 15 days.");
	gotoxy(60,30);
	printf("\tDelay by 1st week per day (after due date) -	Rs.0.50 library fine\n");
	gotoxy(60,32);
	printf("\tDelay by 2nd week per day - Rs.1.00  library fine\n");
	gotoxy(60,34);
	printf("\tDelay by 3rd week & above per day - Rs.2.00 library fine\n");
	getch();
}
void CollegeDetails(char *MyFile)
{
	int n;
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct student t;
	fread(&t,sizeof(t),1,fp);
	system("cls");
	system("color 6");
	box(60,5,140,40);
	gotoxy(60,9);
	printf("\t\t\t\t VASAVI COLLEGE OF ENGINEERING \n");
	gotoxy(60,12);
	printf("\t\t ***Private Un-aided Non-minority Autonomous Institution*** \n\n\t\t\t\t\t\t\t\t***Affiliated to Osmania University and Approved by AICTE.*** \n");
	gotoxy(60,16);
	printf("\t\t\t\t  OUR VISION \n");
	gotoxy(60,18);
	printf("\tStriving for a symbiosis of technological excellence and human values.\n");
	gotoxy(60,20);
	printf("\t\t\t\t OUR MISSION \n");
	gotoxy(60,22);
	printf("\tTo arm young brains with competitive technology and \n\n\t\t\t\t\t\t\t\t nurture holistic development of the individuals for a better tomorrow.\n\n");
	getch();
	while(n!=3)
	{
		system("cls");
		box(60,5,140,40);
		gotoxy(60,9);
		printf("\t\t\t\t VASAVI COLLEGE OF ENGINEERING \n");
		gotoxy(60,12);
		printf("\t\t ***Private Un-aided Non-minority Autonomous Institution*** ");
		gotoxy(60,14);
		printf("\t\t ***Affiliated to Osmania University and Approved by AICTE.*** \n");
		gotoxy(60,16);
		printf("\t  1.About\n");
		gotoxy(60,18);
		printf("\t  2.Departments\n");
		gotoxy(60,20);
		printf("\t  3.Homepage\n\n");
		gotoxy(60,22);
		printf("\t  Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : About(MyFile); break;
			case 2 : Departments(MyFile); break;
			case 3 : Homepage_S(MyFile,t.password); exit(0);
			default :  gotoxy(60,24);
			           printf("\t   Invalid Input\n");
		}
		getch();
	} 			
	fclose(fp);
}
void About(char *MyFile)
{
	int n;
	while(n!=3)
	{
		system("cls");
		box(60,5,140,40);
		gotoxy(60,9);
		printf("\t\t\t VASAVI COLLEGE OF ENGINEERING \n");
		gotoxy(60,12);
		printf("\t 1. Vasavi Academy Of Education\n");
		gotoxy(60,14);
		printf("\t 2. College\n");
		gotoxy(60,16);
		printf("\t 3. Back\n");
		gotoxy(60,18);
		printf("\t Enter your choice : ");
		scanf("%d",&n); 	
		switch(n)
		{
			case 1 : Academy(); break;
			case 2 : College(); break;
			case 3 : CollegeDetails(MyFile); return;
			default : gotoxy(60,20);
			          printf("\n\t Invalid Input\n");
		}
		getch();
	}
}
void Academy()
{
	system("cls");
	box(60,5,140,40);
	gotoxy(60,9);
	printf("\t\t\t VASAVI ACADEMY OF EDUCATION \n");
	gotoxy(60,12);
	printf("\tIn this age of rapid change and development in science and technology, \n\n\t\t\t\t\t\t\t\teducation has come to be recognised as a major input for the speedy\n\n\t\t\t\t\t\t\t\t development of the nation and the upliftment of its people.\n\n\t\t\t\t\t\t\t\tVasavi Academy of Education is an organisation that has been making vital\n\n\t\t\t\t\t\t\t\t contributions towards this goal.\n\n\t\t\t\t\t\t\t\tThe continuing endeavour of the academy is to carry on this relentless \n\n\t\t\t\t\t\t\t\tservice,in the cause of education, into the future.\n\n");
	getch();
	system("cls");
	system("color 6");
	box(60,5,140,40);
	gotoxy(60,9);
	printf("\t\t\tGOVERNING BODY - VASAVI ACADEMY OF EDUCATION \n");
	gotoxy(60,12);
	printf("\t1. Sri. P. Ramamohan Rao  \t - \tPresident\n");
	gotoxy(60,14);
	printf("\t2. Prof. T. V. Subba Rao  \t - \tVice-President\n");
	gotoxy(60,16);
	printf("\t3. Sri. M.Krishna Murthy  \t - \tSecretary\n");
	gotoxy(60,18);
	printf("\t4. Sri. P.V. Ratnam       \t - \tJoint-Secretary\n");
	gotoxy(60,20);
	printf("\t5. Sri.V.M.Parthasarathi  \t - \tTreasurer\n");
	gotoxy(60,22);
	printf("\t6. Sri. K.Ashok Kumar     \t - \tMember\n");
	gotoxy(60,24);
	printf("\t7. Sri. P. Balaji         \t - \tMember\n");
	gotoxy(60,26);
	printf("\t8. Sri. P. Gouri Prasad   \t - \tMember\n");
	gotoxy(60,28);
	printf("\t9. Smt. P. Indrani        \t - \tMember\n");
	gotoxy(60,30);
	printf("\t10. Prof. T.Revathy       \t - \tMember\n");
	gotoxy(60,32);
	printf("\t11. Prof.Dr.V.Srinivasulu \t - \tMember\n");
	gotoxy(60,34);
	printf("\t12. Sri.L.Subba Gurumurthy\t - \tMember\n");
}
void College()
{
	system("cls");
	system("color 6");
	printf("\n\n\t\t\t\t\t\t\t\t============================================================================");
	printf("\n\n\t\t\t\t\t\t\t\t\t VASAVI ACADEMY OF EDUCATION \n");
	printf("\n\t\t\t\t\t\t\t\t============================================================================\n");
	printf("\n\n\t\t\t\t\t\t\t\tFounded in 1981 by Vasavi Academy of Education,\n\n\t\t\t\t\t\t\t\tVasavi College of Engineering represents a rich tradition of excellence in technology-based education.\n\n\t\t\t\t\t\t\t\tA premier-league institution among the affiliates of Osmania University, Vasavi College of Engineering\n\n\t\t\t\t\t\t\t\towes its vision to Sri Pendekanti Venkata Subbaiah, a veteran statesman of Independent India.\n\n");
	printf("\n\n\t\t\t\t\t\t\t\tVasavi College of Engineering, in its 39 years of existence, is a reputed institution \n\n\t\t\t\t\t\t\t\tin the State of Telangana.The college in its pursuit for quality in technical\n\n\t\t\t\t\t\t\t\teducation has earned 3rd ranking in the State and 32nd in the country\n\n\t\t\t\t\t\t\t\t-source: Hindustan Times on 24th June 2009.\n\n");
	printf("\n\n\t\t\t\t\t\t\t\tThe college offers six UG, they are : Civil, Mechanical, ECE, CSE, EEE and IT;\n\n\t\t\t\t\t\t\t\twith total sanctioned intake of 780 and 6 PG programmes\n\n\t\t\t\t\t\t\t\tME :\"ES & VLSI\";\n\t\t\t\t\t\t\t\tME :\"CE & SP\" ;\n\t\t\t\t\t\t\t\tME :\"ADM\";\n\t\t\t\t\t\t\t\tME : \"PS & PE\";\n\t\t\t\t\t\t\t\tM.Tech -CSE and MCA with total sanctioned intake of 156.\n");
	printf("\n\t\t\t\t\t\t\t\t============================================================================\n");
	getch();
	system("cls");
	box(60,5,140,40);
	gotoxy(60,9);
	printf("\t\t\t\t VASAVI ACADEMY OF EDUCATION \n");
	gotoxy(60,12);
	printf("\t\t CONTACT\n\n");
	gotoxy(60,14);
	printf("\tVasavi College of Engineering\n\n\t\t\t\t\t\t\t\tPrivate Un-aided Non-minority Autonomous Institution\n\n\t\t\t\t\t\t\t\tSponsored by Vasavi Academy of Education\n\n\t\t\t\t\t\t\t\tAffiliated to Osmania University, Hyderabad\n\n\t\t\t\t\t\t\t\tApproved by AICTE, New Delhi\n\n\t\t\t\t\t\t\t\t9-5-81, Ibrahimbagh\n\n\t\t\t\t\t\t\t\tHyderabad - 500 031\n\n\t\t\t\t\t\t\t\tTelangana, India\n\n\t\t\t\t\t\t\t\tTel: +91 40 23146003\n\n\t\t\t\t\t\t\t\tFax: +91 40 23146\n\n\t\t\t\t\t\t\t\t090\n\n\t\t\t\t\t\t\t\tprincipal@staff.vce.ac.in\n\n\t\t\t\t\t\t\t\twww.vce.ac.in\n");
}	
void Departments(char *MyFile)
{
	int n;
	while(n!=3)
	{
		system("cls");
		box(60,5,130,40);
		gotoxy(60,9);
		printf("\t\t\t\t DEPARTMENTS \n");
		gotoxy(60,12);
		printf("\t  1.Information technology\n");
		gotoxy(60,14);
		printf("\t  2.Computer Science\n");
		gotoxy(60,16);
		printf("\t  3.Back\n");
		gotoxy(60,18);
		printf("\t  Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : IT(MyFile); break;
			case 2 : CSE(MyFile); break;
			case 3 : CollegeDetails(MyFile); return;
		   default : gotoxy(60,20);
					 printf("\t\t Invalid Input\n");
					 getch();
					 Departments(MyFile);
		}
		getch();
	}	
}
void IT(char *MyFile)
{
	int n,sem;
	system("cls");
	box(60,5,140,40);
	gotoxy(60,9);
	printf("\t\t\t DEPARTMENT OF INFORMATION TECHNOLOGY \n");
	gotoxy(60,12);
	printf("\t\t\tDEPARTMENT VISION\n\n");
	gotoxy(60,14);
	printf("\tTo be a centre of excellence in core Information Technology and\n\n\t\t\t\t\t\t\t\t multidisciplinary learning and research, where students get trained in\n\n\t\t\t\t\t\t\t\t latest technologies for professional and societal growth.\n");
	gotoxy(60,22);
	printf("\t\t\tDEAPRTMENT MISSION\n\n");
	gotoxy(60,24);
	printf("\tTo enable the students acquire skills related to latest \n\n\t\t\t\t\t\t\t\ttechnologies in IT through practice- oriented teaching and training.\n\n");
	getch();
	while(n!=3)
	{
		system("cls");
		box(60,5,140,40);
	    gotoxy(60,9);
		printf("\t\t\t DEPARTMENT OF INFORMATION TECHNOLOGY \n");
		gotoxy(60,12);
		printf("\t  1.Syllabus\n");
		gotoxy(60,14);
		printf("\t  2.Staff\n");
		gotoxy(60,16);
		printf("\t  3.Back\n");
		gotoxy(60,18);
		printf("\t  Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : gotoxy(60,20);
			         printf("\t  Semestre Number (/8) : ");
					 scanf("%d",&sem); 
					 IT_Syllabus(sem, MyFile);
					 break;
			case 2 : IT_Staff(); break;
			case 3 : Departments(MyFile); return;
			default :	gotoxy(60,20); 
					 printf("\t   Invalid Input\n");
		}
		getch();
	}		
}
void IT_Syllabus(int sem, char *MyFile)
{
	if(sem==1)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-1 \n");
		gotoxy(60,12);
		printf("\tTHEORY : \n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE        NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tU19HS110EH - English Language and Communication - I : 2 credits\n");
		gotoxy(60,18);
		printf("\tU19BS110MA - Engineering Mathematics - I : 3 credits\n");
		gotoxy(60,20);
		printf("\tU19BS110PH - Semiconductor Physics and Optoelectronic Devices : 4 credits\n");
		gotoxy(60,22);
		printf("\tU19ES120CS - Programming for Problem Solving : 3 credits\n");
		gotoxy(60,24);
		printf("\tU19ES010EE - Basic Electrical Engineering : 2 credits\n");
		gotoxy(60,26);
		printf("\tU19ES030CE - Engineering Drawing : 2 credits\n");
		gotoxy(60,28);
		printf("\tPRACTICALS\n\n");
		gotoxy(60,30);
		printf("\tU19HS111EH - English Language and Communication Skills Lab-I : 1 credit\n");
		gotoxy(60,32);
		printf("\tU19BS111PH - Semiconductor and Optoelectronics Lab : 1 credit\n");
		gotoxy(60,34);
		printf("\tU19ES121CS - Programming for Problem Solving Lab : 1 credit\n");
		gotoxy(60,36);
		printf("\tU19ES011EE - Basic Electrical Engineering Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\t\tTOTAL CREDITS = 20 \n");	
	}
	else if(sem==2)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-2 \n");
		gotoxy(60,10);
		printf("\tTHEORY :\n\n");
		gotoxy(60,12);
		printf("\tCOURSE CODE        NAME OF THE COURSE  \n");
		gotoxy(60,14);
		printf("\tU19HS210EH - English Language and Communication - II : 2 credits\n");
		gotoxy(60,16);
		printf("\tU19BS210MA - Engineering Mathematics - II : 3 credits\n");
		gotoxy(60,18);
		printf("\tU19BS210CH - Engineering Chemistry : 4 credits\n");
		gotoxy(60,20);
		printf("\tU19ES010CE - Basic Engineering Mechanics : 3 credits\n");
		gotoxy(60,22);
		printf("\tU19ES210IT - Basic Electronics : 3 credits\n");
		gotoxy(60,24);
		printf("\tU19PC210IT - Introduction to Python Programming  : 2 credits\n");
		gotoxy(60,26);
		printf("\tPRACTICALS : \n\n");
		gotoxy(60,28);
		printf("\tU19HS211EH - English Language and Communication Skills Lab-II : 1 credit\n");
		gotoxy(60,30);
		printf("\tU19BS011CH - Chemistry Lab : 1 credit\n");
		gotoxy(60,32);
		printf("\tU19ES021ME - Engineering Workshop : 1 credit\n");
		gotoxy(60,34);
		printf("\tU19ES211IT - Basic Electronics Lab  : 1 credit\n");
		gotoxy(60,36);
		printf("\t\tTOTAL CREDITS = 21 \n");	
	}
	else if(sem==3)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-3 \n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE        NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tU18HS330EH - Skill Development-I :Communication Skills in English :2 credits\n");
		gotoxy(60,18);
		printf("\tU18BS340MA - Discrete Mathematics : 3 credits\n");
		gotoxy(60,20);
		printf("\tU18ES310IT - Basic Electronics : 3 credits\n");
		gotoxy(60,22);
		printf("\tU18ES320IT - Digital Electronics and Logic Design : 3 credits\n");
		gotoxy(60,24);
		printf("\tU18PC310IT - Advanced Data Structures : 2 credits\n");
		gotoxy(60,26);
		printf("\tU18PC320IT - Object Oriented Programming : 3 credits\n");
		gotoxy(60,28);
		printf("\tU18OE3XXXX - Open Elective - I : 2 credits\n"); 
		gotoxy(60,30);
		printf("\tU18MC010CE - Environmental Science : 0 credits\n");
		gotoxy(60,32);
		printf("\tU18MC310ME - Introduction to Entrepreneurship : 0 credits\n");
		gotoxy(60,34);
		printf("\tPRACTICALS\n\n");
		gotoxy(60,36);
		printf("\tU18PC311IT - Advanced Data Structures Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\tU18PC321IT - Object Oriented Programming Lab : 1 credit\n");
		gotoxy(60,40);
		printf("\t\tTOTAL CREDITS = 20 \n");
	}
	else if(sem==4)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-4 \n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE        NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tU18HS010EH - Human Values and Professional Ethics-I : 1 credit\n");
		gotoxy(60,18);
		printf("\tU18HS430EH - Skill Development-II:Communication Skills in English :2 credits\n");
		gotoxy(60,20);
		printf("\tU18BS420MA - Probability and Statistics : 3 credits\n");
		gotoxy(60,22);
		printf("\tU18PC410IT - Computer Organization : 3 credits\n");
		gotoxy(60,24);
		printf("\tU18PC420IT - Database Management Systems : 3 credits\n");
		gotoxy(60,26);
		printf("\tU18PC430IT - Design and Analysis of Algorithms : 3 credits\n");
		gotoxy(60,28);
		printf("\tU18PC440IT - Software Engineering : 2 credits\n");
		gotoxy(60,30);
		printf("\tU18OE4XXXX - Open Elective - II : 3 credits\n");
		gotoxy(60,32);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,34);
		printf("\tU18PC411IT - Database Management Systems Lab : 1 credit\n");
		gotoxy(60,36);
		printf("\tU18PC421IT - Design and Analysis of Algorithms Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\tU18PC431IT - Software Engineering Lab : 1 credit\n");
		gotoxy(60,40);
		printf("\t\tTOTAL CREDITS = 23\n");
	}
	else if(sem==5)
	{
		system("cls");
		system("color 6");
	    box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-5\n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE        NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tHS510EH -   Finishing School–III : Soft Skills : 1 credit\n");
		gotoxy(60,18);
		printf("\tPC510IT -   Computer Networks : 3 credits\n");
		gotoxy(60,20);
		printf("\tPC520IT -   Microprocessors and Interfacing : 3 credits\n");
		gotoxy(60,22);
		printf("\tPC530IT -   Operating Systems : 3 credits\n");
		gotoxy(60,24);
		printf("\tPC540IT -   Software Engineering : 3 credits\n");
		gotoxy(60,26);
		printf("\tPC550IT -   Theory of Automata : 3 credits\n");
		gotoxy(60,28);
		printf("\tPE510IT -   Finishing School - III : Technical Skills : 1 credit\n");
		gotoxy(60,30);
		printf("\tOE5XXXX -   Open Elective - IV : 3 credits\n");
		gotoxy(60,32);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,34);
		printf("\tPC511IT -   Computer Networks Lab : 1 credit\n");
		gotoxy(60,36);
		printf("\tPC521IT -   Microprocessors and Interfacing Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\tPC531IT -   Operating Systems Lab : 1 credit\n");
		gotoxy(60,40);
		printf("\tPC541IT -   Software Engineering Lab : 1 credit\n"); 
		gotoxy(60,42);
		printf("\t\tTOTAL CREDITS = 24\n");
	}
	else if(sem==6)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-6 \n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE      NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tHS040EH  -  Economics and Finance for Engineers : 2 credits\n");
		gotoxy(60,18);
		printf("\tHS620EH  -  Finishing School - IV : Soft Skills : 1 credit\n");
		gotoxy(60,20);
		printf("\tPC610IT  -  Artificial Intelligence and Machine Learning : 3 credits\n");
		gotoxy(60,22);
		printf("\tPC620IT  -  Embedded Systems : 3 credits\n");
		gotoxy(60,24);
		printf("\tPC630IT  -  Web Technologies : 3 credits\n");
		gotoxy(60,26);
		printf("\tPE610IT  -  Finishing School - IV : Technical Skills : 1 credit\n");
		gotoxy(60,28);
		printf("\tOE6XXXX  -  Open Elective - V : 3 credits\n");
		gotoxy(60,30);
		printf("\tMC040EH  -  Human Values and Professional Ethics - II : 1 credit\n");
		gotoxy(60,32);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,34);
		printf("\tPC611IT  -  Artificial Intelligence and Machine Learning Lab  : 1 credit\n");
		gotoxy(60,36);
		printf("\tPC621IT  -  Embedded Systems Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\tPC631IT  -  Web Technologies Lab : 1 credit\n");
		gotoxy(60,40);
		printf("\tP619IT   -  Mini Project - III  : 1 credit\n"); 
		gotoxy(60,42);
		printf("\t\tTOTAL CREDITS = 21\n");
	}
	else if(sem==7)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-7 \n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE      NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tPC710IT   - Distributed Systems and Cloud Computing : 3 credits\n");
		gotoxy(60,18);
		printf("\tPC720IT   - Machine Learning : 3 credits\n");
		gotoxy(60,20);
		printf("\tPE7XXIT   - Professional Elective - II : 3 credits\n");
		gotoxy(60,22);
		printf("\tPE7XXIT   - Professional Elective - III : 3 credits\n");
		gotoxy(60,24);
		printf("\tPE7XXIT   - Professional Elective - IV : 3 credits\n");
		gotoxy(60,26);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,28);
		printf("\tPC711IT   - Distributed Systems and Cloud Computing Lab   : 1 credit\n");
		gotoxy(60,30);
		printf("\tPC721IT   - Machine Learning Lab : 1 credit\n");
		gotoxy(60,32);
		printf("\tPC731IT   - Software Engineering Lab : 1 credit\n");
		gotoxy(60,34);
		printf("\tPW719IT   - Project Seminar : 1 credit\n"); 
		gotoxy(60,36);
		printf("\t\tTOTAL CREDITS = 19\n");
	}
	else if(sem==8)
	{
		system("cls");
		system("color 6");
		box(60,5,130,40);
	    gotoxy(60,9);
		printf("\t\t\t INFORMATION TECHNOLOGY SEMESTER-8 \n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE      NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tPE8XXIT    - Professional Elective - V : 3 credits\n");
		gotoxy(60,18);
		printf("\tPE8XXIT    - Professional Elective -VI : 3 credits\n");
		gotoxy(60,20);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,22);
		printf("\tPW819IT    - Project / Internship : 8 credits\n");
		gotoxy(60,24);
		printf("\t\tTOTAL CREDITS = 14\n");	
	}
	else
	{
		printf("\n\n\t\t\t\t\t\t\tWrong input- please try again!\n");
		getch();
		IT(MyFile);
	}
	return;
}
void IT_Staff()
{
	system("cls");
	system("color 6");
	box(60,5,130,40);
	gotoxy(60,9);
	printf("\t\t FACULTY - DEPARTMENT OF INFORMATION TECHNOLOGY  \n");
	printf("\n\n\n\n\t\t\t\t\t\t\t\tDr. K. Rammohan Rao is Professor and Head of the Department.\n\n\t\t\t\t\t\t\t\tThe faculty have teaching expertise in C and Data Structures,\n\n\t\t\t\t\t\t\t\tJava,Web Technologies,Networking,Soft Engineering, AI, ST,\n\n\t\t\t\t\t\t\t\tCompiler Construction, Data and Mobile Communication,\n\n\t\t\t\t\t\t\t\tData Mining, Microprocessors, VLSI Design, Embedded Systems.\n");
	getch();
	system("cls");
	system("color 5");
	box(60,5,140,44);
    gotoxy(60,9);
	printf("\t\t FACULTY - DEPARTMENT OF INFORMATION TECHNOLOGY  \n");
	gotoxy(60,12);
	printf("\tId : 1280, Dr. K. Ram Mohan Rao, M.Tech, Ph.D., Professor & HOD\n");
	gotoxy(60,14);
	printf("\tId : 2080, Dr. V. Venkata Krishna,  M.Tech, Ph.D, Professor\n");
	gotoxy(60,16);
	printf("\tId : 2100, Dr. Ramesh Vasappanavara ,  M.Tech., Ph.D , Professor\n");
	gotoxy(60,18);
	printf("\tId : Mr. Amar Sharma ,  M.Tech ., Adj.Prof.\n");
	gotoxy(60,20);
	printf("\tId : Mr. Amit Kumar Gupta ,  M.Tech , Adj.Prof.\n");
	gotoxy(60,22);
	printf("\tId : 1395, Ms. S. Aruna,  M.Tech., Associate Professor\n");
	gotoxy(60,24);
	printf("\tId : 1307, Ms. S. Sree Lakshmi, M.Tech., Assistant Professor -\"Sr.Scale\"\n");
	gotoxy(60,26);
	printf("\tId : 1877, Mr. G. Rajashekhar,  M.E., Assistant Professor\n");
	gotoxy(60,28);
	printf("\tId : 1899, Mr. M. Vishnu Chaitanya,  M.Tech., Assistant Professor\n");
	gotoxy(60,30);
	printf("\tId : 1935, Ms. DRL Prasanna,  M.Tech., Assistant Professor\n");
	gotoxy(60,32);
	printf("\tId : 1938, Ms. L. Divya,  M.S., Assistant Professor\n");
	gotoxy(60,34);
	printf("\tId : 1960, Mr. G. Srinivas Rao,  M.Tech., Assistant Professor\n");
	gotoxy(60,36);
	printf("\tId : 1529, Mr. K. Srinivasa Chakravarthy,  M.Tech., Assistant Professor\n");
	gotoxy(60,38);
	printf("\tId : 2025, Ms. B.Leelavathy,  M.Tech., Assistant Professor\n");
	gotoxy(60,40);
	printf("\tId : 2026, Mr. M. Krishna Kishore,  M.Tech., Assistant Professor\n");
	getch();
	system("cls");
	system("color 6");
	box(60,5,130,30);
	gotoxy(60,9);
	printf("\t\t\t CONTACT DETAILS  \n");
	gotoxy(60,12);
	printf("\tDr. K. Ram Mohan Rao");
	gotoxy(60,14);
	printf("\tProfessor and Head of the Department");
	gotoxy(60,16);
	printf("\t040 - 23146050");
	gotoxy(60,18);
	printf("\thodit@staff.vce.ac.in\n");
}
void CSE(char *MyFile)
{
	int n,sem;
	system("cls");
	box(60,5,130,40);
	gotoxy(60,9);
	printf("\t\t\t DEPARTMENT OF COMPUTER SCIENCE \n");
	gotoxy(60,12);
	printf("\t\tDEPARTMENT VISION\n");
	gotoxy(60,14);
	printf("\tBe a pioneer in producing ethical and competent professionals");
	gotoxy(60,16);
	printf("\tin the domain of Computer Science and Engineering.\n");
	gotoxy(60,18);
	printf("\t\tDEAPRTMENT MISSION\n");
	gotoxy(60,20);
	printf("\tTo build analytical and synthesizing skills in the domain of");
	gotoxy(60,22);
    printf("\tComputer Science and Engineering for the benefit of the society.\n");
	getch();
	while(n!=3)
	{
		system("cls");
		box(60,5,140,40);
	    gotoxy(60,9);
		printf("\t\t\t DEPARTMENT OF COMPUTER SCIENCE \n");
		gotoxy(60,12);
		printf("\t  1.Syllabus\n");
		gotoxy(60,14);
		printf("\t  2.Staff\n");
		gotoxy(60,16);
		printf("\t  3.Back\n");
		gotoxy(60,18);
		printf("\t Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : gotoxy(60,20);
			     printf("\t  Semestre Number (/8) : ");
				 scanf("%d",&sem); 
				 CSE_Syllabus(sem,MyFile); break;
			case 2 : CSE_Staff(); break;
			case 3 : Departments(MyFile); return;
			default : gotoxy(60,20);
			printf("\t  Invalid Input\n");
		}
		getch();
	}
}
void CSE_Syllabus(int sem, char *MyFile)
{
	if(sem==1)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t\t COMPUTER SCIENCE SEMESTER-1 \n");
		gotoxy(60,12);
		printf("\tTHEORY : \n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE        NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tU19HS110EH - English Language and Communication - I : 2 credits\n");
		gotoxy(60,18);
		printf("\tU19BS110MA - Engineering Mathematics - I : 3 credits\n");
		gotoxy(60,20);
		printf("\tU19BS110PH - Semiconductor Physics and Optoelectronic Devices : 4 credits\n");
		gotoxy(60,22);
		printf("\tU19ES120CS - Programming for Problem Solving : 3 credits\n");
		gotoxy(60,24);
		printf("\tU19ES010EC - Introduction to Electronics Engineering : 3 credits\n");
		gotoxy(60,26);
		printf("\tU19ES030CE - Engineering Drawing : 2 credits\n");
		gotoxy(60,28);
		printf("\tPRACTICALS\n\n");
		gotoxy(60,30);
		printf("\tU19HS111EH - English Language and Communication Skills Lab-I : 1 credit\n");
		gotoxy(60,32);
		printf("\tU19BS111PH - Semiconductor and Optoelectronics Lab : 1 credit\n");
		gotoxy(60,34);
		printf("\tU19ES121CS - Programming for Problem Solving Lab : 1 credit\n");
		gotoxy(60,36);
		printf("\tU19ES011EC - Introduction to Electronic Engineering Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\t\tTOTAL CREDITS = 21 \n");	
	}
	else if(sem==2)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t\t COMPUTER SCIENCE SEMESTER-2 \n");
		gotoxy(60,12);
		printf("\tTHEORY : \n\n");
		gotoxy(60,14);
		printf("\tNAME OF THE COURSE  :\n");
		gotoxy(60,16);
		printf("\t1.English Language and Communication - II : 2 credits\n");
		gotoxy(60,18);
		printf("\t2.Engineering Mathematics - II : 3 credits\n");
		gotoxy(60,20);
		printf("\t3.Material Chemistry : 3 credits\n");
		gotoxy(60,22);
		printf("\t4.Basic Electrical Engineering : 2 credits\n");
		gotoxy(60,24);
		printf("\t5.Basic Engineering Mechanics : 3 credits\n");
		gotoxy(60,26);
		printf("\t6.Discrete Structures : 3 credits\n");
		gotoxy(60,28);
		printf("\t7.Python Programming : 2\n");
		gotoxy(60,30);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,32);
		printf("\t1.English Language and Communication Skills Lab - II : 1 credit\n");
		gotoxy(60,34);
		printf("\t2.Chemistry Lab : 1 credit\n");
		gotoxy(60,36);
		printf("\t3.Basic Electrical Engineering Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\t4.Python Programming Lab : 1 credit\n");
		gotoxy(60,40);
		printf("\t\tTOTAL CREDITS = 22\n\n");
	}
	else if(sem==3)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t\t COMPUTER SCIENCE SEMESTER-3 \n");
		gotoxy(60,12);
		printf("\tTHEORY : \n\n");
		gotoxy(60,14);
		printf("\tNAME OF THE COURSE  :\n");
		gotoxy(60,16);
		printf("\t1.Skill Development - I : Communication Skills in English : 2 credits\n");
		gotoxy(60,18);
		printf("\t2.Human Values and Professional Ethics-I : 1 credit\n");
		gotoxy(60,20);
		printf("\t3.Transform Calculus, Probability and Statistics : 3 credits\n");
		gotoxy(60,22);
		printf("\t4.Logic and Switching Theory : 3 credits\n");
		gotoxy(60,24);
		printf("\t5.Data Structures : 3 credits\n");
		gotoxy(60,26);
		printf("\t6.Object Oriented Programming : 3 credits\n");
		gotoxy(60,28);
		printf("\t7.Computer Architecture : 3 credits\n");
		gotoxy(60,30);
		printf("\t8.Open Elective-I : 2 credits\n");
		gotoxy(60,32);
		printf("\t9.Introduction to Entrepreneurship : 0 credits\n");
		gotoxy(60,34);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,36);
		printf("\t1.Data Structures Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\t2.Object Oriented Programming Lab : 1 credit\n");
		gotoxy(60,40);
		printf("\t\tTOTAL CREDITS = 22\n");	
	}
	else if(sem==4)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t\t COMPUTER SCIENCE SEMESTER-4 \n");
		gotoxy(60,12);
		printf("\tTHEORY : \n\n");
		gotoxy(60,14);
		printf("\tNAME OF THE COURSE  :\n");
		gotoxy(60,16);
		printf("\t1.Skill Development - II : Communication Skills in English : 2 credits\n");
		gotoxy(60,18);
		printf("\t2.Microprocessors, Microcontroller & Interfacing : 3 credits\n");
		gotoxy(60,20);
		printf("\t3.Operating Systems : 3 credits\n");
		gotoxy(60,22);
		printf("\t4.Design & Analysis of Algorithms : 3 credits\n");
		gotoxy(60,24);
		printf("\t5.Automata, Languages and Computation : 3 credits\n");
		gotoxy(60,26);
		printf("\t6.Open Elective-II : 3 credits\n");
		gotoxy(60,28);
		printf("\t7.Environmental Science : 0 credits\n");
		gotoxy(60,30);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,32);
		printf("\t1.Microprocessors, Microcontroller & Interfacing Lab : 1 credit\n");
		gotoxy(60,34);
		printf("\t2.Operating Systems Lab : 1 credit\n");
		gotoxy(60,36);
		printf("\t3.Design & Analysis of Algorithms Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\t4.Mini Project-I : 1 credit\n");
		gotoxy(60,40);
		printf("\t\tTOTAL CREDITS = 21 \n\n");	  
	}
	else if(sem==5)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t\t COMPUTER SCIENCE SEMESTER-5 \n");
		gotoxy(60,12);
		printf("\tTHEORY : \n\n");
		gotoxy(60,14);
		printf("\tNAME OF THE COURSE  :\n");
		gotoxy(60,16);
		printf("\t1.Skill Development-III (Soft Skills) : 1 credit\n");
		gotoxy(60,18);
		printf("\t2.Human Values and Professional Ethics-II : 1 credit\n");
		gotoxy(60,20);
		printf("\t3.Economics and Finance for Engineers : 2 credits\n");
		gotoxy(60,22);
		printf("\t4.Database Management Systems : 3 credits\n");
		gotoxy(60,24);
		printf("\t5.Computer Networks : 3 credits\n");
		gotoxy(60,26);
		printf("\t6.Web Programming and Services : 3 credits\n");
		gotoxy(60,28);
		printf("\t7.Skill Development-III -Technical Skills : 1 credit\n");
		gotoxy(60,30);
		printf("\t8.Open Elective-IV : 3 credits\n");
		gotoxy(60,32);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,34);
		printf("\t1.Database Management Systems Lab : 1 credit\n");
		gotoxy(60,36);
		printf("\t2.Computer Networks Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\t3.Web Programming and Services Lab : 1 credits\n");
		gotoxy(60,40);
		printf("\t4.Mini Project : 1 credit]\n");
		gotoxy(60,42);
		printf("\t\tTOTAL CREDITS = 21\n\n");
	}
	else if(sem==6)
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t COMPUTER SCIENCE SEMESTER-6 \n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE      NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tHS040EH  -  Economics and Finance for Engineers : 2 credits\n");
		gotoxy(60,18);
		printf("\tHS620EH  -  Finishing School - IV : Soft Skills : 1 credit\n");
		gotoxy(60,20);
		printf("\tPC610IT  -  Artificial Intelligence and Machine Learning : 3 credits\n");
		gotoxy(60,22);
		printf("\tPC620IT  -  Embedded Systems : 3 credits\n");
		gotoxy(60,24);
		printf("\tPC630IT  -  Web Technologies : 3 credits\n");
		gotoxy(60,26);
		printf("\tPE610IT  -  Finishing School - IV : Technical Skills : 1 credit\n");
		gotoxy(60,28);
		printf("\tOE6XXXX  -  Open Elective - V : 3 credits\n");
		gotoxy(60,30);
		printf("\tMC040EH  -  Human Values and Professional Ethics - II : 1 credit\n");
		gotoxy(60,32);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,34);
		printf("\tPC611IT  -  Artificial Intelligence and Machine Learning Lab  : 1 credit\n");
		gotoxy(60,36);
		printf("\tPC621IT  -  Embedded Systems Lab : 1 credit\n");
		gotoxy(60,38);
		printf("\tPC631IT  -  Web Technologies Lab : 1 credit\n");
		gotoxy(60,40);
		printf("\tP619IT   -  Mini Project - III  : 1 credit\n"); 
		gotoxy(60,42);
		printf("\t\tTOTAL CREDITS = 21\n");
	}
	else if(sem==7)	
	{
		system("cls");
		system("color 6");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t COMPUTER SCIENCE SEMESTER-7 \n");
		gotoxy(60,12);
		printf("\tTHEORY :\n\n");
		gotoxy(60,14);
		printf("\tCOURSE CODE      NAME OF THE COURSE  \n");
		gotoxy(60,16);
		printf("\tPC710IT   - Distributed Systems and Cloud Computing : 3 credits\n");
		gotoxy(60,18);
		printf("\tPC720IT   - Machine Learning : 3 credits\n");
		gotoxy(60,20);
		printf("\tPE7XXIT   - Professional Elective - II : 3 credits\n");
		gotoxy(60,22);
		printf("\tPE7XXIT   - Professional Elective - III : 3 credits\n");
		gotoxy(60,24);
		printf("\tPE7XXIT   - Professional Elective - IV : 3 credits\n");
		gotoxy(60,26);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,28);
		printf("\tPC711IT   - Distributed Systems and Cloud Computing Lab   : 1 credit\n");
		gotoxy(60,30);
		printf("\tPC721IT   - Machine Learning Lab : 1 credit\n");
		gotoxy(60,32);
		printf("\tPC731IT   - Software Engineering Lab : 1 credit\n");
		gotoxy(60,34);
		printf("\tPW719IT   - Project Seminar : 1 credit\n"); 
		gotoxy(60,36);
		printf("\t\tTOTAL CREDITS = 19\n");
	}
	else if(sem==8)
	{
		system("cls");
		box(60,5,140,44);
	    gotoxy(60,9);
		printf("\t\t\t\t COMPUTER SCIENCE SEMESTER-8 \n");
		gotoxy(60,12);
		printf("\tTHEORY : \n\n");
		gotoxy(60,14);
		printf("\tNAME OF THE COURSE  :\n");
		gotoxy(60,16);
		printf("\t1.Professional Elective-V : 3 credits\n");
		gotoxy(60,18);
		printf("\t2.Professional Elective-VI : 3 credits\n");
		gotoxy(60,20);
		printf("\tPRACTICALS :\n\n");
		gotoxy(60,22);
		printf("\t1.Project /Internship : 9 credits\n");
		gotoxy(60,24);
		printf("\t\tTOTAL CREDITS = 15\n");
	}
	else
	{
		printf("\n\tWrong input. Please try again...\n");
		getch();
		CSE(MyFile);
	}
	return ;
}
void CSE_Staff()
{
	system("cls");
	system("color 6");
    box(60,5,140,40);
    gotoxy(60,9);
	printf("\t\t\t FACULTY - DEPARTMENT OF COMPUTER SCIENCE  \n");
	printf("\n\n\t\t\t\t\t\t\t\tDr. T. Adilakshmi, Professor and head of the Department,has 27 years experience.\n\n\t\t\t\t\t\t\t\tThe department has 26 well-qualified & experienced faculty members.\n\n\t\t\t\t\t\t\t\tOsmania University has recognized the department as a Research Center and\n\n\t\t\t\t\t\t\t\ttwo professors are recognized as Research Supervisors.\n\n\t\t\t\t\t\t\t\tThe faculty members have varied academic interests and some of their\n\n\t\t\t\t\t\t\t\tspecialized fields include Data Mining, Artificial Intelligence,\n\n\t\t\t\t\t\t\t\tImage Processing, Cloud Computing etc.\n\n\t\t\t\t\t\t\t\tThe department has been associated with eminent industries to carry-out\n\n\n\t\t\t\t\t\t\t\t research/consultancy work.\n\n");
	getch();
	system("cls");
	system("color 1");
	box(60,5,140,44);
    gotoxy(60,9);
	printf("\t\t\t FACULTY - DEPARTMENT OF COMPUTER SCIENCE  \n");
	gotoxy(60,12);
	printf("\tId : 1279, Dr. T.Adilakshmi,  M.Tech, Ph.D., Professor & HOD\n");
	gotoxy(60,14);
	printf("\tId : 1557, Dr. Nagaratna P. Hegde,  M.Tech, Ph.D., Professor\n");
	gotoxy(60,16);
	printf("\tId : 2106, Dr. D.Basavaraj ,  M.Tech, Ph.D , Professor\n");
	gotoxy(60,18);
	printf("\tId : 2107, Dr. M. Shanmukhi ,  M.Tech, Ph.D , Professor\n");
	gotoxy(60,20);
	printf("\tId : -, Dr. Badrinath G. Srinivas ,  M.E., Ph.D , Adj. Prof.\n");
	gotoxy(60,22);
	printf("\tId : 2105, Dr. K. Srinivas ,  M.E, Ph.D , Associate Professor\n");
	gotoxy(60,24);
	printf("\tId : 1487, Ms. M. Sunitha Reddy,  M.Tech., Assistant Professor\n");
	gotoxy(60,26);
	printf("\tId : 1587, Mr. S. Vinay Kumar,  M.Tech., Assistant Professor\n");
	gotoxy(60,28);
	printf("\tId : 1728, Dr. V.Sireesha,  M.Tech., Ph.D., Assistant Professor\n");
	gotoxy(60,30);
	printf("\tId : 1831, Mr.C.Gireesh,  M.Tech., Assistant Professor\n");
	gotoxy(60,32);
	printf("\tId : 1640, Ms. B. Syamala,  M.Tech., Assistant Professor\n");
	gotoxy(60,34);
	printf("\tId : 1654, Mr. P. Narsaiah,  M.Tech., Assistant Professor\n");
	gotoxy(60,36);
	printf("\tId : 1937, Smt. T.Jalaja,  M.Tech., Assistant professor\n");
	getch();
	system("cls");
	system("color 6");
	box(60,5,130,35);
    gotoxy(60,9);
	printf("\t\t\t CONTACT DETAILS  \n");
	gotoxy(60,12);
	printf("\t  Dr. T. Adilakshmi");
	gotoxy(60,14);
	printf("\t  HOD\t 040 - 23146020");
	gotoxy(60,16);
	printf("\t  hodcse@staff.vce.ac.in\n");
}
void Notepad(char *MyFile,char *password)
{
    	int ch;
    	while(1)
    	{
			system("cls");
			box(60,5,130,40);
			gotoxy(60,9);
			system("color 6");
			printf("\t\t\t  *** PERSONAL DIARY ***\n");
			gotoxy(60,12);
        	printf("\tMAIN MENU:");
			gotoxy(60,14);
        	printf("\t  1.Add Record\t");
			gotoxy(60,16);
        	printf("\t  2.View Record\t");
			gotoxy(60,18);
        	printf("\t  3.Edit Record\t");
			gotoxy(60,20);
        	printf("\t  4.Delete Record\t");
			gotoxy(60,22);
        	printf("\t  5.Exit\t\t");
			gotoxy(60,24);
        	printf("\t  ENTER YOUR CHOICE : ");
        	scanf("%d",&ch);
        	switch(ch)
        	{
        	case 1 : addrecord(MyFile);
            		 break;
        	case 2 : viewrecord(MyFile);
            		 break;
        	case 3 : editrecord(MyFile);
            		 break;
        	case 4 : deleterecord(MyFile);
            		 break;
        	case 5 : Settings_S(MyFile,password); return;
        	default: {
					 gotoxy(60,26);
			         printf("\t YOU ENTERED WRONG CHOICE..\n");
            		 printf("\t\tEnter any key..");
					 getch();
					 Notepad(MyFile,password);
					}
					 break;
        	}
        	system("cls");
    	}
}
void addrecord(char *MyFile)
{
    	system("cls");
		box(60,5,130,40);
		gotoxy(60,9);
    	FILE *fp;
		fp=fopen(MyFile,"rb");
    	char another = 'Y' ,time[10];
    	struct record e ;
    	int choice;
		printf("\t\t\t *** WELCOME TO THE ADD MENU ***");
		gotoxy(60,12);
    	printf("\tEnter date of your record:[yyyy-mm-dd]:");
    	fflush(stdin);
    	gets(MyFile);
    	fp = fopen (MyFile, "ab+" ) ;
    	if ( fp == NULL )
    	{
       		fp=fopen(MyFile,"wb+");
        	if(fp==NULL)
        	{
				    gotoxy(60,14);
            		printf("\t SYSTEM ERROR...\n");	
					gotoxy(60,16);
			        printf("\t\tEnter any key..");
					getch();
            		return ;
        	}
    	}
    	while ( another == 'Y'|| another=='y' )
    	{
        	choice=0;
        	fflush(stdin);
			system("cls");
			box(60,5,130,40);
			gotoxy(60,10);
        	printf ( "\t ENTER TIME:[hh:mm]:");
        	scanf("%s",time);
        	rewind(fp);
        	while(fread(&e,sizeof(e),1,fp)==1)
        	{
            		if(strcmp(e.time,time)==0)
            		{
						gotoxy(60,12);
                		printf("\t  THE RECORD ALREADY EXISTS.\n");
                		choice=1;
            		}
        	}
        	if(choice==0)	
			{
      	     	strcpy(e.time,time);
				system("cls");
				box(60,5,130,40);
				gotoxy(60,10);
				printf ( "\t ENTER TIME:[hh:mm]: %s",time);
				gotoxy(60,14);
            	printf("\t Enter Name : ");
            	fflush(stdin);
            	gets(e.name);
            	fflush(stdin);
				gotoxy(60,16);
            	printf("\t Enter Place : ");
            	gets(e.place);
            	fflush(stdin);
				gotoxy(60,18);
            	printf("\t Note : ");
            	gets(e.note);
            	fwrite ( &e, sizeof ( e ), 1, fp ) ;
				gotoxy(60,20);
            	printf("\t  YOUR RECORD IS ADDED...\n");
        	}
			gotoxy(60,23);
        	printf ("\t  ADD ANOTHER RECORD...(Y/N) " ) ;
        	fflush ( stdin ) ;
        	another = getchar( ) ;
    	}
    	fclose ( fp ) ;
		gotoxy(60,25);
    	printf("\tEnter any key..");
		getch();
}
void viewrecord(char *MyFile)
{
    	FILE *fp ;
    	system("cls");
		box(60,5,130,40);
		gotoxy(60,10);
    	struct record customer ;
    	char time[6];
    	int choice,ch;
    	printf("\t\t *** HERE IS THE VIEWING MENU ***");
    	do
    	{
			gotoxy(60,12);
        	printf("\tEnter date of the record to be viewed:[yyyy-mm-dd]:");
        	fflush(stdin);
        	gets(MyFile);
        	fp = fopen ( MyFile, "rb" ) ;
        	if ( fp == NULL )
        	{
				    gotoxy(60,14);
            		puts ( "\tTHE RECORD DOES NOT EXIST...\n" ) ;
					gotoxy(60,16);
            		printf("\tEnter any key..");
					 getch();
            		return ;
        	}
        	system("cls");
			box(60,5,130,40);
			gotoxy(60,10);
        	printf("\t HOW WOULD YOU LIKE TO VIEW:\n");
			gotoxy(60,12);
        	printf("\t  1.Whole record of the day");
			gotoxy(60,14);
        	printf("\t  2.Record of fixed time");
			gotoxy(60,16);
        	printf("\t\t  ENTER YOUR CHOICE : ");
        	scanf("%d",&ch);
        	switch(ch)
        	{	
        	case 1 :system("cls");
					box(60,5,130,40);
					gotoxy(60,10);
					system("color 6");
         			printf("\t  THE WHOLE RECORD FOR %s IS : ",MyFile);
            		while ( fread ( &customer, sizeof ( customer ), 1, fp ) == 1 )
            		{
                		printf("\n\n\n\t\t\t\t\t\t\t\t  TIME: %s",customer.time);
                		printf("\n\t\t\t\t\t\t\t\t  MEETING WITH: %s",customer.name);
                		printf("\n\t\t\t\t\t\t\t\t  MEETING AT: %s",customer.place);
               	 		printf("\n\t\t\t\t\t\t\t\t  NOTE: %s",customer.note);
            		}
					getch();
            		break;
        	case 2 : system("cls");
					 box(60,5,130,40);
					 gotoxy(60,10);
					 system("color 6");
				     fflush(stdin);
            		 printf("\t Enter time:[hh:mm]:");
              		 gets(time);
            		 while ( fread ( &customer, sizeof ( customer ), 1, fp ) == 1 )
            		{
                		if(strcmp(customer.time,time)==0)
                		{
							gotoxy(60,12);
                    		printf("\t  YOUR RECORD IS:");
							gotoxy(60,14);
                    		printf("\t  TIME: %s",customer.time);
							gotoxy(60,16);
                    		printf("\t  MEETING WITH: %s",customer.name);
							gotoxy(60,18);
                    		printf("\t  MEETING AT: %s",customer.place);
							gotoxy(60,20);
                    		printf("\t  NOTE: %s",customer.note);
                			}
						else
						{
							gotoxy(60,12);
							printf("\t No record found");
						}
            			 }
				    gotoxy(60,22);
					printf("\tEnter any key..");
					getch();
              		break;
        	default : gotoxy(60,18);
					  printf("\t  YOU TYPED SOMETHING ELSE...\n"); break;
        	}
			gotoxy(60,30);
        	printf("\t  WOULD YOU LIKE TO CONTINUE VIEWING...(Y/N):");
        	fflush(stdin);
        	scanf("%c",&choice);
    	}
    	while(choice=='Y'||choice=='y');
    	fclose ( fp ) ;
    	return ;
}
void editrecord(char *MyFile)
{
    system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
    FILE *fpte ;
    struct record customer ;
    char time[6],choice;
    int num,count=0;
    printf("\t\t**** WELCOME TO THE EDITING MENU ****");
    do
    {   system("cls");
	    box(60,5,130,40);
		gotoxy(60,10);
		printf("\t\t**** WELCOME TO THE EDITING MENU ****");
		gotoxy(60,12);
        printf("\t  Enter the date of record to be edited:[yyyy-mm-dd]:");
        fflush(stdin);
        gets(MyFile);
		system("cls");
		box(60,5,130,40);
		gotoxy(60,10);
        printf("\t  Enter time:[hh:mm]:");
        gets(time);
        fpte = fopen ( MyFile, "rb+" ) ;
        if ( fpte == NULL )
        {
		    gotoxy(60,12);
            printf( "\t  RECORD DOES NOT EXISTS:" ) ;
			gotoxy(60,14);
            printf("\tEnter any key..");
			getch();
            		return;
        	}
        	while ( fread ( &customer, sizeof ( customer ), 1, fpte ) == 1 )
        	{
            	if(strcmp(customer.time,time)==0)
            	{
					gotoxy(60,12);
                	printf("\t  YOUR OLD RECORD WAS AS:");
					gotoxy(60,14);
                	printf("\t  TIME: %s",customer.time);
					gotoxy(60,16);
                	printf("\t  MEETING WITH: %s",customer.name);
					gotoxy(60,18);
                	printf("\t  MEETING AT: %s",customer.place);
					gotoxy(60,20);
                	printf("\t  NOTE: %s",customer.note);
					gotoxy(60,22);
                	printf("\t\tWHAT WOULD YOU LIKE TO EDIT..\n");
					gotoxy(60,24);
                	printf("\t  1.Time");
					gotoxy(60,26);
                	printf("\t  2.Meeting person");
					gotoxy(60,28);
                	printf("\t  3.Meeting place");
					gotoxy(60,30);
                	printf("\t  4.Note");
					gotoxy(60,32);
                	printf("\t  5.Whole record");
					gotoxy(60,34);
                	printf("\t  6.back to menu");
                	do
                	{
						gotoxy(60,36);
                    	printf("\t  ENTER YOUR CHOICE : ");
                    	fflush(stdin);
                    	scanf("%d",&num);
                    	fflush(stdin);
						switch(num)
                   		{
                    		       case 1:system("cls");
										box(60,5,130,40);
										gotoxy(60,10);
										printf("\t  NEW DATA");
										gotoxy(60,12);
										printf("\t  New time:[hh:mm] : ");
										gets(customer.time);
										gotoxy(60,14);
										printf("\tEnter any key..");
										getch();
                       	 				break;
                    				case 2:system("cls");
										box(60,5,130,40);
										gotoxy(60,10);
										printf("\t  NEW DATA");
										gotoxy(60,12);
                        				printf("\t  New meeting person : ");
                        				gets(customer.name);
										gotoxy(60,14);
										printf("\tEnter any key..");
										getch();
                       		 			break;
                    				case 3: system("cls");
										box(60,5,130,40);
										gotoxy(60,10);
										printf("\t  NEW DATA");
										gotoxy(60,12);
                        				printf("\t  New meeting place : ");
                        				gets(customer.place);
										gotoxy(60,14);
										printf("\tEnter any key..");
										getch();
                        				break;
                    				case 4: system("cls");
										box(60,5,130,40);
										gotoxy(60,10);
										printf("\t  NEW DATA");
										gotoxy(60,12);
                        				printf("\t  Note:");
                        				gets(customer.note);
										gotoxy(60,14);
										printf("\tEnter any key..");
										getch();
                       					break;
                    				case 5: system("cls");
										box(60,5,130,40);
										gotoxy(60,10);
										printf("\t  NEW DATA");
										gotoxy(60,12);
                        				printf("\t  New time:[hh:mm] : ");
                        				gets(customer.time);
										gotoxy(60,14);
                        				printf("\t  New person meeting : ");
                        				gets(customer.name);
										gotoxy(60,16);
                        				printf("\t  New meeting place : ");
                        				gets(customer.place);
										gotoxy(60,18);
                        				printf("\t  Note : ");
                        				gets(customer.note);
										gotoxy(60,20);
										printf("\tEnter any key..");
										getch();
                        				break;
                    				case 6: gotoxy(60,38);
											printf("\tEnter any key..");
											getch();
											return ; 
                    				default:gotoxy(60,38);
											printf("\t YOU TYPED SOMETHING ELSE...TRY AGAIN\n");
											break;
                    			}
                		}
                		while(num<1||num>8);
                		fseek(fpte,sizeof(customer),SEEK_CUR);
                		fwrite(&customer,sizeof(customer),1,fpte);
                		fseek(fpte,sizeof(customer),SEEK_CUR);
                		fread(&customer,sizeof(customer),1,fpte);
                		choice=4;
                		break;
            		}
        	}
        	if(choice==4)
        	{
					system("cls");
					box(60,5,130,40);
					gotoxy(60,10);
            		printf("\t\t EDITING COMPLETED...\n");
					gotoxy(60,12);
            		printf("\t THE NEW RECORD IS:\n");
					gotoxy(60,14);
            		printf("\t TIME: %s",customer.time);
					gotoxy(60,16);
            		printf("\t MEETING WITH: %s",customer.name);
					gotoxy(60,18);
            		printf("\t MEETING AT: %s",customer.place);
					gotoxy(60,20);
            		printf("\t NOTE: %s",customer.note);
            		fclose(fpte);
					gotoxy(60,22);
            		printf("\t WOULD YOU LIKE TO EDIT ANOTHER RECORD.(Y/N)");
            		scanf("%c",&choice);
            		count++;
        	}
        	else
        	{
				    gotoxy(60,12);
            		printf("\t THE RECORD DOES NOT EXIST\n");
					gotoxy(60,14);
            		printf("\t WOULD YOU LIKE TO TRY AGAIN...(Y/N)");
            		scanf("%c",&choice);
        	}
    	}
    	while(choice=='Y'||choice=='y');
    	fclose ( fpte ) ;
	   getch();
}
void deleterecord(char *MyFile)
{
    	system("cls");
		box(60,5,130,40);
		gotoxy(60,9);
    	FILE *fp,*fptr ;
    	struct record file ;
    	char another = 'Y' ,time[10];
    	int choice;
    	printf("\t\t *** WELCOME TO DELETE MENU ***");
    	while ( another == 'Y' )
    	{
			gotoxy(60,12);
        	printf("\t  HOW WOULD YOU LIKE TO DELETE.");
			gotoxy(60,14);
        	printf("\t  1.Delete Whole record");
			gotoxy(60,16);
        	printf("\t  2.Delete a particular record by time");
        	do
        	{
				    gotoxy(60,18);
            		printf("\t ENTER YOU CHOICE : ");
            		scanf("%d",&choice);
            		switch(choice)
            		{
           	 		case 1: gotoxy(60,20);
					        printf("\tEnter the date of record to be deleted:[yyyy-mm-dd]:");
                			fflush(stdin);
                			gets(MyFile);
                			fp = fopen (MyFile, "wb" ) ;
                			if ( fp == NULL )
                			{
								gotoxy(60,22);
                    			printf("\tTHE FILE DOES NOT EXISTS\n");
								gotoxy(60,24);
                   				printf("\tEnter any key..");
								getch();
                    			return ;
                			}
                			fclose(fp);
                			remove(MyFile);
							gotoxy(60,22);
                			printf("\t  DELETED SUCCESFULLY...\n");
                			break;
            		case 2: gotoxy(60,20);
						    printf("\t  Enter the date of record:[yyyy-mm-dd]:");
                			fflush(stdin);
                			gets(MyFile);
                			fp = fopen (MyFile, "rb" ) ;
                			if ( fp == NULL )
                			{
								gotoxy(60,22);
                    			printf("\t THE FILE DOES NOT EXISTS\n");
								gotoxy(60,24);
                    			printf("\tEnter any key..");
								getch();
                    			return ;
                			}
                			fptr=fopen("temp","wb");
                			if(fptr==NULL)
                			{     
						        gotoxy(60,22);
                    			printf("\t SYSTEM ERROR\n");
								gotoxy(60,24);
                    			printf("\tEnter any key..");
								getch();
                    			return ;
                			}
							gotoxy(60,24);
                			printf("\t Enter the  time of record to be deleted:[hh:mm]:");
                			fflush(stdin);
                			gets(time);
                			while(fread(&file,sizeof(file),1,fp)==1)
                			{
                    			if(strcmp(file.time,time)!=0)
                        		fwrite(&file,sizeof(file),1,fptr);
                			}
                			fclose(fp);
                			fclose(fptr);
                			remove(MyFile);
                			rename("temp",MyFile);
							gotoxy(60,28);
                			printf("\tDELETED SUCCESFULLY...\n");
                			break;
            		default:gotoxy(60,20);
          					printf("\t  YOU ENTERED WRONG CHOICE\n");
							system("cls");
							deleterecord(MyFile);
                			 break;
            		}
        	}while(choice<1||choice>2);
			gotoxy(60,30);
        	printf("\tDO YOU LIKE TO DELETE ANOTHER RECORD.(Y/N):");
        	fflush(stdin);
        	scanf("%c",&another);
    	}
    	getch();
}
void Attendance_S(char *MyFile)
{
	system("cls");
	FILE *fp12;
	fp12=fopen(MyFile,"rb");
	struct student t;
	fread(&t,sizeof(t),1,fp12);
	SetColor(14);
	box(60,3,130,44);
	gotoxy(60,5);
	printf("\t\t\t MY ATTENDANCE\n");
	float present = 0;
  	float absent = 0;
  	int y = 25;
  	float mark_att1, mark_att2;
  	float count = 0;
  	float count1 = 0;
  	float count2;
  	char p[20] = {
    	"p"
  	};
  	char a[20] = {
    	"a"
  	};
  	FILE * ssatt;
  	ssatt = fopen("Attendance.dll", "r");
  	char id[30];
  	char dtls[2];
  	int i = 0, found = 0;
  	fflush(stdin);
  	strcpy(id,t.rno);
  	while (fread( &s_att, sizeof(s_att), 1, ssatt)) 
	{
    	if (strcmp(id, s_att.sid) == 0) 
		{
      		if (strcmp(p, s_att.ati) == 0) 
			{
        		present = present + 1;
      		} 
			else 
			{
        		absent = absent + 1;
      		}
      		count = count + 1;
      		found = 1;
    	}
  	}
  	if (found == 0) 
	{
    	SetColor(4);
    	printf("\n\n\t\t\t\t\t\t\t\t DATA NOT FOUND\n");
    	SetColor(45);
  	} 
	else
  	{
    	char idfc[20];
    	FILE * stdptr1;
		struct student std;
    	stdptr1 = fopen(registerFile1, "rb");
    	while (fread(&std, sizeof(std), 1, stdptr1)) 
		{
      		strcpy(idfc, std.rno);
      		break;
    	}
    	fclose(stdptr1);
    	FILE * stdptr2;
    	stdptr2 = fopen("Attendance.dll", "r");
    	while (fread(&s_att, sizeof(s_att), 1, stdptr2)) 
		{
      		if (strcmp(idfc, s_att.sid) == 0) 
			{
        		count1 = count1 + 1;
      		}
    	}
    	fclose(stdptr2);
    	FILE * stdptr;
    	stdptr = fopen(registerFile1, "rb");
    	while (fread( &std, sizeof(std), 1, stdptr)) 
		{
      		if (strcmp(id, std.rno) == 0) 
			{
        		SetColor(6);
        		printf("\n\t\t\t\t\t\t\t\tName:%s", std.name);
        		printf("\n\t\t\t\t\t\t\t\tID: %s", std.rno);
        		printf("\n\t\t\t\t\t\t\t\tDepartment: %s", std.branch);
        		printf("\n\t\t\t\t\t\t\t\tSection: %s", std.section);
        		printf("\n\n\t\t\t\t\t\t\t\tTotal Class: %0.0f", count1);
        		printf("\n\t\t\t\t\t\t\t\tPresent: %0.0f Days", present);
        		printf("\n\t\t\t\t\t\t\t\tAbsent: %0.0f Days\n\n", absent);
      		}
    	}
    	if (count1 > count) 
		{
      		count2 = count1 - count;
      		SetColor(4);
      		printf("\n\t\t\t\t\t\t\t\t[Registered after %0.0f Class]\n", count2);
      		SetColor(14);
    	}
    		mark_att1 = (present * 5) / count1;
    		mark_att2 = (present * 7) / count1;
    		printf("\n\t\t\t\t\t\t\t\t Attendance Mark: %0.2f  [Out of 5.0]\n", mark_att1);
    		printf("\n\t\t\t\t\t\t\t\t Attendance Mark: %0.2f  [Out of 7.0]\n\n", mark_att2);
    		printf("\n\t\t\t\t\t\t\t\t Do you want to view attendance details[y/n] : ");
    		scanf("%s", dtls);
			printf("\n");
   		if (strcmp(dtls,"y")==0) 
		{
      		FILE * temp2;
      		temp2 = fopen("Attendance.dll", "r");
      		while (fread( & s_att, sizeof(s_att), 1, temp2)) 
			{
        		if (strcmp(id, s_att.sid) == 0) 
				{
          			if (strcmp(p, s_att.ati) == 0) 
					{
            			SetColor(11);
            			printf("\n\t\t\t\t\t\t\t\t%s: Present", s_att.date);
          			} 
					else if (strcmp(a, s_att.ati) == 0) 
					{
            			SetColor(4);
            			printf("\n\t\t\t\t\t\t\t\t%s: Absent", s_att.date);
            			SetColor(11);
          			}
                    y++;
        		}
      		}
      		fclose(temp2);
    	}
    	fclose(ssatt);
  	}
  	SetColor(13);
  	char end;
  	printf("\n\n\t\t\t\t\t\t\t\t Press 1 To Search Again");
  	printf("\n\n\t\t\t\t\t\t\t\t Press 2 for go Back");
  	printf("\n\n\t\t\t\t\t\t\t\t  Select an Option : ");
	SetColor(12);
  	end = getche();
  	switch (end) 
	{
  		case '1': Attendance_S(MyFile);  break;
  		case '2': Homepage_S(MyFile,t.password); break;
  		default : printf("\n\t\t\t\t\t\t\t\t INVALID KEYWORD-TRY AGAIN\n");
					Home(); 
					exit(0);
  	}
	fclose(fp12);
}
void Settings_S(char *MyFile, char *password)
{
	    system("cls");
	    int c;
      	while(c!=8)
	    {
	       system("cls");
		   box(60,5,130,40);
	       gotoxy(60,9);
	       printf("\t\t\t **** SETTINGS MENU ****\n");
		   gotoxy(60,12);
	       printf("\t 1.MyDetails\n");
		   gotoxy(60,14);
	       printf("\t 2.Modify Details\n");
		   gotoxy(60,16);
	       printf("\t 3.Search\n");
		   gotoxy(60,18);
	       printf("\t 4.FileName\n");
		   gotoxy(60,20);
	       printf("\t 5.Menu Page\n\n");
		   gotoxy(60,22);
	       printf("\t\t  Enter you choice :");
	       scanf("%d",&c);
	       switch(c)
	       {
				case 1 : MyDetails(MyFile); break;
	       		case 2 : ModifyDetails(MyFile); break;	
		    	case 3 : Search(MyFile); break;
				case 4 : FileName(MyFile); break;
				case 5 : Homepage_S(MyFile,password); exit(0); 
	        	default : gotoxy(60,24);
				          printf("\t  Invalid Input\n");
	       }
			getch();
	}
}	
void MyDetails(char *MyFile)
{
	system("cls");
	box(60,5,130,46);
	gotoxy(60,7);
	FILE *fp;
	struct student s1;
	fp=fopen(MyFile,"rb");	
    printf("\t\t\t\t *** MY DETAILS ***\n");
	fread(&s1,sizeof(s1),1,fp);
	gotoxy(60,10);
	printf("\tID : %s",s1.rno);
	gotoxy(60,12);
    printf("\tName : %s",s1.name);
	gotoxy(60,14);
    printf("\tBranch : %s",s1.branch);
	gotoxy(60,16);
	printf("\tSection : %s",s1.section);
	gotoxy(60,18);
	printf("\tSemester : %s",s1.semster);
	gotoxy(60,20);
	printf("\tContact number : %s",s1.phone);
	gotoxy(60,22);
    printf("\tEmail-ID : %s",s1.mailId);
	gotoxy(60,24);
	printf("\tHouse Number : %s",s1.houseNumber);
	gotoxy(60,26);
	printf("\tHouse address : %s",s1.houseAddress);
	gotoxy(60,28);
	printf("\tSate : %s",s1.state);
	gotoxy(60,30);
	printf("\tCountry : %s",s1.country);
	gotoxy(60,32);
	printf("\tCategory : %s",s1.category);
	gotoxy(60,34);
	printf("\tAdmission Category : %s",s1.admnCategory);
	gotoxy(60,36);
	printf("\tMentorName : %s",s1.mentorName);	
    gotoxy(60,38);	
	printf("\tIdentification Marks : %s",s1.identificationMarks);
	gotoxy(60,40);
	printf("\tFavourite color : %s",s1.color);
	gotoxy(60,42);
	printf("\tFirst school name : %s",s1.schoolName);
	fclose(fp);	
}
void ModifyDetails(char *MyFile)
{
	int n;
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct student t;
	fread(&t,sizeof(t),1,fp);
	while(n!=7)
	{
		system("cls");
		box(60,5,130,40);
	    gotoxy(60,9);
		printf("\t\t\t\t*** MODIFY DETAILS ***\n");
		gotoxy(60,12);
		printf("\t\t\t  What would you like to MODIFY");
		gotoxy(60,14);
		printf("\t  1.Name ");
		gotoxy(60,16);
		printf("\t  2.Branch ");
		gotoxy(60,18);
		printf("\t  3.Password ");
		gotoxy(60,20);
        printf("\t  4.Contact number ");
		gotoxy(60,22);
        printf("\t  5.Email-ID ");
		gotoxy(60,24);
        printf("\t  6.Security questions");
		gotoxy(60,26);
        printf("\t  7.Settings");
		gotoxy(60,28);
		printf("\t\t  Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : namechange(MyFile); break;
			case 2 : branchchange(MyFile); break;
			case 3 : passwordchange(MyFile); break;
			case 4 : phonechange(MyFile); break;
			case 5 : emailchange(MyFile); break;
			case 6 : securityquestionschange(MyFile); break;
			case 7 : Settings_S(MyFile,t.password); exit(0);
			default : gotoxy(60,30);
			          printf("\tInvalid Input\n");
		}
		getch();
  	}
	fclose(fp);	
}
void namechange(char *fName)
{
	FILE *fp,*fp1;
	struct student t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	printf("\t Verify your Roll Number :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.rno,rno)==0)
	{
		found=1;
		gotoxy(60,12);
		printf("\t Enter your Name to update : ");
		scanf("%[^\n]s",t.name);
		fgets(t.name,sizeof(t.name),stdin);
        scanf("%[^\n]s",t.name);
		fflush(stdin);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,14);
		printf("\t Successfully updated\n\n");
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		gotoxy(60,13);
		printf("\t Sorry No Record Found\n\n");
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
	   		{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
	    	}
	}
	fclose(fp);
	fclose(fp1);
	gotoxy(60,16);
	printf("\t\tEnter any key..");
	getch();
}
void branchchange(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	struct student t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
    printf("\t Verify your Roll Number :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.rno,rno)==0)
	{
		found=1;
		gotoxy(60,12);
		printf("\t Enter your branch to update ::");
		scanf("%s",t.branch);
		fflush(stdin);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,14);
		printf("\t Successfully updated\n\n");
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	gotoxy(60,16);
	printf("\t\tEnter any key..");
	getch();
}
void phonechange(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	struct student t;
	int found=0,count;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your Roll Number :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.rno,rno)==0)
	{
		jump1:
		{
			found=1;
			system("cls");
			box(60,5,130,40);
	        gotoxy(60,10);
			printf("\t Verify your Roll Number :: %s",rno);
			gotoxy(60,12);
			printf("\t Enter Student contact number to update : ");
			scanf("%s",t.phone);
			fflush(stdin);
			fwrite(&t,sizeof(t),1,fp1);
		}
		count=strlen(t.phone);
		for(int i=0;i<count;i++)
		{
			if(!isDigit(t.phone[i]))
			{
				gotoxy(60,14);
				printf("\t Sorry,the contact number is invalid!");
				gotoxy(60,16);
        		printf("\t Contact number consists only numbers\n");
				gotoxy(60,18);
				printf("\t\tEnter any key..");
	            getch();
        		goto jump1;
				break;
			}
		}
		if(count!=10)
		{
			gotoxy(60,14);
        	printf("\t Sorry,the contact number is invalid!");
			gotoxy(60,16);
       		printf("\t Contact number consists of 10 digits\n");
			gotoxy(60,18);
			printf("\t\tEnter any key..");
			getch();
        	goto jump1;
		}
		else
		{
			gotoxy(60,20);
			printf("\t Successfully updated");
		}
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	gotoxy(60,22);
	printf("\t\tEnter any key..");
	getch();
}
void emailchange(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	struct student t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
    printf("\t Verify your Roll Number :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.rno,rno)==0)
	{
		found=1;
		jump1:
		{
			system("cls");
			box(60,5,130,40);
			gotoxy(60,10);
			printf("\t Verify your Roll Number :: %s",rno);
			gotoxy(60,12);
			printf("\t Enter your email id to update :: ");
			scanf("%s",t.mailId);
		}
		if(isValid(t.mailId)==1 || isValid2(t.mailId)==1)
		{
			fflush(stdin);
			fwrite(&t,sizeof(t),1,fp1);
			gotoxy(60,14);
			printf("\t Successfully updated");
		}
		else
		{
			gotoxy(60,14);
			printf("\t Invalid mailID-Try Again");
			gotoxy(60,16);
			printf("\t\tEnter any key..");
	        getch();
			goto jump1;
		}
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	gotoxy(60,18);
	printf("\t\tEnter any key..");
	getch();
}
void passwordchange(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	struct student t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your Roll Number :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.rno,rno)==0)
	{
		found=1;
		jump3:
        {
		system("cls");
		box(60,5,130,40);
	    gotoxy(60,10);
		printf("\t Verify your Roll Number :: %s",rno);
		gotoxy(60,12);
        printf("\t NOTE : Password consists of 8 characters\n");
		gotoxy(60,14);
		printf("\t Enter your password to update :: ");
		int i=0;
		char ch;
        while(1)
		{
			ch = getch();
			if(ch==ENTER)
			 {
				t.password[i]='\0';
			    break;
			 }
			 else if(ch==BACKSPACE)
			 {
				if(i>0)
				{
					i--;
					printf("\b \b");
				}
			 }
			else if(ch==TAB || ch==SPACE)
			{
				continue;
			}
			else 
			{
				t.password[i]=ch;
				i++;
				printf("*");
		 }
	  }	
	}
	if(strlen(t.password)!=8)
    {
		gotoxy(60,16);
        printf("\t Sorry,Invalid password\n");
		gotoxy(60,18);
		printf("\t\tEnter any key..");
		getch();
        goto jump3;
    }
	else
	{
		gotoxy(60,16);
        printf("\t Successfully updated\n");
	}
		fflush(stdin);
		strcpy(t.confirmPassword ,t.password);
		fwrite(&t,sizeof(t),1,fp1);
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	gotoxy(60,18);
	printf("\t\tEnter any key..");
	getch();
}
void securityquestionschange(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	struct student t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your Roll Number :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.rno,rno)==0)
	{
		found=1;
		system("cls");
		box(60,5,130,40);
	    gotoxy(60,10);
		printf("\t Verify your Roll Number :: %s",rno);
		gotoxy(60,14);
		printf("\t Enter your first school name to update :: ");
		scanf("%s",t.schoolName);
		fflush(stdin);
		gotoxy(60,16);
		printf("\t Enter your favourite colour to update :: ");	
		scanf("%s",t.color);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,18);
		printf("\t Successfully updated\n");
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	gotoxy(60,20);
	printf("\t\tEnter any key..");
	getch();
}
void Search(char *MyFile)
{
	int n;
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct student t;
	fread(&t,sizeof(t),1,fp);
	while(n!=7)
	{
		system("cls");
	    box(60,5,130,40);
	    gotoxy(60,9);
		printf("\t\t\t\t ***SEARCH***\n");
		gotoxy(60,12);
		printf("\t\t\tWhat would you like to SEARCH");
		gotoxy(60,14);
    	printf("\t 1.Name");
		gotoxy(60,16);
    	printf("\t 2.Branch ");
		gotoxy(60,18);
    	printf("\t 3.Password ");
		gotoxy(60,20);
    	printf("\t 4.Contact number ");
		gotoxy(60,22);
    	printf("\t 5.Email-ID ");
		gotoxy(60,24);
    	printf("\t 6.Security Questions ");
		gotoxy(60,26);
		printf("\t 7.Homepage\n");
		gotoxy(60,28);
		printf("\t\t Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : namesearch(MyFile);
			         break;
	    	case 2 : branchsearch(MyFile);
			         break;
			case 3 : passwordsearch(MyFile);
			         break;
			case 4 : contactsearch(MyFile);
			         break;
			case 5 : emailsearch(MyFile);
			         break;
			case 6 : securityquestionssearch(MyFile);
			         break;
			case 7 : Settings_S(MyFile,t.password); exit(0);
			default : gotoxy(60,30);
			         printf("\t Invalid Input\n");
		}
		getch();
	}
	fclose(fp);
}
void namesearch(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
    FILE *fp;
    struct student t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t Verify your Roll Number : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
     	return;
    }
    if(strcmp(id,t.rno)==0)
    {
    	   found=1;
		   gotoxy(60,13);
     	   printf("\t\t NAME :: %s\n",t.name);
		   gotoxy(60,15);
     }
    	if(found==0)
    	{
			gotoxy(60,12);
    	    printf("\t Sorry, no record found\n");
    	}
    	fclose(fp);
		gotoxy(60,17);
    	printf("\t\tEnter any key..");
		getch();
}
void branchsearch(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
    struct student t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t Verify your Roll Number : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
		return;
    }
    if(strcmp(id,t.rno)==0)
    {
    	found=1;
		gotoxy(60,13);
    	printf("\t\t BRANCH :: %s\n",t.branch);
    }
    if(found==0)
    {
		gotoxy(60,12);
        printf("\t Sorry, no record found\n");
    }
   	fclose(fp);
	gotoxy(60,15);
	printf("\t\tEnter any key..");
	getch();
}
void passwordsearch(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
	struct student t;
	int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your Roll Number : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
        return;
    }
    if(strcmp(id,t.rno)==0)
    {
        found=1;
	    gotoxy(60,13);
        printf("\t\t  PASSWORD :: %s\n",t.password);   
    }
    if(found==0)
    {
		gotoxy(60,12);
        printf("\t Sorry, no record found\n");
    }
   	fclose(fp);
	gotoxy(60,15);
	printf("\t\tEnter any key..");
	getch();
}
void emailsearch(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
	struct student t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your Roll Number : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
        return;
    }
   if(strcmp(id,t.rno)==0)
    {
       found=1;
	   gotoxy(60,13);
       printf("\t\t EMAIL-ID : %s\n",t.mailId);
    }
    if(found==0)
    {
		gotoxy(60,12);
    	printf("\n\t Sorry, no record found\n");
    }
    fclose(fp);
	gotoxy(60,15);
	printf("\t\tEnter any key..");
	getch();
}
void contactsearch(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
    struct student t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your Roll Number : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
        return;
    }
    if(strcmp(id,t.rno)==0)
    {
        found=1;  
		gotoxy(60,13);			
        printf("\t\t  CONTACT NUMBER :: %s\n",t.phone);    
    }
    if(found==0)
    {
		gotoxy(60,12);
    	printf("\t Sorry, no record found\n");
    }
    fclose(fp);
	gotoxy(60,15);
	printf("\t\tEnter any key..");
	getch();
}
void securityquestionssearch(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
    struct student t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your Roll Number : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
        return;
    }
    if(strcmp(id,t.rno)==0)
    {
        found=1;
		gotoxy(60,12);
		printf("\t\t IDENTIFICATION MARKS :: %s\n",t.identificationMarks);
		gotoxy(60,14);
        printf("\t\t FIRST SCHOOL NAME :: %s\n",t.schoolName);
		gotoxy(60,16);
        printf("\t\t FAVOURITE COLOUR :: %s\n",t.color);
    }
    if(found==0)
    {
		gotoxy(60,13);
    	printf("\t Sorry, no record found\n");
    }
    fclose(fp);
	gotoxy(60,18);
	printf("\t\tEnter any key..");
	getch();
}
void FileName(char *MyFile)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	printf("\t\t  Existing file name : %s\n",MyFile);
	gotoxy(60,13);
	printf("\t\t  Enter any key..");
	getch();
}
void Settings_F(char *MyFile, char *password)
{
	int c;
      	while(c!=8)
	{
	    system("cls");
		box(60,5,130,40);
	    gotoxy(60,9);
	    SetColor(24);
	    printf("\t\t\t**** SETTINGS MENU ****\n");
		gotoxy(60,12);
	    printf("\t  1.MyDetails\n");
		gotoxy(60,14);
	    printf("\t  2.Modify Details\n");
		gotoxy(60,16);
	    printf("\t  3.Delete\n");
		gotoxy(60,18);
	    printf("\t  4.Search\n");
		gotoxy(60,20);
	    printf("\t  5.Menu Page\n\n");
		gotoxy(60,22);
	    printf("\t  Enter you choice :");
	    scanf("%d",&c);
	    switch(c)
	    {
			case 1 : MyDetails_F(MyFile); break;
	       	case 2 : ModifyDetails_F(MyFile); break;	
	       	case 3 : Delete_F(MyFile); break;
		    case 4 : Search_F(MyFile); break;
		    case 5 : Homepage_F(MyFile,password); exit(0); 
	        default : printf(" \tInvalid Input\n");
	    }
	    getch();
	}	
}
void MyDetails_F(char *MyFile)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,9);
	FILE *fp;
	struct faculty s1;
	fp=fopen(MyFile,"rb");
    SetColor(45);
    printf("\t\t  \t *** My DETAILS ***\n");
	fread(&s1,sizeof(s1),1,fp);
	gotoxy(60,12);
	printf("\t  ID : %s",s1.id);
	gotoxy(60,14);
    printf("\t  Name : %s",s1.name);
	gotoxy(60,16);
    printf("\t  Branch : %s",s1.department);
	gotoxy(60,16);
	printf("\t  Contact number : %s",s1.phone);
	gotoxy(60,18);
    printf("\t  Email-ID : %s",s1.mailId);
	gotoxy(60,20);
	printf("\t  Subjects : %s",s1.subject);
	gotoxy(60,22);
	printf("\t  Gender : %s",s1.gender);
	gotoxy(60,24);
	printf("\t  Qualifications : %s",s1.qualifications);
	gotoxy(60,26);
	printf("\t  Experience : %s",s1.experience);	
    gotoxy(60,28);	
	printf("\t  Identification Marks : %s",s1.identificationMarks);
	gotoxy(60,30);
	printf("\t  Favouite color : %s",s1.colour);
	gotoxy(60,32);
	printf("\t  First school name : %s",s1.school);
	fclose(fp);	
}
void ModifyDetails_F(char *MyFile)
{
	int n;
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct faculty t;
	fread(&t,sizeof(t),1,fp);
	while(n!=9)
	{
		system("cls");
		box(60,5,130,40);
	    gotoxy(60,9);
		printf("\t\t\t***MODIFY DETAILS***\n");
		gotoxy(60,12);
		printf("\t\t  What would you like to MODIFY");
		gotoxy(60,14);
		printf("\t 1.Name ");
		gotoxy(60,16);
		printf("\t 2.Branch ");
		gotoxy(60,18);
		printf("\t 3.Password ");
		gotoxy(60,20);
        printf("\t 4.Contact number ");
		gotoxy(60,22);
		printf("\t 5.Qualifications");
		gotoxy(60,24);
		printf("\t 6.Experience");
		gotoxy(60,26);
        printf("\t 7.Email-ID ");
		gotoxy(60,28);
        printf("\t 8.Security questions");
		gotoxy(60,30);
        printf("\t 9.Settings");
		gotoxy(60,32);
		printf("\t  Enter your choice:");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : namechange_F(MyFile); break;
			case 2 : branchchange_F(MyFile); break;
			case 3 : passwordchange_F(MyFile); break;
			case 4 : phonechange_F(MyFile); break;
			case 5 : qualifications_F(MyFile); break;
			case 6 : experience_F(MyFile); break;
			case 7 : emailchange_F(MyFile); break;
			case 8 : securityquestionschange_F(MyFile); break;
			case 9 : Settings_F(MyFile,t.password); exit(0);
			default : gotoxy(60,34);
            		  printf("\t Invalid Input\n");
		}
		getch();
  	}
	fclose(fp);	
}
void namechange_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
    gotoxy(60,9);
	FILE *fp,*fp1;
	SetColor(45);
	struct faculty t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		found=1;
		gotoxy(60,12);
		printf("\t Enter your Name to update : ");
		scanf("%[^\n]s",t.name);
		fgets(t.name,sizeof(t.name),stdin);
        scanf("%[^\n]s",t.name);
		fflush(stdin);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,14);
		printf("\t Successfully updated\n\n");
		gotoxy(60,16);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,12);
		printf("\t  Sorry No Record Found\n\n");
		gotoxy(60,14);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
	   		{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
	    	}
	}
	fclose(fp);
	fclose(fp1);
}
void branchchange_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
    gotoxy(60,9);
	FILE *fp,*fp1;
	SetColor(12);
	struct faculty t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
    printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		found=1;
		gotoxy(60,12);
		printf("\t Enter your branch to update ::");
		scanf("%s",t.department);
		fflush(stdin);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,14);
		printf("\t Successfully updated\n\n");
		gotoxy(60,16);
	printf("\t\tEnter any key..");
	getch();
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
		gotoxy(60,14);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);	
}
void phonechange_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,9);
	FILE *fp,*fp1;
	SetColor(12);
	struct faculty t;
	int found=0,count;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		jump1:
		{
			found=1;
			system("cls");
			box(60,5,130,40);
	        gotoxy(60,10);
			printf("\t Verify your ID :: %s",rno);
			gotoxy(60,12);
			printf("\t Enter your contact number to update : ");
			scanf("%s",t.phone);
			fflush(stdin);
			fwrite(&t,sizeof(t),1,fp1);
		}
		count=strlen(t.phone);
		for(int i=0;i<count;i++)
		{
			if(!isDigit(t.phone[i]))
			{
				gotoxy(60,14);
				printf("\t Sorry,the contact number is invalid!");
			    gotoxy(60,16);
        	    printf("\t Contact number consists only numbers\n");
				gotoxy(60,18);
				printf("\t\tEnter any key..");
	            getch();
        		goto jump1;
        		break;
			}
		}
		if(count!=10)
		{
            gotoxy(60,14);
        	printf("\t Sorry,the contact number is invalid!");
			gotoxy(60,16);
       		printf("\t Contact number consists of 10 digits\n");
			gotoxy(60,18);
			printf("\t\tEnter any key..");
			getch();
        	goto jump1;
		}
		else
		{
			gotoxy(60,14);
			printf("\t  Successfully updated");
			gotoxy(60,16);
	printf("\t\tEnter any key..");
	getch();
		}
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,12);
		printf("\t  Sorry No Record Found\n\n");
		gotoxy(60,14);
	printf("\t\tEnter any key..");
	getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
void emailchange_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	SetColor(12);
	struct faculty t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
    printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		found=1;
		jump1:
		{
			system("cls");
			box(60,5,140,40);
			gotoxy(60,10);
			printf("\t Verify your ID :: %s",rno);
			gotoxy(60,12);
			printf("\t Enter your email id to update :: ");
			scanf("%s",t.mailId);
		}
		if(isValid(t.mailId)==1 || isValid2(t.mailId)==1)
		{
			fflush(stdin);
			fwrite(&t,sizeof(t),1,fp1);
			gotoxy(60,14);
			printf("\t  Successfully updated\n\n");
			gotoxy(60,16);
			printf("\t\tEnter any key..");
			getch();
		}
		else
		{
			gotoxy(60,14);
			printf("\t Invalid mailID-Try Again");
			gotoxy(60,16);
			printf("\tEnter any key..");
	        getch();
			goto jump1;
		}
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,12);
		printf("\t  Sorry No Record Found\n\n");
		gotoxy(60,14);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
void passwordchange_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	SetColor(11);
	struct faculty t;
	int found=0;
	char rno[20];
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		found=1;
		jump3:
        {
        system("cls");
		box(60,5,130,40);
	    gotoxy(60,10);
		printf("\t Verify your Roll Number :: %s",rno);
		gotoxy(60,12);
        printf("\t NOTE : Password consists of 8 characters\n");
		gotoxy(60,14);
		printf("\t Enter your password to update :: ");
		int i=0;
		char ch;
        while(1)
		{
			ch = getch();
			if(ch==ENTER)
		    {
				t.password[i]='\0';
				break;
			}
		    else if(ch==BACKSPACE)
			{
				if(i>0)
				{
					i--;
					printf("\b \b");
				}
			}
			else if(ch==TAB || ch==SPACE)
			{
				continue;
			}
			else 
			{
				t.password[i]=ch;
				i++;
				printf("*");
			}
		  }	
		}
		if(strlen(t.password)!=8)
        {
            gotoxy(60,16);
            printf("\t Sorry,Invalid password\n");
			gotoxy(60,18);
			printf("\t\tEnter any key..");
			getch();
            goto jump3;
        }
		else
		{
        gotoxy(60,16);
        printf("\t Successfully updated\n");
		}
		fflush(stdin);
		strcpy(t.confirmPassword ,t.password);
		fwrite(&t,sizeof(t),1,fp1);
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
		gotoxy(60,14);
	printf("\t\tEnter any key..");
	getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
void securityquestionschange_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	SetColor(12);
	struct faculty t;
	int found=0;
	char rno[20];
	SetColor(24);
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		found=1;
		system("cls");
		box(60,5,130,40);
	    gotoxy(60,10);
		printf("\t Verify your ID :: %s",rno);
		gotoxy(60,14);
		printf("\t Enter your first school name to update :: ");
		scanf("%s",t.school);
		fflush(stdin);
		gotoxy(60,16);
		printf("\t Enter your favourite colour to update :: ");	
		scanf("%s",t.colour);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,18);
		printf("\t Successfully updated\n");
		gotoxy(60,20);
	printf("\t\tEnter any key..");
	getch();
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,12);
		printf("\t Sorry No Record Found\n\n");
		gotoxy(60,14);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
	
}
void qualifications_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	SetColor(12);
	struct faculty t;
	int found=0;
	char rno[20];
	SetColor(24);
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		found=1;
		gotoxy(60,12);
		printf("\tEnter your qualifications to update :: ");	
		scanf("%s",t.qualifications);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,14);
		printf("\t Successfully updated\n");
		gotoxy(60,16);
	printf("\t\tEnter any key..");
	getch();
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,14);
		printf("\t  Sorry No Record Found\n\n");
		gotoxy(60,16);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
void experience_F(char *fName)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp,*fp1;
	SetColor(12);
	struct faculty t;
	int found=0;
	char rno[20];
	SetColor(24);
	fp=fopen(fName,"rb");
	fp1=fopen("temp.dat","wb");
	printf("\t Verify your ID :: ");
	scanf("%s",rno);
	fread(&t,sizeof(t),1,fp);
	if(feof(fp))
	{
		return;
	}
	if(strcmp(t.id,rno)==0)
	{
		found=1;
		gotoxy(60,12);
		printf("\t Enter your experience to update :: ");	
		scanf("%s",t.experience);
		fwrite(&t,sizeof(t),1,fp1);
		gotoxy(60,14);
		printf("\t Successfully updated\n");
		gotoxy(60,16);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fwrite(&t,sizeof(t),1,fp1);
	}
	fclose(fp);
	fclose(fp1);
	if(found==0)
	{
		SetColor(45);
		gotoxy(60,12);
		printf("\t  Sorry No Record Found\n\n");
		gotoxy(60,14);
		printf("\t\tEnter any key..");
		getch();
	}
	else
	{
		fp=fopen(fName,"wb");
		fp1=fopen("temp.dat","rb");
		while(1)
		{
			fread(&t,sizeof(t),1,fp1);
			if(feof(fp1))
			{
				break;
			}
			fwrite(&t,sizeof(t),1,fp);
		}
	}
	fclose(fp);
	fclose(fp1);
}
void Search_F(char *MyFile)
{
	SetColor(12);
	int n;
	FILE *fp;
	fp=fopen(MyFile,"rb");
	struct student t;
	fread(&t,sizeof(t),1,fp);
	while(n!=7)
	{
		system("cls");
		box(60,5,130,40);
		gotoxy(60,9);
		printf("\t\t\t\t ***SEARCH***\n");
		gotoxy(60,12);
		printf("\t\t    What would you like to SEARCH");
		gotoxy(60,14);
    	printf("\t  1.Name");
		gotoxy(60,16);
    	printf("\t  2.Branch ");
		gotoxy(60,18);
    	printf("\t  3.Password ");
		gotoxy(60,20);
    	printf("\t  4.Contact number ");
		gotoxy(60,22);
    	printf("\t  5.Email-ID ");
		gotoxy(60,24);
    	printf("\t  6.Security Questions ");
		gotoxy(60,26);
		printf("\t  7.Homepage\n");
		gotoxy(60,28);
		printf("\t Enter your choice : ");
		scanf("%d",&n);
		switch(n)
		{
			case 1 : namesearch_F(MyFile);
			         break;
	    	case 2 : branchsearch_F(MyFile);
			         break;
			case 3 : passwordsearch_F(MyFile);
			         break;
			case 4 : contactsearch_F(MyFile);
			         break;
			case 5 : emailsearch_F(MyFile);
			         break;
			case 6 : securityquestionssearch_F(MyFile);
			         break;
			case 7 : Settings_F(MyFile,t.password); exit(0);
			default : gotoxy(60,28);
			           printf("\tInvalid Input\n");
		}
		getch();
	}
	fclose(fp);
}
void namesearch_F(char *fName)
{
	SetColor(24);
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
    FILE *fp;
    struct faculty t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your ID : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
      return;
    }
    if(strcmp(id,t.id)==0)
    {
    	found=1;
		gotoxy(60,12);
     	printf("\t\t  NAME :: %s\n",t.name);
		gotoxy(60,14);
		printf("\t\tEnter any key..");
	    getch();
    }
    if(found==0)
    {
	    SetColor(4);
		gotoxy(60,12);
        printf("\t  Sorry, no record found\n");
		gotoxy(60,14);
		printf("\t\tEnter any key..");
		getch();
    }
    fclose(fp);
}
void branchsearch_F(char *fName)
{
	SetColor(24);
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
    struct faculty t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your ID : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
    	return;
    }
    if(strcmp(id,t.id)==0)
    {
    	found=1;
		gotoxy(60,12);
    	printf("\t\t BRANCH :: %s\n",t.department);
    }
    if(found==0)
    {
	    SetColor(4);
		gotoxy(60,12);
    	printf("\t Sorry, no record found\n");
    }
   	fclose(fp);
	gotoxy(60,14);
	printf("\t\tEnter any key..");
	getch();
}
void passwordsearch_F(char *fName)
{
	SetColor(24);
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
	struct faculty t;
	int found=0;
    char id[50];
    fp=fopen(fName,"rb");
	printf("\t\t Verify your ID : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
            return;
        }
        if(strcmp(id,t.id)==0)
        {
            found=1;
			gotoxy(60,12);
            printf("\t\t  PASSWORD :: %s\n",t.password);   
        }
    	if(found==0)
    	{
		SetColor(4);
		gotoxy(60,12);
        	printf("\t  Sorry, no record found\n");
    	}
   	fclose(fp);
	gotoxy(60,14);
	printf("\t\tEnter any key..");
	getch();
}
void emailsearch_F(char *fName)
{
	SetColor(24);
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
	struct faculty t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your ID : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
        return;
    }
    if(strcmp(id,t.id)==0)
    {
        found=1;
	    gotoxy(60,12);
        printf("\t\t  EMAIL-ID : %s\n",t.mailId);
    }
    if(found==0)
    {
	    SetColor(4);
		gotoxy(60,12);
    	printf("\t  Sorry, no record found\n");
    }
    fclose(fp);
	gotoxy(60,14);
	printf("\t\tEnter any key..");
	getch();
}
void contactsearch_F(char *fName)
{
	SetColor(24);
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
    struct faculty t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your ID: ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
        return;
    }
    if(strcmp(id,t.id)==0)
    {
        found=1; 
        gotoxy(60,12);			
        printf("\t\t  CONTACT NUMBER :: %s\n",t.phone);    
    }
    if(found==0)
    {
		SetColor(4);
		gotoxy(60,12);
    	printf("\t Sorry, no record found\n");
    }
    fclose(fp);
	gotoxy(60,14);
	printf("\t\tEnter any key..");
	getch();
}
void securityquestionssearch_F(char *fName)
{
	SetColor(24);
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	FILE *fp;
    struct faculty t;
    int found=0;
    char id[50];
    fp=fopen(fName,"rb");
    printf("\t\t Verify your ID : ");
    scanf("%s",id);
    fread(&t,sizeof(t),1,fp);
    if(feof(fp))
    {
        return;
    }
    if(strcmp(id,t.id)==0)
    {
        found=1;
	    gotoxy(60,12);
	    printf("\t\t  IDENTIFICATION MARKS :: %s\n",t.identificationMarks);
		gotoxy(60,14);
        printf("\t\t  FAVOURITE COLOUR :: %s\n",t.colour);
		gotoxy(60,16);
		printf("\t\tEnter any key..");
		getch();
        }
    	if(found==0)
    	{
		SetColor(4);
		gotoxy(60,12);
    	printf("\n\t Sorry, no record found\n");
		gotoxy(60,14);
		printf("\t\tEnter any key..");
		getch();
    	}
    fclose(fp);
}
void Delete_F(char *MyFile)
{
	system("cls");
	box(60,5,130,40);
	gotoxy(60,10);
	SetColor(12);
  	printf("\t Delete Student Information\n");
  	FILE * fp1, * fp2;
  	struct faculty std, std1;
  	int found = 0;
  	char id[50];
  	fp1 = fopen(registerFile2, "rb");
  	fp2 = fopen("Delete.dll", "w");
  	fflush(stdin);
	gotoxy(60,14);
  	printf("\t Verify your ID : ");
  	fgets(id,sizeof(id),stdin);
	scanf("%[^\n]s",id);
 	while (1) 
	{
    	fread(&std1, sizeof(std1), 1, fp1);
    	if (feof(fp1)) 
		{
     		break;
    	}
    	if (strcmp(id, std1.id) == 0) 
		{
      		found = 1;
    	}
		else 
		{
      		fwrite(&std1, sizeof(std1), 1, fp2);
    	}
  	}
  	fclose(fp1);
  	fclose(fp2);
  	if (found == 0) 
	{
		gotoxy(60,16);
    	printf("\t DATA NOT FOUND \n");
		gotoxy(60,18);
		printf("\t\tEnter any key..");
		getch();
		Home();
  	} 
	else 
	{
    	fp1 = fopen(registerFile2, "wb");
    	fp2 = fopen("Delete.dll", "r");
    	while (1) 
		{
      		fread(&std1, sizeof(std1), 1, fp2);
      		if (feof(fp2)) 
			{
        		break;
      		}
      		fwrite(&std1, sizeof(std1), 1, fp1);
    		}
		strcat(id,".dat");
		DeleteFile(id);
		SetColor(4);
		gotoxy(60,16);
    	printf("\t  >> ACCOUNT DELETED SUCCESSFUL <<  \n\n");
		SetColor(12);
		gotoxy(60,18);
		printf("\t Thankyou \n");
		gotoxy(60,20);
		printf("\t\tEnter any key..");
		getch();
		Home();
 	 }
  	fclose(fp1);
  	fclose(fp2);
}
void gotoxy(int x, int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
