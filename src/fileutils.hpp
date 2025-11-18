#include <vector>
#include <thread>

#ifndef FILEUTILS_HPP
#define FILEUTILS_HPP

void createFile(char* path);
void unpackFile();

void createDirectories(char* path);
bool checkExist(char* path);
void checkDirectories();

#endif
