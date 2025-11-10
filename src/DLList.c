
typedef struct DLNode DLNode;
struct DLNode{
    DLNode *next;
    DLNode *prev;
    void *data;
    char ownsData;
};

