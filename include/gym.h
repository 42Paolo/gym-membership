#ifndef GYM_H
#define GYM_H

typedef struct s_gym
{
    int gym_id;
    char name[50];
    char address[100];
    char phone[20];
    int capacity;
    struct s_gym *next;
} t_gym;

// ===== FUNZIONI DI BASE =====
t_gym *create_gym(int gym_id, char *name, char *address, char *phone, int capacity);
t_gym *add_gym(t_gym **head, int gym_id, char *name, char *address, char *phone, int capacity);
void remove_gym(t_gym **head, int gym_id);
void free_gym_list(t_gym **head);

// ===== FUNZIONI DI RICERCA =====
t_gym *find_gym_by_id(t_gym *head, int gym_id);
t_gym *find_gym_by_name(t_gym *head, char *name);

// ===== FUNZIONI DI VISUALIZZAZIONE =====
void print_gym(t_gym *gym);
void print_all_gyms(t_gym *head);

// ===== FUNZIONI DI MODIFICA =====
int update_gym_name(t_gym *gym, char *new_name);
int update_gym_address(t_gym *gym, char *new_address);
int update_gym_phone(t_gym *gym, char *new_phone);
int update_gym_capacity(t_gym *gym, int new_capacity);

// ===== FUNZIONI DI UTILITÀ =====
int count_gyms(t_gym *head);
int get_total_capacity(t_gym *head);

#endif
