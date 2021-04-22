#include <stdio.h>
#include <stdlib.h>

#define COMMON
// partial typedef, so the Node type can contain itself
typedef struct Node Node;

struct Node {
	Node *next;
	void *data;
};

typedef struct {
	Node *head;
	int size;
} List;

List* initList();
int getSize(List *list);
void freeList(List *list);
void* getAtIndex(List *list, int index);

#define SECT_A
int insertAtIndex(List *list, void *object, int index);
int indexOf(List *list, void *object);
void* removeFromtail(List *list);

#define SECT_B
int insertAfter(List *list, void *object, void *sentinel);
int listContains(List *list, void *object);
void* removeAtIndex(List *list, int index);

#define SECT_C
int insertAtTail(List *list, void *object);
int numberOf(List *list, void *object);
void* removeBefore(List *list, void *sentinel);

#define SECT_D
int insertAtHead(List *list, void *object);
int lastIndexOf(List *list, void *object);
//void* removeFromtail(List *list);

#define SECT_E
//int insertAtTail(List *list, void *object);
int countOccurrences(List *list, void *object);
void* removeFromHead(List *list);

#define SECT_F
int insertBefore(List *list, void *object, void *sentinel);
int hasDuplicates(List *list, void *object);
void* removeAfter(List *list, void *sentinel);































