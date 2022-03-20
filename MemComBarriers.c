#include "MemComBarriers.h"

// void * func(void * p) {
//     printf("Thread id = %d\n", pthread_self()); // get current thread id
//         pthread_exit(NULL);
//     return NULL;
// }

// struct barrier {
//     int arrived;
//     int left;
//     int sense;
// }

// void * barrier(int type, int Nthreads) {
//     pthread_t threads[Nthreads];
//     int arrived;
//     int left;
//     bool sense;
// }

// void barrier(p) {
//         bool local = !sense;
//         if }

// void CentralizedBarrier (int Num,)
//     int counter = 1;
//     bool sense = false;
    

int main() {
    int barrier = 0;
    char * barriers[] = {"Centralized Barrier", "Dissemination Barrier", "MCS Barrier", "something invalid"};
    while (1) {
        printf("\nBarriers:\n 1 : Centralized Barrier\n 2 : Dissemination Barrier\n 3 : MCS Barrier\n\n Enter the number of desired barrier: ");
        scanf("%d", &barrier);
        if (barrier < 1 || barrier > 3) {
            barrier = 4;
        } else {
            break;
        }
        printf(" You chose %s, pick again.\n", barriers[barrier-1]);
        usleep(1500000);
    }
    int Num = 0;
    printf("\n Enter the number of threads you would like to synchronize (maxes at 100): ");
    scanf("%d", &Num);
    if (Num > 100) {
        Num = 100;
    }
    printf(" Number of Threads = %d\n", Num);

    printf("\nI didn't make time for this assingnment as early as I should have. Travel and other obligations got in the way of getting it done.\nI hope there'll be a chance to make it up or something at some point. It's frustrating. Still, have a great break!\n\n");

    // pthread_t thread; // this declares the thread
    // pthread_create(&thread, NULL, func, NULL);
    // printf("From this function, the thread id is %d\n", thread);
    // pthread_join(thread, NULL); // join with the main thread


    return 0;

}
