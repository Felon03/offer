#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#include "../src/01.h"
#include "../src/02.h"
#include "../src/03.h"
#include "../src/04.h"
#include "../src/05.h"
#include "../src/06.h"
#include "../src/07.h"
#include "../src/08.h"
#include "../src/09.h"
#include "../src/10.h"
#include "../src/11.h"
#include "../src/12.h"
#include "../src/13.h"
#include "../src/14.h"
#include "../src/15.h"
#include "../src/16.h"
#include "../src/17.h"
#include "../src/18.h"
#include "../src/19.h"
#include "../src/20.h"
#include "../src/21.h"
#include "../src/22.h"
#include "../src/23.h"
#include "../src/24.h"
#include "../src/25.h"
#include "../src/26.h"
#include "../src/27.h"
#include "../src/28.h"
#include "../src/29.h"
#include "../src/30.h"
#include "../src/31.h"
#include "../src/32.h"
#include "../src/33.h"
#include "../src/34.h"
#include "../src/35.h"
#include "../src/36.h"
#include "../src/37.h"
#include "../src/38.h"
#include "../src/39.h"
#include "../src/40.h"
#include "../src/41.h"
#include "../src/42.h"
#include "../src/43.h"
#include "../src/44.h"
#include "../src/45.h"
#include "../src/46.h"
#include "../src/47.h"
#include "../src/48.h"
#include "../src/49.h"
#include "../src/50.h"
#include "../src/51.h"
#include "../src/52.h"
#include "../src/53.h"
#include "../src/54.h"
#include "../src/55.h"
#include "../src/56.h"
#include "../src/57.h"
#include "../src/58.h"
#include "../src/59.h"
#include "../src/60.h"
#include "../src/61.h"
#include "../src/62.h"
#include "../src/63.h"
#include "../src/64.h"
#include "../src/65.h"

using std::cout;
using std::endl;
using std::string;
using std::vector;

static void test_01()
{
    Solution01 s;
    vector<vector<int>> matrix{
        {1, 2, 8, 9},
        {2, 4, 9, 12},
        {4, 7, 10, 13},
        {6, 8, 11, 15}
    };
    int target = 7;
    bool res = s.find(matrix, target);
    cout << "Solution01\n";
    cout << "Expect: true\tActual: " << std::boolalpha << res;
    cout << endl;

    target = 5;
    res = s.find(matrix, target);
    cout << "Expect: false\tActual: " << res;
    cout << endl;
}

static void test_02()
{
    Solution02 s;
    char str[] = "We are happy.";
    size_t len = std::strlen(str);
    s.replace_ws(str, len);
    cout << "Solution02\n";
    cout << "Expect: We\%20are\%20happy.\tActual: " << str;
    cout << endl;

    char str1[] = " How are you ";
    len = std::strlen(str1);
    s.replace_ws(str1, len);
    cout << "Expect: \%20How\%20are\%20you\%20\tActual: " << str1;
    cout << endl;
}

static void test_03()
{
    using list::ListNode;
    Solution03 s;
    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    ListNode* p4 = new ListNode(5);
    
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    
    vector<int> res = s.reverse_print(head);
    cout << "Solution03\n";
    cout << "Expect: 5 4 3 2 1\tActual: ";
    s.print(res);
    cout << endl;

    // delete nodes
    while (head)
    {
        ListNode* tmp = head->next;
        delete head;
        head = nullptr;
        head = tmp;
    }
}

static void test_04()
{
    Solution04 s;
    vector<int> pre{1, 2, 4, 7, 3, 5, 6, 8};
    vector<int> in{4, 7, 2, 1, 5, 3, 8, 6};

    TreeNode* root = s.rebuild_tree(pre, in);
    cout << "Solution04\n";
    cout << "Expect: 1 2 3 4 5 6 7 8\tActual: ";
    // s.print(root);
    level_order(root);
    cout << endl;

    // delete root;
    // s.destroy_tree(root);
    destroy_tree(root);
}

static void test_05()
{
    Queue<int> q;
    Stack<int> s;

    cout << "Solution05\n";
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "Expect: 1 2 3\tActual: ";
    cout << q.pop() << " "
         << q.pop() << " "
         << q.pop() << endl;

    s.push(1);
    s.push(2);
    s.push(3);
    
    cout << "Expect: 3 2 1\tActual: ";
    cout << s.pop() << " "
         << s.pop() << " "
         << s.pop() << endl;
}

static void test_06()
{
    Solution06 s;
    vector<int> v1{3, 4, 5, 1, 2};
    vector<int> v2{1, 0, 1, 1, 1};

    cout << "Solution06\n";

    int res = s.min_number_in_rotate_array(v1);
    cout << "Expect: 1\tActual: ";
    cout << res << endl;

    res = s.min_number_in_rotate_array(v2);
    cout << "Expect: 0\tActual: ";
    cout << res << endl;
}

