#include <data.h>

node *subjectData;

bool addSubject(){
    system("clear");
    char subject[sSize];
    char str[sSize];

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);

    get_dir(subject, str);
    FILE *fptr;

    fptr = fopen(str, "w");

    if(fptr == NULL){
        return false;
    }

    fclose(fptr);

    printf("Subject added.\n");
    return true;
}

// add questions in format question\nanswer
bool addQuestions(){
    system("clear");
    char subject[sSize] = "\0";
    char question[qSize] = "\0";
    char answer[aSize] = "\0";

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);

    char dir[sSize];

    // directory str
    strcpy(dir, "test_files/");
    strcat(dir, subject);
    strcat(dir, ".txt");

    // check if file eixsts
    if(access(dir, F_OK) != 0){
        printf("Subject does not exist.\n");
        return false;
    }

    while(question != "q"){
        // get input
        printf("Enter question (q to exit): ");
        fgets(question, sizeof(question), stdin);
        question[strcspn(question, "\n")] = 0;

        if(strcmp(question, "q") == 0){
            break;
        }

        printf("Enter answer: ");
        fgets(answer, sizeof(answer), stdin);
        answer[strcspn(answer, "\n")] = 0;

        // open file
        FILE *file;
        file = fopen(dir,"a");

        if(file == NULL){
            return false;
        }

        // write str
        fprintf(file,"%s\n%s\n",question,answer);
        fclose(file);

        printf("Question added.\n\n");
    }
    return true;
    
}

void loadQuestions(char *subject){
    
}
