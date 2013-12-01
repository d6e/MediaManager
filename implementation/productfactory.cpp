#include "productfactory.h"

ProductFactory::ProductFactory(ProductCollection*) 
        : HASH_TABLE_SIZE(256) {
    pCollect = pC;    

    // cmds['H'] = new HistoryCMD(cIndex);
    // cmds['B'] = new BorrowCMD(cIndex, pCollect);
    // cmds['R'] = new ReturnCMD(cIndex, pCollect);
    // cmds['S'] = new DisplayAllProductCMD(pCollect);    
}

ProductFactory::~ProductFactory(){
    for(it = products.begin(); it != products.end(); ++it) {
        delete it->second;
    }
} 

//parses input to create Product objects, returns null if invalid hash key
Product* ProductFactory::create(std::string key){
    std::string pdtString;
    std::string restOfString;
    std::stringstream ss;
    ss << key;
    ss >> pdtString;
    restOfString = ss.str();
    char pdtChar = pdtString.at(0); //Convert string to a char

    Command* pdtPtr = NULL;
    pdtPtr = products[cmdChar];
    pdtPtr->setData(new Event(restOfString));
    return pdtPtr;
}

int ProductFactory::hash(std::string key){
    return 0; //TODO: finish this
}