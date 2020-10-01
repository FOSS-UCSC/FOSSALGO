#!/bin/bash

# global variables
arrLanguages=()
arrAlgorithms=()
arrDataStructures=()

# Java, C#
REGEX_UPPER_CAMEL="^([A-Z][a-z]+)+.(java|cs)$"
# C, CPP, JavaScript, TypeScript, Golang, Python2, Python3
REGEX_LOWER_UNDERSCORE="^[a-z]([a-z|_]?[a-z])+.(c|cpp|js|ts|go|py)$"

while read F ; do
  arrLanguages+=($F)
done < "$basePath/safety-checkers/language-list.txt"

while read F ; do
  arrAlgorithms+=($F)
done < "$basePath/safety-checkers/algorithm-list.txt"

while read F ; do
  arrDataStructures+=($F)
done < "$basePath/safety-checkers/data-structure-list.txt"

for i in {1..3} ; do
  echo "-> Folder Level $i Validation:"

  for x in algorithms data-structures; do
    for d in $(find "$basePath/$x" -mindepth $i -maxdepth $i) ; do

      # ignore .gitignore & .gitkeep files
      if [ "${d: -8}" == ".gitkeep" ] || [ "${d: -9}" == "README.md" ] || [ "${d: -10}" == ".gitignore" ] ; then
        continue
      fi

      # 1st level folder name validation (lowercase & hyphen only)
      if [ "$i" == 1 ]; then
        if ! [[ $d =~ ^$basePath/$x/[a-z]+(-[a-z]+)*$ ]] ; then
          exitWithError "$d is not a valid folder name"
        fi

        IFS='/' read -r -a arrPath <<< "$d"
        if ([[ $x == "algorithms" && " ${arrAlgorithms[*]} " != *" ${arrPath[-1]} "* ]]) || \
        ([[ $x == "data-structures" && " ${arrDataStructures[*]} " != *" ${arrPath[-1]} "* ]]) ; then
          exitWithError "$d is not a defined folder name"
        fi
      fi

      # 2nd level folder name validation (lowercase, numbers only)
      if [ "$i" == 2 ] ; then
        if ! [[ $d =~ ^$basePath/$x/[a-z]+(-[a-z]+)/[a-z0-9]+$ ]] ; then
          exitWithError "$d is not a valid language folder name"
        fi

        IFS='/' read -r -a arrPath <<< "$d"
        if [[ " ${arrLanguages[*]} " != *" ${arrPath[-1]} "* ]]; then
          exitWithError "$d is not a defined language folder name"
        fi
      fi

      # 3rd level file name validation (lowercase, numbers only)
      if [ "$i" == 3 ] ; then

        IFS='/' read -r -a arrPath <<< "$d"

        # file name validation for upper-camel case
        if ([ "${arrPath[-2]}" == "java" ] || [ "${arrPath[-2]}" == "csharp" ]) && \
        ! [[ "${arrPath[-1]}" =~ $REGEX_UPPER_CAMEL ]]; then
          exitWithError "$d is not in a valid naming convention"
        fi

        if ([ "${arrPath[-2]}" == "c" ] || [ "${arrPath[-2]}" == "cpp" ] || [ "${arrPath[-2]}" == "javascript" ] || \
        [ "${arrPath[-2]}" == "golang" ] || [ "${arrPath[-2]}" == "python2" ] || [ "${arrPath[-2]}" == "python3" ] || \
        [ "${arrPath[-2]}" == "typescript" ]) && ! [[ "${arrPath[-1]}" =~ $REGEX_LOWER_UNDERSCORE ]]; then
          exitWithError "$d is not in a valid naming convention"
        fi
      fi
    done
  done

  echo -e "Validation passed!"
done
