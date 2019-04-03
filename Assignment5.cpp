#include <iostream>
#include "Queue.h"
using namespace std;

int main(int argc, char *argv[]){
	Queue vQueue(10);
	bool quit = false;
	while (quit == false){
		string sSelect = "0";
		int select = 0;
		while (select!=1 && select!=2 && select!=3 && select!=4 && select!=5){
			cout << "======Main Menu=====" << endl;
			cout << "1. Enqueue word" << endl;
			cout << "2. Dequeue word" << endl;
			cout << "3. Print queue" << endl;
			cout << "4. Enqueue sentence" << endl;
			cout << "5. Quit" << endl;
			getline(cin, sSelect);
			select = stoi(sSelect);
			if(select != 1 && select != 2 && select != 3 && select != 4 && select != 5){
				cout << "Invalid selectection, please enter a valid number" << endl;
			}
		}
		if (select == 1){
			string wordToAdd = "";
			cout << "word: ";
			getline(cin, wordToAdd);
			vQueue.enqueue(wordToAdd);
		}else if (select == 2){
			vQueue.dequeue();
		}else if (select == 3){
			vQueue.printQueue();
		}else if (select == 4){
			string sentence = "";
			cout << "sentence: ";
			getline(cin, sentence);
			vQueue.enqueueSentence(sentence);
		}else if (select == 5){
			quit = true;
			cout << "Goodbye!" << endl;
		}
	}
}