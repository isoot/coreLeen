//
// Created by PundiX42 on 2019-04-26.
//

#include <stdio.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>



void error();
int time_now(const char *file, off_t filesize);
int main(int argc, const char **argv)
{

    char *filename="hello.txt";
    int fd;
    struct stat sbuf;
    int stat_result = stat(filename, &sbuf);
    printf("call stat function result value : %d", stat_result);
    if(stat_result)//return 0
    {
        if(errno != ENOENT)
        {
            error(0, errno, "%s", filename);
            return -1;
        }

        fd = creat(filename, 0666);
        if(-1 == fd)
        {
            error(0, errno, "%s", filename);
            return -1;
        }

    }

    int result = time_now(filename, sbuf.st_size);
    printf("result %d", result);
    return 0;
}

int time_now(const char *file, off_t filesize)
{
    int fd ;
    char c;
    int status = 0;
    fd = open(file, O_RDWR, 0666);
    if(fd < 0
       || read(fd, &c, sizeof(char)) < 0
       || lseek(fd, (off_t)0, SEEK_SET) < 0
       || write(fd, &c, sizeof(char)) < 0
       /**
        * ftruncate会将参数fd指定的文件大小改为参数length指定的大小，
        * 参数fd 为已经打开的文件描述符，如果原来的文件大小比参数length大，
        * 则超过的部分会被删去
        */
       || ftruncate(fd, filesize) < 0
       || close(fd) < 0)
        status = -1;
    return status;
}
