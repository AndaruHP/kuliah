#include<stdio.h>
#include<string.h>

struct student{
    char name[50];
    char major[35];
    float gpa;
};

struct student newstudent(char name[], char major[], float gpa){
    struct student s;
    strcpy(s.name, name);
    strcpy(s.major, major);
    s.gpa = gpa;

    return s;
};

int main(){
    struct student waldo = newstudent("Waldo", "Informatika", 3.90);

    printf("Name\t: %s\n", waldo.name);
    printf("Major\t: %s\n", waldo.major);
    printf("GPA\t: %.2f\n", waldo.gpa);
}