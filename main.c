#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
//For Main Function
void playrand();
void playmanually();

//For Playmanually Function
void choice_team();
void Conduct_toss();
int randInt(int,int);
void playmatch();
void scoreboard();
int Playingteam[2];
//Code efficient making
void team_x();
void team_y();
void team_opt(int);
void team_ch();
void team_india_player(int);
void team_pakistan_player(int);
void team_Australia_player(int);
void team_England_player(int);
void team_South_Africa_player(int);
void store(int,char,int);
int wicket=0;
void player_choose(int ,char);                 //The one who plays the match
int t,w,ls;                      //toss result
int min=100, max=200;
int target=0;
int total=0;
char team1[20],team2[20];
//COUNTRIES
char I[]={'M','V','R','S','Y'};
char UI[5]={'0'};
char P[]={'B','S','F','H','W'};
char UP[5]={'0'};
char A[]={'S','D','A','G','M'};
char UA[5]={'0'};
char E[]={'B','J','E','A','M'};
char UE[5]={'0'};
char S[]={'Q','F','A','J','C'};
char US[5]={'0'};
FILE *fptr;

void main()
{
    system("color E0");
    int ch=0;


    do
    {   printf("\n\t\t ........ Select Your Mode .......");
        printf("\n 1. Play Randomly \n 2. Play Manually \n 3. Exit \n");
        printf("\n Enter Your Choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    playrand();
                    break;
            case 2:
                    playmanually();
                    break;
            case 3:
                    exit(0);
                    break;
            default :
                        printf("\n Enter Valid Choice .");
                        break;
        }
    }while(ch!=3);
    fclose(fptr);
    getch();
}

void playrand()
{
    char name1[20],name2[20];
    int i,score=0,S_O_P[2];
    int ro,rb;
     printf("\t\t\t\tWELCOME TO CRICKET\n\n");
    printf("\t\t\t     ........................\n");
    system("color E0");

    printf("Enter 1st player--> \t");
    scanf("%s",&name1);
    printf("Enter 2nd player--> \t");
    scanf("%s",&name2) ;
    for(i=0;i<2;i++)
     {
        if(i==0)
        {

                printf("\n\t\t\t Play your turn\t");
                puts(name1);
        }

        else
        {

            printf("\n\t\t\tPlay your turn\t");
            puts(name2);
        }

            for(ro=1;ro<=3;ro++)
            {
                for(rb=1;rb<=6;rb++)
                {
                    printf("\nOVER %d BALL %d",ro,rb);
                    printf("\n Press any key to score:- \n");
                    getch();
                    int j= randInt(min,max)%7;
                    printf("YOU SCORED %d runs \t\n\n",j);
                    score=score+j;

                }
            }
            printf("\n\t\t\t Total score = %d runs",score);
            printf("\t\t\t\t\t\t\t\t ....................\n");
            S_O_P[i]=score;
            score=0;
         }
            printf("\n\n\n\t\t\t Winner is\t");
                if(S_O_P[0]>S_O_P[1])
                {
                    puts(name1);
                    printf("\t\t\t    By %d runs\n\n\n",S_O_P[0]-S_O_P[1]);
                }
                else
                {
                    puts(name2);
                    printf("\t\t\t    By %d runs\n\n\n\n",S_O_P[1]-S_O_P[0]);
                }

}

void playmanually()
{
    int option=1;

    do{
        printf("\n\t\t\t\tWELCOME TO THE WORLD OF CRICKET\n");
        printf("\t\t\t\t.............................\n\n\n");
        printf("\t\t 1. Select Your Team\n");
        printf("\t\t 2. Play The Match \n");
        printf("\t\t 3. Get The Performance Sheet \n");
        printf("\t\t 4. Exit \n");
        printf("\n ENTER YOUR CHOICE :");
        scanf("%d",&option);
        printf("\n");

        switch(option)
        {
        case 1:
                choice_team();
                Conduct_toss();
                break;
        case 2:
                playmatch();
                break;
        case 3:
                scoreboard();
                break;
        case 4:
                exit(0);
                break;
        default:
                printf("\n Enter Valid choice :");
                break;
        }
       //printf("\n\n\t Enter Your Choice : ");
    //scanf("%d",&option);

    }while(option!=5);
}

