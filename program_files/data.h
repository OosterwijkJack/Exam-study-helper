#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <tools.h>

#pragma once

bool addSubject();

bool addQuestions();

// randomize questions
void quiz(char *subject);

bool loadQuestions(char *subject);

bool randomizeData();
