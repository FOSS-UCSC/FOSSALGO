
var CircularQueue = function(size) {
    this.items = new Array(size)
    this.size = size
    this.length = 0

    this.front = size - 1
    this.rear = 0
};

// Insert an element in to the circular queue.
CircularQueue.prototype.enQueue = function(element) {
    if (this.isFull()){
        return false
    }else{
        this.items[this.rear] = element           
        this.rear = (this.rear + 1) % this.size
        this.length++
        return true
    }
};

// Extract the element at the front of the circular queue.
CircularQueue.prototype.deQueue = function() {
    if (this.isEmpty()){
        return false
    }else{

        const element = this.items[this.front % this.size]
        this.front = (this.front + 1) % this.size
        this.items[this.front % this.size] = null
        
        this.length--

        return element
    }
};

//Checks if the circular queue is empty.
CircularQueue.prototype.isEmpty = function() {
    return this.length === 0
};

//Checks if the circular queue is full.
CircularQueue.prototype.isFull = function() {
   return this.length == this.size
};

CircularQueue.prototype.display = function(){

    if(this.isEmpty()){
        console.log("The circular queue is empty.")
    }else{
        console.log("Front -> " + this.front)
        console.log("Items -> " + this.items.toString())
        console.log("rear -> " + this.rear)
    }
};

function main () {

    const cq = new CircularQueue(6)

    cq.display()
    console.log("")

    // We fill the queue.
    cq.enQueue(1)
    cq.enQueue(2)
    cq.enQueue(3)
    cq.enQueue(4)
    cq.enQueue(5)
    cq.enQueue(6)

    cq.display()
    console.log("")

    // We try to introduce another element, because it is full, it doesn't allow us.
    cq.enQueue(7)

    cq.display()
    console.log("")

    // we empty the queue.
    cq.deQueue()
    cq.deQueue()
    cq.deQueue()
    cq.deQueue()
    cq.deQueue()
    cq.deQueue()

    cq.display()
    console.log("")
}


main()

