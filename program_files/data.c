#include <data.h>

node *subjectData = NULL;
int ncount = 0;

#define ANSI_COLOR_GREEN    "\x1b[32m"
#define ANSI_COLOR_RESET   "\x1b[0m"

bool addSubject(){
    system("clear");
    char subject[sSize];
    char str[sSize];

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);

    get_dir(subject, str);
    printf("%s\n", str);
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
    get_dir(subject, dir);

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

bool loadQuestions(){
    ncount = 0;
    char subject[sSize];

    printf("Enter subject: ");
    fgets(subject, sizeof(subject), stdin);

    if(subjectData != NULL)
        free_linked_list(&subjectData);

    char dir[sSize];
    get_dir(subject,dir);

    // check if file eixsts
    if(access(dir, F_OK) != 0){
        printf("Subject does not exist.\n");
        return false;
    }
    system("clear");
    // open file
    FILE *file;
    file = fopen(dir, "r");
    if(file == NULL){
        return false;
    } 

    // read question and answer
    char question[qSize] = "\0";
    char answer[aSize] = "\0";

    while(fgets(question, sizeof(question), file) && fgets(answer, sizeof(answer), file)){
        // remove \n
        question[strcspn(question, "\n")] = 0;
        answer[strcspn(answer, "\n")] = 0;

        // make space for new node
        node *new = malloc(sizeof(node));

        strcpy(new->question, question);
        strcpy(new->answer, answer);
        new->next = subjectData;
        subjectData = new;
        ncount++;
    }

    fclose(file);
    return true;
}
bool randomizeData(){
    if(subjectData == NULL){
        return false;   
    }

    // shuffle
    int shuffle_array[ncount];

    for(int i = 0; i <ncount; i ++){
        shuffle_array[i] =  i;
    }

    shuffle(shuffle_array, ncount);

    node *temp_ptr = NULL;
    node *new;
    for(int i = 0; i <ncount; i ++){

        node *swp_ptr = subjectData;
        for(int j = 0; j <shuffle_array[i]; j ++){
            swp_ptr = swp_ptr->next;
        }

        new = malloc(sizeof(node));
        strcpy(new->question, swp_ptr->question);
        strcpy(new->answer, swp_ptr->answer);
        new->next = temp_ptr;
        temp_ptr = new;
    }   
    free_linked_list(&subjectData);
    subjectData = temp_ptr;

    return true;
}
bool quiz(){

    node *ptr = subjectData;
    char answer[aSize] = "\0";
    char empty_buffer[sSize];
    while(ptr != NULL){
        printf("\nquestion: %s\n", ptr->question);
        printf("\nEnter answer: ");
        fgets(answer, sizeof(answer), stdin);

        printf(ANSI_COLOR_GREEN "Answer: %s\n" ANSI_COLOR_RESET, ptr->answer);
        printf("\nEnter to continue...");
        fgets(empty_buffer, sizeof(empty_buffer), stdin);
        system("clear");

        ptr = ptr->next;
    }
    free_linked_list(&subjectData);
    return true;
}
bool unloadQuestion(){
    free_linked_list(&subjectData);
    return true;
}