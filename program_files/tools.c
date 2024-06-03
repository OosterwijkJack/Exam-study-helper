#include<tools.h>

void flush(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void get_dir(char *subject, char *str){
    strcpy(str, "test_files/");
    strcat(str, subject);
    strcat(str, ".txt");
}
