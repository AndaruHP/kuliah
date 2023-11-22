#include<stdio.h>

typedef struct {
    char name[50];
    char position[20];
    int dateJoined;
    int workDuration;
    int salary;
} Employee;

int main(){
    int i = 0;
    Employee employees[3];

    FILE *fp = fopen("data.txt", "w");
    while(!feof(fp)){
        Employee newEmp;
        fscanf(fp, "%[^#]#%[^#]#%d#%d#%d\n", newEmp.name, newEmp.position, &newEmp.dateJoined, &newEmp.salary, &newEmp.workDuration);
        employees[i] = newEmp;
        i++;
    }
    fclose(fp);

    for(i = 0; i < 3; i++){
        printf("Employee #%d\n", i + 1);
        printf("Nama\t\t: %s\n", employees[i].name);
        printf("Position\t\t: %s\n", employees[i].position);
        printf("Date joined\t\t: %d\n", employees[i].dateJoined);
        printf("Work Duration\t\t: %d\n", employees[i].workDuration);
        printf("Salary\t\t: %d\n", employees[i].salary);
    }
}