#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Screen;
class Window_mgr
{
    public:
    using ScreenIndex = std::string::size_type;
    
    void clear(ScreenIndex idx);

    private:
    // 初始化
    std::vector<Screen> screens;
};

class Screen
{
public:
    friend void Window_mgr::clear(ScreenIndex idx);
    
    typedef std::string::size_type pos;
    Screen() = default;
    Screen(pos h, pos w) : height(h), width(w), contents(h * w, ' ') {}
    Screen(pos h, pos w, char c) : height(h), width(w), contents(h * w, c) {}
    char get() const;
    char get(pos h, pos w) const;
    Screen move(pos r, pos c);
    Screen set(char c);
    Screen display(std::ostream &os);
    const Screen display(std::ostream &os) const;
    void do_display(std::ostream &os) const;
    pos size() const;

private:
    pos height = 0;
    pos width = 0;
    std::string contents;
    pos cursor = 0;
};
char Screen::get() const
{
    return contents[cursor];
}
char Screen::get(pos r, pos c) const
{
    return contents[r * width + c];
}

Screen Screen::move(pos r, pos c)
{
    cursor = r * width + c;
    return *this;
}
Screen Screen::set(char c)
{
    contents[cursor] = c;
    return *this;
}
Screen Screen::display(std::ostream &os)
{
    do_display(os);
    return *this;
}
const Screen Screen::display(std::ostream &os) const
{
    do_display(os);
    return *this;
}
inline void Screen::do_display(std::ostream &os) const
{
    os << this->contents;
}

inline Screen::pos Screen::size() const
{
    return height * width;
}


void Window_mgr::clear(ScreenIndex idx)
{
    
    Screen &s = screens[idx];
    s.contents = string(s.height * s.width, ' ');
}

int main()
{
    Screen s;
    Window_mgr mgr;
    // mgr.clear(1);
}