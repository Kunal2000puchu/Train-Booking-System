#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>


char ans=0;
int ok;
int b,valid=0;

void WelcomeScreen(void);
void Title(void);
void MainMenu(void);
void LoginScreen(void);
void Add_rec(void);
void Fun_list(void);
void Search_rec(void);
void Edit_rec(void);
void Dlt_rec(void);
void ex_it(void);
void gotoxy(short x,short y);

{
    COORD pos ={x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTUT_HANDLE),pos);
    
}


struct passenger
{
    int age;
    char Gender;
    char First_name[20];
    char Last_name[20];
    char Contact_no[15];
    char Email[20];
    char Address[30];
};

struct passenger p, temp_c;


 int main(void)
{
    WelcomeScreen();
    Title();
    LoginScreen();
}

void WelcomeScreen(void)
{
    printf("\n\n\n\n\n\n\n\t\t\t\t###################");
    printf("\n\t\t\t\t#\t\tWELCOMETO\t\t#");
    printf("\n\t\t\t\t#   ACHARYA TRAVELS   #");
    printf("\n\t\t\t\t###################");
    printf("\n\n\n\n Press any key to continue.....\n");
    getch();
    system("cls");
}
void Title(void)
{
    printf("\n\n\t\t---------------------------------------------");
    printf("\n\t\t   ACHARYA TRAVELS   ");
    printf("\n\n\t\t---------------------------------------------");
}

void LoginScreen(void)
{
    int e=0;
    char Username[15];
    char original_Username[15]="kunalth";
    char Password[15];
    char original_Password[15]="1234";
    
    do
    {
        printf("\n\n\n\n\t\t\t\tEnter your Username and Password :");
        printf("\n\n\n\t\t\t\tUSERNAME:");
        scanf("%s",&Username);
        printf("\n\n\n\t\t\t\tPASSWORD:");
        scanf("%s",&Password);
        
        if(strcmp(Username,original_Username)==0 && (strcmp(Password,original_Password)==0))
        {
            printf("\n\n\n\n\t\t\tLogin successful...");
            getch();
            MainMenu();
            break;
        }
        else
        {
            printf("\n\n\n\t\t\tIncorect Usernamme and Password.....");
            e++;
           getch();
        }
        
   
    }while(e<=2);
if(e>2)
{
    printf("You have crossed the limit(try after some time)......");
    getch();
    ex_it();
}
    system("cls");
}

void MainMenu(void)
{
    system("cls");
    int choose;
    Title();
    printf("\n\n\n\n\n\t\t\t\t1. Add Passengers Record\n");
    printf("\n\t\t\t\t2. List Passengers Record\n");
    printf("\n\t\t\t\t3. Search Passenger Record\n");
    printf("\n\t\t\t\t4. Edit Passenger Record\n");
    printf("\n\t\t\t\t5. Delete Passenger Record\n");
    printf("\n\t\t\t\t6. Exit\n");
    printf("\n\n\n\n\n\n\t\t\t\tChoose from 1 to 6:");
    scanf("%i",&choose);

    switch(choose)
    {
        case 1:
            Add_rec();
            break;
           
        case 2:
            Fun_list();
            break;
            
        case 3:
            Search_rec();
            break;
            
        case 4:
            Edit_rec();
            break;
            
        case 5:
            Dlt_rec();
            break;
            
        case 6:
            ex_it();
            break;
            
        default:
            printf("\t\t Invalid Entry.Please enter right option :");
            getch();
    }
}

