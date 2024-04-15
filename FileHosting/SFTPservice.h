#ifndef SFTPSERVICE_H
#define SFTPSERVICE_H

#pragma once
#include <string>
#include <vector>
#include <libssh/sftp.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fstream>

class sftp_service
{
    public:

    int create_ssh_session();

    int sftp_helloworld(ssh_session session, sftp_session sftp);

    int sftp_start(ssh_session session);

};

#endif // SFTPSERVICE_H