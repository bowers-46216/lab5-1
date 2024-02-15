#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  char letter;
  struct node *next;
} node;

// Returns number of nodes in the linkedList.
int length(node *head) {

  int counter = 0;
  node *temp = head;
  while (temp != NULL) {//while not the last node
    counter++;//increment over list
    temp = temp->next;//traverse
  }

  return counter;//returns length
}

// parses the string in the linkedList
//  if the linked list is head -> |a|->|b|->|c|
//  then toCString function wil return "abc"
char *toCString(node *head) {

  int listLength = length(head);//get length from function
  node *temp = head;//for traversal

  const int MAX_VAL = listLength;//max chars will be length of linked list
  char *newString = (char *)malloc(MAX_VAL + 1 * sizeof(char));//allocate string

  for (int i = 0; i < listLength; i++) {//while not end of list
    newString[i] = temp->letter;//assign vals
    temp = temp->next;//traverse
  }

  return newString;//return string
}

// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node **pHead, char c) {

    struct node* newNode = (struct node*) malloc(sizeof(node));//allocate new letter node
    newNode->letter  = c;//assign letter
  
  	struct node* temp = *pHead;//make temp for traversal
	newNode->next = NULL;//last node points to NULL

    if (*pHead == NULL) {//if head is NULL (list empty)
       *pHead = newNode;//new node is head
       return;//exit function
    }
	//else
    while (temp->next != NULL) {//while not the end of the list
		temp = temp->next;//traverse
	}

    temp->next = newNode;//node after last node is new node
    return;    

}

// deletes all nodes in the linkedList.
void deleteList(node **pHead) {

  node *temp = *pHead;

  while (temp != NULL) {//while not last node
    *pHead = temp->next;//traverse
    free(temp);//free memory from node
    temp = *pHead;
  }

  *pHead = NULL;
}

int main(void) {
  int i, strLen, numInputs;
  node *head = NULL;
  char *str;
  char c;
  FILE *inFile = fopen("input.txt", "r");

  fscanf(inFile, " %d\n", &numInputs);

  while (numInputs-- > 0) {
    fscanf(inFile, " %d\n", &strLen);
    for (i = 0; i < strLen; i++) {
      fscanf(inFile, " %c", &c);
      insertChar(&head, c);
    }

    str = toCString(head);
    printf("String is : %s\n", str);

    free(str);
    deleteList(&head);

    if (head != NULL) {
      printf("deleteList is not correct!");
      break;
    }
  }

  fclose(inFile);
}