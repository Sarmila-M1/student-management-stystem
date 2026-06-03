#include "header.h"

int studentcount=0;
stu ** s=0;

void dynamic_memory_allocate()
{
       	stu* a=(stu *)malloc(sizeof(stu));
	s=realloc(s,(sizeof(stu)*studentcount));
	s[studentcount]=a;
}

void create_record()
{
	dynamic_memory_allocate();
	int num;
	printf("Enter your Name(First_name Second_name Lase_name) : ");
	scanf(" %[^\n]",s[studentcount]->name);
	printf("Enter your Father's Name(First_name Second_name Lase_name) : ");
        scanf(" %[^\n]",s[studentcount]->fathers_name);
	printf("Enter your Mother's Name(First_name Second_name Lase_name) : ");
        scanf(" %[^\n]",s[studentcount]->mothers_name);
	printf("Enter your Date of birth (MM/DD/YYYY) : ");
        scanf(" %[^\n]",s[studentcount]->date_of_birth);
        while(1)
	{
		printf("Enter your gender : \nPress 1 : Female\nPress 2 : Male\nPress 3 : Transgesgender\n");
		scanf(" %d",&num);
		if(num==1)
	       	{
			strcpy(s[studentcount]->gender,"Female");
			break;
		}
		else if(num==2)
		{
			strcpy(s[studentcount]->gender,"Male");
			break;
		}
		else if(num==3)
		{
			strcpy(s[studentcount]->gender,"Transgender");
			break;
		} 
		else
			printf("Invalid choise....\nEnter an valid choise....\n");
	}

	printf("Enter your Blood group : ");
        scanf(" %[^\n]",s[studentcount]->bloodgroup);
        printf("Enter your Phone Number : ");
        scanf("%ld",&(s[studentcount]->phonenumber));
        printf("Enter your Mail Id : ");
        scanf(" %s",s[studentcount]-> mail_id);
	while(1)
	{
		printf("Select your Department\nPress 1 : AIDS\nPress 2 : AIML\nPress 3 : CSE\nPress 4 : IT\nPress 5 : ECE\nPress 6 : EEE\nPress 7 : CIVIL\nPress 8 : MECH\n");
		scanf("%d",&num);
		if(num==1)
		{
			strcpy(s[studentcount]->course,"AIDS");
			break;
		}
		else if(num==2)
		{
			strcpy(s[studentcount]->course,"AIML");
			break;
		}
		else if(num==3)
                {
                        strcpy(s[studentcount]->course,"CSE");
                        break;
                }
		else if(num==4)
                {
                        strcpy(s[studentcount]->course,"IT");
                        break;
                }
		else if(num==5)
                {
                        strcpy(s[studentcount]->course,"ECE");
                        break;
                }
		else if(num==6)
                {
                        strcpy(s[studentcount]->course,"EEE");
                        break;
                }
		else if(num==7)
                {
                        strcpy(s[studentcount]->course,"CIVIL");
                        break;
                } 
		else if(num==6)
                {
                        strcpy(s[studentcount]->course,"MECH");
                        break;
                }
	       	else
                {
                       printf("You enter an invalid choise....\nEnter an valid choise\n");
                }
		
	}
	printf("Enter your 12 Digit adharnumber (without space) : ");
        scanf(" %s",s[studentcount]->adharnumber);
        printf("Enter your nationality (Indian/Foreigner) : ");
        scanf(" %s",s[studentcount]->nationality);	
	printf("Enter your religion (Hindu/Christian/Islam) : ");
        scanf(" %s",s[studentcount]->religion);
	printf("Enter your community (BC/BCM/MBC/DNC/SC/ST) : ");
        scanf(" %s",s[studentcount]->community);
	printf("Enter your caste : ");
        scanf(" %[^\n]",s[studentcount]->caste);
	printf("Enter the year of joining : ");
        scanf("%d",&(s[studentcount]->joind_year));
	printf("Enter your address : ");
        scanf(" %[^\n]",s[studentcount]->address);
	printf("Enter your 10th Mark : ");
        scanf("%d",&(s[studentcount]->tenth_mark));
	printf("Enter your 12th Mark : ");
        scanf("%d",&(s[studentcount]->twelth_mark));
	while(1)
	{
		printf("Lateral Entert\nPress 1 : N0\nPress 2 : Yes\n");
	        scanf("%d",&num);
	        if(num==1)
	        {
	        	s[studentcount]->lateral_entery=0;
		        break;
	        }
        	else if(num==2)
	        {
			s[studentcount]->lateral_entery=1;
			printf("Enter your diploma Marks : ");
                        scanf("%d",&(s[studentcount]->diploma_marks));
		        break;
        	}
		else
			printf("You entered an invalid option\n");
	}
	while(1)
	{
	printf("Mode of staying(hosteller/dayscholar)\nPress 1 : hosteler\nPress 2 : Dayscholar\n");
	scanf("%d",&num);
	if(num==1)
	{
		s[studentcount]->hosteler=1;
		break;
	}
	else if(num==2)
	{
		s[studentcount]->hosteler=0;
		break;
	}
	else
		printf("You entered invalid choise...\n");
	}
        while(1)
	{
	printf("Enter first graduate or not : \nPress 1 : First graduate\nPress 2 : Not a First Graduate\n");
	scanf("%d",&num);
	if(num==1)
	{
		s[studentcount]->first_gradurate=1;
		break;
	}
	else if(num==2)
        {
                s[studentcount]->first_gradurate=0;
                break;
        }  
	else
	{
		printf("You entered an invalid choise...\n");
	}
	}
	strcpy(s[studentcount]->register_number," ");
	s[studentcount]->cgpa=0;
	for(int i=0;i<SEMESTER;i++)
		s[studentcount]->sgpa[i]=0;
	for(int i=0;i<COURSECOUNT ;i++)
		s[studentcount]->arrearcount[i]=0;
	s[studentcount]->semestercount=0;
	if(s[studentcount]->lateral_entery==1)
		 s[studentcount]->semestercount=2;
	s[studentcount]->coursecount=0;
	studentcount++;	
}

