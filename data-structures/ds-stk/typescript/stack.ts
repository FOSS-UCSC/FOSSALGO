type objected = undefined | object;



class Stack{



    private count : number = 0;

    private storage: any = {};



    public push = <T extends unknown>(item: T ): void  => {

        this.storage[this.count] = item;

        this.count++;

    };



    public pop = () : objected => {

        if(this.count == 0){

            return undefined;

        }

        this.count--;

        let result = this.storage[this.count];

        return result;

    };



    // returns value at the end of the stack:

    public peek = () => {

        this.count--;

        return this.storage[this.count];

    }



    // returns the number of items in the stack:

    public size = (): number => {

        return this.count;

    }



    //returns the stack list:

    public showFullStack = () => {

        return this.storage;

    }

};



function main(){

    var mystack : Stack = new Stack();

    mystack.push("james");

    mystack.push("hova");

    mystack.push("kanye");

    mystack.pop();

    mystack.size();

    mystack.peek();

    mystack.showFullStack();

    

    return mystack;

}





// main();

console.log(main());
