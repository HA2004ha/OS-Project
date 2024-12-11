#include "types.h"
#include "stat.h"
#include "user.h"

void loop(int loop) {
    volatile int i, j;
    for (i = 0; i < loop; i++) {
        continue;
    }
}

int main() {
    printf(1, "=== CPU Limit Tests ===\n");
    // test
    printf(1, "\n--- Task without CPU Limit ---\n");
    int start_time = uptime();
    loop(1e9);
    int end_time = uptime();
    int base_time = end_time - start_time;
    printf(1, "Task without limit completed in %d ticks\n", base_time);

    // 25 test
    printf(1, "\n--- Task with 25% CPU Limit ---\n");
    set_limit(25);
    start_time = uptime();
    loop(1e9);
    end_time = uptime();
    int limited_time_25 = end_time - start_time;
    printf(1, "Task with 25%% limit completed in %d ticks\n", limited_time_25);
    
    // 50 test
    printf(1, "\n--- Task with 50% CPU Limit ---\n");
    set_limit(50);    
    start_time = uptime();
    loop(1e9);
    end_time = uptime();
    int limited_time_50 = end_time - start_time;
    printf(1, "Task with 50%% limit completed in %d ticks\n", limited_time_50);

    // 75 test
    printf(1, "\n--- Task with 75% CPU Limit ---\n");
    set_limit(75);    
    start_time = uptime();
    loop(1e9);
    end_time = uptime();
    int limited_time_75 = end_time - start_time;
    printf(1, "Task with 75%% limit completed in %d ticks\n", limited_time_75);
    

    if (limited_time_25 <= base_time * 1.1 || limited_time_75 <= base_time * 1.1 || limited_time_50 <= base_time * 1.1) {
        printf(1, "CPU limit NOT effectively implemented!\n");
    } else {
        printf(1, "CPU limit appears to be working correctly\n");
    }

    exit();
}