int departmentwise_studentcount(char *course,int year)
{
	int count=0;
	for(int i=0;i<studentcount;i++)
	{
		if((!(strcmp(s[i]->course,course)))&&(s[i]->joind_year==year))
			count++;
	}
	return count;
}

int particular_department_studentcount(char *course)
{
	int count=0;
        for(int i=0;i<studentcount;i++)
                if(!(strcmp(s[i]->course,course)))
                        count++;
	return count;
}

void register_number_allocation(char *course,int year)
{
	int count=departmentwise_studentcount(course,year);
	char name[count][N];
	int lastindex=count,start=0;
	int i=0,j=0;
	for(;i<count;i++)
	{
                for(;j<studentcount;j++)
		{
			if((!(strcmp(s[j]->course,course)))&&(s[j]->joind_year==year))
					{ 
					       	if(s[j]->lateral_entery==0)
						      strcpy(name[start++],s[j]->name);
					        else 
						      strcpy(name[--lastindex],s[j]->name);
						j++;
						break;

					}
		}
	}

	for(j=0;j<lastindex;j++)
	{
		for(i=j;i<lastindex;i++)
		{
			char temp[N];
	                if(strcmp(name[j],name[i])>=0)
			{
				strcpy(temp,name[j]);
		                strcpy(name[j],name[i]);
		                strcpy(name[i],temp);
			}
		}
	}
	for(j=lastindex;j<count;j++)
        {
                for(i=j+1;i<count;i++)
                {
                        char temp[N];
                        if(strcmp(name[j],name[i])>=0)
                        {
                                strcpy(temp,name[j]);
                                strcpy(name[j],name[i]);
                                strcpy(name[i],temp);
                        }
                }
        }
	char cch;
	for(i=0;i<studentcount;i++)
	{if((!(strcmp(s[i]->course,course)))&&(s[i]->joind_year==year))
	   {
		   for(j=0;j<lastindex;j++)
	           {
			   if(((!(strcmp(s[i]->name,name[j]))))&&(s[i]->lateral_entery==0))
	                   {
				   char a[N];
				   cch='N';
		                   sprintf(a,"%d%d%s%c%d",7329,s[i]->joind_year%100,s[i]->course,cch,j+1);
               			   strcpy(s[i]->register_number,a);
			           printf("j= %d rginu=%s a=%s i=%d name=%s \n",j,s[i]->register_number,a,i,s[i]->name);
			           name[j][0]='\0';
			           break;
			}
		   }
	    }
	}
	for(i=0;i<studentcount;i++)
        {if((!(strcmp(s[i]->course,course)))&&(s[i]->joind_year==year))
           {
                   for(j=lastindex;j<count;j++)
                   {
                           if(((!(strcmp(s[i]->name,name[j]))))&&(s[i]->lateral_entery==1))
                           {
                                   char a[N];
				   cch='L';
                                   sprintf(a,"%d%d%s%c%d",7329,(s[i]->joind_year%100)-1,s[i]->course,cch,j+1);
                                   strcpy(s[i]->register_number,a);
                                   printf("j= %d rginu=%s a=%s i=%d name=%s \n",j,s[i]->register_number,a,i,s[i]->name);
                                   name[j][0]='\0';
                                   break;
                        }
                   }
            }
        }
}



