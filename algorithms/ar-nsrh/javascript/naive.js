function match (txt,pat) {
	var n = txt.length;
    var m = pat.length;

    for(var i = 0;i < (n-m+1);i++){
        for(var j=0;j<=m-1;j++){
            if(txt.charAt(i+j) !== pat.charAt(j)){
                break;
            }
            if(j === m-1){
                console.log("Pattern found at " + i);
            }
        }
    }
}

function main () {
	var txt="ABCECGBCERBCETY";
    var pat="BCE";
    match(txt, pat);
}

main();