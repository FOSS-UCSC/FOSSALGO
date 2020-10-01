class Node {
    constructor(data) {
        this.right = null;
        this.left = null;
        this.data = data;
    }
}

class Bst {
    constructor() {
        this.root = null;
    }

    insert(data) {
        var node = new Node(data);
        if (!this.root) {
            this.root = node;
            return this;
        }
        var current = this.root;
        while (current) {
            if (data === current.data) {
                return;
            }
            if (data < current.data) {
                if (!current.left) {
                    current.left = node;
                    break;
                }
                current = current.left;
            }
            if (data > current.data) {
                if (!current.right) {
                    current.right = node;
                    break;
                }
                current = current.right;
            }
        }
        return this;
    }
    
    find(data) {
        if (!this.root) {
            return null;
        }
        var current = this.root;
        while (current) {
            if (data == current.data) {
                return current.data;
            }
            if (current.right && data > current.data) {
                current = current.right;
            } else {
                current = current.left;
            }
        }
        return false;
    }
    
    contains(data) {
        var found = this.find(data);
        if (found) {
            return true;
        }
        return false;
    }
    bfs() {
        var node = this.root;
        var queue = [node];
        var finalData = []
        while (queue.length) {
            node = queue.shift();
            if (node.left) {
                queue.push(node.left);
            }
            if (node.right) {
                queue.push(node.right);
            }
            finalData.push(node.data);
        }
        return finalData;
    }

    preOrder() {
        var finalData = [];
        function traverse(node) {
            finalData.push(node.data);
            if (node.left) {
                traverse(node.left);
            }
            if (node.right) {
                traverse(node.right);
            }
        }
        traverse(this.root);
        return finalData;
    }

    postOrder() {
        var finalData = [];
        function traverse(node) {
            if (node.left) {
                traverse(node.left);
            }
            if (node.right) {
                traverse(node.right);
            }
            finalData.push(node.data);
        }

        traverse(this.root);
        return finalData;
    }

    inOrder() {
        var finalData = [];
        function traverse(node) {
            if (node.left) {
                traverse(node.left);
            }
            finalData.push(node.data);
            if (node.right) {
                traverse(node.right);
            }
        }

        traverse(this.root);
        return finalData;
    }

    maxNode() {
        if (!this.root) return null;
        var current = this.root;
        while (current.right) {
            current = current.right;
        }
        return current.data;
    }

    minNode() {
        if (!this.root) {
            return null;
        }
        var current = this.root;
        while (current.left) {
            current = current.left;
        }

        return current.data;
    }
}