#ifndef WELCOME_H
#define WELCOME_H


class Welcome {
    char *m_data;

public:
    Welcome() {
        m_data = new char[14];
        const char *init = "Hello, World!";
        for (int i = 0; i < 14; ++i) m_data[i] = init[i];
    }

    ~Welcome() {
        delete[] m_data;
        m_data = nullptr;
    }

    void print() const;
};


#endif //WELCOME_H
