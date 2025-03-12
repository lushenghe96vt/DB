// db.h
#include <string>
#include <iostream>

class Database {
private:
    std::string db;
    std::string username;
    std::string password;
    bool connected = false;

    static Database* instance;  // Singleton instance

    // Private constructor
    Database(const std::string& name, const std::string& username, const std::string& password);
    ~Database();

public:
    // static getInstance method
    static Database* getInstance(const std::string& name, const std::string& username, const std::string& password);

    void connect();
    void disconnect();
    bool isConnected();

    void* operator new(size_t size);
    void operator delete(void* p);

    void set_username(const std::string& username);
    std::string get_username();

    void set_password(const std::string& password);
    std::string get_password();

    // Reset instance (static)
    static void resetInstance();
};