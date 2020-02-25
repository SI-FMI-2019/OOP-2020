#include <cstring>

class Login
{
private:
    char* username;
    char* password;
    int session_type; //0 - normal user, 1 - admin, etc.

public:
    Login();
    Login(char const* username, char const* password);
    Login(const Login& from);

    bool login(const char* username, const char* password);
};
