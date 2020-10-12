function bfs(value, tree) {
  queue = [];

  queue.unshift(tree);

  while (queue.length > 0) {
    curNode = queue.pop();
    if (curNode.value === value) {
      return curNode;
    }

    var len = curNode.children.length;

    for (var i = 0; i < len; i++) {
      queue.unshift(curNode.children[i]);
    }
  }

  return null;
}
