#include <iostream>

// Function to modify a SIP header (only safe if the original data is mutable)
void modifySIPHeader(const char* header) {
    char* editableHeader = const_cast<char*>(header); // Remove const to allow modification
    editableHeader[0] = 'X'; // Change first character
    std::cout << "Modified header: " << editableHeader << std::endl;
}

int main() {
    // Define a mutable SIP header string
    char sipHeader[] = "INVITE sip:user@example.com";

    std::cout << "Original header: " << sipHeader << std::endl;
    
    // Modify the header using const_cast
    modifySIPHeader(sipHeader); 

    std::cout << "Final header: " << sipHeader << std::endl;

    return 0;
}
