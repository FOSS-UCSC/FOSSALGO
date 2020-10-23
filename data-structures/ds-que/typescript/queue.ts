
//Queue in typescript:
class Queue<T>{
    private collection: Array<T>  = [];
    private length: number = 0;

    public enque = (value :T): void => {
        this.collection.push(value);
    }

    public deque = (): void => {
        this.collection.shift();
    }

    public size = (): number => {
        return this.collection.length;
    }

    public front = (): T => {
        return this.collection[0];
    }

    public getFullQueue = () => {
        return this.collection;
    }
}


const main = () => {
    const myQue = new Queue<string>();
    myQue.enque("Sammy");
    myQue.enque("Daniel");
    myQue.enque("Lady");
    myQue.deque();
    return myQue;
};

main();