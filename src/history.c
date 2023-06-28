#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history()
{
  List *history = (List *)malloc(sizeof(List));

  return history;
}

void add_history(List *list, char *str)
{
  Item *newItem = (Item *)malloc(sizeof(Item));
  char *ptr = str;

  while (*ptr != '\0')
    {
      ptr++;
    }
 
  int len = ptr - str;

  newItem -> str = copy_str(str, len);

  Item *current = list -> root;
  int IdCount = 2;
  
  if (list -> root == NULL)
    {
      list -> root = newItem;
      newItem -> id = 1;
    }
  else
    {
      while(current -> next != NULL)
	{
	  current = current -> next;
	  IdCount++;
	}
      newItem -> id = IdCount;
      current -> next = newItem;
    }
}

char *get_history(List *list, int id)
{
  Item *current = list -> root;
  while (current != NULL)
    {
      if (current -> id == id)
	{
	  return current -> str;
	}
      current = current -> next;
    }
}

void print_history(List *list)
{
  Item *current = list -> root;
  int count = 1;
  while (current != NULL)
    {
      printf("[%d] - %s", count, current -> str);
      count++;
      current = current -> next;
    }
}


void free_history(List *list)
{
  Item *current = list -> root;
  Item *previous;

  while (current != 0)
    {
      previous = current;
      current = current -> next;
      free(previous -> str);
      free(previous);
    }
  free(list);
}

