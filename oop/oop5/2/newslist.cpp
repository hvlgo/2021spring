#include "newslist.h"

void newslist::addfriend(const myfriend & f)
{
    fri.emplace_front(f);
}

std::deque<myfriend> & newslist::getlist()
{
    return fri;
}

void newslist::top(const myfriend & f)
{
    for (auto i = fri.begin(); i != fri.end(); ++i)
    {
        if (f.getid() == (*i).getid())
        {
            fri.erase(i);
            break;
        }
    }
    fri.emplace_front(f);
}