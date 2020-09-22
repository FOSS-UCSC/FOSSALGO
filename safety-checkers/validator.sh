basePath=/home/runner/work/FOSSALGO/FOSSALGO

function exitWithError() {
  echo "Validation failed : $1"
  exit 1
}

echo "### Safety checks validation process started ###"

if test -f ./parse-envs.sh ; then
  ./parse-envs.sh
  source ./parse-envs.sh
fi

# exports
export -f exitWithError
export basePath
export debug
export hashes

if ! test -v $1 ; then
  debug=$1
  hashes=$2
fi

if ! test -f $basePath/safety-checkers/language-list.txt ; then
    exitWithError "language-list file not found"
fi

echo "1. File hash validation ..."
$basePath/safety-checkers/hash-validator.sh

echo "2. File structure validation ..."
$basePath/safety-checkers/file-structure.sh

echo "### Safety checks validation process successfully finished ###"