void choice_team()
{
    int ch,opt,i;
    char teams[]={'I','P','A','E','S'};

    printf("\t\t\t Team Selection : \n");

    for(i=0;i<2;i++)
    {
        if(i==0)
        {
         printf("Select your Team \n\n");
            for(ch=0;ch<5;ch++)
            {
                if(teams[ch]=='I')
                printf("1.India \n");
            if(teams[ch]=='P')
                printf("2.Pakistan \n");
            if(teams[ch]=='A')
                printf("3.Australia \n");
            if(teams[ch]=='E')
                printf("4.England \n");
            if(teams[ch]=='S')
                printf("5.South_Africa\n");

            }

        printf("Enter your choice \n");
        scanf("%d",&opt);
        Playingteam[0]=opt;

        printf("\t\tYou are now playing as \t");
            team_opt(opt);
        }
        else
          {
            printf("Select your Opponent\n\n");
              for(i=opt-1;i<4;i++)
              {
                  teams[i]=teams[i+1];
              }
              for(ch=0;ch<4;ch++)
            {
                if(teams[ch]=='I')
                printf("1.India \n");
            if(teams[ch]=='P')
                printf("2.Pakistan \n");
            if(teams[ch]=='A')
                printf("3.Australia \n");
            if(teams[ch]=='E')
                printf("4.England \n");
            if(teams[ch]=='S')
                printf("5.South_Africa\n");

            }
             printf("Enter your choice \n");
            scanf("%d",&opt);
            i++;
            Playingteam[1]=opt;
            printf("\t\tYou are now playing against\t");
            team_opt(opt);
        }
}
}





void Conduct_toss()
{
printf("\n\n\t\tLet's Get Ready for Toss!\n");
int x=Playingteam[0];
int y=Playingteam[1];
    printf("0:-->\t");
          team_x();
    printf("\n1:-->\t");
            team_y();
    printf("\t\tPress any key to conduct then Toss!!!\n");
    getch();
    t=randInt(min,max)%2;
    printf("%d",t);
    if(t==0)
    {   printf(" \t\t\tCONGRATULATIONS !!!\t");
            team_x();
            w=Playingteam[0];
            ls=Playingteam[1];

    }
       else
        {
        printf(" \t\t\tCONGRATULATIONS !!!\t");
            team_y();
            w=Playingteam[1];
            ls=Playingteam[0];

       }


    }



