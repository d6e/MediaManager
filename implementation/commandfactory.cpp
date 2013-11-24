#include "commandfactory.h"

// constructor, inits hash table
CommandFactory(CustomerIndex, ProductCollection); 
virtual ~CommandFactory();    // destructor
// Creates and inits cmd obj based on key given, returns null if invalid key
Command* create(std::string key);   

CustomerIndex* cIndex; // For commands that need access to the customers
// For commands that need to access the products
ProductCollection* pCollect; 
ProductFactory* mFactory; // For commands that need to create products.
const int HASH_TABLE_SIZE = 256;
 // A pointer to an array of Commands implemented as a hash table
Command* hashTable;
int hash(std::string key);