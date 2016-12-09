/***********************************************************
* IT FUJITSU SECOND GROUP
* File name: file.c
* Summary:   Create a file, set the new property to mode.
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

/*Create a file*/

void create_file(int argc,char * argv[]){
	//Determine the number of parameters    
	if(argc != 4){
		fprintf(stderr, "usage: %s Incorrect\n",argv[0]);
                exit(1);
	}

	int fp;
	char *modefile = argv[3];
	struct stat buff;
	memset(&buff,0,sizeof(buff));
	lstat(modefile,&buff);

	//Determine whether the file exists
	if(S_ISREG(buff.st_mode) && (access(modefile,F_OK) == 0)){
		fprintf(stderr,"Overlay into a new %s file!\n",modefile);
		//Gets the file attributes
		mode_t mode = buff.st_mode;
		umask(0);	
		fp = open(argv[2],O_RDWR|O_CREAT,mode);
		if(fp == 0) 
			return;
		close(fp);
		exit(1);
	}else{
		fprintf(stderr,"%s does not exist, the default attribute new %s!\n",
				modefile,argv[2]);
		umask(0);
		fp = open(argv[2],O_RDWR|O_CREAT,0644);
		if(fp == 0)
			return;
		close(fp);
		exit(1);
	}
}

