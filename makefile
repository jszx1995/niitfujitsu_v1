CC:=gcc
CC+=-o
IC:=-Iinclude
IC+=-c

niitfujitsu:lib/help.o lib/list.o lib/display.o lib/file.o lib/mkdir.o\
		lib/dirdelete.o lib/delete.o lib/create_dir.o lib/dircopy.o\
		lib/dircopydir.o lib/filecopy.o lib/filecopydir.o lib/copy.o\
		lib/symkink.o lib/main.o
	$(CC) niitfujitsu lib/help.o lib/list.o lib/display.o lib/file.o lib/mkdir.o\
		lib/dirdelete.o lib/delete.o lib/create_dir.o lib/dircopy.o\
		lib/dircopydir.o lib/filecopy.o lib/filecopydir.o lib/copy.o\
		lib/symkink.o lib/main.o
lib/help.o:src/help.c
	$(CC) lib/help.o $(IC) src/help.c

lib/list.o:src/list.c
	$(CC) lib/list.o $(IC) src/list.c

lib/display.o:src/display.c
	$(CC) lib/display.o $(IC) src/display.c

lib/file.o:src/file.c
	$(CC) lib/file.o $(IC) src/file.c	

lib/mkdir.o:src/mkdir.c
	$(CC) lib/mkdir.o $(IC) src/mkdir.c

lib/dirdelete.o:src/dirdelete.c
	$(CC) lib/dirdelete.o $(IC) src/dirdelete.c

lib/delete.o:src/delete.c
	$(CC) lib/delete.o $(IC) src/delete.c

lib/create_dir.o:src/copy/create_dir.c
	$(CC) lib/create_dir.o $(IC) src/copy/create_dir.c

lib/dircopy.o:src/copy/dircopy.c
	$(CC) lib/dircopy.o $(IC) src/copy/dircopy.c

lib/dircopydir.o:src/copy/dircopydir.c
	$(CC) lib/dircopydir.o $(IC) src/copy/dircopydir.c

lib/filecopy.o:src/copy/filecopy.c
	$(CC) lib/filecopy.o $(IC) src/copy/filecopy.c

lib/filecopydir.o:src/copy/filecopydir.c
	$(CC) lib/filecopydir.o $(IC) src/copy/filecopydir.c

lib/copy.o:src/copy.c
	$(CC) lib/copy.o $(IC) src/copy.c

lib/symkink.o:src/symkink.c
	$(CC) lib/symkink.o $(IC) src/symkink.c

lib/main.o:src/main.c
	$(CC) lib/main.o $(IC) src/main.c

.PHONY:clean

clean:
	rm -fr niitfujitsu
