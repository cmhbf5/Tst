#include "lab7.h"

void printList(List *list) {
	puts("List: ");
	for(int i = 0; i < getSize(list); ++i) {
		printf("%d%s",
				*((int *)getAtIndex(list, i)),
				(i == (getSize(list) - 1) ? "\n" : ", "));
	}
}

void printArray(int *array, int reversed) {
	puts("Expected list:");
	if(reversed) {
		for(int i = array[-1] - 1; i >= 0; --i) {
			printf("%d%s", array[i], (i == 0 ? "\n" : ", "));
		}
	} else {
		for(int i = 0; i < array[-1]; ++i) {
			printf("%d%s", array[i], (i == (array[-1] - 1) ? "\n" : ", "));
		}
	}
}

int main() {
	{ //------------------------------------------------------ SECTION A
		int size = 4;
		int count = size;
		int *array = (int[]){ size, 1, 2, 3, 4 }; ++array;
		void *list = initList();
		while(count--) {
			insertAtIndex(list, &array[count], 0);
		}
		if(getSize(list) != size) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", size, getSize(list));
		} else {
			puts("function [ getSize ] successfully returned the expected size");
		}
		if(insertAtIndex(list, NULL, -10)) {
			fprintf(stderr, "ERROR: insert did not return FALSE on OOB insert attempt");
		}
		if(getAtIndex(list, 0) != &array[0]) {
			fprintf(stderr, "ERROR: [ getAtIndex ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %p, returned %p\n", &array[0], getAtIndex(list, 0));
		} else {
			puts("function [ getAtIndex ] successfully returned expected value");
		}
		printList(list);
		printArray(array, 0);
		if(indexOf(list, &array[2]) != 2) {
			fprintf(stderr, "ERROR: [ indexOf ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n",
					2, indexOf(list, &array[2]));
		} else {
			puts("function [ indexOf ] successfully returned expected value");
		}
		if(removeFromtail(list) != &array[size - 1]) {
			fprintf(stderr, "ERROR: [ removeFromTail ] function returned unexpected value\n");
		} else {
			puts("function [ removeFromTail ] successfully returned expected value");
		}
		if(getSize(list) != (size - 1)) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "function [ getSize ] did not return correct size after remove\n");
		} else {
			puts("function [ getSize ] successfully returned the expected size after remove");
		}
		puts("Freeing list");
		freeList(list);
	} puts("");
	{ //------------------------------------------------------ SECTION B
		int size = 4;
		int count = size;
		int *array = (int[]){ size, 1, 2, 3, 4 }; ++array;
		void *list = initList();
		while(count--) {
			insertAfter(list, &array[count], NULL);
		}
		if(getSize(list) != size) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", size, getSize(list));
		} else {
			puts("function [ getSize ] successfully returned the expected size");
		}
		if(getAtIndex(list, 0) != &array[size - 1]) {
			fprintf(stderr, "ERROR: [ getAtIndex ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %p, returned %p\n", &array[size - 1], getAtIndex(list, 0));
		} else {
			puts("function [ getAtIndex ] successfully returned expected value");
		}
		printList(list);
		printArray(array, 1);
		if(!listContains(list, &array[2])) {
			fprintf(stderr, "ERROR: [ listContains ] function returned unexpected value\n");
			fprintf(stderr, "Expected value TRUE, returned FALSE\n");
		} else {
			puts("function [ listContains ] successfully returned expected value");
		}
		if(removeAtIndex(list, size - 1) != &array[0]) {
			fprintf(stderr, "ERROR: [ removeFromTail ] function returned unexpected value\n");
		} else {
			puts("function [ removeFromTail ] successfully returned expected value");
		}
		if(getSize(list) != (size - 1)) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "function [ getSize ] did not return correct size after remove\n");
		} else {
			puts("function [ getSize ] successfully returned the expected size after remove");
		}
		puts("Freeing list");
		freeList(list);
	} puts("");
	{ //------------------------------------------------------ SECTION C
		int size = 4;
		int count = size;
		int *array = (int[]){ size, 1, 2, 3, 4 }; ++array;
		void *list = initList();
		while(count--) {
			insertAtTail(list, &array[count]);
		}
		if(getSize(list) != size) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", size, getSize(list));
		} else {
			puts("function [ getSize ] successfully returned the expected size");
		}
		if(getAtIndex(list, 0) != &array[size - 1]) {
			fprintf(stderr, "ERROR: [ getAtIndex ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %p, returned %p\n", &array[size - 1], getAtIndex(list, 0));
		} else {
			puts("function [ getAtIndex ] successfully returned expected value");
		}
		printList(list);
		printArray(array, 1);
		if(numberOf(list, &array[2]) != 1) {
			fprintf(stderr, "ERROR: [ numberOf ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", 1, numberOf(list, &array[2]));
		} else {
			puts("function [ numberOf ] successfully returned expected value");
		}
		if(removeBefore(list, &array[2]) != &array[3]) {
			fprintf(stderr, "ERROR: [ removeBefore ] function returned unexpected value\n");
		} else {
			puts("function [ removeBefore ] successfully returned expected value");
		}
		if(getSize(list) != (size - 1)) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "function [ getSize ] did not return correct size after remove\n");
		} else {
			puts("function [ getSize ] successfully returned the expected size after remove");
		}
		puts("Freeing list");
		freeList(list);
	} puts("");
	{ //------------------------------------------------------ SECTION D
		int size = 4;
		int count = size;
		int *array = (int[]){ size, 1, 2, 3, 4 }; ++array;
		void *list = initList();
		while(count--) {
			insertAtHead(list, &array[count]);
		}
		if(getSize(list) != size) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", size, getSize(list));
		} else {
			puts("function [ getSize ] successfully returned the expected size");
		}
		if(getAtIndex(list, 0) != &array[0]) {
			fprintf(stderr, "ERROR: [ getAtIndex ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %p, returned %p\n", &array[size - 1], getAtIndex(list, 0));
		} else {
			puts("function [ getAtIndex ] successfully returned expected value");
		}
		printList(list);
		printArray(array, 0);
		if(lastIndexOf(list, &array[0]) != 0) {
			fprintf(stderr, "ERROR: [ lastIndexOf ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", 0, lastIndexOf(list, &array[0]));
		} else {
			puts("function [ lastIndexOf ] successfully returned expected value");
		}
		if(removeFromtail(list) != &array[size - 1]) {
			fprintf(stderr, "ERROR: [ removeFromtail ] function returned unexpected value\n");
		} else {
			puts("function [ removeFromtail ] successfully returned expected value");
		}
		if(getSize(list) != (size - 1)) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "function [ getSize ] did not return correct size after remove\n");
		} else {
			puts("function [ getSize ] successfully returned the expected size after remove");
		}
		puts("Freeing list");
		freeList(list);
	} puts("");
	{ //------------------------------------------------------ SECTION E
		int size = 4;
		int count = size;
		int *array = (int[]){ size, 1, 2, 3, 4 }; ++array;
		void *list = initList();
		while(count--) {
			insertAtTail(list, &array[count]);
		}
		if(getSize(list) != size) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", size, getSize(list));
		} else {
			puts("function [ getSize ] successfully returned the expected size");
		}
		if(getAtIndex(list, 0) != &array[size - 1]) {
			fprintf(stderr, "ERROR: [ getAtIndex ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %p, returned %p\n", &array[size - 1], getAtIndex(list, 0));
		} else {
			puts("function [ getAtIndex ] successfully returned expected value");
		}
		printList(list);
		printArray(array, 1);
		if(countOccurrences(list, &array[0]) != 1) {
			fprintf(stderr, "ERROR: [ countOccurrences ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", 0, countOccurrences(list, &array[0]));
		} else {
			puts("function [ countOccurrences ] successfully returned expected value");
		}
		if(removeFromHead(list) != &array[size - 1]) {
			fprintf(stderr, "ERROR: [ removeFromtail ] function returned unexpected value\n");
		} else {
			puts("function [ removeFromtail ] successfully returned expected value");
		}
		if(getSize(list) != (size - 1)) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "function [ getSize ] did not return correct size after remove\n");
		} else {
			puts("function [ getSize ] successfully returned the expected size after remove");
		}
		puts("Freeing list");
		freeList(list);
	} puts("");
	{ //------------------------------------------------------ SECTION F
		int size = 4;
		int count = size;
		int *array = (int[]){ size, 1, 2, 3, 4 }; ++array;
		void *list = initList();
		while(count--) {
			insertBefore(list, &array[count], NULL);
		}
		if(getSize(list) != size) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %d, returned %d\n", size, getSize(list));
		} else {
			puts("function [ getSize ] successfully returned the expected size");
		}
		if(getAtIndex(list, 0) != &array[size - 1]) {
			fprintf(stderr, "ERROR: [ getAtIndex ] function returned unexpected value\n");
			fprintf(stderr, "Expected value %p, returned %p\n", &array[size - 1], getAtIndex(list, 0));
		} else {
			puts("function [ getAtIndex ] successfully returned expected value");
		}
		printList(list);
		printArray(array, 1);
		if(hasDuplicates(list, &array[0])) {
			fprintf(stderr, "ERROR: [ hasDuplicates ] function returned unexpected value\n");
			fprintf(stderr, "Expected value FALSE, returned TRUE\n");
		} else {
			puts("function [ hasDuplicates ] successfully returned expected value");
		}
		if(removeAfter(list, &array[1]) != &array[0]) {
			fprintf(stderr, "ERROR: [ removeAfter ] function returned unexpected value\n");
		} else {
			puts("function [ removeAfter ] successfully returned expected value");
		}
		if(getSize(list) != (size - 1)) {
			fprintf(stderr, "ERROR: [ getSize ] function returned unexpected value\n");
			fprintf(stderr, "function [ getSize ] did not return correct size after remove\n");
		} else {
			puts("function [ getSize ] successfully returned the expected size after remove");
		}
		puts("Freeing list");
		freeList(list);
	} puts("");
}
