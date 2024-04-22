#include "userinterface.h"
#include "stdlib.h"
#include <iostream>
#define NAME_MAX 255
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
            char dir_name[NAME_MAX];
            fgets(dir_name, NAME_MAX, stdin);
            //printf(dir_name);
            int er = sftp_s->sftp_create_dir(dir_name);
            if (er == 0){std::cout << "Complited Sucsessfuly!" << std::endl;}
            else{std::cout <<"!!!=======ERROR========!!!";}
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

void UserInterface::Greeting()
{   
    system("clear");
    system("figlet -c FULCRUM FILE HOSTING");
    /*std::cout <<"             _____      _                              __ _ _      "<< std::endl; 
    std::cout <<"            |  ___|   _| | ___ _ __ _   _ _ __ ___    / _(_) | ___ "<< std::endl;
    std::cout <<"            | |_ | | | | |/ __| '__| | | | '_ ` _ \\  | |_| | |/ _ \\"<< std::endl;
    std::cout <<"            |  _|| |_| | | (__| |  | |_| | | | | | | |  _| | |  __/"<< std::endl;
    std::cout <<"            |_|   \\__,_|_|\\___|_|   \\__,_|_| |_| |_| |_| |_|_|\\___|"<< std::endl;
    std::cout <<"                                                                   "<< std::endl;
    std::cout <<"                       _               _   _                       "<< std::endl;
    std::cout <<"                      | |__   ___  ___| |_(_)_ __   __ _           "<< std::endl;
    std::cout <<"                      | '_ \\ / _ \\/ __| __| | '_ \\ / _` |          "<< std::endl;
    std::cout <<"                      | | | | (_) \\__ \\ |_| | | | | (_| |          "<< std::endl;
    std::cout <<"                      |_| |_|\\___/|___/\\__|_|_| |_|\\__, |          "<< std::endl;
    std::cout <<"                                                   |___/           "<< std::endl;*/
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

