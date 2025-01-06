//import thu vien, khai bao struct

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#pragma once

typedef struct{
	int month,day,year;
}Date;

typedef struct{
	char id[10];
	char classroomId[10];
	char name[20];
	char Email[30];
	char Phone[20];
	char password[20];
	char gender[4];
	int numCourse;
	char course[20];
}Students;

typedef struct{
	char classroomId[10];
	char teacherId[10];
	char classroomName[10];
}Classroom;

typedef struct{
	char id[10];
	char classroomId[10];
	char name[20];
	Date dateOfBirth;
	bool gender;
	char Email[30];
	char Phone[20];
	char password[20];
	Classroom classroom[];
}Teachers;
