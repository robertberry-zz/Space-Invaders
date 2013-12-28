//
//  EventBus.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__EventBus__
#define __Space_Invaders__EventBus__

#include "EventSubscriber.h"
#include <set>
#include <algorithm>

template <typename Event> class EventBus {
public:
    typedef EventSubscriber<Event> Subscriber;
    void addSubscriber(Subscriber *subscriber);
    void removeSubscriber(Subscriber *subscriber);
    void publish(Event event);
    
private:
    std::set< Subscriber* > mSubscribers;
};

template <typename Event> void EventBus<Event>::addSubscriber(EventBus<Event>::Subscriber *subscriber) {
    mSubscribers.insert(subscriber);
}

template <typename Event> void EventBus<Event>::removeSubscriber(EventBus<Event>::Subscriber *subscriber) {
    mSubscribers.erase(subscriber);
}

template <typename Event> void EventBus<Event>::publish(Event event) {
    for_each(mSubscribers.begin(), mSubscribers.end(), [&event](EventBus<Event>::Subscriber *subscriber) {
        subscriber->update(event);
    });
}

#endif /* defined(__Space_Invaders__EventBus__) */
