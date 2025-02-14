//static_cast in C++ is a type conversion operator used for performing explicit type conversions at compile time. It is safer and more readable than C-style casts and is typically used in cases where the conversion is well-defined and does not involve runtime type checking.


#include <iostream>
#include <string>

// Base class for all SIP messages
class SIPMessage {
public:
    virtual void parse() { 
        std::cout << "Parsing generic SIP message\n"; 
    }
    virtual ~SIPMessage() {}  // Virtual destructor for cleanup
};

// Derived class for SIP INVITE messages
class INVITEMessage : public SIPMessage {
public:
    void parse() override { 
        std::cout << "Parsing SIP INVITE message (Call Setup)\n"; 
    }
};

// Derived class for SIP BYE messages
class BYEMessage : public SIPMessage {
public:
    void parse() override { 
        std::cout << "Parsing SIP BYE message (Call Termination)\n"; 
    }
};

// Function to simulate receiving a SIP message type (In real systems, this would be from a network socket)
SIPMessage* receiveSIPMessage(const std::string& msgType) {
    if (msgType == "INVITE") return new INVITEMessage();
    if (msgType == "BYE") return new BYEMessage();
    return new SIPMessage();  // Default case
}

// Function to process SIP messages using static_cast
void processSIPMessage(SIPMessage* msg, const std::string& msgType) {
    if (msgType == "INVITE") {
        INVITEMessage* invite = static_cast<INVITEMessage*>(msg);  // Safe static cast
        invite->parse();
    } else if (msgType == "BYE") {
        BYEMessage* bye = static_cast<BYEMessage*>(msg);  // Safe static cast
        bye->parse();
    } else {
        msg->parse();
    }
}

int main() {
    // Simulate receiving different SIP messages
    SIPMessage* msg1 = receiveSIPMessage("INVITE");
    SIPMessage* msg2 = receiveSIPMessage("BYE");
    SIPMessage* msg3 = receiveSIPMessage("UNKNOWN");

    std::cout << "\nProcessing SIP Messages:\n";

    processSIPMessage(msg1, "INVITE");
    processSIPMessage(msg2, "BYE");
    processSIPMessage(msg3, "UNKNOWN");

    // Cleanup allocated memory
    delete msg1;
    delete msg2;
    delete msg3;

    return 0;
}
