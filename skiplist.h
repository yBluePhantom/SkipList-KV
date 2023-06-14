#include <vector>

#include <memory>
#include <mutex>


template <typename Key, typename Value>
class Node {
public:
    Node () = default;

    Node (const Key &key, const Value &value, int level = 0) :
        m_key(key), m_value(value), m_level(level) {
        m_next.resize(level + 1);  // 0 ~ level
    }

    Node (Key &&key, Value &&value, int level = 0) :
        m_key(std::move(key)), m_value(std::move(value)), m_level(level) {
        m_next.resize(level + 1);  // 0 ~ level
    }

    ~Node () = default;

    Key key() const {
        return m_key;
    }

    Value value() const {
        return m_value;
    }

private:
    Key m_key;
    Value m_value;

    int m_level; // 当前节点的非 0 层数, 一个节点一定在 0 层存在, 一个节点的非 0 层数是随机的, 用于加快寻找
    std::vector<std::shared_ptr<Node<Key, Value>>> m_next; // 当前节点在不同层次的下一个节点
};


template <typename Key, typename Value>
class SkipList {
public:
    explicit SkipList(int max_level = 0, int level = 0, int cnt = 0): 
        m_head(std::make_shared<Node<Key, Value>>()), m_max_level(max_level), m_level(level), m_cnt(cnt) {}

    ~SkipList() = default;

    // Interface
    bool insert(const Key &key, const Value &value);
    bool insert(Key &&key, Value &&value);

    bool erase(const Key &key);
    bool erase(Key &&key);

    bool find(const Key &key);
    bool find(Key &&key);

    // Auxiliary
    int size() const {
        return m_cnt;
    }

    void display() const;

private:


private:
    std::shared_ptr<Node<Key, Value>> m_head; // 头节点点指针

    int m_max_level; // 最大层数
    int m_level; // 当前层数
    int m_cnt; // 当前节点数(不包括头节点)
};