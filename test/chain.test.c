#include "chain.h"
#include "unittest.h"


int main() {
    Chain items = new_chain(sizeof(int));
    unit_test(is_empty(items), "Newly created chain is empty");
    unit_test(length(items) == 0, "Which means it has length of zero");

    void* head = *items.head; 
    int* item = (int*)link(items);
    unit_test(!is_empty(items), "After linking an item chain is not empty anymore");
    unit_test(item == (int*)pull(items, 0), "Pulling newly linked item returns its actuall address");

    link(items);
    link(items);
    unit_test(length(items) == 3, "Adding items increases chain's length");

    release(items);
    unit_test(is_empty(items), "After release chain is empty again");

    link(items);
    link(items);
    unit_test(!is_empty(items), "But it is still reconstructable");

    disassemble(items);
    unit_test(head != *items.head, "After disassembling all memory is freed");

    return report();
}

