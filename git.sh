#! /bin/bash
git add -A
if (( $#==1 ))
then
	if (( $1 = "-h" ))
       	then
		echo "Usage: $0 [ARG1]"
		echo
		echo " -h,	displays help page information"
		echo 
		echo "Arguments:"
		echo "[ARG1] - message of the commit"
	else
		message="$1"
		git commit -m message
	fi
else
	git commit -m "test commit"
fi
echo "New commit created!"
