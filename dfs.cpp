// Recursive DFS
void dfs(Node* node) {
    if (!node) return;

    visit(node);

    dfs(node->left);
    dfs(node->right);
}

//-------------------------------------------------------
// Iterative DFS
stack<Node*> st;
st.push(root);

while (!st.empty()) {
    Node* curr = st.top();
    st.pop();

    visit(curr);

    if (curr->right) st.push(curr->right);
    if (curr->left) st.push(curr->left);
}

//-------------------------------------------------------
// DFS template
bool dfs(...) {
    if (/*stop condition*/) 
        return;

    mark visited;

    for (each neighbor) {
         if (neighbor is not visited) 
             dfs(...);
    }

    unmark visited; // backtrack
}