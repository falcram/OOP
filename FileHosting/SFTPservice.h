#ifndef SFTPSERVICE_H
#define SFTPSERVICE_H

#pragma once
#include <string>
#include <vector>
#include <libssh/sftp.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fstream>

class sftp_service_manager
{
    private:
    
    ssh_session my_ssh_session;

    sftp_session sftp;

    int ssh_start();

    int sftp_start();

    public:

    sftp_service_manager();

    ~sftp_service_manager();
    
    int sftp_create_dir(const char * dir_name);

};

#endif // SFTPSERVICE_H