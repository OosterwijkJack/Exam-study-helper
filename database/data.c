#include <data.h>

node *subjectData[10];

bool addSubject(){
    char subject[sSize];
    char str[sSize];

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);

    strcpy(str, "files/");
    strcat(str, subject);
    strcat(str, ".txt");
    FILE *fptr;

    fptr = fopen(str, "w");

    if(fptr == NULL){
        return false;
    }

    fclose(fptr);

    printf("Subject added.");
    return true;
}

// add questions in format question\nanswer
bool addQuestions(){
    char subject[sSize];
    char question[qSize];
    char answer[aSize];

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);

    char dir[sSize];

    // directory str
    strcpy(dir, "files/");
    strcat(dir, subject);
    strcat(dir, ".txt");

    // check if file eixsts
    if(access(dir, F_OK) != 0){
        printf("Subject does not exist.\n");
        return false;
    }

    // get input
    printf("Enter question: ");
    fgets(question, sizeof(question), stdin);
    printf("Enter answer: ");
    fgets(answer, sizeof(answer), stdin);

    // open file
    FILE *file;
    file = fopen(dir,"a");

    if(file == NULL){
        return false;
    }

    // write str
    fprintf(file,"%s%s",question,answer);
    fclose(file);

    printf("Question added.\n");
    return true;
}