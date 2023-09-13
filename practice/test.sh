echo "Pattern to check :"
read -r pattern
file=$(ls)
for file in $file
do
    if  grep -q "$pattern" "$file" 
    then
        echo "Pattern $pattern is present"
    else
        echo "Pattern $pattern does not present"
    fi
done
