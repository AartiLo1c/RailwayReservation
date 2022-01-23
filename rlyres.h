#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED

struct Train
{
    char train_no[20];
    char from[25];
    char to[25];
    int fac_fare;
    int sac_fare;
};typedef struct Train Train;
struct passenger
{
    char p_name[30];
    char gender;
    char train_no[10];
    char p_class;
    char address[30];
    char mob_no[10];
    int age;
    int ticketno;
};
typedef struct passenger Passenger ;

int enter_choice();
void add_trains();
void view_trains();
int book_ticket(Passenger);
int* get_ticket_no(char*);
void view_ticket(int);
void view_all_bookings();
void view_bookings(char*);
int cancel_ticket(int);
int cancel_train(char*);
int check_mob_no(char*);
int accept_ticket_no();
char* accept_mob_no();
int check_mob_no(char*);
int get_total_ticket_count();
void view_all_tickets(char *,int *);
char* accept_train_no();
int check_train_no(char*);
void view_ticket(int);


#endif // RLYRES_H_INCLUDED
