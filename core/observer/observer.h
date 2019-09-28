#pragma once
#include "stdlib.h"

#ifdef WIN32
#include "../../WinThread/include/pthread.h"
#else
#include <pthread.h>
#endif

typedef struct Observer * ObserverPtr;
typedef struct Subject * SubjectPtr;

// ! Having game events here is not very reusable.
typedef enum 
{ 
    IS_PLAYER_TURN,
    IS_MENU_OPEN
} GAME_EVENT;

SubjectPtr subject_init();
/* 
    * Returns the INT ID of the observer
    * When you want to remove this observer from the subject,
    * Use this INT ID.
    */
int subject_add(SubjectPtr subject, ObserverPtr observer);
/*
    * Pass in the INT ID that was provided when you added this to the subject.
    * It will remove it based on the ID,
    * Next time the Subject triggers notifications it will be removed in constant time.
    */
void subject_remove(SubjectPtr subject, ObserverPtr observer, int id);
void subject_disable(SubjectPtr subject);
void subject_enable(SubjectPtr subject);
void subject_emit(SubjectPtr subject, GAME_EVENT event);
void subject_free(SubjectPtr subject);

/*
    * Pass in the Function you want the subject to call.
    * Provide the is async value if this is a long running event.
    */
ObserverPtr observer_init(void (*func)(GAME_EVENT event), int is_async);
void observer_emit(ObserverPtr observer, GAME_EVENT event);
void observer_free(ObserverPtr observer);