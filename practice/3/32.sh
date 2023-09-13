echo "Enter a file name"
read -r filename
if [[ -f $filename ]]; then
  if [[  -x $filename ]]; then
      echo "file has permissions"
  else
      chmod +x "$filename"
      echo ""
    
  fi
else
    echo "No such file"
fi
