#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"memo.h"

int getLastId(FILE* ptr){
    int lastid=0;
    int bufferLength = 1024;
    char lastmessage[bufferLength];
    char buffer[bufferLength];
    while(fgets(buffer, bufferLength, ptr)) {      
        sscanf( buffer, "%d,%s", &lastid, lastmessage);
      
    }
        
    return lastid;
    }
void printhelp(){
 printf("-h Show this help.\n");
        printf("-i Init a new empty database. For example:\n");
        printf("memo -i \"memo.csv\"\n ");
        printf("Create a new empty database with the name \"memo.csv\"\n");
        printf("-a Append at the end of the database the following message.\n");
        printf("memo -a \"This message will be included at the end of the database\"\n");
        printf("-s Search and find specific entries in the database.\n");
        printf("memo -s \"09-11-2022\" will show all entries at a this given date.\n");
        printf("memo -s \"programming\" will show all entries containing the word\n");
        printf("\"programming\".\n");
        printf("-d Delete an entry in the database.\n");
        printf("memo -d 123 will delete entry number 123.");    
}

void createMemoFile(){
                FILE *ptr;
		ptr = fopen("memo.csv","w");
          
            fclose(ptr);
}

void appendMessage(char* message){
    FILE *ptr;
            ptr = fopen("memo.csv","a+");
            // id = fopen("id.txt","r");
            int i= getLastId(ptr);
            i++;
            // fscanf(id,"%d",&i);
            char timestr[256];
                time_t t = time(NULL);
                struct tm tm = *localtime(&t);
            sprintf(timestr,"%d-%02d-%02d %02d:%02d:%02d",tm.tm_mday, tm.tm_mon + 1,tm.tm_year + 1900, tm.tm_hour, tm.tm_min, tm.tm_sec);
            fprintf(ptr,"%d,%s,%s\n",i,timestr,message);
            // fprintf(ptr,"%s\n",argv[2]);


            fclose(ptr);
}

void searchMessage(char* message){
    FILE *ptr;
            ptr = fopen("memo.csv","r"); 
            if(ptr){
   int bufferLength = 1024;
    char buffer[bufferLength];
    while(fgets(buffer, bufferLength, ptr)) {      
        if(strstr(buffer, message)){
            printf("%s", buffer);
            }   
 
        }
      
    }
        
    }

void deleteMessage(char* message){
    FILE *ptr;
            ptr = fopen("memo.csv","r"); 
            if(ptr){
                 FILE *ptr2;
            ptr2 = fopen("memotemp.csv","w+"); 
   int bufferLength = 1024;
    char buffer[bufferLength];
    while(fgets(buffer, bufferLength, ptr)) {      
        if(! strstr(buffer, message)){
            fprintf(ptr2,"%s", buffer);
            }   
 
        }
      fclose(ptr);
      fclose(ptr2);
    }
        remove("memo.csv");
        rename("memotemp.csv","memo.csv");
    }
