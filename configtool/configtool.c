#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

int main(int argc,char** argv)
{
        struct termios tio;
        struct termios stdio;
        struct termios old_stdio;
        int tty_fd, file_fd;
	char * command = "\r\n\r\nConfig";
	char buf;
 	ssize_t got;
	char * reboot = "\r\n\r\nReboot";
        unsigned char c='D';
        tcgetattr(STDOUT_FILENO,&old_stdio);
 
        memset(&stdio,0,sizeof(stdio));
        stdio.c_iflag=0;
        stdio.c_oflag=0;
        stdio.c_cflag=0;
        stdio.c_lflag=0;
        stdio.c_cc[VMIN]=1;
        stdio.c_cc[VTIME]=0;
        tcsetattr(STDOUT_FILENO,TCSANOW,&stdio);
        tcsetattr(STDOUT_FILENO,TCSAFLUSH,&stdio);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);       // make the reads non-blocking
 
        memset(&tio,0,sizeof(tio));
        tio.c_iflag=0;
        tio.c_oflag=0;
        tio.c_cflag=CS8|CREAD|CLOCAL;           // 8n1, see termios.h for more information
        tio.c_lflag=0;
        tio.c_cc[VMIN]=1;
        tio.c_cc[VTIME]=5;

	if (argc<2) {
         	fprintf(stderr, "%s: syntax: %s <pixelpusher-tty> [[<config-file>] <script-flag>]\r\n",
			argv[0], argv[0]);
        	close(tty_fd);
        	tcsetattr(STDOUT_FILENO,TCSANOW,&old_stdio);
		return -1;
	}
 
        tty_fd=open(argv[1], O_RDWR | O_NONBLOCK);      
        cfsetospeed(&tio,B115200);            // 115200 baud
        cfsetispeed(&tio,B115200);            // 115200 baud

	file_fd = -1;
	if (argc>2) {
		file_fd=open(argv[2], O_RDONLY);
 	}
        tcsetattr(tty_fd,TCSANOW,&tio);

	if (file_fd > -1) {
		printf("%s: writing config.\r\n", argv[0]);
		write(tty_fd, command, strlen(command));
		while((got = read(file_fd, &buf, 1))) {
			write(tty_fd, &buf, 1);
		}
		buf = (char) 0xff;
		write(tty_fd, &buf, 1);
		write(tty_fd, &buf, 1);
		write(tty_fd, &buf, 1);
	}

	write(tty_fd, reboot, strlen(reboot));

	if (argc < 4) {
		printf("\r\n\r\nPress q to quit.\r\n\r\n");
        	while (c!='q')
        	{	
			// if new data is available on the serial port, print it out
                	if (read(tty_fd,&c,1)>0) {
		       		write(STDOUT_FILENO,&c,1);
		       		c='b'; // don't trip on a 'q' in the debug spool
			}	
			// if new data is available on the console, send it to the serial port
                	if (read(STDIN_FILENO,&c,1)>0)  write(tty_fd,&c,1);
        	}	
 	} else {
		sleep(5); 
		while (read(tty_fd,&c,1)>0) {
                	if (strcmp(argv[3], "echo") == 0) 
				write(STDOUT_FILENO,&c,1);
		}
	}
	// we're done, clean up
        close(tty_fd);
        tcsetattr(STDOUT_FILENO,TCSANOW,&old_stdio);
 
        return EXIT_SUCCESS;
}
