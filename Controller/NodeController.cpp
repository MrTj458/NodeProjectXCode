/*
 * NodeController.cpp
 *
 *  Created on: Jan 27, 2016
 *      Author: thod0127
 */

#include "NodeController.h"
#include <iostream>
using namespace std;

NodeController::NodeController()
{
	numbers = new CTECList<int>();
	timer = new Timer();
    array = new CTECArray<int>(6);
}

NodeController::~NodeController()
{

}

void NodeController :: start()
{
	testLists();
}

void NodeController::testLists()
{
	timer->startTimer();

	numbers->addToFront(3);
	numbers->addToEnd(8);
	cout << "End should be 8 and is : " << numbers->getEnd() << endl;
	cout << "Head should be 3 and is : " << numbers->getFront() << endl;
	cout << "Size should be 2 and is: " << numbers->getSize() << endl;
	numbers->addToFront(6);
	cout << "Head should be 6 and is: " << numbers->getFront() << endl;
	numbers->addAtIndex(1, 4);
	cout << "Value at spot 1 should be 4 and is: " << numbers->getFromIndex(1) << endl;
	numbers->removeFromFront();
	cout << "head should be 4 and is: " << numbers->getFront() << endl;
	numbers->removeFromEnd();
	cout << "Value at end should be 3 and is: "<< numbers->getEnd() << endl;
	numbers->addToEnd(5);
	numbers->removeFromIndex(1);
	cout << "Value at index 1 should be 5 and is: " << numbers->getFromIndex(1) << endl;
	numbers->set(1, 100);
	cout << "Value at index 1 should be 100 and is: " << numbers->getFromIndex(1) << endl;

	timer->stopTimer();
	timer->displayTimerInformation();
    
    cout << endl;
    cout << endl;
    
    array->set(0, 1);
    array->set(1, 2);
    array->set(2, 3);
    array->set(3, 4);
    array->set(4, 5);
    array->set(5, 6);
    
    cout << "The value in spot 4 should be 3 and is: " << array->indexOf(4) << endl;
}
