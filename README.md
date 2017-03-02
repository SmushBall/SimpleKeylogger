# SimpleKeylogger
This is a simple keylogger which runs in a stealth mode and captures every key strokes in a file.

This program is written in C++ and makes use of GetAsyncKeyState, which is a function which returns a non zero value when a key is pressed.
The program creates a window handle, allocates a new console and hides itself (can still be seen in Task Manager). It runs indefinitely and detects if a key is pressed. If it detects so, it writes it to a file.

# Testing
There are a coupleof binders available which binds .cpp to executable .exe format. I tested in on my own computer and it worked.

# Caution
This was both educational and experimental, written with the help of tutorials which I came acrosss the web. I take no responsibility for any loss or damage with the program.
