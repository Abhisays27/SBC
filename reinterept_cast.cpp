#include <iostream>
#include <cstring>

// Define a structure for a simplified SIP Header
struct SIPHeader {
    char method[8];   // SIP Method (e.g., "INVITE", "BYE")
    int statusCode;   // Status Code (e.g., 200 for OK)
};

// Function to process a raw SIP packet (binary data)
void processSIPData(const char* rawData) {
    // Reinterpret the raw data as a SIPHeader structure
    const SIPHeader* header = reinterpret_cast<const SIPHeader*>(rawData);

    std::cout << "Processing SIP Message..." << std::endl;
    std::cout << "SIP Method: " << header->method << std::endl;
    std::cout << "Status Code: " << header->statusCode << std::endl;
}

int main() {
    // Simulating a SIP packet (binary data)
    char rawPacket[sizeof(SIPHeader)];

    // Initialize SIP Method (e.g., "INVITE")
    std::memset(rawPacket, 0, sizeof(rawPacket));  // Clear memory
    std::strncpy(rawPacket, "INVITE", 7); // Copy method into struct
    
    // Set status code (e.g., 200 OK)
    int status = 200;
    std::memcpy(rawPacket + 8, &status, sizeof(int));

    // Process the raw SIP packet
    processSIPData(rawPacket);

    return 0;
}
