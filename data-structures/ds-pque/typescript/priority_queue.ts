class QElement {
  element: string;
  priority: number;
  constructor(element: string, priority: number) {
    this.element = element;
    this.priority = priority;
  }
}

class PriorityQueue {
  items: QElement[];
  constructor() {
    this.items = [];
  }

  enqueue(element: string, priority: number) {
    let qElement: QElement = new QElement(element, priority);
    let contain: boolean = false;

    for (let i: number = 0; i < this.items.length; i++) {
      if (this.items[i].priority > qElement.priority) {
        this.items.splice(i, 0, qElement);
        contain = true;
        break;
      }
    }

    if (!contain) {
      this.items.push(qElement);
    }
  }

  dequeue(): any {
    if (this.isEmpty()) return "Underflow";
    return this.items.shift();
  }

  front(): any {
    if (this.isEmpty()) return "No elements in Queue";
    return this.items[0];
  }

  rear(): any {
    if (this.isEmpty()) return "No elements in Queue";
    return this.items[this.items.length - 1];
  }

  isEmpty(): boolean {
    return this.items.length == 0;
  }

  printPQueue(): String {
    let str: String = "";
    for (let i: number = 0; i < this.items.length; i++) {
      str += this.items[i].element + " ";
    }
    return str;
  }
}

let priorityQueue: PriorityQueue = new PriorityQueue();

console.log(priorityQueue.isEmpty());

priorityQueue.enqueue("Person1", 4);
priorityQueue.enqueue("Person2", 1);
priorityQueue.enqueue("Person3", 3);
priorityQueue.enqueue("Person4", 2);
priorityQueue.enqueue("Person5", 1);

console.log(priorityQueue.printPQueue());

console.log(priorityQueue.front().element);

console.log(priorityQueue.rear().element);

console.log(priorityQueue.dequeue().element);

priorityQueue.enqueue("Person6", 2);

console.log(priorityQueue.printPQueue());
