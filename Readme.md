# EchoSerial

A simple C++ program that demonstrates inter-process communication using virtual serial ports. It sends a user-defined message to a virtual serial port and then reads the same message back from a connected port, effectively creating a "serial echo" loop.



### How It Works

The project relies on two main components:

* socat: This tool creates two virtual serial ports, /dev/ttyVSEND and /dev/ttyVREAD, and links them together. Any data written to /dev/ttyVSEND is immediately transferred to /dev/ttyVREAD, and vice-versa. This setup simulates a physical serial device that echoes back any data it receives.


Follow these steps in the given order to run the project successfully.
- Step 1: Start socat

First, you need to create the virtual serial ports using socat. Open a terminal and run the following command. The command will run in the foreground and continue until you terminate it with Ctrl+C.
```bash
sudo socat -d -d PTY,raw,echo=0,link=/dev/ttyVSEND PTY,raw,echo=0,link=/dev/ttyVREAD
2025/08/30 22:17:26 socat[807441] N PTY is /dev/pts/16
2025/08/30 22:17:26 socat[807441] N PTY is /dev/pts/17
2025/08/30 22:17:26 socat[807441] N starting data transfer loop with FDs [5,5] and [7,7]
```
- Step 2: Run the C++ Program

Open a new terminal window and navigate to your project directory. Run the executable with a message of your choice as a command-line argument.
```bash
sudo ./echoSerial "Hello, testing virtual serial port!"
Sent: Hello, testing virtual serial port!
Received: Hello, testing virtual serial port!
```
