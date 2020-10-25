var collection: Array<number> = new Array(0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434);
var arrayList: number[][] = new Array<Array<number>>(collection.length);

function binSort(collection: Array<number>, size:number): void {
    for(let i=0; i<size; i++){
        arrayList[i] = new Array();
    }

    for(let i=0; i<size; i++){
        var index = Math.floor(collection[i]) * size;
        arrayList[index].push(collection[i]);
    }

    for(let element of arrayList){
        element.sort();
    }

    for(let i=0, index=0; i<size; i++){
        for(let j=0, arraySize=arrayList[i].length; j<arraySize; j++){
            collection[index++] = arrayList[i][j];
        }
    }
}

binSort(collection, collection.length);