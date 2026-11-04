# OSI Communication Simulation Project

## Overview
This project demonstrates the seven layers of the OSI (Open Systems Interconnection) model through data encapsulation, decapsulation, and client-server communication.

## Features
- Demonstrates all seven OSI layers.
- Shows data encapsulation and decapsulation.
- Implements C-based TCP client-server communication using Winsock.
- Uses Python to visualize OSI data flow.
- Demonstrates message transmission between client and server.

## Technologies Used
- C
- Python
- TCP/IP Sockets
- Winsock
- Visual Studio Code
- MSYS2 UCRT64

## Project Files
- `client.c` - TCP client implementation.
- `server.c` - TCP server implementation.
- `visualizer.py` - OSI layer data flow visualization.
- `layers.c` and `layers.h` - OSI layer-related implementation.
- `main.c` - Main program.
- `Makefile` - Build configuration.

## How to Run

### Compile the Server
```bash
gcc server.c -o server.exe -lws2_32
```

### Compile the Client
```bash
gcc client.c -o client.exe -lws2_32
```

### Run the Server
```bash
./server.exe
```

### Run the Client
Open another terminal and run:
```bash
./client.exe
```

### Run the Python Visualizer
```bash
python visualizer.py
```

## Sample Message
`APP{Hello from Client}`

The server receives the encapsulated message and extracts the original application message.

## Author
Meharin Choudhury  
Department of Information and Communication Technology  
MBSTU
