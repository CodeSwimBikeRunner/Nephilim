#include "../observer.h"
#include "stdio.h"
struct Observer {
    ObserverPtr tail_;
    ObserverPtr head_;
    int is_locked;
};

ObserverPtr observer_init()
{
    ObserverPtr observer = malloc(sizeof(struct Observer));
    observer->head_ = NULL;
    observer->tail_ = NULL;
    observer->is_locked = 0;
    return observer;
}

void observer_emit(ObserverPtr observer, GAME_EVENT event)
{
    if(!observer->is_locked)
    {

    }
}
void observer_free(ObserverPtr observer)
{
    free(observer);
}