static void test_07()
{
    Solution07 s;
    
    cout << "Solution07\n";
    auto res = s.fibonacci(10);
    cout << "Expect: 55\tActual: " << res << endl;

    res = s.fibonacci(17);
    cout << "Expect: 1597\tActual: " << res << endl;

    res = s.fibonacci(20);
    cout << "Exepct: 6765\tActual: " << res << endl;
}

static void test_08()
{
    Solution08 s;

    cout << "Solution08\n";
    int res = s.jump_floor(10);
    cout << "Expect: 89\tActual: " << res << endl;

    res = s.jump_floor(15);
    cout << "Expect: 987\tActual: " << res << endl;

    res = s.jump_floor(20);
    cout << "Expect: 10946\tActual: " << res << endl;
}

static void test_09()
{
    Solution09 s;

    cout << "Solution09\n";
    int res = s.jump_floor_ii(10);
    cout << "Expect: 512\tActual: " << res << endl;

    res = s.jump_floor_ii(15);
    cout << "Expect: 16384\tActual: " << res << endl;

    res = s.jump_floor_ii(20);
    cout << "Expect: 524288\tActual: " << res << endl;
}

static void test_10()
{
    Solution10 s;

    cout << "Solution10\n";
    int res = s.rect_cover(10);
    cout << "Expect: 89\tActual: " << res << endl;

    res = s.rect_cover(15);
    cout << "Expect: 987\tActual: " << res << endl;

    res = s.rect_cover(20);
    cout << "Expect: 10946\tActual: " << res << endl;    
}

static void test_11()
{
    Solution11 s;
    cout << "Solution11\n";
    int res = s.number_of_1(1);
    cout << "Expect: 1\tActual: " << res << endl;

    res = s.number_of_1(0);
    cout << "Expect: 0\tActual: " << res << endl;

    res = s.number_of_1(0x7FFFFFFF);
    cout << "Expect: 31\tActual: " << res << endl;

    res = s.number_of_1(0x80000000);
    cout << "Expect: 1\tActual: " << res << endl;

    res = s.number_of_1(0xFFFFFFFF);
    cout << "Expect: 32\tActual: " << res << endl;
}

static void test_12()
{
    Solution12 s;
    cout << "Solution12\n";
    double res = s.power(2.0, 10);
    cout << "Expect: 1024.0\tActual: " << res << endl;

    res = s.power(2.0, 0);
    cout << "Expect: 1.0\tActual: " << res << endl;

    res = s.power(2.0, -2);
    cout << "Expect: 0.25\tActual: " << res << endl;

    res = s.power(2.1, 3);
    cout << "Expect: 9.261\tActual: " << res << endl;
}

static void test_13()
{
    Solution13 s;
    cout << "Solution13\n";
    int n = 0;
    cout << "Expect: \tActual: ";
    s.print_1_to_max_of_n_digits(n);
    cout << endl;
    n = 1;
    cout << "Expect: 1 2 3 4 5 6 7 8 9\tActual: ";
    s.print_1_to_max_of_n_digits(n);
    cout << endl;
    // n = 2;
    // cout << "Expect: 1 2 3 4 ... 97 98 99\tActual: ";
    // s.print_1_to_max_of_n_digits(n);
    // cout << endl; 
}

static void test_14()
{
    using list::ListNode;

    Solution14 s;
    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    ListNode* p4 = new ListNode(5);
    
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    cout << "Solution14\n";
    ListNode* node = new ListNode(4);
    head = s.delete_node(head, node);
    cout << "Expect: 1 2 3 5\tActual: ";
    print_list(head);
    cout << endl;
    delete node;
    node = nullptr;

    node = new ListNode(5);
    head = s.delete_node(head, node);
    cout << "Expect: 1 2 3\tActual: ";
    print_list(head);
    cout << endl;
    delete node;
    node = nullptr;

    destroy_list(head);

    head = new ListNode(1);
    node = new ListNode(1);
    head = s.delete_node(head, node);
    cout << "Expect: \tActual: ";
    print_list(head);
    cout << endl;
    delete head;
    delete node;
    head = nullptr, node = nullptr;
}

static void test_15()
{
    Solution15 s;
    cout << "Solution15\n";

    vector<int> v{1, 2, 3, 4, 5, 6, 7, 8};
    s.stable_reorder_array(v);
    cout << "Expect: 1 3 5 7 2 4 6 8\tActual: ";
    for (const auto &e : v)
        cout << e << " ";
    cout << endl;

    v = {1, 2, 3, 4, 5, 6, 7, 8};
    s.stable_reorder_array(v, [](int a){ return (a & 0x01) != 0; });
    cout << "Expect: 2 4 6 8 1 3 5 7\tActual: ";
    for (const auto &e: v)
        cout << e << " ";
    cout << endl;
}

