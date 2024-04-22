#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#pragma once
#include "SFTPservice.h"
#include <string>
#include <vector>
#include <iostream>

class UserInterface
{    
    private:
    sftp_service_manager *sftp_s;
    public:

    UserInterface()
    {
       Greeting();
       sftp_s = new sftp_service_manager();
    }

    
    void Greeting();
    void _mainConsole(); 

    void ShowFunctions();

    // _______________________ 

    std::string consolestring;

    std::vector<std::string> functionsList = {
        "Choose local file (or clf)",
        "Choose remote file (or crf) ",
        "Send file (or sf)",
        "Get File (or gf)",
        "List of directories and files on the server (or lsfs)",
        "Encrition/Decryption (or crypto)",
        "Create Dir (or ctdir)",
        "Rename Dir (or rndir)",
        "Remove Dir (or rmdir)",
        "Settings",
        "exit"
    };

    
};

#endif // USERINTERFACE_H