#include<stdio.h>

struct student{
    char name[50];
    char major[35];
    float gpa;
};

int main(){
    struct student waldo = {"Waldo", "Informatika", 3.90};

    printf("Name\t: %s\n", waldo.name);
    printf("Major\t: %s\n", waldo.major);
    printf("GPA\t: %.2f\n", waldo.gpa);
}