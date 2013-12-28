//
//  EventSubscriber.h
//  Space Invaders
//
//  Created by Robert Berry on 27/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef __Space_Invaders__EventSubscriber__
#define __Space_Invaders__EventSubscriber__

template <class Event>
class EventSubscriber {
public:
    virtual void update(Event event) = 0;
};

#endif /* defined(__Space_Invaders__EventSubscriber__) */
