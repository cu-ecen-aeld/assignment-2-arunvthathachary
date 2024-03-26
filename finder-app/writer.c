// writer implementation to write given string to given file

// Author: arun thathachary 
// Date: 3/18/2024

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <syslog.h>

int main(int argc,char* argv[])
{
    size_t fd;

    /*error handling for not enough parameters*/
    if(argc<2)
    {
        /*check errno through perror and strerror*/
        //perror("perror returned: ");
        fprintf(stderr,"errno is: %d and error type is: %s \n",errno,strerror(errno));
        return 1;
    }
    else if(argc<3)
    {
        /*check errno through perror and strerror*/
        //perror("perror returned: ");
        fprintf(stderr,"errno is: %d and error type is: %s \n",errno,strerror(errno));
        return 1;
    }

    char* path = argv[1];

    /*get file descriptor with creat option and permision settings*/
    fd = open(path, O_CREAT|O_RDWR|O_APPEND,0764);

    /* simple file descriptor with just rd/wr/append enalbed*/
    //fd = open(path, O_RDWR|O_APPEND);

    /*check errno through perror and strerror*/
    //perror("perror returned: ");
    fprintf(stderr,"errno is: %d and error type is: %s \n",errno,strerror(errno));

    /* send output to /var/log/syslog */
    if(errno)
    {
        openlog(NULL,0,LOG_USER);
        syslog(LOG_ERR,"Error returned: %s",strerror(errno));
        return -1;
    }
    
    /* prints for manual debug*/
    //printf("fd: %lu \t path: %s \n",fd,path);
    char* buf = argv[2];
    //printf("buf %s \n",buf);
    ssize_t nr;
    
    nr = write(fd,buf,strlen(buf));
    syslog(LOG_INFO,"Writing %s to file %s",buf,path);
    
    //printf("nr %lu \t strlen %lu \n", nr,strlen(buf));

    if(nr==-1)
    {
        //printf("nr error line");
        //perror("perror returned: ");
        return -1;
    }
    return 0;
}