static void test_16()
{
    using list::ListNode;

    Solution16 s;
    cout << "Solution16\n";

    int k = 3;

    ListNode* tmp = nullptr;
    cout <<"Expect: \tActual: ";
    ListNode* res = s.find_kth_to_tail(tmp, k);
    if (res)
        cout << res->val;
    else
        cout << " ";
    cout << endl;

    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    ListNode* p4 = new ListNode(5);

    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    cout << "Expect: 3\tActual: ";
    res = s.find_kth_to_tail(head, k);
    if (res)
        cout << res->val;
    else
        cout << " ";
    cout << endl;

    k = 2;
    cout << "Expect: 4\tActual: ";
    res = s.find_kth_to_tail(head, k);
    if (res)
        cout << res->val;
    else
        cout << " ";
    cout << endl;

    destroy_list(head);
}

static void test_17()
{
    using list::ListNode;

    Solution17 s;
    cout << "Solution17\n";

    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    ListNode* p4 = new ListNode(5);

    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    ListNode* res = s.reverse_list(head);
    cout << "Expect: 5\tActual: " << res->val << endl;

    head = s.reverse_list_recursive(res);
    cout << "Expect: 1\tActual: " << head->val << endl;

    destroy_list(head);
}

static void test_18()
{
    using list::ListNode;

    Solution18 s;
    cout << "Solution18\n";

    ListNode* l1 = new ListNode(1);
    ListNode* l11 = new ListNode(3);
    ListNode* l12 = new ListNode(5);
    l1->next = l11;
    l11->next = l12;

    ListNode* l2 = new ListNode(2);
    ListNode* l21 = new ListNode(4);
    ListNode* l22 = new ListNode(6);
    l2->next = l21;
    l21->next = l22;

    ListNode* head = s.merge(l1, l2);
    // ListNode* head = s.merge_recursive(l1, l2);
    cout << "Expect: 1 2 3 4 5 6\tActual: ";
    print_list(head);
    cout << endl;

    destroy_list(head);
}

static void test_19()
{
    using tree::TreeNode;

    Solution19 s;
    cout << "Solution19\n";

    TreeNode* root = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(4);
    TreeNode* t4 = new TreeNode(5);
    TreeNode* t5 = new TreeNode(6);
    TreeNode* t6 = new TreeNode(7);

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;
    
    TreeNode* sub_tree = new TreeNode(3);
    TreeNode* s1 = new TreeNode(6);
    TreeNode* s2 = new TreeNode(7);

    sub_tree->left = s1;
    sub_tree->right = s2;
    cout << "Expect: true\tActual: " << s.has_subtree(root, sub_tree) << endl;

    TreeNode* sub = new TreeNode(1);
    TreeNode* sub1 = new TreeNode(2);
    TreeNode* sub2 = new TreeNode(4);

    sub->left = sub1;
    sub->right = sub2;
    cout << "Expect: false\tActual: " << s.has_subtree(root, sub) << endl;    

    destroy_tree(root);
    destroy_tree(sub_tree);
    destroy_tree(sub);
}

static void test_20()
{
    using tree::TreeNode;

    Solution20 s;
    cout << "Solution20\n";

    TreeNode* root = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(4);
    TreeNode* t4 = new TreeNode(5);
    TreeNode* t5 = new TreeNode(6);
    TreeNode* t6 = new TreeNode(7);

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;

    cout << "Expect: 1 2 3 4 5 6 7\tActual: ";
    level_order(root);
    cout << endl;

    s.mirror(root);
    cout << "Expect: 1 3 2 7 6 5 4\tActual: ";
    level_order(root);
    cout << endl;

    destroy_tree(root);
}

static void test_21()
{
    Solution21 s;
    cout << "Solution21\n";

    vector<vector<int>> v{
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}};
    
    vector<int> ret = s.print_matrix(v);
    cout << "Expect: 1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10\tActual: ";
    for (const auto &e : ret)
        cout << e << " ";
    cout << endl;
}

static void test_22()
{
    Stack22<int> s;
    cout << "Solution22\n";

    vector<int> v{3, 4, 2, 1, 0};
    for (const int e : v)
        s.push(e);

    cout << "Expect: 0\tActual: " << s.min() << endl;

    s.pop();
    cout << "Expect: 1\tActual: " << s.min() << endl;

    s.pop();
    cout << "Expect: 2\tActual: " << s.min() << endl;

    s.pop();
    cout << "Expect: 3\tActual: " << s.min() << endl;

    s.pop();
    cout << "Expect: 3\tActual: " << s.min() << endl;
}

