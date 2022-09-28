/*
  part-3-task-1-pthreads.cpp
  A very simple example demonstrating the usage of pthreads.
  Compile: g++ -o part-3-task-1-pthreads part-3-task-1-pthreads.cpp -lpthread
  Execute: ./pthreads_demo

  Used pthreads code from professor
*/

#include <pthread.h>
#include <stdio.h>
#include <iostream>
#include <time.h>

using namespace std;

// The thread
void *thread_func_1(void *data)
{
    char *tname = (char *)data;

    // print thread name
    while (1)
        printf("My thread identifier is %s\n", tname);

    pthread_exit(0);
}

void *thread_func_2(void *arg)
{
    int counter = 1;

    // Increment counter every cycle
    while (1)
    {
        counter += 1;
        cout << "Curent Counter: " << counter << "\n";
    }

    pthread_exit(0);
}

void *thread_func_3(void *arg)
{
    int number;

    // initialize seed
    srand(time(NULL));

    while (1)
    {
        // generate random number from 1 to 2
        number = rand() % 2 + 1;

        // if 1, print heads, if 2 print tails
        if (number == 1)
            cout << "Heads\n";
        else if (number == 2)
            cout << "Tails\n";
    }

    pthread_exit(0);
}

int main()
{
    pthread_t id1, id2, id3;                                // thread identifiers
    pthread_attr_t attr1, attr2, attr3;                     // set of thread attributes
    char *tnames[3] = {"Thread 1", "Thread 2", "Thread 3"}; // names of threads
    // get the default attributes
    pthread_attr_init(&attr1);
    pthread_attr_init(&attr2);
    pthread_attr_init(&attr3);

    // create the threads
    pthread_create(&id1, &attr1, thread_func_1, tnames[0]);
    pthread_create(&id2, &attr2, thread_func_2, NULL);
    pthread_create(&id3, &attr3, thread_func_3, NULL);

    // wait for the threads to exit
    pthread_join(id1, NULL);
    pthread_join(id2, NULL);
    pthread_join(id3, NULL);

    return 0;
}
