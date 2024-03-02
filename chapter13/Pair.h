#ifndef PAIR_H
#define PAIR_H

template<class T>
class Pair {
    T m_b;

public:
    explicit Pair(const T& value) : m_b(value) {}

    virtual T& second() { return m_b; }

    virtual ~Pair() = default;
};

template<class T>
class StringValuePair : public Pair<T> {
    std::string m_string;

public:
    StringValuePair(const std::string& string, const T& value)
        : Pair<T>(value), m_string(string) {}

    std::string& first() { return m_string; }
};


#endif //PAIR_H
