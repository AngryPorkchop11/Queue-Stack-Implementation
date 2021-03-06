//// 2431Homework2.cpp : Defines the entry point for the console application.
////
//
//
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#ifdef _DEBUG
//#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
//#define new DBG_NEW
//#endif
//
//#include <iostream>
//#include <string>
//#include "Solution.h"
//
//using namespace std;
//
//template <class T>
//class QuestionsAndAnswers
//{
//public:
//    static void Answer(const char *q, T t)
//    {
//        assert(q != nullptr);
//
//        cout << q << endl;
//        cout << t << endl << endl;
//    };
//};
//
//static const char *Question1 =  "Question 1: Briefly explain the purpose of the \"virtual\" keyword.\r\n" \
//                                "How does marking a function virtual in class A affect calling that function " \
//                                "in A and in classes deriving from A?";
//static const char *Question2 =  "Explain why your template class is both declared and defined in the header file.\r\n" \
//                                "Hint. Try moving the function bodies to a separate cpp file.";
//static const char *Question3 =  "What's 2 + 3?";
//
//int main()
//{
//	string dashes = "------------------------------\n";
//
//	
//	//Checks for memory leaks
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF | _CRTDBG_CHECK_ALWAYS_DF);
//
//
//    QuestionsAndAnswers<const char *>::Answer(Question1, ANSWER1);
//    QuestionsAndAnswers<const char *>::Answer(Question2, ANSWER2);
//    QuestionsAndAnswers<int>::Answer(Question3, 5);
//
//    Queue<int> *intQueue = new Queue<int>();
//    Queue<string> *strQueue = new Queue<string>();
//    Stack<int> *intStack = new Stack<int>();
//    Stack<string> *strStack = new Stack<string>();
//
//	
//	cout << dashes << "intQueue Check: " <<endl<< dashes;
//	cout << "Size: " << intQueue->Size() << endl;
//    intQueue->EnqueueO1(1);
//	cout << "Size: " << intQueue->Size() << endl;
//    intQueue->EnqueueO1(2);
//	cout << "Size: " << intQueue->Size() << endl;
//    intQueue->EnqueueO1(3);
//	cout << "Size: " << intQueue->Size() << endl;
//    intQueue->EnqueueO1(4);
//	cout << "Size: " << intQueue->Size() << endl;
//    intQueue->EnqueueO1(5);
//	cout << "Size: " << intQueue->Size() << endl;
//    cout << "Dequeue:" << intQueue->Dequeue() << endl;
//	cout << "Size: " << intQueue->Size() << endl;
//    cout << "Dequeue:" << intQueue->Dequeue() << endl;
//	cout << "Size: " << intQueue->Size() << endl;
//    cout << "Dequeue:" << intQueue->Dequeue() << endl;
//	cout << "Size: " << intQueue->Size() << endl;
// //   cout << "Dequeue:" << intQueue->Dequeue() << endl;
//	//cout << "Size: " << intQueue->Size() << endl;               //Does not delete everything
// //   cout << "Dequeue:" << intQueue->Dequeue() << endl;
//	//cout << "Size: " << intQueue->Size() << endl;
//
//	cout << dashes << "strQueue Check: " << endl << dashes;
//    strQueue->EnqueueO1("str1");
//	cout << "Size: " << strQueue->Size() << endl;
//    strQueue->EnqueueO1("str2");
//	cout << "Size: " << strQueue->Size() << endl;
//    strQueue->EnqueueO1("str3");
//	cout << "Size: " << strQueue->Size() << endl;
//    strQueue->EnqueueO1("str4");
//	cout << "Size: " << strQueue->Size() << endl;
//    strQueue->EnqueueO1("str5");
//	cout << "Size: " << strQueue->Size() << endl;
//    cout << "Dequeue:" << strQueue->Dequeue().c_str() << endl;
//	cout << "Size: " << strQueue->Size() << endl;
//    cout << "Dequeue:" << strQueue->Dequeue().c_str() << endl;
//	cout << "Size: " << strQueue->Size() << endl;
//    cout << "Dequeue:" << strQueue->Dequeue().c_str() << endl;
//	cout << "Size: " << strQueue->Size() << endl;
//    cout << "Dequeue:" << strQueue->Dequeue().c_str() << endl;
//	cout << "Size: " << strQueue->Size() << endl;
//    cout << "Dequeue:" << strQueue->Dequeue().c_str() << endl;
//	cout << "Size: " << strQueue->Size() << endl;
//
//	cout << dashes << "intStack Check: " << endl << dashes;
//    intStack->Push(1);
//	cout << "Size: " << intStack->Size() << endl;
//    intStack->Push(2);
//	cout << "Size: " << intStack->Size() << endl;
//    intStack->Push(3);
//	cout << "Size: " << intStack->Size() << endl;
//    intStack->Push(4);
//	cout << "Size: " << intStack->Size() << endl;
//    intStack->Push(5);
//	cout << "Size: " << intStack->Size() << endl;
//    cout << "Pop:" << intStack->Pop() << endl;
//	cout << "Size: " << intStack->Size() << endl;
//    cout << "Pop:" << intStack->Pop() << endl;           
//	cout << "Size: " << intStack->Size() << endl;
//    cout << "Pop:" << intStack->Pop() << endl;
//	cout << "Size: " << intStack->Size() << endl;
//   /* cout << "Pop:" << intStack->Pop() << endl;
//	cout << "Size: " << intStack->Size() << endl;                  //Does not delete everything
//    cout << "Pop:" << intStack->Pop() << endl;
//	cout << "Size: " << intStack->Size() << endl;*/
//
//	cout << dashes << "strStack Check: " << endl << dashes;
//    strStack->Push("str1");
//	cout << "Size: " << strStack->Size() << endl;
//    strStack->Push("str2");
//	cout << "Size: " << strStack->Size() << endl;
//    strStack->Push("str3");
//	cout << "Size: " << strStack->Size() << endl;
//    strStack->Push("str4");
//	cout << "Size: " << strStack->Size() << endl;
//    strStack->Push("str5");
//	cout << "Size: " << strStack->Size() << endl;
//    cout << "Pop:" << strStack->Pop().c_str() << endl;
//	cout << "Size: " << strStack->Size() << endl;
//    cout << "Pop:" << strStack->Pop().c_str() << endl;
//	cout << "Size: " << strStack->Size() << endl;
//    cout << "Pop:" << strStack->Pop().c_str() << endl;
//	cout << "Size: " << strStack->Size() << endl;
//    cout << "Pop:" << strStack->Pop().c_str() << endl;
//	cout << "Size: " << strStack->Size() << endl;
//    cout << "Pop:" << strStack->Pop().c_str() << endl;
//	cout << "Size: " << strStack->Size() << endl;
//
//    
//    cout << "Press enter to exit.";
//    getc(stdin);
//
//    delete intQueue;
//    delete strQueue;
//    delete intStack;
//    delete strStack;
//
//    return 0;
//}