void playmatch()
{
/*char I[]={'M','V','R','S','Y'};
char UI[5]={'0'};
char P[]={'B','S','F','H','W'};
char UP[5]={'0'};
char A[]={'S','D','A','G','M'};
char UA[5]={'0'};
char E[]={'B','J','E','A','M'};
char UE[5]={'0'};
char S[]={'Q','F','A','J','C'};
char US[5]={'0'};*/
 fptr = fopen("C://file//emp.txt", "a");/*  open for writing */
int x=Playingteam[0];
int y=Playingteam[1];
int i,p,player1,player,player2,inings,result;
if(t==0)
 {
     result=0;
 }
else
   {
     result=1;
   }
for(inings=0;inings<1;)
{
    if (inings==0)
    {

       if(result==0)
       {
        result=result+1;

            printf("Select your players sequence\n");
            if(x==1)
            {
                fprintf(fptr, "\n \t India \t \n");
                strcpy(team1,"India");
                for(i=0;i<=4;i++)
                {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                        if((I[p]=='M')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("1.M.S. Dhoni \n");
                        if((I[p]=='V')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("2.Virat Kohli \n");
                        if((I[p]=='R')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("3.Rohit Sharma \n");
                        if((I[p]=='S')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("4.Shikhar Dhavan \n");
                        if((I[p]=='Y')&&((I[p]!=UI[0]&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4]))))
                            printf("5.Yuvraj Singh\n");
                        }
                        printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UI[i]=I[player-1];
                        printf("\nYour %d player is \t",i+1);
                            team_india_player(player);
                }
            }



            if(x==2)
                {
                    fprintf(fptr, "\n \t Pakistan \t \n");
                    strcpy(team1,"Pakistan");
                    for(i=0;i<=4;i++)
                    {
                        for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                            {
                            if((P[p]=='B')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("1.Babar Azam \n");
                            if((P[p]=='S')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("2.Sarfaraz Khan \n");
                            if((P[p]=='F')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("3.Fakhar Zamaan \n");
                            if((P[p]=='H')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("4.Md.Hafeez \n");
                            if((P[p]=='W')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("5.Wahab Riyaz \n");
                            }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UP[i]=P[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_pakistan_player(player);
                    }

                }
                if(x==3)
                {
                    fprintf(fptr, "\n \t Australia \t \n");
                    strcpy(team1,"Australia");
                    for(i=0;i<=4;i++)
                    {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((A[p]=='S')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("1.Steve Smith \n");
                            if((A[p]=='D')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("2.David Miller \n");
                            if((A[p]=='A')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("3.Aaron Finch \n");
                            if((A[p]=='G')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("4.Glenn Maxwell \n");
                            if((A[p]=='M')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("5.Moeen Ali \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UA[i]=A[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_Australia_player(player);
                    }
                }
                if(x==4)
                {
                    fprintf(fptr, "\n \t England \t \n");
                    strcpy(team1,"England");
                    for(i=0;i<=4;i++)
                    {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((E[p]=='B')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("1.Ben Stokes \n");
                            if((E[p]=='J')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("2.Joe Root \n");
                            if((E[p]=='E')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("3.Eon Morgan \n");
                            if((E[p]=='A')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("4.Adil Rahid \n");
                            if((E[p]=='M')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("5.Mark Wood \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UE[i]=E[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_England_player(player);
                    }
            }

            if(x==5)
            {
                fprintf(fptr, "\n \t South_Africa \t \n");
                strcpy(team1,"South Africa");
                for(i=0;i<=4;i++)
                {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((S[p]=='Q')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("1.Quinton De kock \n");
                            if((S[p]=='F')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("2.Faf du Plessis \n");
                            if((S[p]=='A')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("3.AB Diviliers \n");
                            if((S[p]=='J')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("4.JP Duminy \n");
                            if((S[p]=='C')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("5.Chris Morris \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            US[i]=S[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_South_Africa_player(player);
                }
            }

        }
                          //end of if block where result=0
    else
        {
        result=result+2;
        printf("Select your players \n");
        if(y==1)
        {
            fprintf(fptr, "\n \t India \t \n");
            strcpy(team1,"India");
            for(i=0;i<=4;i++)
                {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                        if((I[p]=='M')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("1.M.S. Dhoni \n");
                        if((I[p]=='V')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("2.Virat Kohli \n");
                        if((I[p]=='R')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("3.Rohit Sharma \n");
                        if((I[p]=='S')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("4.Shikhar Dhavan \n");
                        if((I[p]=='Y')&&((I[p]!=UI[0]&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4]))))
                            printf("5.Yuvraj Singh\n");
                        }
                        printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UI[i]=I[player-1];
                        printf("\nYour %d player is \t",i+1);
                            team_india_player(player);
                }
        }
        if(y==2)
            {                                       //Selection of 1st player if y=2 in 1st innning
                fprintf(fptr, "\n \t Pakistan \t \n");
                strcpy(team1,"Pakistan");
                for(i=0;i<=4;i++)
                    {
                        for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                            {
                            if((P[p]=='B')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("1.Babar Azam \n");
                            if((P[p]=='S')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("2.Sarfaraz Khan \n");
                            if((P[p]=='F')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("3.Fakhar Zamaan \n");
                            if((P[p]=='H')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("4.Md.Hafeez \n");
                            if((P[p]=='W')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("5.Wahab Riyaz \n");
                            }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UP[i]=P[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_pakistan_player(player);
                    }
            }
            if(y==3)
                {
                    fprintf(fptr, "\n \t Australia \t \n");
                    strcpy(team1,"Australia");
                    for(i=0;i<=4;i++)
                        {
                        for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((A[p]=='S')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("1.Steve Smith \n");
                            if((A[p]=='D')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("2.David Miller \n");
                            if((A[p]=='A')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("3.Aaron Finch \n");
                            if((A[p]=='G')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("4.Glenn Maxwell \n");
                            if((A[p]=='M')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("5.Moeen Ali \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UA[i]=A[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_Australia_player(player);
                        }
                }
                if(y==4)
                {
                    fprintf(fptr, "\n \t England \t \n");
                    strcpy(team1,"England");
                    for(i=0;i<=4;i++)
                    {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((E[p]=='B')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("1.Ben Stokes \n");
                            if((E[p]=='J')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("2.Joe Root \n");
                            if((E[p]=='E')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("3.Eon Morgan \n");
                            if((E[p]=='A')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("4.Adil Rahid \n");
                            if((E[p]=='M')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("5.Mark Wood \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UE[i]=E[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_England_player(player);
                    }
                }

            if(y==5)
            {
                fprintf(fptr, "\n \t South_Africa \t \n");
                strcpy(team1,"South Africa");
                for(i=0;i<=4;i++)
                {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((S[p]=='Q')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("1.Quinton De kock \n");
                            if((S[p]=='F')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("2.Faf du Plessis \n");
                            if((S[p]=='A')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("3.AB Diviliers \n");
                            if((S[p]=='J')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("4.JP Duminy \n");
                            if((S[p]=='C')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("5.Chris Morris \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            US[i]=S[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_South_Africa_player(player);
                }
            }
            }                       //end of else when innings =0



printf("\t\tMatch is played now\n");
char PT[5];
char CreaseTeam[2];
int PTi=0,PTj=1;
if(result==1)
{
    if(x==1)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UI[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];

    }
    else if(x==2)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UP[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];
    }
    else if(x==3)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UA[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];

    }
    else if(x==4)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UE[i];                                //PT means playing team
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];

    }
    else if(x==5)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=US[i];
        }
       CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];

    }
}
else
{
    if(y==1)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UI[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];

    }
    else if(y==2)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UP[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];
    }
    else if(y==3)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UA[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];
    }
    else if(y==4)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=UE[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];

    }
    else if(y==5)
    {
        for(i=0;i<5;i++)
        {
        PT[i]=US[i];
        }
        CreaseTeam[0]=PT[PTi];
        CreaseTeam[1]=PT[PTj];
    }
}

printf("\n\n\t\tFirst playing team according to sequence is\n");

    for(i=0;i<5;i++)
    {
        printf("\t%c\t",PT[i]);
    }

int t1[18],t2[18],t3[18],t4[18],t5[18];
int run_lb=0,run_ub=7,run,k=0,l=0,j,m=0,n=0,o=0;
char temp;
int li;
char batsman=CreaseTeam[0];
printf("\nPlaying DUO is now %c & %c",CreaseTeam[0],CreaseTeam[1]);
for(li=1;li<=5;li++)
{
    for(j=1;j<=6;j++)
    {
        if(wicket<4){
        printf("\n\nOver %d\tBall %d\n",li,j);
        printf("Play your turn \t");
    if(t==0)
         player_choose(x,batsman);      //Function call for choosing the players
    else
        player_choose(y,batsman);



        printf("Press any key to score\n");
        getch();
        run=randInt(min,max)%8;
        if(run!=7){
            printf("You scored %d run\t\n",run);
            if(batsman==PT[0])
            {
            t1[k]=run;
            k++;
            }
            if(batsman==PT[1])
            {
            t2[l]=run;
            l++;
            }
            if(batsman==PT[2])
            {
            t3[m]=run;
            m++;
            }
            if(batsman==PT[3])
            {
            t4[n]=run;
            n++;
            }
            if(batsman==PT[4])
            {
            t5[o]=run;
            o++;
            }
        }

            if((run==1)||(run==3)||(run==5))
            {
            if(batsman==CreaseTeam[0])
              batsman=CreaseTeam[1];
           else
              batsman=CreaseTeam[0];
            }


        if(run==7)
        {
            ++wicket;
            printf("That's a OUT!!!!\n");
            if(wicket==4)
            {
                printf("\n\n\t\t\t !!!Team is ALL OUT!!!\n");
                break;
            }
          if(batsman==CreaseTeam[0])
           {
            temp=PT[++PTj];
            CreaseTeam[0]=temp;
            batsman=CreaseTeam[0];
            printf("Playing DUO is now %c & %c",CreaseTeam[0],CreaseTeam[1]);
           }
           else
           {
            temp=PT[++PTj];
            printf("Next player is now %c\t",temp);
            CreaseTeam[1]=temp;
            batsman=CreaseTeam[1];
            printf("Playing DUO is now %c & %c",CreaseTeam[0],CreaseTeam[1]);
           }

        }
        }
        else
        {
          printf("\n\n\t\t\t !!!Team is ALL OUT!!!\n");
          goto kick;
                break;
        }

    }
}

int sum1=0,sum2=0,sum3=0,sum4=0,sum5=0;
kick :
for(i=0;i<k;i++)
{
    sum1=sum1+t1[i];
}
for(i=0;i<l;i++)
{
    sum2=sum2+t2[i];
}
for(i=0;i<m;i++)
{
    sum3=sum3+t3[i];
}

for(i=0;i<n;i++)
{
    sum4=sum4+t4[i];
}

for(i=0;i<o;i++)
{
    sum5=sum5+t5[i];
}

printf("\nRuns ---> %c ---> %d\t",PT[0],sum1);
store(w,PT[0],sum1);
printf("\nRuns ---> %c ---> %d\t",PT[1],sum2);
store(w,PT[1],sum2);
printf("\nRuns ---> %c ---> %d\t",PT[2],sum3);
store(w,PT[2],sum3);
printf("\nRuns ---> %c ---> %d\t",PT[3],sum4);
store(w,PT[3],sum4);
printf("\nRuns ---> %c ---> %d\t",PT[4],sum5);
store(w,PT[4],sum5);
target=sum1+sum2+sum3+sum4+sum5;
printf("\n\n\t\t\tTARGET\t%d in %d overs",target,li-1);
fprintf(fptr, "\t Scored by team %s is  %d \n",team1,target);


inings++;                       //next innings starts now

    {
        printf("\n\t\tIt's now for opponent to Bat!!!!!!!\n");
        if(result==1)           /*here we have taken that if in the previous inning,
                                    if x played(by winnning the toss then result would be incremented by 1,
                                                so its time for y to play*/
    {
      printf("Select your players \n");
      if(y==1)                                  //Selection of 1st player if y=1 in 2nd innning
     {
        strcpy(team2,"India");
        fprintf(fptr, "\n \t India \t \n");
         for(i=0;i<=4;i++)
            {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                        if((I[p]=='M')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("1.M.S. Dhoni \n");
                        if((I[p]=='V')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("2.Virat Kohli \n");
                        if((I[p]=='R')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("3.Rohit Sharma \n");
                        if((I[p]=='S')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("4.Shikhar Dhavan \n");
                        if((I[p]=='Y')&&((I[p]!=UI[0]&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4]))))
                            printf("5.Yuvraj Singh\n");
                        }
                        printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UI[i]=I[player-1];
                        printf("\nYour %d player is \t",i+1);
                            team_india_player(player);
            }
    }
            if(y==2)
                {                                                   //Selection of 1st player if y=2 in 2nd innning
                    fprintf(fptr, "\n \t Pakistan \t \n");
                    strcpy(team2,"Pakistan");
                    for(i=0;i<=4;i++)
                    {
                        for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                            {
                            if((P[p]=='B')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("1.Babar Azam \n");
                            if((P[p]=='S')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("2.Sarfaraz Khan \n");
                            if((P[p]=='F')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("3.Fakhar Zamaan \n");
                            if((P[p]=='H')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("4.Md.Hafeez \n");
                            if((P[p]=='W')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("5.Wahab Riyaz \n");
                            }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UP[i]=P[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_pakistan_player(player);
                    }
                }
            if(y==3)
                {
                fprintf(fptr, "\n \t Australia \t \n");
                strcpy(team2,"Australia");
                for(i=0;i<=4;i++)
                        {
                        for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((A[p]=='S')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("1.Steve Smith \n");
                            if((A[p]=='D')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("2.David Miller \n");
                            if((A[p]=='A')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("3.Aaron Finch \n");
                            if((A[p]=='G')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("4.Glenn Maxwell \n");
                            if((A[p]=='M')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("5.Moeen Ali \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UA[i]=A[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_Australia_player(player);
                        }
                }
            if(y==4)
                {
                fprintf(fptr, "\n \t England \t \n");
                strcpy(team2,"England");
                for(i=0;i<=4;i++)
                    {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((E[p]=='B')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("1.Ben Stokes \n");
                            if((E[p]=='J')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("2.Joe Root \n");
                            if((E[p]=='E')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("3.Eon Morgan \n");
                            if((E[p]=='A')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("4.Adil Rahid \n");
                            if((E[p]=='M')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("5.Mark Wood \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UE[i]=E[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_England_player(player);
                    }
                }
            if(y==5)
            {
                fprintf(fptr, "\n \t South_Africa \t \n");
                strcpy(team2,"South Africa");
                for(i=0;i<=4;i++)
                {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((S[p]=='Q')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("1.Quinton De kock \n");
                            if((S[p]=='F')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("2.Faf du Plessis \n");
                            if((S[p]=='A')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("3.AB Diviliers \n");
                            if((S[p]=='J')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("4.JP Duminy \n");
                            if((S[p]=='C')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("5.Chris Morris \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            US[i]=S[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_South_Africa_player(player);
                }
            }
    }                   //end of if block of 2nd innings where result=1,here the value of result is 3
    else
        {
    printf("Select your players \n");
      if(x==1)
        {
        fprintf(fptr, "\n \t India \t \n");
        strcpy(team2,"India");
         for(i=0;i<=4;i++)
                {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                        if((I[p]=='M')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("1.M.S. Dhoni \n");
                        if((I[p]=='V')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("2.Virat Kohli \n");
                        if((I[p]=='R')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("3.Rohit Sharma \n");
                        if((I[p]=='S')&&((I[p]!=UI[0])&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4])))
                            printf("4.Shikhar Dhavan \n");
                        if((I[p]=='Y')&&((I[p]!=UI[0]&&(I[p]!=UI[1])&&(I[p]!=UI[2])&&(I[p]!=UI[3])&&(I[p]!=UI[4]))))
                            printf("5.Yuvraj Singh\n");
                        }
                        printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UI[i]=I[player-1];
                        printf("\nYour %d player is \t",i+1);
                            team_india_player(player);
                }
        }
            if(x==2)
                {
                    fprintf(fptr, "\n \t Pakistan \t \n");
                    strcpy(team2,"Pakistan");
                    for(i=0;i<=4;i++)
                    {
                        for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                            {
                            if((P[p]=='B')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("1.Babar Azam \n");
                            if((P[p]=='S')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("2.Sarfaraz Khan \n");
                            if((P[p]=='F')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("3.Fakhar Zamaan \n");
                            if((P[p]=='H')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("4.Md.Hafeez \n");
                            if((P[p]=='W')&&((P[p]!=UP[0])&&(P[p]!=UP[1])&&(P[p]!=UP[2])&&(P[p]!=UP[3])&&(P[p]!=UP[4])))
                                printf("5.Wahab Riyaz \n");
                            }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UP[i]=P[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_pakistan_player(player);
                    }
                }
            if(x==3)
                {
                fprintf(fptr, "\n \t Australia \t \n");
                strcpy(team2,"Australia");
                for(i=0;i<=4;i++)
                        {
                        for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 1st innning
                        {
                            if((A[p]=='S')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("1.Steve Smith \n");
                            if((A[p]=='D')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("2.David Miller \n");
                            if((A[p]=='A')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("3.Aaron Finch \n");
                            if((A[p]=='G')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("4.Glenn Maxwell \n");
                            if((A[p]=='M')&&((A[p]!=UA[0])&&(A[p]!=UA[1])&&(A[p]!=UA[2])&&(A[p]!=UA[3])&&(A[p]!=UA[4])))
                                printf("5.Moeen Ali \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UA[i]=A[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_Australia_player(player);
                        }
                }
            if(x==4)
                {
                fprintf(fptr, "\n \t England \t \n");
                strcpy(team2,"England");
                for(i=0;i<=4;i++)
                    {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=1 in 2nd innning
                        {
                            if((E[p]=='B')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("1.Ben Stokes \n");
                            if((E[p]=='J')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("2.Joe Root \n");
                            if((E[p]=='E')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("3.Eon Morgan \n");
                            if((E[p]=='A')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("4.Adil Rahid \n");
                            if((E[p]=='M')&&((E[p]!=UE[0])&&(E[p]!=UE[1])&&(E[p]!=UE[2])&&(E[p]!=UE[3])&&(E[p]!=UE[4])))
                                printf("5.Mark Wood \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            UE[i]=E[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_England_player(player);
                    }
                }
            if(x==5)
            {
                fprintf(fptr, "\n \t South_Africa \t \n");
                strcpy(team2,"South Africa");
                for(i=0;i<=4;i++)
                {
                     for(p=0;p<=4;p++)                   //Selection of 1st player if x=5 in 2nd innning
                        {
                            if((S[p]=='Q')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("1.Quinton De kock \n");
                            if((S[p]=='F')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("2.Faf du Plessis \n");
                            if((S[p]=='A')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("3.AB Diviliers \n");
                            if((S[p]=='J')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("4.JP Duminy \n");
                            if((S[p]=='C')&&((S[p]!=US[0])&&(S[p]!=US[1])&&(S[p]!=US[2])&&(S[p]!=US[3])&&(S[p]!=US[4])))
                                printf("5.Chris Morris \n");
                        }
                            printf("Choose %d player \t",i+1);
                            scanf("%d",&player);
                            US[i]=S[player-1];
                            printf("\nYour %d player is \t",i+1);
                            team_South_Africa_player(player);
                }
            }
        }                       //end of else block of x i.e., innings 2
        }
char PT2[5];
char CreaseTeam2[2];
int PTi2=0,PTj2=1;
 wicket=0;
if(result==3)
{
    if(x==1)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UI[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];

    }
    else if(x==2)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UP[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];
    }
    else if(x==3)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UA[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];

    }
    else if(x==4)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UE[i];                                //PT means playing team
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];

    }
    else if(x==5)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=US[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];

    }
}
else
{
    if(y==1)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UI[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];

    }
    else if(y==2)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UP[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];
    }
    else if(y==3)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UA[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];
    }
    else if(y==4)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=UE[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];

    }
    else if(y==5)
    {
        for(i=0;i<5;i++)
        {
        PT2[i]=US[i];
        }
        CreaseTeam2[0]=PT2[PTi2];
        CreaseTeam2[1]=PT2[PTj2];
    }
}

printf("\n\n\t\tSecond playing team according to sequence is\n");

    for(i=0;i<5;i++)
    {
        printf("\t%c\t",PT2[i]);
    }

int t12[18],t22[18],t32[18],t42[18],t52[18];
int run_lb2=0,run_ub2=7,run2,k2=0,l2=0,j2=1,m2=0,n2=0,o2=0;
char temp2;
int li2=1;
char batsman2=CreaseTeam2[0];
printf("\nPlaying DUO is now %c & %c",CreaseTeam2[0],CreaseTeam2[1]);
for(li2=1;li2<=5;li2++)
{
    for(j2=1;j2<=6;j2++)
    {
        if(wicket<4){
        printf("\n\nOver %d\tBall %d\n",li2,j2);
        printf("Play your turn \t");
        if(t==0)
            player_choose(y,batsman2);
            else
                player_choose(x,batsman2);

        printf("Press any key to score\n");
        getch();
        run2=randInt(min,max)%8;
        if(run2!=7){
            printf("You scored %d run\t\n",run2);
            if(batsman2==PT2[0])
            {
            t12[k2]=run2;
            k2++;
            }
            if(batsman2==PT2[1])
            {
            t22[l2]=run2;
            l2++;
            }
            if(batsman2==PT2[2])
            {
            t32[m2]=run2;
            m2++;
            }
            if(batsman2==PT2[3])
            {
            t42[n2]=run2;
            n2++;
            }
            if(batsman2==PT2[4])
            {
            t52[o2]=run2;
            o2++;
            }
            total=total+run2;
        }
        if(total>target)
        {
            break;
        }


            if((run2==1)||(run2==3)||(run2==5))
            {
            if(batsman2==CreaseTeam2[0])
           batsman2=CreaseTeam2[1];
           else
            batsman2=CreaseTeam2[0];
            }

        if(run2==7)
        {   ++wicket;
            printf("\nThat's a OUT!!!!\n");

          if(batsman2==CreaseTeam2[0])
           {
            temp2=PT2[++PTj2];
            if(wicket<4){
            CreaseTeam2[0]=temp2;
            batsman2=CreaseTeam2[0];
            printf("\nPlaying DUO is now %c & %c",CreaseTeam2[0],CreaseTeam2[1]);}
           }
           else
           {
               if(wicket<4){
           temp2=PT2[++PTj2];
            CreaseTeam2[1]=temp2;
            batsman2=CreaseTeam2[1];
            printf("\nPlaying DUO is now %c & %c",CreaseTeam2[0],CreaseTeam2[1]);
               }
           }
        }


        if(total>target)
            break;
        }

        else
        {
            printf("Team is ALL OUT\n");
            goto jump;
            break; //jump statement
        }
    }
}
jump: // label is jump

printf("\n\n\t\t\tMATCH OVER!!!!!");
int sum12=0,sum22=0,sum32=0,sum42=0,sum52=0;
for(i=0;i<k2;i++)
{
    sum12=sum12+t12[i];
}

for(i=0;i<l2;i++)
{
    sum22=sum22+t22[i];
}

for(i=0;i<m2;i++)
{
    sum32=sum32+t32[i];
}
for(i=0;i<n2;i++)
{
    sum42=sum42+t42[i];
}

for(i=0;i<o2;i++)
{
    sum52=sum52+t52[i];
}

printf("\nRuns ---> %c ---> %d\t",PT2[0],sum12);
store(ls,PT2[0],sum12);
printf("\nRuns ---> %c ---> %d\t",PT2[1],sum22);
store(ls,PT2[1],sum22);
printf("\nRuns ---> %c ---> %d\t",PT2[2],sum32);
store(ls,PT2[2],sum32);
printf("\nRuns ---> %c ---> %d\t",PT2[3],sum42);
store(ls,PT2[3],sum42);
printf("\nRuns ---> %c ---> %d\t",PT2[4],sum52);
store(ls,PT2[4],sum52);

if(total<target)
{
    printf("\n\n\t\t\t!!!YOU WON THE MATCH!!!\n\t\t\t\t by %d runs\n\n\n\n",target-total);
    fprintf(fptr, "\t %s Team Won the Match by %d \n",team1,target-total);
}
else
{
         printf("\nTotal=%d\n",total);
        printf("\n\n\t\t\tALAS!!!!You Lost The Match........\n\n\n\n\n");
        fprintf(fptr, "\t %s Team lost the Match  \n",team1);
}
}
fclose(fptr);

    }
    }
                               //end of playmatch()






void scoreboard()
{
    char ch;
fptr = fopen("C://file//emp.txt","r+");
 while ((ch = getc(fptr)) != EOF)
        {
            printf("%c", ch);
        }
}
//code Efficiency modules
void team_x()                               //under the toss function to display the name of team 0
{
        int x=Playingteam[0];

            if(x==1)
                printf("India \n");
            if(x==2)
                printf("Pakistan \n");
            if(x==3)
                printf("Australia \n");
            if(x==4)
                printf("England \n");
            if(x==5)
                printf("South_Africa\n");

}
void team_y()                               //under the toss function to display the name of team 1
{

int y=Playingteam[1];

            if(y==1)
                printf("India \n");
            if(y==2)
                printf("Pakistan \n");
            if(y==3)
                printf("Australia \n");
            if(y==4)
                printf("England \n");
            if(y==5)
                printf("South_Africa\n");

}
void team_opt(int opt)              //function call from team choose
{
    if(opt==1)
                printf("India \n");
            if(opt==2)
                printf("Pakistan \n");
            if(opt==3)
                printf("Australia \n");
            if(opt==4)
                printf("England \n");
            if(opt==5)
                printf("South_Africa\n");
}

void team_india_player(int player)
{
    if (player==1)
        printf("M.S. Dhoni \n");
    if (player==2)
        printf("2 Virat Kohli \n");
    if (player==3)
        printf("Rohit Sharma\n");
    if (player==4)
        printf("Shikhar Dhavan \n");
    if (player==5)
        printf("Yuvraj singh\n");
}
void team_pakistan_player(int player)
{
 if (player==1)
        printf("Babar Azam\n");
    if (player==2)
        printf("Sarfaraz khan \n");
    if (player==3)
        printf("Fakhar zamaan\n");
    if (player==4)
        printf("Md. Hafeez\n");
    if (player==5)
        printf("Wahab Riyaz\n");
}
void team_Australia_player(int player)
{
 if (player==1)
        printf("Steve Smith\n");
    if (player==2)
        printf("David Miller\n");
    if (player==3)
        printf("Aaron Finch\n");
    if (player==4)
        printf("Glenn Maxwell\n");
    if (player==5)
        printf("Moeen Ali\n");

}
void team_England_player(int player)
{
 if (player==1)
        printf("Ben Stokes\n");
    if (player==2)
        printf("Joe Root\n");
    if (player==3)
        printf("Eon Morgan\n");
    if (player==4)
        printf("Adil Rashid\n");
    if (player==5)
        printf("Mitchel Starc\n");

}
void team_South_Africa_player(int player)
{
    if (player==1)
        printf("Quinton De Kock\n");
    if (player==2)
        printf("Faf du plessis \n");
    if (player==3)
        printf("AB Divilers\n");
    if (player==4)
        printf("JP Duminy\n");
    if (player==5)
        printf("Chris Morris\n");
}
void player_choose(int z,char batsman)
{

    if(z==1)
        {
            if(batsman==I[0])
                printf("M.S. Dhoni\n");
           if(batsman==I[1])
                 printf("Virat Kohli\n");
            if(batsman==I[2])
                printf("Rohit Sharma\n");
             if(batsman==I[3])
                printf("Shikhar Dhavan\n");
             if(batsman==I[4])
                printf("Yuvraj Singh\n");
            }
    if(z==2)
        {
            if(batsman==P[0])
                printf("Babar Azam\n");
            if(batsman==P[1])
                printf("Sarfaraz khan\n");
            if(batsman==P[2])
                printf("Fakhar zamaan\n");
            if(batsman==P[3])
                printf("Md. Hafeez\n");
            if(batsman==P[4])
                printf("Wahab Riyaz\n");

        }
if(z==3)
        {

            if(batsman==A[0])
                printf("Steve Smith\n");
            if(batsman==A[1])
                printf("David Miller\n");
            if(batsman==A[2])
                printf("Aaron Finch\n");
            if(batsman==A[3])
                printf("Glenn Maxwell\n");
            if(batsman==A[4])
                printf("Moeen Ali\n");
            }

if(z==4)
        {
            if(batsman==E[0])
                printf("Ben Stokes\n");
            if(batsman==E[1])
                printf("Joe Root\n");
            if(batsman==E[2])
                printf("Eon Morgan\n");
            if(batsman==E[3])
                printf("Adil Rashid\n");
            if(batsman==E[4])
                printf("Mitchel Starc\n");

        }
if(z==5)
        {
            if(batsman==S[0])
                printf("Quinton De Kock\n");
            if(batsman==S[1])
                printf("Faf du plessis \n");
            if(batsman==S[2])
                printf("AB Divilers\n");
            if(batsman==S[3])
                printf("JP Duminy\n");
            if(batsman==S[4])
                printf("Chris Morris\n");
        }
}

void store(int x,char p,int score)
{

        if (fptr == NULL)
        {
            printf("File does not exists \n");
            return;
        }
    if(x==1)
        {
            if(p==I[0])
            {
                fprintf(fptr, "M.S. Dhoni \t %d \n",score);
            }
           if(p==I[1])
            {
                 fprintf(fptr, "Virat Kohli \t %d \n",score);
            }
            if(p==I[2])
            {
                fprintf(fptr, "Rohit Sharma \t %d \n",score);
            }
             if(p==I[3])
            {
                fprintf(fptr, "Shikhar Dhavan \t %d \n",score);
            }
            if(p==I[4])
            {
                fprintf(fptr, "Yuvraj Singh \t %d \n",score);
            }
            //fclose(fptr);
        }

    if(x==2)
        {


            if(p==P[0])
                fprintf(fptr, "Babar Azam \t %d \n",score);
            if(p==P[1])
                fprintf(fptr, "Sarfaraz khan \t %d \n",score);
            if(p==P[2])
                fprintf(fptr, "Fakhar zamaan \t %d \n",score);
            if(p==P[3])
                fprintf(fptr, "Md. Hafeez \t %d \n",score);
            if(p==P[4])
                fprintf(fptr, "Wahab Riyaz \t %d \n",score);

        }
if(x==3)
        {

            if(p==A[0])
                fprintf(fptr, "Steve Smith \t %d \n",score);
            if(p==A[1])
                fprintf(fptr, "David Miller \t %d \n",score);
            if(p==A[2])
                fprintf(fptr, "Aaron Finch \t %d \n",score);
            if(p==A[3])
                fprintf(fptr, "Glenn Maxwell \t %d \n",score);
            if(p==A[4])
                fprintf(fptr, "Moeen Ali \t %d \n",score);
            }

if(x==4)
        {
            if(p==E[0])
                fprintf(fptr, "Ben Stokes \t %d \n",score);
            if(p==E[1])
                fprintf(fptr, "Joe Root \t %d \n",score);
            if(p==E[2])
                fprintf(fptr, "Eon Morgan \t %d \n",score);
            if(p==E[3])
                fprintf(fptr, "Adil Rashid \t %d \n",score);
            if(p==E[4])
                fprintf(fptr, "Mitchel Starc \t %d \n",score);

        }
if(x==5)
        {

            if(p==S[0])
                fprintf(fptr, "Quinton De Kock \t %d \n",score);
            if(p==S[1])
                fprintf(fptr, "Faf du plessis \t %d \n",score);
            if(p==S[2])
                fprintf(fptr, "AB Divilers \t %d \n",score);
            if(p==S[3])
                fprintf(fptr, "JP Duminy \t %d \n",score);
            if(p==S[4])
                fprintf(fptr, "Chris Morris \t %d \n",score);

        }
}
int randInt(int a,int b)
{
    srand(time(NULL));
    int randValue;
    randValue=1+(int)rand()%(b-a+1);
    return randValue;
}
