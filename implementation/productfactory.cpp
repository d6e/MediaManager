#include "productfactory.h"

ProductFactory::ProductFactory(){
    HASH_TABLE_SIZE = 256;
}

ProductFactory::ProductFactory(ProductCollection){
    HASH_TABLE_SIZE = 256;
}