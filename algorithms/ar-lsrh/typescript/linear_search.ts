function linearSearch(l: number[], x: number) : number {
    for(let i = 0; i < l.length; i++) {
        if(l[i] === x){
            return i;
        }
    }
    return -1;
}

//Find 5 in [1,8,9,78,6,5,7,22]
linearSearch([1,8,9,78,6,5,7,22], 5);