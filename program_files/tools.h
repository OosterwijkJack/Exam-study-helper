#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#pragma once

#define sSize 25
#define qSize 200
#define aSize 100

typedef struct node{
    char question[qSize];
    char answer[aSize];
    struct node *next;
}node;


void flush();
void get_dir(char *subject, char *str);
void free_linked_list(node *head);
