#include <iostream>
#include <sstream>
#include "Queue.h"
using namespace std;

Queue::Queue(int size){
	queueSize = size;
	queueHead = 0;
	queueTail = 0;
	queueCount = 0;
	arrayQueue = new string[size];
}

Queue::~Queue(){
	delete [] arrayQueue;
	arrayQueue = nullptr;
}

void Queue::enqueue(string word){
	if(queueIsFull() == true){
		cout << "Queue is full" << endl;
	}else{
		if (queueTail == queueSize-1){
			arrayQueue[queueTail] = word;
			queueTail = 0;
			queueCount++;
		}else{
			arrayQueue[queueTail] = word;
			queueTail++;
			queueCount++;
		}
		cout << "E: " << word << endl;
		cout << "H: " << queueHead << endl;
		cout << "T: " << queueTail << endl;
	}
}

void Queue::dequeue(){
	if (queueIsEmpty() == true){
		cout << "Queue is empty." << endl;
	}else{
		string deWord = "";
		if(queueHead == queueSize-1){
			deWord = arrayQueue[queueHead];
			arrayQueue[queueHead] = -1;
			queueHead = 0;
			queueCount--;
		}else{
			deWord = arrayQueue[queueHead];
			arrayQueue[queueHead] = -1;
			queueHead++;
			queueCount--;
		}
		cout << "H: " << queueHead << endl;
		cout << "T: " << queueTail << endl;
		cout << "word: " << deWord << endl;
	}
}

void Queue::printQueue(){
	if(queueIsEmpty() == true){
		cout << "Empty" << endl;
	}
	else if (queueHead < queueTail){
		for(int i = queueHead; i < queueTail; i++){
			cout << i << ": " << arrayQueue[i] << endl;
		}

	}else{
		int temp = queueHead;
		for(int i = temp; i < queueSize; i++){
			cout << i << ": " << arrayQueue[i] << endl;
		}

		temp = 0;
		for(int i = temp; i < queueTail; i++){
			cout << i << ": " << arrayQueue[i] << endl;
		}
	}
}

void Queue::enqueueSentence(string sentence){
	stringstream ss(sentence);
	string word = "";
	while(ss >> word){
		enqueue(word);
	}
}

bool Queue::queueIsFull(){
	if(queueCount == queueSize){
		return true;
	}else{
		return false;
	}
}

bool Queue::queueIsEmpty(){
	if(queueHead == queueTail && queueIsFull() == false){
		return true;
	}else{
		return false;
	}
}