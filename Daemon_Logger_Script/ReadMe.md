# Daemon Logger Script

### What It Does
This script runs as a daemon (background process) and logs printable characters from standard input to a file.

#### Why It Is Used
The script is useful for monitoring and recording input characters in the background without user intervention.


 ###  How It Works

   - #### Daemonization:
       - The script creates a child process and exits the parent process to run in the background.
       - It sets file permissions, creates a new session, and changes the working directory to root.
       - Standard input and error outputs are closed.
- #### Logging
    - The script opens a log file at /Your/Logs/file.txt
    - It continuously reads characters from standard input.
    - If the character is printable, it writes the character to the log file and flushes the file.
- #### Dependencies
    #####  Standard C++ libraries (iostream, fstream, unistd.h, sys/types.h, sys/stat.h, fcntl.h).


