#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head=NULL,*ptr=NULL,*temp=NULL;
int choice;

void create()
{
    temp=(struct node*)malloc(sizeof( struct node));
    printf("Enter data:\n");
    scanf("%d",&temp->data);
    temp->link=NULL;
}

void insert_end()
{  create();
   if(head==NULL)
    head=temp;
   else
   {
       ptr=head;
       while(ptr->link!=NULL)
       {
           ptr=ptr->link;
       }
       ptr->link=temp;
   }

}
void insert_beg()
{
    create();
    if(head==NULL)
        head=temp;
    else
    {
        temp->link=head;
        head=temp;
    }
}
void insert_location()
{
    int count=0,pos,i;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
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
        ptr=head;
        for(i=1;i<pos-1;i++)
            ptr=ptr->link;
        temp->link=ptr->link;
        ptr->link=temp;
    }
}
void delete_end()
{
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        temp->link=NULL;
        free(ptr);
    }
}
void delete_beg()
{
    if(head==NULL)
        printf("List is empty\n");
    else
    {
        ptr=head;
        head=head->link;
        free(ptr);
    }
}
void delete_location()
{
    int count=0,pos,i;
    ptr=head;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->link;
    }
    printf("Enter position:\n");
    scanf("%d",&pos);
    if(pos==1)
        delete_beg();
    else if(pos>1&&pos<=count)
    {
        ptr=head;
        for(i=1;i<pos;i++)
        {
            temp=ptr;
            ptr=ptr->link;
        }
        temp->link=ptr->link;
    }
}
void display()
{
    if(head==NULL)
        printf("List is empty\n");
    else
    {    ptr=head;
         printf("*****************************\n\n");
        while(ptr!=NULL)
        {
            printf("%d\n",ptr->data);
            ptr=ptr->link;
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
            case 1:insert_end(); break;       /* points to remember->>while!=NULL only for display and count
                                                pos-1 only for insert and pos for delete*/
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

