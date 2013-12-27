    /*
    *   compile with -Wall -std=c99
    *   run with root privilegies
    *
    *   Options: 
    *   -t iteration_time, defaul 60 sec
    *   -f logfile_name, default /var/log/keystroked/keystrokes.log
    *   -d path-to-device, default /dev/input/event0
    *
    */
    
    #include <stdio.h>
    #include <stdlib.h>
    #include <linux/input.h>
    #include <fcntl.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    
    int main(int argc, char const *argv[])
    {
        pid_t pid, sid;
        pid = fork();
        if (pid < 0) 
                exit(EXIT_FAILURE);
         if (pid > 0)
                exit(EXIT_SUCCESS);
        umask(0);
        
        int itertime = 60; 
        char logname[256] = "/var/log/keystroked/keystrokes.log"; 
        char devicename[100] = "/dev/input/event0";
        
        for (int i = 1; i < argc; ++i){
            if (!strcmp (argv[i], "-f")){
                strcpy(logname, argv[++i]);
                continue;
            }
            
            if (!strcmp (argv[i], "-t")){
                itertime = atoi(argv[++i]);
                continue;
            }
            
            if (!strcmp (argv[i], "-d")){
                strcpy(devicename, argv[++i]);
                continue;                
            }
            
            if (!strcmp(argv[i], "-h")){    
                printf("Options:\n-t time_interval (default 60sec)\n"
                        "-f log_filename (default /var/log/keystroked/keystrokes.log\n"
                        "-d device (default /dev/input/event0, will prob work on Arch Linux)\n"
                        "NOTE! Should be run with root privilegies\n");
                exit(EXIT_SUCCESS);
            }
        }   
        int device = open(devicename, O_RDONLY);
        
        if (device < 0)
            exit(EXIT_FAILURE);
                
        long flag = fcntl(device, F_GETFL, 0);
        fcntl(device, F_SETFL, flag | O_NONBLOCK);
                 
        sid = setsid();
        if (sid < 0)
                exit(EXIT_FAILURE);
         
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        close(STDERR_FILENO);
        
        time_t start, end;
        struct input_event ev;
        unsigned long counter = 0;  
        struct tm *loc;
        char buf[100];
        
        start = time(NULL);
        loc = localtime(&start);
        strftime(buf, sizeof(char)*100 - 1, "%s", loc);
        
        FILE *logfile = fopen(logname, "a");
        fprintf(logfile, "Started %s...\n", buf);
        fclose(logfile);
        
        while (1) {
            end = time(NULL);
            sleep(1);
            if (difftime(end, start) < itertime){ 
        
                int c = read(device, &ev, sizeof(struct input_event));
                if (c >= 0 && ev.type == 1 && ev.value == 1)
                    ++counter;
        
           } else {
                loc = localtime(&end);
                strftime(buf, sizeof(char)*100 - 1, "%s", loc);
        
                logfile = fopen(logname, "a");
                fprintf(logfile, "keyboard %s %ld\n", buf, counter);
                fclose(logfile);
        
                counter = 0;
                start = time(NULL);         
           }
        }
        close(device);
        exit(EXIT_SUCCESS);
    }    
