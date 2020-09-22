# global variables
arrLanguages=()

cd ~
pwd
ls

function exitWithError() {
  echo "Validation failed : $1"
  exit 1
}

if ! test -f ./language-list.txt ; then
    exitWithError "language-list file not found"
fi

while read F ; do
    arrLanguages+=($F)
done < ./language-list.txt

for i in {1..3} ; do
  echo "-> Folder Level $i Validation:"

  # validation for algorithms folder
  for d in `find ../algorithms -mindepth $i -maxdepth $i` ; do

    # ignore .gitignore & .gitkeep files
    if [ ${d: -8} == ".gitkeep" ] || [ ${d: -9} == "README.md" ] || [ ${d: -10} == ".gitignore" ] ; then
      continue
    fi

    # 1st level folder name validation (lowercase & hyphen only)
    if [ $i == 1 ] && ! [[ $d =~ ^../algorithms/[a-z]+(-[a-z]+)*$ ]] ; then
      exitWithError "$d is not a valid folder name"
    fi

    # 2nd level folder name validation (lowercase, numbers only)
    if [ $i == 2 ] ; then
      if ! [[ $d =~ ^../algorithms/[a-z]+(-[a-z]+)/[a-z0-9]+$ ]] ; then
        exitWithError "$d is not a valid language folder name"
      fi

      IFS='/' read -r -a arrPath <<< $d
      if [[ " ${arrLanguages[*]} " != *" ${arrPath[3]} "* ]]; then
        exitWithError "$d is not a defined language folder name"
      fi
    fi

    # 3rd level file name validation (lowercase, numbers only)
    if [ $i == 3 ] ; then

      IFS='/' read -r -a arrPath <<< $d

      # file name validation for upper-camel (pascal) case
      if [ ${arrPath[3]} == "java" ] && ! [[ ${arrPath[4]} =~ ^([A-Z][a-z0-9]+)+.java$ ]]; then
          exitWithError "$d is not in a valid naming convention"
      fi
    fi

  done

  echo -e "Validation passed!"
done
