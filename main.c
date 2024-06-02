#include <stdio.h>
#include <data.h>

/* 
This program helps study for exams 

- add subject to the database
- questions with answers nodes in subject database

- able to append to certain databases
- be able to randomize questions and answers 

- display questions, when finished question you go to next
- display answer
- next question 

*/
void flush();


int main(void){
    char choice[2] = "\0";
    int cmp = -1;
    while(cmp != 0 ){
        
        printf("Welcome to exam study helper!!\n");
        printf("\n1. Add subject");
        printf("\n2. Add questions");
        printf("\n3. Test myself");
        printf("\nEnter choice (0 to exit): ");

        // get user choice
        fgets(choice,sizeof(choice),stdin);
        choice[strcspn(choice, "\n")] = '\0';

        // remove any newline characters from stdin buffer
        flush();
    
        cmp = atoi(choice);

        if(cmp == 1){
           addSubject();
        }
        else if(cmp == 2){
            addQuestions();
        }
        else if(cmp != 0){
            printf("Invalid input.\n");
        }
        //sleep(2);
       // system("clear");
    }
    
}
void flush(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
