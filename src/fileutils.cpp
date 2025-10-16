#include "fileutils.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>

std::vector<char*> directories = {
    "/store/",
    "/store/deb",
    "/store/nix",
    "/store/arch",
    "/store/dfn"
};

void createFile(char *name) {

}
void unpackFile() {

}

void createDirectories(char* path) {
    std::filesystem::create_directory(path);
}

void checkDirectories() {
    for(int i = 0;i<directories.size();i++) {
        if(!std::filesystem::exists(directories[i])) {
            createDirectories(directories[i]);
            std::cout<<"Created dir: "<<directories[i]<<std::endl;
        }
    }
}
