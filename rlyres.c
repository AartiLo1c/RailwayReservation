#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include"conio2.h"
#include"rlyres.h"
#include"conio.h"
int enter_choice()
{
    clrscr();
    int choice,i;
    textcolor(YELLOW);
    gotoxy(28,1);
    printf("RAILWAY RESERVATION SYSTEM\n");
    for(i=1;i<=80;i++){
        printf("=");
        textcolor(LIGHTBLUE);}
        textcolor(WHITE);
    printf("SELECT AN OPTION:--\n");
    printf("1- View Trains\n");
    printf("2- Book Ticket\n");
    printf("3- View Ticket\n");
    printf("4- Search Ticket No.\n");
    printf("5- View All Bookings\n");
    printf("6- View Train Bookings\n");
    printf("7- Cancel Ticket\n");
    printf("8- Cancel Train\n");
    printf("9- Quit\n\n");
    printf("Enter choice:");
    scanf("%d",&choice);
    return choice;
}

void add_trains()
{
    FILE *fp;
    fp = fopen("D:\\myproject\\alltrains.dat","rb");
    if(fp==NULL)
    {
        Train alltrains[4]={
        {"123","BPL","GWA",2100,1500},
        {"546","BPL","DEL",3500,2240},
        {"345","HBJ","AGR",1560,1135},
        {"896","HBJ","MUM",4500,3360},
        };
        fp=fopen("D:\\myproject\\alltrains.dat","wb");
        fwrite(alltrains,4*sizeof(Train),1,fp);
        printf("file saved  successfully\n");
        fclose(fp);
    }
    else{
           printf("file already present\n");
        fclose(fp);
    }
}
    void view_trains()
    {
    int i,j;
    FILE * fp=fopen("D:\\myproject\\alltrains.dat","rb");
      Train alltrains[4];
      fread(alltrains,4*sizeof(Train),1,fp);
      textcolor(YELLOW);
      printf("Train.no\tFrom\t\t To\tFIRST AC FAIR\tSECOND AC FAIR\n");
       for(j=1;j<=80;j++){
        printf("=");
        textcolor(LIGHTBLUE);}
      for(i=0;i<=3;i++)
      {
          textcolor(WHITE);
        printf("%s \t\t %s\t\t %s\t %d \t\t%d \n",alltrains[i].train_no,alltrains[i].from,alltrains[i].to,alltrains[i].fac_fare,alltrains[i].sac_fare);
      }
      fclose(fp);
        printf("\n");
        textcolor(WHITE);
        gotoxy(1,24);
        printf("Press any key to go back to the main screen");
        getch();

        return 0;
    }
    Passenger* get_passenger_details()
    {
        textcolor(LIGHTGREEN);
        gotoxy(60,1);
        printf("Press 0 to Exit");
        gotoxy(1,1);
        textcolor(YELLOW);
        static Passenger psn;
        printf("Enter Passenger name:");
        fflush(stdin);
        fgets(psn.p_name,20,stdin);
        char *pos;
        pos = strchr(psn.p_name,'\n');
        *pos='\0';
        if(strcmp(psn.p_name,"0")==0)
        {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            getch();
            return NULL;
        }

        printf("Enter gender(M/F):");
        int valid = 1;
        do
        {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.gender);
            if(psn.gender=='0')
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("\t\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            if(psn.gender!='M' && psn.gender!='F')
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!Gender should be M or F(in uppercase)");
                valid=0;
                getch();
                gotoxy(19,2);
                printf(" \b");
                textcolor(YELLOW);
            }
            }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t");
            gotoxy(1,3);
            printf("Enter Train number: ");
            do
            {
            fflush(stdin);
            scanf("%s",psn.train_no);
            if(strcmp(psn.train_no,"0")==0)
            {
            gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("Reservation Cancelled");
            getch();
            textcolor(YELLOW);
            return NULL;
            }
            valid = check_train_no(psn.train_no);
            if(valid==0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!Invalid Train no");
                getch();
                gotoxy(20,3);
                printf("\t\t\t\t\t\t\t\t");
                gotoxy(20,3);
                textcolor(YELLOW);
            }
            }while(valid==0);
            gotoxy(1,25);
             printf("\t\t\t\t\t\t");
            gotoxy(1,4);

       printf("Enter Travelling Class(FIRST AC-F,SECOND AC-S):");
      //  int valid1 = 1;
        do
        {
            valid=1;
            fflush(stdin);
            scanf("%c",&psn.p_class);
            if(psn.p_name=='0')
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("\t\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled");
                getch();
                textcolor(YELLOW);
                return NULL;
            }
            if(psn.p_class!='F' && psn.p_class!='S')
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!Train Class should be F or S(in uppercase)");
                valid=0;
                getch();
                gotoxy(48,4);
                printf(" \b");
                textcolor(YELLOW);
            }
            }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t");
            gotoxy(1,5);

             printf("Enter Address: ");
            fflush(stdin);
            fgets(psn.address,30,stdin);
            //char *pos1;
            removeChar(&psn.address);
            if(psn.address[0]=='0')
            {
                displayError("Reservation Cancelled");
                return NULL;
            }

           gotoxy(1,6);
                printf("Enter Age: ");
                do
                {
                    valid=1;
                    fflush(stdin);
                    scanf("%d",&psn.age);
                    if(psn.age==0)
                    {
                        gotoxy(1,25);
                        textcolor(LIGHTRED);
                        printf("\t\t\t\t\t\t\t\t");
                        gotoxy(1,25);
                        printf("Reservation Cancelled");
                        getch();
                        textcolor(YELLOW);
                        return NULL;
                    }
                    if(psn.age<=0)
                    {
                        textcolor(LIGHTRED);
                        gotoxy(1,25);
                        printf("Error!Age must be positive");
                        valid=0;
                        getch();
                        gotoxy(11,6);
                        printf("\t\t\t\t\t\t\t\t");
                        gotoxy(11,6);
                        textcolor(YELLOW);
                    }
                    }while(valid==0);
                    gotoxy(1,25);
                    printf("\t\t\t\t\t\t\t\t");
                    gotoxy(1,7);

            printf("Enter Mobile Number: ");
            do
            {
            valid=1;
            fflush(stdin);
            fgets(psn.mob_no,11,stdin);
            pos = strchr(psn.mob_no,'\n');
            if(pos!=NULL)
                *pos='\0';
            if(strcmp(psn.mob_no,"0")==0)
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("Reservation Cancelled");
                getch();
                textcolor(YELLOW);
                getch();
                return NULL;
            }
            valid=check_mob_no(psn.mob_no);
            if(valid==0)
            {
                textcolor(RED);
                gotoxy(1,25);
                printf("Invalid! Mobile Number");
                getch();
                gotoxy(21,7);
                printf("\t\t\t\t\t");
                gotoxy(21,7);
                textcolor(YELLOW);
            }
            }while(valid==0);
            gotoxy(1,25);
            printf("\t\t\t\t\t");
            return &psn;
          return NULL;
        }

    int check_train_no(char* num)
    {
        FILE *fp;
        fp=fopen("D:\\myproject\\alltrains.dat","rb");
        Train tr;
        while(fread(&tr,sizeof(tr),1,fp)==1)
        {
            if(strcmp(tr.train_no,num)==0)
            {
                fclose(fp);
                return 1;
            }
        }
        fclose(fp);
        return 0;
    }
    int get_booked_ticket_count(char *train_no,char tc)
    {
       FILE *fp=fopen("D:\\myproject\\alltrains.dat","rb");
       if(fp==NULL)
        return 0;
       Passenger pr;
       int count=0;
       while(fread(&pr,sizeof(pr),1,fp)==1)
       {
           if(strcmp(pr.train_no,train_no)==0&&pr.p_class==tc)
            ++count;
       }
       fclose(fp);
       return count;
    }

    int last_ticket_no()
    {
        FILE *fp=fopen("D:\\myproject\\allbookings.dat","rb");
        if(fp==NULL)
            return 0;
        Passenger pr;
        fseek(fp,-1*sizeof(pr),SEEK_END);
        fread(&pr,sizeof(pr),1,fp);
        fclose(fp);
        return pr.ticketno;
    }
    int book_ticket(Passenger p)
    {
        int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
        if(ticket_count==2)
        {
            textcolor(LIGHTRED);
            printf("all seats full in train number %s in %c class\n",p.train_no,p.p_class);
            return -1;
        }
        int ticket_no=last_ticket_no()+1;
        p.ticketno=ticket_no;
        FILE *fp=fopen("D:\\myproject\\allbookings.dat","ab");
        if(fp==NULL)
            return -1;
        fwrite(&p,sizeof(p),1,fp);
        fclose(fp);
        return ticket_no;
    }

    int check_mob_no(char *p_mob)
    {
        if(strlen(p_mob)!=10)
           return 0;
           while(*p_mob!='\0')
        {
            if(isdigit(*p_mob)==0)
                return 0;
            p_mob++;
        }
        return 1;
    }

    int accept_ticket_no()
    {
         printf("Enter Ticket number: ");
         int ticket_no;
         int valid;
            do
            {
            valid=1;
            scanf("%d",&ticket_no);
            if(ticket_no==0)
            {
                gotoxy(1,25);
                textcolor(LIGHTRED);
                printf("\t\t\t\t\t\t\t\t");
                gotoxy(1,25);
                printf("Reservation Cancelled");
                getch();
                textcolor(YELLOW);
                return 0;
            }
            if(ticket_no<=0)
            {
                textcolor(LIGHTRED);
                gotoxy(1,25);
                printf("Error!Ticket number must be positive");
                valid=0;
                getch();
                gotoxy(11,1);
                printf("\t\t\t\t\t\t\t\t");
                gotoxy(11,1);
                textcolor(YELLOW);
            }
            }while(valid==0);
            return ticket_no;
    }

    int cancel_ticket(int ticket_no)
    {
         FILE *fp1=fopen("D:\\myproject\\allbookings.dat","rb+");
        if(fp1==NULL)
        {
            textcolor(LIGHTRED);
            printf("\nNo bookings done yet");
            return -1;
        }
         FILE *fp2=fopen("D:\\myproject\\temp.dat","wb");
        Passenger pr;
        int found=0;
        while(fread(&pr,sizeof(pr),1,fp1)==1)
        {
            if(pr.ticketno!=ticket_no)
            {
                fwrite(&pr,sizeof(pr),1,fp2);
            }
            else{
                found=1;
            }
        }
        fclose(fp1);
        fclose(fp2);
        if(found==0)
        {
            remove("D:\\myproject\\temp.dat");
        }
        else
        {
            remove("D:\\myproject\\allbookings.dat");
            rename("D:\\myproject\\temp.dat","D:\\myproject\\allbookings.dat");
        }
        return found;
    }


        void displayError(char *msg)
        {
             gotoxy(1,25);
            textcolor(LIGHTRED);
            printf("\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("%s",msg);
            //getch();
            textcolor(YELLOW);
            getch();
            return NULL;
        }
        void clearError()
        {
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
        }
        void removeChar(char *str)
        {
            char *tmp=strchr(str,'\n');
            if(tmp!=NULL)
                *tmp='\0';
        }

        void view_ticket(int ticket_no)
        {
            int i;
            FILE *fp=fopen("D:\\myproject\\allbookings.dat","rb");
            if(fp==NULL)
            {
                textcolor(LIGHTRED);
                printf("\nNo bookings done yet");
                return;
            }

            Passenger pr;
            int found=0;
            while(fread(&pr,sizeof(pr),1,fp)==1)
            {
            if(pr.ticketno==ticket_no)
            {
               printf("\nNAME: %s\nGENDER: %c\nTRAIN NO: %s\nCLASS: %c\nADDRRESS: %s\nAGE: %d\nMOBILE NO: %s\nTICKET NO: %d\n",pr.p_name,pr.gender,pr.train_no,pr.p_class,pr.address,pr.age,pr.mob_no,pr.ticketno);
               printf("\n\n");
              found=1;
              break;
            }
            }
            if(!found)
            {
                textcolor(LIGHTRED);
                printf("\nNo details of ticket no %d found!",ticket_no);

            }
        fclose(fp);
        }

        char* accept_mob_no()
        {
            static char mob_no[11];
            char *pos;
            int valid;
            printf("Enter mobile number:");
            do
            {
            fflush(stdin);
            fgets(mob_no,11,stdin);
            pos=strchr(mob_no,'\n');
            if(pos!=NULL)
               *pos='\0';
            if(strcmp(mob_no,"0")==0)
            {
              textcolor(LIGHTRED);
              gotoxy(1,25);
              printf("\t\t\t\t\t\t\t");
              gotoxy(1,25);
              printf("Cancelling Input. . .!");
              getch();
              textcolor(YELLOW);
              return NULL;
            }
            valid=check_mob_no(mob_no);
            if(valid==0)
              {
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("Error! Invalid Mobile No");
               getch();
               gotoxy(21,1);
               printf("\t\t\t\t\t\t");
               gotoxy(21,1);
               textcolor(YELLOW);
              }
             }while(valid==0);
            clrscr();
            return mob_no;
        }

        int* get_ticket_no(char *p_mob_no)
        {
           int count=0;
           FILE *fp=fopen("D:\\myproject\\allbookings.dat","rb");
           if(fp==NULL)
            {
                return NULL;
            }
           Passenger pr;
           while(fread(&pr,sizeof(pr),1,fp)==1)
            {
              if(strcmp(pr.mob_no,p_mob_no)==0)
                    ++count;
           }
            if(count==0)
            {
                fclose(fp);
                return NULL;
            }
            rewind(fp);
            int *p=(int*)malloc((count+1)*sizeof(int));
            int i=0;
            while(fread(&pr,sizeof(pr),1,fp)==1)
            {
              if(strcmp(pr.mob_no,p_mob_no)==0)
              {
                  *(p+i)=pr.ticketno;
                    i++;
              }
            }
        *(p+i)=-1;
        fclose(fp);
        return p;
        }

        void view_all_tickets(char *pmob_no,int *pticket_no)
        {
            if(pticket_no==NULL)
            {
                textcolor(LIGHTRED);
                printf("Sorry! No tickets booked against mobile no %s",pmob_no);
                textcolor(WHITE);
                printf("\n\nPress any key to go back to the main screen");
                textcolor(YELLOW);
                getch();
                return;
            }
            printf("Following are tickets booked for mobile no %s",pmob_no);
            int i;
            printf("\n\nTICKET NO\n");
            printf("---------");
            for(i=0;*(pticket_no+i)!=-1;i++)
                printf("\n%d",*(pticket_no+i));
            textcolor(WHITE);
            printf("\n\nPress any key to go back to the main screen");
            textcolor(YELLOW);
            getch();
        }

        char* accept_train_no()
        {
            static char train_no[4];
            char *pos;
            int valid;
            printf("Enter train number:");
            do
            {
            fflush(stdin);
            fgets(train_no,4,stdin);
            pos=strchr(train_no,'\n');
            if(pos!=NULL)
               *pos='\0';
            if(strcmp(train_no,"0")==0)
            {
              textcolor(LIGHTRED);
              gotoxy(1,25);
              printf("\t\t\t\t\t\t\t");
              gotoxy(1,25);
              printf("Cancelling Input. . .!");
              getch();
              textcolor(YELLOW);
              return NULL;
            }
            valid=check_train_no(train_no);
            if(valid==0)
              {
               textcolor(LIGHTRED);
               gotoxy(1,25);
               printf("Error! Invalid Train No");
               getch();
               gotoxy(20,1);
               printf("\t\t\t\t\t\t");
               gotoxy(20,1);
               textcolor(YELLOW);
              }
             }while(valid==0);
            clrscr();
            return train_no;
        }

       void view_bookings(char* ptrain_no)
       {
           int i=0,j=1,k=1;
           FILE *fp3=fopen("D:\\myproject\\allbookings.dat","rb");
           if(fp3==NULL)
           {
               gotoxy(1,25);
               printf("No bookings done yet");
               return -1;
           }
           for(j=1;j<=1;j++)
           {
                gotoxy(1,1);
                printf("TICKET NO");
                gotoxy(20,1);
                printf("CLASS");
                gotoxy(35,1);
                printf("NAME");
                gotoxy(55,1);
                printf("MOBILE");
           }
            printf("\n");
            for(k=1;k<=74;k++)
            {
                printf("-");
            }
             int m=3,s;
            s=get_total_ticket_count();
            Passenger psg[s];
           while(fread(&psg,sizeof(Passenger),1,fp3)==1)
           {
            for(i=0;i<s;i++)
            {
            if(strcmp(ptrain_no,psg[i].train_no)==0) {
            {
            gotoxy(1,m);
            printf("%d",psg[i].ticketno);
            gotoxy(20,m);
            printf("%c",psg[i].p_class);
            gotoxy(35,m);
            printf("%s",psg[i].p_name);
            gotoxy(55,m);
            printf("%s",psg[i].mob_no);
            m++;
            }
            }
            }
           }
            textcolor(WHITE);
            gotoxy(1,15);
            printf("\n\nPress any key to go back to the main screen");
           fclose(fp3);
            return 0;
       }

    void view_all_bookings()
    {
    int i,j;
    FILE * fp=fopen("D:\\myproject\\allbookings.dat","rb");
      int c;
       c=get_total_ticket_count();
       Passenger ps[c];
      fread(&ps,sizeof(Passenger),c,fp);
        gotoxy(1,1);
        printf("TRAIN NO");
        gotoxy(15,1);
        printf("TICKET NO");
        gotoxy(30,1);
        printf("CLASS");
        gotoxy(40,1);
        printf("NAME");
        gotoxy(60,1);
        printf("MOBILE");
        printf("\n");
       for(j=1;j<=74;j++)
        printf("-");
       int  m=3;
      for(i=0;i<c;i++)
      {
            gotoxy(1,m);
            printf("%s",ps[i].train_no);
            gotoxy(15,m);
            printf("%d",ps[i].ticketno);
            gotoxy(30,m);
            printf("%c",ps[i].p_class);
            gotoxy(40,m);
            printf("%s",ps[i].p_name);
            gotoxy(60,m);
            printf("%s",ps[i].mob_no);
            m++;
      }
      fclose(fp);
        printf("\n");
        textcolor(WHITE);
        gotoxy(1,24);
        printf("Press any key to go back to the main screen");
        getch();
        return 0;
    }
        int get_total_ticket_count()
        {
            FILE *fp4=fopen("D:\\myproject\\allbookings.dat","rb");
            Passenger p;
            int x=0;
            while(fread(&p,sizeof(p),1,fp4)==1)
            {
                    x++;
            }
            fclose(fp4);
                return x;
        }

        int cancel_train(char *ptrain_no)
        {
         FILE *fp1=fopen("D:\\myproject\\allbookings.dat","rb+");
        if(fp1==NULL)
        {
            textcolor(LIGHTRED);
            printf("\nNo bookings done yet");
            return -1;
        }
         FILE *fp2=fopen("D:\\myproject\\tmp.dat","wb");
        Passenger pr;
        int  found=0;
        while(fread(&pr,sizeof(pr),1,fp1)==1)
        {
            if(strcmp(pr.train_no,ptrain_no)!=0)
            {
                fwrite(&pr,sizeof(pr),1,fp2);
            }
            else
            {
                found=1;
            }

        }
        fclose(fp1);
        fclose(fp2);
        if(found==0)
        {
            remove("D:\\myproject\\tmp.dat");
        }
        else
        {
            remove("D:\\myproject\\allbookings.dat");
            rename("D:\\myproject\\tmp.dat","D:\\myproject\\allbookings.dat");
        }
        return found;
        }

