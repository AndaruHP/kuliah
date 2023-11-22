#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    FILE *fp = fopen("text.txt", "r");
    
    char line[100], *token;

    while(fgets(line, sizeof(line), fp) != NULL){
        token = strtok(line, "$^@#%&*)");
        printf("%s\n", token);
        token = strtok(NULL, "$^@#%&*)");
        
        printf("%s\n", token);
        
        token = strtok(NULL, "$^@#%&*)");
        printf("%s\n", token);
    }
}