#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next, *prev;
}

class Hashtable{
private:
	int *arr;
	int m;
	
	int hash_function(int);
public:
	Hashtable() {};
	Hashtable(int n){ arr = new int[n]; m = n/3;)
	~Hashtable() { delete arr;}
	
	void insert(int k);
	bool search(int k);
	void remove(int k);
};

int main()
{
	return 0;
}

int hash_function(int k)
{
	return k%m;
}

void Hashtable :: insert(int k)
{
	arr[hash_function(k)] = k;
}