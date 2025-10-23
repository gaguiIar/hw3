#ifndef EVENT_H
#define EVENT_H
#include "wire.h"

struct Event
{
    uint64_t time;
    Wire* wire;
    char state;
};

typedef struct EventLess {
        //write the operator() required to make this a functor that compares Events by time
        bool operator()(const Event* event_a, const Event*event_b) const {
            if(event_a->time != event_b->time) { 
                return (event_a->time < event_b->time);
            }
            return (event_a < event_b);
            
        }
} EventLess;
	
#endif
