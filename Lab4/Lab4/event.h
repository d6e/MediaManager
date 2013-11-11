#ifndef EVENT_H
#define EVENT_H

/*
An event object holds the data for a transaction.
*/
class Event {
private:
    String borrowedOrReturned;
public:
    void display() const;  // Display the data from one event object
    Event();
    ~Event();
};


#endif