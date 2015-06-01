# keystroked
Productivity monitor for keyboard activity in linux. Logs whether there was keyboard activity or not, each minute.

If you're on mac this won't work. [hours](https://github.com/vanceza/short-programs), is alternative approach which only looks at bash commands.

    Options
      -t iteration_time, default 60 sec
      -f logfile_name, default /var/log/keystroked/keystrokes.log
      -d path-to-device, default /dev/input/event0

Loglines are in the format `keyboard <timestamp> <number of keystrokes>`
