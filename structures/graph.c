#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct graph {
	int numnodes; 
	bool **edges;
} graph; 

void destroy_graph(graph* g) {
	 if (g->edges == NULL) {
		return;
	 }

	for (int i = 0; i < g->numnodes; i++) {
		free(g->edges[i]);
	}

	free(g->edges);
	free(g);
}

graph *create_graph(int numnodes) {
	graph* g = malloc(sizeof(*g));
	if (g == NULL) {
		return NULL;
	}

	g->numnodes = numnodes;

	// allocate our matrix 
	g->edges = calloc(sizeof(bool*), g->numnodes);
	if (g->edges == NULL) {
		free(g);
		return NULL;
	}

	for (int i = 0; i < g->numnodes; i++) {
		g->edges[i] = calloc(sizeof(bool), g->numnodes);
		if (g->edges[i] == NULL) {
			destroy_graph(g);
			return NULL;
		}
	}
	return g;
}


void print_graph(graph* g) {
	printf("digraph {\n");

	for (int from=0; from < g->numnodes; from++) {
		for (int to=0; to < g->numnodes; to++) {
			if (g->edges[from][to]) {
				printf("%d -> %d;\n", from, to);
			}
		} 
	}
	printf("}\n");
}

bool has_edge(graph* g, unsigned int from_node, unsigned int to_node) {
	assert(g != NULL);
	assert(from_node < g->numnodes); 
	assert (to_node < g->numnodes);
	return false;
}

bool add_edge(graph* g, unsigned int from_node, unsigned int to_node) {
	if (has_edge(g, from_node, to_node)) {
		return false;
	}

	g->edges[from_node][to_node] = true;
	return true;
}



int main() {
	graph *g1 = create_graph(5);

	add_edge(g1, 0, 1);
	add_edge(g1, 0, 2);
	add_edge(g1, 0, 0);
	add_edge(g1, 1, 2);
	add_edge(g1, 1, 3);
	add_edge(g1, 3, 4);
	add_edge(g1, 4, 1);
	add_edge(g1, 4, 0);

	print_graph(g1);
	destroy_graph(g1);
	return 0; 
}