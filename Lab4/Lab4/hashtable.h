#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "nodedata.h"
/*
The customerindex class that constains all customer objects for each customer 
who uses the system.   

The class has a private datamember called custHT. It's a hashtable used to
hold pointers to the customer objects. The key for it is the customerID.

The addTransaction method looks up the customer object in the hashtable 
using custID as a key, it then calls the customer object's addTransaction
method using the passed in string as a parameter. If the customer object
does not exist it creates an error object with an error message string as a 
parameter, if it does exist, the error object has an empty string.

The customerExists method determines whether the customer object corresponding
to the custID exists. It attempts to look up the customer object in the 
hash table using custID as a key, if it exists it returns true, otherwise
it returns false.

The displayHistory method displays the customer's history by calling the
customer object's displayHistory method. It looks up the customer object
in the customer hash table using the custID parameter and if it does not exist
it returns an Error object with an error message string describing the error,
otherwise, if the object does exist it returns an Error object with an empty
string. 

The insertCustomer method takes in a customer pointer and inserts it
*/

/*
The hashtable class that maps each search key into a unique location of the hash
table. The class has a private array data member wich will holds the customer data,
this array is static array with the size of 2001

The tableIsEmpty checks, wheter the hash table is empty or not, if it is empty it 
will return true, otherwise it will return false 

The tableGetLength will return the size of the table, note it will return an integer 

The tableInsert function will insert a type of NodeData into the hashtable, the function
will throw an error, if the data inserted is not a NodeData object

The tableDelete function will delete a type of NodeData object from the hashtable and 
will return an error if the data deleted is not a NodeData object 

The tableRetrieve function will retrieve a tyep of NodeData object from the hashtable and
will return an error, if the data retrieved is node a NodeData object 
*/
class HashTable {

public:

	HashTable(); //default constructor 
	HashTable(const HashTable& table); 
	virtual ~HashTable(); //default destructor 

	/* table operations */
	virtual bool tableIsEmpty() const; //check if table is empty or not 
	virtual int tableGetLength() const; //get the length of the table 
	virtual void tableInsert(const NodeData& newItem) //insert data into the table
				throw(TableException);
	virtual void tableDelete(KeyType searchKey) //delete item from the table
				throw(TableException);
	virtual void tableRetrieve(KeyType searchKey, NodeData& tableItem) const 
				throw(TableException); //retrieve data from the table
				
protected:
	int hashIndex(KeyType searchKey) const; //hash function 
	
private:
	static const int HASH_TABLE_SIZE = 2001; //size of the hash table 
	typedef NodeData *HashTable[HASH_TABLE_SIZE];

	HashTable table; //hash table 
	int size; //size of the ADT table 

}; //end HashTable

#endif 
