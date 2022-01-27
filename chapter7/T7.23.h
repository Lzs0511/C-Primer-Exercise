#include<string>

class Screen
{
    public:
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos h, pos w): height(h), width(w), contents(h*w, ' '){}
    Screen(pos h, pos w, char c): height(h), width(w), contents(h*w, c){}
    std::string get() const;
    std::string get(pos h, pos w) const;
    private:
    pos height = 0;
    pos width = 0;
    std::string contents;
    pos cursor = 0;
};
std::string Screen::get() const
{
    return contents[cursor];
}
std::string Screen::get(pos r, pos c) const
{
    return contents[r * width + c];
}
