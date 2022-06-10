#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FIXED_PRICE 2.5
int main(){
    FILE *fp,*fp1;
    float count=0;
    // printf("here");
    char places[100],re[100],buffer[1024],name[100],ch;
    char re1[100],buffer1[1024],from1[100],from[100],to[100];
    scanf("%s",from);
    scanf("%s",to);
    strcpy(from1,from);
    strcat(from1,"_fares.txt");
    fp=fopen("4_23ll8ll2022.txt","r");
 
    while(!feof(fp)){ 
        fscanf(fp,"%s",re);
        
        if(strcmp(re,"Name_of_the_passenger:") == 0){
            count++;
        }
    }
    printf("\n%f",count);

    fp1=fopen(from1,"r");
    while(!feof(fp1)){
        fscanf(fp1,"%s",re);
        if(strcmp(re,to) == 0){
            while (fgets(buffer, 1024, fp1) != NULL){
                if((strcmp(buffer,"\n")==0) || (strcmp(buffer,"\t\n")==0) || (strcmp(buffer," \n")==0)){
                    continue;
                }
                printf("The total distance from %s to %s is %s",from,to,buffer);
                break;
            }
        }
    }
    float fare=atof(buffer);
    printf("\n%f",fare);
    printf("The total revenue generated = %f",fare*FIXED_PRICE*count);
}