#ifndef CUSTOMERFACTORY_H
#define CUSTOMERFACTORY_H
#include "factory.h"
#include "customer.h"
#include <string>

class CustomerFactory : public Factory {
public:
    CustomerFactory(void);
    ~CustomerFactory(void);
    Customer* createCustomer(String);
};

#endif