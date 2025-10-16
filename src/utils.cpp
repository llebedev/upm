#include "utils.hpp"
#include <cerrno>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <asm-generic/errno-base.h>
#include <unistd.h>


bool checkRoot() {
    if(getuid() != 0) {
        std::cout<<"Error code "<<EPERM<<"("<<strerror(EPERM)<<")"<<std::endl;
        std::cout<<"Please, run UPM with superadmin permission"<<std::endl;
        return false;
    }
    return true;
}
