#include<stdio.h>
#include<strings.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

typedef struct node
{
  char name[222];
  char pre[222];
  struct node *next;
}stud;

int n;
char str[3000][3000];

void outputlist(stud *node){
    while (node->next != NULL)
    {
        printf("%s -> ", node->name);
        node = node->next;
    }
    printf("%s",node->name);
}

//function to compare two adjacent strings

int check2(char a[], char b[])
{
    int k=0;
    for(int i=0; a[i]!='\0' ||b[i]!='\0'; i++)
    {
        if(a[i]==b[i])
            k++;
        else
        {
            k++;
            break;
        }   
    }
    
    return k;
}

void printfun(stud *node)
{
    while (node->next != NULL)
    {
         printf("%s -> ", node->pre);
         node = node->next;
    }
    printf("%s",node->pre);
}

//Dictionary order
void orderalp(stud *head)
{
        stud *word = head, *index = NULL;
        char a[100];
        char b[100];
        if(head == NULL) {  //base case
            return;
        }
        else {
            while(word != NULL) {
                index = word->next;
                while(index != NULL) {
                    //Checking if current node is ahead in dictionary order
                    if(strcmp(word->pre,index->pre)>0)
                    {
                         //swapping prefix
                        strcpy(a,word->pre);
                        strcpy(word->pre,index->pre);
                        strcpy(index->pre,a);
                        //swapping name
                      memcpy(b,word->name, strlen(word->name)+1);
                        memcpy(word->name,index->name, strlen(index->name)+1);
                        memcpy(index->name,b, strlen(b)+1);
                    }
                    index = index->next;
                }
                word = word->next;
            }
        }
    }

int main()
{
    printf("no. of persons : ");
    scanf("%d",&n);
    printf("name of persons : ");
    for(int i=0;i<n;i++)
    {
        
        scanf("%s",str[i]);
    }
   int a,b;
   for(int i=0;i<n;i++){
   for(int j=i+1;j<n;j++){
   a=strcmp(str[i],str[j]);
   if(a==0){printf("ERROR Names are not unique");b=0;}}
   }

if(b!=0)
 {
    char pre[n][100];                        
    for(int i=0;i<n;i++) pre[i][0]='\0';        


  for(int i = 0; i < n; i++) // to get prefix
  {
    int ind=0;
      for(int j =0; j < n; j++)
      {
          if(i!=j)
          {
              int k = check2(str[i], str[j]);
             if(k > ind)
                  ind = k;
          }
      }
      int j=0;
      for(; str[i][j] != '\0' && j < ind ; j++)
          strncat(pre[i],&str[i][j],1);

  }

    //linked list
    stud* head = NULL,*prev;
    for(int i=0;i<n;i++)
    {
        stud *p=(stud *)malloc(sizeof(struct node));

        memcpy(p->pre, pre[i], strlen(pre[i])+1); 
        memcpy(p->name, str[i], strlen(str[i])+1); 

        p->next=NULL;
        if(head == NULL)
        {
            head=p;
            prev=head;
        }
        else
        {
         prev->next=p;
         prev=p;
        }
    }
    printf("\nOutput 1: ");
    printfun(head);
    orderalp(head);
    printf("\nOutput 2: ");
    printfun(head);
    printf("\nOutput 3: ");
    outputlist(head);
    printf("\n");
  return 0;}
}