static void test_23()
{
    Solution23 s;
    cout << "Solution23\n";

    vector<int> push_v{1, 2, 3, 4, 5};
    vector<int> pop_v{4, 5, 3, 2, 1};
    vector<int> pop_v1{4, 3, 5, 1, 2};

    cout << "Expect: true\tActual: " << s.is_pop_order(push_v, pop_v) << endl;
    cout << "Expect: false\tActual: " << s.is_pop_order(push_v, pop_v1) << endl;
}

static void test_24()
{
    using tree::TreeNode;

    Solution24 s;
    cout << "Solution24\n";

    TreeNode* root = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(4);
    TreeNode* t4 = new TreeNode(5);
    TreeNode* t5 = new TreeNode(6);
    TreeNode* t6 = new TreeNode(7);

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;

    cout << "Expect: 1 2 3 4 5 6 7\tActual: ";
    vector<int> ret = s.level_traverse(root);
    for (const auto& e : ret)
        cout << e << " ";
    cout << endl;

    destroy_tree(root);
}

static void test_25()
{
    Solution25 s;
    cout << "Solution25\n";

    vector<int> v{5, 7, 6, 9, 11, 10, 8};
    cout << "Expect: true\tActual: " << s.verify_sequence_of_bst(v) << endl;

    v = { };
    cout << "Expect: false\tActual: " << s.verify_sequence_of_bst(v) << endl;

    v = {7, 4, 6, 5};
    cout << "Expect: false\tActual: " << s.verify_sequence_of_bst(v) << endl;
}

static void test_26()
{
    using tree::TreeNode;

    Solution26 s;
    cout << "Solution26\n";

    TreeNode* root = new TreeNode(10);
    TreeNode* t1 = new TreeNode(5);
    TreeNode* t2 = new TreeNode(12);
    TreeNode* t3 = new TreeNode(4);
    TreeNode* t4 = new TreeNode(7);

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;

    int val = 22;
    vector<vector<int>> ret = s.find_path(root, val);
    cout << "Expect: 10 5 7 \t10 12\tActual: ";
    for (const auto &v : ret)
    {
        for (const auto &e : v)
            cout << e << " ";
        cout << "\t";
    }
    cout << endl;

}

static void test_27()
{

    using List = ListNode27;

    Solution27 s;
    cout << "Solution27\n";

    List* head = new List(1);
    List* l1 = new List(2);
    List* l2 = new List(3);
    List* l3 = new List(4);
    List* l4 = new List(5);

    head->next = l1;
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;

    head->sibling = l2;
    l1->sibling = l4;
    l3->sibling = l1;

    List* copy = s.clone(head);

    cout << "Expect: 1(3) 2(5) 3(null) 4(2) 5(null)\tActual: ";
    s.print_list(copy);
    cout << endl;

    s.destroy_list(head);
}

static void test_28()
{
    Solution28 s;
    cout << "Solution28\n";

    BinaryTreeNode* root = new BinaryTreeNode(10);
    BinaryTreeNode* t1 = new BinaryTreeNode(6);
    BinaryTreeNode* t2 = new BinaryTreeNode(14);
    BinaryTreeNode* t3 = new BinaryTreeNode(4);
    BinaryTreeNode* t4 = new BinaryTreeNode(8);
    BinaryTreeNode* t5 = new BinaryTreeNode(12);
    BinaryTreeNode* t6 = new BinaryTreeNode(16);

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->left = t5;
    t2->right = t6;

    BinaryTreeNode* head = s.convert(root);
    cout << "Expect: 4 6 8 10 12 14 16\tActual: ";
    s.print_double_list(head);
    cout << endl;

    // destroy_tree(root);
    s.destroy_double_list(head);    
}

static void test_29()
{
    Solution29 s;
    cout << "Solution29\n";

    string str("abc");
    cout << "Expect: abc acb bac bca cab cba\tActual: ";
    vector<string> res = s.permutation(str);
    for (const auto &e : res)
        cout << e << " ";
    cout << endl;
}

static void test_30()
{
    Solution30 s;
    cout << "Solution30\n";

    vector<int> v{1, 2, 3, 2, 2, 2, 5, 4, 2};
    int res = s.more_than_half_num(v);
    cout << "Expect: 2\tActual: " << res << endl;

    v = {1, 2, 3, 2, 2, 4, 5, 1, 4};
    res = s.more_than_half_num(v);
    cout << "Expect: -1\tActual: " << res << endl;
}

static void test_31()
{
    Solution31 s;
    cout << "Solution31\n";

    vector<int> v{4, 5, 1, 6, 2, 7, 3, 8};
    int k = 4;

    vector<int> res = s.get_least_k_nums(v, k);
    cout << "Expect: 1 2 3 4\tActual: ";
    for (const auto &e : res)
        cout << e << " ";
    cout << endl;

    k = 6;
    res = s.get_least_k_nums(v, k);
    cout << "Expect: 1 2 3 4 5 6\tActual: ";
    for (const auto &e : res)
        cout << e << " ";
    cout << endl;
}

