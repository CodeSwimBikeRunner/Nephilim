#include "../observer.h"

struct Observer {
    void (*func)(GAME_EVENT event);
    int is_async;
    int is_locked;
};

ObserverPtr observer_init(void (*func)(GAME_EVENT event), int is_async)
{
    ObserverPtr observer = malloc(sizeof(struct Observer));
    observer->is_locked = 0;
    observer->is_async = is_async;
    return observer;
}

void observer_emit(ObserverPtr observer, GAME_EVENT event)
{
    if(!observer->is_locked)
    {
        if(observer->is_async)
        {
            //TODO:: Implement threading so it works crossplatform
            // HANDLE thread[1];
        }
        else {
            observer->is_locked = 1;
            observer->func(event);
            observer->is_locked = 0;
        }
    }
}
void observer_free(ObserverPtr observer)
{
    free(observer);
}
