#ifndef CHAIN_LOADED 
#define CHAIN_LOADED

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>


typedef unsigned long size_t;

typedef struct {
    void** head;
    size_t width;
} Chain;


static const int PTR_SIZE = sizeof(void*);


Chain new_chain(size_t item_size);

bool is_empty(Chain chain);

int length(Chain chain);

void* link(Chain chain);

void* pull(Chain chain, int index);

void* advance(Chain chain, void* node);

void print(Chain chain);

void release(Chain chain);

void disassemble(Chain chain);

#endif

