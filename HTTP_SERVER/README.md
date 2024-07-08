# HTTP_SERVER

This project involves the creation of an [HTTP server](https://en.wikipedia.org/wiki/Web_server) from scratch using C++ and C.

<p align="center">
  <img src="https://media.geeksforgeeks.org/wp-content/uploads/20190927155217/webserver.png" width="500">
</p>

The objective of this project is to gain a deep understanding of how servers work, their functionalities, and features. We implement key HTTP methods: [GET](https://http.dev/get), [POST](https://http.dev/post), and [DELETE](https://http.dev/delete).

## Some Important Concepts

In this project, you'll delve into various concepts, with one of the most fundamental being sockets.

A socket is a crucial mechanism that enables communication over the internet. It can be likened to file descriptors but serves as a specialized type of file descriptor. For detailed information, refer to the following resources:
- [Socket Programming in C/C++](https://www.geeksforgeeks.org/socket-programming-cc/)
- [Introduction to Socket Programming](https://www.cs.rpi.edu/~moorthy/Courses/os98/Pgms/socket.html)

## How We Build It

To successfully build this project, you'll need to become acquainted with several essential functions.

### `socket()`

The `socket()` function is one of the cornerstones of server creation. It is used to create a socket, an essential component in server operation. Here's the basic syntax:

```c
int my_socket = socket("Domain", "socket type", "protocol to be used");
``` 
In practice, it might look like this 

```c
int my_socket = socket(AF_INET, SOCK_STREAM, 0);
```
Understanding ports, sockets, and addresses can be likened to a physical address system. You, the application, reside in your "apartment." The address represents the location, the mailbox corresponds to the port, the network resembles the post office, and the socket serves as the key granting access to the correct mailbox.

Selecting the port that the socket can connect to is accomplished using the bind function.

