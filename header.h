#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 25
#define D 11
#define ADDRESS 50
#define ADHAR  13
#define SEMESTER 8
#define MAX 100
#define COURSECOUNT 70
#define PASSMARK 3.5
void print_semesterwise_mark(char *register_number);
void calculate_sgpa_cgpa(char *register_number);
typedef struct student
{
        char name[N];
        char fathers_name[N];
        char mothers_name[N];
        long int phonenumber;
        char nationality[N];
        char caste[N];
        char religion[N];
        char community[N];
        char bloodgroup[N];
        char gender[N];
        char date_of_birth[D];
        char adharnumber[ADHAR];
        int joind_year;
        char register_number[N];
        char course[N];
        char address[ADDRESS];
        int hosteler;
        int first_gradurate;
        char mail_id[N];
        int tenth_mark;
        int twelth_mark;
        float sgpa[SEMESTER];
        float cgpa;
	 int semestercount;
        char course_name[COURSECOUNT][N];
        int course_point[COURSECOUNT];
        int course_grade[COURSECOUNT];
        int course_semester_wisecount[SEMESTER];
        int coursecount;
        int arrearcount[COURSECOUNT];
        int lateral_entery;
        int diploma_marks;
}stu;


void dynamic_memory_allocate();
void create_record();
int departmentwise_studentcount(char *course,int year);
int particular_department_studentcount(char *course);
void register_number_allocation(char *course,int year);
void print_studentdetail();
void enter_semestermark();
void arrear_exammark();
void print_semesterwise_mark(char *register_number);
void calculate_sgpa_cgpa(char *register_number);
void arrange_year_department_name();
void print_all_student();
void  print_student_detail_index(int i);
void less_than_three_five();
void first_mark();
void copy_file_to_stru();
void copy_stru_to_file();
void retrivefile(FILE *fp);
void addfile(FILE *fp,int scou);
