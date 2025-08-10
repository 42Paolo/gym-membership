#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <time.h>

typedef struct s_activity
{
    int activity_id;
    char name[50];
    char instructor[50];
    int max_participants;
    time_t start_time;
    int duration_minutes;
    int current_participants;
    struct s_activity *next;
} t_activity;

// ===== FUNZIONI DI BASE =====
t_activity *create_activity(int activity_id, char *name, char *instructor, int max_participants, time_t start_time, int duration);
t_activity *add_activity(t_activity **head, int activity_id, char *name, char *instructor, int max_participants, time_t start_time, int duration);
void remove_activity(t_activity **head, int activity_id);
void free_activity_list(t_activity **head);

// ===== FUNZIONI DI RICERCA =====
t_activity *find_activity_by_id(t_activity *head, int activity_id);
t_activity *find_activity_by_name(t_activity *head, char *name);
t_activity *find_activity_by_instructor(t_activity *head, char *instructor);

// ===== FUNZIONI DI VISUALIZZAZIONE =====
void print_activity(t_activity *activity);
void print_all_activities(t_activity *head);
void print_activities_by_instructor(t_activity *head, char *instructor);

// ===== FUNZIONI DI MODIFICA =====
int update_activity_name(t_activity *activity, char *new_name);
int update_activity_instructor(t_activity *activity, char *new_instructor);
int update_activity_time(t_activity *activity, time_t new_start_time, int new_duration);

// ===== FUNZIONI DI UTILITÀ =====
int count_activities(t_activity *head);
int count_activities_by_instructor(t_activity *head, char *instructor);
int is_activity_full(t_activity *activity);
int get_available_spots(t_activity *activity);
void increment_participants(t_activity *activity);
void decrement_participants(t_activity *activity);

#endif
