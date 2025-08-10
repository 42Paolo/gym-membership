#include "../include/utils.h"

int main(void)
{
    t_gymember *head;
    t_gymember *found_member;
    
    // Inizializza la lista vuota
    head = NULL;
    
    printf("=== GESTIONE MEMBRI PALESTRA ===\n\n");
    
    // Aggiungi alcuni membri
    printf("Aggiungendo membri...\n");
    add_gymember(&head, 1, 101, "Marco Rossi", 25);
    add_gymember(&head, 2, 101, "Anna Bianchi", 30);
    add_gymember(&head, 3, 102, "Luca Verdi", 28);
    add_gymember(&head, 4, 101, "Sofia Neri", 22);
    
    // Stampa tutti i membri
    printf("\nLista completa dei membri:\n");
    print_all_gymembers(head);
    
    // Cerca un membro per ID
    printf("\nCercando membro con ID 2:\n");
    found_member = find_gymember_by_id(head, 2);
    if (found_member)
        print_gymember(found_member);
    else
        printf("Membro non trovato\n");
    
    // Cerca un membro per nome
    printf("\nCercando membro 'Luca Verdi':\n");
    found_member = find_gymember_by_name(head, "Luca Verdi");
    if (found_member)
        print_gymember(found_member);
    else
        printf("Membro non trovato\n");
    
    // Modifica un membro
    printf("\nModificando l'età di Marco Rossi:\n");
    found_member = find_gymember_by_name(head, "Marco Rossi");
    if (found_member)
    {
        update_gymember_age(found_member, 26);
        printf("Età aggiornata:\n");
        print_gymember(found_member);
    }
    
    // Conta i membri
    printf("\nStatistiche:\n");
    printf("Totale membri: %d\n", count_gymembers(head));
    printf("Membri nella palestra 101: %d\n", count_gymembers_by_gym(head, 101));
    printf("Membri nella palestra 102: %d\n", count_gymembers_by_gym(head, 102));
    
    // Rimuovi un membro
    printf("\nRimuovendo membro con ID 3:\n");
    remove_gymember(&head, 3);
    printf("Lista dopo la rimozione:\n");
    print_all_gymembers(head);
    
    // Verifica se un membro esiste
    printf("\nVerificando esistenza membri:\n");
    printf("Membro ID 1 esiste: %s\n", gymember_exists(head, 1) ? "Sì" : "No");
    printf("Membro ID 5 esiste: %s\n", gymember_exists(head, 5) ? "Sì" : "No");
    
    // Libera la memoria
    printf("\nLiberando memoria...\n");
    free_gymember_list(&head);
    
    printf("Programma completato!\n");
    return (0);
}