static void test_32()
{
    Solution32 s;
    cout << "Solution32\n";

    vector<int> nums{6, -3, -2, 7, -15, 1, 2, 2};
    cout << "Expect: 8\tActual: " << s.maximum_subarray(nums) << endl;

    cout << "Expect: 8\tActual: " << s.maximum_subarray_dp(nums) << endl;
}

static void test_33()
{
    Solution33 s;
    cout << "Solution33\n";

    int n = 534;
    cout << "Expect: 214\tActual: " << s.number_of_1_between_1_and_n(n) << endl;
    n = 514;
    cout << "Expect: 207\tActual: " << s.number_of_1_between_1_and_n(n) << endl;
    n = 530;
    cout << "Expect: 213\tActual: " << s.number_of_1_between_1_and_n(n) << endl;
}

static void test_34()
{
    Solution34 s;
    cout << "Solution34\n";

    vector<int> nums{3, 32, 321};
    cout << "Expect: 321323\tActual: " << s.min_number(nums) << endl;

    nums = {1, 12, 231};
    cout << "Expect: 112231\tActual: " << s.min_number(nums) << endl;

    nums = {13, 12, 114};
    cout << "Expect: 1141213\tActual: " << s.min_number(nums) << endl;
}

static void test_35()
{
    Solution35 s;
    cout << "Solution35\n";

    int n = 1500;
    cout << "Expect: 859963392\tActual: " << s.get_ugly_number(n) << endl;

    n = 1000;
    cout << "Expect: 51200000\tActual: " << s.get_ugly_number(n) << endl;

    n = 386;
    cout << "Expect: 262144\tActual: " << s.get_ugly_number(n) << endl;
}

static void test_36()
{
    Solution36 s;
    cout << "Solution36\n";

    string str = "loveleetcode";
    cout << "Expect: 2\tActual: " << s.first_unique_char(str) << endl;

    str = "leetcode";
    cout << "Expect: 0\tActual: " << s.first_unique_char(str) << endl;
}

static void test_37()
{
    Solution37 s;
    cout << "Solution37\n";

    vector<int> array{7, 5, 6, 4};
    cout << "Expect: 5\tActual: " << s.inverse_pairs(array) << endl;

    array = {7, 4, 5, 6};
    cout << "Expect: 3\tActual: " << s.inverse_pairs(array) << endl;
}

static void test_38()
{
    using list::ListNode;

    Solution38 s;
    cout << "Solution38\n";

    ListNode* l1 = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* l2 = new ListNode(4);
    ListNode* p4 = new ListNode(5);
    ListNode* p6 = new ListNode(6);
    ListNode* p7 = new ListNode(7);
    
    l1->next = p1;
    p1->next = p2;
    p2->next = p6;
    p6->next = p7;

    l2->next = p4;
    p4->next = p6;

    cout << "Expect: 6\tActual: " << s.intersection(l1, l2)->val << endl;
    cout << "Expect: 6\tActual: " << s.get_intersection_node(l1, l2)->val << endl;
    
    p4->next = nullptr;

    destroy_list(l1);
    destroy_list(l2);
}

static void test_39()
{
    Solution39 s;
    cout << "Solution39:\n";

    vector<int> data{1, 2, 3, 3, 3, 3, 4, 5};
    int k = 3;
    cout << "Expect: 4\tActual: " << s.get_num_of_k(data, k) << endl;
    
    data = {1, 2, 3, 3, 4, 4, 4, 5};
    k = 4;
    cout << "Expect: 3\tActual: " << s.get_num_of_k(data, k) << endl;

}

static void test_40()
{
    using tree::TreeNode;

    Solution40 s;
    cout << "Solution40:\n";

    TreeNode* root = new TreeNode(1);
    TreeNode* t1 = new TreeNode(2);
    TreeNode* t2 = new TreeNode(3);
    TreeNode* t3 = new TreeNode(4);
    TreeNode* t4 = new TreeNode(5);
    TreeNode* t5 = new TreeNode(6);
    TreeNode* t6 = new TreeNode(7);

    root->left = t1;
    root->right = t2;
    t1->left = t3;
    t1->right = t4;
    t2->right = t5;
    t4->left = t6;

    cout << "Expect: 4\tActual: " << s.tree_depth(root) << endl;
    cout << "Expect: true\tActual: " << s.is_balanced(root) << endl;

    destroy_tree(root);
    
}

static void test_41()
{
    Solution41 s;
    cout << "Solution41:\n";

    vector<int> nums{1, 2, 1, 3, 2, 5};
    cout << "Expect: 3 5\tActual: ";
    vector<int> res = s.single_number_i(nums);
    for (int num : res)
        cout << num << " ";
    cout << endl;

    cout << "Expect: 3 5\tActual: ";
    res = s.single_number_ii(nums);
    for (int num : res)
        cout << num << " ";
    cout << endl;
}

