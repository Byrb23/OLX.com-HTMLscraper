   


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <assert.h>
#include <time.h>
#include <ctype.h>
#include "mp2head.h"
#define MAX_LENGTH 256


void print_menu()
{
    printf(" ------------------------ \n");
    printf(" ------ M  E  N  U  ----- \n");
    printf(" ------------------------ \n");
    printf("| 1.)Change input file.  |\n");
    printf("| 2.)View original list. |\n");
    printf("| 3.)List all locations. |\n");
    printf("| 4.)Calculate ave.price |\n");
    printf("| 5.)Create .CSV  file   |\n");
    printf("| 6.)Sort by location.   |\n");
    printf("| 7.)Sort by price.      |\n");
    printf("| 8.)Exit.               |\n");
    printf(" ------------------------ \n");


}
//
char *trimwhitespace(char *str)
{
    char *end;
    while(isspace((unsigned char)*str)) str++;
    if(*str == 0)
    return str;
    end = str + strlen(str) - 1;
    while(end > str && isspace((unsigned char)*end)) end--;
  *(end+1) = 0;

  return str;
}
//
void removeStringTrailingNewline(char *str) {
  if (str == NULL)
    return;
  int length = strlen(str);
  if (str[length-1] == '\n')
    str[length-1]  = '\0';
}

