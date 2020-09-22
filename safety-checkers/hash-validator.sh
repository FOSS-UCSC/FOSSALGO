if [[ $debug == "true" ]]; then
  echo "Debug mode activated: Hash validations are ignored"
fi

if [[ $debug == "false" ]]; then
  while IFS= read -r line ; do
    if ! test -z "$line" ; then
      echo $line | sha256sum --check --status
      if [ $? != 0 ]; then
        exit 1
      fi
    fi
  done <<< "$hashes"
fi
