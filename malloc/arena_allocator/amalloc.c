#include "amalloc.h"

int is_power_of_two(uintptr_t num) {
	return (num & (num - 1)) == 0;
}

uintptr_t align_forward(uintptr_t ptr, size_t align) {
	
}

typedef struct Arena {
	unsigned char *buf;
	size_t buf_len;
	size_t prev_offset;
	size_t curr_offset;
} Arena;

Arena *arena;

void *arena_alloc_align(Arena *a, size_t size, size_t align) {

}

void arena_init() {

}

void arena_alloc() {

}

void arena_free() {

}

void arena_resize() {

}


void *amalloc(size_t size) {

	if (size == 0) {
		return NULL;
	}



	return 0;
}

