#include "doctest.h"
#include <stdio.h>
#include <stdexcept>
using namespace std;

#include "BinaryTree.hpp"
using namespace ariel;

TEST_CASE("preorder: BinaryTree<int>")
{
    BinaryTree<int> tree;

    SUBCASE("add and override root: BinaryTree<int>")
    {
        CHECK_NOTHROW(tree.add_root(0));
        auto it = tree.begin_preorder();
        CHECK_EQ((*it), 0);

        CHECK_NOTHROW(tree.add_root(30));
        it = tree.begin_preorder();
        CHECK_EQ((*it), 30);
    }
    SUBCASE("add to not exist root left and right (shuld throw): BinaryTree<int>")
    {
        CHECK_THROWS(tree.add_left(0, 0));
        CHECK_THROWS(tree.add_right(0, 0));
    }
    SUBCASE("add and override to root left and right: BinaryTree<int>")
    {

        CHECK_NOTHROW(tree.add_left(30, 20));
        CHECK_NOTHROW(tree.add_right(30, 40));
        CHECK_NOTHROW(tree.add_left(20, 15));
        CHECK_NOTHROW(tree.add_right(20, 25));
        CHECK_NOTHROW(tree.add_left(40, 35));
        CHECK_NOTHROW(tree.add_right(40, 50));
        CHECK_NOTHROW(tree.add_left(15, 5));
        CHECK_NOTHROW(tree.add_right(15, 18));
        CHECK_NOTHROW(tree.add_left(50, 45));
        CHECK_NOTHROW(tree.add_right(50, 60));

        int preorder_traversal[] = {30, 20, 15, 5, 18, 25, 40, 35, 50, 45, 60};

        int i = 0;
        for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
        {
            CHECK_EQ((*it), preorder_traversal[i]);
            i++;
        }

        CHECK_NOTHROW(tree.add_left(20, 1));
        CHECK_NOTHROW(tree.add_right(20, 2));
        CHECK_NOTHROW(tree.add_left(50, 3));
        CHECK_NOTHROW(tree.add_right(50, 4));

        int preorder_traversal_with_chang[] = {30, 20, 1, 5, 18, 2, 40, 35, 50, 3, 4};

        i = 0;
        for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
        {
            CHECK_EQ((*it), preorder_traversal_with_chang[i]);
            i++;
        }
    }
}

TEST_CASE("inorder: BinaryTree<int>")
{
    BinaryTree<int> tree;

    SUBCASE("add and override root: BinaryTree<int>")
    {
        CHECK_NOTHROW(tree.add_root(0));
        auto it = tree.begin_inorder();
        CHECK_EQ((*it), 0);

        CHECK_NOTHROW(tree.add_root(30));
        it = tree.begin_inorder();
        CHECK_EQ((*it), 30);
    }
    SUBCASE("add to not exist root left and right (shuld throw): BinaryTree<int>")
    {
        CHECK_THROWS(tree.add_left(0, 0));
        CHECK_THROWS(tree.add_right(0, 0));
    }
    SUBCASE("add and override to root left and right: BinaryTree<int>")
    {

        CHECK_NOTHROW(tree.add_left(30, 20));
        CHECK_NOTHROW(tree.add_right(30, 40));
        CHECK_NOTHROW(tree.add_left(20, 15));
        CHECK_NOTHROW(tree.add_right(20, 25));
        CHECK_NOTHROW(tree.add_left(40, 35));
        CHECK_NOTHROW(tree.add_right(40, 50));
        CHECK_NOTHROW(tree.add_left(15, 5));
        CHECK_NOTHROW(tree.add_right(15, 18));
        CHECK_NOTHROW(tree.add_left(50, 45));
        CHECK_NOTHROW(tree.add_right(50, 60));

        int inorder_traversal[] = {5, 15, 18, 20, 25, 30, 35, 40, 45, 50, 60};

        int i = 0;
        for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
        {
            CHECK_EQ((*it), inorder_traversal[i]);
            i++;
        }

        CHECK_NOTHROW(tree.add_left(20, 1));
        CHECK_NOTHROW(tree.add_right(20, 2));
        CHECK_NOTHROW(tree.add_left(50, 3));
        CHECK_NOTHROW(tree.add_right(50, 4));

        int inorder_traversal_with_chang[] = {5, 1, 18, 20, 2, 30, 35, 40, 3, 50, 4};

        i = 0;
        for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
        {
            CHECK_EQ((*it), inorder_traversal_with_chang[i]);
            i++;
        }
    }
}

