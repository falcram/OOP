#include <libssh/sftp.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fstream>
#include "SFTPservice.h"
#include <iostream>

sftp_service_manager::sftp_service_manager()
{
  ssh_start();
  sftp_start();
}

sftp_service_manager::~sftp_service_manager()
{
  sftp_free(sftp);
  ssh_disconnect(my_ssh_session);
  ssh_free(my_ssh_session);
}

int sftp_service_manager::sftp_create_dir(const char * dir_name)
{
  if (sftp==nullptr)
  {
    std::cout<<"===ERROR==NO_SFTP_SESSION==="<<std::endl;
    return SSH_ERROR;
  }
  
  int rc;
  rc = sftp_mkdir(sftp, dir_name, S_IRWXU);
  if (rc != SSH_OK)
  {
    if (sftp_get_error(sftp) != SSH_FX_FILE_ALREADY_EXISTS)
    {
      fprintf(stderr, "Can't create directory: %s\n",
              ssh_get_error(my_ssh_session));
        return rc;
    }
  }
  return SSH_OK;
}
 
int sftp_service_manager::ssh_start()
{
  int rc;
  char *password;
  // Open session and set options
  my_ssh_session = ssh_new();
  if (my_ssh_session == NULL)
  {
    return SSH_ERROR;
    //exit(-1);
  }
  //___________________________________________________________________________________________________________________
  //Set Connect options:
  //TODO: Make Special function to set options 
  ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "test_server@192.168.122.149");

  //___________________________________________________________________________________________________________________
  // Connect to server
  rc = ssh_connect(my_ssh_session);
  if (rc != SSH_OK)
  {
  fprintf(stderr, "Error connecting to localhost: %s\n",
  ssh_get_error(my_ssh_session));
  ssh_free(my_ssh_session);
  return SSH_ERROR;
  //exit(-1);
  }
  
  //___________________________________________________________________________________________________________________
  // Authenticate ourselves
  password = getpass("Password: ");
  rc = ssh_userauth_password(my_ssh_session, NULL, password);
  if (rc != SSH_AUTH_SUCCESS)
  {
  fprintf(stderr, "Error authenticating with password: %s\n",
  ssh_get_error(my_ssh_session));
  ssh_disconnect(my_ssh_session);

  ssh_free(my_ssh_session);
  return SSH_ERROR;
  //exit(-1);
  }
  //___________________________________________________________________________________________________________________
  return SSH_OK;
}

int sftp_service_manager::sftp_start()
{
  //sftp_session sftp;
  int rc;
 
  sftp = sftp_new(my_ssh_session);
  if (sftp == NULL)
  {
    fprintf(stderr, "Error allocating SFTP session: %s\n",
            ssh_get_error(my_ssh_session));
    return SSH_ERROR;
  }
 
  rc = sftp_init(sftp);
  if (rc != SSH_OK)
  {
    fprintf(stderr, "Error initializing SFTP session: code %d.\n",
            sftp_get_error(sftp));
    sftp_free(sftp);
    return rc;
  }
 
  //sftp_helloworld(sftp);
  //sftp_free(sftp);
  return SSH_OK;
}