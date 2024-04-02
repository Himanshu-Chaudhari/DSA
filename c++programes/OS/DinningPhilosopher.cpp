// #include <unistd.h>
// #include <iostream>
// #include <thread>
// #include <mutex>
// #include <chrono>
// #include<iostream>
// #include<pthread.h>
// #include<mutex>
// #include<condition_variable>
// using namespace std;
// const int num_philosophers = 5;
// mutex forks[num_philosophers];
// condition_variable cv[num_philosophers];

// // Function for the philosopher's behavior
// void dine(int id) {
//     int left_fork = id;
//     int right_fork = (id + 1) % num_philosophers;

//     while (true) {
//         // Acquire left and right forks
//         unique_lock<std::mutex> left_lock(forks[left_fork]);
//         unique_lock<std::mutex> right_lock(forks[right_fork]);

//         // Wait until both forks are available
//         cv[left_fork].wait(left_lock, [&] { return !forks[left_fork].try_lock(); });
//         cv[right_fork].wait(right_lock, [&] { return !forks[right_fork].try_lock(); });

//         // Philosopher is eating
//         cout << "Philosopher " << id << " is eating." << std::endl;

//         // Philosopher is thinking
//         cout << "Philosopher " << id << " is thinking." << std::endl;

//         // Release forks
//         left_lock.unlock();
//         right_lock.unlock();
//         cv[left_fork].notify_one();
//         cv[right_fork].notify_one();
//     }
// }

// int main() {
//     thread philosophers[num_philosophers];

//     // Create philosopher threads
//     for (int i = 0; i < num_philosophers; ++i) {
//         philosophers[i] = std::thread(dine, i);
//     }

//     // Join philosopher threads
//     for (int i = 0; i < num_philosophers; ++i) {
//         philosophers[i].join();
//     }

//     return 0;
// }



#include<iostream> 
#include<mutex>
#include<thread>
#include<chrono>
#include<pthread.h>
#include<condition_variable>
#include<unistd.h>
using namespace std;
const int no_phil = 5;
mutex forks[no_phil];
condition_variable cv[no_phil];


void dine(int id){
    int left_fork = id;
    int right_fork = (id+1)%no_phil;

    unique_lock<mutex> left_lock(forks[left_fork]);
    unique_lock<mutex> right_lock(forks[right_fork]);

    cv[left_fork].wait(left_lock, [&]{return !forks[left_fork].try_lock();});
    cv[right_fork].wait(right_lock, [&]{return !forks[right_fork].try_lock();});

    cout<<"phil is eating"<<endl;
    cout<<"phil is thinking"<<endl;

    left_lock.unlock();
    right_lock.unlock();

    cv[left_fork].notify_one();
    cv[right_fork].notify_one();
    
}

int main(){
    thread phil[no_phil];

    for(int i=0;i<no_phil;i++){
        phil[i] = thread(dine, i);
    }

    for(int i=0;i<no_phil;i++){
        phil[i].join();
    }
}

