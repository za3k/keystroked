# keystroked
Productivity monitor for keyboard activity. Logs whether there was keyboard activity or not, each minute.

    Options
      -t iteration_time, default 60 sec
      -f logfile_name, default /var/log/keystroked/keystrokes.log
      -d path-to-device, default /dev/input/event0

Loglines are in the format `keyboard <timestamp> <number of keystrokes>`
