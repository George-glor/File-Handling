#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int getLastId(FILE* ptr);
void printhelp();
void createMemoFile();
void appendMessage(char* message);
void searchMessage(char* message);
void deleteMessage(char* message);
