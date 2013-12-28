//
//  Maybe.h
//  Space Invaders
//
//  Created by Robert Berry on 28/12/2013.
//  Copyright (c) 2013 Robert Berry. All rights reserved.
//

#ifndef Space_Invaders_Maybe_h
#define Space_Invaders_Maybe_h
#include <stdexcept>

template <typename T>
class Maybe {
public:
    virtual T &get() = 0;
    
    virtual bool isDefined() = 0;
    
    bool isEmpty() {
        return !isDefined();
    }
    
    /** If Just<T>, invokes f with T */
    template <typename F> void forEach(F f) {
        if (isDefined()) {
            f(get());
        }
    }
    
    template <typename F> bool exists(F f) {
        if (isDefined()) {
            return f(get());
        } else {
            return false;
        }
    }
};

template <typename T>
class Nothing : public Maybe<T> {
public:
    T &get() {
        throw std::runtime_error("called get on Nothing");
    }
    
    bool isDefined() {
        return false;
    }
};

template <typename T>
class Just : public Maybe<T> {
private:
    T mT;
public:
    Just(T t): mT(t) {}
    
    T &get() {
        return mT;
    }
    
    bool isDefined() {
        return true;
    }
};

#endif
