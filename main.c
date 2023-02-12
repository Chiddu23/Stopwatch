#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int hour=0,minute=0,second=0,flag=0;

void delay(ms)
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock());
}
int counter(){
    while(!kbhit() && flag ==0){
            if(minute > 59){            //after minute is greater than 59, reset minute and increase 1 hour
                minute = 0;++hour;
            }
                if(second > 59){         //after second is greater than 59, reset second and increase 1 minute
                    second = 0;++minute;
                    }
                     printData();           //print out the new data, delay for 1000 millisecond and increase 1 second.
                    delay(1000);second += 1;
        }
        selection();
}

int printData(){
system("cls");
printf("1.Start  2.Stop  3.Reset  4. End\n");
printf("***********************************\n");
printf("            %d:%d:%d\n",hour,minute,second);
printf("***********************************\n");
}

int selection(){
    switch(getch()){
    case 49: flag =0; break;
    case 50: flag =1; break;
    case 51:
        hour = minute = second = 0;flag = 1;
        printData();
        break;
    case 52: exit(0);;break;
    }
}

int main()
{
    while(1){
    counter();
    }
}
