function modularExponential(x: number, n: number, m: number) : number {
    if(n === 0) {
        return 1;
    } else if(n%2 === 0) {
        return (modularExponential(x, n/2, m)**2)%m;
    } else {
        return (x*modularExponential(x,n-1,m))%m;
    }
}

//Example : 5^8 mod 78
modularExponential(5,8,78);