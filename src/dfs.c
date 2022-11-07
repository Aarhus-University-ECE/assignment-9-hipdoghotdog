/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.
  printf("Tree: \n");
  print_tree(root, 0);
  printf("\nDFS with stack: \n");

  stack *list = malloc(sizeof(stack));
  node *temp = root;

  push(list, root);
  temp -> visited = false;
  while(isEmpty(list) == false)
  {
    temp = pop(list) -> node;
    if (temp -> visited != true)
    {
      print_node(temp);
      temp -> visited = true;
    }

    if(temp -> rchild != NULL)
    {
      push(list, temp -> rchild);
    }
    if(temp -> lchild != NULL)
    {
      push(list, temp -> lchild);
    }
    free(temp);
  }
}

node *make_node (int num, node * left, node * right)
{
  struct node *new_node = malloc(sizeof(struct node));
  new_node -> num = num;
  new_node -> lchild = left;
  new_node -> rchild = right;
  new_node -> visited = false;
	return new_node;
}

void free_node (node * p)
{
	free(p);
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d ", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * nodeins)
{
    //implement push here
    struct stack *temp = malloc(sizeof(struct stack));  
    temp -> node = nodeins;
    temp -> next = topp;
    topp = temp;
	return 0;
}

bool isEmpty (stack * topp)
{
  if (topp-> node == NULL){
    return true;
  }
  else
  return false;
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop topp  
// element from the stack 

stack *pop (stack * topp)
{
  if(topp->next = NULL)
  {
    abort;
  }

  struct stack *temp = topp;
  if(topp->node == NULL)
  {
    printf("Stack is Empty\n");
  }
  else
  {
    topp = topp -> next;
     
  }

  return temp;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}
