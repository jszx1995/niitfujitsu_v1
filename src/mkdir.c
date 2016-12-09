/***********************************************************
* IT FUJITSU SECOND GROUP
* File name: mkdir.c
* Summary:   Create a directory, set the new property to mode.
* Author:    Zhu Xiang <jszx1995@126.com>
************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "io.h"

/*Create a directory*/

void create_directory(int argc, char * argv[]){
	//Determine the number of parameters	
	if(argc != 4){
		fprintf(stderr, "usage: %s Incorrect\n",argv[0]);
		exit(1);
	}

	char * modefile = argv[3];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(modefile,&buff);

	//Determine whether the directory exists
	if(S_ISDIR(buff.st_mode) && (access(modefile,F_OK) == 0)){
		fprintf(stderr,"Overlay into a new %s directory!\n",modefile);
		//Gets the file attributes
		mode_t mode = buff.st_mode;
		umask(0);
		mkdir(argv[2],mode);
		exit(1);
	}else{
		fprintf(stderr,"%s does not exist, the default attribute new %s!\n",
				modefile,argv[2]);
		mkdir(argv[2],0777);
		exit(1);
	}
}
