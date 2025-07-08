#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char position[11], p1[50], p2[50];
int t=1, n=-1, l=0, u=0;

void interface();
int start_game();
int Win_or_not();
void red ();
void green();
void blue();
void yellow();
void purple();
void reset ();

int main() {
    int player = 1, i=-1, input;
	char mark;
	position[1] = '1';
	position[2] = '2';
	position[3] = '3';
	position[4] = '4';
	position[5] = '5';
	position[6] = '6';
	position[7] = '7';
	position[8] = '8';
	position[9] = '9';

    int oo;
	if(u==0) oo=start_game();
	u++;
    if(oo==-1) {
        printf("\n\n\t\t****************\n");
        printf("\t\t***Thank You.***\n");
        printf("\t\t****************\n");
        return 0;
    }
    ///name input
	if(n==2 || n==-1) {
        printf("\nEnter the name of Player 1: ");
        scanf("%*c%[^\n]", &p1);
        printf("\n");
        printf("Enter the name of Player 2: ");
        scanf("%*c%[^\n]", &p2);
        printf("\n");
	}
    ///PLayers input
	while(i == -1) {
		interface();
		if(player%2!=0) player=1;
		else player=2;
		if(player==1) printf("\n\t%s, enter the choice : ",p1);
		else printf("\n\t%s, enter the choice : ",p2);
		scanf("%d",&input);
		mark='O';
		if(player==1) mark='X';
		if(input == 1 && position[1] == '1')
			position[1] = mark;
		else if(input == 2 && position[2] == '2')
			position[2] = mark;
        else if(input == 3 && position[3] == '3')
			position[3] = mark;
        else if(input == 4 && position[4] == '4')
			position[4] = mark;
        else if(input == 5 && position[5] == '5')
			position[5] = mark;
        else if(input == 6 && position[6] == '6')
			position[6] = mark;
        else if(input == 7 && position[7] == '7')
			position[7] = mark;
        else if(input == 8 && position[8] == '8')
			position[8] = mark;
			else if(input == 9 && position[9] == '9')
        position[9] = mark;
        else {
            red();
            printf("\n\t***Invalid option!!!***\n");
            reset();
            printf("Press Enter Key to enter your choice again.");
            player--;
            getch();
        }
			i = Win_or_not();
			player++;
	}

	interface();
	if(i==1){
        player--;
        ///Result printing
        green();
		if(player==1) printf("\n\n\t\tResult:- %s Won The Match\n\n",p1);
		else printf("\n\n\t\tResult:- %s Won The Match\n\n",p2);
		reset();
		///wining Line
		yellow();
		printf("\t\tWinning Line : ");
		reset();
		blue();
        if(l>=1 && l<=3) printf("Row %d\n", l);
        else if(l>=4 && l<=6) printf("Column %d\n", l-3);
        else if(l==7) printf("Main Diagonal\n");
        else if(l==8) printf("Minor Diagonal\n");
        reset();
        l=0;
	}
	else {
		///draw
		printf("\n\n\t\tResult:- Game draw\n");
	}
	///Saving option
    int st;
    while(1) {
        printf("\n\n\t\tWant To Save The Game Result? For Yes(1) - No(0): ");
        scanf("%d", &st);
        if(st==1) {
            ///file write
            FILE *result=fopen("Result.txt", "a");
            if(i==1) {
                if(player==1)fprintf(result, "%s %s %s\n", p1, p2, p1);
                else fprintf(result, "%s %s %s\n", p1, p2, p2);
            }
            else fprintf(result, "%s %s Draw\n", p1, p2);

            fclose(result);
            printf("\n\t\tPlease wait While Saving!");
            printf("\n\t\t\tSaving");
            for(i=0; i<=3; i++) {
                printf(". ");
                Sleep(500);
            }
            printf("\n");
            green();
            printf("\n\t\tThe Result Saved Successfully!!!");
            reset();
            break;
        }
        else if(st==0){
            yellow();
            printf("\n\t\tThe Result Not Saved!!!");
            reset();
            break;
        }
        else {
            red();
            printf("\n\t\tEnter '0' or '1'\n");
            reset();
        }
	}
    ///play again and restart option
	while(1) {
        printf("\n\n\t\tWant To Play Again or Restart? For Yes(1) - No(0) - Restart(2): ");
        scanf("%d", &n);
        if(n==1) {
            main();
            break;
        }
        else if(n==0){
            purple();
            printf("\n\n\t\t*************************\n");
            printf("\t\t***Thanks For Playing.***\n");
            printf("\t\t*************************\n");
            reset();
            break;
        }
        else if(n==2) {
            printf("\n");
            main();
            break;
        }
        else {
            red();
            printf("\n\t\tEnter '0' or '1'");
            reset();
        }
	}
    return 0;
}
///start interface (main menu)
int start_game() {
    int start, i;
	while(1) {
        printf("\t\tTic Tac Toe Game\n\n");
        printf("\t\t   Start Game(1)\n\n\t\tSee Statistics(2)\n\n\t\t    Exit(0)\n");
        while(1) {
            printf("\nEnter Your Choice: ");
            scanf("%d", &start);
            if(start==1 || start==2 || start==0) break;
            else {
                printf("\n\t\tEnter '1' or '2' or '0'\n");
            }
        }

        if(start==0) {
            return -1;
            break;
        }
        else if(start==1) {
            printf("\n\t\tLoading");
            for(i=0; i<=3; i++) {
                printf(". ");
                Sleep(500);
            }
            printf("\n");
            return;
        }
        else if(start==2) {
            ///file read

            while(1) {
                FILE *result=fopen("Result.txt", "r");
                char name1[50], name2[50], status[50], check[50];
                printf("\nEnter The Player Name For Statistics: ");
                scanf("%s", &check);
                int winm=0, totalm=0;
                float per;
                while(fscanf(result, "%s %s %s", &name1, &name2, &status)!=EOF) {
                    if(strcmpi(check,name1)==0 || strcmpi(check,name2)==0) {
                        if(strcmpi(status,check)==0) winm++;
                        totalm++;
                    }
                }
                ///statistics print
                if(totalm==0) {
                    printf("No Data Found!\n");
                }
                else {
                    per=((float)winm/totalm)*100;
                    printf("Total Played Games: %d\n", totalm);
                    printf("Total Winning Games: %d\n", winm);
                    printf("Winning Rate: %.2f%%\n", per);
                }
                ///statistic check again option
                int tt=0;
                printf("\t\tWant to check another player statistics? YES(1) || NO(0)\n\n\t\tEnter your choice: ");
                scanf("%d", &tt);
                if(tt==1) continue;
                else if(tt==0) {
                    printf("\n\n");
                    break;
                }
                else {
                    printf("\n\t\tEnter '0' or '1'\n");
                }
                fclose(result);
            }

        }

	}
}
///game interface
void interface(){
	system("cls");
	///whole interface coloring (status- off)
	//if(t%2!=0) red ();
	//else yellow();
	//t++;
	printf("\n\n\t\t Tic Tac Toe \n\n");
	printf("\t     %s (X) - %s (O) \n\n\n", p1, p2);
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n", position[1], position[2], position[3]);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n", position[4], position[5], position[6]);
	printf("\t\t_____|_____|_____\n");
	printf("\t\t     |     |     \n");
	printf("\t\t  %c  |  %c  |  %c  \n", position[7], position[8], position[9]);
	printf("\t\t     |     |     \n");
}
///winning condition checking
int Win_or_not(){
	if(position[1] == position[2] && position[2] == position[3]) {
        l=1;
        return 1;
	}
	else if (position[4] == position[5] && position[5] == position[6]) {
        l=2;
        return 1;
	}
	else if(position[7] == position[8] && position[8] == position[9]) {
        l=3;
        return 1;
	}
	else if(position[1] == position[4] && position[4] == position[7]) {
        l=4;
        return 1;
	}
	else if(position[2] == position[5] && position[5] == position[8]) {
        l=5;
        return 1;
	}
	else if(position[3] == position[6] && position[6] == position[9]) {
        l=6;
        return 1;
	}
	else if(position[1] == position[5] && position[5] == position[9]) {
        l=7;
        return 1;
	}
	else if(position[3] == position[5] && position[5] == position[7]) {
        l=8;
        return 1;
	}
	else if(position[1] != '1' && position[2] != '2' && position[3] != '3' && position[4] !='4' && position[5] != '5' && position[6] != '6' && position[7] != '7' && position[8] != '8' && position[9] != '9')
		return 0;
	else
		return -1;
}

void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[1;32m");
}

void blue () {
  printf("\033[1;34m");
}

void yellow () {
  printf("\033[1;33m");
}

void purple () {
  printf("\033[1;35m");
}

void reset () {
  printf("\033[0m");
}