void print_studentdetail()
{
	int num;
	int countarray[MAX],countvalue=0;
	printf("Press 1 : Search student detail using name\nPress 2 : Search student detail using Register number\n");
	scanf("%d",&num);
	if(num==1)
	{
		char name[N];
		printf("Enter name : ");
		scanf(" %[^\n]",name);
		for(int i=0;i<studentcount;i++)
		{
			if(!(strcmp(s[i]->name,name)))
			{countarray[countvalue++]=i;}
		}
	}
	else if(num==2)
	{
		char register_number[N];
		printf("Enter Register number : ");
		scanf(" %[^\n]",register_number);
		for(int i=0;i<studentcount;i++)
		{
			if(!(strcmp(s[i]->register_number,register_number)))
						{countarray[countvalue++]=i;}
		}
	}
	
	for(int i=0;i<countvalue;i++)
	{
		printf("---------------------------------------------------------------------------------------------------\n\n");
		printf("Name            : %s\n",s[countarray[i]]->name);
		printf("Department      : %s\n",s[(countarray[i])]->course);
		if(strcmp(s[i]->register_number," "))
		        printf("Register number : %s\n",s[(countarray[i])]->register_number);
		else
			printf("Register number : Not allocated\n");
		printf("Accademic year  : %d - %d\n",s[(countarray[i])]->joind_year,s[(countarray[i])]->joind_year+4);
		printf("Father's Name   : %s\n",s[(countarray[i])]->fathers_name);
		printf("Mother's Name   : %s\n",s[(countarray[i])]->mothers_name);
		printf("Gender          : %s\n",s[(countarray[i])]->gender);
		printf("Date of Birth   : %s\n",s[(countarray[i])]->date_of_birth);
		printf("Blood group     : %s\n",s[(countarray[i])]->bloodgroup);
		printf("Address         : %s\n",s[(countarray[i])]->address);
		printf("Adhar number    : %s\n",s[(countarray[i])]->adharnumber);
		printf("Caste           : %s\n",s[(countarray[i])]->caste);
		printf("Religion        : %s\n",s[(countarray[i])]->religion);
		printf("Community       : %s\n",s[(countarray[i])]->community);
		printf("Phone Number    : %ld\n",s[(countarray[i])]->phonenumber);
		printf("Mail Id         : %s\n",s[(countarray[i])]->mail_id);
		printf("Hosteler        : ");
		if(s[(countarray[i])]->hosteler)
		{
			printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
		printf("First graduate  : ");
		if(s[(countarray[i])]->first_gradurate)
		{
                        printf("Yes\n");
		}
                else
		{
                        printf("No\n");
		}
		printf("Lateral entery : ");
		if(s[(countarray[i])]->lateral_entery)
		{
			printf("Yes\n");
                }
                else
                {
                        printf("No\n");
                }
		printf("10th Mark       : %d\n",s[(countarray[i])]->tenth_mark);
		printf("12th Mark       : %d\n",s[(countarray[i])]->twelth_mark);
		if(s[(countarray[i])]->lateral_entery==1)
		printf("Diploma Marks   : %d\n",s[(countarray[i])]->diploma_marks);
		if(((s[(countarray[i])]->semestercount>0)&&(s[(countarray[i])]->lateral_entery==0))||(s[(countarray[i])]->semestercount>2))
		{
			printf("\nSemester Wise SGPA\n\n");
		}
		for(int j=0;j<s[(countarray[i])]->semestercount;j++)
	        {
			if((s[(countarray[i])]->lateral_entery==1)&&((j==0)||(j==1)))
				continue;

			printf("%d Semester      : %.1f\n",(j+1),s[(countarray[i])]->sgpa[j]);
		}
		printf("\n");
		printf("CGPA            : %.1f\n\n",s[(countarray[i])]->cgpa);
		print_semesterwise_mark(s[(countarray[i])]->register_number);
		printf("---------------------------------------------------------------------------------------------------\n\n");
	}
}


void enter_semestermark()
{
	char register_number[N];
	int i,j,secount,num,sc;
	printf("Enter the register number : ");
	scanf(" %s",register_number);
	for(i=0;i<studentcount;i++)
	{
		if(!(strcmp(s[i]->register_number,register_number)))
		{
			printf("Enter the semester (EX:1,2,3,4,5,6,7,8) : ");
			scanf("%d",&secount);
			if(secount==s[i]->semestercount+1)
			{
				s[i]->semestercount=secount;
				printf("Enter the number of subjects in that particular semester including lab : ");
				scanf("%d",&(s[i]->course_semester_wisecount[secount-1]));
			}
			else if(secount>s[i]->semestercount+1)
			{
				printf("Invalid semester count....");
				return;
			}
			else if(secount<=s[i]->semestercount)
			{
				if(s[i]->lateral_entery==1)
				{
					printf("For lateral entery no 1st and 2nd semester\n");
				        return;
				}
				printf("Already entered the marks....\nOnce entered mark cannot be modified...\n");
				return;
			}
			printf("Once the mark and course code entered that cannot be modified....\nEnter all the %d course grade of this semsester\n",s[i]->course_semester_wisecount[secount-1]);
			for(j=0;j<s[i]->course_semester_wisecount[secount-1];j++)
			{
				sc=1;
				printf("Enter the course code : ");
				scanf(" %s",s[i]->course_name[s[i]->coursecount]);
				for(int p=0;p<s[i]->coursecount;p++)
				{
					if(!(strcmp(s[i]->course_name[s[i]->coursecount],s[i]->course_name[p])))
					{
						printf("Already this course has been done\n");
						sc=0;
						break;
					}
				}
				if(sc==0)
				{
					j--;
					continue;
				}
				printf("Enter the course total credit points : ");
				scanf("%d",&(s[i]->course_point[(s[i]->coursecount)]));
				while(1)
				{
					printf("select the grade \n");
                                        printf("Press 1 : O grade\nPress 2 : A+ grade\nPress 3 : A grade\n");
                                        printf("Press 4 : B+ grade\nPress 5 : B grade\n");
                                        printf("Press 6 : C grade\nPress 7 : Re - appear \n");
                                        scanf("%d",&num);
					printf("\n%d\n",num);
                                        if(num==1)
                                        {
						printf("%d cours\t",s[i]->coursecount);
						s[i]->course_grade[(s[i]->coursecount++)]=10;
                                                printf("%d course\n",s[i]->coursecount);
						break;
                                        }
                                        else if(num==2)
                                        {
                                                s[i]->course_grade[(s[i]->coursecount++)]=9;
                                                break;
                                        }
                                        else if(num==3)
                                        {
                                                s[i]->course_grade[(s[i]->coursecount++)]=8;
                                                break;
                                        }
                                        else if(num==4)
					{
                                                s[i]->course_grade[(s[i]->coursecount++)]=7;
                                                break;
                                        }
                                        else if(num==5)
                                        {
                                                s[i]->course_grade[(s[i]->coursecount++)]=6;
                                                break;
                                        }
                                        else if(num==6)
					{
                                                s[i]->course_grade[(s[i]->coursecount++)]=5;
                                                break;
                                        }
                                        else if(num==7)
                                        {
                                                s[i]->course_grade[(s[i]->coursecount)]=0;
                                                s[i]->arrearcount[(s[i]->coursecount++)]++;
                                                break;
                                        }
                                        else
					{printf("You entered and invalid grade points....\n");
                                                                 continue;}
				}
			}
			calculate_sgpa_cgpa(register_number);
			break;
		}

	}
	if(i==studentcount)
		printf("Give register number not found\n");
}
				
				
			
void arrear_exammark()
{
	char register_number[N];
	int i,j,num;
	printf("Enter the register number : ");
	scanf("%s",register_number);
	for(i=0;i<studentcount;i++)
	{
		if(!(strcmp(s[i]->register_number,register_number)))
		{
			char course_code[N];
			printf("Enter the course code : ");
			scanf(" %s",course_code);
			for(j=0;j<s[i]->coursecount;j++)
			{
				if(!(strcmp(s[i]->course_name[j],course_code)))
				{ 
					if((s[i]->arrearcount[j]<1)||(s[i]->course_grade[j]!=0))
					{
						 if((s[i]->arrearcount[j]<1))
							 printf("It is not an arrear exam subject....\n");
						 else
							 printf("This arrear exam subject is already cleared....\n");
						return;
					}

					 while(1)
                                                 {
                                                         printf("select the grade \n");
                                                         printf("Press 1 : O grade\nPress 2 : A+ grade\nPress 3 : A grade\n");
                                                         printf("Press 4 : B+ grade\nPress 5 : B grade\n");
                                                         printf("Press 6 : C grade\nPress 7 : Re - appear \n");
                                                         scanf("%d",&num);
							 printf("\n%d\n",num);
                                                         if(num==1)
                                                         {
                                                                 s[i]->course_grade[j]=10;
                                                                 break;
                                                         }
                                                         else if(num==2)
                                                         {
                                                                 s[i]->course_grade[j]=9;
                                                                 break;
                                                         }
                                                         else if(num==3)
                                                         {
                                                                 s[i]->course_grade[j]=8;
                                                                 break;
                                                         }
                                                         else if(num==4)
                                                         {
                                                                 s[i]->course_grade[j]=7;
                                                                 break;
                                                         }
                                                         else if(num==5)
                                                         {
                                                                 s[i]->course_grade[j]=6;
                                                                 break;
                                                         }
                                                         else if(num==6)
							 {
                                                                 s[i]->course_grade[j]=5;
                                                                 break;
                                                         }
                                                         else if(num==7)
                                                         {
                                                                 s[i]->arrearcount[j]++;
                                                                 break;
                                                         }
                                                         else
							 {printf("You entered and invalid grade points....\n");
								 continue;}
							 calculate_sgpa_cgpa(register_number);
						 }
					 break;
				}
			}
			if(j==s[i]->coursecount)
				printf("You entered invalid course code...\n");
			break;

		}
	
	}
	if(i==studentcount)
		printf("No such Register number found....\n");
}
void print_semesterwise_mark(char *register_number)
{
	int m=0;
	for(int i=0;i<studentcount;i++)
	{
		if(!(strcmp(s[i]->register_number,register_number)))
		{for(int j=0;j<s[i]->semestercount;j++)
			{
				if((s[i]->lateral_entery==1)&&((j==0)||(j==1)))
					continue;
				printf("SEMESTER %d\n",j+1);
				for(int k=0;k<s[i]->course_semester_wisecount[j];k++,m++)
				{
					printf("Couse Name  : %-10s",s[i]->course_name[m]);
					if(s[i]->course_grade[m]==0)
						 printf("Couse grade   : RA\n");
					else
					{
						printf("Couse grade : ");
						if(s[i]->course_grade[m]==10)
							printf("O  ");
						else if(s[i]->course_grade[m]==9)
							printf("A+ ");
						else if(s[i]->course_grade[m]==8)
                                                        printf("A  ");
						else if(s[i]->course_grade[m]==7)
                                                        printf("B+ ");
						else if(s[i]->course_grade[m]==6)
                                                        printf("B  ");
						else if(s[i]->course_grade[m]==5)
                                                        printf("C  ");
					      printf(" (%d Points)    ",s[i]->course_grade[m]);
				              printf("Total credits for this subject : %d\n",s[i]->course_point[m]);	      
					}

				}
				printf("\n");
			}
		}
	}
}


void calculate_sgpa_cgpa(char *register_number)
{
	int i,j,k,m=0,cgpa=0,credcgpa=0,sgpa=0,credsgpa=0;
	for(i=0;i<studentcount;i++)
	{
		if(!(strcmp(s[i]->register_number,register_number)))
		{
			for(j=0;j<s[i]->coursecount;j++)
			{
				cgpa=cgpa+(s[i]->course_point[j]*s[i]->course_grade[j]); 
				if((s[i]->arrearcount[j]<1))
				credcgpa+=s[i]->course_point[j];
			}

			s[i]->cgpa=(float)cgpa/credcgpa;

			for(j=0;j<s[i]->semestercount;j++)
			{
				for(k=0;k<s[i]->course_semester_wisecount[j];k++,m++)
				{
					sgpa+=((s[i]->course_point[m]*s[i]->course_grade[m]));
					credsgpa+=s[i]->course_point[m];
				}
				s[i]->sgpa[j]=(float)sgpa/credsgpa;
				sgpa=0;credsgpa=0;
			}
		}
	}
}

void arrange_year_department_name()
{
	int i,j,y1,y2;
	struct student temp;
	for(i=0;i<studentcount;i++)
	{
		for(j=i+1;j<studentcount;j++)
		{
			y1=s[i]->joind_year-s[i]->lateral_entery;
		        y2=s[j]->joind_year-s[j]->lateral_entery;

		       if(y1>y2)
		       {
			       temp=*s[i];
                               *s[i]=*s[j];
                               *s[j]=temp;
                       }
		       else if(y1==y2)
		       {
			       if(strcmp(s[i]->course,s[j]->course)>0)
			       {
				        temp=*s[i];
                                        *s[i]=*s[j];
                                        *s[j]=temp;
                               }
			       else if(strcmp(s[i]->course,s[j]->course)==0)
			       {
				       if((s[i]->lateral_entery==1)&&(s[j]->lateral_entery==0))
					       {
                                                       temp=*s[i];
                                                       *s[i]=*s[j];
                                                       *s[j]=temp;
                                               }
				       else if((s[i]->lateral_entery==0)&&(s[j]->lateral_entery==1))
					       continue;
				       else if(strcmp(s[i]->name,s[j]->name)>0)
					       {
						       temp=*s[i];
                                                       *s[i]=*s[j];
                                                       *s[j]=temp;
					       }
                                       
			       }
		       }
		}
	}
}



void print_all_student()
{int i;
 for(i=0;i<studentcount;i++)
        {
                printf("---------------------------------------------------------------------------------------------------\n\n");
                printf("Name            : %s\n",s[i]->name);
                printf("Department      : %s\n",s[i]->course);
                if(strcmp(s[i]->register_number," "))
                        printf("Register number : %s\n",s[i]->register_number);
                else
                        printf("Register number : Not allocated\n");
                printf("Accademic year  : %d - %d\n",s[i]->joind_year,s[i]->joind_year+4);
		printf("Father's Name   : %s\n",s[i]->fathers_name);
                printf("Mother's Name   : %s\n",s[i]->mothers_name);
                printf("Gender          : %s\n",s[i]->gender);
                printf("Date of Birth   : %s\n",s[i]->date_of_birth);
                printf("Blood group     : %s\n",s[i]->bloodgroup);
                printf("Address         : %s\n",s[i]->address);
                printf("Adhar number    : %s\n",s[i]->adharnumber);
                printf("Caste           : %s\n",s[i]->caste);
                printf("Religion        : %s\n",s[i]->religion);
                printf("Community       : %s\n",s[i]->community);
                printf("Phone Number    : %ld\n",s[i]->phonenumber);
                printf("Mail Id         : %s\n",s[i]->mail_id);
                printf("Hosteler        : ");
                if(s[i]->hosteler)
                {
                        printf("Yes\n");
                }
                else
                {
                        printf("No\n");
                }
                printf("First graduate  : ");
                if(s[i]->first_gradurate)
                {
                        printf("Yes\n");
                }
		else
		{
			printf("No\n");
		}
		 printf("Lateral entery : ");
                if(s[i]->lateral_entery)
                {
                        printf("Yes\n");
                }
                else
                {
                        printf("No\n");
                }
                printf("10th Mark       : %d\n",s[i]->tenth_mark);
                printf("12th Mark       : %d\n",s[i]->twelth_mark);
                if(s[i]->lateral_entery==1)
                printf("Diploma Marks   : %d\n",s[i]->diploma_marks);
                if(((s[i]->semestercount>0)&&(s[i]->lateral_entery==0))||(s[i]->semestercount>2))
                {
                        printf("\nSemester Wise SGPA\n\n");
                }
                for(int j=0;j<s[i]->semestercount;j++)
                {
                        if((s[i]->lateral_entery==1)&&((j==0)||(j==1)))
                                continue;

                        printf("%d Semester      : %.1f\n",(j+1),s[i]->sgpa[j]);
                }
                printf("\n");
                printf("CGPA            : %.1f\n\n",s[i]->cgpa);
                print_semesterwise_mark(s[i]->register_number);
                printf("---------------------------------------------------------------------------------------------------\n\n");
        }
}

int main()
{
	int num;
        while(1)
	{
		printf("Press 1 : Create new student record\nPress 2 : Allocate register number for student\nPress 3 : Enter semester exam marks\nPress 4 : Enter arrear exam mark\nPress 5 : Print student details\nPress 6 : Print all the student details\nPress 7 : Arange the student in assending order wise\nPress 8 : Exit\n");
		scanf("%d",&num);
		if(num==1)
			create_record();
		else if(num==2)
		{
			int year;
			printf("Enter the year of joining ");
                        scanf("%d",&year);
			char cour[][N]={"AIDS","AIML","CSE","IT","ECE","EEE","CIVIL","MECH"};
		        int ele=sizeof(cour)/sizeof(cour[0]);
		        for(int i=0;i<ele;i++)
				register_number_allocation(cour[i],year);
		}
	        else if(num==3)
			enter_semestermark();
		else if(num==4)
			arrear_exammark();
		else if(num==5)
			print_studentdetail();
		else if(num==6)
		        print_all_student();
		else if(num==7)
		      arrange_year_department_name();
		else if(num==8)
			break;

		else
			printf("You entered an invalid option....\n");
			
	}
}

