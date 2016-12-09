/************************************************************
* IT FUJITSU SECOND GROUP
* File name:	symlink.c
* Summary:   	Create a soft link for the file directory
* Author:    	Zhu Xaing <jszx1995@126.com>
************************************************************/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include "io.h"

 /*Create a soft link for the file directory*/

void symkink_file_dir(int argc,char * argv[]){
	//Determine the number of parameters 
	if(argc != 4){
		fprintf(stderr, "usage: %s Incorrect\n",argv[0]);
			exit(1);
	}

	char *oldfile = argv[2];
	char *newfile = argv[3];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(oldfile,&buff);
	
	//Determine whether the file directory exists
	if(access(oldfile,F_OK) == 0){
		symlink(oldfile,newfile);
	}else{
		fprintf(stderr,"%s file does not exist!\n",oldfile);
	}
	exit(1);
}

