#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FIXED_PRICE 2.5
int main(){
    FILE *fp;
    char places[100],re[100],to[100],from[100],buffer[1024],from1[100];
    int i=0;
    scanf("%s",from);
    strcpy(from1,from);
    strcat(from,"_fares.txt");
    printf("%s\n",from);
    scanf("%s",to);
    fp=fopen(from,"r");
    while(!feof(fp)){
        fscanf(fp,"%s",re);
        if(strcmp(re,to) == 0){
            while (fgets(buffer, 1024, fp) != NULL){
                if((strcmp(buffer,"\n")==0) || (strcmp(buffer,"\t\n")==0) || (strcmp(buffer," \n")==0)){
                    continue;
                }
                printf("The total distance from %s to %s is %s",from1,to,buffer);
                break;
            }
        }
    }
    float fare=atof(buffer);
    printf("Total price: %.2f",fare*FIXED_PRICE);
    fclose(fp);
}