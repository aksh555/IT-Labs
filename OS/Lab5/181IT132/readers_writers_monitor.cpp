// Execution: g++ readers_writers_monitor.cpp -lpthread && ./a.out

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <semaphore.h>
# include<bits/stdc++.h>
using namespace std; 

// monitor
struct monitor_DataType {
          sem_t read;
          sem_t write;
          int rcount;
          int writes;
          int reads;
};
struct monitor_DataType monitor_data; 

void monitor_StartWrite() {
          if(monitor_data.writes || monitor_data.rcount != 0){
                sem_wait(&(monitor_data.write));
          }
          monitor_data.writes++;   
}

void monitor_EndWrite() {
          monitor_data.writes--;
          if(monitor_data.reads){
            sem_post(&(monitor_data.read));
          } else {
            sem_post(&(monitor_data.write));
          }
}

void monitor_StartRead() {
          if(monitor_data.writes){
                monitor_data.reads++;
                sem_wait(&(monitor_data.read));
                monitor_data.reads--;
          }
          monitor_data.rcount++;
          sem_post(&(monitor_data.read));
}

void monitor_EndRead() {
          monitor_data.rcount--;
          if(monitor_data.rcount == 0){
            sem_post(&(monitor_data.write));
          }
}

// intialize the monitor
int monitor_Initialized(){  
        int val = 1;
        // Initialize the structure
        monitor_data.rcount = 0;
        monitor_data.writes = 0;
        monitor_data.reads = 0;
        // initialize the semaphores
        if(sem_init(&(monitor_data.write), 0, 1) == 0 && 
           sem_init(&(monitor_data.read), 0, 1) == 0){
                val = 0;
        } else {
             cout<<"Unable to initialize semaphores\n";
        }
        return val;
}

void monitor_Destroy(){
      sem_destroy(&(monitor_data.write));
      sem_destroy(&(monitor_data.read));
}
int main() {
       if(monitor_Initialized() == 0){
         cout << "Initialized\n";
         monitor_StartWrite();
         cout << "Writing data\n";
         monitor_EndWrite();
         monitor_StartRead();
         cout << "Reading data\n";
         monitor_EndRead();
         monitor_Destroy();
       }
      return 0;
}              
