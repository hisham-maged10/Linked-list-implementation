#include <stdio.h>
#include <stdlib.h>
#define type int
typedef struct
{
    type data;
    struct node* next;
}node;
typedef struct
{
    node*head,*tail;
}llist;
//prototypes
node* newnode(type value);
void initlist(llist* list);
void addtohead(llist*list,type value);
void addtotail(llist*list,type value);
void addpos(llist*list,type value,int pos);
type deletehead(llist*list);
type deletetail(llist*list);
node* search(llist*list,type value);
node* searchrecursive(node*n,type value);
int size(llist*list);
int isempty(llist*list);
void printlinkedlist(node*n);
void printlinkedlistrecursive(node*n);
type getsum(node*n);
float getavg(node*n);
llist* copy(llist*list);
int main()
{
    llist mylist;
    initlist(&mylist);
    printlinkedlist(mylist.head);
    printf("Size: %d\n",size(&mylist));
    addtotail(&mylist,1);
    addtohead(&mylist,5);
    addtohead(&mylist,6);
    addtotail(&mylist,7);
    printlinkedlist(mylist.head);
    printf("Size: %d\n",size(&mylist));
    addpos(&mylist,10,3);
    printf("Size: %d\n",size(&mylist));
    printlinkedlist(mylist.head);
    printf("---------------------------------------\n");
    printf("Deleted from head:%d\n",deletehead(&mylist));
    printlinkedlist(mylist.head);
    printf("size:%d\n",size(&mylist));
    printf("Deleted from tail: %d\n",deletetail(&mylist));
    printlinkedlist(mylist.head);
    printf("Size:%d\n",size(&mylist));
    printf("---------------------------------------\n");
    node*result=search(&mylist,10);
    printf("Search Results:%d\n", result?result->data:-1);
    result=search(&mylist,9);
    printf("Search Results: %d\n",result?result->data:-1);
    printlinkedlist(mylist.head);
    printf("---------------------------------------\n");
    printf("Deleting the remaining elements:\n");
    while(!isempty(&mylist))
    {
        deletehead(&mylist);
    }
    printlinkedlist(mylist.head);
    printf("Size:%d\n",size(&mylist));
    return 0;
}
node* newnode(type value)
{
    node* n=(node*)malloc(sizeof(node));
    n->data=value;
    n->next=NULL;
    return n;
}
void initlist(llist*list)
{
    list->head=NULL;
    list->tail=NULL;
}
//add to the beginning
void addtohead(llist*list,type value)
{
    node*n=newnode(value);
    n->next=list->head;
    list->head=n;
    if(!list->tail)
    {
        list->tail=n;
    } //if the list is empty then tail and head should point to n which is the node u added
}
void addtotail(llist*list,type value)
{
    node*n=newnode(value);
    if(list->tail)
    {
        list->tail->next=n;
    }
    list->tail=n;
    if(!list->head)
    {
        list->head=n;
    }
}
void addpos(llist*list,type value,int pos)
{
    node*n=newnode(value);
    node*search;
    search=list->head;
    if(pos==1)
    {
        n->next=list->head->next;
        list->head=n;
    }
    int i;
    for(i=0;i<pos-2;i++)
    {
        search=search->next;
    }
    n->next=search->next;
    search->next=n;
    if(n->next==NULL)
    {
        list->tail=n;
    }

}
type deletehead(llist*list)
{
    node *first=list->head;
    if(first)
    {
        type value=first->data;
        list->head=first->next;
        free(first);
        if(list->head==NULL)
        {
            list->tail=NULL;
        }
        return value;
    }
    else
    {
        printf("[underflow] list is empty!\n");
        exit(1);
    }
}
type deletetail(llist*list)
{
    node *n=list->head;
    if(n)
    {
        while(n->next!=list->tail)
        {
            n=n->next;
        }
        node* last=list->tail;
        type value=last->data;
        list->tail=n;
        n->next=NULL;
        free(last);
        return value;

    }
    else
    {
        printf("[underflow] the list is empty!\n");
        exit(1);
    }
}
node* search(llist*list,type value)
{
    node*n=list->head;
   while(n)
   {
       if(n->data==value)
       {
           return n;
       }
       n=n->next;
   }
   return NULL;
}
node* searchrecursive(node*n,type value)
{
    if(n==NULL)
        return NULL;
    if(n->data==value)
        return n;
    else
        return searchrecursive(n->next,value);
}
int size(llist*list)
{
    node*n=list->head;
    int count=0;
    while(n)
    {
        count++;
        n=n->next;
    }
    return count;
}
int isempty(llist*list)
{

    if(list->head==NULL)
    {
        return 1;
    }
    else
        return 0;
}
void printlinkedlist(node*n)
{
    printf("[");
    while(n)
    {
        printf("%d",n->data);
        n=n->next;
    }
    printf("]\n");
}
void printlinkedlistrecursive(node *n)
{
    if(n==NULL)
        printf("\n");
    else
    {
        printf("%d",n->data);
        printlinkedlistrecursive(n->next);
    }
}
type getsum(node *n)
{
    type sum=0;
    while(n)
    {
        sum+=n->data;
        n=n->next;
    }
    return sum;
}
float getavg(node*n)
{
    type sum=0;
    int count=0;
    while(n)
    {
        sum+=n->data;
        count++;
        n=n->next;
    }
    return (float)sum/count;
}
llist* copy(llist*list)
{
    llist*list2=malloc(sizeof(llist));
    initlist(list2);
    node *n=list->head;
    while(n)
    {
        addtotail(&list2,n->data);
        n=n->next;
    }
    return list2;
}


