BinaryTreeNode<int>* lcaOfThreeNodes(BinaryTreeNode<int>* root, int node1, int node2, int node3) {
    if(!root) return NULL;
	if(root->data==node1 || root->data==node2 || root->data==node3) return root;

	BinaryTreeNode<int>* leftAns = lcaOfThreeNodes(root->left, node1, node2, node3);
	BinaryTreeNode<int>* rightAns = lcaOfThreeNodes(root->right, node1, node2, node3);

	if(leftAns && rightAns) return root;
	else if(leftAns && !rightAns) return leftAns;
	else if(!leftAns && rightAns) return rightAns;
	else return NULL;
}
