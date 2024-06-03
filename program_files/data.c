#include <data.h>

node *subjectData = NULL;
int ncount = 0;

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

bool loadQuestions(char *subject){
    ncount = 0;
    free_linked_list(&subjectData);

    char dir[sSize];
    get_dir(subject, dir);

    // check if file eixsts
    if(access(dir, F_OK) != 0){
        printf("Subject does not exist.\n");
        return false;
    }

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

    node *node_list[ncount];

    node *tmp1 = subjectData;
    node *tmp2 = tmp1->next;
    // unload linked list as array
    for(int i = 0; i<ncount; i++){
        tmp1->next = NULL;
        node_list[i] = tmp1;

        tmp1 = tmp2;

        if(tmp2->next != NULL)
            tmp2 = tmp2->next;
    }   
    // shuffle
    int shuffle_array[ncount];

    for(int i = 0; i <ncount; i ++){
        shuffle_array[i] =  i;
    }

    shuffle(shuffle_array, ncount);

    node *shuffled_node_list[ncount];
    for(int i = 0; i <ncount; i++){
        shuffled_node_list[shuffle_array[i]] = node_list[i];
    }
    //reload

    free_linked_list(&subjectData);
    for(int i = 0; i <ncount; i++){
        shuffled_node_list[i]->next = subjectData;
        subjectData = shuffled_node_list[i];
    }

    node *ptr = subjectData;
    while(ptr != NULL){
        printf("question: %s\nanswer: %s\n", ptr->question, ptr->answer);
        ptr = ptr->next;
    }
}