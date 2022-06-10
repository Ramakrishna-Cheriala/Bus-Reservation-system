#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define FIXED_PRICE 2.5
int main(){
    FILE *fp;
    int count=0;
    char places[100],re[100],buffer[1024],name[100],ch;
    fp=fopen("4_23ll8ll2022.txt","r");
    while(!feof(fp)){ 
        // fscanf(fp,"%s",re);
        
        if(strcmp(re,"Name_of_the_passenger:") == 0){
            printf("%s",re);
            count++;
        }
    }
    printf("\n%d",count);
}
