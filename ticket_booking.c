#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"seat.h"
struct bus{
    char From[50];
    char To[50];
    char DriverName[50];
    char Type[50];
    char BUSID[10];
}s;
void add_bus();
void ticket_display();
int main(){
    int var;
    do
    {
        printf("\n1.ADD BUS\n2.TICKET INFO\n3.Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d",&var);
        switch(var)
        {
            case 1:
                add_bus();
                break;
            case 2:
                ticket_display();
                break;
            case 3:
                break;
            default:
                printf("Enter Correct Choice\n");
                break;
        }
        
    }while(var!=3);
    return 0;
}

void add_bus(){
    FILE *fp,*fp1;
    int count=0,flag=0,n;
    char m[50]="FROM:",p[50]="TO:",d[50]="DRIVER NAME:",t[50]="TYPE:",b[10]="BUS ID:"; //predefined in file... 
    char from[50],to[50],driver[50],type[50],bid[10]; //user credentials gets appended
    printf("\t\t\t*ADD BUS*\t\t\t\n");
    fp=fopen("BUS.txt","a");
    printf("Enter n:");
    scanf("%d",&n);
    fprintf(fp,"%d\n",n);
    printf("Enter From:\n");
    fflush(stdin);
    gets(from);//or use scanf
    fp1=fopen("BUS.txt","r");
    fclose(fp1);
    if(flag==1){
        return;
    }
    strcat(m,from);
	fprintf(fp,"%s",m);
    printf("Enter To:\n");
    fflush(stdin);
    gets(to);
    strcat(p,to);
	fprintf(fp,"\n%s",p);
	printf("Enter Driver Name:\n");
	fflush(stdin);
	gets(driver);
	strcat(d,driver);
	fprintf(fp,"\n%s",d);
	printf("Enter Type:\n");
	fflush(stdin);
	gets(type);
	strcat(t,type);
	fprintf(fp,"\n%s",t);
	printf("Enter Bus Id:\n");
	fflush(stdin);
	gets(bid);
	strcat(b,bid);
	fprintf(fp,"\n%s",b);
	fprintf(fp,"\n*********\n");
	printf("\nBus Added Successfully!!\n\n");
    fclose(fp);
}


//////////////////////// reservation la pettali ra ....///////////////////////////


void ticket_display(){
	FILE *fp;
    char from[100],from1[100],to[100];
    printf("Enter FROM: ");
    scanf("%s",from);
    strcpy(from1,from);
    // printf("%s",from1);
    char buffer[100];
    int size=100;
	char ch[size];
    strcat(from,".txt");
	fp=fopen(from,"r");
    char d[10],re[100];
	printf("Enter to: ");
	scanf("%s",d);
    strcpy(to,d);
	printf("\t\t\t*TICKET DISPLAY*\t\t\t\n");
//	FILE *fp = fopen("BUS.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s",re);
		if(strcmp(re,d) == 0)
		{
			while(1)
			{
				char ch = fgetc(fp);
				if(ch == '*')
				{
					break;
				}
				printf("%c",ch);
			}
		}
	}
	fclose(fp);
    seat(from1,d);
}