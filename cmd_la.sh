echo "Total number of Argumnets" $#
for i in $*
do 
        echo "Filename:" $i
        echo "Contents of file:"
        cat $i 2>> error.txt
done
echo $0

