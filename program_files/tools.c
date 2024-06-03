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

void shuffle(int *array, size_t n)
{
    srand(time(NULL));

    // Fisher-Yates shuffle algorithm
    for (int i = n - 1; i > 0; i--) {
        // Generate a random index j such that 0 <= j <= i
        int j = rand() % (i + 1);

        // Swap array[i] with the element at the random index
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }
}