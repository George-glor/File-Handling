#define _GNU_SOURCE
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include "memo.h"


int main(int argc, char **argv){

   
    if(argc==2){ 
        if(strcmp(argv[1],"-h")==0){
      printhelp();
    return 0;
        }
    else if(strcmp(argv[1],"-i")==0){
        createMemoFile();

           
            return 0;
            
        }    
    else
    {
        printf("wrong argument\n");
        printf("use -h to see help\n");
        return -1;
    }
    }
    else if(argc==3){
        if(strcmp(argv[1],"-a")==0){
            appendMessage(argv[2]);
            
          
            
            return 0;
        }
        else if(strcmp(argv[1],"-s")==0){
            searchMessage(argv[2]);
        }
        else if(strcmp(argv[1],"-d")==0){
            deleteMessage(argv[2]);
        }
        else
    {
        printf("wrong argument\n");
        printf("use -h to see help\n");
        return -3;
    }    
    }


    return 0;
}