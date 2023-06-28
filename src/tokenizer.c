#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  return (c == ' ' || c == '\t') ? 1 : 0;
}

int non_space_char(char c)
{
  return (c != ' ' && c != '\t' && c != '\0') ? 1 : 0;
}

char *token_start(char *str)
{
  while (*str != '\0')
    {
      if (non_space_char(*str))
	{
	  return str;
	}
      str++;
    }
  return 0;
}

char *token_terminator(char *token)
{
  while (non_space_char(*token))
    {
      token++;
    }
  return token;
}

int count_tokens(char *str)
{
  int count = 0;
  while(*str != '\0')
    {
      str = token_start(str);
      str = token_terminator(str);
      count++;
    }
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *cpystr = (char *)malloc((len + 1) * sizeof(char));
  
  for (int i = 0; i < len; i++)
    {
      cpystr[i] = inStr[i];
    }

  cpystr[len] = '\0';

  return cpystr;
}

char **tokenize(char *str)
{
  int num_of_tokens = count_tokens(str);
  char **tokens = malloc((num_of_tokens + 1) * sizeof(char));

  str = token_start(str);
   
  for (int i = 0; i < num_of_tokens; i++)
    {
      char *end = token_terminator(str);
      tokens[i] = copy_str(str, end - str);
      str = token_start(end);
    }
  char **terminator = tokens + num_of_tokens;
  *terminator = 0;
  return tokens;
}

void print_tokens(char **tokens)
{
  int count = 0;
  puts("BELLO");

  while (*tokens != 0)
    {
      printf("[%d]\t",count);
      puts(*tokens);
      count++;
      tokens++;
    }
}

void free_tokens(char **tokens)
{
  char **current = tokens;
  while (*current != NULL)
    {
      free(*current);
      current++;
    }
  free(tokens);
}



