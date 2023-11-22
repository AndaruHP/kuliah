#include<stdio.h>
#include<string.h>

struct course{
    char cname[50];
    int sks, assignment, midexam, finalexam;
    float score;
};

struct student{
    char name[50];
    char major[35];
    float gpa;
    struct course algorithm, multimedia;
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

    strcpy(waldo.algorithm.cname, "Algorithm and Data Structure");
    waldo.algorithm.sks = 3;

    printf("%s\n\n", waldo.algorithm.cname);
    printf("Assignment\t: "); scanf("%d", &waldo.algorithm.assignment);
    printf("Mid Exam\t: "); scanf("%d", &waldo.algorithm.midexam);
    printf("Final Exam\t: "); scanf("%d", &waldo.algorithm.finalexam);

    waldo.algorithm.score = 0.3 * waldo.algorithm.assignment + 0.3 * waldo.algorithm.midexam + 0.4 * waldo.algorithm.finalexam;
    printf("Final score\t: %.2f\n", waldo.algorithm.score); 

    
}