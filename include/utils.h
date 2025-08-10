#ifndef UTILS_H
#define UTILS_H

#include <unistd.h>
#include <printf.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// ===== FUNZIONI DI UTILITÀ GENERALI =====
char *time_to_string(time_t time);
time_t add_months_to_time(time_t time, int months);
int days_between_dates(time_t date1, time_t date2);
void print_current_time(void);

// ===== FUNZIONI DI SISTEMA =====
void book_activity_for_member(void **bookings, void **activities, int member_id, int activity_id);
void cancel_activity_booking(void **bookings, void **activities, int member_id, int activity_id);
void process_payment_for_member(void **payments, int member_id, float amount, char *payment_method);
void check_and_update_memberships(void **members);
void print_system_statistics(void *members, void *payments, void *activities, void *bookings);

#endif