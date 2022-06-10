#include<stdio.h>
#include<stdio.h>
#include<string.h>
struct employee{
    int empId;
    char empName[100],empPhoNo[100],empAge[10];
    char empAddress[1000],empSalary[100],empBusId[10],empPost[100];
    struct employee *rchild,*lchild;
};
int c=0;
struct employee *newNode;
struct employee* insert(struct employee *,int);
struct employee *inorder(struct employee*,int,int);
struct employee *delete_node(struct employee*,int);


struct employee* getNode(int id){
    newNode=(struct employee *)malloc(sizeof(struct employee));
    newNode->empId=id;
    printf("Enter the post of the employee: \n");
    scanf("%s",newNode->empPost);
    printf("Enter the name of the employee: \n");
    scanf("%s",newNode->empName);
    printf("Enter the phone Number of the employee: \n");
    scanf("%s",newNode->empPhoNo);
    printf("Enter the age of the employee: \n");
    scanf("%s",newNode->empAge);
    printf("Enter the address of the employee: \n");
    scanf("%s",newNode->empAddress);
    printf("Enter the bus ID for the employee: \n");
    scanf("%s",newNode->empBusId);
    printf("Enter the salary for the employee: \n");
    scanf("%s",newNode->empSalary);
    newNode->lchild = NULL;
	newNode->rchild = NULL;
	return(newNode);
}

int main(){
    int c1;
    int n,id,eid,e1id;
    struct employee *root=NULL;
    while (1){
        printf("\n\n1.Add Employee\n2.Employee Information\n3.Employee Deletion\n");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("Enter the id of the employee: ");
                scanf("%d",&id);
                root = insert(root,id);
                c++;
                break;
            case 2:
                c1=-1;
                printf("Enter the id of the employee: ");
                scanf("%d",&e1id);
                inorder(root,e1id,c1);
                break;
            case 3:
                printf("Enter the id of the employee: ");
                scanf("%d",&eid);
                delete_node(root,eid);
                c--;
                printf("\n\nDetails deleted!!");
                break;
        }
    }
    return(0);
    
}

struct employee* insert(struct employee *root,int id){
    struct employee *temp=root;
    if(root == NULL){
        root = getNode(id);
        return(root);
    }
    while(1){
        if(temp->empId>id){
            if(temp->lchild==NULL){
                temp->lchild=getNode(id);
                break;
            }
            else{
                temp=temp->lchild;
            }
        }
        else{
            if(temp->rchild==NULL){
                temp->rchild=getNode(id);
                break;
            }
            else{
                temp=temp->rchild;
            }
        }
    }
    return(root);
}

struct employee *inorder(struct employee *root,int id,int count){
    count++;
    if(count==c){
        printf("details not found!!");
        return;
    }
    if(id == root->empId){
        printf("\n\nName = %s",root->empName);
        printf("\nEmployeeID = %d",root->empId);
        printf("\nDesignation = %s",root->empPost);
        printf("\nAge = %s",root->empAge);
        printf("\nPhoneNumber = %s",root->empPhoNo);
        printf("\nAddress = %s",root->empAddress);
        printf("\nSalary = %s",root->empSalary);
        printf("\nBusID = %s",root->empBusId);
        return;
    }    
    else if(root->empId > id){
        inorder(root->lchild,id,count);
    }
    else if(root->empId < id){
        inorder(root->rchild,id,count);
    }
        
}




struct employee* delete_node(struct employee *root,int id){
    if (root == NULL)
    return root;
    if (id < root->empId)
    root->lchild = delete_node(root->lchild,id);
    else if (id > root->empId)
    root->rchild = delete_node(root->rchild,id);
    else{
        if (root->lchild == NULL){
            struct employee *temp = root->rchild;
            free(root);
            return temp;
        }
        else if (root->rchild == NULL){
            struct employee *temp = root->lchild;
            free(root);
            return temp;
        }
    }
}    