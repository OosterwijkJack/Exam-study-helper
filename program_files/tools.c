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

void free_linked_list(node **head){
    struct node* current = *head;
    struct node* next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    *head = NULL;
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
void clear_linked_list(node *head){
    node *temp;
    while(temp != NULL){
        temp = head->next;
        memset(&temp, 0, sizeof(temp));
        temp = NULL;
        head=temp;
    }
}

void copyLinkedList(node **dest, node *src) {
    *dest = NULL;  // Initialize dest to NULL

    node *tail = NULL;  // Tail of the new list
    node *tmp = src;

    while (tmp != NULL) {
        // Allocate memory for the new node
        node *newNode = (node*)malloc(sizeof(node));
        if (newNode == NULL) {
            // Handle memory allocation failure (optional)
            exit(1);
        }

        // Copy the data from the source node to the new node
        strcpy(newNode->question, tmp->question);
        strcpy(newNode->answer, tmp->answer);
        newNode->next = NULL;

        if (*dest == NULL) {
            // If this is the first node, set dest and tail to this node
            *dest = newNode;
            tail = newNode;
        } else {
            // Otherwise, link the new node to the end of the list and update the tail
            tail->next = newNode;
            tail = newNode;
        }

        // Move to the next node in the source list
        tmp = tmp->next;
    }
}