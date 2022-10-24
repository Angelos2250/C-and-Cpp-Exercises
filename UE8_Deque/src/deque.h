//       $Id: deque.h 3088 2022-01-16 13:47:45Z p20068 $
//      $URL: https://svn01.fh-hagenberg.at/se/sw/swo3/trunk/Aufgaben/WS21/VZ/deque/deque.h $
// $Revision: 3088 $
//     $Date: 2022-01-16 14:47:45 +0100 (So., 16 Jän 2022) $
//   $Author: p20068 $
//   Creator: Peter Kulczycki
//  Creation: January 16, 2022
// Copyright: (c) 2022 Peter Kulczycki (peter.kulczycki<AT>fh-hagenberg.at)
//   License: This document contains proprietary information belonging to
//            University of Applied Sciences Upper Austria, Campus Hagenberg.
//            It is distributed under the Boost Software License (see
//            https://www.boost.org/users/license.html).
#pragma once

#include <cstddef>
#include <initializer_list>
#include <iterator>
#include <cstdlib>
#include <cassert>
#include <stdexcept>

namespace swo {

    template <typename T>
    class deque final {
    private:
        T* arr{ nullptr };
        size_t capacity{ 10 };
        size_t first{ 0 };
        size_t last{ 0 };

        void resize_cap(size_t count) {
            assert(count > 0);
            if (count > capacity) {
                T* tmp = new T[count];
                for (size_t i = 0 ; i < last; i++) {
                    tmp[i] = std::move(arr[(i + first) % capacity]);
                }
                capacity = count;
                first = 0;
                delete[] arr;
                arr = tmp;
            }
        }
    public:
        using const_reference = T const&;
        using reference = T&;
        using size_type = std::size_t;
        using value_type = T;

        friend bool operator==(deque const& lhs, deque const& rhs) noexcept {
            if (lhs.capacity != rhs.capacity) {
                return false;
            }
            for (size_t i = 0 ; i < lhs.last; i++) {
                if (lhs[(lhs.first + i) % lhs.capacity] == rhs[(rhs.first + i) % rhs.capacity]) {
                    return false;
                }
            }
            return true;
        }

        friend auto operator!=(deque const& lhs, deque const& rhs) noexcept {
            return !(lhs == rhs);
        }

        friend auto operator<(deque const& lhs, deque const& rhs) noexcept {
            size_t min_size{ lhs.last > rhs.last ? rhs.last : lhs.last };
            for (size_t i = 0; i < min_size; i++) {
                if (lhs.arr[(lhs.first + i) % lhs.capacity] != rhs.arr[(rhs.first + i) % rhs.capacity]) {
                    if (lhs.arr[(lhs.first + i) % lhs.capacity] < rhs.arr[(rhs.first + i) % rhs.capacity]) {
                        return true;
                    }
                    else
                        return false;
                }
            }
            if ((lhs.last < rhs.last) && (lhs != rhs))
            {
                return true;
            }
            return false;
        }

        friend auto operator<=(deque const& lhs, deque const& rhs) noexcept {
            return lhs == rhs || lhs < rhs;
        }

        friend auto operator>(deque const& lhs, deque const& rhs) noexcept {
            return (!(lhs < rhs)) && (lhs != rhs);
        }

        friend auto operator>=(deque const& lhs, deque const& rhs) noexcept {
            return lhs == rhs || lhs > rhs;
        }

        friend void swap(deque <T>& a, deque <T>& b) noexcept {
            a.swap(b);
        }

        class iterator final {

        };

        deque() {
            arr = new T[capacity + 1];
        }

        explicit deque(size_type count) {
            capacity = count + 1;
            last = count;
            arr = new T[capacity + 1];
            T val{};
            for (size_t i = 0; i < count; i++)
                arr[i] = val;
        }

        deque(size_type count, T const& value) {
            capacity = count + 1;
            arr = new T[capacity];
            last = count;
            for (std::size_t i{ 0 }; i < last; i++) {
                arr[i] = value;
            }
        }

        deque(deque const& src) {
            capacity = src.capacity;
            last = src.last;
            arr = new T[capacity];
            first = src.first;
            if (src.empty()) {
                return;
            }
            size_t i = 0;
            while (i < last) {
                arr[(first + i) % capacity] = src[(first + i) % capacity];
                i++;
            }
        }

