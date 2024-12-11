#include "types.h"
#include "stat.h"
#include "user.h"

#define ALLOCATION_SIZE 128 * 1024  
#define MEMORY_LIMIT 512*1024   
#define MAX_ALLOCS 10

int main() {
    int i;
    void* ptr[MAX_ALLOCS];  

    set_limit(0, MEMORY_LIMIT);

    for (i = 0; i < MAX_ALLOCS; i++) {
        ptr[i] = malloc(ALLOCATION_SIZE);
        if (ptr[i] == 0) {
            printf(1, "Allocation failed at iteration %d\n", i);
        } else {
            increase_memory_usage(ALLOCATION_SIZE);
            printf(1, "Allocation succeeded at iteration %d\n", i);
        }
        
    }

    for (i = 0; i < MAX_ALLOCS; i++) {
        if (ptr[i] != 0) {
            free(ptr[i]);  
            decrease_memory_usage(ALLOCATION_SIZE);  
            printf(1, "Freed memory at iteration %d\n", i);
        }
    }
    for (i = 0; i < MAX_ALLOCS; i++) {
        ptr[i] = malloc(ALLOCATION_SIZE);
        if (ptr[i] == 0) {
            printf(1, "Allocation failed at iteration %d\n", i);
        } else {
            increase_memory_usage(ALLOCATION_SIZE);
            printf(1, "Allocation succeeded at iteration %d\n", i);
        } 
    }
    printf(1, "Test finished\n");
    exit();
}