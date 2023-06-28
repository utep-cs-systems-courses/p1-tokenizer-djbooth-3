#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char userInput[300];
  List *history = init_history();

  while (1)
    {
      puts("Hello my name is Tokenizer! What can I do for you?");
      puts("Your Options: \n\n Type a sentence. \n\n Type '1' for history. \n\n Type ! then a number to print a past input (example -> !2). \n\n Type 'q' to quit.");

      printf("> ");
      fgets(userInput,sizeof(userInput),stdin);

      if (userInput[0] == '1')
	{
	  puts("\n-----------------");
	  print_history(history);
	  puts("^^^^^History^^^^^\n");
	}
      else if (userInput[0] == '!')
	{
	  int id_val = (*(userInput + 1) - '0');
	  char *str = get_history(history,id_val);

	  if (str == NULL)
	    {
	      printf("No history found!\n\n");
	    }
	  else
	    {
	      char **tokens = tokenize(str);
	      print_tokens(tokens);
	      puts("hi");
	      //free_tokens(tokens);
	      puts("finished");
	    }
	}
      else if (userInput[0] == 'q')
	{
	  free_history(history);
	  puts("Bye Bye!");
	  goto exit;
	}
      else
	{
	  puts(userInput);
	  add_history(history, userInput);
	}
    }
 exit:
  return 0;
}

