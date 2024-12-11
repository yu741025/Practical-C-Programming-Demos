/* This program copies the content and permissions of a source file to a target file, creating the target file if it does not exist.
 *
 * 1. Header Files
 *    - Necessary header files are included at the beginning of the code.
 *
 * 2. Define BUFFER_SIZE
 *    - A macro `BUFFER_SIZE` is defined to set the size of the read/write buffer, with a value of 10.
 *
 * 3. Custom `show_error` Function
 *    - A custom function `show_error` is implemented to display error messages and terminate the program when an error occurs.
 *    - `show_error` accepts a string parameter containing the error message.
 *
 * 4. `main` Function
 *    - The `main` function takes two command line arguments:
 *        1. The path to the source file.
 *        2. The path to the target file.
 *    - `argc` indicates the number of command line arguments.
 *    - `argv[]` is an array of strings storing the command line arguments.
 *
 * 5. File Opening
 *    - The program attempts to open the source and target files:
 *        - `O_RDONLY`: Opens the source file in read-only mode.
 *        - `O_CREAT`: Creates the target file if it does not exist.
 *        - `O_TRUNC`: Clears the contents of the target file if it already exists.
 *        - `O_WRONLY`: Opens the target file in write-only mode.
 *    - The target file permissions are set to `0777` for maximum permissions.
 *
 * 6. File Content Copying
 *    - The content of the source file is copied to the target file using:
 *        - `read` to read the content from the source file into a buffer.
 *        - `write` to write the buffer content to the target file.
 *    - The copying process occurs in a `while` loop until the source file is completely copied.
 *
 * 7. File Permission Copying
 *    - `stat` is used to obtain the permission settings of the source file.
 *    - `fchmod` is used to apply the same permissions to the target file.
 *    - This ensures the target file has the same permissions as the source file.
 *
 * 8. Closing Files
 *    - Finally, the source and target files are properly closed.
 *
 */


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

#define BUFFER_SIZE 10


int show_error(char error_msg[]) {
    printf("%s\n", error_msg);
    exit(-1);
}

int main(int argc, char* argv[]) {
    char *source_file = argv[1];
    char *target_file = argv[2];
    char my_buffer[BUFFER_SIZE] = "";
    int fd1;
    int fd2;

    if((fd1 = open(source_file, O_RDONLY)) < 0) {
        show_error("open error");
    }
 
    if((fd2 = open(target_file, O_CREAT | O_TRUNC | O_WRONLY, 0777)) < 0) {
        show_error("create error");
    }
    
    ssize_t read_size;
    while((read_size = read(fd1, my_buffer, BUFFER_SIZE - 1)) > 0) {
        if(write(fd2, my_buffer, read_size) != read_size) {
            show_error("write error");
        }
    }

    struct stat stat_buf;
    stat(source_file, &stat_buf);
    // printf("%o\n", stat_buf.st_mode & 0777);
    fchmod(fd2, stat_buf.st_mode);


    close(fd1);
    close(fd2);

    return 0;
}