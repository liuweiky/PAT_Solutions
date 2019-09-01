#include <cstdio>
#include <vector>
#include <queue>

#define MAX_N 32

using namespace std;

struct node
{
	int data;
	node* lc;
	node* rc;
	node() { lc = rc = NULL; }
};

int N;
int postorder[MAX_N];
int inorder[MAX_N];
node* root = NULL;
vector<int> ans;

node* rebuild(int pl, int pr, int il, int ir)
{
	if (pl > pr || il > ir)
		return NULL;

	node* n = new node();
	n->data = postorder[pr];

	int k;

	for (k = il; k <= ir; k++)
		if (n->data == inorder[k])
			break;

	n->lc = rebuild(pl, k - il + pl - 1, il, k - 1);
	n->rc = rebuild(k - il + pl, pr - 1, k + 1, ir);

	return n;
}

void level()
{
	queue<node*> q;
	q.push(root);

	while (!q.empty())
	{
		node* r = q.front();
		q.pop();
		ans.push_back(r->data);
		if (r->lc != NULL)
			q.push(r->lc);
		if (r->rc != NULL)
			q.push(r->rc);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 1; i <= N; i++)
		scanf("%d", &postorder[i]);

	for (int i = 1; i <= N; i++)
		scanf("%d", &inorder[i]);

	root = rebuild(1, N, 1, N);

	level();

	for (int i = 0; i < N; i++)
	{
		if (i != 0)
			putchar(' ');
		printf("%d", ans[i]);
	}

	return 0;
}
