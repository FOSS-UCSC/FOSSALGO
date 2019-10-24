function match (txt,pat) {
	n=txt.length;
    m=pat.length;

    for(i=0;i<(n-m+1);i++){

        for(j=0;j<=m-1;j++){
            if(txt.charAt(i+j)!=pat.charAt(j))
                break;
            if(j==m-1){
                console.log("Pattern found at "+i);
            }
        }
    }
}

function main () {
	txt="ABCECGBCERBCETY";
    pat="BCE";
    match(txt,pat);
}

main();