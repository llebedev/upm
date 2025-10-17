#include "fileutils.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>

std::vector<std::thread> threads;

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
    try {
        std::error_code ec;
        std::filesystem::create_directories(path, ec);

        if(ec) {
            std::cerr << "Error creating directory " << path
                      << ": " << ec.message() << std::endl;
        } else {
            std::cout << "Created dir: " << path << std::endl;
        }
    } catch(const std::exception& e) {
        std::cerr << "Exception to create directories: " << e.what() << std::endl;
    } catch(...) {
        std::cerr << "Unknown exception to create directories " << std::endl;
    }
}

void checkDirectories() {
    for(int i = 0;i<directories.size();i++) {
        if(!std::filesystem::exists(directories[i])) {
            threads.emplace_back(createDirectories, directories[i]);
        }
    }
    for(auto& thread: threads) {
        if(thread.joinable()) {
            thread.join();
        }
    }
}
