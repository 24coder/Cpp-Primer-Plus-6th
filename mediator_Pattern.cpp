#include <iostream>
#include <string>
#include <map>

// 抽象中介者
class Mediator {
public:
    virtual void send(const std::string& message, const std::string& colleagueName) = 0;
};

// 抽象同事类
class Colleague {
protected:
    Mediator* mediator_;
public:
    Colleague(Mediator* mediator) : mediator_(mediator) {}
    virtual void send(const std::string& message) = 0;
    virtual void receive(const std::string& message) = 0;
};

// 具体中介者
class ChatRoom : public Mediator {
private:
    std::map<std::string, Colleague*> colleagues_;
public:
    void registerColleague(const std::string& name, Colleague* colleague) {
        colleagues_[name] = colleague;
    }
    void send(const std::string& message, const std::string& colleagueName) override {
        for (auto& it : colleagues_) {
            if (it.first != colleagueName) {
                it.second->receive(message);
            }
        }
    }
};

// 具体同事类
class User : public Colleague {
private:
    std::string name_;
public:
    User(Mediator* mediator, const std::string& name) : Colleague(mediator), name_(name) {}
    void send(const std::string& message) override {
        std::cout << name_ << " sends: " << message << std::endl;
        mediator_->send(message, name_);
    }
    void receive(const std::string& message) override {
        std::cout << name_ << " receives: " << message << std::endl;
    }
    std::string getname(){
        return name_;
    }
};

int main() {
    ChatRoom chatRoom;

    User user1(&chatRoom, "Alice");
    User user2(&chatRoom, "Bob");
    User user3(&chatRoom, "Charlie");

    chatRoom.registerColleague(user1.getname(), &user1);
    chatRoom.registerColleague(user2.getname(), &user2
    
    );
    chatRoom.registerColleague(user3.getname(), &user3);

    user1.send("Hi, Bob!");
    user2.send("Hello, Alice!");



}