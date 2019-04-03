#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

class Queue{
public:
    Queue(int);
    ~Queue();
    //circular queue methods
    void enqueue(std::string);
    void dequeue();
    void printQueue();
    void enqueueSentence(std::string);
    bool queueIsFull(); //check when full
    bool queueIsEmpty(); //check when empty
    
protected:
    
private:
    int queueSize;
    int queueHead;
    int queueTail;
    int queueCount;
    std::string *arrayQueue;
};

#endif // QUEUE_H