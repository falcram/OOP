// g++ -Wall  ProtocolTest.cpp  -o ProtocolTest -lssh -DLIBSSH_STATIC 
#include <libssh/libssh.h>
#include <stdlib.h>
#include <stdio.h>
#include "SFTPservice.cpp" 
int create_ssh_session()
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
 
  system("touch file_created_by_ssh.txt");
  ssh_disconnect(my_ssh_session);
  ssh_free(my_ssh_session);
}