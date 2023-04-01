#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void red()
{
 printf("\033[1;31m");

}
void reset()
{
 printf("\033[0m");

}
void green()
{
 printf("\033[1;32m");

}
static char name[10];
static int move=400; //maximum move
// when Arrow keys will press these Function will call
void result(int a[4][4])
{
 int count=1,win=0;
 char play;
     for(int i=0;i<4;i++){
      for(int j=0;j<4;j++){
       if(count==a[i][j])
       win++;
      count++;
      }
    }

   if(win==15)
   {
     system("cls");
     green();
     printf("\n          YOU WIN !");
     reset();
     printf("\nYou completed the game in : %d moves",400-move);
      printf("\n\nwant to play again ?\nPress Enter to play again or Exit press 'e'\n");
     play=getch();
          if(play=='e')
   exit(0);
   else {
     system("cls");
     move=400;
     RandomNumber_generator(a);
     board_printer(a);
     cursor_position(a);
       }
   }
   else
   if(move==0)
   {
    {
     system("cls");
     red();
     printf("\n          YOU LOSE !");
     reset();
      printf("\n\nwant to play again ?\nPress Enter to play again or Exit press 'e'\n");
      play=getch();
   }
     if(play=='e')
   exit(0);
   else {
     system("cls");
     move=400;
     RandomNumber_generator(a);
     board_printer(a);
     cursor_position(a);
       }
   }
}
void up(int a[4][4])
{
  for(int i=0;i<=3;i++){
   for(int j=0;j<=3;j++)
   {
    if(a[i][j]==0){
    if(i<=2&&j<=3)
    {
     a[i][j]=a[i+1][j];
    a[i+1][j]=0;
    system("cls");
    move--;
    board_printer(a,move);
    return 0;
     }

    }

   }
  }


}
void down(int a[4][4])
{
 for(int i=0;i<=3;i++){
   for(int j=0;j<=3;j++)
   {
    if(a[i][j]==0){
    if((i<=3&&j<=3)&&(i>=1&&j>=0))
    {
     a[i][j]=a[i-1][j];
    a[i-1][j]=0;
    system("cls");
    move--;
    board_printer(a,move);
     return 0;
     }
    }

   }
  }
}
void left(int a[4][4])
{

  for(int i=0;i<=3;i++){
   for(int j=0;j<=3;j++)
   {
    if(a[i][j]==0){
    if((i<=3&&j<=2&&i>=3&&j>=0)||(i<=2&&j<=2&&i>=2&&j>=0)||(i<=1&&j<=2&&i>=1&&j>=0)||(i<=0&&j<=2&&i>=0&&j>=0))
    {
     a[i][j]=a[i][j+1];
    a[i][j+1]=0;
    system("cls");
    move--;
    board_printer(a,move);
     return 0;
     }
    }

   }
  }
}
void right(int a[4][4])
{
  for(int i=0;i<=3;i++){
   for(int j=0;j<=3;j++)
   {
    if(a[i][j]==0){
    if((i<=3&&j<=3&&i>=3&&j>=1)||(i<=2&&j<=3&&i>=2&&j>=1)||(i<=1&&j<=3&&i>=1&&j>=1)||(i<=0&&j<=3&&i>=0&&j>=1))
    {
     a[i][j]=a[i][j-1];
    a[i][j-1]=0;
    system("cls");
    move--;
    board_printer(a,move);
     return 0;
     }
    }

   }
  }
}
 void cursor_position(int a[4][4])
 { char c;

     while(1)
    {
          c=getch();
         switch(c)
       {
// We don't have Ascii code of Arrow Keys so here we have to use Scan codes of Arrow Keys more as like Ascii code.
          case 75:
          left(a);
           result(a);
           break;

          case 77:
          right(a);
           result(a);
           break;

          case 72:
          up(a);
          result(a);
          break;

          case 80:
          down(a);
           result(a);
          break;

     }
   }
 }

// random number generator function use to generate random number from 1 to 15 and assign number non sequencely and non repetitive manner
void RandomNumber_generator(int a[4][4])
{

int temp,min=1,max=15,i,j,a1[15],l=0;
srand(time());
// time function is use to return seconds because time is always different and it is fit for random number
// srand function is use to provide seed value (Initial value)
// rand function is use to generate random number.
   for(i=0;i<15;i++)
    {
     temp=(rand()%(max-min+1))+min;

      for(j=0;j<=i-1;j++)
      {
       if(temp==a1[j])
        break;
      }

     if(i==j)
      a1[i]=temp;
     else
      i--;
     }


   for(i=0;i<4;i++){
   for(j=0;j<4;j++){
   if(i==3&&j==3){
    a[3][3]=0;
    break;
    }
    a[i][j]=a1[l];
    l++;

    }
   }
}

void board_printer(int a[4][4])// Use to print playing board
{
   printf("\n   Player Name: %s    ,  Move Remaining : %d\n\n",name,move);
    printf("Note- Enter Space if you don't want to move further\n");
printf("---------------------\n");

   for(int i=0;i<4;i++){
for(int j=0;j<4;j++){
if(a[i][j]==0)
{
 printf("|%2c |\b ",32);

}else

  if(a[i][j]<10)
 printf("|%2d |\b ",a[i][j]);
else
 printf("|%d |\b ",a[i][j]);
}
 printf("|");
 printf("\n");
   }

printf("---------------------\n");


}
// ------------------Main function--------------
int main()
{int a[4][4]={0};
char c;
//            Game rules........
printf("\n        Welcome's to you in Number shifting game\n");
printf("\n                      Enter name\n");
gets(name);
system("cls");


 while(1)
 {
printf("                      MATRIX PUZZLE\n\n");
printf("                    RULE OF THIS GAME\n\n");
red();
 printf("1.You can move only 1 step at a time by arrow key\nMove Up     : by Up arrow Key\nMove Down   : by Down arrow Key");
printf("\nMove Left   : by Left arrow Key\nMove Right  : by Right arrow Key");
reset();
printf("\n\n2.You can move number at empty position only");
printf("\n3.For each valid move : your total number of move will decreased by 1");
printf("\n4.Winning situation : number in a 4*4 matrix should be in order from 1 to 15\n\n");
green();
printf("               winning situation:\n-----------------\n");
printf("| 1 | 2 | 3 | 4 |\n");
printf("| 5 | 6 | 7 | 8 |\n");
printf("| 9 | 10| 11| 12|\n");
printf("| 13| 14| 15|   |\n");
printf("-----------------\n");
reset();
printf("5.You can exit the game at any time by pressing 'E' or 'e' key.\n");
printf("6.If you want to Exit in between game press 'space' key.\n");
printf("So Try to win in minimum no of move.\n\n");
printf("               Happy gaming , Good Luck\n\n");
printf("Enter any key to start.............\n");

fflush(stdin);
c=getch();
if(c=='e'||c=='E')
 {
return 0;
 }
system("cls");
RandomNumber_generator(a);
board_printer(a);
cursor_position(a);

 }

}

