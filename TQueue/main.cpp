#include <iostream>
#include "TQueue.h"
#include <cstdlib>

using namespace std;

int main()
{
	double P = 0.5, Q = 0.1;
	int countTasks = 10, inCount = 0, outCount = 0;
	srand(unsigned(time(0)));
	TQueue<double> TaskQueue(countTasks);
	for (int i = 0; i < countTasks; i++)
	{
		double num = rand() % 1;
		if (num < P)
		{
			TaskQueue.Push(num);
			inCount++;
		}
			
		if (num < Q)
		{
			if (!TaskQueue.IsEmpty())
			{
				TaskQueue.Pop();
				outCount++;
			}
		}
		i++;
	}
	cout << inCount << outCount;

}
