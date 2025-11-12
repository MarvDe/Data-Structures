#ifndef TREE_H
#define TREE_H

typedef struct Tree Tree;
struct Tree{
    struct TNode *root;
};


Tree *TreeCreate();
void TreeDestroy(Tree *tree);
void *TreeGet(Tree *tree, int *keys);
void TreeRemove(Tree *tree, int *keys);
void *TreeRemoveAndGet(Tree *tree, int *keys);
void TreeInsert(Tree *tree, void *data, char ownsData, int *keys);

#endif