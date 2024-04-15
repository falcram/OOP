#include <libssh/sftp.h>
#include <sys/stat.h>
#include <stdio.h>
#include <fstream>
#include "SFTPservice.h"

int sftp_service::create_ssh_session()
{
  ssh_session my_ssh_session;
  int rc;
  char *password;
 
  // Open session and set options
  my_ssh_session = ssh_new();
  if (my_ssh_session == NULL)
    exit(-1);
  ssh_options_set(my_ssh_session, SSH_OPTIONS_HOST, "test_server@192.168.122.149");
 
  // Connect to server
  rc = ssh_connect(my_ssh_session);
  if (rc != SSH_OK)
  {
    fprintf(stderr, "Error connecting to localhost: %s\n",
            ssh_get_error(my_ssh_session));
    ssh_free(my_ssh_session);
    exit(-1);
  }
  
  
  // Verify the server's identity
  // For the source code of verify_knownhost(), check previous example
  /*if (verify_knownhost(my_ssh_session) < 0)
  {
    ssh_disconnect(my_ssh_session);
    ssh_free(my_ssh_session);
    exit(-1);
  }*/
 
  // Authenticate ourselves
  password = getpass("Password: ");
  rc = ssh_userauth_password(my_ssh_session, NULL, password);
  if (rc != SSH_AUTH_SUCCESS)
  {
    fprintf(stderr, "Error authenticating with password: %s\n",
            ssh_get_error(my_ssh_session));
    ssh_disconnect(my_ssh_session);

    ssh_free(my_ssh_session);
    exit(-1);
  }

  //================================================================
  sftp_start(my_ssh_session);
  //================================================================
  
  ssh_disconnect(my_ssh_session);

  ssh_free(my_ssh_session);
  return 0;
}

int sftp_service::sftp_helloworld(ssh_session session, sftp_session sftp)
{
  int rc;
 
  rc = sftp_mkdir(sftp, "helloworld", S_IRWXU);
  if (rc != SSH_OK)
  {
    if (sftp_get_error(sftp) != SSH_FX_FILE_ALREADY_EXISTS)
    {
      fprintf(stderr, "Can't create directory: %s\n",
              ssh_get_error(session));
        return rc;
    }
  }
 
  return SSH_OK;
  
}
 
int sftp_service::sftp_start(ssh_session session)
{
  sftp_session sftp;
  int rc;
 
  sftp = sftp_new(session);
  if (sftp == NULL)
  {
    fprintf(stderr, "Error allocating SFTP session: %s\n",
            ssh_get_error(session));
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
 
  sftp_helloworld(session, sftp);
  sftp_free(sftp);
  return SSH_OK;
}