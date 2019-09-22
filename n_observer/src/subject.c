#include "../observer.h"
#include "stdlib.h"

#define MAX_OBSERVERS 100
struct Subject
{
    ObserverPtr * observers[MAX_OBSERVERS];
    int count;
};

SubjectPtr subject_init()
{
    SubjectPtr subject = malloc(sizeof(struct Subject));
    subject->count = 0;
}
void subject_add(SubjectPtr subject, ObserverPtr observer)
{
    subject->observers[subject->count] = observer;
    subject->count++;
}
void subject_remove(SubjectPtr subject, ObserverPtr observer);
void subject_emit(SubjectPtr subject, GAME_EVENT event);
void subject_free(SubjectPtr subject);