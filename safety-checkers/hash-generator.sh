#!/bin/bash

# use sha256 for checksums
echo "- Checksum generating process started"

if test -f ./checksums.sha256 ; then
    rm ./checksums.sha256
fi

# safety-checkers files
sha256sum ./language-list.txt >> checksums.sha256
sha256sum ./algorithm-list.txt >> checksums.sha256
sha256sum ./data-structure-list.txt >> checksums.sha256
sha256sum ./validator.sh >> checksums.sha256
sha256sum ./file-structure.sh >> checksums.sha256
sha256sum ./hash-validator.sh >> checksums.sha256

# .gitignore files
for d in $(find .. -type f -name ".gitignore") ; do
  sha256sum "$d" >> checksums.sha256
done

# files in .github folder
sha256sum ../.github/workflows/main.yml >> checksums.sha256
sha256sum ../.github/ISSUE_TEMPLATE.md >> checksums.sha256
sha256sum ../.github/PULL_REQUEST_TEMPLATE.md >> checksums.sha256

# . & .. change to base path for github action
pattern1='s/\.\.\//\/home\/runner\/work\/FOSSALGO\/FOSSALGO\//g'
pattern2='s/\.\//\/home\/runner\/work\/FOSSALGO\/FOSSALGO\/safety-checkers\//g'
sed -i "$pattern1" checksums.sha256
sed -i "$pattern2" checksums.sha256
echo "- Checksum generating process successfully finished"