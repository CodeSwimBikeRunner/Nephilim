#include "../observer.h"
#ifdef WIN32
#include "memory.h"
#endif
#define MAX_OBSERVERS 30
struct Subject
{
    int observers_to_remove[MAX_OBSERVERS];
    ObserverPtr observers[MAX_OBSERVERS];
    int observer_ids[MAX_OBSERVERS];
    int index;
    int remove_observers;
    int is_enabled;
};

SubjectPtr subject_init()
{
    SubjectPtr subject = malloc(sizeof(struct Subject));
    subject->remove_observers = 0;
    subject->is_enabled = 1;

    memset(subject->observers_to_remove, 0, MAX_OBSERVERS * sizeof(int));
    memset(subject->observers, NULL, MAX_OBSERVERS * sizeof(ObserverPtr));
    memset(subject->observer_ids, NULL, MAX_OBSERVERS * sizeof(int));
    return subject;
}
int subject_add(SubjectPtr subject, ObserverPtr observer)
{
    int local_id = subject->index;
    subject->observers[local_id] = observer;
    subject->observers_to_remove[local_id] = 0;
    subject->observer_ids[local_id] = local_id;
    subject->index++;
    return local_id;
}
void subject_remove(SubjectPtr subject, ObserverPtr observer, int id)
{
    subject->observers_to_remove[id] = 1;
    subject->remove_observers = 1;
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
    if (subject->is_enabled)
    {
        if (subject->remove_observers)
        {
            remove_observers(subject);
        }
        else
        {
            // walk the list of notifications
            for (int p = subject->observers; p != NULL; p++)
            {
                observer_emit(subject->observers[p], event);
            }
        }
    }
}
void subject_free(SubjectPtr subject)
{
    for (int i = 0; subject->observers[i] != NULL; i++)
    {
        observer_free(subject->observers[i]);
    }
    free(subject);
}

void remove_observers(SubjectPtr subject)
{
    int number_removed = 0;
    for (int i = 0; subject->observers[i] != NULL; i++)
    {
        if(subject->observers_to_remove[i])
        {
            int local_add = i + 1;
            subject->observers[i] = subject->observers[local_add];
            subject->observers_to_remove[i] = subject->observers_to_remove[local_add];
            subject->observer_ids[i] = subject->observer_ids[local_add];
            i--;
            number_removed++;
        }
    }

    subject->index = subject->index - number_removed;
    int local_index = subject->index;
    memset(subject->observers[local_index], NULL, (MAX_OBSERVERS - local_index) * sizeof(ObserverPtr));
    memset(subject->observer_ids[local_index], NULL, (MAX_OBSERVERS - local_index) * sizeof(int));
    memset(subject->observers_to_remove[local_index], NULL, (MAX_OBSERVERS - local_index) * sizeof(int));
}