#ifndef Parser_H
#define Parser_H
#include <string>
#include <vector>
using namespace std;

struct argument
{
    std::string args1;
    int def;
    std::string args2;
};
class Parser
{
    private :
    int argc;
    vector<std::string> argv;
    argument args_[5];
    argument args__[5];
    public :
    void add_argument(std::string arg, int defau, std::string _arg);
    void init(int _agrc, char * _argv[]);
    int get_argument(std::string arg);
    Parser()
    {
        argc = 0;
        return ;
    }
};
#endif