#ifndef __UARTORDERPROCESSING_H__
#define __UARTORDERPROCESSING_H__
#include "room.h"

/*void pcOrder_Processing (char * UART_CMD , struct room *r){
    //printf("%c\n",*UART_CMD);
    //point to second char "room number"
    char roomNumber = *(++UART_CMD);

    //printf("%c\n",roomNumber);
    //convert room number to int to be used in indexing the array of rooms
    int roomNumberI = roomNumber - '0';
    //point to first char "status type"
    UART_CMD--;
    //printf("%d\n",roomNumberI);
    int i;
    //printf("%c\n",*UART_CMD);
    //pc send i want to clean room "c"
    r[roomNumberI].roomIndex = roomNumber;
    if (*UART_CMD == 'c'){
        r[roomNumberI].roomOpened = true;
        r[roomNumberI].status = 'c';
    }
    //pc send i want to reserve room "r
    else if (*UART_CMD =='r'){
        r[roomNumberI].roomOpened = false;
        r[roomNumberI].status = 'r';
        //printf("%d",roomNumberI);
        //point to second element
        UART_CMD++;
        //storing the password starting from the third element
        for ( i =0 ; i<4 ; i++){

            r[roomNumberI].password[i]=*(++UART_CMD);
            //printf("%c\n",*(++UART_CMD));
        }
        *UART_CMD-=4;
    }
    //pc send i want to checkout room "locked room" "l"
    else if (*UART_CMD=='l'){
        r[roomNumberI].roomOpened = false;
        r[roomNumberI].status = 'l';
        r[roomNumberI].password[0] ='x';
			  r[roomNumberI].password[1] ='x';
			  r[roomNumberI].password[2] ='x';
			  r[roomNumberI].password[3] ='x';
    }
}*/

void pcOrder_Processing (char * UART_CMD ,struct room *r){
    //printf("%c\n",*UART_CMD);
    //point to second char "room number"
       while (1) {
        char roomNumber = *(++UART_CMD);

        //printf("%c\n",roomNumber);
        //convert room number to int to be used in indexing the array of rooms
        int roomNumberI = roomNumber - '0';
        //point to first char "status type"
        UART_CMD--;
        //printf("%d\n",roomNumberI);
        int i;
        //printf("%c\n",*UART_CMD);
        //pc send i want to clean room "c"
        r[roomNumberI].roomIndex = roomNumber;
        if (*UART_CMD == 'c') {
            UART_CMD++;
            r[roomNumberI].roomOpened = true;
            r[roomNumberI].status = 'c';
            UART_CMD++;
        }
            //pc send i want to reserve room "r
        else if (*UART_CMD == 'r') {
            r[roomNumberI].roomOpened = false;
            r[roomNumberI].status = 'r';
            //printf("%d",roomNumberI);
            //point to second element
            UART_CMD++;
            //storing the password starting from the third element
            for (i = 0; i < 4; i++) {

                r[roomNumberI].password[i] = *(++UART_CMD);
                //printf("%c\n",*(++UART_CMD));

            }
            UART_CMD++;
            //*UART_CMD -= 4;
        }
            //pc send i want to checkout room "locked room" "l"
        else if (*UART_CMD == 'l') {
            UART_CMD++;
            r[roomNumberI].roomOpened = false;
            r[roomNumberI].status = 'l';
            r[roomNumberI].password[0] = 'x';
					  r[roomNumberI].password[1] = 'x';
					  r[roomNumberI].password[2] = 'x';
					  r[roomNumberI].password[3] = 'x';
            UART_CMD++;
        }
        else
            break;
    }
}

void pcOrder_Processing_2 (char * UART_CMD , struct room *r){
      //loop tell the end of chars

       while (*UART_CMD != '\0' ) {


        //pc send i want to clean room "c"

        if (*UART_CMD == 'c' || *UART_CMD == 'C') {
            UART_CMD++;
            if (*UART_CMD !='\0'){
                char roomNumber = *UART_CMD;
                //convert char to int
                int roomNumberI = roomNumber - '0';
                //store data to room object
                r[roomNumberI].roomIndex = roomNumber;
                r[roomNumberI].roomOpened = true;
                r[roomNumberI].status = 'c';
                UART_CMD++;}
            else break;
        }
            //pc send i want to reserve room "r
        else if (*UART_CMD == 'r' || *UART_CMD == 'R') {
            UART_CMD++;
            if (*UART_CMD !='\0') {
                char roomNumber = *UART_CMD;
                //convert string to integer
                int roomNumberI = roomNumber - '0';
                //store data at room struct
                r[roomNumberI].roomIndex = roomNumber;
                r[roomNumberI].roomOpened = false;
                r[roomNumberI].status = 'r';
                unsigned int i;
                //store password
                for (i = 0; i < 4; i++) {

                    r[roomNumberI].password[i] = *(++UART_CMD);


                }
                UART_CMD++;
            } else break;

            }

        //pc send i want to checkout room "locked room" "l"
        else if (*UART_CMD == 'l'|| *UART_CMD == 'L') {
            UART_CMD++;
            if (*UART_CMD !='\0') {
                char roomNumber = *UART_CMD;
                int roomNumberI = roomNumber - '0';
                r[roomNumberI].roomIndex = roomNumber;
                r[roomNumberI].roomOpened = false;
                r[roomNumberI].status = 'l';
                r[roomNumberI].password[0] = 'x';
							  r[roomNumberI].password[1] = 'x';
							  r[roomNumberI].password[2] = 'x';
							  r[roomNumberI].password[3] = 'x';
                UART_CMD++;
            } else break;
        }
        else
            UART_CMD = UART_CMD+1;

    }
}








#endif
