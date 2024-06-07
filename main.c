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

        // remove any newline characters from stdin buffer
        flush();
    
        cmp = atoi(choice);
        

        switch(cmp){
        case 1:
            addSubject();
            break;
        case 2:
            addQuestions();
            break;
        case 3:
            loadQuestions("Biology");
            randomizeData();
            quiz();
            break;
        case 0:
            return false;
        default:
            printf("Invalid option.\n");
            break;
        }

        sleep(2);
        system("clear");

    }
    unloadQuestion();
    
}
