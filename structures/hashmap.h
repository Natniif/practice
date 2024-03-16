#include <stdlib.h>
#include <string.h>	
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

#define TABLE_MAX_LOAD 0.75

#define ALLOCATE(type, count) \ 
	(type*)reallocate(NULL, 0, sizeof(type) * (count))

#define FREE(type, pointer) reallocate(pointer, sizeof(type), 0)

#define GROW_CAPACITY(capacity) \
	((capacity) < 8 ? 8 : (capacity) * 2)

typedef struct Obj {
	struct Obj* next;
} Obj;

typedef struct ObjString {
	Obj obj; 
	int length;
	char* chars; 
	uint32_t hash;
} ObjString;

typedef uint64_t Value;

typedef struct Entry {
	ObjString* key;
	Value value;
} Entry;

typedef struct Table {
	int count;
	int capacity; 
	Entry *entries;
} Table;