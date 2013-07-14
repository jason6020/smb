#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <libsmbclient.h>

static void auth_fn(const char *server, const char *share, char *workgroup, int wgmaxlen, char *username, int unmaxlen, char *password, int pwmaxlen) {
	
	strncpy(workgroup, "workgroup", wgmaxlen - 1);
	strncpy(username, "admin", unmaxlen - 1);
	strncpy(password, "admin", pwmaxlen - 1);

	printf("server = %s share = %s workgroup = %s username = %s password = %s", server, share, workgroup, username, password);
}

int main() {
	
	int err = -1;
	int dh = 0;
	struct smbc_dirent *dirptr;

	err = smbc_init(auth_fn, 10);
	if (err < 0) {
		
		fprintf(stdout, "smbc_init error!");
		return ;
	} else {
		
		dh = smbc_opendir("smb://192.168.169.1/huaxiayou/sda1/");
		printf("smbc_opendir dh = %d", dh);

		while ((dirptr = smbc_readdir(dh)) != NULL) {
			
			printf("dirptr->name = %s dirptr->smbc_type = %d\n", dirptr->name, dirptr->smbc_type);
		}

		smbc_close(dh);
	}
	return 0;
}
