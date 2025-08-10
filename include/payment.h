#ifndef PAYMENT_H
#define PAYMENT_H

#include <time.h>

typedef struct s_payment
{
    int payment_id;
    int member_id;
    float amount;
    time_t payment_date;
    char payment_method[20];  // "carta", "contanti", "bonifico"
    struct s_payment *next;
} t_payment;

// ===== FUNZIONI DI BASE =====
t_payment *create_payment(int payment_id, int member_id, float amount, char *payment_method);
t_payment *add_payment(t_payment **head, int payment_id, int member_id, float amount, char *payment_method);
void remove_payment(t_payment **head, int payment_id);
void free_payment_list(t_payment **head);

// ===== FUNZIONI DI RICERCA =====
t_payment *find_payment_by_id(t_payment *head, int payment_id);
t_payment *find_payments_by_member(t_payment *head, int member_id);

// ===== FUNZIONI DI VISUALIZZAZIONE =====
void print_payment(t_payment *payment);
void print_all_payments(t_payment *head);
void print_member_payments(t_payment *head, int member_id);

// ===== FUNZIONI DI UTILITÀ =====
int count_payments(t_payment *head);
int count_payments_by_member(t_payment *head, int member_id);
float get_total_payments_by_member(t_payment *head, int member_id);
float get_total_payments_by_date_range(t_payment *head, time_t start_date, time_t end_date);

#endif
