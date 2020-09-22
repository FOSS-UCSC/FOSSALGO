if [[ $debug == "true" ]]; then
  echo "Debug mode activated: Hash validations are ignored"
fi

if [[ $debug == "false" ]]; then
  IFS=$'\n' read -rd '' -a arrHashList <<< $hashes
  for i in ${arrHashList[*]} ; do
#    IFS=' ' read -r -a currHashSet <<< $i
#    echo "hash -> ${currHashSet[0]}"
    echo "hash -> $i"
  done
fi
