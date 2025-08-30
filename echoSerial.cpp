#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unistd.h>

int main(int argc, char* argv[]) {

    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <message>" << std::endl;
        return 1;
    }

    // Combine all command-line arguments into a single message string
    std::string message;
    for (int i = 1; i < argc; ++i) {
        message += argv[i];
        if (i < argc - 1) {
            message += " ";
        }
    }

    std::fstream write_stream("/dev/ttyVSEND", std::ios::out);
    std::fstream read_stream("/dev/ttyVREAD", std::ios::in);

    if (!write_stream.is_open() || !read_stream.is_open()) {
        std::cerr << "Error: Could not open virtual serial ports." << std::endl;
        return 1;
    }
    
    // std::endl adds a newline character ('\n') AND flushes the stream.
    write_stream << message << std::endl; 
    std::cout << "Sent: " << message << std::endl;


    sleep(1); 

    std::string received_message;
    if (std::getline(read_stream, received_message)) {
        std::cout << "Received: " << received_message << std::endl;
    } else {
        std::cerr << "Error reading from stream." << std::endl;
    }

    write_stream.close();
    read_stream.close();

    return 0;
}
