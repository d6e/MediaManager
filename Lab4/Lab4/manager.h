#ifndef MANAGER_H
#define MANAGER_H

/*
The manager class is the main controller for the program.
*/

class Manager{

private:
    CustomerIndex customerDB;
    MediaCollection mediaDB;
    CommandControl controls;
    bool inputMedia(String);
    bool inputCustomer(String);
    bool initCmd();
    bool inputCmd(String);

public:
	Manager();
	~Manager();
};

#endif