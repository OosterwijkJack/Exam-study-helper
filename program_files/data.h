#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <tools.h>

#define sSize 25
#define qSize 200
#define aSize 100

typedef struct node{
    char subjectName[sSize];
    char question[qSize];
    char answer[aSize];
    struct node *next;
}node;

bool addSubject();

bool addQuestions();

// randomize questions
void quiz(char *subject);

void loadQuestions(char *subject);