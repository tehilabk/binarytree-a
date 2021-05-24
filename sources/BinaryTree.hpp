
#pragma once
#include <stdio.h>
using namespace std;

namespace ariel
{

    template <typename T>
    class BinaryTree
    {

private:
        struct Node
        {
            T value;
            Node *left;
            Node *right;

            Node(const T &v, Node *l = nullptr, Node *r = nullptr)
                : value(v), left(l), right(r) {}
        };

        Node *root;

public:
        //-------------------------------------------------------------------
        // iterator related code:
        // inner class and methods that return instances of it)
        //-------------------------------------------------------------------
        class iterator
        {

        protected:
            Node* current_node_ptr;

        public:
            iterator(Node *ptr = nullptr)
                : current_node_ptr(ptr) {}

            T &operator*() const
            {
                return current_node_ptr->value;
            }

            T *operator->() const
            {
                 return &(current_node_ptr->value);
            }

            // ++i;
            virtual iterator &operator++()
            {
                return *this;
            }

            // i++;
            // Usually iterators are passed by value and not by const& as they are small.
            virtual const iterator operator++(int)
            {
                return *this;

            }

            bool operator==(const iterator &other) const
            {
                return current_node_ptr == other.current_node_ptr;
            }

            bool operator!=(const iterator &rhs) const
            {
                return current_node_ptr != rhs.current_node_ptr;
            }
        };

        class preorder_iterator : public iterator
        {

        public:
            preorder_iterator(Node *ptr = nullptr) : iterator(ptr) {}

            iterator &operator++()
            {
                return *this;
            }

            const iterator operator++(int)
            {
                return *this;

            }
        };

        class inorder_iterator : public iterator
        {
        public:
            inorder_iterator(Node *ptr = nullptr) : iterator(ptr) {}

            iterator &operator++()
            {
                return *this;

            }

            const iterator operator++(int)
            {
                return *this;

            }
        };

        class postorder_iterator : public iterator
        {
        public:
            postorder_iterator(Node *ptr = nullptr) : iterator(ptr) {}

            iterator &operator++()
            {
                return *this;

            }

            const iterator operator++(int)
            {
                return *this;

            }
        };

public:
        BinaryTree(){}
        BinaryTree<T> add_root(const T &new_root)
        {
            return *this;
        }

        BinaryTree<T> add_left(const T &parent, const T &left_child)
        {
            // if "data" Node dosen't exsist --> Exception
            return *this;
        }

        BinaryTree<T> add_right(const T &parent, const T &right_child)
        {
            // if "data" Node dosen't exsist --> Exception
            return *this;
        }

        friend ostream &operator<<(ostream &out, const BinaryTree &tree)
        {
            return out;
        }

        // PreOrder : (root -> left -> right)
        iterator begin_preorder()
        {
            return iterator{root};
        }
        iterator end_preorder()
        {
            return iterator{root};
        }

        // InOrder : (left -> root -> right)
        iterator begin_inorder()
        {
            return iterator{root};
        }

        iterator end_inorder()
        {
            return iterator{root};
        }

        // PostOrder : (left -> right -> root)
        iterator begin_postorder()
        {
            return iterator{root};
        }

        iterator end_postorder()
        {
            return iterator{root};
        }

        iterator begin()
        {
            return iterator{root};
        }

        iterator end()
        {
            return iterator{root};
        }
    };

}