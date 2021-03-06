// 2431Homework2.cpp : Defines the entry point for the console application.
//


#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#define new DBG_NEW
#endif

#include <iostream>
#include <string>
#include "Solution.h"

using namespace std;

template <class T>
class QuestionsAndAnswers
{
public:
    static void Answer(const char *q, T t)
    {
        assert(q != nullptr);

        cout << q << endl;
        cout << t << endl << endl;
    };
};

static const char *Question1 =  "Question 1: Briefly explain the purpose of the \"virtual\" keyword.\r\n" \
                                "How does marking a function virtual in class A affect calling that function " \
                                "in A and in classes deriving from A?";
static const char *Question2 =  "Explain why your template class is both declared and defined in the header file.\r\n" \
                                "Hint. Try moving the function bodies to a separate cpp file.";
static const char *Question3 =  "What's 2 + 3?";

int main()
{
	string dashes = "------------------------------\n";
	string testArray[] = { "str1", "str2","str3","str4","str5" ,"str6" ,"str7" ,"str8","str9","str10" };

	
	//Checks for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);


    QuestionsAndAnswers<const char *>::Answer(Question1, ANSWER1);
    QuestionsAndAnswers<const char *>::Answer(Question2, ANSWER2);
    QuestionsAndAnswers<int>::Answer(Question3, 5);

    Queue<int> *intQueue = new Queue<int>();
    Queue<string> *strQueue = new Queue<string>();
    Stack<int> *intStack = new Stack<int>();
    Stack<string> *strStack = new Stack<string>();

	//checking with empty 
	//intQueue->Dequeue();                                 //Uncomment these to check your asserts
	//intQueue->Peek();
	
	/////////////////////////////////////
	//////////Queue Check///////////////
	///////////////////////////////////

	//intQueue check 
	cout << dashes << "intQueue Check: " <<endl<< dashes;

	cout << "Size: " << intQueue->Size() << endl;
	for(unsigned int i=0; i<9; i++)
	{
	intQueue->EnqueueO1(i);
	cout <<"Push: "<<i<< "  " "Peak: " << intQueue->Peek()<<"  " << "Size: " << intQueue->Size() << endl;
	}
   
	for (unsigned int i = 0; i<6; i++)
	{
		cout << "Peak: " << intQueue->Peek() <<"  "<< "Dequeue:" << intQueue->Dequeue() << endl;
		cout << "Push: " << i << "  " "Peak: " << intQueue->Peek() << "  " << "Size: " << intQueue->Size() << endl;
	}


	//strQeue check
	//String Stack Check
	cout << dashes << "strQeue Check: " << endl << dashes;
	for (auto i = 0; i<9; i++)
	{
		strQueue->EnqueueO1(testArray[i]);
		cout << "Enqueue: " << testArray[i] << "  " << "Peak: " << strQueue->Peek() << "  ";
		cout << "Size: " << strQueue->Size() << endl;
	}
	for (auto i = 0; i<7; i++)
	{
		cout << "Size: " << strQueue->Size() << "  " << "Peak: " << strQueue->Peek() << "  ";
		cout << "Pop:" << strQueue->Dequeue().c_str() << endl;
	}

	
   

	
	//intStack->Peek();                                //Uncomment these to check your asserts
	//intStack->Pop();





	///////////////////////////////////////////
	///////////////STACK//////////////////////
	/////////////////////////////////////////

	//IntStack Check
	cout << dashes << "intStack Check: " << endl << dashes;
	for (unsigned int i = 0; i<9; i++)
	{
		intStack->Push(i);
		cout << "Push:" << i << "  " << "Peak: " << intStack->Peek() << "  ";
		cout << "Size: " << intStack->Size() << endl;
	}
	for (auto i = 0; i<7; i++)
	{
		cout << "Size: " << intStack->Size() << "  " << "Peak: " << intStack->Peek() << "  ";
		cout << "Pop:" << intStack->Pop() << endl;
	}
	  

	//String Stack Check
	cout << dashes << "strStack Check: " << endl << dashes;
	for (auto i = 0; i<9; i++)
	{
		strStack->Push(testArray[i]);
		cout << "Push:" << testArray[i] << "  "<< "Peak: " << strStack->Peek() << "  ";
		cout << "Size: " << strStack->Size() << endl;
	}
	for(auto i=0; i<7; i++)
	{
		cout << "Size: " << strStack->Size() << "  " << "Peak: " << strStack->Peek()<< "  ";
		cout << "Pop:" << strStack->Pop().c_str() << endl;
	}
	

    
    cout << "Press enter to exit.";
    getc(stdin);

    delete intQueue;
    delete strQueue;
    delete intStack;
    delete strStack;

    return 0;
}