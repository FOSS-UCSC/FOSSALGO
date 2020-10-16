function exponentiationBySquaring(x: number, n: number) : number {
    if(n === 0) {
        return 1;
    } else if(n%2 === 0) {
        return (exponentiationBySquaring(x, n/2)**2);
    } else {
        return (x*exponentiationBySquaring(x,n-1));
    }
}

//Example : 5^8
exponentiationBySquaring(5,8);