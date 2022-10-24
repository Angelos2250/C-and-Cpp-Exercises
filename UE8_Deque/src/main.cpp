#include "deque.h"
#include <iostream>
#include <numeric> //for accumulate
#include <algorithm> //for max_element

static void test_deque_Constructors() {
    std::cout << std::endl;
    std::cout << "--------- deque(10) -------------" << std::endl;
    swo::deque<int> d1(10);
    for (int n = 0; n < d1.size(); n++) {
        std::cout << d1[n] << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------- deque(10,11) -------------" << std::endl;
    swo::deque<int> d2(10,11);
    for (int n = 0; n < d2.size(); n++) {
        std::cout << d2[n] << ' ';
    }
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "--------- deque Copy Constructor deque d3 = d2; -------------" << std::endl;
    swo::deque<int> d3 = d2;
    for (int n = 0; n < d3.size(); n++) {
        std::cout << d3[n] << ' ';
    }
    std::cout << std::endl;
}

static void test_deque_operator() {
    std::cout << "init deque with init list and print: ";
    swo::deque<int> d1{ 23, 38, 14, -3, 1, 14, 9, 103, -56, 0 };
    for (int n = 0; n < d1.size(); n++) {
        std::cout << d1[n] << ' ';
    }
    std::cout << std::endl;
    std::cout << "init deque2 with init list and print: ";
    swo::deque<int> d2{ 23, 38, 14, -3, 1, 14, 9, 103, -56, 0 };
    for (int n = 0; n < d1.size(); n++) {
        std::cout << d1[n] << ' ';
    }
    std::cout << std::endl;
    std::cout << "---------TESTING == OPERATOR: 0 EXPECTED -------------" << std::endl;
    bool test = (d1 == d2);
    std::cout << test << std::endl;
    std::cout << "---------TESTING > OPERATOR: 1 EXPECTED -------------" << std::endl;
    test = (d1 > d2);
    std::cout << test << std::endl;
    std::cout << "---------TESTING <= OPERATOR: 0 EXPECTED -------------" << std::endl;
    test = (d1 <= d2);
    std::cout << test << std::endl;
    std::cout << "---------TESTING [] OPERATOR ON INDEX 2: 14 EXPECTED -------------" << std::endl;
    int test2 = d1[2];
    std::cout << test2 << std::endl;
    std::cout << "---------TESTING = OPERATOR WITH d1 = temp{6,1,2} -------------" << std::endl;
    swo::deque<int> temp = { 6,1,2 };
    d1 = temp;
    for (int n = 0; n < d1.size(); n++) {
        std::cout << d1[n] << ' ';
    }
    std::cout << std::endl;
    std::cout << "---------TESTING = OPERATOR WITH d1 = {4,3,2} -------------" << std::endl;
    d1 = { 4,3,2 };
    for (int n = 0; n < d1.size(); n++) {
        std::cout << d1[n] << ' ';
    }
    std::cout << std::endl;
}

static void test_deque_functions() {
    std::cout << "---------TESTING back() WITH d1 = {6,1,2}: EXPECTING 2 -------------" << std::endl;
    swo::deque<int> temp = { 6,1,2 };
    std::cout << temp.back() << std::endl;
    std::cout << "---------TESTING front() WITH d1 = {6,1,2}: EXPECTING 6 -------------" << std::endl;
    std::cout << temp.front() << std::endl;
    std::cout << "---------TESTING front() and back() after popback WITH d1 = {6,1,2}: EXPECTING 6 and 1 -------------" << std::endl;
    temp.pop_back();
    std::cout << "front: " << temp.front() << std::endl;
    std::cout << "back: " << temp.back() << std::endl;
    std::cout << "---------TESTING front() and back() after popback WITH d1 = {6,1,2} and after push_front(10): EXPECTING 10 and 1 -------------" << std::endl;
    temp.push_front(10);
    std::cout << "front: " << temp.front() << std::endl;
    std::cout << "back: " << temp.back() << std::endl;
    std::cout << "---------TESTING at(1) WITH d1 = {10,6,1} : EXPECTING 6 -------------" << std::endl;
    std::cout << "at(1): " << temp.at(1) << std::endl;
    std::cout << "---------TESTING push_back(299) and push_front(399) WITH d1 = {10,6,1} : EXPECTING d1 = {399,10,6,1,299}-------------" << std::endl;
    temp.push_back(299);
    temp.push_front(399);
    for (int n = 0; n < temp.size(); n++) {
        std::cout << temp[n] << ' ';
    }
    std::cout << std::endl;
    std::cout << "---------TESTING pop_back() and pop_front() WITH d1 = {399,10,6,1,299} : EXPECTING d1 = {10,6,1}-------------" << std::endl;
    temp.pop_back();
    temp.pop_front();
    for (int n = 0; n < temp.size(); n++) {
        std::cout << temp[n] << ' ';
    }
    std::cout << std::endl;
    std::cout << "---------TESTING clear WITH d1 = {10,6,1} : EXPECTING d1 = {}-------------" << std::endl;
    temp.clear();
    for (int n = 0; n < temp.size(); n++) {
        std::cout << temp[n] << ' ';
    }

}

int main() {
    test_deque_Constructors();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    test_deque_operator();
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    test_deque_functions();
}