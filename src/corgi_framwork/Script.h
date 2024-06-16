// Script.h - Main class for scripts to inherit

#ifndef SCRIPT_H
#define SCRIPT_H

#define DEFINE_TYPE_TAG(className) \
    virtual const char *getTypeTag() const override { return #className; }

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

    virtual const char *getTypeTag() const
    {
        return "Script";
    }

    virtual void start() = 0;
    virtual void update() = 0;
    virtual ~Script() {} // Virtual destructor for proper cleanup
};

#endif // SCRIPT_H