void Add_rec(void)
{
    system("cls");
    Title();
    char ans;
    FILE *w;
    w=fopen("Record.txt", "a");
    printf("\n\n\t\t\t\t!!!!!!!!!!!!!ADD RECORD!!!!!!!!!!!!!\t\t");
    /************************FIRST NAME*************************/
A:
    printf("\n\t\t\tFirst Name :");
    scanf("%s",p.First_name);
    p.First_name[0] = toupper(p.First_name[0]);
    if(strlen(p.First_name)>20 || strlen(p.First_name)<2)
    {
        printf("\n\t INVALID(\t the max range for first name is 20 and min is 2)");
        goto A;
    }
    
    for(b=0;b<strlen(p.First_name);b++)
    {
        if(isalpha(p.First_name[b]))
        {
            valid=1;
        }
        else
        {
            valid=0;
            break;
        }
    }
    if(!valid)
    {
        printf("\n\t\t First name contain Invalid character : (Enter again :)");
        goto A;
    }

//**************LAST NAME*******************/
B:
    printf("\n\t\t\tLast Name :");
    scanf("%s",p.Last_name);
    p.First_name[0] = toupper(p.First_name[0]);
       if(strlen(p.Last_name)>20 || strlen(p.Last_name)<2)
       {
           printf("\n\t INVALID(\t the max range for last name is 20 and min is 2)");
           goto A;
       }
       
       for(b=0;b<strlen(p.Last_name);b++)
       {
           if(isalpha(p.Last_name[b]))
           {
               valid=1;
           }
           else
           {
               valid=0;
               break;
           }
       }
       if(!valid)
       {
           printf("\n\t\t Last name contain Invalid character : (Enter again :)");
           goto B;
       }
    
    //**************GENDER******************
    do
    {
    printf("\n\t\t\tGender:");
    scanf("%c",p.Gender);
    if(toupper(p.Gender)=='M' || toupper(p.Gender)=='F')
    {
        ok=1;
    }
    else
    {
        ok=0;
    }
    if(!ok)
    {
        printf("\n\t\t\tGender contain Invalid :");
    }
    }while (!ok);
    
    //**********AGE***********************
    
    printf("\n\t\t\tAge");
    scanf("%d",p.age);
    
    //*********ADDRESS********************
    
    do
    {
    C:
        printf("\n\t\t\tAddress:");
        scanf("%s",p.Address);
        p.Address[0]=toupper(p.Address);
        if(strlen(p.Address)>20  || (strlen(p.Address)<3))
           {
            printf("\n\t invalid :(The max range for address is 20 and min range is 4");
            goto C;
           }
    }while (!valid);
    //**********************CONTACT NUMBER*****************************
    
     do
     {
     D:
         printf("\n\t\t\tContact No:");
         scanf("%s",p.Contact_no);
         if(strlen(p.Contact_no)>10 || (strlen(p.Contact_no)!=10))
         {
             printf("\n\tSORRY:Invalid contact no(Try again later)");
             goto D;
         }
         else
         {
             for(b=0;b<strlen(p.Contact_no);b++)
             {
                 if(!isalpha(p.Contact_no[b]))
                 {
                     valid=1;
                     break;
                 }
                 else
                 {
                     valid=0;
                     break;
                 }
             }
             if(!valid)
             {
                 printf("\n\tContact no contains character value.....(Enter again) ");
                 goto D;
             }
         }
     }while(!valid);
    
    //********************EMAIL ID******************************
    
E:
    do
    {
        printf("\n\t\t\tEmail Id:");
        scanf("%s",p.Email);
        if(strlen(p.Email)>30||strlen(p.Email)<8)
        {
            printf("Invalid mail id(it should contain max 30 and min 8 character)");
            goto E;
        }
        
    }while(strlen(p.Email)>30||strlen(p.Email)<8);
    
    
}

void Fun_list(void)
{
    int row;
    system("cls");
    Title();
    FILE *w;
    w=fopen("Record.txt", "r");
    printf("\n\t\t\t!!!!!!!!!!!!!LIST OF RECORDS!!!!!!!!!!!!!!!");
    gotoxy(1, 15);
    printf("Full Name");
    gotoxy(20, 15);
    printf("Gender");
    gotoxy(32, 15);
    printf("Age");
    gotoxy(37, 15);
    printf("Address");
    gotoxy(49, 15);
    printf("Contact No");
    gotoxy(64, 15);
    printf("Email Id");
    printf("=================================================================================");
    row=17;
    while (fscanf(w, "%s %s %c %i %s %s %s",p.First_name,p.Last_name,p.Gender,p.age,p.Contact_no,p.Email))
    {
        gotoxy(1,row);
        printf("%s%s",p.First_name,p.Last_name);
        gotoxy(20, row);
        printf("%c",p.Gender);
        gotoxy(32, row);
        printf("%i",p.age);
        gotoxy(37, row);
        printf("%s",p.Contact_no);
        gotoxy(49, row);
        printf("%s",p.Email);
        row++;
    }
    fclose(w);
    getch();
    MainMenu();
}

