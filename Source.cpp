#include <iostream>
using namespace std;


template<typename T>
class Spysok
{
public:
    Spysok();
    ~Spysok();
    void input() { return data; }
    void goto_back(T value);
    void goto_front(T value);
    void pop_front();
    void pop_back();
    void output();


private:
    template<typename T>
    struct Noda
    {
        Noda* next;
        Noda* previous;
        T data;

        Noda(T data = T(), Noda* pnext = nullptr, Noda* pprev = nullptr)
        {
            this->data = data;
            this->previous = pprev;
            this->next = pnext;
        }
    };

    Noda<T>* list_beg;
    Noda<T>* list_end;
    int node_count;
};


int main()
{
    Spysok<int> list;
    Spysok<double> list2;
    Spysok<char> list3;
    Spysok<string> list4;

    list.goto_back(1);
    list.pop_back();
    list.goto_front(18);
    list.goto_back(2);
    list.goto_front(2);
    list.pop_front();
    list.output();
    cout << endl;
    list2.goto_back(11.1);
    list2.goto_front(43.1);
    list2.pop_back();
    list2.goto_back(33.3);
    list2.goto_back(15.5);
    list2.output();
    cout << endl;
    list3.goto_back('b');
    list3.goto_front('c');
    list3.pop_back();
    list3.goto_back('a');
    list3.goto_front('d');
    list3.output();
    cout << endl;
    list4.goto_back("Hello World!");
    list4.goto_back("gjwp");
    list4.goto_front("pineapple pizza");
    list4.pop_back();
    list4.output();
}

template<typename T>
Spysok<T>::Spysok()
{
    node_count = 0;
    list_beg = nullptr;
    list_end = nullptr;
}

template<typename T>
Spysok<T>::~Spysok()
{
    Noda<T>* ptr;
    for (ptr = list_beg->next; ptr != nullptr; ptr = ptr->next)
    {
        if (node_count == 1)
        {
            break;
        }
        delete ptr->previous;
    }
    delete ptr;
}

template<typename T>
void Spysok<T>::goto_back(T data)
{
    if (list_beg == nullptr)
    {
        list_end = list_beg = new Noda<T>(data);
    }
    else
    {
        Noda<T>* new_node = new Noda<T>(data, nullptr, list_end);
        list_end->next = new_node;
        list_end = new_node;
    }
    node_count++;
}

template<typename T>
void Spysok<T>::goto_front(T data)
{
    if (list_beg == nullptr)
    {
        list_end = list_beg = new Noda<T>(data);
    }
    else
    {
        Noda<T>* new_node = new Noda<T>(data, list_beg);
        list_beg->previous = new_node;
        list_beg = new_node;
    }
    node_count++;
}

template<typename T>
void Spysok<T>::pop_back()
{
    if (list_end == nullptr)
    {
        return;
    }
    if (list_end->previous != nullptr)
    {
        list_end = list_end->previous;
        delete list_end->next;
        list_end->next = nullptr;
    }
    else
    {
        delete list_end;
        list_beg = list_end = nullptr;
    }
}

template<typename T>
void Spysok<T>::pop_front()
{
    if (list_beg == nullptr)
    {
        return;
    }
    if (list_beg->next != nullptr)
    {
        list_beg = list_beg->next;
        delete list_beg->previous;
        list_beg->previous = nullptr;
    }
    else
    {
        delete list_beg;
        list_end = list_beg = nullptr;
    }
}

template<typename T>
void Spysok<T>::output()
{
    Noda<T>* p;
    for (p = list_beg; p != nullptr; p = p->next)
    {
        cout << p->data << endl;
    }
}
