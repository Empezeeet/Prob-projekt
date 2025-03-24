#include "replace.h"


std::string replaceString(std::string str, char find, char replace) {
    for (char& c : str) {
        if (c == find) c = replace;
    }
    return str;
}