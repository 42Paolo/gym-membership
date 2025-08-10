#ifndef GYM_MEMBER_H
#define GYM_MEMBER_H

#include <time.h>

typedef struct s_gymember
{
    int ID_member;
    int ID_gym;
    char nome[20];
    int anni;
    char membership_type[20];    // "mensile", "annuale", "giornaliero"
    time_t registration_date;    // Data di registrazione
    time_t expiry_date;         // Data di scadenza abbonamento
    int is_active;              // 1 = attivo, 0 = scaduto
    struct s_gymember *next;
} t_gymember;

// ===== FUNZIONI DI BASE =====
t_gymember *create_gymember(int id_member, int id_gym, char *nome, int anni, char *membership_type);
t_gymember *add_gymember(t_gymember **head, int id_member, int id_gym, char *nome, int anni, char *membership_type);
void remove_gymember(t_gymember **head, int id_member);
void free_gymember_list(t_gymember **head);

// ===== FUNZIONI DI RICERCA =====
t_gymember *find_gymember_by_id(t_gymember *head, int id_member);
t_gymember *find_gymember_by_name(t_gymember *head, char *nome);
t_gymember *find_gymember_by_gym(t_gymember *head, int id_gym);

// ===== FUNZIONI DI VISUALIZZAZIONE =====
void print_gymember(t_gymember *member);
void print_all_gymembers(t_gymember *head);

// ===== FUNZIONI DI MODIFICA =====
int update_gymember_name(t_gymember *member, char *new_name);
int update_gymember_age(t_gymember *member, int new_age);
int update_gymember_gym(t_gymember *member, int new_gym_id);
int update_membership_type(t_gymember *member, char *new_type);

// ===== FUNZIONI DI UTILITÀ =====
int count_gymembers(t_gymember *head);
int count_gymembers_by_gym(t_gymember *head, int id_gym);
int gymember_exists(t_gymember *head, int id_member);

// ===== FUNZIONI GESTIONE ABBONAMENTI =====
int is_membership_active(t_gymember *member);
void check_all_expired_members(t_gymember **head);
int get_membership_days_left(t_gymember *member);
void renew_membership(t_gymember *member, int months);
int count_active_members(t_gymember *head);
int count_members_by_type(t_gymember *head, char *type);
void print_expiring_soon(t_gymember *head, int days_threshold);

#endif
