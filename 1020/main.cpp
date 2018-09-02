#include <cstdio>
#include <queue>

using namespace std;

struct Node
{
    Node* left;
    Node* right;
    int data;
    Node(){left = right = NULL;}
    Node(int d): data(d) {left = right = NULL;}
};

int node_num;
int inorder[32];
int postorder[32];


Node* rebuild(int post_from, int post_to, int in_from, int in_to)
{
    Node* root = new Node(postorder[post_to]);
    for (int i = in_from; i <= in_to; i++)
    {
        if (root->data == inorder[i])
        {
            int left_count = i - in_from;
            int right_count = in_to - i;
            if (left_count == 0)
                root->left = NULL;
            else
                root->left = rebuild(post_from, post_from + left_count - 1, in_from, i - 1);
            if (right_count == 0)
                root->right = NULL;
            else
                root->right = rebuild(post_from + left_count, post_to - 1, i + 1, in_to);
        }
    }
    return root;
}

void LevelOrder(Node* root)
{
    queue<Node*> q;
    q.push(root);
    printf("%d", root->data);
    while (!q.empty())
    {
        Node* n = q.front();
        q.pop();
        if (n->left != NULL)
        {
            printf(" %d", n->left->data);
            q.push(n->left);
        }
        if (n->right != NULL)
        {
            printf(" %d", n->right->data);
            q.push(n->right);
        }
    }
}

int main()
{
    scanf("%d", &node_num);
    for (int i = 0; i < node_num; i++)
        scanf("%d", &postorder[i]);
    for (int i = 0; i < node_num; i++)
        scanf("%d", &inorder[i]);

    Node* root = rebuild(0, node_num - 1, 0, node_num - 1);
    LevelOrder(root);
    return 0;
}
