/*
Part C:

Bug 1 output: memory leak

==12345== HEAP SUMMARY:
==12345==     in use at exit: 96 bytes in 3 blocks
==12345==   total heap usage: 3 allocs, 0 frees, 96 bytes allocated
==12345==
==12345== 96 bytes in 3 blocks are definitely lost in loss record 1 of 1
==12345==    at 0x4C2E80F: operator new(unsigned long)
==12345==    by 0x400XXX: NodeList::addNode(int, std::string) (PartC.cpp:123)
==12345==    by 0x400XXX: main (PartC.cpp:151)
==12345==
==12345== LEAK SUMMARY:
==12345==    definitely lost: 96 bytes in 3 blocks
==12345==    indirectly lost: 0 bytes in 0 blocks
==12345==      possibly lost: 0 bytes in 0 blocks
==12345==    still reachable: 0 bytes in 0 blocks
==12345==         suppressed: 0 bytes in 0 blocks

Bug 2 output: double free

=================================================================
==21653==ERROR: AddressSanitizer: attempting double-free on 0x604000000510 in thread T0:
    #0 0x000100917b0c in _ZdlPv+0x74 (libclang_rt.asan_osx_dynamic.dylib:arm64e+0x4bb0c)
    #1 0x0001000b8974 in main PartC.cpp:98
    #2 0x000182fc5d50  (<unknown module>)

0x604000000510 is located 0 bytes inside of 40-byte region [0x604000000510,0x604000000538)
freed by thread T0 here:
    #0 0x000100917b0c in _ZdlPv+0x74 (libclang_rt.asan_osx_dynamic.dylib:arm64e+0x4bb0c)
    #1 0x0001000b8950 in main PartC.cpp:97
    #2 0x000182fc5d50  (<unknown module>)

previously allocated by thread T0 here:
    #0 0x0001009176e4 in _Znwm+0x74 (libclang_rt.asan_osx_dynamic.dylib:arm64e+0x4b6e4)
    #1 0x0001000b888c in main PartC.cpp:96
    #2 0x000182fc5d50  (<unknown module>)

SUMMARY: AddressSanitizer: double-free PartC.cpp:98 in main
==21653==ABORTING
zsh: abort      ./partC

Bug 3 output: use after free

=================================================================
==22565==ERROR: AddressSanitizer: heap-use-after-free on address 0x60400000052f at pc 0x0001022e6280 bp 0x00016db1aa10 sp 0x00016db1aa08
READ of size 1 at 0x60400000052f thread T0
    #0 0x0001022e627c in std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ne190102]() const string:1881
    #1 0x0001022e61d4 in std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__get_pointer[abi:ne190102]() const string:2009
    #2 0x0001022e5f08 in std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::data[abi:ne190102]() const string:1705
    #3 0x0001022e4a38 in std::__1::basic_ostream<char, std::__1::char_traits<char>>& std::__1::operator<<[abi:ne190102]<char, std::__1::char_traits<char>, std::__1::allocator<char>>(std::__1::basic_ostream<char, std::__1::char_traits<char>>&, std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>> const&) basic_ostream.h:758
    #4 0x0001022e4974 in main PartC.cpp:122
    #5 0x000182fc5d50  (<unknown module>)

0x60400000052f is located 31 bytes inside of 40-byte region [0x604000000510,0x604000000538)
freed by thread T0 here:
    #0 0x000102c7fb0c in _ZdlPv+0x74 (libclang_rt.asan_osx_dynamic.dylib:arm64e+0x4bb0c)
    #1 0x0001022e4950 in main PartC.cpp:121
    #2 0x000182fc5d50  (<unknown module>)

previously allocated by thread T0 here:
    #0 0x000102c7f6e4 in _Znwm+0x74 (libclang_rt.asan_osx_dynamic.dylib:arm64e+0x4b6e4)
    #1 0x0001022e488c in main PartC.cpp:120
    #2 0x000182fc5d50  (<unknown module>)

SUMMARY: AddressSanitizer: heap-use-after-free string:1881 in std::__1::basic_string<char, std::__1::char_traits<char>, std::__1::allocator<char>>::__is_long[abi:ne190102]() const
Shadow bytes around the buggy address:
  0x604000000280: fa fa 00 00 00 00 00 07 fa fa 00 00 00 00 00 00
  0x604000000300: fa fa 00 00 00 00 00 00 fa fa 00 00 00 00 00 00
  0x604000000380: fa fa 00 00 00 00 00 05 fa fa fd fd fd fd fd fd
  0x604000000400: fa fa fd fd fd fd fd fd fa fa fd fd fd fd fd fd
  0x604000000480: fa fa fd fd fd fd fd fd fa fa fd fd fd fd fd fd
=>0x604000000500: fa fa fd fd fd[fd]fd fa fa fa fa fa fa fa fa fa
  0x604000000580: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x604000000600: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x604000000680: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x604000000700: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
  0x604000000780: fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa fa
Shadow byte legend (one shadow byte represents 8 application bytes):
  Addressable:           00
  Partially addressable: 01 02 03 04 05 06 07 
  Heap left redzone:       fa
  Freed heap region:       fd
  Stack left redzone:      f1
  Stack mid redzone:       f2
  Stack right redzone:     f3
  Stack after return:      f5
  Stack use after scope:   f8
  Global redzone:          f9
  Global init order:       f6
  Poisoned by user:        f7
  Container overflow:      fc
  Array cookie:            ac
  Intra object redzone:    bb
  ASan internal:           fe
  Left alloca redzone:     ca
  Right alloca redzone:    cb
==22565==ABORTING
(zsh: abort ./partC)

*/

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int id;
    string name;
    ListNode* next;
};

class NodeList {
private:
    ListNode* head;
    int count;
public:
    NodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) {
        ListNode* n = new ListNode{id, name, head};
        head = n;
        count++;
    }

    void removeNode(int id) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }
        if (!curr) return;
        if (prev) prev->next = curr->next;
        else head = curr->next;
        delete curr;
        count--;
    }

    // Bug 1: no desconstructor
    
};

int main() {
    // Bug 1: memory leak
    {
        NodeList list;
        list.addNode(1, "A");
        list.addNode(2, "B");
        list.addNode(3, "C");
        cout << "Bug 1 test: 3 nodes were added" << endl;
    }

    // Bug 2: delete a node twice
    // {
    //     ListNode* n = new ListNode{1, "A", nullptr};
    //     delete n;
    //     delete n; 
    //     cout << "Bug 2 test: node deleted twice" << endl;
    // }

    // Bug 3: access node after deleting it
    // {
    //     ListNode* n = new ListNode{1, "Router-A", nullptr};
    //     delete n;
    //     cout << "Bug 3: trying to access node after deleting: " << n->name << endl;
    // }

    return 0;
}
