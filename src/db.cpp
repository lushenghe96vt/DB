 //db.cpp
#include "db.h"
    Database::Database(const std::string &name, const std::string &username, const std::string &password){
        Database::username = username;
        Database::password = password;
        db = name;
    }

    Database::~Database(){
        if(connected){
            disconnect();
        }
    }

    //"getInstance" that creates and returns the instance of the database. If called first time it sets the username and password. However, subsequent time, it matches the database name, username and password and returns the previous instance if matched else it throws std::runtime_error("invalid database name, username or password"). We are using Singleton Design Pattern that creates only one instance of the databse. The instance is still created by the constructor.
    //ToDo
    Database* Database::getInstance(std::string &name, std::string &username, std::string &password){
        if(instance == nullptr){
            instance = new Database(name, username, password);
        }
        else{
            if(instance->db == name && instance->username == username && instance->password == password){
                return instance;
            }
            else{
                throw std::runtime_error("invalid database name, username or password");
            }
        }
        return instance;
    }

    //"connect" that sets "connected" to true (return void)
    //ToDo
    void Database::connect(){
        connected = true;
    }

    //"disconnect" that sets "connected" to false (return void)
    //ToDo
    void Database::disconnect(){
        connected = false;
    }

    // retrun status of connected true/false (return bool)
    //ToDo
    bool Database::isConnected(){
        return connected;
    }

    //overload the new operator that allocates memory using malloc of given size and returns pointer of type void and prints " overloaded new " (cout is okay in this case). std::cout << "overloaded new ";
    //If the memory allocation fails it should throw std::bad_alloc()
    //ToDo
    void* Database::operator new(size_t size){
        void* p = malloc(size);
        if(p == nullptr){
            throw std::bad_alloc();
        }
        std::cout << " overloaded new ";
        return p;
    }

    //overload the delete operator that deallocates memory and prints "overloaded delete " (cout is okay in this). std::cout << "overloaded delete ";
    //ToDo
    void Database::operator delete(void* p){
        free(p);
        std::cout << "overloaded delete ";
    }

    //set_username and get_username for username
    //ToDo
    void Database::set_username(std::string &username){
        Database::username = username;
    }

    //ToDo
    std::string Database::get_username(){
        return username;
    }

    //set_password and get_password for password.
    //ToDo
    void Database::set_password(std::string &password){
        Database::password = password;
    }

    //ToDo
    std::string Database::get_password(){
        return password;
    }


 void Database::resetInstance() {
    if (instance != nullptr) {
      delete instance;
      instance = nullptr;
    }
  }