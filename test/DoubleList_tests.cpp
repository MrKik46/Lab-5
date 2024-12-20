#include "DoubleList.cpp"
#include "catch.hpp"

TEST_CASE("Double List Constructor") {
    DoubleList<int> TestList;
    REQUIRE(TestList.back() == nullptr);
    REQUIRE(TestList.front() == nullptr);
}

TEST_CASE("Double List CopyConstr") {
    DoubleList<int> TestList;
    DoubleList<int> TwoList = TestList;
    REQUIRE(TestList.front() == TwoList.front());
    REQUIRE(TestList.back() == TwoList.back());
}

TEST_CASE("Double List Destructor") {
    DoubleList<int> TestList;
    TestList.push_back(1);
    TestList.push_back(2);
    TestList.push_back(3);
    TestList.~DoubleList();
    REQUIRE(TestList[0] != 1);
    REQUIRE(TestList[1] != 2);
    REQUIRE(TestList[2] != 3);
    REQUIRE(TestList.size() == 0);
}

TEST_CASE("Double List Push front") {
    DoubleList<int> TestList;
    TestList.push_front(2);
    REQUIRE(TestList.front()->data == 2);
    REQUIRE(TestList.front()->next == nullptr);
    TestList.push_front(3);
    REQUIRE(TestList.front()->data == 3);
    REQUIRE(TestList.front()->next->data == 2);
}

TEST_CASE("Double List Push back") {
    DoubleList<int> TestList;
    TestList.push_back(2);
    REQUIRE(TestList.back()->data == 2);
    REQUIRE(TestList.back()->next == nullptr);
    TestList.push_back(3);
    REQUIRE(TestList.back()->data == 3);
    REQUIRE(TestList.front()->data == 2);
}

TEST_CASE("Double List Insert ") {
    DoubleList<int> TestList;
    TestList.insert(0, 2);
    REQUIRE(TestList.front()->data == 2);
    TestList.insert(1, 4);
    REQUIRE(TestList.back()->data == 4);
    TestList.insert(1, 5);
    REQUIRE(TestList[1] == 5);
}

TEST_CASE("Double List Pop_front") {
    DoubleList<int> TestList;
    TestList.push_front(2);
    TestList.push_front(3);
    TestList.pop_front();
    REQUIRE(TestList.front()->data == 2);
}

TEST_CASE("Double List Pop_back") {
    DoubleList<int> TestList;
    TestList.push_back(2);
    TestList.push_back(3);
    TestList.pop_back();
    REQUIRE(TestList.back()->data == 2);
}

TEST_CASE("Double List Remove ") {
    DoubleList<int> TestList;
    TestList.push_back(2);
    TestList.push_back(3);
    TestList.push_back(4);
    TestList.push_back(5);
    TestList.remove(5);
    REQUIRE(TestList.back()->data == 4);
    TestList.push_back(4);
    TestList.push_back(2);
    TestList.push_back(3);
    TestList.remove(4);
    REQUIRE(TestList.front()->data == 2);
}

TEST_CASE("Double List Front ") {
    DoubleList<int> TestList;
    REQUIRE(TestList.front() == nullptr);
    TestList.push_front(2);
    REQUIRE(TestList.front()->data == 2);
}

TEST_CASE("Double List Back ") {
    DoubleList<int> TestList;
    REQUIRE(TestList.back() == nullptr);
    TestList.push_back(2);
    REQUIRE(TestList.back()->data == 2);
}

TEST_CASE("Double List Size ") {
    DoubleList<int> TestList;
    REQUIRE(TestList.size() == 0);
    TestList.push_back(3);
    TestList.push_back(2);
    TestList.push_back(4);
    REQUIRE(TestList.size() == 3);
}

TEST_CASE("Double List Operator []") {
    DoubleList<int> TestList;
    bool flag = 0;
    try {
        TestList[0];
    }
    catch (...) {
        flag = 1;
    }
    REQUIRE(!flag);
    TestList.push_back(3);
    TestList.push_back(2);
    TestList.push_back(4);
    REQUIRE(TestList[1] == 2);
}

TEST_CASE("Double List Empty") {
    DoubleList<int> TestList;
    REQUIRE(TestList.empty() == 1);
    TestList.push_back(2);
    REQUIRE(TestList.empty() == 0);
}

TEST_CASE("1. Множественные добавления и удаления Double List") {
    DoubleList<int> TestList;
    for (int i = 0; i < 100000; i++) {
        TestList.push_back(i);
        REQUIRE(TestList.size() == i + 1);
        REQUIRE(TestList.back()->data == i);
    }

    REQUIRE(TestList[0] == 0);
    REQUIRE(TestList[100] == 100);
    REQUIRE(TestList[256] == 256);
    REQUIRE(TestList[99999] == 99999);

    for (int i = 99999; i > 0; i--) {
        TestList.pop_back();
        REQUIRE(TestList.size() == i);
        REQUIRE(TestList.back()->data == i - 1);
        REQUIRE(TestList.front()->data == 0);
    }

    TestList.pop_back();
    REQUIRE(TestList[0] != 0);
    REQUIRE(TestList.back()->data != 0);
    REQUIRE(TestList.front()->data != 0);
    REQUIRE(TestList.size() == 0);
}


TEST_CASE("2. Высвобождение ресурсов памяти Double List") {
    DoubleList<int> TestList;
    TestList.push_back(1);
    TestList.push_back(2);
    TestList.push_back(3);
    TestList.push_back(4);

    for (int i = 0; i < 5; i++) {
        TestList.~DoubleList();
    }

    REQUIRE(TestList[2] != 3);
}

TEST_CASE("3. Краевые случаи Double List") {
    DoubleList<int> TestList;
    REQUIRE(TestList.size() == 0);

    TestList.push_back(1);
    REQUIRE(TestList.size() == 1);
    REQUIRE(TestList[0] == 1);
    REQUIRE(TestList.back()->data == 1);
    REQUIRE(TestList.front()->data == 1);

    TestList.pop_back();
    REQUIRE(TestList.size() == 0);
    REQUIRE(TestList[0] != 1);
    REQUIRE(TestList.back()->data != 1);
    REQUIRE(TestList.front()->data != 1);
}

TEST_CASE("4. Обработка исключений Double List") {
    DoubleList<int> TestList;
    TestList.push_back(1);
    TestList.remove(2);
}

TEST_CASE("5. Комплексная проверка списка Double List") {
    DoubleList<int> TestList;
    int arr_1[5] = { 1, 2, 3, 4, 5 };
    int arr_2[4] = { 2, 3, 4, 5 };
    int arr_3[5] = { 6, 2, 3, 4, 5 };

    TestList.push_back(1);
    TestList.push_back(2);
    TestList.push_back(3);
    TestList.push_back(4);
    TestList.push_back(5);

    for (int i = 0; i < TestList.size(); i++) {
        REQUIRE(TestList[i] == arr_1[i]);
    }
    REQUIRE(TestList.size() == 5);

    TestList.remove(1);

    for (int i = 0; i < TestList.size(); i++) {
        REQUIRE(TestList[i] == arr_2[i]);
    }
    REQUIRE(TestList.size() == 4);

    TestList.push_front(6);

    for (int i = 0; i < TestList.size(); i++) {
        REQUIRE(TestList[i] == arr_3[i]);
    }
    REQUIRE(TestList.size() == 5);
}
