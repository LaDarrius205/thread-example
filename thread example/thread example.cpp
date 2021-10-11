// thread example.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>
#include <future>  
#include <chrono>

using namespace std;

// not declaring a function as global you can still pass it to another function by adding it by reference.
void The_Ultimate_Question(promise<int>  & promise_int){
    std::lock_guard<mutex> guard1();
    cout << "Pan-dimensional beings -> What is the answer to" << endl << "life, the universe, and everything?" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Deep thought -> Thinking............." << endl;
    this_thread::sleep_for(chrono::seconds(10));
    cout << "The narator -> 7 1/2 Million Years Later" << endl;
    this_thread::sleep_for(chrono::seconds(3));
    cout << "Deep thought -> The answer to life, the universe, and everything is........" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Pan-dimensional beings -> Yes, Yes ... tell us we've waited so long" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Deep thought -> The answer to life, the universe, and everything is ...." << endl;
    this_thread::sleep_for(chrono::seconds(4));

    promise_int.set_value(42);

    this_thread::sleep_for(chrono::seconds(2));
    cout << "Pan-Dimensional beings -> 42 ? , what? Are you sure?" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Deep thought -> Yes, Yes I'm sure, that's it 42 " << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Pan-Dimensional beings -> 42 ? , what a meaningless answer.. stupid computer" << endl;
    this_thread::sleep_for(chrono::seconds(2));
    cout << "Deep thought -> How can i answer your question, " << endl << "when you don't even know what the question is "<<endl;
}


int main()
{
    promise <int> promise_int;
    future <int> future_int = promise_int.get_future();
    thread worker(The_Ultimate_Question, ref(promise_int));
    cout << "Deep thought ->" << future_int.get() << endl;

    worker.join();
    printf("Press enter to continue\n");
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