        deque(deque&& src) noexcept {
            swap(*this, src);
        }

        deque(std::initializer_list <T> init) {
            if (init.size() + 1 > capacity) {
                capacity = init.size() + 1;
            }
            arr = new T[capacity];
            for (auto& value : init) {
                push_back(value);
            }
        }

        ~deque() {
            delete[] arr;
        }

        template<typename T>
        void copy(T* dest, T* source, size_t size) {
            for (size_t i = 0; i < size; i++) {
                dest[i] = source[i];
            }
        }

        auto operator = (deque const& src) {
            if (&src != this) {
                delete[] arr;

                capacity = src.capacity;
                first = src.first;
                last = src.last;
                arr = new T[capacity];
                copy(arr, src.arr, capacity);
            }
            return *this;
        }

        auto operator=(deque&& src) noexcept {
            swap(src);
            return *this;
        }

        auto operator=(std::initializer_list <T> init){
            if (init.size() > capacity) {
                delete[] arr;
                capacity = init.size() * 2;
                arr = new T[capacity];
            }

            first = 0;
            last = 0;

            for (T item : init) {
                push_back(item);
            }
        }

        auto operator[](size_type pos) {
            if (pos >= last) {
                throw std::out_of_range("deque<Type>::[] : index is out of range");
            }
            return arr[(first + pos) % capacity];
        }
        auto operator[](size_type pos) const{
            if (pos >= last) {
                throw std::out_of_range("deque<Type>::[] : index is out of range");
            }
            return arr[(first + pos) % capacity];
        }

        auto at(size_type pos) {
            if (pos >= last) {
                throw std::out_of_range("deque<Type>::at : index is out of range");
            }
            return arr[(first + pos) % capacity];
        }
        auto at(size_type pos) const{
            if (pos >= last) {
                throw std::out_of_range("deque<Type>::at : index is out of range");
            }
            return arr[(first + pos) % capacity];
        }
        auto back() const {
            assert(!empty());
            return arr[(first + last - 1) % capacity];
        }
        auto back() {
            assert(!empty());
            return arr[(first + last - 1) % capacity];
        }
        auto front() const {
            assert(!empty());
            return arr[first];
        }
        auto front() {
            assert(!empty());
            return arr[first];
        }

        auto begin() noexcept {
            
        }
        auto end() noexcept {
            
        }

        auto empty() const noexcept {
            return last == 0;
        }
        auto size() const noexcept {
            return last;
        }

        void clear() noexcept {
            first = 0;
            last = 0;
        }

        void push_back(T const& value) {
            if (last + 1 >= capacity) {
                resize_cap(2 * capacity);
            }
            arr[(first + last) % capacity] = value;
            last++;
        }
        void push_back(T&& value) {
            if (last + 1 >= capacity) {
                resize_cap(2 * capacity);
            }
            arr[(first + last) % capacity] = std::move(value);
            last++;
        }
        void pop_back() {
            assert(last > 0);
            last--;
        }

        void push_front(T const& value) {
            if (last + 1 >= capacity) {
                resize_cap(2 * capacity);
            }
            size_t next_first = first == 0 ? capacity - 1 : first - 1;
            arr[next_first] = value;
            first = next_first;
            last++;
        }
        void push_front(T&& value) {
            if (last + 1 >= capacity) {
                resize_cap(2 * capacity);
            }
            size_t next_first = (first == 0 ? capacity - 1 : first - 1);
            arr[next_first] = std::move(value);
            first = next_first;
            last++;
        }
        void pop_front() {
            if (first == capacity - 1) {
                first = 0;
            }
            else {
                first++;
            }
            last--;
        }

        void resize(size_type count) {
            assert(count > 0);
            T val{};
            resize(count, val);
        }

        void resize(size_type count, T const& value) {
            assert(count > 0);
            if (count == last) {
                return;
            }

            if (count > last) {
                if (count + 1 > capacity) {
                    resize_cap(count + 1);
                }
                for (size_t i{ last }; i < count; i++) {
                    arr[i] = value;
                    last++;
                }
            }
            else {
                last = count;
            }
        }

        void swap(deque& other) noexcept {
            std::swap(first, other.first);
            std::swap(last, other.last);
            std::swap(capacity, other.capacity);
            std::swap(arr, other.arr);
        }
    };
}   // namespace swo