/*******************************************************************************
	Filename:		link.c
	Revision:		$Revision: 1.0 $
	Author	:		Feng
	Description:	link Demo
*******************************************************************************/

/*------------------------------------------------------------------------------
                                  Includes
------------------------------------------------------------------------------*/

#include "link.h"

/*------------------------------------------------------------------------------
                                  Function
------------------------------------------------------------------------------*/
/*------------------------------------------------------------------------------
 * Function :   linkInit() => Initialize the link
 * Input	:	p_link -> point to link
------------------------------------------------------------------------------*/
void linkInit(t_link *p_link)
{
	p_link->head.p_next = &(p_link->tail);
	p_link->tail.p_next = NULL;
}

/*------------------------------------------------------------------------------
 * Function :   linkDeinit() => deinit of the link
 * Input	:	p_link -> point to link
------------------------------------------------------------------------------*/
void linkDeinit(t_link *p_link)
{
    t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    
    while (p_link->head.p_next != &(p_link->tail)) {
        p_first = &(p_link->head);
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        p_first->p_next = p_last;
        
        free (p_mid);
        p_mid = NULL;
    }
}

/*------------------------------------------------------------------------------
 * Function :   linkAddTail() => addition data to link tail
 * Input	:	p_link -> point to link
 				data    -> the date need to push
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
t_node *linkCreatNode(int data)
{
    t_node *p_node = (t_node *)malloc(sizeof(t_node));
    
    if (p_node) {
        p_node->val = data;
        p_node->p_next = NULL;
    }
    return (p_node);
    
}

/*------------------------------------------------------------------------------
 * Function :   linkGetSize() => get the link size
 * Input	:	p_link -> point to link
 * Output	:	the size of link
------------------------------------------------------------------------------*/
int linkGetSize(const t_link *p_link)
{
    int cnt = 0;
    
    const t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    const t_node *p_tmp = &(p_link->head);   
    
    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        
        if (p_mid != &(p_link->tail)) {
            cnt++;
        }
    }

    return (cnt);
}

