//Martin Phillip
//Kylee Webb
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include<semaphore.h>
#include <unistd.h>
#include "bots.h"
using namespace std;
sem_t FLAG;
ofstream Fl;
//the bot function where each thread will print to
void *bot(void *t)
{         
    //this will helps keep track of even and odd threads
    long threadID = (long) t;
    for (int i = 0; i<8; i++){
        //critical section
        sem_wait(&FLAG);        
        Fl.open("QUOTE.txt",std::fstream::app);
        if(threadID%2==0)
        {
           Fl<<"The thread's tid "<<pthread_self()<<" Controlling complexity is the essence of computer programming."<<"\r\n"; 
           
        }else{
           Fl<<"The thread's tid "<<pthread_self()<<" Computer science is no more about computers than astronomy is about telescopes."<<"\r\n";
       
        }
        
        printf("Thread <%ld> is running\n",pthread_self());
        Fl.close();
        sem_post(&FLAG);
        //end of critical section
        
        //make the thread sleep after opening and clsoing the QUOTE.txt
        if(threadID%2==0)
        {
            sleep(2);  
        }else{
            sleep(3);
        }
    }
    pthread_exit((void*)t);

}


int main(int argc, char *argv[])
{
    //array to hold our threads 
    pthread_t thread[NUM_Of_THREADS];
    pthread_attr_t attr; 

    //writing the Process ID (pid) to file
    Fl.open("QUOTE.txt");
    Fl<<(int)getpid()<<"\r\n";
    Fl.close();

    /*initialising semaphore*/
    sem_init(&FLAG, 0, 1);  
    // initialize the thread attribute object and set the detachstate to Joinable
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    
    //creating 7 threads using the bot function, the theread attubute object and passing the number of the thread.
    int error;
    for(long thrd=0; thrd<NUM_Of_THREADS; thrd++) {
        error = pthread_create(&thread[thrd], &attr, bot, (void *)(thrd+1));
        if (error) {
            printf("ERROR; %d\n", error);
            exit(-1);
        }
    }
   
    // handling the threads before the main process ends
    pthread_attr_destroy(&attr);
    for(long thrd=0;thrd<NUM_Of_THREADS;thrd++){
        void *s;
        error = pthread_join(thread[thrd], &s);
        if (error) {
            printf("ERROR; %d\n", error);
            exit(-1);
        }
       
    }

    //destroying the semaphore and print message 
    sem_destroy(&FLAG);
    
    printf("Program is done. Yay!\n");
    pthread_exit(NULL);

}



















