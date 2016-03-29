/*
 * NodeController.h
 *
 *  Created on: Jan 27, 2016
 *      Author: thod0127
 */

#ifndef CONTROLLER_NODECONTROLLER_H_
#define CONTROLLER_NODECONTROLLER_H_
#include "../Model/Node.cpp"
#include "../Model/ArrayNode.cpp"
#include "../Model/CTECArray.cpp"
#include "../Model/CTECList.cpp"
#include "../Model/Timer.h"
#include <string>

using namespace std;

class NodeController
{
private:
	CTECList<int> * numbers;
	Timer * timer;
    CTECArray<int> * array;
    void sortData();
public:
	NodeController();
	virtual ~NodeController();
	void start();
	void testLists();
};

#endif /* CONTROLLER_NODECONTROLLER_H_ */
