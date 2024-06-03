#include<tools.h>

void flush(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void get_dir(char *subject, char *str){
    if(strchr(subject, '\n')){
        subject[strcspn(subject, "\n")] = 0;
    }

    strcpy(str, "test_files/");
    strcat(str, subject);
    strcat(str, ".txt");
    
}

void free_linked_list(node *head){
    node *temp = head;
    while(temp != NULL){
        head = head->next;
        free(temp);
        temp = head;
    }
}
