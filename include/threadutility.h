#include <thread>    // for Threading
#include <iostream>
#include <stdlib.h>  //for using the function sleep
#include <unistd.h>

void threadFunction(int id);

void myThreading();

void threading_and_heap();

void workFunc(int* ptr, size_t times);