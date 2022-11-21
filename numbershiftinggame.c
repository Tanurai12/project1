#include<stdio.h>
#include<conio.h>
#include<stdlib.h>//for.........sys(cls).and.........random number generation
#include<time.h>//for  srand--->seed value

int readkey()
    {
       char c;
       c = getch();
       return c;
    }
void showmatrix(int a[][4])
{
  int i,j;
 printf("---------------------\n");
      for( i=0;i<4;i++)
          {
            printf("|");
      
          for(j=0;j<4;j++)
          {
            if(a[i][j]!=0)
            printf("%3d |", a[i][j]);
            else
            printf("    |");
          }
          printf("\n");
          }
          printf("---------------------\n");
    }
 int winner(int a[][4])
{
    int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
            if (a[i][j] != k && k != 16)
                break;
        if (j < 4)
            break;
    }

    if (j < 4)
        return 0;
    return 1;
}


void swap(int *a,int *b)
{
  *a=*a+*b;
  *b=*a-*b;
  *a=*a-*b;
  
}

     void rule()
     {
       system("cls");
    printf("\n \t   RULE OF THIS GAME \n");
    printf(" 1. You can move only 1 step at a time by arrow key \n");
    printf("Move up    :  by up arrow key \n");
    printf("Move down  :  by down arrow key \n");
    printf("Move left  :  by left  arrow key \n");
    printf("Move right : by right arrow key \n");
    printf("2. You can move number at empty position only \n \n");
    printf(" 3.for each valid move : your total number of move will decreased by 1 \n");
    printf("4. winning situation : number in a 4*4 matrix should be inorder from 1 to 15 \n \n ");
    printf("\t winning situation \n");
    printf("-----------------------\n");
    printf("| 1  | 2  | 3  |  4   |  \n");
    printf("| 5  | 6  | 7  |  8   |  \n");
    printf("| 9  | 10 | 11 |  12  | \n");
    printf("| 13 | 14 | 15 |      |  \n");
    printf("-----------------------\n");
    printf(" You can exit the game in any time by pressing 'E' or 'e' so try to win in minimum number of move\n");
    printf("\t \t Happy gaming, Good luck \n\n");
    printf("enter any key to start........\n") ;
    }

    void creatematrix(int a[][4])
    {
      int i,j,n=15,index,num[n],lastindex=n-1;
        for(int i=0;i<=n;i++)
         num[i]=i+1;
 
        srand(time(NULL));
        for( i=0;i<4;i++)
    {
          for(j=0;j<4;j++)
          {
            if(lastindex>=0)
            {
             index=rand()%(lastindex+1);
             a[i][j]=num[index];
             num[index]=num[lastindex--];
          }
        
        }
    }

     a[i-1][j-1]=0; 
    }
    
int shiftup(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 3) // shifting not possible
        return 0;

    // Successfully swapped two numbers !
    swap(&arr[i][j], &arr[i + 1][j]);
    return 1; // Success
}

int shiftdown(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 0) // shifting not possible
        return 0;
    swap(&arr[i][j], &arr[i - 1][j]); // swap numbers

    return 1; // shift up success
}
   

 
  int shiftright(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j - 1]);

    return 1; // shift up success
}

int shiftleft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }

    if (j == 3) // shifting not possible
        return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1; // shift up success
}
  int main()
{
    int a[4][4],move=4;
    char name[30];
    printf("enter your name");
    gets(name);
    
    while(1)
    {
    rule();
    getch();
    creatematrix(a);

   
    while(!winner(a))
    {

         printf("hello %s, welcome in this game...,move remainig %d\n",name,move);
    showmatrix(a);

      if(!move)//for 0
      break;
    int key=readkey(); // this will return ascii code of user entered key

            switch (key)
            {
            case 101: // ascii of E

            case 69: // ascii of e
                printf("\a\a\a\a\a\a\n     Thanks for Playing ! \n\a");
                printf("\nHit 'Enter' to exit the game \n");
                key =readkey();
                return 0;

            case 72: // arrow up
                if (shiftup(a))
                    move--;
                break;
            case 80: // arrow down
                if (shiftdown(a))
                    move--;
                break;
            case 77: // arrow  right
                if (shiftright(a))
                    move--;
                break;
            case 75: // arrow left
                if (shiftleft(a))
                    move--;
                break;
            default:

                printf("enter a correct key...!");
            }
    }
    if(!move)
   printf("you lose \n");
   else
   printf("\a\a \n congrats...you won!!!\n");
    fflush(stdin);
    char a;
    printf("want to play again ?\n...enter y to play again\n ");
   scanf("%c",&a);
    if((a!='Y')&&(a!='y'))
    
    break;


    move=4;
    }     
    return 0;
}