static void test_42()
{
    Solution42 s;
    cout << "Solution42:\n";

    vector<int> nums{1, 2, 3, 4, 7, 11, 12, 15};
    int k = 15;
    cout << "Expect: 3 12\tActual: ";
    vector<int> ret = s.find_number_with_sum(nums, k);
    for (int num : ret)
        cout << num << " ";
    cout << endl;
    cout << "Expect: 1 2 3 4 5 \t 4 5 6 \t7 8 \tActual: ";
    vector<vector<int>> res = s.find_continuous_seq(k);
    for (const auto v: res)
    {
        for (int num : v)
            cout << num << " ";
        cout << '\t';
    }
    cout << endl;    
}

static void test_43()
{
    Solution43 s;
    cout << "Solution43:\n";

    string str = "I am a student.";
    cout << "Expect: student. a am I\tActual: " << s.reverse_sentence(str) << endl;

    string str1 = "abcdefg";
    int n = 2;
    cout << "Expect: cdefgab\tActual: " << s.left_rotate_str(str1, n) << endl;
}

static void test_44()
{
    Solution44 s;
    cout << "Solution44:\n";
    
    int num_of_dice = 2;
    vector<pair<int, double>> res = s.probability(num_of_dice);
    cout << "Expect: {2, 2.77778}, {3, 5.55556}, {4, 8.33333}, {5, 11.1111}, {6, 13.8889}, "
         << "{7, 16.6667}, {8, 13.8889}, {9, 11.1111}, {10, 8.33333}, {11, 5.55556}, {12, 2.77778}"
         << endl;
    cout << "Actual: ";
    for (size_t i = 0; i < res.size(); ++i)
    {
        if (i == res.size() - 1)
            cout << "{" << res[i].first << ", " << res[i].second << "}" << endl;
        else
            cout << "{" << res[i].first << ", " << res[i].second << "}, ";
    }
    cout << endl;
}

static void test_45()
{
    Solution45 s;
    cout << "Solution45:\n";

    vector<int> nums{0, 0, 1, 2, 4};
    cout << "Expect: true\tActual: " << s.is_continuous(nums) << endl;

    nums = {0, 1, 2, 3, 6};
    cout << "Expect: false\tActual: " << s.is_continuous(nums) << endl;

    nums = {0, 1, 2, 3, 3};
    cout << "Expect: false\tActual: " << s.is_continuous(nums) << endl; 
}

static void test_46()
{
    Solution46 s;
    cout << "Solution46:\n";

    int n = 100, m = 7;
    cout << "Expect: 49\tActual: " << s.last_remaining(n, m) << endl;

    n = 101;
    cout << "Expect: 56\tActual: " << s.last_remaining_recursive(n, m) << endl;
}

static void test_47()
{
    Solution47 s;
    cout << "Solution47:\n";

    int n = 100;
    cout << "Expect: 5050\tActual: " << s.get_sum(n) << endl;
}

static void test_48()
{
    Solution48 s;
    cout << "Solution48:\n";

    int a = 7, b = 9;
    cout << "Expect: 16\tActual: " << s.add(a, b) << endl;

    a = 6, b = 35;
    cout << "Expect: 41\tActual: " << s.add_recursive(a, b) << endl;
}

static void test_49()
{
    Solution49 s;
    cout << "Solution49:\n";

    string str = "     +123456789";
    cout << "Expect: 123456789\tActual: " << s.str_to_int(str) << endl;

    str = "-31415926";
    cout << "Expect: -31415926\tActual: " << s.str_to_int(str) << endl;

    str = "123 345 456";
    cout << "Expect: 0\tActual: " << s.str_to_int(str) << endl;
}

static void test_50()
{
    Solution50 s;
    cout << "Solution50:\n";

    vector<int> nums{2, 3, 1, 0, 2, 5, 3};
    int dup = -1;
    cout << "Expect: true, 2\tActual: " << s.duplicate(nums, dup)
         << ", " << dup << endl;
    
    nums = {1, 2, 3, 4, 5, 6};
    dup = -1;
    cout << "Expect: false, -1\tActual: " << s.duplicate(nums, dup)
         << ", " << dup << endl;
}

static void test_51()
{
    Solution51 s;
    cout << "Solution51:\n";

    vector<int> nums{1, 2, 3, 4, 5, 6};
    vector<int> res = s.multiply(nums);
    cout << "Expect: 720 360 240 180 144 120\tActual: ";
    for (size_t i = 0; i < res.size(); ++i)
    {
        if (i == res.size() - 1)
            cout << res[i] << endl;
        else
            cout << res[i] << " ";
    }
}

