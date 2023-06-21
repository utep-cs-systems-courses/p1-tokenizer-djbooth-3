#include "stdio.h"

typedef struct BstNode_s {
  struct BstNode_s *children[2];
  char *str;
} BstNode;

BstNode *bstRoot;

void bstInsert(BstNode **rootp, char *str);
void bstPrint(BstNode *root);
void bstClear(BstNode **rootp);

