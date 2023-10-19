#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode *left, *right;
} TreeNode;

TreeNode * new_node(int item)
{
	TreeNode * temp = (TreeNode *)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
	// 주소는 내가 설정하는군.
}

TreeNode * insert_node(TreeNode * node, int key)
	// 내가 노드를 넣는게 아니라 트리를 넣는거네. 트리니까 서브트리가 될 수도 있고 루트가 될 수 도 있군.
{
	if (node == NULL) return new_node(key);
	// 이런 경우 실제로 null이려면 root만 있는 상태에서 루트의 왼쪽/오른쪽을 넣었다던가. 정말 루트가 없거나. 잘못 넣은 경우겠군.
	// 어찌되었건 이 함수 밖에서 반환값을 잘 처리해야겠군.

	if (key < node->key)
		node->left = insert_node(node->left, key);
		// 내가 보고 있는 노드가 값을 저장하고 있을테니 값을 비교해서 왼쪽노드로 가서 값을 저장하거나 다시 비교하러 가거나하겠군. 
	else if (key > node->key)
		node->right = insert_node(node->right, key);
		// 오른쪽도 마찬가지겠군.

	return node;
	// 반환값은 노드의 주소겠군.
}

TreeNode* get_most(TreeNode* node, int RL){
	if (RL == 1){
		while(node->left != NULL){
			node = node->left;
		}
		return node;
	}
	if (RL == 2){
		while(node->right != NULL){
			node = node->right;
		}
		return node;
	}
}

int min(TreeNode *root){
	// 어떻게 출력해야 할지 고민을 해야겠지만, 여기서는 무려 '이.진.탐.색.트.리'니까 그냥 제일 왼쪽 밑 노드를 출력하면 되겠군.
	TreeNode * temp = get_most(root, 1);
	return temp->key;
}

int max(TreeNode *root){
	TreeNode * temp = get_most(root, 2);
	return temp->key;
}

TreeNode* printTree(TreeNode *root)
{
	if (root == NULL) return NULL;
	printf("%d\n", root->key);
	printTree(root->left);
	printTree(root->right);
}


void delete_node(TreeNode *root, int key) {
	TreeNode *current = root;
	TreeNode *parent = NULL;

	// 삭제할 노드를 찾습니다.
	while (current != NULL && current->key != key) {
		parent = current;
		if (key < current->key) {
		current = current->left;
		} else {
		current = current->right;
		}
	}

	// 삭제할 노드가 없으면, 종료합니다.
	if (current == NULL) {
		return;
	}

	// 삭제할 노드의 자식 노드를 확인합니다.
	if (current->left == NULL && current->right == NULL) {
		// 삭제할 노드의 자식 노드가 없으면, 해당 노드를 트리에서 제거합니다.
		if (parent->left == current) {
		parent->left = NULL;
		} else {
		parent->right = NULL;
		}
	} else if (current->left != NULL && current->right != NULL) {
		// 삭제할 노드의 자식 노드가 두 개 있으면, 해당 노드의 후계자를 찾아서 해당 노드를 대체합니다.
		TreeNode *successor = current->right;
		TreeNode *successor_parent = current;

		while (successor->left != NULL) {
		successor_parent = successor;
		successor = successor->left;
		}

		// 후계자의 자식 노드를 후계자의 부모 노드와 연결합니다.
		if (successor_parent->left == successor) {
		successor_parent->left = successor->right;
		} else {
		successor_parent->right = successor->right;
		}

		// 삭제할 노드를 후계자로 대체합니다.
		current->key = successor->key;
		current->left = successor->left;
		current->right = successor->right;
	} else {
		// 삭제할 노드의 자식 노드가 하나만 있으면, 해당 노드를 트리에서 제거하고, 자식 노드를 해당 노드의 부모 노드와 연결합니다.
		if (current->left != NULL) {
			if (parent->left == current) {
				parent->left = current->left;
			} else {
				parent->right = current->left;
			}
		} else {
			if (parent->left == current) {
				parent->left = current->right;
			} else {
				parent->right = current->right;
			}
		}
	}
}


int main()
{

	TreeNode * root = NULL;
	int temp;

	printf("이진 탐색 트리에 5개의 정수를 삽입 하시오.\n");
	for(int i=0; i<5; i++){
		scanf("%d", &temp);
		root = insert_node(root, temp);
	}
	
	printf("최소값: %d, 최대값: %d\n", min(root), max(root));

	printTree(root);
	printf("\n");

	delete_node(root, 3);

	printTree(root);
	printf("\n");
		
	return 0;
}
