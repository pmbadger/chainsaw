#include "chain/chain.h"


Chain new_chain(size_t width) {
    Chain chain;
    chain.width = width;
    chain.head = malloc(PTR_SIZE);
    return chain;
}

bool is_empty(Chain chain) {
	return *chain.head == NULL;
}

void* link(Chain chain) {
	int node_size = chain.width + PTR_SIZE;
	void* new_node = malloc(node_size);
	memset(new_node, 0, node_size);

	if (is_empty(chain)) {
		*chain.head = new_node;
	} else {
		void** node = chain.head;
    	while (*node) {
        	node = *node;
        	node = (void**)((size_t)node + chain.width);
		}
    	*node = new_node;
	}

    return new_node;
}

void* pull(Chain chain, int index) {
	if (!is_empty(chain)) {
		void** node = chain.head;
		int i = 0;
    	while (*node) {
        	node = *node;
			if (i == index) return node;
        	node = (void**)((size_t)node + chain.width);
			i++;
		}
	}
    return NULL;
}

void print(Chain chain) {
	if (is_empty(chain)) {
		printf("Chain nodes: ");
	} else {
		void** node = chain.head;
		while (*node) {
			node = *node;
			printf("%d ", *(int*)node);
			node = (void**)((size_t)node + chain.width);
		}
		printf("\n");
	}
}

void release(Chain chain) {
	if (!is_empty(chain)) {
		void** node = chain.head;
		void* killer = NULL;
		while (*node) {
			node = *node;
			if (killer) {
				free(killer);
			}
			killer = node;
			node = (void**)((size_t)node + chain.width);
		}
		free(killer);
		*chain.head = NULL;
	}
}


void disassemble(Chain chain) {
	release(chain);
	free(chain.head);
}

