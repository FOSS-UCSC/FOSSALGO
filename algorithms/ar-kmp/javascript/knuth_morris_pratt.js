function buildPrefixTable(search) {
  const prefixTable = Array(search.length);
  let pos = 1;
  let cnd = 0;

  prefixTable[0] = -1;

  while ( pos < search.length) {
    
    if (search[pos] === search[cnd]) {
      
      prefixTable[pos] = prefixTable[cnd];
    
    } else {

      prefixTable[pos] = cnd;
      cnd = prefixTable[cnd];
      
      while (cnd >= 0 && search[pos] !== search[cnd]) {
        
        cnd = prefixTable[cnd];
      
      }

    }

    pos += 1;
    cnd += 1;
  
  }

  return prefixTable;
}

function knuthMorrisPratt (phrase, word) {
  const phraseLength = phrase.length;
  const wordLength = word.length;
  const prefixTable = buildPrefixTable(word);
  const matches = [];
  let i = 0;
  let j = 0;

  while (i < phraseLength) {
    
    if (phrase[i] === word[j]) {
      
      i += 1;
      j += 1;

      if (j === wordLength) { // Found a match
        
        matches.push(i - j);
        j = prefixTable[j - 1];
      
      }

    } else {

      j = prefixTable[j];
      
      if (j < 0) {
        
        i += 1;
        j += 1;
      
      }
    }
  }

  return matches;
}

function main () {
  const phrase = "ABC ABCDAB ABCDABCDABDE";
  const search = "ABCDABD";
	const matches = knuthMorrisPratt(phrase, search);
  
  /* eslint-disable no-console */
  console.log(`Found ${matches.length} matches at positions: ${matches}`);
  /* eslint-enable no-console */
}

main();