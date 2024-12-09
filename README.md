# Practical-C-Programming-Demos

This repository showcases a collection of C programming projects designed to explore and demonstrate practical system-level programming concepts, focusing on UNIX/Linux environments. Each module highlights a specific area of advanced C programming, such as file operations, process management, multithreading, memory mapping, and system calls. These projects were created to deepen understanding of low-level programming and serve as hands-on demonstrations of critical software development skills.

Features

	•	File Operations: Advanced usage of open, read, write, and lseek to manipulate files and demonstrate random access and efficient file handling techniques.
	•	Process Management: Examples of creating and managing processes, including zombie processes, session leaders, and process group management.
	•	Multithreading: Implementation of thread synchronization mechanisms using pthread and the development of a custom thread barrier.
	•	Memory Mapping: File copying through memory-mapped I/O using mmap for efficient file operations.
	•	UNIX Time Management: Using strftime for formatting system time in different time zones.
	•	System Call Exploration: Hands-on demonstrations of system calls and their interaction with the operating system.

Why This Project?

This repository is ideal for:
	•	Students or Developers: Looking to understand the practical aspects of C programming in a UNIX/Linux environment.
	•	Interview Preparation: Demonstrates proficiency in key system programming topics and showcases problem-solving skills.
	•	Expanding Knowledge: Explores the use of low-level system calls and advanced programming techniques.

How to Use

	1.	Clone the repository:

git clone https://github.com/yourusername/Practical-C-Programming-Demos.git
cd Practical-C-Programming-Demos


	2.	Navigate to a specific module:

cd src/file_operations
make
./file_lseek


	3.	Explore other modules for additional functionalities and demonstrations.

Modules Overview

	1.	File Operations:
	•	Demonstrates file reading and writing using lseek, handling random access, and modifying file content programmatically.
	2.	Process Management:
	•	Explores process states (e.g., zombie processes) and session creation through fork and setsid.
	3.	Multithreading:
	•	Implements a thread barrier using pthread synchronization primitives.
	4.	Memory Mapping:
	•	Efficient file copying via mmap and discussions on the implications of file descriptor closures on memory mapping.
	5.	System Time:
	•	Prints formatted system time using strftime, with timezone manipulation.
	6.	System Call Validation:
	•	Tests the behavior and implications of specific C standard library functions, including safety considerations.

Highlights

	•	Demonstrates proficiency in C programming with real-world system-level applications.
	•	Explores low-level UNIX/Linux concepts that are critical for software development roles.
	•	Showcases problem-solving skills through self-contained examples and well-documented code.

Acknowledgements

This project was developed as part of an advanced UNIX programming course and is intended for educational and demonstration purposes. It serves as a bridge between academic learning and real-world system programming challenges.