TEST_CASE("postorder: BinaryTree<int>")
{
    BinaryTree<int> tree;

    SUBCASE("add and override root: BinaryTree<int>")
    {
        CHECK_NOTHROW(tree.add_root(0));
        auto it = tree.begin_postorder();
        CHECK_EQ((*it), 0);

        CHECK_NOTHROW(tree.add_root(30));
        it = tree.begin_postorder();
        CHECK_EQ((*it), 30);
    }
    SUBCASE("add to not exist root left and right (shuld throw): BinaryTree<int>")
    {
        CHECK_THROWS(tree.add_left(0, 0));
        CHECK_THROWS(tree.add_right(0, 0));
    }
    SUBCASE("add and override to root left and right: BinaryTree<int>")
    {

        CHECK_NOTHROW(tree.add_left(30, 20));
        CHECK_NOTHROW(tree.add_right(30, 40));
        CHECK_NOTHROW(tree.add_left(20, 15));
        CHECK_NOTHROW(tree.add_right(20, 25));
        CHECK_NOTHROW(tree.add_left(40, 35));
        CHECK_NOTHROW(tree.add_right(40, 50));
        CHECK_NOTHROW(tree.add_left(15, 5));
        CHECK_NOTHROW(tree.add_right(15, 18));
        CHECK_NOTHROW(tree.add_left(50, 45));
        CHECK_NOTHROW(tree.add_right(50, 60));

        int postorder_traversal[] = {5, 18, 15, 25, 20, 35, 45, 60, 50, 40, 30};

        int i = 0;
        for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it)
        {
            CHECK_EQ((*it), postorder_traversal[i]);
            i++;
        }

        CHECK_NOTHROW(tree.add_left(20, 1));
        CHECK_NOTHROW(tree.add_right(20, 2));
        CHECK_NOTHROW(tree.add_left(50, 3));
        CHECK_NOTHROW(tree.add_right(50, 4));

        int postorder_traversal_with_chang[] = {5, 18, 1, 2, 20, 35, 3, 4, 50, 40, 30};

        i = 0;
        for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it)
        {
            CHECK_EQ((*it), postorder_traversal_with_chang[i]);
            i++;
        }
    }
}

TEST_CASE("preorder: BinaryTree<string>")
{
    BinaryTree<string> tree;

    SUBCASE("add and override root: BinaryTree<string>")
    {
        CHECK_NOTHROW(tree.add_root("0"));
        auto it = tree.begin_preorder();
        // CHECK_EQ((*it), "0");

        CHECK_NOTHROW(tree.add_root("30"));
        it = tree.begin_preorder();
        // CHECK_EQ((*it), "30");
    }
    SUBCASE("add to not exist root left and right (shuld throw): BinaryTree<string>")
    {
        CHECK_THROWS(tree.add_left("0", "0"));
        CHECK_THROWS(tree.add_right("0", "0"));
    }
    SUBCASE("add and override to root left and right: BinaryTree<string>")
    {

        CHECK_NOTHROW(tree.add_left("30", "20"));
        CHECK_NOTHROW(tree.add_right("30", "40"));
        CHECK_NOTHROW(tree.add_left("20", "15"));
        CHECK_NOTHROW(tree.add_right("20", "25"));
        CHECK_NOTHROW(tree.add_left("40", "35"));
        CHECK_NOTHROW(tree.add_right("40", "50"));
        CHECK_NOTHROW(tree.add_left("15", "5"));
        CHECK_NOTHROW(tree.add_right("15", "18"));
        CHECK_NOTHROW(tree.add_left("50", "45"));
        CHECK_NOTHROW(tree.add_right("50", "60"));

        string preorder_traversal[] = {"30", "20", "15", "5", "18", "25", "40", "35", "50", "45", "60"};

        int i = 0;
        for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
        {
            CHECK_EQ((*it), preorder_traversal[i]);
            i++;
        }

        CHECK_NOTHROW(tree.add_left("20", "1"));
        CHECK_NOTHROW(tree.add_right("20", "2"));
        CHECK_NOTHROW(tree.add_left("50", "3"));
        CHECK_NOTHROW(tree.add_right("50", "4"));

        string preorder_traversal_with_chang[] = {"30", "20", "1", "5", "18", "2", "40", "35", "50", "3", "4"};

        i = 0;
        for (auto it = tree.begin_preorder(); it != tree.end_preorder(); ++it)
        {
            CHECK_EQ((*it), preorder_traversal_with_chang[i]);
            i++;
        }
    }
}

