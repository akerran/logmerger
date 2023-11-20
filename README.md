# logmerger
simple executable to merge several log files into one by timestamp

# prerequisites
/tmp/logs directory with logfiles
each log file has entries in format "posix_timestamp some_message\n"

# compiling instruction
g++ logmerger.cpp -o logmerger -std=c++2a

# execution example
```
// three initial log files, some of them contain timestamp duplicates
user:~/cpp_stuff$ cat /tmp/logs/sys1.log 
1700512985 message1
1700512985 duplicate timestamp
1700512986 message2
1700512986 message3
user:~/cpp_stuff$ cat /tmp/logs/sys2.log 
1700513061 message
1700513062 message
1700513096 duplicate timestamp from sys3.log
user:~/cpp_stuff$ cat /tmp/logs/sys3.log 
1700513094 message3
1700513095 message2
1700513096 message1

// remove merged log (in order to have clean experiment)
// compile and run
user:~/cpp_stuff$ rm /tmp/merged.log 
user:~/cpp_stuff$ g++ logmerger.cpp -o logmerger -std=c++2a
user:~/cpp_stuff$ ./logmerger 

// check result merged file
// it has all sorted lines from initial log files, including messages with duplicate timestamps
user:~/cpp_stuff$ cat /tmp/merged.log 
1700512985 message1
1700512985 duplicate timestamp
1700512986 message2
1700512986 message3
1700513061 message
1700513062 message
1700513094 message3
1700513095 message2
1700513096 duplicate timestamp from sys3.log
1700513096 message1
```

