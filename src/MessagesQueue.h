#ifndef HIGHLOADCUP_MESSAGESQUEUE_H
#define HIGHLOADCUP_MESSAGESQUEUE_H

#include <queue>
#include <map>

class MessagesQueue;

template<typename T>
T& singleton();

template<>
MessagesQueue& singleton<MessagesQueue>();

class Message {
public:
    Message(const std::string &dest_, const std::string &message_);

    std::string dest() const;
    std::string message() const;
    uint64_t id() const;

private:
    std::string dest_;
    std::string message_;
    uint64_t id_;
};

class MessagesQueue {
public:
    void addMessage(const Message&);
    bool hasNext(const std::string& user) const;
    Message getNext(const std::string& user);

private:
    MessagesQueue();
    std::map<std::string, std::queue<Message>> messagesContainer_;

    friend MessagesQueue& singleton<MessagesQueue>();
};



#endif //HIGHLOADCUP_MESSAGESQUEUE_H
