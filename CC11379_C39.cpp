//ahmad solehin
#include <stdio.h>
#include <stdlib.h>


struct btree_node
{
    int id;
    char name[30];
    int subordinate1,subordinate2;
    struct btree_node *subor1, *subor2;
};
struct btree_node *rootptr,*newptr,*currentptr,*previousptr,*tmpptr;

btree_node* SEARCH(btree_node *,int);
void INSERT(int);
void INORDER (btree_node *);
void DELETE (int);
btree_node* COPY(btree_node *);

int main ()
{

   int element,choice;
   rootptr=NULL;

   while (choice !=0)
   {

     printf("\n\n-----------------Multi-Level-Marketing (MLM) MENU-----------");
     printf("\n\n 0: Quit");
     printf("\n 1: Search Member");
     printf("\n 2: Insert Member");
     printf("\n 3: Display Member");
     printf("\n 4: Delete Member");
     printf("\n\n Enter your choice: ");
     scanf("\t%d",&choice);

         switch(choice)
         {
          	case 1 : printf("\n SEARCH Member");
            			printf("\n Enter the searching member id number:");
            			scanf("%d", &element);
                     tmpptr = SEARCH(rootptr,element);
                     if(tmpptr!= NULL){
                     printf("\n The member id %d is found",tmpptr->id);
                        printf("\nMember Id\tName\tSubordinate1\tSubordinate2");
                     printf("\n%d", tmpptr->id);
                     printf("\t%s",tmpptr->name);
                     printf("\t%d",tmpptr->subordinate1);
                     printf("\t%d",tmpptr->subordinate2);
                     break;}

                     else{
                     printf("\n The member id %d is not found\n", element);
                     system("\npause");
                     system("cls");
                     break;}

         	case 2 : printf ("\n Insert");
            		   printf("\n Enter a Member Id : ");
                 		scanf("%d",&element);
                 		INSERT(element);
                 		printf ("\n Insertion is successful\n");
                 		system("\npause");
                     system("cls");
                 		break;

         	case 3 : printf("\n Display All Team Member\n\n");
         	    printf("\nMember Id\tName\tSubordinate1\tSubordinate2");

                     INORDER(rootptr);
                  	break;

         	case 4 : printf ("\n Delete Team Member");
                 		printf("\n Enter a Member Id to delete: ");
                 		scanf("%d",&element);
                 		DELETE(element);
                 		break;

            default: printf("\n Please enter number only from the MENU\n");
                      system("pause");
                      system("cls");


         }
   }

}

void INSERT(int number)
{
   newptr = (struct btree_node*) malloc (sizeof(struct btree_node));
   newptr->subor1 = NULL;
   newptr->subor2 = NULL;
   newptr->id = number;

   printf("\nEnter name : ");
   scanf(" %s", &newptr->name);

   printf("\nEnter subordinate 1 : ");
   scanf(" %d", &newptr->subordinate1);

   printf("\nEnter subordinate 2 : ");
   scanf(" %d", &newptr->subordinate2);

   currentptr =rootptr;
   while (currentptr!=NULL) //search the location to insert
   {
      previousptr = currentptr;

      if (number > currentptr->id)
         currentptr = currentptr->subor2;
      else
         currentptr = currentptr->subor1;
   }

   if (rootptr==NULL)
      rootptr = newptr;
   else if (number > previousptr->id)
      previousptr->subor2 = newptr;
   else
      previousptr->subor1 = newptr;
}

void INORDER (btree_node *node)
{
   if (node!=NULL)
   {

      INORDER(node->subor1);
      printf("\n  %d",node->id);
      printf("\t\t%s",node->name);
      printf("\t %d",node->subordinate1);
      printf("\t\t%d",node->subordinate2);
      INORDER(node->subor2);
   }

}

btree_node* SEARCH(btree_node *node,int number)
{
 	if(node!=NULL)// node is not null
   {
    	if(number == node->id)
      	return node;

      else if(number > node->id)
      	return SEARCH(node->subor2,number);

      else
      	return SEARCH(node->subor1,number);
   }

   else
   	return NULL;

}

void DELETE(int number)
{
   currentptr = rootptr;

   while (currentptr!=NULL)//search the node to delete
   {
      if (currentptr->id == number)
         break;

      previousptr = currentptr;//previousptr hold the address of node to delete

      if (number > currentptr->id)
         currentptr = currentptr->subor2;
      else
         currentptr = currentptr->subor1;
   }

   if (currentptr==NULL)
     { printf ("\n Member id %d is not in the tree!!!",number);
       return;
     }

   else if (currentptr->id == number)
      {	if (currentptr == rootptr)
         	rootptr=COPY(rootptr);
      	else if (previousptr->subor1 == currentptr)
           previousptr->subor1=COPY(previousptr->subor1);
      	else
           previousptr->subor2=COPY(previousptr->subor2);
      }

}

btree_node* COPY (btree_node *node)
{
   struct btree_node *previousptr2;
   tmpptr=node;

   if(node->subor2==NULL)//no right node
      node = node->subor1;

   else if (node->subor1==NULL)//no left node
      node = node->subor2;

   else
     {
      tmpptr = node->subor1;
      previousptr2 =node;
      	while (tmpptr->subor2!=NULL) //find the rightmost node of the left subtree
      	{
         	previousptr2 = tmpptr;
         	tmpptr = tmpptr->subor2;
      	}

      node->id = tmpptr->id;//copy the element to node

      if (previousptr2 == node)
      	previousptr2->subor1 = tmpptr->subor1;

      else
         previousptr2->subor2 = tmpptr->subor1;
     }

   free(tmpptr);
   return node;
}


