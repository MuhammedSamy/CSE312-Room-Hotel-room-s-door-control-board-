#ifndef __PWCHECKER_H__
#define __PWCHECKER_H__
#include <stdbool.h>
#include "room.h"

bool checkPassword (char *enteredPw,struct room r){
    if (enteredPw[0] != r.password[0] || enteredPw[1] != r.password[1] || enteredPw[2] != r.password[2] || enteredPw[3] != r.password[3])
        return false;
    else
        return true;
}















#endif
