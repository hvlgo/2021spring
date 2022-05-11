//#pragma once
#include "Parser.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

bool isInt(string str)
{
	bool isNum = false;

	int index = 0;
	for (int i = 0; i < str.length(); i++, index++)
	{
		switch (str[i])
		{
		case'0':case'1':case'2':case'3':case'4':case'5':
		case'6':case'7':case'8':case'9':
			isNum = true;
			break;
		case '-':case '+':
			if (index != 0)
			{
				return false;
			}
			break;
		default:
			return false;
		}
	}

	if (!isNum)
	{
		return false;
	}

	return true;
}

void Parser::add_argument(string arg, int defau, string _arg)
{
    static int num = 0;
    args_[num].args1 = arg;
    args_[num].def = defau;
    args_[num].args2 = _arg;
    num++;
}

void Parser::init(int _argc, char * _argv[])
{
    argc = _argc;
    for (int i = 0; i < 3; i++)
    {
        transform(args_[i].args1.begin() + 2, args_[i].args1.end(),back_inserter(args__[i].args1), ::toupper);
    }
    for (int i = 0; i < argc; i++)
    {
        argv.push_back(_argv[i]);
        if (argv[i] == "--help")
        {
            cout << "usage: ./main [--help] [" << args_[0].args1 << ' ' << args__[0].args1 << "] [" << args_[1].args1 << ' ' << args__[1].args1 << "] [" << args_[2].args1 << ' ' << args__[2].args1 <<  "]" << endl;
            cout << endl;
            cout << "optional arguments:" << endl;
            cout << " --help   show this help message and exit" << endl;
            cout << " " << args_[0].args1 << ' ' << args__[0].args1 << "   " << args_[0].args2 << endl;
            cout << " " << args_[1].args1 << ' ' << args__[1].args1 << "   " << args_[1].args2 << endl;
            cout << " " << args_[2].args1 << ' ' << args__[2].args1 << "   " << args_[2].args2 << endl;
            exit(0);
        }
    }
    for (int i = 0; i < argc; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (argv[i] == args_[j].args1)
            {
                if (i == argc - 1)
                {
                    cout << "usage: ./main [--help] [" << args_[0].args1 << ' ' << args__[0].args1 << "] [" << args_[1].args1 << ' ' << args__[1].args1 << "] [" << args_[2].args1 << ' ' << args__[2].args1 <<  "]" << endl;
                    cout << "./main: error: argument "<< argv[i] << ": expected an argument" << endl;
                    exit(0);
                }
                else if (!isInt(argv[i+1]))
                {
                    cout << "usage: ./main [--help] [" << args_[0].args1 << ' ' << args__[0].args1 << "] [" << args_[1].args1 << ' ' << args__[1].args1 << "] [" << args_[2].args1 << ' ' << args__[2].args1 <<  "]" << endl;
                    cout << "./main: error: argument " << argv[i] << ": invalid int value: '"<< argv[i+1] << "'" << endl;
                    exit(0);
                }
                else
                    {
                        args_[j].def = atoi(_argv[i+1]);
                        i++;
                        break;
                    }
            }
            else if (j == 2 && i != 0)
            {
                cout << "usage: ./main [--help] [" << args_[0].args1 << ' ' << args__[0].args1 << "] [" << args_[1].args1 << ' ' << args__[1].args1 << "] [" << args_[2].args1 << ' ' << args__[2].args1 <<  "]" << endl;
                cout << "./main: error: unrecognized arguments: " << argv[i] << endl;
                exit(0);
            }
        }
    }
}

int Parser::get_argument(string arg)
{
    if ( "--" + arg == args_[0].args1)
        return args_[0].def;
    if ( "--" + arg == args_[1].args1)
        return args_[1].def;
    if ( "--" + arg == args_[2].args1)
        return args_[2].def;
}

