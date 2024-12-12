# Practical System Utilities with C

This repository contains a collection of lightweight system-level utilities developed in C, focusing on advanced UNIX programming concepts. Each utility demonstrates specific aspects of system programming, including file operations, process management, multithreading, and memory usage.

## Features

- **File Operations**:
  - `file_lseek`: Demonstrates file manipulation using `lseek`, `read`, and `write`.
  - `copy_file`: Replicates a source file’s content and permissions to a target file, creating the target if it doesn’t exist.
- **Process Management**:
  - `zombie_checker`: Identifies zombie processes and validates process states.
  - `session_creator`: Creates new sessions and demonstrates process group management.

- **Multithreading**:
  - `thread_barrier`: Implements a synchronization barrier for threads using `pthread`.

- **Memory Mapping**:
  - `mmap_file_copy`: A high-performance file copying tool using memory-mapped I/O.

- **Time Management**:
  - `formatted_time`: Formats system time and supports timezone adjustments.

- **Safety and Pointer**:
  - `pointer_validation`: Explores pointer safety and memory lifecycle in C.

- **Daemon Utilities**:
  - `daemon_login`: A utility to test daemon behavior and login sessions.

## Usage

Each utility is self-contained and can be executed independently. To build and run the utilities, follow these steps:

1. Clone the repository:
   ```bash
   git clone https://github.com/yu741025/Practical-C-Programming-Demos.git
   cd Practical-C-Programming-Demos
