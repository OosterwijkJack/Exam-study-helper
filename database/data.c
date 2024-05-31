#include <data.h>

node *subjectData[10];

bool addSubject(){

    printf("Enter subject name: ");
    char subject[sSize];

    char str[sSize];

    fgets(subject, sSize, stdin);

    strcpy(str, "files/");
    strcat(str, subject);
    FILE *fptr;

    printf("%s\n", str);

    fptr = fopen(str, "w");

    if(fptr == NULL){
        return false;
    }

    return true;
}

bool addQuestions(char *subject, char *question, char *answer){
    
}