//
void ave_price(node_t *head,int counter)
{  node_t *tempo;
   tempo=head;
   float sum=0;
   float average=0;
   while(tempo!=NULL)
            
                
                {
                     sum += (tempo->item_price);
                     tempo=tempo->next;
                }


            
        average = (sum) / (counter);
    printf("Average Price =Php %f\n", average);
    sum=0;
    average=0;
}
//
void bsortDesc(node_t list[50], int s)
{
    int i, j;
    node_t temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (list[j].item_price < list[j + 1].item_price)
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
//
void bsortletDesc(node_t list[50], int s)
{
    int i, j;
    node_t temp;

    for (i = 0; i < s - 1; i++)
    {
        for (j = 0; j < (s - 1-i); j++)
        {
            if (strcasecmp(list[j].item_location,list[j + 1].item_location) < strcasecmp(list[j+1].item_location,list[j].item_location))
            {
                temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }
}
//
//
void reverse(node_t **head_ref)              //Function description//
{                                                   //Reverse the order of my linked list!! :D//
    node_t* prev   = NULL;
    node_t* current = *head_ref;
    node_t* next;
    while(current!= NULL)
    {
        next  = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
void print_csv(FILE* pointer,int counter,node_t items[50],char *file_name)
{
    time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
   strftime(buffer,80,"_%Y_%m_%d_%H%M", info);
   printf("%s", buffer );
    strcat(file_name,buffer);
    strcat(file_name,".csv");
    pointer=fopen(file_name,"w");
    fprintf(pointer,"Item name,Price,Locations,Link\n");
    for(int i=0;i<counter;i++)
    {
        fprintf(pointer,"%s,%d,%s,%s\n",items[i].item_name,items[i].item_price,items[i].item_location,items[i].item_link);
    }
    fclose(pointer);

}
//
void print_csv_price(FILE* pointer,int counter,node_t items[50],char *file_name)
{
     time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
   strftime(buffer,80,"_by_price_%Y_%m_%d_%H%M", info);
    strcat(file_name,buffer);
    strcat(file_name,".csv");
    pointer=fopen(file_name,"w");
    fprintf(pointer,"Price,Item name,Locations,Link\n");
    for(int i=0;i<counter;i++)
    {
        fprintf(pointer,"%d,%s,%s,%s\n",items[i].item_price,items[i].item_name,items[i].item_location,items[i].item_link);
    }
    fclose(pointer);

}
//
void print_csv_loc(FILE* pointer,int counter,node_t items[50],char *file_name)
{
     time_t rawtime;
    struct tm *info;
    char buffer[80];
    time( &rawtime );
    info = localtime( &rawtime );
    strftime(buffer,80,"_by_location_%Y_%m_%d_%H%M", info);
    printf("%s", buffer );
    strcat(file_name,buffer);
    strcat(file_name,".csv");
    pointer=fopen(file_name,"w");
    fprintf(pointer,"Locations,Item name,Price,Link\n");
    for(int i=0;i<counter;i++)
    {
        fprintf(pointer,"%s,%s,%d,%s\n",items[i].item_location,items[i].item_name,items[i].item_price,items[i].item_link);
    }
    fclose(pointer);

}
//
 void removeSpaces(char *str1)
{                                               //Removes whitespaces.//
    char *str2;                                 //Used for parsing.//
    str2=str1;
    while (*str2==' ') str2++;
    if (str2!=str1) memmove(str1,str2,strlen(str2)+1);
}
//
void count_nodes(node_t *start)
 {
      int count = 0;
      node_t *p=start;

      while(p!=NULL)
      {
                    p=p->next;
                    count++;
      }
      printf("Number of nodes %d ", count);
}
//
void insert(node_t **head,node_t items[50],int i) {

   node_t* new_head = (node_t*)malloc(sizeof(node_t));

    new_head->item_price =items[i].item_price;
    strcpy(new_head->item_link,items[i].item_link);
    strcpy(new_head->item_location,items[i].item_location);
    strcpy(new_head->item_name,items[i].item_name);
    new_head->next = *head;

    *head = new_head;
}
//
void chopN(char *str, size_t n)
{                                                   //Removes n characters starting from the first character that you don't want.//
    assert(n != 0 && str != 0);                     //Used for parsing.//
    size_t len = strlen(str);
    if (n > len)
        return;
    memmove(str, str+n, len - n + 1);
}
//

//
void removeSubstring(char *s,const char *toremove)
{
  while( s=strstr(s,toremove) )                                     //Removes the substring that you want.//
    memmove(s,s+strlen(toremove),1+strlen(s+strlen(toremove)));     //Used for parsing.
}

//
int get_name(char *line,FILE* fPointer,struct Results items [50])
{                                                                               //Function description//
    char *p1;                                                              //Get the item name from olx html file.//
    char *p2;
    char temp[100]={0};
    int i=0;
     while(fgets(line,256,fPointer)!=NULL)
        {    //GET NAME//
           p1=strstr(line,"<span class=\"title\">");
    		if(p1==NULL)
    				{

    				}
    		else    {
                            p2=strstr(p1,"</span>");
                            if(p2!=NULL)
                                    {
                                    strncpy(temp, p1 + strlen("<span class=\"title\">"),p2-p1);
                                    removeSubstring(temp,"</span>");
                                    removeStringTrailingNewline(temp);
                                    strncpy(items[i].item_name,temp,sizeof(temp)/sizeof(temp[0]));
                                    i++;
                                    }
                    }
        }
return i;
}
//PRICE//
void get_price(char *line,FILE* fPointer,struct Results items[50])
{
    char *p1;
    char *p2;
    char temp[100]={0};
    int i=0;
     while(fgets(line,256,fPointer)!=NULL)
        {    //GET NAME//
            p1=strstr(line,"<span class=\"price\">₱ ");
    		if(p1!=NULL)
    				{
                      p2=strstr(p1,"</span>");
                      if(p2!=NULL)
                      {
                       strncpy(temp, p1 + strlen("<span class=\"price\">"), p2-p1-strlen("<span>"));
                       removeSubstring(temp,"</span>");
                       chopN(temp,3);
                       char buf1[256]={0};
                       strncpy(buf1,temp,sizeof(buf1)/sizeof(buf1[0]));
                       removeSubstring(temp,",");
                       int k=atoi(temp);
                       items[i].item_price=k;
                       i++;
                      }
    				}


        }
}

//LOCATION//
void get_location(char *line,FILE* fPointer,struct Results items[50])
{
    char *p1;
    char *p2;
    char *p3;
    int i=0;
     while(fgets(line,256,fPointer)!=NULL)
        {    //GET NAME//
            p1=strstr(line,"<span class=\"location\">\n");

    		if(p1!=NULL)
                    {

                        fgets(line,256,fPointer);
    					p2=strstr(line,"</span>");

                                                if(p2==NULL)
    													{
                                                            p3=strstr(line,",");
                                                            char buf1[256]={0};
                                                            int length = strlen(",");
                                                            strncpy(buf1, line,(p3-line));
                                                            removeSubstring(buf1,",");
                                                            removeSpaces(buf1);
                                                            strcat(buf1," ");
                                                            strcat(buf1,p3+length);
                                                            trimwhitespace(buf1);
                                                            strncpy(items[i].item_location,buf1,sizeof(buf1)/sizeof(buf1[0]));
                                                            i++;

    													}
                                                else    {
                                                            char buf2[256]={0};
                                                            strncpy(buf2,line, p2-line);
                                                            removeSubstring(buf2,",");
                                                            removeSpaces(buf2);
                                                           trimwhitespace(buf2);
                                                           strncpy(items[i].item_location,buf2,sizeof(buf2)/sizeof(buf2[0]));
                                                            i++;



                                                        }

                    }
     }
}
//LINK//
void get_ref(char *line,FILE* fPointer,struct Results items[50])
{
    char *p1;
    char *p2;
    int i=0;
     while(fgets(line,256,fPointer)!=NULL)
        {    //GET NAME//
            p1=strstr(line,"<a href=\"/item/");
    		if(p1!=NULL)
    				{
    					p2=strstr(line,"\"");
                        if(p2!=NULL)
                            {
                                char buf2[256]={0};
                                char buf3[256]={0};
                                char buf4[256]={"\"https://www.olx.ph"};
                                strncpy(buf2,line, p2-line);
                                int length = strlen("/");
                                strncpy(buf3,p1+length,sizeof(buf3));
                                removeSubstring(buf3,"a href=\"");
                                strcat(buf4,buf3);
                                strncpy(items[i].item_link,buf4,sizeof(buf4)/sizeof(buf4[0]));
                                i++;


                            }


    				}

      }
}
