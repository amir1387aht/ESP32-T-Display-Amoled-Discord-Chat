// Script.h - Main class for scripts to inherit

#ifndef SCRIPT_H
#define SCRIPT_H

class Script
{
private:
    bool isEnabled;

public:
    Script() : isEnabled(true) {}

    // Function to enable the script
    void SetActive(bool v)
    {
        isEnabled = v;
    }

    // Function to check if the script is enabled
    bool IsEnabled() const
    {
        return isEnabled;
    }

    virtual void start() = 0;
    virtual void update() = 0;
    virtual ~Script() {} // Virtual destructor for proper cleanup
};

#endif // SCRIPT_H