#ifndef BOOKING_H
#define BOOKING_H

#include <time.h>

typedef struct s_booking
{
    int booking_id;
    int member_id;
    int activity_id;
    time_t booking_date;
    int status;  // 1 = confermato, 0 = cancellato
    struct s_booking *next;
} t_booking;

// ===== FUNZIONI DI BASE =====
t_booking *create_booking(int booking_id, int member_id, int activity_id);
t_booking *add_booking(t_booking **head, int booking_id, int member_id, int activity_id);
void remove_booking(t_booking **head, int booking_id);
void free_booking_list(t_booking **head);

// ===== FUNZIONI DI RICERCA =====
t_booking *find_booking_by_id(t_booking *head, int booking_id);
t_booking *find_bookings_by_member(t_booking *head, int member_id);
t_booking *find_bookings_by_activity(t_booking *head, int activity_id);

// ===== FUNZIONI DI VISUALIZZAZIONE =====
void print_booking(t_booking *booking);
void print_all_bookings(t_booking *head);
void print_member_bookings(t_booking *head, int member_id);
void print_activity_bookings(t_booking *head, int activity_id);

// ===== FUNZIONI DI UTILITÀ =====
int count_bookings(t_booking *head);
int count_bookings_by_member(t_booking *head, int member_id);
int count_bookings_by_activity(t_booking *head, int activity_id);
int is_member_booked_for_activity(t_booking *head, int member_id, int activity_id);
void cancel_booking(t_booking *booking);
void confirm_booking(t_booking *booking);

#endif
