// Name: Adithya M
// SRN:  PES1UG20CS621
#include "bst.h"
#include <stdlib.h>
/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
 */

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst->root = NULL;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
static node_t *insert_node(node_t *r, int key, int *count_ptr)
{
    if (r == NULL)
    {
        r = (node_t *)malloc(sizeof(node_t));
        r->key = key;
        r->left = NULL;
        r->right = NULL;
    }
    else
    {
        if (++*count_ptr && r->key > key)
            r->left = insert_node(r->left, key, count_ptr);
        else
            r->right = insert_node(r->right, key, count_ptr);
    }
    return r;
}
void insert(bst_t *tree, int key, int *count_ptr)
{
    tree->root = insert_node(tree->root, key, count_ptr);
}

static node_t *del_node(node_t *r, int key, int *count_ptr)
{
    node_t *p;
    if (r == NULL)
        return r;

    if (++*count_ptr && key < r->key)
        r->left = del_node(r->left, key, count_ptr);

    else if (++*count_ptr && key > r->key)
        r->right = del_node(r->right, key, count_ptr);

    else
    {
        if (++*count_ptr && r->left == NULL)
        {
            node_t *temp = r->right;
            free(r);
            r = temp;
        }
        else if (++*count_ptr && r->right == NULL)
        {
            node_t *temp = r->left;
            free(r);
            r = temp;
        }
        else
        {
            p = r->right;
            while (++*count_ptr && p->left != NULL)
                p = p->left;
            r->key = p->key;
            r->right = del_node(r->right, p->key, count_ptr);
        }
    }
    return r;
}
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    tree->root = del_node(tree->root, key, count_ptr);
}

// Searches for the element key in the bst
// Returns the element if found, else -1
static int search_node(node_t *node, int key, int *count_ptr)
{
    int ans;
    if (node == NULL)
        ans = -1;
    else
    {
        if (++*count_ptr && node->key == key)
            ans = key;

        else if (++*count_ptr && node->key < key)
            ans = search_node(node->right, key, count_ptr);
        else
            ans = search_node(node->left, key, count_ptr);
    }
    return ans;
}
int search(const bst_t *tree, int key, int *count_ptr)
{
    return search_node(tree->root, key, count_ptr);
}

// Returns the maximum element in the BST
static int max(node_t *node, int *count_ptr)
{
    int ans;
    if (node == NULL)
        ans = -1;
    else
    {
        if (++*count_ptr && node->right == NULL)
            ans = node->key;

        else
            ans = max(node->right, count_ptr);
    }
    return ans;
}

int find_max(const bst_t *tree, int *count_ptr)
{
    return max(tree->root, count_ptr);
}

static void clear_node(node_t *node)
{
    if (node == NULL)
        return;
    clear_node(node->left);
    clear_node(node->right);
    free(node);
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst)
{
    clear_node(bst->root);
    free(bst);
}

// Deletes all the elements if the bst and ensures it can be used again

void clear_bst(bst_t *bst)
{
    clear_node(bst->root);
    bst->root = NULL;
}
