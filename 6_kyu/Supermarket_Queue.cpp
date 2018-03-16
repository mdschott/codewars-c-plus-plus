/*
There is a queue for the self-checkout tills at the supermarket. 
Your task is write a function to calculate the total time required for all the customers to check out!

The function has two input variables:

customers: an array (list in python) of positive integers representing the queue. 
Each integer represents a customer, and its value is the amount of time they require to check out.
n: a positive integer, the number of checkout tills.
The function should return an integer, the total time required.
*/

long queueTime(std::vector<int> customers,int n){
int waitTime = 0;
	int nextCustomer = 0;
	int totalCustomers = customers.size();

	if (n > customers.size())
	{
		for (int i = 0; i < customers.size(); i++)
		{
			if (customers.at(i) > waitTime)
				waitTime = customers.at(i);
		}
		return waitTime;
	}

	std::vector<int> customerQueue;
	customerQueue.resize(n);
	nextCustomer = customerQueue.size();

	for (int i = 0; i < customerQueue.size(); i++)
	{
		customerQueue.at(i) = customers.at(i);
	}

	do
	{
		for (int i = 0; i < customerQueue.size(); i++)
		{
			customerQueue.at(i) -= 1;

			if (customerQueue.at(i) == 0)
			{
				if(customers.size() > nextCustomer)
				customerQueue.at(i) = customers.at(nextCustomer);
				nextCustomer++;
				totalCustomers--;
			}
		}
		waitTime++;
	} while (totalCustomers > 0);

	
	return waitTime;
}