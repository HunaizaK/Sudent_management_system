#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

char money='P';
int i=0,j=0,n,option,count=0;
float attendance =75.00;
float totaldays;
 
struct student {
 	char name[100];
 	int rno;
 	char fees;
 	float days ;
 	float attendance ;
 	char dept[100] ;
 	//variable[].attritube
}s[50];

//function declaration
void login();
void Add(struct student s[]);
void PrintStudent(struct student s[]);
void DeleteRecord(struct student s[]);
void menu ();
void EligibleStudent(struct student s[]);
void SortStudent(struct student s[]);
 
void menu (){
	
	getch();
	system ("cls");
printf("Enter the serial number to select the following options\n");
printf("_______\n");
printf(" 1. To show eligible candidates.\n");
printf(" 2. To delete the student record.\n");
printf(" 3. To change the eligibility criteria.\n");
printf(" 4. To reset the eligibility criteria. \n");
printf(" 5. Sort the students details according to the alphabetical order.\n");
printf(" 6. Print the record of students.\n");
printf(" 7. Enter 0 to exit.\n");
scanf ("%d",& option );

switch (option)
{
	
    case 0:
	        exit (0);
	
	case 1:
	        EligibleStudent(s);
	      	menu ();
		    break;
		
		
		case 2:
		     	DeleteRecord(s);
		
		    	menu();
		     	break;
			
			
			case 3:
				printf(" Old attendance required was %0.2f.\n",attendance );
				printf(" Enter the new atendance  :\n");
				scanf("%f",& attendance);
				printf(" The fee status required  was %c.\n",money );
				printf(" Enter the new fee status 'P' for paid 'N' for not paid and 'B' for both.\n");
				scanf("\n%c" , & money);
				printf(" \n");
				printf("_ Eligibility criteria  has been changed successfully___\n");
			    menu ();
		    	break;
			
			
		    case 4:
		    	
		    	attendance=75.00;
		    	money ='P';
		    	printf("_Eligibility criteria reset_\n");
		    	menu();
		    	break;
		    	
		    	
		    case 5:
		    	
			 SortStudent (s);
			 printf("_The records have been  sorted successfully_\n ");
			 menu();
			 break;
			 
			 
		    case 6:
		    	
		    	PrintStudent(s);
		    	menu();
		    	break;
		
		
		    default :
		    	
			printf("Enter a valid number from 0-6\n");
			menu ();
		}
	}
   
            void SortStudent(struct student s[]){
            	
            	int temprno;
            	char tempname[100];
            	char tempdept[100];
            	char tempfees;
            	float temp;
            	
            	for (i=0;i<n-count;i++)
            	{
            		for (j=0;j<n-count-i-1;j++)
            		{
            		if (s[j].name[0]>s[j+1].name[0])
					{
						
						strcpy(tempname,s[j].name);
						strcpy(s[j].name,s[j+1].name);
						strcpy(s[j+1].name ,tempname);
						
						
						strcpy(tempdept,s[j].dept);
						strcpy(s[j].dept,s[j+1].dept);
						strcpy(s[j+1].dept ,tempdept);
						
						
						temprno=s[j].rno;
						s[j].rno=s[j+1].rno;
						s[j+1].rno=temprno;
						
						tempfees=s[j].fees;
						s[j].fees=s[j+1].fees;
						s[j+1].fees=tempfees;
						
						temp=s[j].days;
						s[j].days=s[j+1].days;
						s[j+1].days=temp;
						
						temp=s[j].attendance;
						s[j].attendance=s[j+1].attendance;
						s[j+1].attendance=temp;	
						
						}		
					}
				}
			}

 	void PrintStudent(struct student s[] ) {
	 
 		if (n==count)
 		{
 			printf("*__No record exists__*\n");
		}else{
		
 		for (i=0;i<n-count;i++)
 		{
 			printf("Name of student %d = %s.\n",i+1,s[i].name);
 			printf("Student's deptartment = %s .\n",s[i].dept);
 			printf("Student roll.no = %d.\n",s[i].rno);
 			printf("Student fee status = %c.\n",s[i].fees);
 			printf("The no of days the student was present  = %0.2f.\n",s[i].days);
 			printf("Student's attendance = %0.2f.\n",s[i].attendance);
 			printf("*____* \n");
 			printf(" \n");
		 }
	    }
	 }
	
	 void  DeleteRecord(struct student s[])
	{
		int a=0,checker=0;
		printf("Enter the roll no. of the student you want to delete\n");
		scanf("%d",&a);
		for (i=0;i<=n;i++)
		{
			if (s[i].rno == (a))  
			
			{
				printf("_Student record deleted successfully_\n");
				printf("Student roll.no = %d record deleted.\n",s[i].rno);
				printf("Name of student  = .\n");
 			    printf("Student's deptartment =  .\n");
 			    printf("Student fee status = .\n");
 			    printf("The no of days the student was present  = 0.0.\n");
 			    printf("Student's attendance = 0.0.\n");
				for (j=i;j<n;j++)
				{
				 	strcpy(s[j].name ,s[j+1].name);
				 	strcpy(s[j].dept ,s[j+1].dept);
                     s[j].rno=s[j+1].rno;
                     s[j].attendance=s[j+1].attendance;
                     s[j].days=s[j+1].days;
                     s[j].fees=s[j+1].fees;
  	
				}
	            checker = 1;
	            count++;									
			}
		}
		if (checker == 0) 		
		{
			printf("*__No record found to delete__*\n");
		}
		
	}
	
  void EligibleStudent(struct student s[] ) 
  {
  	
  		if (n==count)
 		{
 			printf("*__No record exists__*\n");
		}else{
  	printf(" ___________\n");
  	printf("The students eligible for examination are :\n ");
  	for (i=0;i<n;i++) {
  		
  		if ( ( s[i].fees == money) || money =='B') 
  		{
  			if ( s[i].attendance >= attendance )
  			{
  				
  				printf("Name of %d student = %s.\n",i+1,s[i].name);
  				printf("Student's Department = %s.\n",s[i].dept);
  				printf("Student's roll no = %d.\n",s[i].rno);
  				printf("Student fee status = %c. \n",s[i].fees);
  				printf("The number of days the student was present = %0.2f.\n",s[i].days);
  				printf("Student's sttendance = %0.2f.\n",s[i].attendance);
  			
  				
			  }
		  }
	  }
    }
  }
	
    void Add(struct student s [50])
	{

	printf("Enter the total number of working days\n");
	scanf("%f",&totaldays);
		
	printf("Enter the number of students\n");
	scanf("%d",&n);
     	for (i=0;i<n;i++) 
	    {
        	 printf("_ Student %d_\n",i+1);
			 
	    	 printf("Enter the name of student :");
	         fflush (stdin);
		     gets(s[i].name);
			 
			 printf("Enter the roll no. of students (in digits only):");
			 scanf(" %d",&s[i].rno);
			 int j;
			 for( j=0;j<i;j++)
			 {
			 	while (s[j].rno == s[i].rno) 
			 	{
			 		printf("Roll Number already exists, please enter a different one.\n");
			 		scanf(" %d",&s[i].rno);
				}
			 } 
			 
			 printf("Enter the name of department of the student: ");
			 fflush (stdin);
			 gets (s[i].dept);
			 
			 printf("Enter the fee status of student 'P' for paid and 'N' for not paid: ");
			 scanf("\n%c",&s[i].fees);
			 
			 printf("Enter the number of days the student was present:");
			 scanf("%f",&s[i].days);
			 
			 s[i].attendance=( s[i].days/totaldays)*100;
			 printf("Students attendance : %0.2f",s[i].attendance);
			 printf("\n\n");
			
			
		}
		menu ();
		
	}
	
	int main ()
	{	
	     int RED;
		  
		 printf("xxxx---------------WELCOME TO EXAMINATION MANAGEMENT SYSTEM.---------------xxxx\n\n"); 
		 login();
		 
		 printf("Please select an option :\nPress 0 to exit and 1 to add student record \n");
		 scanf("%d",&option );
		 
		 switch (option)
		 {
		 	case 0:
		 		exit (0);
		 		
		 	case 1 :
		 		Add(s);
		 		break;
		 			
		 	default :
		 		printf(" Only enter 0 or 1 ");
		 		menu ();
		 }
		 return 0; 
		
	}
void login()
{
    	char name[200],pass[200],comb[200];
    	int flag=0;
    	FILE *ptr;
	  
	    printf("Please Log In to continue.\n");
		
		 Sleep(3000);
		 printf("Enter your username: ");
		 fflush(stdin);
		 gets(name);
		 printf("Enter your password: ");
		 fflush(stdin);
		 gets(pass);
		 
		 strcat(name,"*");
		 strcat(name,pass);
		 strcat(name,"\n");		 
		 ptr=fopen("username pass.txt","r");
		 
		 if(ptr==NULL)
		 {
		 	printf("File not found.\n");
		 }
		 
		 while(!feof(ptr))
		 {
		 	fgets(comb,200,ptr);
		 	if(strcmp(comb,name) == 0)
		 {
		 	for(i=0;i<3;i++) 
			{
		 	Beep(5000,300);
		    }
		 	printf("Thank you! \n Please proceed for further details.\n");
		    flag = 1;
		    break;
		 }
		 
	    }
		if (flag == 0) 
		{
			Beep(740,300);
		 	printf("Either username or password is wrong. Please enter again.\n");
		 	login();
		}
	    fclose(ptr);
}
