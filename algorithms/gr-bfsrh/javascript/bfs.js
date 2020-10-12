function bfs(value, tree) {
  let queue = [];

  queue.unshift(tree);

  while (queue.length > 0) {
    let curNode = queue.pop();
    if (curNode.value === value) {
      return curNode;
    }

    const len = curNode.children.length;

    for (let i = 0; i < len; i++) {
      queue.unshift(curNode.children[i]);
    }
  }

  return null;
}
