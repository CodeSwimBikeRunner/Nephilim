#include "../observer.h"
#include "stdlib.h"

#define MAX_OBSERVERS 30
struct Subject
{
    int * observers_to_remove[MAX_OBSERVERS];
    ObserverPtr * observers[MAX_OBSERVERS];
    int count;
    int remove_in_constant_time;
    int is_enabled;
};

SubjectPtr subject_init()
{
    SubjectPtr subject = malloc(sizeof(struct Subject));
    subject->count = 0;
    subject->remove_in_constant_time = 0;
    subject->is_enabled = 1;
}
int subject_add(SubjectPtr subject, ObserverPtr observer)
{
    int local_id = subject->count;
    subject->observers[local_id] = observer;
    subject->observers_to_remove[local_id] = 0;
    subject->count++;
    return local_id;
}
void subject_remove(SubjectPtr subject, ObserverPtr observer, int id)
{
    subject->observers_to_remove[id] = 1;
    subject->remove_in_constant_time = 1;
}
void subject_disable(SubjectPtr subject)
{
    subject->is_enabled = 0;
}
void subject_enable(SubjectPtr subject)
{
    subject->is_enabled = 1;
}
void subject_emit(SubjectPtr subject, GAME_EVENT event)
{
    if(subject->is_enabled)
    {
        if(subject->remove_in_constant_time)
        {
            // TODO:: Learn how to properly use pointer arithmetic 
            // TODO:: finish walking and removing
            for(int p = subject->observers; p != NULL; p++)
            {
                p = recursively_check(subject, p);
            }
        }
        else {
            // walk the list of notifications
            for(int p = subject->observers; p != NULL; p++)
            {
                observer_emit(subject->observers[p], event);
            }
        }
    }
}
void subject_free(SubjectPtr subject)
{
    // free all the observers first
    // TODO:: Figure out how to use pointer arithmetic.
    for(int p = subject->observers; p != NULL; p++)
    {
        observer_free((ObserverPtr)p);
    }
    free(subject);
}

int recursively_check_and_emit(SubjectPtr subject, int p)
{

}