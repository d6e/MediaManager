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
	HashTable(); //default constructor, creates array for hashtable
	HashTable(const HashTable& table); 
	virtual ~HashTable(); //default destructor 

	/* table operations */
    //insert data into the table, NodeData contains key
	virtual void tableInsert(const NodeData& newItem); 
    //delete item from the table
	virtual void tableDelete(std::string searchKey); 
	virtual void tableRetrieve(std::string searchKey,NodeData& tableItem)const;
				
protected:
	int hashIndex(std::string searchKey) const; //hash function 
	int resize(int size);
private:
	static const int DEFAULT_HASH_TABLE_SIZE = 2001;
	int hashTableSize; //size of the hash table 
	NodeData* tablePtr; //Points to first element of dynamic array.
}; //end HashTable


#endif 
