#include<stdio.h>

struct student{
    char name[50];
    char major[35];
    float gpa;
};

int main(){
    struct student waldo = {"Waldo", "Informatika", 3.90};
    struct student *waldoPtr = &waldo;

    printf("Without Pointer\n");
    printf("Name\t: %s\n", waldo.name);
    printf("Major\t: %s\n", waldo.major);
    printf("GPA\t: %.2f\n", waldo.gpa);

    printf("\nWith Pointer\n");
    printf("Name\t: %s\n", waldoPtr->name);
    printf("Major\t: %s\n", waldoPtr->major);
    printf("GPA\t: %.2f\n", waldoPtr->gpa);
}