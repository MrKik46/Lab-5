#include <iostream>


template <typename myType>
struct Element {
    myType data;
    Element<myType>* next;

public:
    Element(myType new_element) {
        data = new_element;
        next = nullptr;
    }

    ~Element() {
        Element<myType>* next;
    }
};


template <typename myType>
class OneList {
private:
    Element<myType>* begin;
    Element<myType>* end;
    int list_size;

public:
    OneList() : begin(nullptr), end(nullptr), list_size(0) {}
    ~OneList() {
        list_size = 0;
        begin->~Element();
        end->~Element();
    }

    myType& operator[](int index) {
        int counter = 0;
        Element<myType>* current_element = begin;
        if (list_size > 1) {
            if (index == -1) {
                while (current_element != nullptr) {
                    if (counter == list_size - 1) {
                        return current_element->data;
                    }
                    current_element = current_element->next;
                    counter++;
                }
            }
            else {
                while (current_element != nullptr) {
                    if (counter == index) {
                        return current_element->data;
                    }
                    current_element = current_element->next;
                    counter++;
                }
            }
        }
        else if (list_size == 1) {
            Element<myType>* current_element = begin;
            return current_element->data;
        }
    }

    void push_front(myType _data) {
        Element<myType>* new_element = new Element<myType>(_data);

        if (begin == nullptr) {
            begin = new_element;
            end = new_element;
        }

        else {
            new_element->next = begin;
            begin = new_element;
        }
        list_size++;

    }

    void push_back(myType _data) {
        Element<myType>* new_element = new Element<myType>(_data);

        if (begin == nullptr) {
            begin = new_element;
            end = new_element;
        }

        else {
            end->next = new_element;
            end = new_element;
        }
        list_size++;
    }

    void pop_front() {
        if (begin != nullptr) {
            Element<myType>* element_to_delete = begin;
            begin = begin->next;
            delete element_to_delete;
            list_size--;
        }

        else {
            throw "List size Error";
        }

    }

    void pop_back() {
        if (begin != nullptr) {
            Element<myType>* point = begin;
            if (point->next != nullptr) {
                while (point->next->next != nullptr) {
                    point = point->next;
                }
            }
            point->next = nullptr;
            delete end;
            end = point;
            list_size--;
        }
    }

    void remove(myType _data) {
        if (end != nullptr) {
            int current_element_index = 0;
            Element<myType>* element = new Element<myType>(_data);
            Element<myType>* current_element = begin;

            if (current_element->data == _data) {
                pop_front();
            }
            else {
                for (int i = 0; i < list_size; i++) {
                    while (current_element->next != nullptr) {
                        if (current_element->next->data == element->data) {
                            if (current_element_index + 2 == list_size) {
                                pop_back();
                                break;
                            }
                            Element<myType>* elemDel = current_element->next;
                            current_element->next = elemDel->next;
                            delete elemDel;
                            list_size--;
                            break;

                        }

                        current_element = current_element->next;
                        current_element_index++;
                    }
                }
            }

        }

        else {
            throw "List size Error";
        }
    }

    void insert(int position, myType _data) {
        if (position == list_size) {
            push_back(_data);
        }
        else if (position == 0) {
            push_front(_data);
        }
        else if (position < list_size) {
            Element<myType>* new_element = new Element<myType>(_data);
            Element<myType>* previos_element = begin;
            int counter = 1;
            while (counter != position) {
                counter++;
                previos_element = previos_element->next;
            }
            new_element->next = previos_element->next;
            previos_element->next = new_element;
            list_size++;
        }
    }

    int size() {
        return list_size;
    }

    Element<myType>* front() {
        return begin;
    }

    Element<myType>* back() {
        return end;
    }

    bool empty() {
        if (list_size == 0) return true;
        return false;
    }
};
