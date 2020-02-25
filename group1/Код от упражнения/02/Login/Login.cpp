#include "Login.hpp"

Login::Login(): session_type(0)
{
    this->username = new char[1];
    this->password = new char[1];

    this->username[0] = '\0';
    this->password[0] = '\0';
}
Login::Login(char const* username, char const* password)
{
    int username_len = strlen(username);
    this->username = new char[username_len + 1];
    strcpy(this->username, username);

    //Цикъл също става

    int password_len = strlen(password);
    this->password = new char[password_len + 1];
    strcpy(this->password, password);

    this->session_type = 0;
}

Login::Login(const Login& from)
{
    Login(from.username, from.password);
    this->session_type = from.session_type;
}

bool Login::login(const char* username, const char* password)
{
    //Цикъл може

    int is_username_correct = strcmp(this->username, username); //Връща 0 ако са равни
    int is_password_correct = strcmp(this->password, password); 

    return (is_username_correct == 0 && is_password_correct == 0);
}