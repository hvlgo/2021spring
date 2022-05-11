#include "myfriend.h"

auto splitstring(const std::string & str, const std::string & pattern)
{
    std::deque<std::string> v;
    std::string tmp = str;
    auto pos = str.find(pattern);
    while (pos != tmp.npos)
    {
        v.emplace_front(tmp.substr(0, pos));
        tmp = tmp.substr(pos + 1, tmp.npos);
        pos = tmp.find(pattern);
    }
    v.push_front(tmp);
    return v;
    //std::regex RegPartten(partten);
    //return std::vector<std::string>(std::sregex_token_iterator(src.cbegin(), src.cend(), RegPartten, -1), std::sregex_token_iterator());

}
myfriend::myfriend(int number, const std::string & message) : id(number)
{
    chat = splitstring(message, "/");
}

void myfriend::addmessage(const std::string & str)
{
    chat.emplace_front(str);
}

int myfriend::getid() const
{
    return id;
}
std::ostream & operator << (std::ostream & os, const myfriend & f)
{
    os << f.id << std::endl;
    for (auto i : f.chat)
    {
        os << i << std::endl;
    }
    return os;
}