static void test_52()
{
    Solution52 s;
    cout << "Solution52:\n";

    char str[] = "aaa";
    char pattern[] = "a.a";
    cout << "Expect: true\tActual: " << s.match(str, pattern) << endl;

    char pattern1[] = "ab*ac*a";
    cout << "Expect: true\tActual: " << s.match(str, pattern1) << endl;

    char pattern2[] = "ab*ac*";
    cout << "Expect: false\tActual: " << s.match(str, pattern2) << endl;
    
}

static void test_53()
{
    Solution53 s;
    cout << "Solution53:\n";
    
    char str[] = "1.234E+10";
    cout << "Expect: true\tActual: " << s.is_numeric(str) << endl;

    char str1[] = "3.1416";
    cout << "Expect: true\tActual: " << s.is_numeric(str1) << endl;

    char str2[] = ".123";
    cout << "Expect: false\tActual: " << s.is_numeric(str2) << endl;
}

static void test_54()
{
    Solution54 s;
    cout << "Solution54:\n";

    string str = "google";
    cout << "Expect: g g g # l l\tActual: ";
    for (size_t i = 0; i < str.size(); ++i)
    {
        s.insert(str[i]);
        if (i == str.size() - 1)
            cout << s.first_appearing_once() << endl;
        else
            cout << s.first_appearing_once() << " ";
    }
}

static void test_55()
{
    using list::ListNode;
    Solution55 s;
    cout << "Solution55:\n";

    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(4);
    ListNode* p4 = new ListNode(5);
    ListNode* p5 = new ListNode(6);
    ListNode* p6 = new ListNode(7);
    ListNode* p7 = new ListNode(8);
    ListNode* p8 = new ListNode(9);
    ListNode* p9 = new ListNode(10);
    
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;
    p7->next = p8;
    p8->next = p9;
    p9->next = p4;

    cout << "Expect: 5\tActual: " << s.detect_cycle(head)->val << endl;

    p9->next = p5;
    cout << "Expect: 6\tActual: " << s.detect_cycle(head)->val << endl;
    
    p9->next = nullptr;

    destroy_list(head);    
}

static void test_56()
{
    using list::ListNode;
    Solution56 s;
    cout << "Solution56:\n";

    ListNode* head = new ListNode(1);
    ListNode* p1 = new ListNode(2);
    ListNode* p2 = new ListNode(3);
    ListNode* p3 = new ListNode(3);
    ListNode* p4 = new ListNode(4);
    ListNode* p5 = new ListNode(4);
    ListNode* p6 = new ListNode(5);

    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    s.remove_duplicates(head);
    cout << "Expect: 1 2 5\tActual: ";
    print_list(head);
    cout << endl;

    destroy_list(head);
}

static void test_57()
{
    using tree::TreeNodeP;
    Solution57 s;
    cout << "Solution57:\n";

    TreeNodeP* root = new TreeNodeP(1);
    TreeNodeP* n1 = new TreeNodeP(2);
    TreeNodeP* n2 = new TreeNodeP(3);
    TreeNodeP* n3 = new TreeNodeP(4);
    TreeNodeP* n4 = new TreeNodeP(5);
    TreeNodeP* n5 = new TreeNodeP(6);

    root->left = n1;
    n1->parent = root;

    root->right = n2;
    n2->parent = root;

    n1->left = n3;
    n3->parent = n1;
    n1->right = n4;
    n4->parent = n1;

    n2->left = n5;
    n5->parent = n2;

    cout << "Expect: 2\tActual: " << s.get_next(n3)->val << endl;
    cout << "Expect: 1\tActual: " << s.get_next(n4)->val << endl;
    cout << "Expect: 3\tActual: " << s.get_next(n5)->val << endl;

    destroy_tree_p(root);

}

static void test_58()
{
    using tree::TreeNode;
    Solution58 s;
    cout << "Solution58:\n";

    TreeNode* root = new TreeNode(8);
    TreeNode* n1 = new TreeNode(6);
    TreeNode* n2 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(5);
    TreeNode* n4 = new TreeNode(5);
    TreeNode* n5 = new TreeNode(7);
    TreeNode* n6 = new TreeNode(7);
    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n5;
    n2->left = n6;
    n2->right = n4;

    cout << "Expect: true\tActual: " << s.is_symmetric(root) << endl;

    TreeNode* n7 = new TreeNode(8);
    n4->left = n7;
    cout << "Expect: false\tActual: " << s.is_symmetric(root) << endl;

    destroy_tree(root);
}

