/*******************************************************************************
	Filename:		link.h
	Revision:		$Revision: 1.0 $
	Author	:		Feng
	Description:	link Demo
*******************************************************************************/
#ifndef __LINK_H__
#define __LINK_H__

/*------------------------------------------------------------------------------
                                  Includes
------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>

/*------------------------------------------------------------------------------
                                struct define
------------------------------------------------------------------------------*/

// make link struct
typedef struct node{
	int val;                // store data
	struct node *p_next;    // point to next node
}t_node;

// make link struct
typedef struct link{
	t_node head;            // the head of link
	t_node tail;            // the tail of link
}t_link;

/*------------------------------------------------------------------------------
                                  Function
------------------------------------------------------------------------------*/
/* Initialize the link */
void linkInit(t_link *p_link);

/* deinit of the link */
void linkDeinit(t_link *p_link);

/* addition data to link tail */
t_node *linkCreatNode(int data);

/* get the link size */
int linkGetSize(const t_link *p_link);

/* addition data to link head */
int linkAddHead(t_link *p_link, int data);

/* addition data to link tail */
int linkAddTail(t_link *p_link, int data);

/* insert data to link, from small to big */
int linkInsertData(t_link *p_link, int data);

/* delete the head data from link */
int linkDeleteHead(t_link *p_link);

/* delete the tail data from link */
int linkDeleteTail(t_link *p_link);

/* delete the indicated data from link */
int linkDeleteData(t_link *p_link, int data);

/* get the front of link data */
int linkGetFront(const t_link *p_link, int *p_data);

/* get the tail of link data */
int linkGetTail(const t_link *p_link, int *p_data);

/* get the indicated number of link data */
int linkGetData(const t_link *p_link, int *p_data, int num);

/* print link data for test */
void linkPrint(const t_link *p_link);

#endif
