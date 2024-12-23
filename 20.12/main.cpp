#include <iostream>
#include <memory>
#include <utility>

// int *f() {
//     return new int(17);
// }
//
// std::unique_ptr<int> g() {
//     return std::make_unique<int> (17);
// }
// int main() {
//     f();
//     g();
//     return 0;
// }


// void sendIn (std::unique_ptr<int> x) {
//
// }


// template<typename T>
// class ForwardList {
// private:
//     struct Node {
//         T data;
//         std::unique_ptr<Node> next;
//     };
//     std::unique_ptr<Node> head;
// public:
//     void Pushfront (const T &elem) {
//         head = std::make_unique<Node>(elem, std::move(head));
//     }
//     void PopFront() {
//         head = std::move(head -> next);
//     }
//     const T &front() const {
//         return head -> data;
//     }
//
//     bool Empty() const {
//         return head ==nullptr;
//     }
// };
//

int main() {
    std::shared_ptr<int> ptr1=std::make_shared<int>(17);
    std::cout<< *ptr1<< "\n";
    std::cout<<ptr1.use_count()<<"\n";

    auto ptr2=ptr1;
    std::cout<< *ptr1<< "\n";
    std::cout<< *ptr2<< "\n";

    std::cout<<ptr1.use_count()<<"\n";
    std::cout<<ptr2.use_count()<<"\n";

    std::shared_ptr<int> ptr3;

    std::cout<<ptr3.use_count()<<"\n";
    ptr3=ptr1;
    std::cout<< *ptr3<< "\n";
    std::cout<<ptr3.use_count()<<"\n";
     return 0;
 }