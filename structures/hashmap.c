#include "hashmap.h"

void initTable(Table* table) {
	table->count = 0; 
	table->capacity = 0; 
	table->entries = NULL;
}

void printTable(Table* table) {
	Entry* entries = table->entries;
	for(int i = 0; i < table->capacity; i++) {
		printf("[%d]", entries[i]);
	}
}

Entry* findEntry(Entry* entries, int capacity, ObjString* key) {
	uint32_t index = key->hash & (capacity - 1);

	Entry* tombstone = NULL;

	for(;;) {
		Entry* entry = &entries[index];
		if (entry->key == NULL) {
			if (entry->value == NULL) {
				return tombstone != NULL ? tombstone : entry;
			} else {
				if (tombstone == NULL) tombstone = entry;
			}
		} else if (entry->key == key) {
			return entry;
		}
	}
	index = (index + 1) & (capacity - 1);
}

bool tableAdd(Table* table, ObjString* key, Value* value) {
	if (table->count + 1 > table->capacity * TABLE_MAX_LOAD) {
		int capacity = GROW_CAPACITY(table->capacity);
	}
	return false;
}

int main() {

	// tests

	Table* table; 
	initTable(table);



	return 0;
}