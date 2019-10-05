/*
 * main1.c
 */
#include <stdio.h>
#define MAXNO 100
void what(int [], int);
int main() // main1.c
{
    int no = 0, i ;
    int data[MAXNO] ;

    printf("Enter data, terminate with Ctrl+D\n") ;
    while(scanf("%d", &data[no]) != EOF) ++no;
    what(data, no) ;
    printf("Data in sorted order is: ") ;
    for(i = 0; i < no; ++i) printf("%d ", data[i]);
    putchar('\n') ;
    return 0 ;
} // main1.c

