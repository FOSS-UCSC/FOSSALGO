# global variables
arrLanguages=()
arrAlgorithms=()
arrDataStructures=()

function exitWithError() {
  echo "Safety checker failed : $1"
  exit 1
}

echo "- Non-existing language folder generating process started"

if ! test -f ./language-list.txt ; then
  exitWithError "language-list file is not found"
fi

if ! test -f ./algorithm-list.txt ; then
  exitWithError "algorithm-list file is not found"
fi

if ! test -f ./data-structure-list.txt ; then
  exitWithError "data-structure-list file is not found"
fi

while read F ; do
  arrLanguages+=($F)
done < ./language-list.txt

while read F ; do
  arrAlgorithms+=($F)
done < ./algorithm-list.txt

while read F ; do
  arrDataStructures+=($F)
done < ./data-structure-list.txt

for d in "${arrAlgorithms[@]}"; do
  if ! test -d "../algorithms/$d"; then
    mkdir "../algorithms/$d"
  fi

  for dl in "${arrLanguages[@]}"; do
    if ! test -d "../algorithms/$d/$dl"; then
      mkdir "../algorithms/$d"
    fi
  done
done

echo "- Non-existing language folder generating process starsuccessfully finishedted"