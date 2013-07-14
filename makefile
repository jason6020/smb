read_smb : read_smb.o
	gcc -o read_smb read_smb.o -lsmbclient
read_smb.o : read_smb.c
	gcc -c read_smb.c
clean:
	rm read_smb *.o

