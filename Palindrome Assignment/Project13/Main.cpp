#include "ArrayQueue.h"
#include "ArrayStack.h"
#include "PrecondViolatedExcept.h"
#include "QueueInterface.h"
#include "StackInterface.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void fixCaps(char array[], int size);

int main() {
	string fileInput, originalInput;
	char chArray[75];
	ArrayStack <char> palindromeStack;
	ArrayQueue <char> palindromeQueue;
	char queueFront, stackTop;
	bool isPalindrome;
	int len;

		ifstream inFile;

		inFile.open("Palindrome.txt");
		if (!inFile) { //Failsafe in case the file is not found
			cout << "Error: File Not Found" << endl;
		}

		while (!inFile.eof()) {
			getline(inFile, fileInput);
			originalInput = fileInput;
		}

		for (unsigned int i = 0; i < fileInput.size(); i++) { //accounts for spaces and punctuation
			if (fileInput[i] < 65 || (90 < fileInput[i] && fileInput[i < 97]) || fileInput[i] > 122) {
				fileInput.erase(i, 1);
				i--;
			}
		}


		strcpy_s(chArray, fileInput.c_str()); //string to char array
		len = strlen(chArray);
		fixCaps(chArray, len); //calls function to convert to lowercase

		cout << "Checking: " << chArray << endl << endl;


		for (int i = 0; i < len; i++) {
			palindromeStack.push(chArray[i]);
			palindromeQueue.enqueue(chArray[i]);
		}


		while (!palindromeQueue.isEmpty() && !palindromeStack.isEmpty()) {
			stackTop = palindromeQueue.peekFront();
			queueFront = palindromeStack.peek();

			if (stackTop == queueFront) {
				palindromeQueue.dequeue();
				palindromeStack.pop();
				isPalindrome = true;
			}

			else {
				isPalindrome = false;
				while (!palindromeStack.isEmpty() && !palindromeQueue.isEmpty()) {
					palindromeQueue.dequeue();
					palindromeStack.pop();
				}
			}

		}

		if (isPalindrome == true)
			cout << originalInput << " is a palindrome" << endl;
		else if (isPalindrome == false)
			cout << originalInput << " is not a palindrome" << endl;

	system("PAUSE");
}

void fixCaps(char array[], int size) { //converts uppercase to lowercase
	for (int i = 0; i <= size; i++) {
		if (array[i] >= 65 && array[i] <= 92) {
			array[i] = array[i] + 32;
		}
	}
}