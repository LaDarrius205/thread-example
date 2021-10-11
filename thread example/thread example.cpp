// thread example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>   
#include <mutex>    
#include <condition_variable>
#include <chrono>

using namespace std;
mutex mutex1; // Declaring a mutex
condition_variable con_var; // Declaring a mutex
int x = 0; 

//Void function
void waits() {
    unique_lock<mutex> locked(mutex1);
    cout << "waiting...\n";

    con_var.wait(locked, []() {return x == 1; });

    cout << "...finished waiting. x ==1\n";
}
//Void function
void signal() {
    this_thread::sleep_for(chrono::seconds(1));
    cout << "Notifying...\n";

    con_var.notify_all();

    this_thread::sleep_for(chrono::seconds(1));
    x = 1;
    cout << "Notifying Againg...\n";
    con_var.notify_all();
}


int main()
{
    vector<thread> threads; 
    for (int i = 0; i < 4; ++i)
    {
        threads.push_back(thread(waits));
    }

    thread s_thread(signal);

    for (auto& thread : threads)
    {
        thread.join();
    }

    printf("press enter to continue\n");
    getchar();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
