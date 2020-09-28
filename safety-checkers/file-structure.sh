#!/bin/bash

# global variables
arrLanguages=()
arrAlgorithms=()
arrDataStructures=()

# Java
REGEX_UPPER_CAMEL="^([A-Z][a-z]+)+.java$"
# C, CPP
REGEX_LOWER_UNDERSCORE="^[a-z]([a-z|_]?[a-z])+.(c|cpp)$"

while read F ; do
  arrLanguages+=($F)
done < $basePath/safety-checkers/language-list.txt

while read F ; do
  arrAlgorithms+=($F)
done < $basePath/safety-checkers/algorithm-list.txt

while read F ; do
  arrDataStructures+=($F)
done < $basePath/safety-checkers/data-structure-list.txt

for i in {1..3} ; do
  echo "-> Folder Level $i Validation:"

  # validation for algorithms folder
  for d in `find $basePath/algorithms -mindepth $i -maxdepth $i` ; do

    # ignore .gitignore & .gitkeep files
    if [ ${d: -8} == ".gitkeep" ] || [ ${d: -9} == "README.md" ] || [ ${d: -10} == ".gitignore" ] ; then
      continue
    fi

    # 1st level folder name validation (lowercase & hyphen only)
    if [ $i == 1 ]; then
      if ! [[ $d =~ ^$basePath/algorithms/[a-z]+(-[a-z]+)*$ ]] ; then
        exitWithError "$d is not a valid folder name"
      fi

      IFS='/' read -r -a arrPath <<< $d
      if [[ " ${arrAlgorithms[*]} " != *" ${arrPath[-1]} "* ]]; then
        exitWithError "$d is not a defined language folder name"
      fi
    fi

    # 2nd level folder name validation (lowercase, numbers only)
    if [ $i == 2 ] ; then
      if ! [[ $d =~ ^$basePath/algorithms/[a-z]+(-[a-z]+)/[a-z0-9]+$ ]] ; then
        exitWithError "$d is not a valid language folder name"
      fi

      IFS='/' read -r -a arrPath <<< $d
      if [[ " ${arrLanguages[*]} " != *" ${arrPath[-1]} "* ]]; then
        exitWithError "$d is not a defined language folder name"
      fi
    fi

    # 3rd level file name validation (lowercase, numbers only)
    if [ $i == 3 ] ; then

      IFS='/' read -r -a arrPath <<< $d

      # file name validation for upper-camel case
      if [ ${arrPath[-2]} == "java" ] && ! [[ ${arrPath[-1]} =~ $REGEX_UPPER_CAMEL ]]; then
        exitWithError "$d is not in a valid naming convention"
      fi

      if ([ ${arrPath[-2]} == "c" ] || [ ${arrPath[-2]} == "cpp" ]) && ! [[ ${arrPath[-1]} =~ $REGEX_LOWER_UNDERSCORE ]]; then
        exitWithError "$d is not in a valid naming convention"
      fi
    fi

  done

  # validation for data-structure folder
  for d in `find $basePath/data-structures -mindepth $i -maxdepth $i` ; do

    # ignore .gitignore & .gitkeep files
    if [ ${d: -8} == ".gitkeep" ] || [ ${d: -9} == "README.md" ] || [ ${d: -10} == ".gitignore" ] ; then
      continue
    fi

    # 1st level folder name validation (lowercase & hyphen only)
    if [ $i == 1 ]; then
      if ! [[ $d =~ ^$basePath/data-structures/[a-z]+(-[a-z]+)*$ ]] ; then
        exitWithError "$d is not a valid folder name"
      fi

      IFS='/' read -r -a arrPath <<< $d
      if [[ " ${arrDataStructures[*]} " != *" ${arrPath[-1]} "* ]]; then
        exitWithError "$d is not a defined language folder name"
      fi
    fi

    # 2nd level folder name validation (lowercase, numbers only)
    if [ $i == 2 ] ; then
      if ! [[ $d =~ ^$basePath/data-structures/[a-z]+(-[a-z]+)/[a-z0-9]+$ ]] ; then
        exitWithError "$d is not a valid language folder name"
      fi

      IFS='/' read -r -a arrPath <<< $d
      if [[ " ${arrLanguages[*]} " != *" ${arrPath[-1]} "* ]]; then
        exitWithError "$d is not a defined language folder name"
      fi
    fi

    # 3rd level file name validation (lowercase, numbers only)
    if [ $i == 3 ] ; then

      IFS='/' read -r -a arrPath <<< $d

      # file name validation for upper-camel case
      if [ ${arrPath[-2]} == "java" ] && ! [[ ${arrPath[-1]} =~ $REGEX_UPPER_CAMEL ]]; then
        exitWithError "$d is not in a valid naming convention"
      fi

      if ([ ${arrPath[-2]} == "c" ] || [ ${arrPath[-2]} == "cpp" ]) && ! [[ ${arrPath[-1]} =~ $REGEX_LOWER_UNDERSCORE ]]; then
        exitWithError "$d is not in a valid naming convention"
      fi
    fi

  done

  echo -e "Validation passed!"
done
