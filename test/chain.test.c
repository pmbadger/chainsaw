#include "chain/chain.h"
#include "unittest/unittest.h"


int main() {
    Chain items = new_chain(sizeof(int));
    unit_test(is_empty(items), "Newly created chain is empty");

    void* head = *items.head; 
    int* item = (int*)link(items);
    unit_test(!is_empty(items), "After linking an item chain is not empty anymore");
    unit_test(item == (int*)pull(items, 0), "Pulling newly linked item returns its actuall address");

    link(items);
    link(items);
    release(items);
    unit_test(is_empty(items), "After release chain is empty again");

    link(items);
    link(items);
    unit_test(!is_empty(items), "But it is still reconstructable");

    disassemble(items);
    unit_test(head != *items.head, "After disassembling all memory is freed");

    return report();
}

