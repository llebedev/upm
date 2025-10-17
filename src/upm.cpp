#include "utils.hpp"
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "upm.hpp"
#include "fileutils.hpp"

Operation currentOperation;

std::unordered_map<std::string, Operation> arguments = {
    {"install",INSTALL },
    {"remove", REMOVE},
    {"list", LIST}
};

void help(int code) {
    if(code==1)  printf("Few arguments not found. Please try upm -h for more information. Using: upm <action> <...>\n");
    else {

    }
}

bool checkArguments(int argc, char* argv[]) {
    for(int i = 1;i < argc;i++) {
        auto arg = arguments.find(argv[i]);
        if(arg != arguments.end()) {
            currentOperation = arg->second;
            return 1;
        }
    }
    return 0;
}

int main(int argc, char* argv[]) {
    if(!checkRoot()) return 0;

    if(argc<2) help(1);
    else if(checkArguments(argc, argv)) {
        checkDirectories();
    } else help(0);
}
