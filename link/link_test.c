/*******************************************************************************
	Filename:		linkTest.c
	Revision:		$Revision: 1.0 $
	Author	:		Feng
	Description:	link Test
*******************************************************************************/

#include "link.h"

/*------------------------------------------------------------------------------
 * Function :   main() -> entry to program
------------------------------------------------------------------------------*/
int main(void)
{
    int val;
    t_link mylink;
    
    linkInit(&mylink);

    linkAddHead(&mylink, 25);
    linkAddHead(&mylink, 41);
    linkAddHead(&mylink, 16);
    linkAddHead(&mylink, 7);
    linkAddTail(&mylink, 8);
    linkAddTail(&mylink, 19);
    linkAddHead(&mylink, 22);
    
    printf("the size of link is: %d\n", linkGetSize(&mylink));
    linkPrint(&mylink);
    
    linkDeleteHead(&mylink);
    linkDeleteTail(&mylink);
    printf("the size of link is: %d\n", linkGetSize(&mylink));
    linkPrint(&mylink);       

    if (linkGetFront(&mylink, &val)) {
        printf("the front link data is: %d\n", val);
    }
    
    if (linkGetTail(&mylink, &val)) {
        printf("the tail link data is: %d\n", val);
    }
    
    if (linkGetData(&mylink, &val, 3)) {
        printf("the 3th link data is: %d\n", val);
    }    
    
	return 0;
}









