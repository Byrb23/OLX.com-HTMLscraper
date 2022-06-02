#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include "mp2head.h"
#define MAX_LENGTH 256



//Main//


int main()
{
  struct Results items[50];
  struct Results items_by_price[50];
  struct Results items_by_location[50];
  struct Results items_dup_location[50];
  node_t* head=NULL;
  node_t* head2=NULL;
  node_t* head3=NULL;
  node_t* head4=NULL;
  node_t* tempo;
  float sum = 0.0, average;
  int count=0;
  char line[256];
  int i = 0;
  int z=0;
  int k=0;
  char file_name[50]={0};
   char new_location[100]={0};
  int choice;
  char file_location[100];
  FILE* fPointer=NULL;
do{
  printf("Enter the filename that you wish to open.\n");
  scanf("%s",file_location);
  fPointer=fopen(file_location,"r");

if (fPointer==NULL)
		{
			printf("File error!,invalid file name! program will now exit.\n");
			exit(0);
		}
else
		{
			printf("Success!\n");
		}


        //LOAD INFORMATION//
        //GET NAME//
        count=get_name(line,fPointer,items);
        rewind(fPointer);
        count=get_name(line,fPointer,items_by_price);
        rewind(fPointer);
        count=get_name(line,fPointer,items_by_location);
        rewind(fPointer);
        count=get_name(line,fPointer,items_dup_location);
        rewind(fPointer);
        //GET PRICE//
        get_price(line,fPointer,items);
        rewind(fPointer);
        get_price(line,fPointer,items_by_price);
        rewind(fPointer);
        get_price(line,fPointer,items_by_location);
        rewind(fPointer);
        get_price(line,fPointer,items_dup_location);
        rewind(fPointer);
        //GET LOCATION//
        get_location(line,fPointer,items);
        rewind(fPointer);
        get_location(line,fPointer,items_by_price);
        rewind(fPointer);
        get_location(line,fPointer,items_by_location);
        rewind(fPointer);
        get_location(line,fPointer,items_dup_location);
        rewind(fPointer);
        // GET LINK//
        get_ref(line,fPointer,items);
        rewind(fPointer);
        get_ref(line,fPointer,items_by_price);
        rewind(fPointer);
        get_ref(line,fPointer,items_by_location);
        rewind(fPointer);
        get_ref(line,fPointer,items_dup_location);
        rewind(fPointer);
        for(i=0;i<count;i++)
                    {
                      insert(&head,items,i);
                      insert(&head2,items,i);
                      insert(&head3,items,i);
                      insert(&head4,items,i);
                    }
menu:
      print_menu();
      
      printf("Enter your choice:\n");
          do{
               scanf("%d",&choice);
               printf("You entered %d\n",choice);
               if(choice<1||choice>8)
             {
               printf("Error,please enter a number from 1 to 8\n");
             }

            }while(choice<1||choice>8);


        //Start of Switch//
        switch(choice)
  {
        case 1:
                fclose(fPointer);
               
        break;


          

        case 2:
                  
                    reverse(&head);
                    tempo=head;
                    printf("-----------Original Item List -------------\n");
                    while(tempo!=NULL)
                     {  printf("---------------Item -------------\n");
                         printf("Item name :%s\n",tempo->item_name);
                         printf("Price:Php %d\n",tempo->item_price);
                         printf("Location:%s\n",tempo->item_location);
                         printf("Link:%s\n",tempo->item_link);
                        tempo=tempo->next;
                        printf("------------------------------------\n");
                        k++;
                     }
                     goto menu;
                     break;


        case 5:
                    printf("Enter the filename output: ");
                    scanf("%s",file_name);
                    printf("%s ","Creating");
                    printf("%s",file_name);
                    print_csv(fPointer,count,items,file_name);
                    printf("%s","......");
                    printf("\nFile successfully created!\n");
                    goto menu;

                        break;
         case 4:
                    
                    for(i = 0; i < count; ++i)
                      {
                         
                         sum += items[i].item_price;
                      }
                     average = sum / count;
                    printf("Average = %.2f\n", average);
                    sum=0;
                    average=0;
                    goto menu;
                    break;
         case 6:

                    bsortDesc(items_by_price,count);
                    printf("-----------Sort by Price -------------\n");
                    for(i=0;i<count;i++)

                    {   printf("---------------Item -------------\n");
                        printf("Item name :%s\n",items_by_price[i].item_name);
                        printf("Price :Php %d \n",items_by_price[i].item_price);
                        printf("Location :%s\n",items_by_price[i].item_location);
                        printf("Link : %s\n",items_by_price[i].item_link);
                        printf("------------------------------------\n");
                     }
                     printf("Enter the filename output: ");
                     scanf("%s",file_name);
                     printf("%s ","Creating");
                     printf("%s",file_name);
                     printf(" %s","......");
                     print_csv_price(fPointer,count,items_by_price,file_name);
                     printf("%s","......");
                     printf("\nFile successfully created!\n");
                     goto menu;
                         break;


        case 7:
                bsortletDesc(items_by_location,count);
                printf("-----------Sort by Location-------------\n");
                for(i=0;i<count;i++)
                {    printf("---------------Item-------------\n");
                     printf("Item name :%s\n",items_by_location[i].item_name);
                     printf("Price :Php %d \n",items_by_location[i].item_price);
                     printf("Location :%s\n",items_by_location[i].item_location);
                     printf("Link : %s\n",items_by_location[i].item_link);
                     printf("------------------------------------\n");
                 }
                 printf("Enter the filename output: ");
                 scanf("%s",file_name);
                 printf("%s ","Creating");
                 printf("%s",file_name);
                 print_csv_loc(fPointer,count,items_by_location,file_name);
                 printf("%s","......");
                 printf("\nFile successfully created!\n");
                 goto menu;
             break;

        case 3://////////////////////FUNCTION TO PRINT ALL LOCATIONS WITHOUT DUPLICATE//////////
                bsortletDesc(items_by_location,count);
                z=0;
                printf("------------List of all locations--------------\n");
                do
                {
                 if(strcasecmp(items_by_location[z].item_location,items_by_location[z+1].item_location)==0)
                     {
                        z++;
                     }

                 else
                    {
                     printf("%s\n",items_by_location[z].item_location);
                     z++;
                    }
                }while(z<count);
                printf("-----------------------------------------------");
                goto menu;
        break;

        case 8:
              fclose(fPointer);
              printf("Bye bye!\n");
              exit(0);

   }

}while(choice==1);



 




return 0;
}
