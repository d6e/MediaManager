#include "hashtable.h"

//default constructor, creates array for hashtable
HashTable::HashTable(){
    hashTableSize = DEFAULT_HASH_TABLE_SIZE; //set tablesize to default size
    tablePtr = new int[hashTableSize];   // create array
} 

HashTable::HashTable(const HashTable& table){

} 

//default destructor 
virtual HashTable::~HashTable(){
    delete[] tablePtr;
    tablePtr = NULL;
} 


// The tableInsert function will insert a type of NodeData into the hashtable, 
// the function will throw an error, if the data inserted is not a NodeData 
// object.
virtual void HashTable::tableInsert(const NodeData& newItem){
    // searchKey = //the search key of the new newItem
    // i = hashIndex(searchKey);
    // p = //pointer to a new node
    // p->item = newItem;
    // p->next = table[i];
    // table[i] = p;
}

// The tableDelete function will delete a type of NodeData object from the 
// hashtable and will return an error if the data deleted is not a NodeData 
// object.
virtual void HashTable::tableDelete(std::string searchKey){

}

// The tableRetrieve function will retrieve a tyep of NodeData object from the 
// hashtable and will return an error, if the data retrieved is node a NodeData 
// object.
virtual void HashTable::tableRetrieve(std::string searchKey,NodeData& tableItem)const{
    // i = hashIndex(searchkey);
    // p = table[i];

    // while ((p != NULL) && (p->item.getKey() != searchkey))
    //     p = p->next;
    // if (p == NULL)
    //     // THROW A TABLE EXCEPTION
    // else
    //     tableItem = p->item;
}
            
// overloaded hash function for strings
int HashTable::hashIndex(std::string searchKey) const{
    // pg 692
    // separate string into chars
    // convert each char to a number from 0-26 assign to variable "a"
    // a*32^3 + a*32^2 + a*32^1 + a*32^0
    // return searchkey % hashTableSize;
    return 0;
}

//overloaded hash function to account for just ints
int HashTable::hashIndex(int searchKey) const{
    return searchkey % hashTableSize;
}

int HashTable::resize(int size){
// tablesize has to be a prime number
// have to reinsert the searchkey into the table
}