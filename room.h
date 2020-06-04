#ifndef __ROOM_H__
#define __ROOM_H__
#include <stdbool.h>
/*communication protocol: the pc sends command to the board by sending one char presenting the command type
 * followed by one char representing  followed by one char for room number
 * followed by four chars for the room password if the command is r (reserve)
 * commands are : 1) r (reserve room with specific password) (reserved)
 *                2) c (clean the room)
 *                3) l (lock the room after the guest checkout) (room became free) (not reserved)
 ex: "r51234" mean : (reserve) room (5) with password (1234)
 the locked unreserved room has default password (xxxx)
 */

struct room {
    //room status : 1) c for cleaning , 2) r for reserved  3)l for locked (not reserved)
    unsigned char status ;
    unsigned char roomIndex ;
    bool roomOpened ; //o room is closed & 1 for room opened
    char password [4] ;

//by default room status is l (locked & not reserved) , room index is 0 , password for not reserved is xxxx
}room_default = {'l','0',false,"xxxx"};








#endif
