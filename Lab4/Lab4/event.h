#ifndef EVENT_H
#define EVENT_H

/*
An event object holds the data for a transaction. It parses the string passed 
into it and assigns the first substring to the borrowedOrReturned string and 
the rest of the string to the otherInfo String.
*/
class Event {
private:
    String borrowedOrReturned;
    String otherInfo;  // based on the sorting criteria of the particular genre.
public:
    void display() const;  // Display the data from one event object
    Event();
    ~Event();
    Error set(String);   // Parses the borrowed/returned status from the rest of the string info.
};


#endif