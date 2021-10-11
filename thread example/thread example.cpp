// thread example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <vector>   
#include <mutex>    

using namespace std;
std::mutex mutex1;

void helloWorld() {
    std::lock_guard<mutex> guard1(mutex1);
    cout << "hello World from thread" << this_thread::get_id() << endl;
}


int main()
{
    vector<thread> threads; 
    for (int i = 0; i < 5; ++i)
    {
        threads.push_back(thread(helloWorld));
    }

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
