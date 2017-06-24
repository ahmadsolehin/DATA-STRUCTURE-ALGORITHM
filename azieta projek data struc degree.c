/**=========== PROJECT DSA ===================
|  TITLE      : KAMI FRIED CHICKEN (KFC)     |
|  GROUP NAME : NUR AZIETA BT ASERI          |
|             : FATIN ATHIRAH BT NASOHA      |
|             : WAN NOR AFIQAH BT WAN OTHMAN |
===========================================**/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


/**Define TRUE and FALSE value**/
#define TRUE 1
#define FALSE 0

/**Function**/
void staffFunction ();
void display_menu();
void display();
void list_Orderings();
void del_Orderings();
void search_Ordering();
//void sort_Ordering();
int customerCount=0;

/**Structure of Ordering**/
struct Ordering
{
    char order_id[10];
    int code, quantity;
	float priceProd, price;
	struct Ordering *ptrnext;


};
struct Ordering *front, *rear, *headptr, *newptr,*newptrs, *thisptr, *currentptr;            //pointer that can point to a node

main ()
{

    front=NULL;

    /**Declaration Variable**/
    int exit1,password,pwd=1234;
    char staff;
    int i=0;
    int *ptri;

    /**Open File**/
    ///File for staff information
    FILE *input;
    FILE *read;
    input=fopen("Staff.txt","a+");

    /**Declaration for time & date**/
    char currentTime [20];
    char date [20];
    time_t clock;
    struct clock;
    struct tm * timeinfo;
    ptri=&i;
        printf ("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        printf ("\n\n\t\t\tWelcome to Kami Fried Chicken <KFC> ");
        time (&clock);
        timeinfo=localtime(&clock);
        strftime(currentTime,20,"%I:%M %p",timeinfo);
        printf("\n\n\n\t\t\t\t   Time : %s",currentTime);
        strftime ( date,20,"%x",timeinfo);
        printf("\n\t\t\t\t   Date : %s",date);
        printf("\n");
        printf("\n");
        printf ("\n\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");

    /**Input**/
    printf ("\n\n\n\n\t\t\tPress 'S' for Staff         : ");
    scanf(" %c",&staff);
    if (staff == 's' || staff == 'S')
   {
       printf ("\n\t\t\tEnter Password To Continue  : ");
       scanf ("%d",&password);
       system ("CLS");
       if (password==pwd)
       {
            staffFunction();
            printf("\n\n\n\n\n\n\n\n\n\n\n \tDo you want to continue? <No = 0   Yes = 1> : ");
            scanf("%i", &exit1);
            system ("CLS");
            switch (exit1)
           {
            case 0 :printf("\n\n\n\n\n\t\t\t  Thank You use our sytem!\n");
            break;
            case 1 :display();
            break;
            }
            }
            else
            {
                 printf ("\a\a\n\n\n\t\t\tERROR: Wrong Password Entered. Try again");
                 printf("\n\n\t\t\tExit? Yes = 0   NO = 1 : ");
                 scanf("%d", &exit1);
                 system ("CLS");
                 if(exit1==1)
                    main();
                 else if(exit1==0)
                    exit(0);
            }
       }
       printf("\n\n\n");
       fclose(input);
}
void staffFunction ()
{
    /**Declaration Variable**/
    char f_name[100],l_name[100],da_te[100],ti_me[100],gen_der[100],format[100];
    int phone,ages,user_id;
    user_id =0;

    printf("\7\n\n\tSuccess Staff!"); //information staff success log in

    /**Read data from Staff.txt**/
    FILE *read;
    read = fopen ("Staff.txt", "r");
        while (!feof(read))
        {
        fscanf(read, "%s" , f_name);
        fscanf(read, "%s" , l_name);
        fscanf(read, "%d" , &phone);
        fscanf(read, "%d" , &ages);
        fscanf(read, "%s" , da_te);
        fscanf(read, "%s %s" , ti_me,format);
        fscanf(read, "%s" , gen_der);
        user_id++;

        ///Output on screen when staff view
        printf ("\n\n\n\n\t\t%i  First Name        : %s",user_id,f_name);
        printf ("\n\t\t   Last Name         : %s",l_name);
        printf ("\n\t\t   Phone Number      : +60%d",phone);
        printf ("\n\t\t   Age               : %d",ages);
        printf ("\n\t\t   Date              : %s",da_te);
        printf ("\n\t\t   Time              : %s %s ",ti_me,format);
        printf ("\n\t\t   Gender            : %s",gen_der);
        }
        fclose(read);
}

void display()
{
    /**Declaration Variable**/
    char ch;
	int choice=TRUE;

	///Queue

    while(choice==TRUE)
	{
	    printf("\n\n");
	    printf("\n\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
		printf("\t\t\t\tFOOD ORDERING SYSTEM\t\n\n");
		printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
	    printf("\n\t\t\t\tm - List Menu");
		printf("\n\t\t\t\tl - List all Customer");
        printf("\n\t\t\t\td - Delete Customer");
        printf("\n\t\t\t\ts - Search Customer");
		printf("\n\t\t\t\tx - Exit\n\n");
        printf("\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
		printf("\n\n\n\t\t\t\tEnter choice : ");
		scanf(" %c",&ch);
		ch=toupper(ch);
        switch(ch)
		{
        case 'M': display_menu(); break;//Open other void
		case 'L': list_customers(); break;//Open other void
		case 'D':del_customers();break;//Open other void
		case 'S':search_customer();break;//Open other void
		//case 'O': sort_Ordering();break;
		case 'X': exit(0);
		default: printf("\nInvalid entry. Please select 'M','L','D','S','X'\n");
		}
	}

}

void display_menu()
{

    /**Declaration of Variable**/
    char order_id[10];
    system("cls"); //clear screen
    int cond=0;
    int code,quantity,add;
    float totalAmount=0,priceProd=0,price=0;

    /**Open file**/
    //To save the order in file
    FILE*data;
    data = fopen("data.txt", "a+");

    printf("\n--------------------------------------------------------------------------------");
    printf("\n\t\t\t::Kami Fried Chicken (KFC)::\n\n");
    printf("\n--------------------------------------------------------------------------------");
    printf("\n\n\t\t Code   Drinks                    Price(RM)");
    printf("\n\t\t   0    Coca Cola                 3.20");
    printf("\n\t\t   1    Sprite                    2.30");
    printf("\n\t\t   2    Mirinda (Orange)          2.40");
    printf("\n\t\t   3    Mirinda (Strawberry)      2.40\n");
    printf("\n\n\t\t Code   Burger                    Price(RM)");
    printf("\n\t\t   4    Colonel Burger            4.50");
    printf("\n\t\t   5    Zinger Burger             5.50");
    printf("\n\t\t   6    Cheezy Burger             6.50\n");
    printf("\n\n\t\t Code   Combo                     Price(RM)");
    printf("\n\t\t   7    Rice Plate                8.50");
    printf("\n\t\t   8    Snack Plate               9.50");
    printf("\n\t\t   9    Dinner Plate              10.50");
    printf("\n\t\t   10   Boneless Snack Plate      11.50");
    printf("\n\t\t   11   Mini Bucket               12.00\n");
    printf("\n\t\t Code   Side Orders               Price(RM)");
    printf("\n\t\t   12   Coleslaw                  2.45");
    printf("\n\t\t   13   French Fries              2.00");
    printf("\n\t\t   14   Cheezy Wedges             3.50");
    printf("\n\n");
    printf("\n--------------------------------------------------------------------------------");



    /**Queue**/
    ///Customer ordering
    newptr=(struct Ordering *)malloc(sizeof (struct Ordering)); // pointer to a new memory allocation

    ///Get the information
    printf("\n\n\t\tEnter Ordering order ID (*eg:cd1)     : ");
    scanf("%s",&order_id);
    strcpy(newptr->order_id,order_id);
    fprintf(data, "%s\n",newptr->order_id);
    printf("\n\t\tOrdering Order ID                     : %s\n",newptr->order_id);

    do{

        newptr=(struct Ordering *)malloc(sizeof (struct Ordering)); // pointer to a new memory allocation

        strcpy(newptr->order_id,order_id);

        buymore:
        printf("\n\t\tEnter Code                            : ");
        scanf("%d",&newptr->code);
        fprintf(data, "%d\n",newptr->code);

        if (newptr->code==0)
            newptr->price=3.20;
        else if (newptr->code==1)
            newptr->price=2.30;
        else if (newptr->code==2)
            newptr->price=2.40;
        else if (newptr->code==3)
            newptr->price=2.40;
        else if (newptr->code==4)
            newptr->price=4.50;
        else if (newptr->code==5)
            newptr->price=5.50;
        else if (newptr->code==6)
            newptr->price=6.50;
        else if (newptr->code==7)
            newptr->price=8.50;
        else if (newptr->code==8)
            newptr->price=9.50;
        else if (newptr->code==9)
            newptr->price=10.50;
        else if (newptr->code==10)
            newptr->price=11.50;
        else if (newptr->code==11)
            newptr->price=12.00;
        else if (newptr->code==12)
            newptr->price=2.45;
        else if (newptr->code==13)
            newptr->price=2.00;
        else if (newptr->code==14)
            newptr->price=3.50;
        else{
            printf("INVALID CHOSEN. PLEASE SELECT AGAIN!!\n");
            printf("\n");
            printf("\n");
            goto buymore;
        }

        printf("\n\t\tQuantity (Number only)                : ");
        scanf("%d",&newptr->quantity);
        fprintf(data, "%d\n",newptr->quantity);
        priceProd+= (newptr->price) * (newptr->quantity);
        newptr->priceProd=priceProd;
        printf ("\n\n\t\tDo you want to add order? <No = 0   Yes = 1> :");
        scanf ("%d",&add);
        printf("\n");

        ///This is for Ordering
        if (front==NULL){            //node is empty
            front=newptr;          //first pointer point to first node
            newptr->ptrnext=NULL;  //first node pointer point to null
        }
        else{
            currentptr=front;
            while(currentptr->ptrnext !=NULL)      //search until last node
                  currentptr=currentptr->ptrnext;  //point to next node

            currentptr->ptrnext=newptr;                      //last node point to new node
            newptr->ptrnext=NULL;                             //new node point to null
        }
     }while (add != 0);

     printf("\n\n\t\t\t\t=======================================");
     printf("\n\t\t\t\t\tTotal price is RM %.2f",priceProd);
     printf("\n\t\t\t\t=======================================");
     printf("\n\n");
     printf("\n\n\t\tPress any key ");
     customerCount++;       //to increase the total count of Orderings after adding new order
     //sortchoice();        //auto sorting the list after adding new order
     getch();               //to pause the screen by waiting for any random key
     system("CLS");         //clear screen
     return;                //to return to main menu
     fclose(data);
}

void list_customers()
{
    ///Declared variable
    int terminate;

    if (front==NULL)  //empty list
    {
		printf("\n\t\t\t\tEMPTY LIST!!!\7\7\7");
		return;
    }

    else
    {
        system("cls");
        currentptr=front;
        printf("\n");
        printf("\t\t\t\t~LIST ALL CUSTOMER~");
        printf("\n\n\n");
        printf("********************************************************************************");
        printf("\n\n\t  ORDER ID          \t CODE    \t QUANTITY      \t PRICE(RM)\n\n");
        printf("********************************************************************************");
        printf("\n");

   do
    {
                printf("\n\n");
                printf("\t  %s",currentptr->order_id);
                printf("\t\t %d",currentptr->code);
                printf("\t\t %d",currentptr->quantity);
                printf("\t\t RM%.2f",currentptr->priceProd);

        currentptr=currentptr->ptrnext;
        printf("\n\t");

   } while(currentptr!=NULL);
        printf("\n\n\n\n\n\n\n\n\n\n\n \tDo you want to continue? <No = 0   Yes = 1> : ");
        scanf("%d", &terminate);
        system ("CLS");
        if(terminate==1)
           display();
        else if(terminate==0)
           printf("\n\n\t\t   Thank you for use our system!!!\n");
           exit(0);

    }
}

void del_customers()
{
    thisptr=front;
	if (front==NULL)   //node is empty?
      {
      	printf("\n\n\t\t        The list is empty. Cannot delete!!!\7\7\7\7\7\n");  //the list is empty
      	return;
      }
	else
	{
	    front=front->ptrnext;
	    free(thisptr);
    }

    list_customers();

}
void search_customer()
{
    ///Declared variable
    char item[10],order_id[10];

    currentptr=front;
    if(front==NULL) //list empty
    {
        printf("\n\n\t\t    List is empty. Nothing can be searched!!!\7\7\7\7\7");
    }
    else            //list not empty
    {
        currentptr=front;
        ///KEY IN ORDER ID TO SEARCH -To search a data using user input to find a match-
        printf("\n");
        printf("\n\n\t\tPlease enter Order id : ");
        scanf(" %s",&item);
        printf("\n");

        //currentptr=front;

        ///LOOP TO SELECTED CUSTOMER ORDER ID
        while(currentptr!=NULL)
        {
        if(strcmp(currentptr->order_id,item)==NULL)
        {

            printf("\n\t\t\t   Customer order ID\tPrice(RM) \1");
            printf("\n\t\t==================================================");
            printf("\n\n\a\t\t\t\t%s\t\t%.2f",currentptr->order_id, currentptr->priceProd);
            printf("\n\n\t\t==================================================\n\n");
            return;

        }
        else
        {
                //Data not found or search order id are not match
                printf("\n\t\t\t\t  Data not found!!!\7\7\7\7\7\n\n");
               return;
        }
        //currentptr=currentptr->ptrnext;
        }
    }
}
