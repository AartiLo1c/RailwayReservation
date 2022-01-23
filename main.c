#include<stdio.h>
#include<stdlib.h>
#include"rlyres.h"
#include"conio2.h"
int main()
{
    int choice;
    add_trains();
    Passenger *ptr;
    int ticket_no;
    int result;
    char *ptrain_no;
    char *pmob_no;
    int *pticket_no;
    while(1)
    {
        choice=enter_choice();
        if(choice==9)
            exit(0);
        switch(choice)
        {
        case 1:
            clrscr();
            view_trains();
            break;
        case 2:
            clrscr();
            ptr = get_passenger_details();
            clrscr();
            if(ptr!=NULL)
            {
                ticket_no=book_ticket(*ptr);
                if(ticket_no==-1)
                {
                    textcolor(LIGHTRED);
                    printf("booking failed");
                }
                else
                {
                    textcolor(LIGHTGREEN);
                    printf("\nTicket successfully booked\nyour  ticket number is %d ",ticket_no);
                }
                textcolor(WHITE);
                printf("\nPress any key to go back to main menu");
                getch();
                clrscr();
            }
            break;
        case 3:
            clrscr();
            ticket_no=accept_ticket_no();
            if(ticket_no!=0)
                view_ticket(ticket_no);
            textcolor(WHITE);
            printf("\nPress any key to go back to main menu");
            getch();
            clrscr();
            break;
        case 4:
            clrscr();
            pmob_no=accept_mob_no();
            if(pmob_no!=NULL)
            {
                pticket_no=get_ticket_no(pmob_no);
                view_all_tickets(pmob_no,pticket_no);
            }
            clrscr();
            break;

            break;
        case 5:
            clrscr();
            view_all_bookings();
           // getch();
            break;
        case 6:
            clrscr();
            ptrain_no=accept_train_no();
            if(ptrain_no!=0)
            {
                view_bookings(ptrain_no);
            }
            getch();
            break;
        case 7:
            clrscr();
            ticket_no= accept_ticket_no();
            if(ticket_no!=0)
            {
                result=cancel_ticket(ticket_no);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry!no tickets booked against ticket no %d",ticket_no);
                }
                else if(result==1)
                {
                    textcolor(LIGHTGREEN);
                    printf("ticket no %d successfully cancelled",ticket_no);
                }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to main menu");
                }

            getch();
            clrscr();
            break;
        case 8:
             clrscr();
             int result = 1;
            ptrain_no = accept_train_no();
            if(ptrain_no != NULL)
            {
                result = cancel_train(ptrain_no);
                if(result==0)
                {
                    textcolor(LIGHTRED);
                    printf("Sorry!No train found of no. %s",ptrain_no);
                }
                if(result==1)
                {
                    textcolor(LIGHTGREEN);
                    printf("train no %s successfully cancelled",ptrain_no);
                }
                textcolor(WHITE);
                printf("\n\nPress any key to go back to main menu");
            }
                getch();
                clrscr();
            break;

        default:
            textcolor(LIGHTRED);
            printf("Wrong choice!Try again\n");
            getch();
            clrscr();
    }
    }

    return 0;
}
