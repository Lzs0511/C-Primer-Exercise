#ifndef MESSAGE_FOLDER_H
#define MESSAGE_FOLDER_H
#include<set>
#include<string>
#include<iostream>
class Folder;
class Message{
    friend void swap(Message &lhs, Message &rhs);
public:
    explicit Message(const std::string & s = ""):content(s){}
    void save(Folder &f);
    void remove(Folder &f);
    Message(const Message &rhs);
    // 移动构造函数
    Message(Message &&rhs);
    // 移动赋值运算符
    Message &operator=(Message &&rhs);
    Message &operator=(const Message &rhs);
    ~Message();
private:
    std::string content;
    std::set<Folder *> folders;
    void add_msg_Folders(const Message &msg);
    void rem_from_Folders();
    void move_folders(Message *msg);
};
class Folder{
public:
    explicit Folder(const std::string &s = ""):name(s){}
    void addmsg(Message *msg);
    void remmsg(Message *msg);
private:
    std::string name;
    std::set<Message *> messages;
};

void Message::save(Folder &f){
    folders.insert(&f);
    f.addmsg(this);
}
void Message::remove(Folder &f){
    folders.erase(&f);
    f.remmsg(this);
}
void Message::add_msg_Folders(const Message &msg){
    for(auto tmp: folders){
        tmp->addmsg(this);
    }
}
void Message::rem_from_Folders(){
    for(auto tmp: folders){
        tmp->remmsg(this);
    }
}
Message::Message(const Message &msg):content(msg.content), folders(msg.folders){
    add_msg_Folders(msg);
}
Message &Message::operator=(const Message &msg){
    rem_from_Folders();
    this->content = msg.content;
    this->folders = msg.folders;
    add_msg_Folders(msg);
    return *this;
}
Message::~Message(){
    rem_from_Folders();
}

void Folder::addmsg(Message *msg){
    messages.insert(msg);
}
void Folder::remmsg(Message *msg){
    messages.erase(msg);
}

void swap(Message &lhs, Message &rhs){
    using std::swap;
    swap(lhs.content, rhs.content);
    for(auto tmp: lhs.folders){
        tmp->remmsg(&lhs);
    }
    for(auto tmp: rhs.folders){
        tmp->remmsg(&rhs);
    }
    swap(lhs.folders, rhs.folders);
    for(auto tmp: lhs.folders){
        tmp->addmsg(&lhs);
    }
    for(auto tmp: rhs.folders){
        tmp->addmsg(&rhs);
    }
}
// 移动构造函数
Message::Message(Message &&rhs){
    content = std::move(rhs.content);
    move_folders(&rhs);

}
// 移动赋值运算符
Message &Message::operator=(Message &&rhs){
    if(this != &rhs){
        rem_from_Folders();
        content = std::move(rhs.content);
        
    }
    return *this;
}

void Message::move_folders(Message *msg){
    folders = std::move(msg->folders);
    // 在Folder中去掉源Message
    for(auto f: msg->folders){
        f->remmsg(msg);
        f->addmsg(this);
    }
    msg->folders.clear();
}


#endif