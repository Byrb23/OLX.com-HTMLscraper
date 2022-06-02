														

#ifndef __MP2HEAD_H__
#define __MP2HEAD_H__
typedef struct Results {
	char item_name[256];
	int item_price;
    char item_location[256];
	char item_link[256];

	struct Results* next;


}node_t;
///Function prototype//
void print_menu();
char *trimwhitespace(char *str);
void removeStringTrailingNewline(char *str);
void ave_price(node_t *head,int counter);
void bsortDesc(node_t list[50], int s);
void bsortletDesc(node_t list[50], int s);
void reverse(node_t **head_ref);
void print_csv(FILE* pointer,int counter,node_t items[50],char *file_name);
void print_csv_price(FILE* pointer,int counter,node_t items[50],char *file_name);
void print_csv_loc(FILE* pointer,int counter,node_t items[50],char *file_name);
void removeSpaces(char *str1);
void count_nodes(node_t *start);
void insert(node_t **head,node_t items[50],int i);
void chopN(char *str, size_t n);
void removeSubstring(char *s,const char *toremove);
int get_name(char *line,FILE* fPointer,struct Results items [50]);
void get_price(char *line,FILE* fPointer,struct Results items[50]);
void get_location(char *line,FILE* fPointer,struct Results items[50]);
void get_ref(char *line,FILE* fPointer,struct Results items[50]);
#endif
