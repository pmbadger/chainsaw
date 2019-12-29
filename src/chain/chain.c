#include "chain.h"


Chain new_chain(size_t width) {
    Chain chain;
    chain.width = width;
    chain.head = malloc(PTR_SIZE);
    return chain;
}

bool is_empty(Chain chain) {
    return *chain.head == NULL;
}

void* advance(Chain chain, void* node) {
    return (void**)((size_t)node + chain.width);
}

int length(Chain chain) {
    int length = 0;
    for (
        void** node = chain.head;
        (node = *node);
        node = advance(chain, node)
    ){
        length++;
    }
    return length;
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
            node = advance(chain, node);
        }
        *node = new_node;
    }

    return new_node;
}

void* pull(Chain chain, int index) {
    if (!is_empty(chain)) {
        int i = 0;
        for (
            void** node = chain.head;
            (node = *node);
            node = advance(chain, node)
        ){
            if (i == index) return node;
            i++;
        }
    }
    return NULL;
}

void print(Chain chain) {
    if (is_empty(chain)) {
        printf("Chain nodes: ");
    } else {
        for (
            void** node = chain.head;
            (node = *node);
            node = advance(chain, node)
        ){
            printf("%d ", *(int*)node);
        }
        printf("\n");
    }
}

void release(Chain chain) {
    if (!is_empty(chain)) {
        void* killer = NULL;
        for (
            void** node = chain.head;
            (node = *node);
            node = advance(chain, node)
        ){
            if (killer) {
                free(killer);
            }
            killer = node;
        }
        free(killer);
        *chain.head = NULL;
    }
}


void disassemble(Chain chain) {
    release(chain);
    free(chain.head);
}

