#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H
#include <iostream>
#include <vector>
#include "Markup.h"
#include <cstdlib>
#include <string>
#include <sys/stat.h>
#include <unistd.h>

#include "User.h"

using namespace std;

class FileWithUsers
{
    string FileName;

    bool isFileEmpty();

public:
    FileWithUsers(){};
   void addUsersToFile(User user);
   vector<User> loadUsersFromFile();

};


#endif