static void test_59()
{
    using tree::TreeNode;
    Solution59 s;
    cout << "Solution59:\n";

    TreeNode* root = new TreeNode(8);
    TreeNode* n1 = new TreeNode(5);
    TreeNode* n2 = new TreeNode(6);
    TreeNode* n3 = new TreeNode(7);
    TreeNode* n4 = new TreeNode(9);
    TreeNode* n5 = new TreeNode(10);
    TreeNode* n6 = new TreeNode(11);

    root->left = n2;
    root->right = n5;
    n2->left = n1;
    n2->right = n3;

    n5->left = n4;
    n5->right = n6;

    vector<vector<int>> res = s.print(root);
    cout << "Expect: 8 10 6 5 7 9 11\tActual: ";
    for (const auto v : res)
    {
        for (const auto e : v)
            cout << e << " ";
    }
    cout << endl;
    
}

static void test_60()
{
    using tree::TreeNode;
    Solution60 s;
    cout << "Solution60:\n";

    TreeNode* root = new TreeNode(1);
    TreeNode* n1 = new TreeNode(2);
    TreeNode* n2 = new TreeNode(3);
    TreeNode* n3 = new TreeNode(4);
    TreeNode* n4 = new TreeNode(5);
    TreeNode* n5 = new TreeNode(6);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n2->left = n4;
    n2->right = n5;
    
    string res = s.serialize(root);
    cout << "Expect: 1 2 4 # # # 3 5 # # 6 # #\tActual: " << res << endl;

    cout << "Expect: 1 2 4 3 5 6\tActual: ";
    TreeNode* root1 = s.deserialize(res);
    pre_order(root1);
    cout << endl;

    destroy_tree(root);
    destroy_tree(root1);
}

static void test_61()
{
    using tree::TreeNode;
    Solution61 s;
    cout << "Solution61:\n";

    TreeNode* root = new TreeNode(5);
    TreeNode* n1 = new TreeNode(3);
    TreeNode* n2 = new TreeNode(7);
    TreeNode* n3= new TreeNode(2);
    TreeNode* n4 = new TreeNode(4);
    TreeNode* n5 = new TreeNode(6);
    TreeNode* n6 = new TreeNode(8);

    root->left = n1;
    root->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;

    int k = 4;
    cout << "Expect: 5\tActual: " << s.kth_node(root, k)->val << endl;

    k = 6;
    cout << "Expect: 7\tActual: " << s.kth_node(root, k)->val << endl;

    k = 7;
    cout << "Expect: 8\tActual: " << s.kth_node(root, k)->val << endl;

    destroy_tree(root);
}

static void test_62()
{
    Solution62<int> s;
    cout << "Solution62:\n";
    for (int i = 1; i < 8; i++)
    {
        s.insert(i);
    }

    cout << "Expect: 4\tActual: " << s.get_median() << endl;

    s.insert(9);
    cout << "Expect: 8\tActual: " << s.get_median() << endl; 
}

static void test_63()
{
    Solution63 s;
    cout << "Solution63:\n";
    vector<int> nums{2, 3, 4, 2, 6, 2, 5, 1};

    int window_size = 3;
    vector<int> res = s.max_in_windows(nums, window_size);
    cout << "Expect: 4 4 6 6 6 5\tActual: ";
    for (const auto e : res)
        cout << e << " ";
    cout << endl;
}

static void test_64()
{
    Solution64 s;
    cout << "Solution64:\n";
    vector<vector<char>> matrix{
        {'a', 'b', 'c', 'e'},
        {'s', 'f', 'c', 's'},
        {'a', 'd', 'e', 'e'}
    };

    string str = "bcced";
    cout << "Expect: true\tActual: " << s.has_path(matrix, str) << endl;

    str = "abcb";
    cout << "Expect: false\tActual: " << s.has_path(matrix, str) << endl;
    
    str = "asadfbcceese";
    cout << "Expect: true\tActual: " << s.has_path(matrix, str) << endl;
}

static void test_65()
{
    Solution65 s;
    cout << "Solution65:\n";

    int rows = 40, cols = 40;
    int threshold = 18;
    cout << "Expect: 1484\tActual: " << s.moving_count(threshold, rows, cols) << endl;
}

void test()
{
    test_01();
    test_02();
    test_03();
    test_04();
    test_05();
    test_06();
    test_07();
    test_08();
    test_09();
    test_10();
    test_11();
    test_12();
    test_13();
    test_14();
    test_15();
    test_16();
    test_17();
    test_18();
    test_19();
    test_20();
    test_21();
    test_22();
    test_23();
    test_24();
    test_25();
    test_26();
    test_27(); 
    test_28();
    test_29();
    test_30();
    test_31();
    test_32();
    test_33();
    test_34();
    test_35();
    test_36();
    test_37();
    test_38();
    test_39();
    test_40();
    test_41();
    test_42();
    test_43();
    test_44();
    test_45();
    test_46();
    test_47();
    test_48();
    test_49();
    test_50();
    test_51();
    test_52();
    test_53();
    test_54();
    test_55();
    test_56();
    test_57();
    test_58();
    test_59();
    test_60();
    test_61();
    test_62();
    test_63();
    test_64();
    test_65();
    // test_01();
}