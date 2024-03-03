#include <threadutility.h>

// Function to be executed in a separate thread
void threadFunction(int id) {
    std::cout << "Hello from thread " << id << std::endl;
    // Do something
    sleep(1); // sleep for 1 second
    std::cout << "Finished execution of thread " << id << std::endl;
}

void myThreading() {
    const int numThreads = 5;
    std::thread threads[numThreads];

    // Launch a group of threads
    for (int i = 0; i < numThreads; ++i) {
        threads[i] = std::thread(threadFunction, i);
    }

    std::cout << "Hello from the main thread" << std::endl;

    // Join the threads with the main thread
    for (int i = 0; i < numThreads; ++i) {
        threads[i].join();
    }

    return;
}


void workFunc(int* ptr, size_t times)
{
	while(times--) {
		*ptr += 1;
	}
}


void threading_and_heap()
{
	int* numbers = new int[3];

	std::thread t1(workFunc, numbers, 500);
	std::thread t2(workFunc, numbers + 1, 600);
	std::thread t3(workFunc, numbers + 2, 700);

    /*
    Detaching a thread means allowing it to work and complete it’s work independently of the main thread. But, this can be dangerous. The first risk here is using the heap-allocated after it’s deleted. Unlike join() , detach() does not make the calling thread stop or wait for anything. This means as soon as the third call to detach() ends, the calling thread will delete the numbers array. If the created threads haven’t finished their work, they will be writing to a deleted array, which corrupts memory. The second risk here is that the created threads can keep running even after the main thread finishes, if their work is not completed. Or they might be killed as soon as main ends. This is undefined behavior according to the C++ standard. 
    */
    // t1.detach();
	// t2.detach();
	// t3.detach();

    /*
    The main thread wait for them to complete their assigned work.
    */
	t1.join();
	t2.join();
	t3.join();

	for(int i = 0; i < 3; ++i)
		std::cout << "Number Slot " << (int)i << " is " << (int)numbers[i] << std::endl;

	delete[] numbers;
	return;
}

// #include <mutex>

// std::mutex myMutex;

// // ...

// void sharedResourceAccessFunction() {
//     std::lock_guard<std::mutex> lock(myMutex);
//     // Code to access shared resource
// }

// #include <semaphore>

// std::counting_semaphore<int> mySemaphore(1);

// // ...

// void sharedResourceAccessFunction() {
//     mySemaphore.acquire(); // Wait until semaphore value is greater than zero
//     // Code to access shared resource
//     mySemaphore.release(); // Increment semaphore value
// }

// #include <atomic>

// std::atomic<int> sharedVariable(0);

// // ...

// void sharedResourceAccessFunction() {
//     // Code to access shared resource using atomic operations
// }

// #include <condition_variable>

// std::mutex myMutex;
// std::condition_variable myCondition;

// // ...

// void sharedResourceAccessFunction() {
//     std::unique_lock<std::mutex> lock(myMutex);
//     // Code to check a condition
//     myCondition.wait(lock); // Release the lock and wait for the condition
//     // Code to access shared resource
// }

#include <iostream>
#include <memory>

class MyClass {
public:
    MyClass(int value) : data(value) {
        std::cout << "Constructing MyClass with value: " << data << std::endl;
    }

    ~MyClass() {
        std::cout << "Destructing MyClass with value: " << data << std::endl;
    }

    void printData() {
        std::cout << "Data: " << data << std::endl;
    }

private:
    int data;
};

void smart_pointer_test() {
    // Example using std::unique_ptr
    std::unique_ptr<MyClass> uniquePtr(new MyClass(42));
    uniquePtr->printData(); // Accessing member function

    // std::unique_ptr automatically releases memory when it goes out of scope

    // Example using std::shared_ptr
    std::shared_ptr<MyClass> sharedPtr1 = std::make_shared<MyClass>(10);
    std::shared_ptr<MyClass> sharedPtr2 = sharedPtr1; // shared ownership

    sharedPtr1->printData();
    sharedPtr2->printData();

    // sharedPtr1 and sharedPtr2 share ownership, so the object will be deleted
    // only when both sharedPtr1 and sharedPtr2 go out of scope

    return;
}
