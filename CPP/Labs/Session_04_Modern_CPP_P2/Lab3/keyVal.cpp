#include <iostream>
#include <array>

template <typename Key_t, typename Value_t>
class KeyValuePair
{
private:
    Key_t key;
    Value_t value;

public:
    KeyValuePair() = delete;

    KeyValuePair(Key_t k, Value_t v) : key(k), value(v)
    {
    }

    void setKey(Key_t k)
    {
        key = k;
    }

    void setValue(Value_t v)
    {
        value = v;
    }

    Key_t getKey()
    {
        return key;
    }

    Value_t getValue()
    {
        return value;
    }

    void setPairs(Key_t k, Value_t v)
    {
        key = k;
        value = v;
    }

    void printPair()
    {
        std::cout << "key: " << key << ", value: " << value << std::endl;
    }
};

int main(void)
{

    // One pair
    std::cout << "*** One Pair ***" << std::endl;

    KeyValuePair<std::string, int> p("key name", 0);

    p.setKey("A");
    p.setValue(10);

    std::cout << "key: " << p.getKey() << ", value: " << p.getValue() << std::endl;

    return 0;
}