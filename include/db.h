
// db.h
#include <string>
#include <iostream>
#include <ctime>

class Database {
//private: 
public: 
    //member variable "db" is of string type
    std::string db;
    //member variable "username" is of string type
    std::string username;
    //member variable "password" is of string type
    std::string password;
    //member variable "connected" is of string type
     //The "connected" is set to false initially.
    bool connected = false;

    //member variable "instance" is static 
    //"instance" (pointer to Database) is a staic variable that stores the instance of the database. Its value is set in the function "getInstance"
    static Database* instance;

    //constructor that helps creating instance of db(e.g. sales.db) accepts name of the database, username, password. 
    Database(const std::string& name, const std::string& username, const std::string& password);
    //destructor that disconnects the connection if connected.
    ~Database();

    // timeout variables
    time_t last_activity;
    static const int TIMEOUT{5};

//public:
    //"getInstance" that creates and returns the instance of the database. If called first time it sets the username and password. However, subsequent time, it matches the database name, username and password and returns the previous instance if matched else it throws std::runtime_error("invalid database name, username or password"). We are using Singleton Design Pattern that creates only one instance of the databse. The instance is still created by the constructor.
    static Database* getInstance(const std::string& name, const std::string& username, const std::string& password);
    //"connect" that sets "connected" to true (return void)
    void connect();
    //"disconnect" that sets "connected" to false (return void)
    void disconnect();
    // retrun status of connected true/false (return bool)
    bool isConnected();
    //overload the new operator that allocates memory using malloc of given size and returns pointer of type void and prints " overloaded new " (cout is okay in this case). std::cout << "overloaded new ";
    //If the memory allocation fails it should throw std::bad_alloc()
    void* operator new(size_t size);
    //overload the delete operator that deallocates memory and prints "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
    void operator delete(void* p);

    //set_username and get_username for username
    void set_username(const std::string& username);
    std::string get_username() const;
    //set_password and get_password for password.
    void set_password(const std::string& password);
    std::string get_password() const;

    //The static "resetInstance" as defined below.
    static void resetInstance();

    // Timeout management
    bool isTimeout();
    void refreshConnection();
   
    // Copy and move prevention
    Database(const Database&);
    Database& operator=(const Database&);
    Database(const Database&&) noexcept;
    Database& operator=(const Database&&) noexcept;
};