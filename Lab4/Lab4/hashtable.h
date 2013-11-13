#ifndef HASHTABLE_H
#define HASHTABLE_H
#include "nodedata.h"

/*
The hashtable class that maps each search key into a unique location of 
the hashtable. The class has a private array data member wich will holds the 
customer data, this array is static array with the size of 2001

The tableIsEmpty checks whether the hash table is empty or not, if it is 
empty it will return true, otherwise it will return false.

The tableGetLength will return the size of the table.
(note: it will return an integer.)

The tableInsert function will insert a type of NodeData into the hashtable, 
the function will throw an error, if the data inserted is not a NodeData 
object.

The tableDelete function will delete a type of NodeData object from the 
hashtable and will return an error if the data deleted is not a NodeData 
object.

The tableRetrieve function will retrieve a tyep of NodeData object from the 
hashtable and will return an error, if the data retrieved is node a NodeData 
object.

NOTE: Design of this class was based on examples from
Data Abstraction & Problem Solving with C++ (5th Edition) by Frank Carrano
*/

class HashTable {
public:
	HashTable(); //default constructor 
	HashTable(const HashTable& table); 
	virtual ~HashTable(); //default destructor 

	/* table operations */
<<<<<<< HEAD
	virtual bool tableIsEmpty() const; //check if table is empty or not 
	virtual int tableGetLength() const; //get the length of the table 
	//insert data into the table
	virtual void tableInsert(const NodeData& newItem); 
	virtual void tableDelete(KeyType searchKey); //delete item from the table
	virtual void tableRetrieve(KeyType searchKey, NodeData& tableItem) const;

=======
>>>>>>> 3befecbf59d95ca001a6784f7b61bc36b7b63813
	virtual void tableInsert(const NodeData& newItem); //insert data into the table, NodeData contains key
	virtual void tableDelete(std::string searchKey); //delete item from the table
	virtual void tableRetrieve(std::string searchKey, NodeData& tableItem) const;
				
protected:
	int hashIndex(std::string searchKey) const; //hash function 
	int resize(int size);
private:
<<<<<<< HEAD
	const static int HASH_TABLE_SIZE = 2001; //size of the hash table 
	NodeData* table[HASH_TABLE_SIZE];
=======
	int hashTableSize = 2001; //size of the hash table 
	NodeData* table[hastTableSize];
>>>>>>> 3befecbf59d95ca001a6784f7b61bc36b7b63813

}; //end HashTable
typedef KeyType;

#endif 