void Search_rec(void)
{
    char name[20];
    system("cls");
    Title();
    FILE *w;
    w=fopen("Record.txt", "r");
    printf("\n\n\t\t\t!!!!!!!!!!search passenger record!!!!!!!!!!!!!!");
    printf("Enter passenger name to be viewed");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    while (fscanf(w, "%s %s %c %i %s %s %s",p.First_name,p.Last_name,p.Gender,p.age,p.Contact_no,p.Email))
    {
        if(strmp(p.First_name,name)==0)
        {
            gotoxy(1, 15);
            printf("Full Name");
            gotoxy(20, 15);
            printf("Gender");
            gotoxy(32, 15);
            printf("Age");
            gotoxy(37, 15);
            printf("Address");
            gotoxy(49, 15);
            printf("Contact No");
            gotoxy(64, 15);
            printf("Email Id");
            printf("============================================================================");
            break;

        }
    }
    if(strcmp(p.First_name, name)!=0)
    {
        gotoxy(5, 10);
        printf("Record not found!");
        getch();
    }
    fclose(w);
F:
    getch();
    printf("\n\n\t\t\tDo you want to view more[Y/N]?");
    scanf("%c",&ans);
    if(toupper(ans)=='Y')
    {
        Search_rec();
    }
    else if (toupper(ans)=='N')
    {
        printf("\n\t\tThank you :");
        getch();
        MainMenu();
    }
    else
    {
        printf("\n\t\t\t Invalid Input.\n");
        goto F;
    }
}
void Edit_rec()
{
    FILE *w,*k;
    int i,b,valid=0;
    char ch;
    char name[20];
    system("cls");
    Title();
    k=("kunal13.txt","w++");
    w=("Record.txt","r");
    if(w==NULL)
    {
        printf("\n\t Can't open the file..");
        getch();
        MainMenu();
    }
    printf("\n\n\t\t\t!!!!!!!!!!! Edit passenger record!!!!!!!!!!\n");
    gotoxy(12, 13);
    printf("Enter the First name of the passenger :");
    scanf("%s",name);
    fflush(stdin);
    name[0]=toupper(name[0]);
    gotoxy(12, 15);
    if(k==NULL)
    {
        printf("\n Can not open file");
        getch();
        MainMenu();
        
    }
    while (fscanf(w, "%s %s %c %i %s %s %s",p.First_name,p.Last_name,p.Gender,p.age,p.Contact_no,p.Email));
    {
        if(strcmp(p.First_name, name))
        {
            valid=1;
            gotoxy(25, 17);
            printf("***Existing Record***");
            gotoxy(10, 19);
            printf("%s \t%s \t%c \t%i \t%s \t%s \t%s\n",p.First_name,p.Last_name,p.Gender,p.age,p.Contact_no,p.Email);
            gotoxy(12, 22);
            
        }
    }
    
    
}
void Dlt_rec()
{
    char name[20];
    int found=0;
    system("cls");
    Title();
    FILE *w,*k;
    w=fopen("kunal3.txt", "w++");
    k=fopen("Record.txt", "r");
    printf("\n\n\t\t\t\t !!!!!!!!!!!Delete!!!!!!!!!!!!!\n");
    gotoxy(12, 8);
    printf("\n Enter passenger name to delete:");
    fflush(stdin);
    gets(name);
    name[0]=toupper(name[0]);
    while (fscanf(w, "%s %s %c %i %s %s %s",p.First_name,p.Last_name,p.Gender,p.age,p.Contact_no,p.Email))
    {
        if(strcmp(p.First_name, name)!=0)
            fprintf(k, "%s %s %c %i %s %s %s",p.First_name,p.Last_name,p.Gender,p.age,p.Contact_no,p.Email);
    
    else
    {
    printf( "%s %s %c %i %s %s %s",p.First_name,p.Last_name,p.Gender,p.age,p.Contact_no,p.Email);
        found=1;
    }
}
if(found==0)
{
    printf("\n\n\n\t\t Record not found...");
    getch();
    MainMenu();
}
else
{
    fclose(w);
    fclose(k);
    remove("Record.txt");
    rename("kunal3.txt","Record.txt");
    printf("\n\n\t\t\t Record deleted successfully : ");
    getch();
    MainMenu();
    
}
}







