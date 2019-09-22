#pragma once

typedef struct Observer * ObserverPtr;
typedef struct Subject * SubjectPtr;

// ! Having game events here is not very reusable.
typedef enum 
{ 
    IS_PLAYER_TURN
} GAME_EVENT;

SubjectPtr subject_init();
void subject_add(SubjectPtr subject, ObserverPtr observer);
void subject_remove(SubjectPtr subject, ObserverPtr observer);
void subject_disable(SubjectPtr);
void subject_enable(SubjectPtr);
void subject_emit(SubjectPtr subject, GAME_EVENT event);
void subject_free(SubjectPtr subject);

ObserverPtr observer_init();
void observer_emit(ObserverPtr observer, const void * entity, GAME_EVENT event);
void observer_free(ObserverPtr observer);