TEST_CASE("inorder: BinaryTree<string>")
{
    BinaryTree<string> tree;

    SUBCASE("add and override root: BinaryTree<string>")
    {
        CHECK_NOTHROW(tree.add_root("0"));
        auto it = tree.begin_preorder();
        // CHECK_EQ((*it), "0");

        CHECK_NOTHROW(tree.add_root("30"));
        it = tree.begin_preorder();
        // CHECK_EQ((*it), "30");
    }
    SUBCASE("add to not exist root left and right (shuld throw): BinaryTree<string>")
    {
        CHECK_THROWS(tree.add_left("0", "0"));
        CHECK_THROWS(tree.add_right("0", "0"));
    }
    SUBCASE("add and override to root left and right: BinaryTree<string>")
    {

        CHECK_NOTHROW(tree.add_left("30", "20"));
        CHECK_NOTHROW(tree.add_right("30", "40"));
        CHECK_NOTHROW(tree.add_left("20", "15"));
        CHECK_NOTHROW(tree.add_right("20", "25"));
        CHECK_NOTHROW(tree.add_left("40", "35"));
        CHECK_NOTHROW(tree.add_right("40", "50"));
        CHECK_NOTHROW(tree.add_left("15", "5"));
        CHECK_NOTHROW(tree.add_right("15", "18"));
        CHECK_NOTHROW(tree.add_left("50", "45"));
        CHECK_NOTHROW(tree.add_right("50", "60"));

        string inorder_traversal[] = {"5", "15", "18", "20", "25", "30", "35", "40", "45", "50", "60"};

        int i = 0;
        for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
        {
            CHECK_EQ((*it), inorder_traversal[i]);
            i++;
        }

        CHECK_NOTHROW(tree.add_left("20", "1"));
        CHECK_NOTHROW(tree.add_right("20", "2"));
        CHECK_NOTHROW(tree.add_left("50", "3"));
        CHECK_NOTHROW(tree.add_right("50", "4"));

        string inorder_traversal_with_chang[] = {"5", "1", "18", "20", "2", "30", "35", "40", "3", "50", "4"};

        i = 0;
        for (auto it = tree.begin_inorder(); it != tree.end_inorder(); ++it)
        {
            CHECK_EQ((*it), inorder_traversal_with_chang[i]);
            i++;
        }
    }
}
TEST_CASE("postorder: BinaryTree<string>")
{
    BinaryTree<string> tree;

    SUBCASE("add and override root: BinaryTree<string>")
    {
        CHECK_NOTHROW(tree.add_root("0"));
        auto it = tree.begin_preorder();
        // CHECK_EQ((*it), "0");

        CHECK_NOTHROW(tree.add_root("30"));
        it = tree.begin_preorder();
        // CHECK_EQ((*it), "30");
    }
    SUBCASE("add to not exist root left and right (shuld throw): BinaryTree<string>")
    {
        CHECK_THROWS(tree.add_left("0", "0"));
        CHECK_THROWS(tree.add_right("0", "0"));
    }
    SUBCASE("add and override to root left and right: BinaryTree<string>")
    {

        CHECK_NOTHROW(tree.add_left("30", "20"));
        CHECK_NOTHROW(tree.add_right("30", "40"));
        CHECK_NOTHROW(tree.add_left("20", "15"));
        CHECK_NOTHROW(tree.add_right("20", "25"));
        CHECK_NOTHROW(tree.add_left("40", "35"));
        CHECK_NOTHROW(tree.add_right("40", "50"));
        CHECK_NOTHROW(tree.add_left("15", "5"));
        CHECK_NOTHROW(tree.add_right("15", "18"));
        CHECK_NOTHROW(tree.add_left("50", "45"));
        CHECK_NOTHROW(tree.add_right("50", "60"));

        string postorder_traversal[] = {"5", "18", "15", "25", "20", "35", "45", "60", "50", "40", "30"};

        int i = 0;
        for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it)
        {
            CHECK_EQ((*it), postorder_traversal[i]);
            i++;
        }

      
        CHECK_NOTHROW(tree.add_left("20", "1"));
        CHECK_NOTHROW(tree.add_right("20", "2"));
        CHECK_NOTHROW(tree.add_left("50", "3"));
        CHECK_NOTHROW(tree.add_right("50", "4"));

        string postorder_traversal_with_chang[] = {"5", "18", "1", "2", "20", "35", "3", "4", "50", "40", "30"};

        i = 0;
        for (auto it = tree.begin_postorder(); it != tree.end_postorder(); ++it)
        {
            CHECK_EQ((*it), postorder_traversal_with_chang[i]);
            i++;
        }
    }
}