function Node(data) {
    this.data = data;
    this.next = null;
};

// Stack implemented using LinkedList
function Stack() {
    this.top = null;
};

Stack.prototype.push = function(data) {
    const newNode = new Node(data);

    newNode.next = this.top;
    this.top = newNode;
};

Stack.prototype.pop = function() {
    if (this.top !== null) {
        const topItem = this.top.data;
        this.top = this.top.next;
        return topItem;
    }
    return null;
};

Stack.prototype.print = function() {
    let curr = this.top;
    while (curr) {
       // console.log(curr.data); uncomment this to print values
        curr = curr.next;
    }
};

const newStack = new Stack();
newStack.push(1);
newStack.push(2);
newStack.pop();
newStack.push(3);
newStack.print();
