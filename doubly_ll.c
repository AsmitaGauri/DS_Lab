#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *llink,*rlink;
};
struct node *start=NULL,*temp=NULL,*ptr=NULL;
int choice;
void create()
{
    temp=(struct node*)malloc(sizeof(struct node));
    printf("Enter data:\n");
    scanf("%d",&temp->data);
    temp->llink=NULL;
    temp->rlink=NULL;
}
void insert_end()
{
    create();
    if(start==NULL)
        start=temp;
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL)
        {
            ptr=ptr->rlink;
        }
        ptr->rlink=temp;
        temp->llink=ptr;
    }
}
void insert_beg()
{
    create();
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        temp->rlink=start;
        start->llink=temp;
        start=temp;
    }
}
void insert_location()
{
    int count=0,pos,i;
    ptr=start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->rlink;
    }
    printf("Enter position:\n");
    scanf("%d",&pos);
    if(pos==1)
        insert_beg();
    else if(pos==count+1)
        insert_end();
    else if(pos>1&&pos<=count)
    {
        create();
        ptr=start;
        for(i=1;i<pos-1;i++)
        {
            ptr=ptr->rlink;
        }
        temp->rlink=ptr->rlink;
        ptr->rlink=temp;
        temp->llink=ptr;
        temp->rlink->llink=temp;
    }
}
void delete_end()
{
    if(start==NULL)
        printf("List is empty");
    else
    {
        ptr=start;
        while(ptr->rlink!=NULL)
        {
            temp=ptr;
            ptr=ptr->rlink;
        }
        temp->rlink=NULL;
        free(ptr);
    }
}
void delete_beg()
{
    if(start==NULL)
        printf("List is empty");
    else
    {
        ptr=start;
        start->rlink->llink=NULL;
        start=start->rlink;
        free(ptr);
    }
}
void delete_location()
{
    int count=0,pos,i;
    ptr=start;
    while(ptr!=NULL)
    {   count++;
         ptr=ptr->rlink;
    }
    printf("Enter position:\n");
    scanf("%d",&pos);
    if(pos==1)
        delete_beg();
    else if(pos>1&&pos<=count)
    {
        ptr=start;
        for(i=1;i<pos;i++)
            ptr=ptr->rlink;
        ptr->llink->rlink=ptr->rlink;
        ptr->rlink->llink=ptr->llink;
        free(ptr);

    }
}
void display()
{
    if(start==NULL)
        printf("List is empty\n");
    else
    {    ptr=start;
        printf("*****************************\n\n");
        while(ptr!=NULL)
        {
             printf("%d\n\n",ptr->data);
             ptr=ptr->rlink;
        }
        printf("*****************************\n\n");
    }
}
void main()
{
    while(1)
    {
        printf("1.INSERT_END\n\n2.INSERT_BEG\n\n3.INSERT_LOCATION\n\n4.DELETE_END\n\n5.DELETE_BEG\n\n6.DELETE_LOCATION\n\n7.DISPLAY\n\n8.EXIT\n\n");
        printf("Enter choice:\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insert_end(); break;
            case 2:insert_beg(); break;
            case 3:insert_location(); break;
            case 4: delete_end(); break;
            case 5:delete_beg();break;
            case 6:delete_location(); break;
            case 7: display(); break;
            case 8:exit(0);break;
            default:printf("Invalid");
        }
    }
}
