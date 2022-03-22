#include "MemComBarriers.h"

bool sense = false;
int counter = 0;
int P = 0;
unsigned long * d = 0; // pointer to the dictionary of actual thread ids and user-friendly ids


void * cBarrier(void * p) { // code for Centralized Barrier
    unsigned long * id = (long unsigned *) &p;
    int ID = 0;
    
    for (int i = 0; i<P; i++) {
        if (d[2*i+1] == (unsigned long) *id) {
            ID = (int) d[2*i];
            break;
        }
    }
    bool local_sense = ! sense;
    printf("Thread %i arrived\n", ID);
    if (++counter == P) {
        counter = 0;
        sense = local_sense;
        printf("Sense switched by thread %i\n", ID);
    } else {
        while (sense != local_sense) { /* spin */
        usleep(100);
        }
    }
    printf("Thread %i passed\n", ID);
    
    return NULL;
}


// void dBarrier(int * P) { // code for Dissemination Barrier
//     for (round = 0 to rounds - 1) {
//         partner = (tid + 2^round) mod P;
//         flags[partner][parity][round] = !sense;
//         while (flags[tid][parity][round] == sense) { /* spin */ }
//         }
//     if (parity == 1) {
//         sense = !sense;
//     }
//     parity = 1 - parity;
// }

// for simplicity, assume P power of 2
// void mcsBarrier(int tid) { // code for MCS Barrier (actually Tournament Barrier - needs to be edited)
//     int round;
//     for (round = 0; /* wait for children (depth == first 1)*/ ((P | tid) & (1 << round)) == 0; round++) {
//         while (flags[tid][round] != sense) { /* spin */ }
//     }
//     if (round < logP) { // signal + wait for parent (all but root)
//         int parent = tid & ~((1 << (round+1)) - 1);
//         flags[parent][round] = sense;
//         while (flags[tid][round] != sense) { /* spin */ }
//     }
//     while (round-- > 0) { // wake children
//         int child = tid | (1 << round);
//         flags[child][round] = sense;
//     }
//     sense = !sense;
// }


// void * thread


int main() {
    int barrier = 0;
    char * barriers[] = {"Centralized Barrier", "Dissemination Barrier", "MCS Barrier", "something invalid"};
    while (true) {
        barrier = 0;
        printf("\nBarriers:\n 1 : Centralized Barrier\n 2 : Dissemination Barrier\n 3 : MCS Barrier\n\n Enter the number of desired barrier: ");
        scanf("%d", &barrier);
        if (barrier == 1 || barrier == 2 || barrier == 3) {
            break;
        } else {
            barrier = 4;
        }
        printf(" You chose %s, pick again.\n", barriers[barrier-1]);
        usleep(1200000);
    }
    printf("\n Enter the number of threads you would like to synchronize (maxes at 32): ");
    scanf("%d", &P);
    if (P > 32) {
        P = 32;
    }
    printf(" Number of Threads = %d\n\n", P);

    pthread_t thr[P];
    d = (unsigned long *) calloc(P, sizeof(unsigned long));
    if (barrier == 1) { // Centralized Barrier
        for (int i=0; i<P; i++) {
            usleep(100);
            pthread_create(&thr[i], NULL, cBarrier, (void *)&thr[i]);
            d[2*i] = (unsigned long) i+1;
            d[2*i+1] = (unsigned long) &thr[i];;
            usleep(1000); // this is the lowest order of magnitude that doesn't cut off thread spinning
            // pthread_join(thr[i], NULL);
        }

    } else if (barrier == 2) { // Dissemination Barrier
        // const int rounds = log(P);
        // bool flags[P][2][rounds]; // allocated in local storage per thread
        // local bool sense = false;
        // local int parity = 0;

    } else { // MCS Barrier


    }

    // printf("\nI didn't make time for this assingnment as early as I should have. Travel and other obligations got in the way of getting it done.\nI hope there'll be a chance to make it up or something at some point. It's frustrating. Still, have a great break!\n\n");

    // pthread_t thread; // this declares the thread
    // pthread_create(&thread, NULL, func, NULL);
    // printf("From this function, the thread id is %d\n", thread);
    // pthread_join(thread, NULL); // join with the main thread

    free(d);
    return 0;

}
