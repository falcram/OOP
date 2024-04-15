#include "userinterface.h"
#include <iostream>

void UserInterface::_mainConsole()
{
    std::cout << "# ___ | Enter \"Functions\" to see all functions | ___" << std::endl;
    while (true)
    {
        getline(std::cin, consolestring);
        
        if (consolestring == "Functions"){ShowFunctions();}
        else if( consolestring == "Choose local file" || consolestring == "clf")
        {
            /* code */
        }
        else if( consolestring == "Choose remote" || consolestring == "crf")
        {
            /* code */
        }
        else if( consolestring == "Send file" || consolestring == "sf")
        {
            /* code */
        }
        else if( consolestring == "Get File" || consolestring == "gf")
        {
            /* code */
        }
        else if( consolestring == "List of directories and files on the server" || consolestring == "lsfs")
        {
            /* code */
        }
        else if( consolestring == "Encrition/Decryption" || consolestring == "crypto")
        {
            /* code */
        }
        else if( consolestring == "Create Dir" || consolestring == "ctdir")
        {
            int er = sftp_s.create_ssh_session();
            if (er == 0)
            {
                std::cout << "Complited Sucsessfuly!" << std::endl;
            }
            else
            {
                std::cout <<"!!!=======ERROR========!!!";
            }
            

        }
        else if( consolestring == "Rename Dir" || consolestring == "rndir")
        {
            /* code */
        }
        else if( consolestring == "Remove Dir" || consolestring == "rmdir")
        {
            /* code */
        }
        else if( consolestring == "Settings")
        {
        
        }
        else if ( consolestring == "exit")
        {
            exit(0);
        }
        else{std::cout << "No such command" << std ::endl;}
    }
    
}

void UserInterface::ShowFunctions()
{
    int i = 1;
    for( std::string fun : functionsList)
    {
        std::cout << i << ") " << fun << std::endl;
        i++;
    }
}

