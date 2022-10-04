#include <iostream>
#include "../Heap.hpp"
#include "../Customer.hpp"

using std::cout;
using std::endl;

int main()
{
	cout << "Beginning Tests: creating customers." << endl;
	Customer* earlyCust = new Customer(44.30);
	cout << "Customer arrived at: " << earlyCust->GetArrivalT() << endl;
	Customer* middleCust = new Customer(12.66);
	cout << "Customer arrived at: " << middleCust->GetArrivalT() << endl;
	Customer* latestCust = new Customer (6.23);
	cout << "Customer arrived at: " << latestCust->GetArrivalT() << endl << endl;

	cout << "Creating Storage Heap..." << endl;

	Heap testHeap;

	cout << "Heap Created." << endl;
	cout << "Inserting customers." << endl;

	testHeap.Insert(earlyCust);
	cout << "earlyCust Inserted." << endl;
	testHeap.Insert(latestCust);
	cout << "latestCust Inserted." << endl;
	testHeap.Insert(middleCust);
	cout << "middleCust Inserted." << endl;

	cout << "longest wait to shortest: " << endl;
	cout << testHeap.Pop()->GetArrivalT() << endl;
	cout << testHeap.Pop()->GetArrivalT() << endl;
	cout << testHeap.Pop()->GetArrivalT() << endl;

	cout << "Deleting Customers." << endl << endl;

	cout << "Operations complete." << endl;
	return 0;
}
