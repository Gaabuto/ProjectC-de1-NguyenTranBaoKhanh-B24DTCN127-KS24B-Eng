//khai bao nguyen mau ham


#include "datatype.h"
#pragma once
void clearScreen();
void admin();
void saveStudent(Students students[],int countS);
void loadStudent(Students students[],int *countS);
void loadTeachers(Teachers teachers[], int countT);
void saveTeacher(Teachers teachers[], int countT);



void managementStudent();
void addStudents(Students students[], int *countS);
void showStudents(Students students[], int countS);
void searchStudents(Students students[], int countS);
void editStudents(Students students[], int countS);
void deleteStudents(Students students[], int *countS);
void sortStudents(Students students[], int countS);


void managementTeachers(Teachers teacher[]);
void addTeachers(Teachers teachers[]);
void showTeachers(Teachers teachers[]);
void searchTeachers(Teachers teachers[]);
void editTeachers(Teachers teachers[]);
void deleteTeachers(Teachers teachers[]);
void sortTeachers(Teachers teachers[]);


void managementClassrooms(Classroom classroom[]);
void addClassroom(Classroom classroom[]);
void showClassroom(Classroom classroom[]);
void searchClassroom(Classroom classroom[]);
void editClassroom(Classroom classroom[]);
void deleteClassroom(Classroom classroom[]);
void sortClassroom(Classroom classroom[]);
void addstudentinclass(Classroom classroom[]);
void deletestudentinclass(Classroom classroom[]);
void roleTeacher();
void roleStudent();


