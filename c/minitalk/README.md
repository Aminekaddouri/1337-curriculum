# minitalk

> A lightweight inter-process communication (IPC) system using UNIX signals.

A C program that enables a client to send a string to a server in real time using only `SIGUSR1` and `SIGUSR2` signals — no sockets, no files, no pipes. A deep dive into signal handling and binary data transmission.

---

### 🛠️ Features

- **Client-Server Communication**:  
  The `server` prints its PID on launch; the `client` sends a string using that PID.

- **Signal-Based Messaging**:  
  Each bit of the message is sent using:
  - `SIGUSR1` for `1`
  - `SIGUSR2` for `0`

- **Real-Time Delivery**:  
  The server prints the received string immediately — with no noticeable delay.

- **Multiple Clients Support**:  
  The server can receive messages from multiple clients **in sequence** without restarting.

- **No External Libraries**:  
  Built using only allowed functions: `signal`, `sigaction`, `kill`, `pause`, `malloc`, `write`, and `getpid`.

- **No Global Variables (except justified one)**:  
  Uses only **one global variable** in the server to store the current byte being reconstructed.

---

### 🧰 Tech Stack
- **Language**: C
- **Tools**: `make`, `gcc` with `-Wall -Wextra -Werror`
- **Standard**: C89
- **Key Concepts**: UNIX signals, bit manipulation, process communication


