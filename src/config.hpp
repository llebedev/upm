#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <libconfig.h>
#include <boost/spirit.hpp>

class Config{
public:
Config(char* path);
char* getPath() const {return path;}
private:
char* path;
};

#endif