/*------------------------------------------------------------------------------
 * Function :   linkAddHead() => addition data to link head
 * Input	:	p_link  -> point to link
 				data    -> the date need to addition
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkAddHead(t_link *p_link, int data)
{
    t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    t_node *p_node = linkCreatNode(data);
    
    if (!p_node) {
        return 0;
    }
    
    p_first = &(p_link->head);
    p_mid = p_first->p_next;

    p_first->p_next = p_node;
    p_node->p_next = p_mid;

    return 1;
}

/*------------------------------------------------------------------------------
 * Function :   linkAddTail() => addition data to link tail
 * Input	:	p_link  -> point to link
 				data    -> the date need to addition
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkAddTail(t_link *p_link, int data)
{
    t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    t_node *p_tmp = &(p_link->head);    
    t_node *p_node = linkCreatNode(data);
    
    if (!p_node) {
        return 0;
    }

    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        
        if (p_mid == &(p_link->tail)) {
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            break;
        }
    }
    return 1;
}

/*------------------------------------------------------------------------------
 * Function :   linkInsertData() => insert data to link, from small to big
 * Input	:	p_link  -> point to link
 				data    -> the date need to insert
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkInsertData(t_link *p_link, int data)
{
    t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    t_node *p_tmp = &(p_link->head);
    t_node *p_node = linkCreatNode(data);
    
    if (!p_node) {
        return 0;
    }
    
    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;

        if ((p_mid==&(p_link->tail)) || (p_mid->val>=data)) {
            p_first->p_next = p_node;
            p_node->p_next = p_mid;
            break;
        }
    }
    return 1;
}

/*------------------------------------------------------------------------------
 * Function :   linkDeleteHead() => delete the head data from link
 * Input	:	p_link -> point to link
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkDeleteHead(t_link *p_link)
{
    t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    
    if (p_link->head.p_next == &(p_link->tail)) {
        return 0;
    }
    
    p_first = &(p_link->head);
    p_mid = p_first->p_next;
    p_last = p_mid->p_next;
    
    p_first->p_next = p_last;
    free(p_mid);
    p_mid = NULL;
    
    return 1;
}

/*------------------------------------------------------------------------------
 * Function :   linkDeleteTail() => delete the tail data from link
 * Input	:	p_link -> point to link
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkDeleteTail(t_link *p_link)
{
    t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    t_node *p_tmp = &(p_link->head);

    if (p_link->head.p_next == &(p_link->tail)) {
        return 0;
    }
    
    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {        
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        
        if (p_last == &(p_link->tail)) {
            p_first->p_next = p_last;
            free(p_mid);
            p_mid = NULL;
            break; 
        }
    }  
    return 1;
}

/*------------------------------------------------------------------------------
 * Function :   linkDeleteData() => delete the indicated data from link
 * Input	:	p_link  -> point to link
                data    -> the date need to delate
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkDeleteData(t_link *p_link, int data)
{
    t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    t_node *p_tmp = &(p_link->head);

    if (p_link->head.p_next == &(p_link->tail)) {
        return 0;
    }
    
    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {        
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        
        if ((p_mid!=&(p_link->tail)) && (p_mid->val==data)) {
            p_first->p_next = p_last;
            free(p_mid);
            p_mid = NULL;
            return 1; 
        }
    }  
    return 0;
}

/*------------------------------------------------------------------------------
 * Function :   linkGetFront() => get the front of link data
 * Input	:	p_link -> point to link
 				p_data  -> point the data which is geted
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkGetFront(const t_link *p_link, int *p_data)
{
    if (p_link->head.p_next == &(p_link->tail)) {
        return 0;
    }
    
    *p_data = p_link->head.p_next->val;
    return 1;
}

/*------------------------------------------------------------------------------
 * Function :   linkGetTail() => get the tail of link data
 * Input	:	p_link -> point to link
 				p_data  -> point the data which is geted
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkGetTail(const t_link *p_link, int *p_data)
{
    const t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    const t_node *p_tmp = &(p_link->head);

    if (p_link->head.p_next == &(p_link->tail)) {
        return 0;
    }
    
    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {        
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;
        
        if (p_last == &(p_link->tail)) {
            *p_data = p_mid->val;
            return 1; 
        }
    }  
    return 0;
}

/*------------------------------------------------------------------------------
 * Function :   linkGetData() => get the indicated number of link data
 * Input	:	p_link  -> point to link
 				p_data  -> point the data which is geted
 				num     -> used indicated number
 * Output	:	=0 failed ; =1 success
------------------------------------------------------------------------------*/
int linkGetData(const t_link *p_link, int *p_data, int num)
{
    int cnt = 0;
    const t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    const t_node *p_tmp = &(p_link->head);

    if (p_link->head.p_next == &(p_link->tail)) {
        return 0;
    }
    
    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {        
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;

        if (p_mid!=&(p_link->tail) && (cnt == num)) {
            *p_data = p_mid->val;
            return 1; 
        }
        cnt++;
    }  
    return 0;
}

/*------------------------------------------------------------------------------
 * Function :   linkPrint() => print link data for test
 * Input	:	p_link -> point to link
------------------------------------------------------------------------------*/
void linkPrint(const t_link *p_link)
{
    const t_node *p_first=NULL, *p_mid=NULL, *p_last=NULL;
    const t_node *p_tmp = &(p_link->head);

    if (p_link->head.p_next == &(p_link->tail)) {
        return;
    }
    
    for (; p_tmp!=&(p_link->tail); p_tmp=p_tmp->p_next) {        
        p_first = p_tmp;
        p_mid = p_first->p_next;
        p_last = p_mid->p_next;

        if (p_mid!=&(p_link->tail)) {
            printf("%d ", p_mid->val);
        }
    }  
    printf("\n");
}
