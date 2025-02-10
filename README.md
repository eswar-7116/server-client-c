# Simple TCP Client-Server Communication
This project demonstrates basic socket programming in C by setting up a simple client-server communication over TCP.
The server listens on port 8000 and sends a message to the client upon connection. The client connects to the server, receives the message, and displays it.
You need a Unix-like environment to run it.

## Technologies Used
- C
- Socket Programming (TCP)
- Basic Networking Concepts

## Instructions to Run

### 1. Clone the repository
First, clone this repository to your local machine using Git:

```bash
git clone https://github.com/eswar-7116/server-client-c.git server_client_c
cd server_client_c
```

### 2. Compile the server and client
Use `gcc` to compile both the server and client files.

- To compile the server:
  ```bash
  gcc server.c -o server
  ```
- To compile the client:
  ```bash
  gcc client.c -o client
  ```
- You can do this in a single command too:
  ```bash
  gcc server.c client.c -o server client
  ```

### 3. Run the server
Open a terminal and run the server:
```bash
./server
```
The server will start listening on port 127.0.0.1:8000.
You can Ctrl+C to stop the server.

### 4. Run the client
In a different terminal window, run the client to connect to the server:
```bash
./client
```
The client should connect to the server and display the message sent by the server.
